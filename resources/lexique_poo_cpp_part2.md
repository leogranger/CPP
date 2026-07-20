# 📕 Lexique C++ — Partie 2 : Exceptions, Conversions, Templates & STL

> Suite de la [Partie 1 — Lexique de la POO](lexique_poo_cpp.md).
> La Partie 1 pose les **fondations** (classe, héritage, polymorphisme, abstraction). Cette Partie 2 couvre les **mécanismes** qu'on construit par-dessus : gestion d'erreurs, conversions de type, généricité, conteneurs.

**Classe d'exemple utilisée** : `Animal` — la même que dans la Partie 1, pour la continuité. Tu peux mentalement la remplacer par n'importe quelle classe. Les concepts sont **universels** ; les exercices 42 où ils apparaissent sont cités dans les encadrés 🚀.

**Convention typographique du document** (identique à la Partie 1) :

| Emoji | Sens |
|---|---|
| 📘 | Définition |
| 🎬 | Exemple complet |
| 🎨 | Métaphore |
| 🧠 | Mnémotechnique |
| ⚠️ | Piège classique |
| 🔍 | Règle pratique / tableau |
| 🚀 | Aperçu / lien avec un exercice 42 |

---

## 📑 Table des matières

**Gestion des erreurs — les exceptions**
1. [Le mécanisme d'exception (vue d'ensemble)](#-le-mécanisme-dexception-vue-densemble)
2. [`throw` — lever une exception](#-throw--lever-une-exception)
3. [`try` / `catch` — attraper une exception](#-try--catch--attraper-une-exception)
4. [`std::exception` et la méthode `what()`](#-stdexception-et-la-méthode-what)
5. [Créer ses propres exceptions](#-créer-ses-propres-exceptions)
6. [La spécification `throw()` (C++98)](#-la-spécification-throw-c98)
7. [Catch par référence et catch polymorphique](#-catch-par-référence-et-catch-polymorphique)
8. [Le déroulement de la pile (stack unwinding) et RAII](#-le-déroulement-de-la-pile-stack-unwinding-et-raii)
9. [Règle d'or : jamais d'exception hors d'un destructeur](#-règle-dor--jamais-dexception-hors-dun-destructeur)

**Outils de conception (callables)**
10. [Pointeurs de fonction](#-pointeurs-de-fonction)
11. [Foncteur (objet-fonction)](#-foncteur-objet-fonction)

**Conversions de type — les casts (CPP06)**
12. [Conversion implicite vs explicite](#-conversion-implicite-vs-explicite)
13. [Pourquoi 4 casts nommés (et pas le cast à la C) ?](#-pourquoi-4-casts-nommés-et-pas-le-cast-à-la-c-)
14. [`static_cast` — la conversion logique](#-static_cast--la-conversion-logique)
15. [`dynamic_cast` — l'identification vérifiée](#-dynamic_cast--lidentification-vérifiée)
16. [RTTI et `typeid`](#-rtti-et-typeid)
17. [`reinterpret_cast` — relire les bits autrement](#-reinterpret_cast--relire-les-bits-autrement)
18. [`const_cast` — retirer (ou ajouter) le `const`](#-const_cast--retirer-ou-ajouter-le-const)
19. [Quel cast choisir ? (tableau de décision)](#-tableau-de-décision--quel-cast-choisir-)
20. [Aparté — la classe utilitaire non instanciable](#-aparté--la-classe-utilitaire-non-instanciable)

**Généricité — les templates (CPP07)**
21. [La généricité — le problème](#-la-généricité--le-problème)
22. [Template de fonction](#-template-de-fonction)
23. [`typename` vs `class`](#-typename-vs-class)
24. [Plusieurs paramètres de template](#-plusieurs-paramètres-de-template)
25. [Template de classe](#-template-de-classe)
26. [Pourquoi un template vit dans le header](#-pourquoi-un-template-vit-dans-le-header)
27. [Instanciation implicite vs explicite](#-instanciation-implicite-vs-explicite)

**Conteneurs, itérateurs et algorithmes — la STL (CPP08-09)**
28. [La STL — vue d'ensemble](#-la-stl--vue-densemble)
29. [Les conteneurs séquentiels (vector, list, deque)](#-les-conteneurs-séquentiels-vector-list-deque)
30. [Les adaptateurs de conteneur (stack, queue, priority_queue)](#-les-adaptateurs-de-conteneur-stack-queue-priority_queue)
31. [Les conteneurs associatifs (map, set)](#-les-conteneurs-associatifs-map-set)
32. [`std::pair` et l'entrée d'une map](#-stdpair-et-lentrée-dune-map)
33. [Les itérateurs](#-les-itérateurs)
34. [Le pattern `typename T::iterator` (types dépendants)](#-le-pattern-typename-titerator-types-dépendants)
35. [Les algorithmes (`<algorithm>` et `<numeric>`)](#-les-algorithmes-algorithm-et-numeric)
36. [Hériter d'un conteneur (MutantStack)](#-hériter-dun-conteneur-mutantstack)
37. [Choisir le bon conteneur (la philosophie du CPP09)](#-choisir-le-bon-conteneur-la-philosophie-du-cpp09)

**Annexes**
- [Termes complémentaires](#-termes-complémentaires) (dont un **zoom sur l'opérateur ternaire**)
- [Quiz d'auto-évaluation](#-quiz-dauto-évaluation)

---

## 🎯 Le mécanisme d'exception (vue d'ensemble)

📘 Une **exception** est un mécanisme du C++ pour **signaler une erreur** à un endroit du code et la **traiter** ailleurs, sans polluer toutes les fonctions intermédiaires avec des codes de retour.

### 🤔 Le problème qu'on résout

En C, pour signaler une erreur, on renvoie un code (`-1`, `NULL`, `errno`...). Chaque appelant **doit** vérifier à la main, et l'information se perd vite.

```cpp
// Style C : on pollue tout le code de vérifications
int err = setAge(rex, -5);
if (err == -1) { /* gérer ici, et à CHAQUE appel... */ }
```

Avec les exceptions, on **sépare** le code normal du code de gestion d'erreur :

```cpp
try {
    Animal rex("Rex", -5);   // un âge négatif n'a pas de sens → throw
    // ... suite du code "heureux", lisible, sans if d'erreur partout
}
catch (std::exception& e) {
    std::cout << e.what() << std::endl;   // gestion centralisée
}
```

🎨 **Métaphore** : une exception, c'est une **alarme incendie**. Celui qui détecte le feu (le `throw`) ne sait pas qui réagira : il déclenche l'alarme. Le signal **remonte** les étages jusqu'à ce que quelqu'un d'équipé (le `catch`) s'en occupe. Entre les deux, tout le monde évacue proprement (les destructeurs sont appelés — voir [stack unwinding](#-le-déroulement-de-la-pile-stack-unwinding-et-raii)).

### 🧩 Les 3 mots-clés

| Mot-clé | Rôle | Phrase mentale |
|---|---|---|
| `throw` | **Lève** l'exception : « il y a un problème ! » | *« Je lance l'alarme »* |
| `try` | **Délimite** la zone surveillée | *« Je surveille ce bloc »* |
| `catch` | **Attrape** et traite l'exception | *« Je gère le problème »* |

🧠 **Mnémotechnique** : **« TTC »** comme une facture — **T**ry, **T**hrow, **C**atch.

🚀 **Où ça apparaît en 42** : le CPP05 (« Repetition and Exceptions ») est entièrement bâti là-dessus — un `Bureaucrat` ou un `Form` au grade invalide doit **throw**.

---

## 💥 `throw` — lever une exception

📘 `throw expr;` **interrompt immédiatement** l'exécution de la fonction courante et **remonte** jusqu'au premier `catch` capable de traiter le type de `expr`.

```cpp
Animal::Animal(std::string name, int age) : _name(name)
{
    if (age < 0)
        throw InvalidAgeException();   // ← interrompt le constructeur ICI
    _age = age;                         // jamais atteint si on a throw
}
```

### 🔑 Ce qu'il faut comprendre

- **`throw` arrête tout** : les lignes après le `throw` (dans la même fonction) **ne s'exécutent pas**.
- On peut lancer **n'importe quel type** (un `int`, une `std::string`...), mais la **bonne pratique** est de lancer un **objet dérivé de `std::exception`** (voir plus bas).
- `throw InvalidAgeException();` **construit** un objet exception temporaire et le lance.

### ⚠️ Piège : un `throw` dans un constructeur

Si un constructeur `throw`, l'objet **n'est jamais considéré comme construit** → son **destructeur ne sera PAS appelé**. En revanche, les attributs **déjà construits** avant le `throw` sont, eux, détruits proprement.

```cpp
Animal rex("Rex", -5);   // throw dans le ctor
// → rex n'existe PAS. ~Animal() n'est pas appelé pour rex.
//   (mais _name, déjà construit, est bien détruit)
```

🚀 **Contexte 42** : instancier un `Bureaucrat`/`Form` avec un grade hors bornes [1..150] doit **throw** — l'objet n'est donc pas créé.

---

## 🛡️ `try` / `catch` — attraper une exception

📘 Le bloc `try { ... }` délimite le code **surveillé**. Si une exception est levée dedans (directement ou dans une fonction appelée), le `catch` correspondant l'**intercepte**.

```cpp
try
{
    Animal rex("Rex", -5);          // throw InvalidAgeException
    std::cout << "jamais affiché" << std::endl;
}
catch (std::exception& e)           // attrape l'exception
{
    std::cout << "Erreur : " << e.what() << std::endl;
}
// le programme CONTINUE ici, normalement
```

### 🔑 Mécanisme détaillé

1. Le code dans `try` s'exécute normalement.
2. Dès qu'un `throw` survient, le reste du `try` est **abandonné**.
3. Le programme cherche un `catch` dont le **type correspond** à l'exception.
4. Le code du `catch` s'exécute, puis l'exécution **reprend après** le bloc `try/catch`.
5. Si **aucun** `catch` ne correspond nulle part → `std::terminate()` → le programme **crashe** (`abort`).

### 🔗 Plusieurs `catch` en cascade

On peut enchaîner plusieurs `catch` pour traiter différents types. Le **premier qui correspond** gagne.

```cpp
try {
    rex.setAge(value);
}
catch (Animal::InvalidAgeException& e) {   // cas spécifique d'abord
    std::cout << "Âge invalide : " << e.what() << std::endl;
}
catch (std::exception& e) {                 // cas général ensuite
    std::cout << "Autre erreur : " << e.what() << std::endl;
}
```

⚠️ **Ordre crucial** : mets le **plus spécifique en premier**, le **plus général en dernier**. Un `catch (std::exception&)` placé en premier attraperait **tout** (voir [catch polymorphique](#-catch-par-référence-et-catch-polymorphique)), rendant les `catch` suivants inaccessibles.

---

## 📛 `std::exception` et la méthode `what()`

📘 `std::exception` (header `<exception>`) est la **classe de base** de toute la hiérarchie d'exceptions standard. Elle expose **une** méthode virtuelle clé :

```cpp
virtual const char* what() const throw();
```

`what()` renvoie une **chaîne C** (`const char*`) qui **décrit** l'erreur. C'est le message qu'on affiche.

### 🎯 Pourquoi hériter de `std::exception` ?

Parce que ça permet d'attraper **toutes** tes exceptions (et celles de la STL) avec **un seul** `catch (std::exception& e)`. C'est la base du [catch polymorphique](#-catch-par-référence-et-catch-polymorphique).

```cpp
catch (std::exception& e) {        // attrape TOUT ce qui dérive de std::exception
    std::cout << e.what() << std::endl;
}
```

🔍 **Quelques exceptions standard** (culture générale) :

| Exception | Header | Levée quand... |
|---|---|---|
| `std::exception` | `<exception>` | base de toutes les autres |
| `std::bad_alloc` | `<new>` | `new` échoue (plus de mémoire) |
| `std::out_of_range` | `<stdexcept>` | accès `.at()` hors bornes |
| `std::logic_error` / `std::runtime_error` | `<stdexcept>` | familles d'erreurs prêtes à l'emploi |

---

## 🏗️ Créer ses propres exceptions

📘 Une exception personnalisée est simplement une **classe qui hérite de `std::exception`** et qui **redéfinit `what()`**. On la déclare souvent comme **classe imbriquée** (`nested class`) à l'intérieur de la classe concernée, quand elle n'a de sens que dans ce contexte.

```cpp
// Animal.hpp
class Animal {
public:
    // ... le reste de la classe ...

    class InvalidAgeException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};
```

```cpp
// Animal.cpp
const char* Animal::InvalidAgeException::what() const throw() {
    return "Animal age is invalid";
}
```

### 🔑 Pourquoi une classe *imbriquée* ?

- **Logique** : `InvalidAgeException` n'a de sens que **dans le contexte** d'un `Animal`. L'imbriquer exprime cette appartenance.
- **Nommage** : on l'utilise via `Animal::InvalidAgeException`, ce qui évite les collisions de noms avec d'autres exceptions du projet.

🎨 **Métaphore** : c'est comme un type de panne **propre à une marque**. « Erreur moteur Renault » a du sens écrit `Renault::ErreurMoteur` — on sait tout de suite de quoi on parle.

### ⚠️ L'exception N'A PAS besoin de la forme canonique (OCF)

C'est l'**unique** classe que les sujets 42 dispensent de l'[OCF](lexique_poo_cpp.md#-la-forme-canonique-orthodoxe-orthodox-canonical-form-ocf) (que la Partie 1 impose partout ailleurs) :

> *« exception classes do not have to be designed in Orthodox Canonical Form. »*

Une exception ne stocke (souvent) aucune donnée à copier proprement — pas besoin de constructeur de copie / `operator=` explicites.

🧠 **Mnémotechnique** : *« Une exception : juste `what()`, rien d'autre d'obligatoire. »*

🚀 **Contexte 42** : au CPP05, `Bureaucrat::GradeTooHighException` et `Bureaucrat::GradeTooLowException` suivent exactement ce patron.

---

## 📜 La spécification `throw()` (C++98)

📘 Le `throw()` à la **fin** d'une signature est une **spécification d'exception** (héritée du C++98). Elle annonce : *« cette fonction ne lèvera **aucune** exception. »*

```cpp
const char* what() const throw();
//                ↑       ↑
//          const méthode  ← "ne throw rien"
```

### 🔍 Ne pas confondre les deux usages de `throw`

| Forme | Où | Sens |
|---|---|---|
| `throw expr;` | dans le **corps** | **lève** une exception |
| `... ) const throw();` | **après** la signature | **promet** de ne rien lever |

C'est le même mot-clé, deux rôles **opposés** — exactement comme les deux `*` ou les deux `&` de la [Partie 1](lexique_poo_cpp.md#-les-symboles--et--en-c).

### 🎯 Pourquoi on le met sur `what()` ?

La signature de `std::exception::what()` est **exactement** `virtual const char* what() const throw();`. Pour **redéfinir** (override) correctement la méthode de base, ta signature doit **coïncider** — y compris le `throw()`.

🧠 **Mnémotechnique** : *« `what()` ne doit jamais elle-même planter → elle promet `throw()` (rien). »* Logique : on ne veut pas qu'afficher un message d'erreur déclenche une **nouvelle** erreur.

⚠️ **C++11+** : `throw()` est **déprécié** au profit de `noexcept`. Mais les sujets imposent `-std=c++98`, donc on écrit **`throw()`**. À connaître, à ne pas remplacer ici.

---

## 🎣 Catch par référence et catch polymorphique

### 1️⃣ Toujours attraper **par référence**

```cpp
catch (std::exception& e)   // ✅ par référence
catch (std::exception  e)   // ❌ par valeur → slicing !
```

**Pourquoi par référence ?** Attraper **par valeur** une exception de type dérivé via la base provoque un **slicing** (voir [Partie 1](lexique_poo_cpp.md#-le-piège-du-slicing-à-éviter)) : la partie spécifique est découpée, et `what()` ne renvoie plus le bon message (celui de la base, pas du type réel).

🧠 **Mnémotechnique** : *« Catch by reference, toujours. »* (la référence préserve le **vrai type** → bon `what()`.)

### 2️⃣ Le catch **polymorphique**

📘 Un `catch (Base& e)` attrape **aussi** toutes les exceptions des classes **dérivées** de `Base`. C'est du [polymorphisme](lexique_poo_cpp.md#-polymorphisme-de-sous-type) appliqué aux exceptions.

```cpp
try {
    rex.setAge(value);   // peut throw Animal::InvalidAgeException
}
catch (std::exception& e) {   // InvalidAgeException EST-UNE std::exception → attrapée
    std::cout << e.what() << std::endl;
}
```

Comme l'exception hérite de `std::exception`, un seul `catch (std::exception&)` suffit pour **tout** intercepter. Et grâce au `virtual` sur `what()`, c'est la **bonne version** du message qui s'affiche (liaison dynamique → [vtable](lexique_poo_cpp.md#️-comment-ça-marche-la-vtable)).

🔍 **Conséquence sur l'ordre des `catch`** :

| Ordre | Effet |
|---|---|
| Spécifique → général | ✅ chaque cas traité correctement |
| Général (`std::exception`) en premier | ⚠️ il attrape tout, les `catch` suivants sont **morts** |

---

## 🧹 Le déroulement de la pile (stack unwinding) et RAII

📘 Le **stack unwinding** (« déroulement de la pile ») est le processus par lequel, entre le `throw` et le `catch`, le C++ **détruit proprement tous les objets locaux** des scopes qu'il quitte.

```cpp
void process() {
    Animal rex("Rex", 3);       // objet local sur la pile
    riskyOperation();           // throw ici
    // ... pas atteint ...
}                               // pendant la remontée, ~Animal() de rex EST appelé
```

Quand `riskyOperation()` lève une exception, en remontant vers le `catch`, le destructeur de `rex` est **garanti** d'être appelé. C'est ce qui rend les exceptions **sûres** : pas de fuite de ressources allouées sur la pile.

🎨 **Métaphore** (suite de l'alarme incendie) : pendant que l'alarme remonte les étages, **chaque personne évacue en fermant sa porte derrière elle** (destructeur). Rien n'est laissé en plan.

### 🔗 Lien avec RAII

📘 **RAII** (*Resource Acquisition Is Initialization*) : un objet **acquiert** sa ressource dans son constructeur et la **libère** dans son destructeur. Comme le destructeur est appelé pendant le stack unwinding, **RAII + exceptions = pas de fuite**, même en cas d'erreur.

```cpp
// std::ifstream est un objet RAII : il ferme le fichier dans son destructeur
void readFile() {
    std::ifstream file("data.txt");   // ouvre
    parse(file);                       // si throw ici...
}                                      // ...file est quand même fermé (destructeur)
```

⚠️ **Piège du `new` brut** : un pointeur brut **n'est pas** RAII. Si tu fais `new` puis qu'un `throw` survient avant le `delete`, **tu fuis**.

```cpp
void leak() {
    Animal* a = new Animal();   // sur le tas
    riskyOperation();           // throw → 'a' n'est JAMAIS delete → fuite !
    delete a;                   // jamais atteint
}
```

🔍 **Solution sûre** : libère **avant** tout `throw` potentiel, ou encadre le `new`/`delete` dans un `try/catch` qui `delete` puis relance. (Hors 42 C++98, on utiliserait un *smart pointer*.)

🧠 **Mnémotechnique** : *« La pile se nettoie toute seule ; le tas, c'est à toi. »* (écho direct de [Stack vs Heap](lexique_poo_cpp.md#️-stack-vs-heap-pile-vs-tas).)

---

## 🚷 Règle d'or : jamais d'exception hors d'un destructeur

📘 Un destructeur ne doit **jamais laisser s'échapper** une exception.

**Pourquoi ?** Pendant un stack unwinding (déjà déclenché par une première exception), si un destructeur en lève une **deuxième**, le C++ ne sait pas laquelle traiter → il appelle directement `std::terminate()` → **crash immédiat**, sans recours.

```cpp
~Animal() {
    throw std::exception();   // ❌ TRÈS dangereux : peut tuer le programme
}
```

🧠 **Mnémotechnique** : *« On meurt en silence. »* Un destructeur gère ses erreurs en interne (try/catch local), il n'en propage jamais.

---

## 🔀 Pointeurs de fonction

📘 Un **pointeur de fonction** est une variable qui **stocke l'adresse d'une fonction**. On peut l'appeler comme la fonction elle-même. C'est l'outil idéal pour **remplacer une longue cascade de `if/else`** par une table de correspondance.

```cpp
void (*ptr)(int);   // ptr = pointeur vers une fonction qui prend un int et ne renvoie rien
ptr = &maFonction;  // on lui assigne l'adresse d'une fonction
ptr(42);            // on l'appelle comme une fonction normale
```

### 🎬 Le pattern « deux tableaux parallèles »

Au lieu de tester chaque cas à la main, on associe une **liste de clés** à une **liste de fabriques** et on boucle :

```cpp
// une fonction "fabrique" par type de Animal
static Animal* makeDog(std::string name)  { return new Dog(name); }
static Animal* makeCat(std::string name)  { return new Cat(name); }
static Animal* makeBird(std::string name) { return new Bird(name); }

Animal* makeAnimal(std::string type, std::string name)
{
    std::string keys[3]                  = {"Dog", "Cat", "Bird"};
    Animal* (*builders[3])(std::string)  = {&makeDog, &makeCat, &makeBird};

    for (int i = 0; i < 3; i++) {
        if (type == keys[i])
            return builders[i](name);   // appel via le pointeur de fonction
    }
    return NULL;   // type inconnu
}
```

### 🔑 Pourquoi c'est mieux qu'une cascade de `if`

- **Lisible et court** : ajouter un type = ajouter une ligne dans deux tableaux.
- **Pas de duplication** de logique (un seul `for`).
- **Évolutif (DRY)** — même esprit que la [délégation au parent](lexique_poo_cpp.md#-pourquoi-cette-approche-est-meilleure) de la Partie 1.

🧠 **Mnémotechnique** : *« Deux tableaux parallèles : les clés d'un côté, les fabriques de l'autre. »*

⚠️ **Attention mémoire** : la fabrique renvoie un objet alloué par `new`. C'est à **l'appelant** de le `delete` (relie ça au [RAII](#-le-déroulement-de-la-pile-stack-unwinding-et-raii)).

🚀 **Contexte 42** : c'est exactement la technique attendue pour `Intern::makeForm("...", "...")` au CPP05, où le sujet **interdit** la forêt de `if/else`. La fabrique renvoie un `AForm*` (pointeur sur la base abstraite) → [polymorphisme](lexique_poo_cpp.md#-polymorphisme-de-sous-type) pur.

---

## 🪄 Foncteur (objet-fonction)

📘 Un **foncteur** (*function object*) est un **objet qu'on peut appeler comme une fonction**. Techniquement : une classe qui **surcharge `operator()`**. On l'utilise exactement comme un appel — `f(x)` — sauf que `f` est un **objet**, pas une fonction.

```cpp
class Multiplier {
private:
    int _factor;
public:
    Multiplier(int factor) : _factor(factor) {}
    int operator()(int x) const { return x * _factor; }   // ← operator()
};

Multiplier triple(3);
std::cout << triple(10);   // 30 — on "appelle" l'objet triple
```

### 🔑 Foncteur vs pointeur de fonction

Les deux sont **callables** (appelables), mais le foncteur a un **superpouvoir** : il **transporte un état**.

| | Pointeur de fonction | Foncteur |
|---|---|---|
| Nature | adresse d'une fonction | objet d'une classe |
| Appel | `f(x)` | `f(x)` (via `operator()`) |
| Peut stocker un état ? | ❌ non | ✅ oui (ses attributs) |
| Usage avec la STL | possible | souvent **préféré** |

Un pointeur de fonction ne pourrait pas "retenir" le facteur 3 ; le foncteur, si — c'est son attribut `_factor`.

🎨 **Métaphore** : un pointeur de fonction, c'est une **recette** affichée au mur (la même pour tous). Un foncteur, c'est un **cuisinier** : il connaît la recette **et** garde ses propres ingrédients en poche (son état). Tu lui dis « cuisine ! », il applique sa recette avec **ses** réglages.

🧠 **Mnémotechnique** : *« Foncteur = un objet qui répond à `()`. »*

🚀 **Contexte 42 (esprit ex01 — `iter`)** : ton template `iter(array, len, f)` accepte `f` **sans savoir** si c'est une fonction libre, un pointeur de fonction ou un foncteur — il lui suffit que `f(element)` soit valide. C'est la force du paramètre de template « callable » : il avale **tout ce qui s'appelle**. (Tu approfondiras les foncteurs avec la STL au CPP08-09.)

---

## 🔄 Conversion implicite vs explicite

📘 **Convertir**, c'est faire passer une donnée d'un **type** à un autre. Le C++ le fait de deux manières : **implicitement** (le compilateur décide tout seul) ou **explicitement** (tu le demandes par un *cast*).

### Implicite — le compilateur le fait dans ton dos

```cpp
int    i = 65;
double d = i;     // int → double : automatique, silencieux
char   c = i;     // int → char  : c devient 'A' (code ASCII 65)
```

Pratique… mais **dangereux** : une conversion qui **perd de l'information** (un `double → int` qui jette la partie décimale) se fait **sans le moindre avertissement**.

### Explicite — tu signes pour la conversion

```cpp
double d = 3.99;
int    i = static_cast<int>(d);   // tu ASSUMES la troncature → i vaut 3
```

🧠 **Mnémotechnique** : *« Explicite = je signe pour la perte. »* Le cast est ta **signature** : tu déclares au compilateur (et au lecteur) que tu **sais** ce que tu fais.

### 🎨 Convertir une valeur ≠ recopier des octets

📘 Un **type scalaire** contient **une seule valeur** : `char` (1 octet), `int` (4), `float` (4), `double` (8). Deux types de **même taille** (un `int` et un `float`, 4 octets chacun) **n'interprètent pas leurs bits de la même façon**.

🎨 **Métaphore** : le mot **« PAIN »** écrit sur un papier se lit « nourriture » en français et « douleur » en anglais. Mêmes lettres (mêmes octets), **sens différent selon la langue (le type)**. Une vraie conversion traduit le **sens**, pas les lettres.

🔑 D'où la distinction qui structure tout le module : convertir une **valeur** (traduire le sens → `static_cast`) n'a **rien à voir** avec réinterpréter des **bits** (relire les mêmes lettres autrement → `reinterpret_cast`).

🚀 **Contexte 42** : le CPP06 insiste sur le mot **« explicitly »** — tu dois convertir avec un cast **visible**, jamais te reposer sur l'implicite. C'est tout l'esprit du module.

---

## 🧰 Pourquoi 4 casts nommés (et pas le cast à la C) ?

📘 En C, il n'existe qu'**un seul** cast : `(type)valeur`. Il fait **tout** — le sûr, le douteux, l'illégal — **sans distinction**. C'est précisément le problème.

```cpp
Animal* a = (Animal*)quelquePointeur;   // conversion logique ? réinterprétation brutale ? mystère.
```

Le C++ **éclate** ce cast unique en **4 opérateurs nommés**, chacun porteur d'une intention claire :

| Cast | Intention | Vérifié à… |
|---|---|---|
| `static_cast` | conversion « logique » entre types liés | la **compilation** |
| `dynamic_cast` | descendre une hiérarchie en **vérifiant** le vrai type | l'**exécution** |
| `reinterpret_cast` | relire les **bits** tels quels (bas niveau) | rien (à tes risques) |
| `const_cast` | ajouter / retirer le `const` | la compilation |

**Ce qu'on y gagne** :
1. **Lisibilité** — le lecteur voit *quel genre* de conversion tu fais.
2. **Sécurité** — le compilateur **refuse** un `static_cast` absurde que le cast C aurait laissé passer en silence.
3. **Audit** — tu peux `grep reinterpret_cast` pour retrouver d'un coup toutes les conversions dangereuses du projet.

🧠 **Mnémotechnique** : *« **S**tatic = sûr · **D**ynamic = vérifié · **R**einterpret = brutal · **C**onst = juste le const. »*

---

## ✅ `static_cast` — la conversion logique

📘 La conversion **standard** entre types **logiquement liés** : entre numériques (`int`↔`float`↔`double`↔`char`), ou dans une hiérarchie de classes **quand tu es sûr** du type. Vérifiée à la **compilation**.

```cpp
double pi = 3.14159;
int    n  = static_cast<int>(pi);    // 3   (troncature assumée)
char   c  = static_cast<char>(65);   // 'A'
float  f  = static_cast<float>(n);   // 3.0f
```

🔑 **Ce qu'il sait faire** :
- Conversions **numériques** (avec perte éventuelle, mais **logique**).
- **Upcast** (fille → mère) : toujours sûr.
- **Downcast** (mère → fille) **sans vérification** : autorisé, mais c'est **à toi** de garantir que le type est bon — sinon comportement indéfini. Pour un downcast **vérifié**, c'est [`dynamic_cast`](#-dynamic_cast--lidentification-vérifiée).

⚠️ **Ce qu'il refuse** : convertir entre types **sans rapport** (ex. `int*` → `float*`). Le compilateur t'arrête — et c'est une **bonne** nouvelle, il t'épargne une bêtise.

🧠 **Mnémotechnique** : *« static_cast = la conversion que tu écrirais "à la main", mais propre et contrôlée. »*

🚀 **Contexte 42 (esprit ex00 — scalaires)** : c'est l'outil pour faire circuler une valeur entre `char`/`int`/`float`/`double`. Mais attention — **trouver** le type de départ à partir d'un texte (`"42.0f"`) n'est **pas** un problème de cast, c'est du **parsing** (de la logique à toi de concevoir). Pense aussi à :
> - `<limits>` (`std::numeric_limits<T>::max()` / `::min()`) pour détecter un **dépassement** (*overflow*) **avant** de convertir ;
> - `<cmath>` pour les valeurs **spéciales** des flottants — `nan`, `+inf`, `-inf` — qui ne sont **pas** des nombres ordinaires (⚠️ `nan != nan` est **vrai** !) ;
> - `isprint` : tout `int` valide ne correspond pas à un caractère **affichable**.

---

## 🔎 `dynamic_cast` — l'identification vérifiée

📘 Sert à **descendre** dans une hiérarchie (mère → fille) **en vérifiant à l'exécution** que la conversion est légitime. Ne fonctionne **que** sur des classes **polymorphes** — au moins une méthode `virtual`, typiquement le [destructeur virtuel](lexique_poo_cpp.md#-le-destructeur-virtual-important-).

```cpp
Animal* a = getSomeAnimal();        // un Animal*… mais lequel, vraiment ?
Dog*    d = dynamic_cast<Dog*>(a);  // est-ce un Dog ?
if (d != NULL)
    std::cout << "C'était bien un Dog !" << std::endl;
```

### 🔑 Le point crucial : pointeur vs référence en cas d'échec

C'est **LE** concept du module — le comportement diffère selon que tu castes un **pointeur** ou une **référence** :

| Tu castes un… | Si la conversion échoue… | Tu testes avec… |
|---|---|---|
| **pointeur** `dynamic_cast<Dog*>` | renvoie **`NULL`** | un `if` |
| **référence** `dynamic_cast<Dog&>` | **lève `std::bad_cast`** | un `try` / `catch` |

```cpp
try {
    Dog& d = dynamic_cast<Dog&>(refAnimal);   // une référence ne peut pas être "nulle"…
    // … c'est un Dog
}
catch (std::bad_cast& e) {
    // … ce n'en était pas un   (lien direct avec le chapitre [Exceptions](#-try--catch--attraper-une-exception) ci-dessus)
}
```

🎨 **Métaphore** : `dynamic_cast` est un **contrôle d'identité**. « Es-tu un Dog ? » Avec un **pointeur**, on te répond « non » poliment (`NULL`). Avec une **référence**, comme tu **affirmais** que c'en était un, on déclenche l'**alarme** (`bad_cast`).

🧠 **Mnémotechnique** : *« dynamic = je vérifie à l'exécution. Pointeur → NULL, référence → exception. »*

🚀 **Contexte 42 (esprit ex02 — vrai type)** : identifier le type réel d'un objet manipulé via sa base, **sans** `typeid` (interdit par le sujet). La technique : tenter un `dynamic_cast` vers chaque type dérivé possible ; celui qui **réussit** révèle le vrai type. Le sujet demande une version **pointeur** **et** une version **référence** précisément pour te faire pratiquer **les deux mécanismes d'échec** (NULL vs exception).

---

## 🔬 RTTI et `typeid`

📘 **RTTI** (*Run-Time Type Information*) est le mécanisme par lequel le C++ **garde la trace du vrai type** d'un objet **à l'exécution**. C'est ce qui rend [`dynamic_cast`](#-dynamic_cast--lidentification-vérifiée) possible : pour vérifier « est-ce vraiment un `Dog` ? », il faut bien que l'information du type réel **existe quelque part** au runtime.

🔑 **Qui active la RTTI ?** Le `virtual`. Dès qu'une classe possède **au moins une méthode virtuelle** (typiquement le destructeur virtuel), le compilateur lui attache de quoi s'identifier à l'exécution (via la [vtable](lexique_poo_cpp.md#️-comment-ça-marche-la-vtable)). C'est pour ça que `dynamic_cast` **exige** une classe polymorphe.

### 🆔 L'opérateur `typeid`

📘 `typeid(expr)` (header `<typeinfo>`) renvoie un objet `std::type_info` qui **décrit le type** de `expr`. Sur un objet polymorphe déréférencé, il donne le **vrai** type dynamique.

```cpp
Base* p = new Dog();
std::cout << typeid(*p).name();   // le type réel : "Dog" (nom décoré, non portable)
```

⚠️ **`typeid` est souvent interdit par les sujets 42** — et c'est volontaire. Le but pédagogique est de te faire **identifier un type sans lui**, uniquement avec des `dynamic_cast` successifs. C'est plus verbeux, mais ça t'oblige à comprendre le polymorphisme **en profondeur** plutôt qu'à lire une étiquette toute faite.

🎨 **Métaphore** : `typeid`, c'est **demander la carte d'identité** (réponse directe). La méthode imposée (`dynamic_cast` en cascade), c'est un **interrogatoire** : « Es-tu un Dog ? Non. Un Cat ? Oui ! » — tu **déduis** le type des réponses.

🧠 **Mnémotechnique** : *« RTTI = le runtime se souvient du vrai type ; `virtual` est l'interrupteur. »*

🚀 **Contexte 42 (esprit ex02)** : identifier le type réel **sans `typeid`** — tu tentes `dynamic_cast<A*>`, `<B*>`, `<C*>` jusqu'à ce que l'un renvoie non-NULL (version pointeur) ou ne lève pas `bad_cast` (version référence). C'est l'application directe de la RTTI, sans le raccourci.

---

## ⚡ `reinterpret_cast` — relire les bits autrement

📘 La conversion **bas niveau** : prendre un paquet de bits et le **réinterpréter** comme un autre type, **sans aucune vérification ni transformation**. Le plus **dangereux** des quatre.

```cpp
Animal*   a   = new Animal();
uintptr_t raw = reinterpret_cast<uintptr_t>(a);   // l'adresse vue comme un entier
Animal*   b   = reinterpret_cast<Animal*>(raw);   // l'entier re-vu comme une adresse
// a == b : l'aller-retour exact redonne le pointeur d'origine, intact
```

🔑 **L'idée** : une adresse mémoire **est** un nombre. `reinterpret_cast` te laisse passer de « pointeur » à « entier » et inversement. Il ne **change pas** les bits — il change seulement **comment on les lit**.

📘 **`uintptr_t`** (`<cstdint>` / `<stdint.h>`) : un entier **non signé** garanti assez grand pour contenir n'importe quelle adresse. C'est le **bon** type pour stocker un pointeur ; un `int` ordinaire **tronquerait** l'adresse sur une machine 64 bits.

🎨 **Métaphore** : regarder la **même photo** à travers des lunettes différentes. La photo (les bits) ne change pas ; ce que tu y vois, oui. Mets les mauvaises lunettes → tu vois n'importe quoi (crash ou bug silencieux).

🧠 **Mnémotechnique** : *« reinterpret = mêmes bits, autre regard. Aucun filet de sécurité. »*

🚀 **Contexte 42 (esprit ex01 — sérialisation)** : *sérialiser*, c'est transformer une donnée en une représentation **stockable/transportable**, puis la **reconstruire** à l'identique (désérialiser). Ici : `pointeur → uintptr_t → pointeur`, et l'aller-retour doit redonner **exactement** le pointeur de départ (c'est la propriété à **vérifier** dans ton programme de test).
> 🎨 Tu notes l'adresse d'une maison sur un papier (sérialiser) ; plus tard, tu relis le papier et retrouves **la même maison** (désérialiser). Le papier ne contient pas la maison — juste de quoi la **retrouver**.

---

## 🔓 `const_cast` — retirer (ou ajouter) le `const`

📘 Le seul cast capable d'**ajouter ou retirer** le qualificatif `const` (ou `volatile`). Il ne change **pas** le type, juste la « constance ».

```cpp
void legacyPrint(char* s);                  // vieille API qui oublie le const

void show(const char* msg) {
    legacyPrint(const_cast<char*>(msg));    // on retire le const pour appeler l'API
}
```

⚠️ **Danger** : retirer le `const` puis **modifier réellement** une variable qui était **vraiment** `const` à l'origine = **comportement indéfini**. `const_cast` ne sert légitimement qu'à **s'interfacer** avec du code mal fichu (souvent du vieux C) qui oublie le `const` — **pas** à tricher avec tes propres `const`.

🧠 **Mnémotechnique** : *« const_cast = j'enlève juste le panneau "interdit", à mes risques. »*

🚀 **Contexte 42** : moins central que les autres au CPP06, mais il **complète le quatuor** des casts à connaître. À comprendre pour la culture et la défense.

---

## 🧮 Tableau de décision : quel cast choisir ?

| Ta situation | Cast à utiliser |
|---|---|
| Convertir un `int` ↔ `double` ↔ `char`… | `static_cast` |
| Monter dans la hiérarchie (fille → mère) | `static_cast` (ou implicite) |
| Descendre (mère → fille) en **vérifiant** le vrai type | `dynamic_cast` |
| « Cet objet de base est-il de tel type dérivé ? » | `dynamic_cast` |
| Transformer un pointeur en entier (ou l'inverse) | `reinterpret_cast` |
| Ajouter / retirer un `const` | `const_cast` |
| Tu hésites entre deux casts | mauvais **design** probable — réfléchis avant de caster |

🔍 **Règle d'or** : demande-toi **toujours** d'abord si `static_cast` suffit. Les trois autres sont des outils de **cas particuliers** (héritage vérifié, bas niveau, const). Un projet truffé de `reinterpret_cast` est presque toujours un projet **mal conçu**.

---

## 🔒 Aparté — la classe utilitaire non instanciable

📘 Certaines classes du CPP06 ne **stockent rien** : elles n'existent que pour **héberger des méthodes `static`** (un convertisseur, un sérialiseur…). Créer un objet d'une telle classe n'aurait aucun sens — on l'**empêche**.

🔑 **Comment ?** En rendant le **constructeur `private`** (déclaré, souvent non implémenté). Sans constructeur accessible, `ScalarConverter sc;` **ne compile pas** ; on appelle alors les méthodes via `ScalarConverter::convert(...)`. (Rappel : la [visibilité](lexique_poo_cpp.md#--public--private---protected---la-visibilité-access-specifiers) de la Partie 1.)

🎨 **Métaphore** : une **boîte à outils murale** — tu te sers d'un outil (`::convert`), tu n'emportes pas le mur. La classe est un **rangement de fonctions**, pas un objet à fabriquer.

🚀 **Contexte 42** : `ScalarConverter` (ex00) et `Serializer` (ex01) sont exactement ça — des classes **non instanciables**, porteuses de méthodes `static` uniquement.

---

## 🧬 La généricité — le problème

📘 La **généricité** (*genericity*) consiste à écrire du code qui **fonctionne pour n'importe quel type**, sans le réécrire pour chacun. En C++, l'outil s'appelle le **template** (*patron*, *modèle*).

### 🤔 Le problème qu'on résout

Imagine une fonction `swap` qui échange deux valeurs. Sans template, tu dois la **dupliquer** pour chaque type :

```cpp
void swap(int& a, int& b)                 { int tmp = a; a = b; b = tmp; }
void swap(double& a, double& b)           { double tmp = a; a = b; b = tmp; }
void swap(std::string& a, std::string& b) { std::string tmp = a; a = b; b = tmp; }
// ... et ainsi de suite pour CHAQUE type. Catastrophe.
```

C'est une violation flagrante du principe [DRY](lexique_poo_cpp.md#-pourquoi-cette-approche-est-meilleure) : la **logique est identique**, seul le **type** change.

🎨 **Métaphore** : un template, c'est un **emporte-pièce**. Le même outil découpe la pâte en cœur, qu'elle soit au chocolat (`int`), à la vanille (`double`) ou aux amandes (`std::string`). Tu ne fabriques pas un emporte-pièce par parfum.

🧠 **Mnémotechnique** : *« Même logique, type variable → template. »*

🚀 **Contexte 42** : tout le CPP07 est dédié aux templates — `swap`/`min`/`max` (ex00), `iter` (ex01), la classe `Array<T>` (ex02).

---

## 🧪 Template de fonction

📘 Un **template de fonction** est un **patron** à partir duquel le compilateur **génère** une vraie fonction pour chaque type utilisé. On le déclare avec `template <typename T>`.

```cpp
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

`T` est un **paramètre de type** : un nom de remplacement pour « le type qu'on précisera plus tard ».

### 🎬 À l'utilisation

```cpp
int x = 5, y = 10;
swap(x, y);                    // le compilateur DÉDUIT T = int

std::string a = "hi", b = "yo";
swap(a, b);                    // ici T = std::string
```

Tu n'écris la logique **qu'une fois** ; le compilateur fabrique une version par type rencontré. C'est l'**instanciation** du template (voir [plus bas](#-instanciation-implicite-vs-explicite)).

🔑 **`T` doit « supporter » ce que tu fais avec.** Si ton template écrit `a > b`, alors `T` doit posséder un `operator>`. Avec `max`, par exemple :

```cpp
template <typename T>
T max(const T& a, const T& b)
{
    return (a > b) ? a : b;   // exige que T ait operator>
}
```

Si tu appelles `max` sur un type sans `operator>`, l'erreur surgit **à la compilation**, au moment de l'instanciation.

🎨 **Métaphore** : le template est un **contrat à trous**. « Donne-moi un type `T` qui sait se comparer avec `>`, et je te rends le plus grand. » Tant que le type honore le contrat, ça marche.

🚀 **Contexte 42 (ex00)** : `swap`, `min`, `max` sont exactement ces templates de fonction. Astuce : on les appelle souvent `::swap(a, b)` avec le `::` pour forcer **ta** version globale et éviter une collision avec `std::swap`.

---

## 🏷️ `typename` vs `class`

📘 Dans la déclaration d'un template, **`typename` et `class` sont strictement équivalents** :

```cpp
template <typename T>   // version 1
template <class T>      // version 2 — exactement la même chose ici
```

Les deux disent : « `T` est un paramètre de type ». Le mot `class` **n'impose pas** que `T` soit une classe — `T` peut très bien être `int` ou `char`.

🔍 **Lequel choisir ?** Question de style. Beaucoup préfèrent **`typename`**, plus honnête (`T` n'est pas forcément une *classe*). Tu verras les deux ; sois juste **cohérent**.

⚠️ **Nuance** : `typename` a un **second** usage (hors paramètre) pour désambiguïser un type dépendant : `typename Conteneur<T>::iterator it;`. Là, `class` ne marcherait pas. Mais pour **déclarer un paramètre**, les deux sont interchangeables.

🧠 **Mnémotechnique** : *« Pour un paramètre de template : `typename` = `class`. »*

🚀 **Contexte 42** : tu peux écrire `template <class T>` ou `template <typename T>` indifféremment dans tes corrections — sache juste **expliquer** qu'ils sont équivalents si on te le demande.

---

## 🎛️ Plusieurs paramètres de template

📘 Un template peut prendre **plusieurs** paramètres de type, séparés par des virgules.

```cpp
template <typename T_array, typename T_function>
void iter(T_array* array, size_t length, T_function func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}
```

Ici **deux** types sont génériques :
- `T_array` : le type des éléments du tableau (`int`, `std::string`…) ;
- `T_function` : le type du **callable** appliqué à chaque élément.

🔑 **Pourquoi rendre la fonction générique aussi ?** Parce que `func` peut être une **fonction libre**, un **pointeur de fonction** ou un [**foncteur**](#-foncteur-objet-fonction). Le template s'en moque : il exige seulement que `func(array[i])` **compile**. C'est la même philosophie que les algorithmes de la STL.

```cpp
void  printInt(int& n)        { std::cout << n << " "; }
void  toUpper(std::string& s) { /* ... */ }

int         nums[3]  = {1, 2, 3};
iter(nums, 3, printInt);              // T_array=int,         T_function=void(*)(int&)

std::string words[2] = {"a", "b"};
iter(words, 2, toUpper);              // T_array=std::string, T_function=void(*)(std::string&)
```

🎨 **Métaphore** : `iter` est une **chaîne de montage** universelle. Tu lui branches un **tapis** (le tableau, n'importe quel type d'objet) et une **machine-outil** (le callable, n'importe quoi qui s'applique). Elle fait défiler et applique, sans se soucier de ce qui passe.

🚀 **Contexte 42 (ex01)** : `iter` illustre à la fois les **templates multiples** et le **paramètre callable** — le pont parfait entre le chapitre [pointeurs de fonction](#-pointeurs-de-fonction) et les templates.

---

## 🗃️ Template de classe

📘 On peut rendre **toute une classe** générique. Elle est alors paramétrée par un (ou plusieurs) type(s). C'est ainsi que sont faits les conteneurs (`std::vector<T>`, et ton `Array<T>`).

```cpp
template <typename T>
class Array
{
private:
    T*           _array;
    unsigned int _size;
public:
    Array(void);
    Array(unsigned int n);
    Array(const Array& other);
    Array&         operator=(const Array& other);
    ~Array(void);

    T&             operator[](int i);          // accès lecture/écriture
    const T&       operator[](int i) const;    // accès lecture seule
    unsigned int   size(void) const;
};
```

`Array<int>`, `Array<std::string>`, `Array<Animal>` sont alors **trois classes distinctes**, générées par le compilateur à partir du même patron.

🔑 **Tout ce que tu sais de la POO reste vrai.** Un template de classe a sa [forme canonique (OCF)](lexique_poo_cpp.md#-la-forme-canonique-orthodoxe-orthodox-canonical-form-ocf), sa [copie profonde](lexique_poo_cpp.md#-lidiome-clone-et-la-copie-profonde-polymorphique) s'il possède un pointeur (`new T[]`), ses exceptions. Le template **ne dispense de rien** — il généralise, c'est tout.

### 🔁 Le double `operator[]` (const et non-const)

⚠️ Tu remarques **deux** surcharges de `operator[]` ci-dessus. Ce n'est pas une erreur, c'est de la **const-correctness** :

```cpp
T&        operator[](int i);         // sur un Array NON-const → peut écrire
const T&  operator[](int i) const;   // sur un Array const     → lecture seule
```

C'est le **`const` en fin de signature** (vu en [Partie 1](lexique_poo_cpp.md#-les-deux-const-dans-une-signature-de-méthode)) qui distingue les deux. Le compilateur choisit **automatiquement** la bonne version selon que l'objet est `const` ou non :

```cpp
Array<int>       a(5);
const Array<int> b(5);

a[0] = 42;                       // ✅ version non-const : écriture autorisée
std::cout << b[0];               // ✅ version const : lecture seule
b[0] = 42;                       // ❌ ERREUR : la version const renvoie const T&
```

🔑 **Pourquoi la version non-const renvoie `T&` (et pas `T`) ?** Pour permettre l'**écriture** `a[0] = 42`. Si elle renvoyait une copie (`T`), tu modifierais un temporaire jeté aussitôt — `a[0] = 42` ne changerait rien.

🧠 **Mnémotechnique** : *« Une paire `operator[]` : la non-const pour écrire, la const pour lire. »*

🎨 **Métaphore** : deux **guichets** pour le même registre. Le guichet « modification » (non-const) te laisse écrire dans le cahier ; le guichet « consultation » (const) te laisse seulement lire. C'est l'objet lui-même (const ou non) qui décide à quel guichet tu as droit.

🚀 **Contexte 42 (ex02)** : `Array<T>` exige cette paire, plus une `OutOfBoundsException` levée si l'indice est hors bornes (relie au chapitre [exceptions](#-créer-ses-propres-exceptions)), et une **copie profonde** (sinon double-free sur le `delete[]`).

---

## 📂 Pourquoi un template vit dans le header

📘 Contrairement à une classe normale (déclaration en `.hpp`, implémentation en `.cpp`), un template doit avoir son **implémentation visible dans le header**. On met donc **tout** dans le `.hpp` — ou dans un fichier `.tpp` **inclus à la fin** du `.hpp`.

```cpp
// Array.hpp
#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array { /* ... déclarations ... */ };

# include "Array.tpp"   // ← l'implémentation, incluse À LA FIN du header
#endif
```

### 🔑 Pourquoi cette contrainte ?

Un template **n'est pas du code** : c'est une **recette pour générer** du code. Tant que personne n'écrit `Array<int>`, **aucune** fonction n'existe réellement. Quand le compilateur rencontre `Array<int>`, il doit **voir la recette complète** (le corps des méthodes) pour fabriquer la version `int`. Si l'implémentation était cachée dans un `.cpp` compilé à part, le compilateur ne la verrait pas au moment de l'instanciation → **erreur de l'éditeur de liens** (*undefined reference*).

🎨 **Métaphore** : une classe normale, c'est un **plat déjà cuisiné** (le `.cpp` compilé) — chaque convive en reçoit une part. Un template, c'est une **recette** : pour que chaque convive cuisine **sa** version (au type voulu), il faut que la recette soit **sous ses yeux** (dans le header), pas enfermée dans la cuisine d'à côté.

🔍 **Les conventions de fichier** :

| Fichier | Contenu | Quand |
|---|---|---|
| `.hpp` seul | déclaration **+** implémentation ensemble | petits templates |
| `.hpp` + `.tpp` | `.hpp` = déclaration, `.tpp` = implémentation (`#include` à la fin du `.hpp`) | gros templates, plus lisible |

⚠️ Le `.tpp` (parfois `.ipp`) **n'est jamais** ajouté au Makefile ni compilé seul : il est **inclus** par le `.hpp`. Le seul point d'entrée reste le header.

🧠 **Mnémotechnique** : *« Template = recette visible → tout dans le header. »*

🚀 **Contexte 42 (ex02)** : c'est exactement le montage `Array.hpp` + `Array.tpp` avec `#include "Array.tpp"` en bas du `.hpp`. Sache **justifier** que séparer dans un `.cpp` casserait l'édition de liens.

---

## ♻️ Instanciation implicite vs explicite

📘 **Instancier un template**, c'est le moment où le compilateur **génère une vraie version** pour un type donné. Deux façons :

### Implicite — le compilateur déduit tout seul

```cpp
swap(x, y);             // x, y sont des int → T=int déduit automatiquement
Array<int> arr(5);      // pour une CLASSE, on précise le type entre < >
```

Pour une **fonction**, le type se déduit des **arguments**. Pour une **classe**, il n'y a pas d'argument à analyser → tu **dois** écrire `<int>`.

### Explicite — tu forces le type

```cpp
swap<double>(x, y);     // je FORCE T=double, même si x, y sont des int
```

Utile quand la déduction est ambiguë ou quand tu veux un type précis.

🔑 **À ne pas confondre** : « instancier un *template* » (générer le type `Array<int>`) ≠ « instancier une *classe* » (créer un objet). Le premier fabrique le **type**, le second fabrique l'**objet**. Pour une classe template, les deux arrivent souvent dans la même ligne : `Array<int> a(5);` instancie **le type** `Array<int>` **puis** **l'objet** `a`.

🎨 **Métaphore** : instancier le template, c'est **usiner le moule** `Array<int>` à partir du plan générique. Instancier la classe, c'est **couler un gâteau** dans ce moule. Un moule (le type), plusieurs gâteaux (les objets).

🧠 **Mnémotechnique** : *« Template → type ; type → objet. Deux étages d'instanciation. »*

🚀 **Contexte 42** : `Array<int> numbers(5);` enchaîne les deux — génération du type `Array<int>` et construction de l'objet `numbers`. Pour `swap`/`iter`, l'instanciation est **implicite** (déduite des arguments).

---

## 🏛️ La STL — vue d'ensemble

📘 La **STL** (*Standard Template Library*) est la bibliothèque générique du C++ : un ensemble de **conteneurs** et d'**algorithmes** déjà écrits, **templatés** (donc valables pour n'importe quel type). C'est l'aboutissement de tout ce que tu as appris : la [généricité](#-la-généricité--le-problème) du CPP07 **mise en pratique à grande échelle**.

Elle repose sur **trois piliers** qui s'emboîtent :

| Pilier | Rôle | Exemples |
|---|---|---|
| **Conteneurs** | **stockent** les données | `vector`, `list`, `deque`, `map`, `stack`… |
| **Itérateurs** | **parcourent** les conteneurs (le « pont ») | `begin()`, `end()` |
| **Algorithmes** | **opèrent** sur les données *via* les itérateurs | `find`, `sort`, `max_element`… |

### 🔑 L'idée géniale : le découplage

Un algorithme **ne connaît pas** le conteneur sur lequel il travaille. Il ne parle qu'aux **itérateurs**. C'est pour ça que `std::find` marche **aussi bien** sur un `vector` que sur une `list` ou un `set` : il demande juste un `begin()` et un `end()`.

```
  Conteneurs  ──fournissent──►  Itérateurs  ◄──consomment──  Algorithmes
  (vector…)                     (begin/end)                  (find, sort…)
```

🎨 **Métaphore** : pense à des **rails de train**. Le conteneur, c'est le **paysage** (ce qui est stocké) ; les itérateurs, ce sont les **rails** posés dessus ; l'algorithme, c'est le **train** qui roule sur les rails. Le train se fiche de savoir si le paysage est une montagne ou une plaine — tant qu'il y a des rails, il avance.

🧠 **Mnémotechnique** : *« Conteneurs + Itérateurs + Algorithmes = STL. Les itérateurs sont la colle. »*

🚀 **Contexte 42** : tout le **CPP08** (« Templated containers, iterators and algorithms ») et le **CPP09** (« STL ») reposent là-dessus. CPP08 t'apprend à **manipuler** la STL ; CPP09 t'apprend à **choisir** le bon outil pour un vrai problème.

---

## 📦 Les conteneurs séquentiels (vector, list, deque)

📘 Un **conteneur séquentiel** range ses éléments dans un **ordre linéaire** (comme une file de personnes) : chaque élément a une position, du premier au dernier. Les trois à connaître en 42 :

| Conteneur | Header | Structure interne | Force | Faiblesse |
|---|---|---|---|---|
| `std::vector<T>` | `<vector>` | tableau **contigu** en mémoire | accès direct `[i]` ultra-rapide, ajout en **fin** rapide | insertion/suppression **au milieu** lente |
| `std::list<T>` | `<list>` | liste **doublement chaînée** | insertion/suppression **partout** rapide | **pas** d'accès `[i]`, parcours seulement |
| `std::deque<T>` | `<deque>` | tableau par **blocs** | rapide aux **deux bouts** (avant **et** arrière), accès `[i]` | un peu plus lourde que `vector` |

### 🎬 `std::vector` — le conteneur par défaut

C'est celui que tu utilises **par défaut** quand tu hésites. Tableau dynamique qui grandit tout seul.

```cpp
std::vector<int> v;
v.push_back(42);        // ajoute en fin
v.push_back(7);
std::cout << v[0];      // accès direct → 42
std::cout << v.size();  // nombre d'éléments → 2
v.insert(v.end(), 99);  // insère à une position (ici, la fin)
```

🚀 **Contexte 42 (CPP08 ex01 — `Span`)** : ton `Span` stocke ses nombres dans un `std::vector<int>`. `addNumber` fait un `push_back` ; `addRange` fait un `insert(tab.end(), first, last)` pour avaler tout un intervalle d'un coup.

```cpp
// Ton code Span — push_back tant qu'il reste de la place, sinon throw
void Span::addNumber(int to_add) {
    if (this->tab.size() < this->tab_size)
        this->tab.push_back(to_add);
    else
        throw SpanFullException();
}
```

### 🎬 `std::list` — la liste chaînée

Pas d'accès `v[i]` : on la parcourt avec des [itérateurs](#-les-itérateurs). Imbattable pour insérer/retirer au milieu sans tout décaler.

```cpp
std::list<long> l;
l.push_back(10);
l.push_front(5);     // ← push_front : impossible sur un vector !
l.pop_back();
```

🚀 **Contexte 42 (CPP09 ex01 — `RPN`)** : ta calculatrice polonaise inverse empile les opérandes dans un `std::list<long>`. (Un `std::stack` conviendrait aussi — voir [adaptateurs](#-les-adaptateurs-de-conteneur-stack-queue-priority_queue) et [choisir le bon conteneur](#-choisir-le-bon-conteneur-la-philosophie-du-cpp09).)

### 🎬 `std::deque` — la double-ended queue

Prononcé « *deck* ». Rapide à **ajouter/retirer aux deux extrémités**, tout en gardant l'accès `[i]`.

```cpp
std::deque<int> d;
d.push_back(1);
d.push_front(0);     // rapide aux DEUX bouts
std::cout << d[1];   // accès direct possible
```

🚀 **Contexte 42 (CPP09 ex02 — `PmergeMe`)** : le sujet impose d'implémenter le **même tri** (Ford-Johnson / merge-insertion) sur **deux conteneurs différents** pour **comparer leurs performances** — typiquement un `std::vector` **et** un `std::deque`. Tout l'enjeu pédagogique : le **choix du conteneur** a un coût mesurable.

🧠 **Mnémotechnique** : *« vector = tableau qui grandit · list = maillons qu'on recoud · deque = tableau ouvert aux deux bouts. »*

---

## 🥞 Les adaptateurs de conteneur (stack, queue, priority_queue)

📘 Un **adaptateur de conteneur** n'est **pas** un nouveau conteneur : c'est une **interface restreinte** posée **par-dessus** un conteneur séquentiel existant. Il **cache** la plupart des opérations pour n'exposer qu'un **comportement précis**.

| Adaptateur | Header | Comportement | Conteneur sous-jacent par défaut |
|---|---|---|---|
| `std::stack<T>` | `<stack>` | **LIFO** (dernier entré, premier sorti) | `std::deque` |
| `std::queue<T>` | `<queue>` | **FIFO** (premier entré, premier sorti) | `std::deque` |
| `std::priority_queue<T>` | `<queue>` | sort toujours le **plus grand** d'abord | `std::vector` |

### 🎬 `std::stack` — la pile LIFO

```cpp
std::stack<int> s;
s.push(1);          // empile
s.push(2);
std::cout << s.top(); // regarde le sommet → 2 (le dernier entré)
s.pop();              // retire le sommet (NE renvoie rien !)
std::cout << s.size();
```

⚠️ **Piège** : `pop()` **ne renvoie pas** l'élément retiré — il le détruit. Pour récupérer la valeur, tu fais `top()` **puis** `pop()`. (Choix de design lié à la sécurité face aux exceptions.)

🎨 **Métaphore** : une **pile d'assiettes**. Tu ne peux poser (`push`) et reprendre (`pop`) **que celle du dessus** (`top`). Impossible de tirer une assiette du milieu.

### 🔑 Le piège fondamental : pas d'itérateurs !

Un adaptateur n'expose **pas** `begin()` / `end()`. Tu ne peux **pas** le parcourir avec un itérateur ni lui appliquer un [algorithme](#-les-algorithmes-algorithm-et-numeric) STL. C'est **voulu** : un adaptateur sert à *restreindre*, pas à explorer.

🚀 **Contexte 42 (CPP08 ex02 — `MutantStack`)** : c'est exactement le **problème** que l'exercice te demande de résoudre. Un `std::stack` « normal » ne se parcourt pas ; tu fabriques un `MutantStack` qui, lui, **expose des itérateurs**. Voir [Hériter d'un conteneur](#-hériter-dun-conteneur-mutantstack).

🧠 **Mnémotechnique** : *« Stack = LIFO, Queue = FIFO. Un adaptateur restreint : pas d'itérateurs. »*

---

## 🗺️ Les conteneurs associatifs (map, set)

📘 Un **conteneur associatif** range ses éléments **triés par clé** (et non par ordre d'insertion). La recherche y est **rapide** (`O(log n)`, arbre binaire équilibré en interne), sans que tu aies à trier toi-même.

| Conteneur | Header | Stocke | Clés en double ? |
|---|---|---|---|
| `std::map<K, V>` | `<map>` | des **paires** clé→valeur | ❌ non (clés uniques) |
| `std::set<K>` | `<set>` | des **clés** seules (un ensemble) | ❌ non |
| `std::multimap` / `std::multiset` | idem | idem | ✅ oui (doublons permis) |

### 🎬 `std::map` — le dictionnaire clé → valeur

C'est le conteneur « **dictionnaire** » : à chaque **clé** unique correspond **une valeur**.

```cpp
std::map<std::string, double> prix;
prix["2011-01-03"] = 0.3;        // insertion / écriture par clé
prix["2011-01-09"] = 0.32;
std::cout << prix["2011-01-03"]; // accès par clé → 0.3
```

🔑 **La recherche : `find` membre, pas l'algorithme**. Un `map` a sa **propre** méthode `find()`, **plus rapide** que `std::find` (elle exploite l'arbre trié). Elle renvoie un [itérateur](#-les-itérateurs), ou `end()` si la clé est absente.

```cpp
std::map<std::string, double>::iterator it = prix.find("2011-01-03");
if (it == prix.end())
    std::cout << "date absente";
else
    std::cout << it->second;   // la VALEUR associée (voir std::pair plus bas)
```

⚠️ **Piège classique** : `prix["clé_inexistante"]` **ne renvoie pas une erreur** — il **crée** silencieusement l'entrée avec une valeur par défaut (`0.0` pour un `double`). Pour **tester** une présence sans créer, utilise `find()`, jamais `[]`.

🚀 **Contexte 42 (CPP09 ex00 — `BitcoinExchange`)** : tu charges la base de prix dans un `std::map<std::string, double>` (date → taux). Pour une date demandée **absente** de la base, le sujet impose de prendre la date **inférieure la plus proche** : c'est là que `lower_bound()` / l'itération sur un map **trié** devient précieuse (le tri automatique par clé te sert directement).

```cpp
// Ton header BitcoinExchange — la base EST un map trié par date
std::map<std::string, double> _database;
```

### 🎬 `std::set` — l'ensemble trié sans doublon

Un `set` ne stocke **que des clés** (pas de valeur associée), garde tout **trié**, et **refuse les doublons** automatiquement.

```cpp
std::set<int> s;
s.insert(3);
s.insert(1);
s.insert(3);          // ignoré : 3 est déjà là
// s contient {1, 3}, triés
```

🧠 **Mnémotechnique** : *« map = dictionnaire (clé→valeur) · set = ensemble (clés seules) · tout est trié, recherche en log(n). »*

---

## 🔗 `std::pair` et l'entrée d'une map

📘 Un `std::pair<A, B>` (header `<utility>`) est un **mini-objet à deux champs** : `.first` (de type `A`) et `.second` (de type `B`). C'est la brique de base d'une `map` : **chaque entrée d'une map est un `pair<const K, V>`**.

```cpp
std::pair<std::string, double> entry("2011-01-03", 0.3);
std::cout << entry.first;    // "2011-01-03"  (la clé)
std::cout << entry.second;   // 0.3           (la valeur)
```

### 🔑 Conséquence directe quand tu parcours une map

Comme un élément de map **est** une paire, tu accèdes à la clé via `->first` et à la valeur via `->second` :

```cpp
std::map<std::string, double>::iterator it;
for (it = prix.begin(); it != prix.end(); ++it)
{
    std::cout << it->first  << " => " << it->second << std::endl;
    //           ↑ la clé              ↑ la valeur
}
```

🎨 **Métaphore** : `it->first` et `it->second`, c'est le **recto/verso** d'une fiche cartonnée. Recto : le mot (la clé). Verso : sa définition (la valeur). L'itérateur te tend la fiche ; à toi de la retourner.

🔧 **`std::make_pair`** construit une paire sans répéter les types :

```cpp
prix.insert(std::make_pair("2011-01-09", 0.32));   // équivaut à prix["2011-01-09"] = 0.32;
```

🧠 **Mnémotechnique** : *« first = clé, second = valeur. Une entrée de map est une paire. »*

---

## ➡️ Les itérateurs

📘 Un **itérateur** est un objet qui **désigne une position** dans un conteneur et sait passer à la **suivante**. C'est une **généralisation du pointeur** : on le déréférence avec `*it` pour lire l'élément, et on avance avec `++it`.

```cpp
std::vector<int> v;
v.push_back(10); v.push_back(20); v.push_back(30);

std::vector<int>::iterator it;
for (it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";   // 10 20 30   (*it = l'élément pointé)
```

### 🔑 `begin()` et `end()` — l'intervalle semi-ouvert `[begin, end)`

- `begin()` pointe sur le **premier** élément.
- `end()` pointe **juste après le dernier** — c'est une **sentinelle**, **pas** un élément valide. On ne le déréférence **jamais**.

```
 indices :   [0]   [1]   [2]
 éléments:    10    20    30
              ▲                 ▲
            begin()           end()  ← "après le dernier", marqueur de fin
```

C'est pour ça que la boucle teste `it != end()` (et non `<=`) : on s'arrête **quand on atteint la sentinelle**.

🧠 **Mnémotechnique** : *« begin pointe le premier, end pointe APRÈS le dernier. L'intervalle est `[begin, end)` — fermé à gauche, ouvert à droite. »*

### 🔑 `*it` et `it->` — comme un pointeur

| Écriture | Sens |
|---|---|
| `*it` | l'**élément** désigné |
| `it->membre` | un membre de l'élément (raccourci de `(*it).membre`) |
| `++it` | avancer à l'élément suivant |

C'est volontairement **identique à la syntaxe des pointeurs** ([Partie 1](lexique_poo_cpp.md#-les-symboles--et--en-c)) : un itérateur **se comporte comme** un pointeur sur un élément.

### 🔍 Les catégories d'itérateurs (culture)

Tous les itérateurs n'offrent pas les mêmes pouvoirs — ça dépend du conteneur :

| Catégorie | Peut… | Conteneurs |
|---|---|---|
| **Bidirectionnel** | `++it` **et** `--it` | `list`, `map`, `set` |
| **Accès aléatoire** | `++`, `--`, **et `it + n`, `it[i]`** | `vector`, `deque` |

C'est pourquoi `std::sort` marche sur un `vector` (accès aléatoire) mais **pas** sur une `list` (qui fournit sa propre méthode `.sort()`).

### 🔍 La variante `const_iterator`

Pour parcourir un conteneur **`const`** (lecture seule), on utilise un `const_iterator` : il interdit de modifier l'élément pointé. C'est la [const-correctness](lexique_poo_cpp.md#-les-deux-const-dans-une-signature-de-méthode) appliquée au parcours.

```cpp
std::vector<int>::const_iterator it;   // sur un vector const
```

🎨 **Métaphore** : un itérateur, c'est un **doigt** qui suit une ligne de texte. `begin()` = le doigt sur le premier mot ; `end()` = le doigt **dans le vide juste après le point final** ; `*it` = le mot sous le doigt ; `++it` = glisser au mot suivant.

🚀 **Contexte 42 (CPP08)** : les itérateurs sont **le** thème du module. `easyfind` renvoie un `T::iterator` ; `Span::addRange` prend deux itérateurs `first`/`last` ; `MutantStack` doit **fabriquer** des itérateurs.

---

## 🏷️ Le pattern `typename T::iterator` (types dépendants)

📘 Quand un template manipule un conteneur générique `T`, le type de son itérateur s'écrit `T::iterator`. Mais le compilateur a besoin du mot-clé **`typename`** devant, pour savoir que `T::iterator` est bien **un type** (et pas une variable statique, par exemple). On appelle ça un **type dépendant** (il *dépend* du paramètre `T`).

```cpp
template <typename T>
typename T::iterator easyfind(T& container, int value)
//  ↑ obligatoire : "T::iterator est un TYPE"
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}
```

### 🔑 Pourquoi `typename` ici précisément ?

Tant que `T` n'est pas connu, le compilateur **ne peut pas deviner** ce qu'est `T::iterator`. Par défaut, il suppose que `T::quelquechose` est une **valeur**. Pour lui dire « non, c'est un **type** », tu ajoutes `typename`. C'est le **second usage** de `typename` annoncé dans le chapitre [`typename` vs `class`](#-typename-vs-class) — celui où `class` **ne marcherait pas**.

⚠️ **Sans `typename`** → erreur de compilation cryptique du genre *« need 'typename' before T::iterator because T is a dependent scope »*. Dès que tu vois ce message, le réflexe est : ajoute `typename`.

🚀 **Contexte 42 (CPP08 ex00 — `easyfind`)** : c'est **exactement** ton code. `easyfind` accepte n'importe quel conteneur `T` contenant des `int`, et renvoie un `typename T::iterator` vers la valeur trouvée (ou `throw` si absente). Le `typename` n'est **pas** décoratif : sans lui, ça ne compile pas.

🧠 **Mnémotechnique** : *« `T::iterator` dépend de `T` → préviens le compilateur avec `typename`. »*

---

## ⚙️ Les algorithmes (`<algorithm>` et `<numeric>`)

📘 Les **algorithmes** de la STL sont des **fonctions templates libres** qui opèrent sur un **intervalle d'itérateurs** `[first, last)`. Ils ne touchent **jamais** le conteneur directement — uniquement ses itérateurs. Résultat : **un seul** `std::sort` trie n'importe quel conteneur à accès aléatoire.

### 🔍 Ceux que tu as croisés en 42

| Algorithme | Header | Rôle | Renvoie |
|---|---|---|---|
| `std::find(b, e, val)` | `<algorithm>` | cherche `val` | un itérateur (ou `e` si absent) |
| `std::sort(b, e)` | `<algorithm>` | trie sur place | rien |
| `std::max_element(b, e)` | `<algorithm>` | itérateur sur le **max** | un itérateur |
| `std::min_element(b, e)` | `<algorithm>` | itérateur sur le **min** | un itérateur |
| `std::distance(b, e)` | `<iterator>` | **nombre** d'éléments entre deux itérateurs | un entier |
| `std::adjacent_difference(b, e, dest)` | `<numeric>` | écrit les **écarts** entre voisins | un itérateur |

### 🔑 L'idiome universel : `if (it == container.end())`

La quasi-totalité des algorithmes de recherche **renvoient `end()` en cas d'échec** (impossible de renvoyer « rien »). D'où le réflexe :

```cpp
std::vector<int>::iterator it = std::find(v.begin(), v.end(), 42);
if (it == v.end())
    std::cout << "pas trouvé";
else
    std::cout << "trouvé : " << *it;
```

🧠 **Mnémotechnique** : *« Trouvé ? On compare à `end()`. `end()` = échec. »*

### 🎬 Tout ça réuni — ton `Span::shortestSpan`

Ton code combine **quatre** algorithmes pour trouver le plus petit écart entre deux nombres :

```cpp
int Span::shortestSpan(void) const
{
    std::vector<int> copytab;
    if (this->tab.size() <= 1)
        throw NoSpanException();
    copytab = this->tab;
    std::sort(copytab.begin(), copytab.end());                       // 1. on trie
    std::adjacent_difference(copytab.begin(), copytab.end(),         // 2. écarts entre voisins
                             copytab.begin());
    return *std::min_element(copytab.begin() + 1, copytab.end());    // 3. le plus petit écart
}
```

🔑 **Pourquoi `begin() + 1` ?** Après `adjacent_difference`, le **premier** élément reste la valeur d'origine (il n'a pas de voisin de gauche) — ce n'est **pas** un écart. On l'ignore en partant de `begin() + 1` (possible car le vector a un itérateur à **accès aléatoire**).

Et ton `longestSpan` montre l'autre combo classique — `max_element` moins `min_element` :

```cpp
result = *std::max_element(tab.begin(), tab.end())
       - *std::min_element(tab.begin(), tab.end());
```

⚠️ **Piège** : `max_element`/`min_element` renvoient un **itérateur**, pas la valeur. Tu dois le **déréférencer** avec `*` pour obtenir le nombre (d'où le `*std::max_element(...)`).

🚀 **Contexte 42 (CPP08 ex01)** : `Span` est le terrain de jeu idéal — il te force à **chaîner** plusieurs algorithmes plutôt que d'écrire des boucles à la main. C'est l'esprit STL : *« décris le QUOI, la STL fournit le COMMENT. »*

🧠 **Mnémotechnique** : *« Un algorithme parle aux itérateurs, jamais au conteneur. Il rend souvent un itérateur — déréférence-le. »*

---

## 🧬 Hériter d'un conteneur (MutantStack)

📘 Comme un [adaptateur](#-les-adaptateurs-de-conteneur-stack-queue-priority_queue) ne fournit pas d'itérateurs, on peut **hériter** de `std::stack` pour lui en **ajouter**. C'est de l'[héritage](lexique_poo_cpp.md#-héritage-inheritance) (Partie 1) appliqué à un type de la STL.

### 🔑 Le secret : le membre protégé `c`

Tout adaptateur (`stack`, `queue`) garde son conteneur sous-jacent dans un attribut **`protected`** nommé **`c`**. Comme il est `protected`, une **classe fille** y a accès — et ce conteneur, lui, **a** des itérateurs.

```cpp
template <class T>
class MutantStack : public std::stack<T>
{
public:
    // le type d'itérateur du conteneur sous-jacent
    typedef typename MutantStack<T>::container_type::iterator iterator;

    iterator begin(void) { return this->c.begin(); }   // c = conteneur interne (protected)
    iterator end(void)   { return this->c.end();   }
};
```

### 🔑 Décortiquer le `typedef`

```cpp
typedef typename MutantStack<T>::container_type::iterator iterator;
//      └──────┬─────┘ └──────────────┬──────────────────┘ └──┬──┘
//      mot-clé type    chemin vers le type d'itérateur     nouveau nom court
```

- `container_type` est le type du conteneur interne (un `std::deque<T>` par défaut), exposé par `std::stack`.
- `::iterator` est **son** type d'itérateur — un [type dépendant](#-le-pattern-typename-titerator-types-dépendants), d'où le **`typename`**.
- Le `typedef` lui donne un **alias court**, `iterator`, pour ne plus réécrire toute la chaîne.

🎨 **Métaphore** : `std::stack`, c'est une **boîte fermée** avec juste une fente sur le dessus (`push`/`pop`). En héritant, tu obtiens la clé d'une **trappe arrière** (`c`) qui donne sur le contenu rangé en ligne — tu peux enfin le **parcourir** du début à la fin.

🚀 **Contexte 42 (CPP08 ex02 — `MutantStack`)** : c'est tout l'exercice. Tu transformes une pile aveugle en pile **parcourable**, sans réécrire la pile — juste en **exposant** son conteneur interne via `begin()`/`end()`. Tu peux alors écrire `for (it = mstack.begin(); it != mstack.end(); ++it)` ou même lui appliquer un [algorithme](#-les-algorithmes-algorithm-et-numeric).

🧠 **Mnémotechnique** : *« Un adaptateur cache son conteneur dans `c` (protected). Hérite, et `c.begin()`/`c.end()` te rendent les itérateurs. »*

---

## 🧭 Choisir le bon conteneur (la philosophie du CPP09)

📘 Le CPP08 t'apprend à **manipuler** la STL ; le CPP09 t'apprend à **choisir**. La vraie compétence n'est pas de connaître `vector` par cœur, mais de répondre à : *« pour CE problème, quel conteneur ? »* Un mauvais choix **fonctionne** mais peut être **lent** ou **maladroit**.

### 🔍 Tableau de décision

| Ton besoin | Conteneur conseillé | Pourquoi |
|---|---|---|
| Accès direct par indice `[i]`, ajout en fin | `std::vector` | contigu, `[i]` instantané |
| Insérer/retirer souvent **au milieu** | `std::list` | pas de décalage |
| Ajouter/retirer aux **deux bouts** | `std::deque` | optimisé recto-verso |
| Associer une **clé** à une **valeur**, recherche rapide | `std::map` | trié, `O(log n)` |
| Garder des éléments **uniques et triés** | `std::set` | doublons refusés |
| Comportement **LIFO** strict (pile) | `std::stack` | interface volontairement réduite |
| Comportement **FIFO** strict (file) | `std::queue` | idem |

### 🚀 Les choix de tes exercices CPP09

| Exercice | Conteneur | Raison du choix |
|---|---|---|
| **ex00 `BitcoinExchange`** | `std::map<std::string, double>` | besoin d'associer **date → taux** et de retrouver la date **la plus proche** → tri automatique par clé indispensable |
| **ex01 `RPN`** | `std::list<long>` (ou `std::stack`) | une calculatrice polonaise inverse **empile/dépile** des opérandes → comportement de pile |
| **ex02 `PmergeMe`** | `std::vector` **et** `std::deque` | le sujet impose **deux** conteneurs pour **comparer** leurs perfs sur le même tri |

⚠️ **Le piège du CPP09** : presque tout « marche » avec un `vector`. Mais le sujet **évalue ton jugement** : utiliser un `map` là où un `map` s'impose, choisir deux conteneurs *vraiment* différents pour `PmergeMe`. Le bon réflexe : pars du **comportement** voulu (clé/valeur ? LIFO ? accès aléatoire ?), pas de ton conteneur préféré.

🎨 **Métaphore** : la STL est une **caisse à outils**. Un `vector`, c'est le **tournevis universel** — il dépanne presque partout. Mais on ne plante pas un clou avec un tournevis : pour une recherche par clé, le `map` est le **bon** outil. Choisir, c'est ça l'ingénierie.

🧠 **Mnémotechnique** : *« Pars du comportement, pas du conteneur. Clé→valeur = map · pile = stack · accès direct = vector. »*

---

## 📚 Termes complémentaires

### 💡 Zoom — l'opérateur ternaire `? :`

📘 L'**opérateur ternaire** est le seul opérateur du C++ à **trois opérandes**. C'est un **`if/else` condensé en une expression** qui **renvoie une valeur**.

```cpp
condition ? valeur_si_vrai : valeur_si_faux
```

Le `?` sépare la condition du premier choix ; le `:` sépare les deux choix.

🎬 **Du `if/else` au ternaire** :

```cpp
// version if/else (5 lignes)
int max;
if (a > b)
    max = a;
else
    max = b;

// version ternaire (1 ligne) — STRICTEMENT équivalente
int max = (a > b) ? a : b;
```

🔑 **Point clé : c'est une *expression*, pas une *instruction*.** Un `if` **exécute** ; un ternaire **produit une valeur** qu'on peut affecter, retourner ou passer en argument :

```cpp
return (a > b) ? a : b;                            // dans un return
std::cout << (isSigned ? "✓ true" : "✗ false");    // directement dans un flux
```

C'est précisément ce qui le rend pratique dans `max`/`min` (CPP07 ex00) ou pour afficher l'état signé d'un `Form` (`getIsSigned`, CPP05).

⚠️ **Piège — lisibilité** : les ternaires **imbriqués** deviennent vite illisibles. Au-delà d'un niveau, repasse au `if/else` :

```cpp
// ❌ illisible
int r = a > b ? (a > c ? a : c) : (b > c ? b : c);
// ✅ un if/else explicite est préférable dès que la logique se complexifie
```

⚠️ **Types compatibles obligatoires** : les deux branches doivent renvoyer un type cohérent. `cond ? 1 : "texte"` ne compile pas (`int` vs `const char*`).

🧠 **Mnémotechnique** : *« condition `?` oui `:` non — un `if` qui rend une valeur. »*

🎨 **Métaphore** : un **aiguillage ferroviaire**. La condition est le levier ; selon sa position, le train (la valeur) part à gauche ou à droite. Dans tous les cas, **un** train sort.

---

| Terme | Définition rapide |
|---|---|
| **Exception** | Objet signalant une erreur, propagé du `throw` jusqu'au `catch` |
| **`throw`** | Lève une exception (corps) **ou** promet de ne rien lever (fin de signature) |
| **`try` / `catch`** | Délimite la zone surveillée / intercepte et traite l'exception |
| **`what()`** | Méthode virtuelle de `std::exception` renvoyant le message (`const char*`) |
| **Classe imbriquée** | Classe déclarée à l'intérieur d'une autre (`Animal::InvalidAgeException`) |
| **Spécification d'exception** | `throw()` en C++98 (≈ `noexcept` en C++11) : « ne lève rien » |
| **Catch polymorphique** | `catch (Base&)` attrape aussi toutes les classes dérivées |
| **Stack unwinding** | Destruction ordonnée des objets locaux entre `throw` et `catch` |
| **RAII** | Acquérir la ressource au constructeur, la libérer au destructeur |
| **`std::terminate`** | Fonction appelée si une exception n'est jamais attrapée → `abort` |
| **Pointeur de fonction** | Variable contenant l'adresse d'une fonction, appelable directement |
| **Cast** | Opérateur de conversion de type ; le C++ en propose 4 nommés |
| **`static_cast`** | Conversion logique entre types liés, vérifiée à la compilation |
| **`dynamic_cast`** | Downcast vérifié à l'exécution (classes polymorphes) ; échec → `NULL` (pointeur) ou `std::bad_cast` (référence) |
| **`reinterpret_cast`** | Réinterprétation brute des bits (pointeur ⇄ entier) ; aucune vérification |
| **`const_cast`** | Ajoute / retire le `const` (ou `volatile`) |
| **Upcast / Downcast** | Convertir fille → mère (sûr) / mère → fille (à vérifier) |
| **`uintptr_t`** | Entier non signé assez grand pour contenir n'importe quelle adresse |
| **Sérialiser** | Transformer une donnée en représentation reconstructible à l'identique |
| **`std::bad_cast`** | Exception levée par un `dynamic_cast` de **référence** qui échoue |
| **Foncteur** | Objet appelable comme une fonction (classe avec `operator()`) ; peut porter un état |
| **`operator()`** | Opérateur d'appel ; le surcharger transforme une classe en foncteur |
| **RTTI** | *Run-Time Type Information* : le runtime garde le vrai type (activé par `virtual`) |
| **`typeid`** | Opérateur renvoyant le type d'une expression (`std::type_info`) ; souvent interdit en 42 |
| **`std::type_info`** | Objet décrivant un type, renvoyé par `typeid` (`<typeinfo>`) |
| **Généricité** | Écrire du code valable pour n'importe quel type, sans le dupliquer |
| **Template** | Patron générant du code pour chaque type utilisé (`template <typename T>`) |
| **Template de fonction** | Patron de fonction (ex. `swap`, `min`, `max`) ; type souvent déduit des arguments |
| **Template de classe** | Patron de classe (ex. `Array<T>`) ; le type se précise entre `< >` |
| **`typename` / `class`** | Équivalents pour déclarer un paramètre de template |
| **Instanciation (template)** | Génération d'une version concrète du patron pour un type donné |
| **`.tpp`** | Fichier d'implémentation d'un template, inclus à la fin du `.hpp` (jamais compilé seul) |
| **Double `operator[]`** | Paire const/non-const : la non-const écrit (`T&`), la const lit (`const T&`) |
| **Opérateur ternaire** | `cond ? a : b` — un `if/else` qui **renvoie une valeur** (expression) |
| **STL** | *Standard Template Library* : conteneurs + itérateurs + algorithmes templatés |
| **Conteneur** | Objet qui **stocke** une collection d'éléments (`vector`, `list`, `map`…) |
| **Conteneur séquentiel** | Éléments en ordre linéaire : `vector`, `list`, `deque` |
| **Conteneur associatif** | Éléments **triés par clé**, recherche `O(log n)` : `map`, `set` |
| **Adaptateur de conteneur** | Interface restreinte sur un conteneur : `stack` (LIFO), `queue` (FIFO) ; **pas** d'itérateurs |
| **`std::vector`** | Tableau dynamique contigu ; accès `[i]` rapide, ajout en fin |
| **`std::list`** | Liste doublement chaînée ; insertion partout, pas d'accès `[i]` |
| **`std::deque`** | Tableau ouvert aux deux bouts ; `push_front` **et** `push_back` rapides |
| **`std::map`** | Dictionnaire clé→valeur, trié, clés uniques |
| **`std::set`** | Ensemble trié de clés uniques (sans valeur associée) |
| **`std::stack`** | Pile LIFO ; `push`/`top`/`pop` (⚠️ `pop` ne renvoie rien) |
| **`std::pair`** | Couple `.first` / `.second` ; brique d'une entrée de map |
| **Itérateur** | Objet « pointeur généralisé » désignant une position ; `*it`, `++it` |
| **`begin()` / `end()`** | Premier élément / **après** le dernier (sentinelle) → intervalle `[begin, end)` |
| **`const_iterator`** | Itérateur de lecture seule (parcours d'un conteneur `const`) |
| **Type dépendant** | Type qui dépend d'un paramètre template (`T::iterator`) → exige `typename` |
| **Algorithme STL** | Fonction template opérant sur `[first, last)` (`find`, `sort`, `min/max_element`…) |
| **`std::find`** | Cherche une valeur ; renvoie un itérateur (ou `end()` si absent) |
| **Idiome `== end()`** | Façon standard de tester l'échec d'une recherche STL |
| **Membre `c`** | Conteneur sous-jacent (`protected`) d'un adaptateur ; clé du MutantStack |

---

## 🎯 Quiz d'auto-évaluation

### Niveau 1 — Mécanisme

1. Quels sont les trois mots-clés du mécanisme d'exception et le rôle de chacun ?
2. Que se passe-t-il dans une fonction après l'exécution d'un `throw` ?
3. Que se passe-t-il si aucun `catch` ne correspond à une exception levée ?
4. De quelle classe doit hériter une exception personnalisée, et quelle méthode redéfinit-elle ?

### Niveau 2 — Subtilités

5. Que signifie le `throw()` à la **fin** de `const char* what() const throw();` ? En quoi diffère-t-il du `throw` dans le corps ?
6. Pourquoi attrape-t-on une exception **par référence** plutôt que par valeur ?
7. Dans quel ordre faut-il placer `catch (Animal::InvalidAgeException&)` et `catch (std::exception&)` ? Pourquoi ?
8. Une classe d'exception doit-elle respecter la forme canonique orthodoxe ?

### Niveau 3 — Mémoire et design

9. Qu'arrive-t-il aux objets locaux sur la pile entre un `throw` et son `catch` ?
10. Pourquoi un `new` sans `delete` est-il dangereux en présence d'exceptions, et comment s'en prémunir ?
11. Pourquoi ne faut-il jamais laisser une exception sortir d'un destructeur ?
12. Comment un tableau de pointeurs de fonction remplace-t-il une cascade de `if/else` ?

### Niveau 4 — Conversions de type (casts)

13. Quels sont les 4 casts du C++, l'intention de chacun, et pourquoi les préférer au cast « à la C » ?
14. Quelle est la différence entre une conversion **implicite** et **explicite** ?
15. À quelle condition une classe peut-elle être la cible d'un `dynamic_cast` ?
16. Que renvoie un `dynamic_cast` de **pointeur** qui échoue ? Et un `dynamic_cast` de **référence** ?
17. Que garantit l'aller-retour `reinterpret_cast` pointeur → entier → pointeur, et pourquoi `uintptr_t` plutôt qu'un `int` ?
18. Pourquoi `reinterpret_cast` est-il le plus dangereux des quatre ?
19. À quoi servent `<limits>` et `<cmath>` quand on convertit des scalaires ?

### Niveau 5 — Généricité et templates

20. Pourquoi un template doit-il avoir son implémentation **dans le header** (et pas dans un `.cpp`) ?
21. Quelle est la différence entre `typename` et `class` dans la déclaration d'un template ?
22. Pourquoi `Array<T>` définit-il **deux** `operator[]` (un const, un non-const) ? Pourquoi la version non-const renvoie-t-elle `T&` plutôt que `T` ?
23. Quelle est la différence entre instancier un *template* et instancier une *classe* ?
24. Qu'est-ce qu'un foncteur, et qu'a-t-il de plus qu'un pointeur de fonction ?
25. Pourquoi le sujet de l'ex02 (CPP06) interdit-il `typeid` alors que ce serait plus simple ? Qu'est-ce que la RTTI ?
26. Réécris `int m; if (a < b) m = a; else m = b;` avec un opérateur ternaire. Quelle nuance entre « instruction » et « expression » cela illustre-t-il ?

### Niveau 6 — La STL (CPP08-09)

27. Quels sont les **trois piliers** de la STL, et pourquoi dit-on que les **itérateurs** sont la « colle » ?
28. Quand préférer un `std::list` à un `std::vector` ? Et un `std::deque` ?
29. Pourquoi un `std::stack` ne se parcourt-il pas avec un itérateur ? Comment le `MutantStack` contourne-t-il ça (rôle du membre `c`) ?
30. Quelle est la différence entre `std::map` et `std::set` ? Pourquoi tester une clé avec `find()` plutôt qu'avec `operator[]` ?
31. Que désignent `it->first` et `it->second` quand on parcourt une `map` ?
32. Que pointe `end()` exactement ? Pourquoi la boucle teste-t-elle `it != end()` et pas `<=` ?
33. Pourquoi faut-il écrire `typename T::iterator` et pas seulement `T::iterator` dans un template ?
34. Que renvoie `std::find` en cas d'échec ? Et `std::max_element` en cas de succès (valeur ou itérateur) ?
35. Pour `BitcoinExchange`, `RPN` et `PmergeMe`, quel conteneur choisirais-tu et **pourquoi** ?

---

*Lexique C++ Partie 2 — exceptions, conversions, templates **et STL** complets. Tu as maintenant tout le vocabulaire du CPP05 au CPP09. Bonne continuation, fducrot !* 🚀
