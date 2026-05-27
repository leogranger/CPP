# 📘 Lexique de la Programmation Orientée Objet en C++

> Référence personnelle universelle pour la POO en C++
> Conçue pour servir tout au long du parcours C++ et au-delà.

**Classe d'exemple utilisée** : `Animal` — choisie parce qu'elle parle naturellement à tout le monde. Tu peux mentalement remplacer `Animal` par n'importe quelle classe (`Fixed`, `User`, `Car`, `Account`...) — les concepts sont **universels**.

**Convention typographique du document** :

| Emoji | Sens |
|---|---|
| 📘 | Définition |
| 🎬 | Exemple complet |
| 🎨 | Métaphore |
| 🧠 | Mnémotechnique |
| ⚠️ | Piège classique |
| 🔍 | Règle pratique / tableau |
| 🚀 | Aperçu de ce qui vient plus tard |

---

## 📑 Table des matières

**Fondamentaux**
1. [Les 4 piliers de la POO (vue d'ensemble)](#-les-4-piliers-de-la-poo-vue-densemble)
2. [Classe](#-classe-class)
3. [Objet / Instance](#-objet--instance-object--instance)
4. [Instancier](#-instancier-to-instantiate)
5. [Attribut / Membre de donnée](#-attribut--membre-de-donnée-attribute--data-member--field)
6. [Fonction membre / Méthode](#-fonction-membre--méthode-member-function--method)
7. [Public / Private / Protected](#--public--private---protected---la-visibilité-access-specifiers)
8. [Encapsulation](#-encapsulation-encapsulation)

**Mémoire et indirection**
9. [Les symboles `&` et `*`](#-les-symboles--et--en-c)
10. [Stack vs Heap](#-stack-vs-heap-pile-vs-tas)

**Cycle de vie d'un objet**
11. [Constructeur](#-constructeur-constructor)
12. [Liste d'initialisation](#-liste-dinitialisation-member-initializer-list)
13. [Constructeur de copie (CRC)](#-constructeur-de-copie--mnémotechnique-crc)
14. [`operator=`](#-operator-opérateur-dassignation)
15. [Destructeur](#-destructeur-destructor)
16. [Les deux `const` dans une signature](#-les-deux-const-dans-une-signature-de-méthode)
17. [`this`](#-this-le-pointeur-magique)
18. [`explicit`](#-explicit-éviter-les-conversions-implicites-pièges)

**Classe — vue d'ensemble**
19. [Static](#-static-membre-statique-static-member)
20. [Surcharge](#-surcharge-overloading)
21. [`friend` et `operator<<`](#-friend-et-operator)
22. [La forme canonique orthodoxe (OCF)](#-la-forme-canonique-orthodoxe-orthodox-canonical-form-ocf)
23. [Header (`.hpp`) vs Source (`.cpp`)](#-header-hpp-vs-source-cpp)

**Héritage et au-delà**
24. [Héritage](#-héritage-inheritance)
25. [`operator=` et constructeur de copie avec héritage](#-operator-et-constructeur-de-copie-avec-héritage)
26. [Héritage en diamant](#-lhéritage-en-diamant)

**Polymorphisme et abstraction (CPP04)**
27. [Polymorphisme (de sous-type)](#-polymorphisme-de-sous-type)
28. [Fonction virtuelle pure et classe abstraite](#-fonction-virtuelle-pure-et-classe-abstraite)
29. [Interface (classe abstraite pure)](#-interface-classe-abstraite-pure)
30. [L'idiome clone() et la copie profonde polymorphique](#-lidiome-clone-et-la-copie-profonde-polymorphique)

**Annexes**
31. [Récap visuel](#-récap-visuel)
32. [Termes complémentaires](#-termes-complémentaires-à-connaître)
33. [Quiz d'auto-évaluation](#-quiz-dauto-évaluation)

---

## 🎓 Les 4 piliers de la POO (vue d'ensemble)

Avant de plonger dans le vocabulaire, situons-le dans le cadre général. La POO repose sur **4 piliers** :

| # | Pilier | Idée centrale | Module 42 |
|---|---|---|---|
| 1 | **Encapsulation** | Cacher les détails, exposer une interface propre | CPP00–CPP02 |
| 2 | **Héritage** | Créer des classes filles qui réutilisent et étendent une classe mère | CPP03 |
| 3 | **Polymorphisme** | Un objet peut se comporter selon plusieurs types | CPP04 |
| 4 | **Abstraction** | Modéliser des concepts sans s'embarrasser des détails d'implémentation | CPP04+ |

L'**encapsulation** est traitée dans ce lexique sous les sections *Public/Private/Protected* et *Encapsulation*. L'**héritage** a sa section dédiée. Le **polymorphisme** et l'**abstraction** seront approfondis au CPP04, mais quelques aperçus sont donnés ici (sections 🚀).

---

## 🏛️ Classe (*class*)

Une **classe** est un **plan de construction**, un *modèle* qui décrit :
- quelles **données** un objet de ce type contiendra,
- quelles **opérations** on pourra faire dessus.

C'est un **type de données** que **toi**, le programmeur, tu inventes.

```cpp
class Animal {
    // description de ce qu'est un Animal :
    // ses attributs (nom, âge, espèce...)
    // ses méthodes (manger, dormir, faireDuBruit...)
};
```

🎨 **Métaphore** : la classe, c'est le **moule** à gâteaux. Le moule en lui-même n'est pas un gâteau — c'est juste la forme qui dit comment fabriquer un gâteau.

---

## 🍰 Objet / Instance (*object / instance*)

Un **objet** (ou **instance**) est une **réalisation concrète** d'une classe en mémoire. C'est un exemplaire vivant du moule.

```cpp
Animal rex;         // rex est UN OBJET, UNE INSTANCE de la classe Animal
Animal whiskers;    // whiskers est UN AUTRE OBJET, UNE AUTRE INSTANCE
```

`rex` et `whiskers` sont **deux instances distinctes** de la même classe `Animal`. Elles partagent la même structure (mêmes attributs, mêmes méthodes), mais elles ont leurs **propres valeurs**.

🎨 **Métaphore** : si la classe `Animal` est le moule, alors `rex` et `whiskers` sont **deux gâteaux** différents sortis du même moule. Ils ont la même forme, mais l'un peut être au chocolat et l'autre à la vanille.

⚠️ **Attention au vocabulaire** : "objet" et "instance" sont **synonymes** dans 99 % des cas. Certains puristes font une nuance, mais en pratique tu peux utiliser indifféremment les deux.

---

## 🌱 Instancier (*to instantiate*)

**Instancier**, c'est l'action de **créer une instance** d'une classe. Le verbe vient directement du nom.

```cpp
Animal rex;                 // ← j'instancie Animal (sur la pile / stack)
Animal* dog = new Animal;   // ← j'instancie Animal (sur le tas / heap)
```

Quand tu écris `Animal rex;`, tu **instancies** la classe `Animal`. Tu fabriques un animal à partir du plan.

**Vocabulaire associé** : on dit aussi *"créer un objet"*, *"construire un objet"*. Le **constructeur** est d'ailleurs la fonction spéciale qui est appelée automatiquement lors de l'instanciation.

---

## 📦 Attribut / Membre de donnée (*attribute / data member / field*)

Un **attribut** est une **variable qui appartient à un objet**. C'est une donnée stockée à l'intérieur de l'instance.

```cpp
class Animal {
private:
    std::string _name;              // ← attribut
    int         _age;               // ← attribut
    static int  _populationCount;   // ← attribut (static, partagé par toute la classe)
};
```

Chaque instance possède **sa propre copie** des attributs (sauf les attributs `static`).

**Synonymes** : tu verras aussi **"champ"** (*field*), **"membre de donnée"** (*data member*), **"propriété"** (*property*, mais c'est plus du vocabulaire C# / JavaScript). En 42, on dit le plus souvent **attribut**.

🎨 **Métaphore** : si un objet `Animal` est un être vivant, ses attributs sont les **caractéristiques** stockées en lui (son nom, son âge, son poids...).

---

## 🛠️ Fonction membre / Méthode (*member function / method*)

Une **fonction membre** (ou **méthode**) est une **fonction qui appartient à une classe**. Elle peut accéder aux attributs des objets de cette classe et opère typiquement sur **un objet précis**.

```cpp
class Animal {
public:
    std::string getName(void) const;        // ← méthode (getter)
    void        setName(std::string name);  // ← méthode (setter)
    void        eat(void);                  // ← méthode (action)
    void        makeSound(void) const;      // ← méthode (action)
};
```

À l'utilisation, tu appelles une méthode **sur un objet** avec la notation point :

```cpp
Animal rex;
rex.setName("Rex");                     // appel de setName sur l'objet rex
std::string name = rex.getName();       // appel de getName sur l'objet rex
rex.makeSound();                        // appel de makeSound sur l'objet rex
```

**Synonymes** : "méthode" et "fonction membre" sont rigoureusement équivalents. Le terme **méthode** vient du monde Java/Python, **fonction membre** est le terme officiel C++. En 42, les deux sont compris.

🎨 **Métaphore** : si les attributs sont les caractéristiques de l'animal, les méthodes sont les **comportements** qu'il peut avoir : `manger()`, `dormir()`, `aboyer()`...

**Convention de ce lexique** : on note `getName(void)` plutôt que `getName()`. C'est la convention 42 (héritée du C) qui rend explicite l'absence de paramètres. En C++ pur, `()` suffit.

---

## 🔓 Public / 🔒 Private / 🛡️ Protected — La visibilité (*access specifiers*)

Ces mots-clés contrôlent **qui peut accéder à quoi** dans une classe. C'est le cœur de l'**encapsulation**.

```cpp
class Animal {
private:
    std::string _name;           // ← personne d'extérieur ne peut y toucher
    int         _age;

public:
    std::string getName(void) const; // ← tout le monde peut l'appeler
    void        eat(void);

protected:
    // accessible par les classes filles (utile en héritage)
    int _energy;
};
```

### 🔒 `private`

Membre **invisible et inaccessible depuis l'extérieur** de la classe. Seules les **méthodes de la classe elle-même** peuvent y toucher.

```cpp
Animal rex;
rex._name = "Rex";    // ❌ ERREUR : _name est private
rex.getName();        // ✅ OK : la méthode est publique, et elle a accès à _name depuis l'intérieur
```

Par défaut, dans une `class`, **tout est `private`** si tu ne précises rien.

### 🔓 `public`

Membre **accessible par tout le monde** (n'importe quel code qui possède une instance).

```cpp
Animal rex;
std::string name = rex.getName();  // ✅ OK
```

### 🛡️ `protected`

Membre accessible par la classe et ses **classes dérivées** (héritage). Tu en verras l'utilité dès que tu attaqueras l'héritage.

🎨 **Métaphore** : pense à une voiture.
- `public` : le volant, les pédales, le levier de vitesse → l'utilisateur les manipule directement.
- `private` : l'injection électronique, le calculateur moteur → cachés sous le capot, l'utilisateur n'y touche pas (et c'est mieux pour tout le monde).
- `protected` : les pièces accessibles seulement par les **mécaniciens d'usine** ou des **modèles dérivés** de la voiture.

---

## 🎯 Encapsulation (*encapsulation*)

L'**encapsulation** est le **principe fondamental de POO** qui consiste à :
1. **Cacher** les détails internes d'un objet (en les mettant `private`).
2. **Exposer** une interface publique propre pour interagir avec lui (méthodes `public`).

C'est pour ça qu'on met les attributs en `private` et qu'on fournit des **getters / setters** publics : tu contrôles **comment** le monde extérieur peut lire et modifier l'état de tes objets.

**Bénéfices** :
- Tu peux changer l'implémentation interne sans casser le code des utilisateurs.
- Tu peux **valider** ce qu'on essaie de faire à ton objet (refuser un âge négatif dans un setter, par exemple).
- Le code utilisateur est plus simple : il n'a pas à connaître les détails internes.

---

## 🎯 Les symboles `&` et `*` en C++

Ces deux symboles sont **piégeux** parce qu'ils ont **plusieurs significations différentes** selon le contexte. C'est exactement ce qui crée la confusion.

### 📌 Le `*` — Trois rôles

#### Rôle 1 : Déclarer un **pointeur**

Un **pointeur** est une variable qui contient l'**adresse mémoire** d'une autre variable.

```cpp
int  x = 42;        // x est un int qui vaut 42
int* p;             // p est un pointeur vers un int (mais ne pointe vers rien encore)
p = &x;             // p contient maintenant l'adresse de x
```

Quand le `*` est dans une **déclaration**, il signifie : *"cette variable est un pointeur."*

```cpp
int*    p;   // pointeur vers int
char*   s;   // pointeur vers char (typiquement une string en C)
Animal* a;   // pointeur vers un objet Animal
```

#### Rôle 2 : **Déréférencer** un pointeur

Une fois que tu as un pointeur, mettre `*` **devant** te permet d'**accéder à la valeur pointée**.

```cpp
int  x = 42;
int* p = &x;     // p contient l'adresse de x

std::cout << p;   // affiche une adresse (genre 0x7ffd1234abcd)
std::cout << *p;  // affiche 42 — la valeur À l'adresse pointée
```

Le `*` ici signifie : *"va chercher ce qu'il y a À l'adresse contenue dans p."*

C'est le même symbole, mais le **contexte change tout** :
- Dans une **déclaration** (`int* p;`), c'est *"je suis un pointeur"*.
- Dans une **expression** (`*p`), c'est *"donne-moi la valeur pointée"*.

#### Rôle 3 : La multiplication

`a * b` reste la multiplication classique. Le contexte (entre deux variables, sans déclaration autour) le distingue facilement.

---

### 📌 Le `&` — Trois rôles

#### Rôle 1 : L'opérateur **"adresse de"**

Quand tu mets `&` **devant une variable**, tu obtiens son **adresse mémoire**.

```cpp
int x = 42;
int* p = &x;   // &x = "donne-moi l'adresse de x"
```

C'est l'**inverse** du déréférencement `*`. Tu peux les voir comme des opérations symétriques :
- `&` : variable → adresse
- `*` : adresse → variable

#### Rôle 2 : Déclarer une **référence**

Quand `&` apparaît dans une **déclaration de variable ou de paramètre**, ce n'est plus l'opérateur "adresse de", c'est un **alias**.

```cpp
int  x = 42;
int& r = x;   // r est UNE RÉFÉRENCE à x — un AUTRE NOM pour x
```

`r` n'est **pas** un pointeur. C'est **littéralement x**, mais avec un nom différent. Si tu modifies `r`, tu modifies `x`. Ils partagent la même case mémoire.

```cpp
int  x = 42;
int& r = x;
r = 100;
std::cout << x;  // affiche 100 ! Parce que r ET x désignent la même variable.
```

**Différences clés entre pointeur et référence** :

| | Pointeur (`int*`) | Référence (`int&`) |
|---|---|---|
| Peut être `NULL` | Oui | Non |
| Peut être réassigné | Oui (`p = &y`) | Non (lié à vie à sa cible) |
| Doit être initialisé | Non | **Oui, obligatoirement** à la déclaration |
| Syntaxe d'accès | `*p`, `p->method()` | Comme la variable elle-même |

#### Rôle 3 : Le ET binaire

`a & b` fait un ET bit-à-bit. Tu n'en auras quasi jamais besoin en POO classique.

---

### 🎬 Exemple complet pour visualiser

```cpp
int x = 42;          // x est une variable (42 quelque part en mémoire)

int* p = &x;         // p est un pointeur (contient l'ADRESSE de x)
                     // & ici = "adresse de"

int& r = x;          // r est une RÉFÉRENCE (un alias pour x)
                     // & ici = "référence" (parce que dans une DÉCLARATION)

std::cout << x;      // 42  — accès direct
std::cout << *p;     // 42  — déréférencement (* = "valeur à l'adresse")
std::cout << r;      // 42  — accès via l'alias

x = 100;
std::cout << *p;     // 100 — p pointe toujours vers x, qui a changé
std::cout << r;      // 100 — r EST x, donc forcément
```

---

### 🔑 Règle d'or pour ne plus confondre

> Si le symbole apparaît **à droite d'un type** (`int*`, `int&`, `Animal&`...), c'est une **déclaration** :
> - `*` = je suis un pointeur
> - `&` = je suis une référence
>
> Si le symbole apparaît **devant une variable** dans du code normal (`*p`, `&x`), c'est un **opérateur** :
> - `*` = déréférencement (donne-moi la valeur)
> - `&` = adresse de (donne-moi l'adresse)

```cpp
// DÉCLARATIONS (à droite du type)
int*  p;        // p est un pointeur
int&  r = x;    // r est une référence

// OPÉRATEURS (devant une variable)
p = &x;         // & = "adresse de x"
int v = *p;     // * = "valeur pointée par p"
```

---

### 🎨 Métaphore pour mémoriser

Imagine une maison.

- **Variable normale** (`int x`) : c'est la maison elle-même. Adresse "12 rue des Lilas".
- **Pointeur** (`int* p`) : c'est un **post-it** sur lequel tu as noté "12 rue des Lilas". Tu peux changer l'adresse écrite sur le post-it, ou le jeter (NULL).
- **Référence** (`int& r`) : c'est un **deuxième nom** officiel pour la maison ("Villa Bellevue"). Le facteur livre au même endroit, peu importe le nom utilisé. Tu ne peux pas changer le nom, et il pointe forcément vers une vraie maison.

---

### 🚀 Cas d'usage typiques en C++

| Situation | Ce qu'on utilise | Pourquoi |
|---|---|---|
| Passer un gros objet à une fonction sans le modifier | `const Type&` | Évite la copie, sécurité |
| Passer un objet à modifier | `Type&` | Modifications visibles à l'extérieur |
| Allocation dynamique | `Type*` avec `new`/`delete` | La référence ne peut pas être `NULL` |
| Constructeur de copie | `const Type&` | Obligatoire (récursion sinon) |
| `operator=` | `const Type&` en paramètre, `Type&` en retour | Idem + chaînage |

---

### ⚠️ Le piège classique avec `*` dans une déclaration

```cpp
int* a, b;   // ATTENTION : a est un int*, mais b est juste un int !
```

Le `*` ne s'applique **qu'à `a`**, pas à `b`. Pour avoir deux pointeurs :

```cpp
int *a, *b;   // les deux sont des pointeurs
// ou mieux :
int* a;
int* b;
```

C'est pour ça que beaucoup préfèrent le style `int* a;` (collé au type) plutôt que `int *a;` (collé au nom) — visuellement, le `*` "appartient" au type.

---

## 🗄️ Stack vs Heap (pile vs tas)

Comprendre **où** vit un objet en mémoire est essentiel pour comprendre **quand** son destructeur est appelé.

### 📚 La pile (*stack*)

La **pile** est gérée **automatiquement** par le compilateur. Les variables locales y vivent.

```cpp
void func() {
    Animal rex;        // rex est sur la PILE
}                      // ← rex est automatiquement détruit ici (fin de scope)
```

**Caractéristiques** :
- **Création / destruction automatique** : tu n'écris pas `new` ni `delete`.
- **Durée de vie** : du `{` ouvrant au `}` fermant du bloc englobant.
- **Rapide** mais **limitée en taille** (quelques Mo).

### 🗃️ Le tas (*heap*)

Le **tas** est de la mémoire **gérée manuellement** par le programmeur via `new` / `delete`.

```cpp
void func() {
    Animal* rex = new Animal;   // rex est sur le TAS
    // ...
    delete rex;                  // ← TU DOIS appeler delete explicitement
}
```

**Caractéristiques** :
- **Création** avec `new`, **destruction** avec `delete`.
- **Durée de vie** : du `new` au `delete`. **Si tu oublies `delete` → fuite mémoire.**
- **Plus lent** mais **beaucoup plus grand** (limité par la RAM disponible).
- Permet une **durée de vie indépendante du scope**.

### 🔍 Quand utiliser quoi ?

| Situation | Préfère |
|---|---|
| Objet à durée de vie connue, taille raisonnable | **Pile** (par défaut) |
| Objet qui doit "survivre" à la fonction qui le crée | **Tas** |
| Objet polymorphique (CPP04) | **Tas** (via pointeur de base) |
| Tableau de taille connue à la compilation | Pile |
| Tableau de taille déterminée à l'exécution | Tas |

🧠 **Mnémotechnique** :
> **"Pile = automatique, Tas = à ta charge."**

### ⚠️ Conséquences pour le destructeur

Le destructeur est appelé **automatiquement** sur la pile, **manuellement** (via `delete`) sur le tas. Si tu fais `new` sans `delete`, le destructeur n'est **jamais** appelé → fuite de toutes les ressources que l'objet possédait.

---

## 🏗️ Constructeur (*constructor*)

Une **fonction membre spéciale** qui est appelée **automatiquement** quand un objet est instancié. Son rôle : **initialiser** l'objet.

**Caractéristiques** :
- Porte **le même nom que la classe**.
- **Pas** de type de retour (même pas `void`).
- Plusieurs constructeurs peuvent coexister (surcharge), tant qu'ils ont des paramètres différents.

```cpp
class Animal {
public:
    Animal(void);                       // constructeur par défaut
    Animal(const Animal& other);        // constructeur de copie
    Animal(std::string name, int age);  // constructeur paramétré
};
```

### Les trois types de constructeurs à connaître

| Type | Signature type | Quand est-il appelé ? |
|---|---|---|
| **Par défaut** | `Animal(void);` | `Animal rex;` (sans paramètres) |
| **Paramétré** | `Animal(std::string name, int age);` | `Animal rex("Rex", 5);` |
| **De copie** | `Animal(const Animal& other);` | `Animal copy(rex);` ou passage par valeur |

---

## 🎯 Liste d'initialisation (*member initializer list*)

La **liste d'initialisation** est la syntaxe avec `:` après la signature du constructeur, qui permet d'**initialiser directement** les attributs au lieu de les **assigner** dans le corps.

```cpp
// ✅ Avec liste d'initialisation (recommandé)
Animal::Animal(std::string name, int age) : _name(name), _age(age)
{
    std::cout << "Animal constructor called" << std::endl;
}

// ⚠️ Sans liste d'initialisation (sub-optimal)
Animal::Animal(std::string name, int age)
{
    this->_name = name;   // assignation, pas initialisation
    this->_age = age;
    std::cout << "Animal constructor called" << std::endl;
}
```

### 🔬 Différence fondamentale : initialisation vs assignation

Les deux versions semblent équivalentes, mais le mécanisme sous-jacent est **différent** :

#### Sans liste d'init (assignation dans le corps)
1. **Étape 1** : tous les attributs sont d'abord initialisés avec leur **constructeur par défaut** (ou laissés avec une valeur indéterminée pour les types primitifs comme `int`).
2. **Étape 2** : dans le corps `{ ... }`, l'opérateur d'**assignation** (`operator=`) écrase la valeur initiale.

→ **Deux étapes**, donc plus coûteux.

#### Avec liste d'init (initialisation directe)
1. **Étape unique** : les attributs sont **directement initialisés** avec la valeur souhaitée.

→ **Une seule étape**, plus efficace.

### ⚠️ Cas où la liste d'init est OBLIGATOIRE

Pour certains types d'attributs, la liste d'initialisation n'est **pas un choix** — c'est la **seule façon** qui compile.

#### Cas 1 : Attributs `const`

```cpp
class Animal {
private:
    const std::string _species;   // const !
};

// ❌ ERREUR : on ne peut pas assigner à un const
Animal::Animal(std::string s) { this->_species = s; }

// ✅ OK : initialisation directe via la liste
Animal::Animal(std::string s) : _species(s) {}
```

Un `const` ne peut être fixé **qu'à sa naissance**. Une fois né, plus de modification possible.

#### Cas 2 : Attributs de type référence

```cpp
class Animal {
private:
    Owner& _owner;   // référence !
};
```

Une référence **doit** être liée à sa cible dès sa naissance. Pas d'assignation possible.

#### Cas 3 : Attributs sans constructeur par défaut

Si un attribut est un objet d'une classe qui n'a **pas** de constructeur par défaut, il **doit** être initialisé directement via la liste.

### 📊 Tableau comparatif

| | Assignation dans le corps | Liste d'initialisation |
|---|---|---|
| **Étapes** | 2 (init défaut + assignation) | 1 (init directe) |
| **Performance** | Plus lent (surtout pour objets complexes) | Plus rapide |
| **Pour les `int`** | Fonctionne mais sub-optimal | Idiomatique |
| **Pour les `const`** | ❌ Ne compile pas | ✅ Obligatoire |
| **Pour les références** | ❌ Ne compile pas | ✅ Obligatoire |
| **Style 42** | Toléré | **Attendu** |

### ⚠️ Piège : l'ordre d'initialisation

Les attributs sont initialisés dans l'**ordre de leur déclaration dans la classe**, **pas** dans l'ordre de la liste d'init.

```cpp
class Animal {
private:
    int _age;       // déclaré en premier → initialisé en premier
    int _doubleAge; // déclaré en second  → initialisé en second
};

Animal::Animal(int age) : _doubleAge(age * 2), _age(age) { }
//                        ↑ apparaît en premier dans la liste
//                          MAIS _age est initialisé AVANT _doubleAge
```

🔍 **Règle pratique** : pour éviter la confusion, **liste d'init dans le même ordre que les déclarations** dans la classe.

---

## 🧬 Constructeur de copie — Mnémotechnique **CRC**

Pour ne jamais oublier la **signature** du constructeur de copie, retiens **CRC** :

- **C**lasse — il porte le nom de la classe
- **R**éférence — le paramètre est une référence (`&`)
- **C**onst — la référence est constante (`const`)

```cpp
Animal(const Animal& other);
//     └─C─┘ └─C─┘└R┘
```

**Pourquoi ces 3 contraintes ?**

- **Const** : tu ne dois pas modifier l'objet source (sinon, copier `rex` modifierait `rex`, ce serait absurde).
- **Référence** : sans `&`, tu passerais le paramètre **par valeur**, ce qui appellerait... le constructeur de copie. Récursion infinie, crash.
- **Classe** : c'est un constructeur, donc même nom que la classe.

🧠 **Phrase magique associée** : *« Je nais comme toi. »* Tu prends la perspective du nouvel objet : *"je viens de naître, et je veux ressembler à `other`."*

Cette phrase t'évite la confusion avec `operator=` (*"je change pour devenir comme toi"*) :

| Fonction | Phrase mentale |
|---|---|
| Constructeur de copie | *"Je **nais** comme toi"* |
| `operator=` | *"Je **change** pour devenir comme toi"* |

**Quand le constructeur de copie est-il appelé ?** Souviens-toi de **« I-P-R »** :

- **I**nitialisation : `Animal copy(rex);` ou `Animal copy = rex;`
- **P**aramètre passé par valeur : `void func(Animal a);`
- **R**etour par valeur : `Animal make() { return local; }`

### 🎬 Exemple complet

```cpp
// Animal.hpp
class Animal {
private:
    std::string _name;
    int         _age;
public:
    Animal(const Animal& other);
};

// Animal.cpp
Animal::Animal(const Animal& other) : _name(other._name), _age(other._age)
{
    std::cout << "Animal copy constructor called" << std::endl;
}
```

Note : on accède aux attributs `private` d'`other` parce qu'on est **dans la même classe**. Une classe a accès aux membres privés de **toutes ses instances**, pas seulement à `this`.

---

## 🟰 `operator=` (opérateur d'assignation)

L'**opérateur d'assignation** est la méthode appelée quand tu fais `a = b` entre deux objets **déjà existants**.

### 🎯 La différence avec le constructeur de copie

```cpp
Animal rex("Rex", 5);
Animal copy(rex);     // ← constructeur de COPIE (copy est NOUVEAU)
Animal milo("Milo", 3);
milo = rex;           // ← operator= (milo existait DÉJÀ)
```

| | Constructeur de copie | `operator=` |
|---|---|---|
| Quand ? | À la **naissance** d'un objet | Sur un objet **existant** |
| Phrase | *"Je nais comme toi"* | *"Je change pour devenir comme toi"* |
| Syntaxe d'appel | `Animal copy(rex);` | `milo = rex;` |

### 📐 La forme canonique

```cpp
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)        // 1. protection contre l'auto-assignation
    {
        this->_name = other._name;   // 2. copier chaque attribut
        this->_age  = other._age;
    }
    return (*this);            // 3. retourner *this pour permettre le chaînage
}
```

**Trois points clés** :

#### 1️⃣ Le check `if (this != &other)`

Empêche les bêtises lors d'une auto-assignation (`rex = rex;`). Sans ce check, dans certains cas (allocation dynamique notamment), tu détruirais une ressource avant de la copier — segfault.

🧠 **Mnémotechnique** : *"Avant de me copier sur toi, je vérifie qu'on n'est pas la même personne."*

#### 2️⃣ Le retour par **référence** (`Animal&`)

Permet le **chaînage** :

```cpp
Animal a, b, c;
a = b = c;     // équivalent à : a = (b = c);
               // possible grâce au retour par référence
```

Sans le retour par référence, on créerait une copie temporaire à chaque maillon de la chaîne — coûteux et parfois bogué.

#### 3️⃣ Le `return (*this);`

`this` est un pointeur sur l'objet courant ; `*this` est l'objet lui-même. On retourne l'objet par référence pour permettre le chaînage.

### ⚠️ Pièges classiques

| Piège | Conséquence |
|---|---|
| Oublier `if (this != &other)` | Possibles bugs sur auto-assignation |
| Retourner par valeur au lieu de référence | Copies inutiles, chaînage moins efficace |
| Oublier `return (*this);` | Comportement indéfini ! |
| Confondre avec le constructeur de copie | Mauvais comportement selon le contexte |

🎬 **Tu verras dès le CPP01** que l'OCF impose à la fois constructeur de copie ET `operator=` — pas l'un sans l'autre.

---

## ⚰️ Destructeur (*destructor*)

Le **destructeur** est une **fonction membre spéciale** appelée **automatiquement** quand un objet est détruit. Son rôle : **nettoyer** ce que l'objet a alloué (mémoire, fichiers ouverts, etc.).

```cpp
class Animal {
public:
    Animal(void);     // constructeur
    ~Animal(void);    // destructeur (tilde + nom de la classe)
};
```

**Caractéristiques** :
- Nom : **tilde `~` + nom de la classe**.
- **Pas** de type de retour, **pas** de paramètres.
- **Un seul** destructeur par classe (pas de surcharge possible).
- Appelé **automatiquement** par le compilateur.

### 🎯 Quand le destructeur est-il appelé ?

| Type d'objet | Destruction |
|---|---|
| Variable locale (pile) | Fin du scope `{ ... }` |
| Variable globale | Fin du programme |
| Membre d'un objet | Quand l'objet conteneur est détruit |
| Objet créé avec `new` | Quand tu appelles `delete` |
| Objet créé avec `new[]` | Quand tu appelles `delete[]` |

```cpp
{
    Animal rex;          // → constructeur appelé
    Animal* milo = new Animal;
    delete milo;         // → destructeur de milo appelé
}                        // → destructeur de rex appelé (fin de scope)
```

### 🧹 Ce que le destructeur fait

Pour les classes simples (sans allocation dynamique), le destructeur n'a souvent **rien à faire** — le compilateur génère un destructeur par défaut qui détruit chaque attribut.

Mais dès que ta classe **possède** une ressource (mémoire allouée par `new`, fichier ouvert, socket...), tu **dois** la libérer dans le destructeur :

```cpp
class Animal {
private:
    char* _bigBuffer;
public:
    Animal(void)  { _bigBuffer = new char[1024]; }
    ~Animal(void) { delete[] _bigBuffer; }       // ← obligatoire
};
```

Sans cette libération → **fuite mémoire**.

### ⚠️ Le destructeur `virtual` (important !)

Si une classe est **destinée à être héritée**, son destructeur **doit** être `virtual` :

```cpp
class Animal {
public:
    virtual ~Animal(void);   // ← virtual !
};
```

**Pourquoi ?** Sans `virtual`, lors d'une destruction polymorphique (via un pointeur `Animal*` vers un `Dog`), le destructeur de `Dog` **ne serait pas appelé** → fuite mémoire des ressources spécifiques à `Dog`.

Le détail du pourquoi est dans le pilier **polymorphisme** (CPP04), mais retiens **dès maintenant** : si ta classe est conçue pour être héritée, destructeur = `virtual`.

### 🧠 La règle des 3 (et règle des 5)

En dehors de la convention 42, le monde C++ parle de :

- **Règle des 3** (C++98) : si tu définis l'**un** des trois — destructeur, constructeur de copie, `operator=` — tu devrais définir **les trois**. C'est la base de l'**OCF** vue plus loin.
- **Règle des 5** (C++11+) : avec la sémantique de mouvement, on ajoute le constructeur de déplacement et l'`operator=` de déplacement.

42 te demande la **règle des 4** (OCF), qui ajoute le constructeur par défaut aux trois précédents.

---

## 🛡️ Les deux `const` dans une signature de méthode

Une signature comme celle-ci contient **deux `const` indépendants** qui protègent **deux choses différentes** :

```cpp
bool Animal::operator<(Animal const& input) const
//                     ↑                   ↑
//                  const #1            const #2
```

### Const #1 : `const` sur le paramètre — protège l'opérande de droite

```cpp
Animal const& input    // équivalent à : const Animal& input
```

Ce `const` dit : *"`input` est une référence à un `Animal`, et je promets de **ne pas modifier** ce `Animal` à travers cette référence."*

**Pourquoi c'est nécessaire ?** Quand tu écris `a < b`, l'opérande de droite (`b`) est passé en paramètre sous le nom `input`. Tu ne veux pas que comparer modifie `b` — sinon ce serait absurde !

C'est aussi un **contrat** : tu garantis aux utilisateurs que la comparaison ne modifie pas leur objet.

**Note de syntaxe** : `Animal const&` et `const Animal&` sont **strictement équivalents**. Question de style.

### Const #2 : `const` à la fin — protège l'opérande de gauche (`this`)

```cpp
bool Animal::operator<(Animal const& input) const
//                                          ↑
//                                    ce const-ci
```

Ce `const`, qu'on appelle **"const de méthode"** ou **"trailing const"**, dit : *"cette méthode promet de **ne pas modifier** l'objet sur lequel elle est appelée (c'est-à-dire `*this`)."*

**Pourquoi c'est crucial ?** Sans ce `const`, ta méthode **ne peut pas être appelée sur un objet `const`** :

```cpp
Animal const rex("Rex", 5);
Animal milo("Milo", 3);
if (milo < rex) { ... }   // ❌ ERREUR si operator< n'a pas le const final
                          //    (rex est const, le compilateur refuse)
```

Le compilateur refuse d'appeler une méthode non-const sur un objet const, parce qu'il ne peut pas garantir qu'elle ne modifierait pas l'objet.

### 📊 Récapitulatif

| Const | Protège | Empêche | Permet de... |
|---|---|---|---|
| `const` sur le paramètre | L'opérande de droite (`input`) | De modifier `input` dans le corps | Accepter des arguments const |
| `const` à la fin | L'opérande de gauche (`this`) | De modifier `this` dans le corps | Appeler la méthode sur un objet const |

### 🎨 Métaphore pour mémoriser

Imagine que tu compares deux livres pour savoir lequel est le plus épais.

- **Const sur le paramètre** : *"Je promets de ne pas écorner le livre que tu me passes en main droite."*
- **Const de méthode** : *"Je promets de ne pas écorner le livre que je tiens dans ma main gauche (`this`) non plus."*

Les deux mains sont protégées. Tu peux donc comparer même des **livres précieux** (des objets `const`) sans que la bibliothécaire t'arrête.

### 🔍 Règle pratique : quand mettre le `const` final ?

| Type de méthode | `const` final ? | Exemples |
|---|---|---|
| **Getters / lecture seule** | ✅ Oui | `getName(void) const`, `toFloat(void) const` |
| **Comparaisons** | ✅ Oui | `operator< const`, `operator== const` |
| **Opérateurs arithmétiques** | ✅ Oui | `operator+ const`, `operator- const` |
| **Méthodes d'affichage** | ✅ Oui | `print(void) const`, `display(void) const` |
| **Setters** | ❌ Non | `setName(string)`, `setAge(int)` |
| **Opérateurs modifiants** | ❌ Non | `operator++`, `operator+=`, `operator=` |
| **Constructeurs / Destructeur** | ❌ Non | (créent ou détruisent l'objet) |

**Règle simple** : si la méthode **ne modifie pas** l'état de l'objet, mets `const`. Sinon, ne le mets pas.

### ⚠️ Le piège classique des opérateurs arithmétiques

Pour bien fixer la nuance :

```cpp
// Opérateur d'addition : crée un NOUVEL objet, ne modifie ni a ni b
Animal Animal::operator+(const Animal& other) const;   // ← const à la fin

// Opérateur d'incrément : modifie this (l'incrémente)
Animal& Animal::operator++(void);                       // ← PAS de const à la fin
```

`a + b` ne modifie **ni `a` ni `b`** — il retourne un troisième objet qui est leur somme. Donc `const` final.

`++a` modifie **`a`**. Donc pas de `const` final.

---

## 🔗 `this` (le pointeur magique)

À l'intérieur d'une méthode, **`this`** est un **pointeur** vers l'objet sur lequel la méthode a été appelée.

```cpp
void Animal::setName(std::string name) {
    this->_name = name;   // this pointe vers l'objet courant
    // équivalent à : _name = name;
}
```

```cpp
Animal rex;
rex.setName("Rex");   // dans setName, this == &rex
```

**Pourquoi c'est utile ?**
- Distinguer un attribut d'un paramètre qui aurait le même nom.
- Retourner l'objet lui-même (utile pour `operator=` et le chaînage).
- Comparer l'identité de deux objets (`if (this != &other)` dans `operator=`).

⚠️ **`this` n'existe pas dans une méthode `static`** — une méthode static ne s'applique à aucun objet en particulier.

---

## 🚫 `explicit` (éviter les conversions implicites pièges)

Quand une classe a un **constructeur à un seul argument**, le compilateur s'autorise par défaut à l'utiliser pour faire des **conversions implicites**. Souvent surprenant, parfois dangereux.

```cpp
class Fixed {
public:
    Fixed(int n);          // constructeur à 1 argument
};

void func(Fixed f);

func(42);   // ❌ Tu pensais passer un int...
            //    Le compilateur a CONSTRUIT silencieusement un Fixed(42) !
```

Le compilateur a fait : `func(Fixed(42));` — sans rien te demander.

### ✅ La solution : `explicit`

Ajoute `explicit` devant le constructeur. Il ne sera utilisable **que de façon explicite** :

```cpp
class Fixed {
public:
    explicit Fixed(int n);   // ← explicit !
};

func(42);          // ❌ ERREUR de compilation : conversion implicite refusée
func(Fixed(42));   // ✅ OK : conversion EXPLICITE
```

### 🔍 Quand utiliser `explicit` ?

| Situation | `explicit` ? |
|---|---|
| Constructeur à 1 argument numérique (`Fixed(int)`, `Fixed(float)`) | ✅ Souvent recommandé |
| Constructeur à 2+ arguments | Pas nécessaire (pas de conversion implicite) |
| Constructeur de copie | Pas nécessaire (cas spécial du langage) |
| Quand tu **veux** explicitement permettre la conversion | ❌ Ne pas mettre |

⚠️ Le sujet du CPP02 (`Fixed`) ne demande **pas** `explicit`, mais c'est une bonne pratique à connaître pour la culture C++.

---

## 🌍 Static (membre statique) (*static member*)

Un attribut ou une méthode marqué `static` **appartient à la classe**, pas aux instances. Il n'existe qu'**en une seule copie**, partagée par tous les objets.

```cpp
class Animal {
private:
    std::string _name;                   // un par instance
    static int  _populationCount;        // UN SEUL pour toute la classe
public:
    static int getPopulationCount(void); // méthode static
};
```

**Méthode static** : elle peut être appelée **sans instance**, avec la notation `ClassName::method()` :

```cpp
int total = Animal::getPopulationCount();  // pas besoin d'avoir un Animal pour appeler ça
```

🎨 **Métaphore** : si chaque animal a son propre nom (attribut normal), un **compteur global** de la population (attribut static) est partagé et accessible à tous, sans qu'il appartienne à un animal en particulier.

### ⚠️ Piège #1 : `static` ne se met QUE dans la déclaration

`static` doit apparaître **uniquement dans le `.hpp`** (déclaration), **pas dans le `.cpp`** (définition).

```cpp
// Animal.hpp
class Animal {
public:
    static int getPopulationCount(void);   // ✅ static ici
};

// Animal.cpp
int Animal::getPopulationCount(void)       // ✅ PAS de static ici
{
    return _populationCount;
}

// ❌ ERREUR si tu écris :
static int Animal::getPopulationCount(void) { ... }   // erreur de compilation
```

C'est une bizarrerie historique : `static` dans le `.cpp` aurait un sens **complètement différent** (lié à la portée de fichier, héritage du C). Le compilateur t'arrête net.

### ⚠️ Piège #2 : Initialiser un attribut static

Un attribut static **doit être défini hors de la classe**, dans le `.cpp` :

```cpp
// Animal.hpp
class Animal {
private:
    static int _populationCount;   // déclaration
};

// Animal.cpp
int Animal::_populationCount = 0;  // ← définition + initialisation (obligatoire)
```

Sans cette ligne dans le `.cpp` → erreur de l'éditeur de liens (`undefined reference`).

### 🔍 Quand utiliser `static` ?

| Situation | Static ? | Pourquoi |
|---|---|---|
| Compteur global de toutes les instances | ✅ | Appartient à la classe, pas à une instance |
| Constante de classe (ex: nombre de bits, max value) | ✅ | Partagée, ne change pas par instance |
| Méthode utilitaire qui ne dépend d'aucune instance | ✅ | Symétrie, pas d'objet "principal" |
| Getter/setter d'un attribut d'instance | ❌ | A besoin de `this` |
| Méthode qui modifie l'état d'un objet | ❌ | A besoin de `this` |

### 🎯 Récapitulatif des règles `static`

| Aspect | Règle |
|---|---|
| **Où mettre `static`** | Uniquement dans la **déclaration** (`.hpp`) |
| **Comment l'appeler** | `ClassName::method(...)` (sans objet) |
| **Accès à `this`** | ❌ Aucun (pas d'objet appelant) |
| **Accès aux attributs d'instance** | ❌ Pas direct (mais via paramètres oui) |
| **Accès aux membres static de la classe** | ✅ Oui |
| **Initialisation d'un attribut `static`** | Dans le `.cpp`, hors de toute fonction : `int Animal::_x = 8;` |

---

## 🎭 Surcharge (*overloading*)

Avoir **plusieurs fonctions du même nom**, mais avec des **paramètres différents**. Le compilateur choisit laquelle appeler selon les arguments fournis.

```cpp
class Animal {
public:
    Animal(void);                       // surcharge 1
    Animal(std::string name);           // surcharge 2
    Animal(std::string name, int age);  // surcharge 3
};

Animal a;                  // appelle surcharge 1
Animal b("Rex");           // appelle surcharge 2
Animal c("Rex", 5);        // appelle surcharge 3
```

⚠️ **Ne pas confondre** avec la **surcharge d'opérateur**, qui est un cas particulier où on surcharge `operator+`, `operator==`, etc.

**Le terme savant** pour la surcharge est le **"polymorphisme ad-hoc"** — à ne pas confondre avec le polymorphisme classique (lié à l'héritage, vu au CPP04).

---

## 👥 `friend` et `operator<<`

Le mot-clé `friend` permet à une **fonction libre** (non-membre) d'accéder aux membres **privés** d'une classe. Son usage le plus typique : surcharger `operator<<` pour pouvoir afficher un objet avec `std::cout`.

### 🎯 Le problème

Tu voudrais pouvoir écrire :

```cpp
Animal rex("Rex", 5);
std::cout << rex << std::endl;   // afficher l'objet directement
```

Pour ça, il faut **surcharger `operator<<`**. Mais cet opérateur prend `std::ostream&` à gauche, pas un `Animal`. Donc il ne peut **pas** être une méthode membre d'`Animal`. C'est une **fonction libre**.

### 📐 La solution

```cpp
// Animal.hpp
class Animal {
private:
    std::string _name;
    int         _age;
public:
    // Déclarer la fonction libre comme amie de la classe
    friend std::ostream& operator<<(std::ostream& os, const Animal& a);
};

// Animal.cpp (ou directement après la classe)
std::ostream& operator<<(std::ostream& os, const Animal& a)
{
    os << "Animal(" << a._name << ", " << a._age << ")";
    //              ↑                ↑
    //         accès à _name (private) — autorisé grâce à friend
    return os;   // retourne l'ostream pour permettre le chaînage
}
```

**À noter** :
- La fonction `operator<<` est **libre**, pas membre d'`Animal`.
- Le mot-clé `friend` dans la classe lui donne accès aux membres privés.
- Elle retourne `std::ostream&` pour permettre le chaînage : `cout << a << b << c`.

### 🔍 Quand utiliser `friend` ?

| Situation | `friend` ? |
|---|---|
| `operator<<` (affichage) | ✅ Cas typique |
| `operator>>` (lecture) | ✅ Idem |
| Pouvoir éviter d'écrire des getters publics pour TOUT exposer | ❌ Préfère les getters propres |
| Fonction utilitaire qui a vraiment besoin de l'accès interne | ✅ Avec parcimonie |

⚠️ **Attention** : abuser de `friend` casse l'encapsulation. À utiliser quand c'est vraiment justifié (cas de `operator<<`).

---

## 📋 La forme canonique orthodoxe (*Orthodox Canonical Form*, OCF)

C'est la **convention** qui dit qu'une classe "bien formée" en C++98 doit définir **les 4 fonctions membres spéciales** suivantes :

| # | Nom | Signature | Rôle |
|---|---|---|---|
| 1 | Constructeur par défaut | `Animal(void)` | Créer un objet sans paramètres |
| 2 | Constructeur de copie | `Animal(const Animal& other)` | Créer un objet à partir d'un autre |
| 3 | Opérateur d'assignation | `Animal& operator=(const Animal& other)` | Copier dans un objet existant |
| 4 | Destructeur | `~Animal(void)` | Nettoyer à la mort de l'objet |

C'est **la règle non négociable** dans la plupart des projets C++ pédagogiques en 42 (CPP00 → CPP04).

### 🎬 Squelette d'OCF complet

```cpp
class Animal {
private:
    std::string _name;
    int         _age;

public:
    Animal(void);                                // 1. constructeur par défaut
    Animal(const Animal& other);                 // 2. constructeur de copie
    Animal& operator=(const Animal& other);      // 3. operator=
    ~Animal(void);                               // 4. destructeur

    // ... autres méthodes ...
};
```

### 🧠 Astuce de mémorisation

> **"Naissance, Copie, Changement, Mort."**
>
> 1. Naissance (par défaut)
> 2. Copie (constructeur de copie)
> 3. Changement (operator=)
> 4. Mort (destructeur)

### 🔗 Lien avec la "Règle des 3"

L'OCF de 42 est la version "+1 constructeur par défaut" de la **Règle des 3** du monde C++ :

> Si tu définis l'**un** parmi {destructeur, constructeur de copie, `operator=`}, tu devrais définir **les trois**. Sinon, le comportement par défaut du compilateur peut causer des fuites/bugs.

42 ajoute le constructeur par défaut pour des raisons pédagogiques (initialisation propre garantie).

---

## 🗂️ Header (`.hpp`) vs Source (`.cpp`)

- **`.hpp`** (header) : contient la **déclaration** de la classe — le "à quoi ça ressemble". Quels attributs, quelles méthodes existent.
- **`.cpp`** (source) : contient l'**implémentation** des méthodes — "comment elles font leur travail".

```cpp
// Animal.hpp
class Animal {
public:
    std::string getName(void) const;  // déclaration
};

// Animal.cpp
std::string Animal::getName(void) const {  // implémentation
    return this->_name;
}
```

L'opérateur `::` s'appelle **opérateur de résolution de portée** (*scope resolution operator*). Il dit : *"cette méthode appartient à la classe Animal."*

### 🛡️ Les **include guards** (protection contre les inclusions multiples)

Un fichier `.hpp` peut être inclus plusieurs fois indirectement par d'autres fichiers. Sans protection, le compilateur verrait plusieurs déclarations de la même classe → erreur.

```cpp
// Animal.hpp
#ifndef ANIMAL_HPP    // si ANIMAL_HPP n'est pas défini...
# define ANIMAL_HPP   // ... le définir maintenant

# include <string>

class Animal {
    // ...
};

#endif                // fin de la protection
```

🧠 **Le mécanisme** : la première fois que le compilateur voit ce fichier, il définit `ANIMAL_HPP` et lit la classe. Les fois suivantes, `ANIMAL_HPP` est déjà défini → le contenu est ignoré.

**Convention 42** : la macro porte le nom du fichier en majuscules, suffixé `_HPP`. Pour `Animal.hpp` → `ANIMAL_HPP`.

### Alternative moderne : `#pragma once`

```cpp
#pragma once

# include <string>

class Animal {
    // ...
};
```

**Plus court**, mais **non-standard** (extension supportée par tous les compilateurs modernes, pas dans la norme C++98). En 42, on utilise les **include guards classiques**.

### 🔍 Que mettre où ?

| Élément | `.hpp` | `.cpp` |
|---|---|---|
| Déclaration de classe | ✅ | ❌ |
| Déclarations de méthodes | ✅ | ❌ |
| Implémentations de méthodes | ❌ (sauf inline) | ✅ |
| `#include` des dépendances de l'interface | ✅ | — |
| `#include` des dépendances de l'implémentation | — | ✅ |
| Définition d'attributs `static` | ❌ | ✅ |

---

## 🧬 Héritage (*inheritance*)

L'**héritage** permet à une classe (**la fille**) de **récupérer** automatiquement tous les attributs et méthodes d'une autre classe (**la mère** ou **la parente**), et de les **étendre** ou **modifier**.

C'est le **2ème pilier** de la POO après l'encapsulation.

### 🎯 Le problème que ça résout

Sans héritage, modéliser plusieurs types similaires (Chien, Chat, Poisson) entraîne une **duplication massive** : mêmes attributs (`_name`, `_age`), mêmes méthodes (`eat()`, `sleep()`) répétés dans chaque classe. Difficile à maintenir, source de bugs.

Avec l'héritage, tu factorises le **code commun** dans une classe **parente**, et chaque classe fille **n'ajoute que ce qui lui est spécifique**.

### 📐 Syntaxe de base

```cpp
class Animal {                  // classe PARENTE (mère / base)
protected:
    std::string _name;
public:
    Animal(std::string name);
    void eat(void);
    void sleep(void);
};

class Dog : public Animal {     // Dog HÉRITE d'Animal
//          ↑↑↑↑↑↑↑↑↑↑↑↑
public:
    Dog(std::string name);
    void bark(void);            // méthode SPÉCIFIQUE à Dog
};
```

Maintenant `Dog` possède **automatiquement** `_name`, `eat()`, `sleep()` en plus de ses propres méthodes. Pas besoin de les réécrire.

```cpp
Dog rex("Rex");
rex.eat();    // méthode héritée d'Animal
rex.sleep();  // méthode héritée d'Animal
rex.bark();   // méthode propre à Dog
```

### 🔑 La relation **"est-un"** (*is-a*)

L'héritage modélise une relation **"est-un"** :

- Un `Dog` **est un** `Animal` ✅
- Un `Cat` **est un** `Animal` ✅
- Un `Pneu` **est-il un** `Voiture` ? ❌ Non, une `Voiture` **a un** `Pneu` → composition, pas héritage.

**Test mental** : si tu ne peux pas dire *"X est un Y"* avec un sens naturel, n'utilise PAS l'héritage. Utilise la **composition** à la place (un attribut de type Y dans la classe X).

### 🌳 La hiérarchie en arbre

```
                    Animal
                   /      \
                Dog        Cat
               /    \
        Bulldog    Poodle
```

Plus on **descend**, plus on est **spécifique** (spécialisation).
Plus on **monte**, plus on est **général** (généralisation).

Par transitivité : un `Bulldog` est un `Dog`, qui est un `Animal`. Donc un `Bulldog` est aussi un `Animal`.

### 🛡️ `protected` prend tout son sens

Avec l'héritage, le mot-clé `protected` (qu'on avait mentionné plus tôt) prend toute son utilité :

| Visibilité | Accès depuis la classe ? | Accès depuis une fille ? | Accès depuis l'extérieur ? |
|---|---|---|---|
| **`private`** | ✅ | ❌ | ❌ |
| **`protected`** | ✅ | ✅ | ❌ |
| **`public`** | ✅ | ✅ | ✅ |

**`protected`** = *"privé pour le monde extérieur, mais accessible pour ma descendance."*

**Règle pratique** :
- Si un attribut sera **manipulé par les classes filles** → `protected`
- Si un attribut est **strictement interne** à la classe parente → `private`

### 🎭 Les 3 modes d'héritage

Tu peux hériter de trois façons :

```cpp
class Dog : public Animal { };      // héritage public (le plus courant)
class Dog : protected Animal { };   // héritage protégé (rare)
class Dog : private Animal { };     // héritage privé (rare)
```

Effet du mode d'héritage sur les membres publics de la classe parente :

| Mode d'héritage | Les membres `public` deviennent... |
|---|---|
| `public` | `public` (inchangé) |
| `protected` | `protected` |
| `private` | `private` |

Le mode d'héritage **dégrade** la visibilité, jamais ne la rehausse.

**En pratique : utilise toujours `public`.** C'est ce que 99% des cas exigent et c'est ce que CPP03 attend.

### 🏗️ Constructeurs et héritage

Point **fondamental** : quand tu crées un `Dog`, **deux constructeurs** sont appelés, dans un ordre précis.

#### Ordre de construction

```cpp
Dog rex("Rex");
```

1. **D'abord** : le constructeur d'`Animal` (la partie parente)
2. **Ensuite** : le constructeur de `Dog` (la partie fille)

C'est logique : avant de pouvoir construire la partie "Dog" spécifique, il faut d'abord construire la partie "Animal" sous-jacente. On construit **du général au spécifique**.

#### Appeler explicitement le constructeur parent

Si le parent n'a pas de constructeur par défaut (par exemple, il prend des arguments obligatoires), tu **dois** appeler son constructeur explicitement dans la liste d'initialisation :

```cpp
Dog::Dog(std::string name) : Animal(name)
//                           ↑↑↑↑↑↑↑↑↑↑↑↑
//                  appel du constructeur parent
{
    std::cout << "Dog constructor called" << std::endl;
}
```

Si tu oublies, le compilateur essaie d'appeler le constructeur par défaut d'`Animal`. S'il n'existe pas → erreur de compilation.

### ⚰️ Destructeurs et héritage

Pareil mais **dans l'ordre INVERSE** :

```cpp
~Dog();
```

1. **D'abord** : le destructeur de `Dog` (la partie spécifique)
2. **Ensuite** : le destructeur d'`Animal` (la partie générale)

C'est comme démonter une poupée russe : on enlève d'abord la coque extérieure pour accéder à l'intérieur.

**Vue d'ensemble** :

```
Construction :  Animal → Dog        (général → spécifique)
Destruction  :  Dog → Animal        (spécifique → général)
```

### ⚠️ Rappel d'or : destructeurs `virtual`

> **Si une classe est destinée à être héritée, son destructeur DOIT être `virtual`.**

```cpp
class Animal {
public:
    virtual ~Animal(void);   // ← virtual !
};
```

Détail complet dans la section *Destructeur* plus haut. Retiens : destructeur de classe parente = toujours `virtual`.

### 🎬 Exemple complet

```cpp
// Animal.hpp
class Animal {
protected:
    std::string _name;
public:
    Animal(std::string name);
    virtual ~Animal(void);
    void eat(void);
};

// Animal.cpp
Animal::Animal(std::string name) : _name(name) {
    std::cout << "Animal constructor called" << std::endl;
}
Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}
void Animal::eat(void) {
    std::cout << _name << " is eating." << std::endl;
}

// Dog.hpp
class Dog : public Animal {
public:
    Dog(std::string name);
    ~Dog(void);
    void bark(void);
};

// Dog.cpp
Dog::Dog(std::string name) : Animal(name) {
    std::cout << "Dog constructor called" << std::endl;
}
Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
}
void Dog::bark(void) {
    std::cout << _name << " says: Woof!" << std::endl;
}

// main.cpp
int main(void) {
    Dog rex("Rex");
    rex.eat();
    rex.bark();
    return (0);
}
```

**Sortie** :
```
Animal constructor called    ← parent d'abord
Dog constructor called       ← puis fille
Rex is eating.
Rex says: Woof!
Dog destructor called        ← fille d'abord
Animal destructor called     ← puis parent
```

### 🆚 Héritage vs Composition

Ne pas confondre :

| Héritage ("est-un") | Composition ("a-un") |
|---|---|
| `Dog` **est un** `Animal` | `Car` **a un** `Engine` |
| `class Dog : public Animal` | `class Car { Engine _engine; };` |
| Lien fort, dépendance forte | Lien faible, les classes restent indépendantes |
| Hérite de TOUT (attrs + méthodes) | Utilise juste un objet à l'intérieur |
| Visibilité contrôlée par `protected` | Pas d'impact sur la visibilité |

**Règle d'or moderne** : *"Préfère la composition à l'héritage quand tu as le choix."*

L'héritage est puissant mais crée des **couplages forts** entre classes. La composition reste plus flexible. Ne hérite que quand la relation **"est-un"** est claire et naturelle.

### 🎨 Métaphore pour mémoriser

Pense à l'héritage comme à un **héritage familial** :

- Tes **parents** te transmettent des caractéristiques (couleur des yeux, taille, certains traits).
- Tu en **hérites** automatiquement.
- Tu as aussi tes **propres caractéristiques** que tes parents n'avaient pas.
- Tu peux **redéfinir** certaines choses (musique préférée différente).
- Ton existence dépend de celle de tes parents : tu n'aurais pas pu exister sans eux.

C'est exactement la POO : la classe fille hérite, enrichit, peut redéfinir, mais reste fondamentalement liée à sa classe parente.

### 🚀 Aperçu de ce qui vient au CPP04 : le polymorphisme

L'héritage seul est utile, mais il révèle son plein potentiel avec le **polymorphisme** (CPP04). Spoiler :

```cpp
Animal* tab[3];
tab[0] = new Dog("Rex");
tab[1] = new Cat("Whiskers");
tab[2] = new Bird("Tweety");

for (int i = 0; i < 3; i++)
    tab[i]->makeSound();   // chaque animal fait SON propre son !
```

Un seul appel `makeSound()` produit des **comportements différents** selon le **vrai type** de l'objet. C'est la magie du polymorphisme, et c'est ce qu'on couvrira au CPP04.

### 🧠 Mnémotechniques pour l'héritage

- **"Est-un"** pour décider quand hériter
- **`protected`** pour partager avec les enfants
- **Constructeurs : parent → enfant** (du général au spécifique)
- **Destructeurs : enfant → parent** (l'inverse)
- **Destructeur parent toujours `virtual`** si la classe sera héritée
- **Préfère la composition à l'héritage** quand tu as le choix

---

## 🔧 `operator=` et constructeur de copie avec héritage

Quand tu écris l'OCF d'une classe fille, **deux opérations** posent souvent problème : le constructeur de copie et l'opérateur d'assignation. Le piège classique : essayer de tout réécrire à la main au lieu de **déléguer au parent**.

### 📐 Le pattern à connaître par cœur

```cpp
// Constructeur de copie d'une classe fille
Child::Child(const Child& src) : Parent(src)
//                               ↑↑↑↑↑↑↑↑↑↑↑
//              appelle le constructeur de copie du PARENT
{
    std::cout << "Child copy constructor called" << std::endl;
    // Copier les attributs PROPRES à Child si nécessaire
}

// Opérateur d'assignation d'une classe fille
Child& Child::operator=(const Child& src)
{
    std::cout << "Child assignment operator called" << std::endl;
    if (this != &src)
    {
        Parent::operator=(src);   // ← délègue au parent
        // Copier les attributs PROPRES à Child si nécessaire
    }
    return (*this);
}
```

**La règle d'or** : pour les attributs **hérités**, laisse le parent s'en occuper. Pour les attributs **propres** à la classe fille, copie-les explicitement dans le corps `{}`.

### 🎯 Pourquoi `Parent::operator=(src)` et pas autre chose ?

Le `Parent::` est un **résolveur de scope** qui dit explicitement *"je veux la version de `Parent`, pas celle de `Child`."*

Sans ce préfixe, si tu écrivais `operator=(src)` tout seul, le compilateur appellerait... **la méthode courante** (celle de `Child`), créant une **récursion infinie** qui crashe.

### ⚠️ Le piège du slicing à éviter

Une **mauvaise idée** qui semble logique mais qui pose problème :

```cpp
// ❌ MAUVAIS
Child& Child::operator=(const Child& src)
{
    *this = Parent(src);   // SLICING + récursion potentielle
    return (*this);
}
```

**Ce qui ne va pas** :

1. **`Parent(src)`** crée un objet **temporaire** de type `Parent`. Le compilateur fait un **slicing** : il copie uniquement la partie `Parent` de `src` et perd toute la spécificité de `Child`.
2. **`*this = ...`** appelle `operator=` sur `*this` (qui est un `Child`). Selon les surcharges disponibles, ça peut mener à une **récursion infinie** ou à du comportement indéfini.
3. **Performance** : tu crées un objet temporaire pour rien, alors que la délégation directe (`Parent::operator=(src)`) modifie `*this` en place sans copie intermédiaire.

### 🎬 Le slicing visualisé

Le **slicing** est un concept à connaître. Quand tu fais `Parent(src)` où `src` est un `Child` :

```
   Child src                    Parent(src) — temporaire
   ┌──────────────┐             ┌──────────────┐
   │ attrs hérités│             │ attrs hérités│
   │ (de Parent)  │ ──"slice"─→ │ (de Parent)  │
   │              │             └──────────────┘
   │ attrs propres│             (la partie Child est DÉCOUPÉE,
   │ (de Child)   │              perdue à jamais)
   └──────────────┘
```

Le compilateur "découpe" la partie spécifique à `Child` parce qu'un `Parent` ne peut pas la contenir. C'est rarement ce qu'on veut.

### 📋 Cas avec attributs propres à la classe fille

Si `Child` a ses propres attributs (en plus de ceux hérités) :

```cpp
class Child : public Parent {
private:
    int _specialAbility;   // attribut propre à Child
};

// Constructeur de copie complet
Child::Child(const Child& src)
    : Parent(src)                            // 1. délègue les attrs hérités
    , _specialAbility(src._specialAbility)   // 2. copie les attrs propres
{
    std::cout << "Child copy constructor called" << std::endl;
}

// operator= complet
Child& Child::operator=(const Child& src)
{
    std::cout << "Child assignment operator called" << std::endl;
    if (this != &src)
    {
        Parent::operator=(src);                          // 1. attrs hérités
        this->_specialAbility = src._specialAbility;     // 2. attrs propres
    }
    return (*this);
}
```

**Tu ne peux PAS** initialiser un attribut hérité dans la liste d'init de la classe fille :

```cpp
// ❌ ERREUR : _name appartient à Parent
Child::Child(const Child& src) : Parent(src), _name(src._name) { }

// ✅ Le constructeur de Parent s'en occupe via Parent(src)
Child::Child(const Child& src) : Parent(src) { }
```

### 💡 Pourquoi cette approche est meilleure

**Maintenance** : si tu ajoutes un attribut à `Parent` plus tard, tu **n'as qu'à mettre à jour le constructeur de copie et l'`operator=` de `Parent`**. Toutes les classes filles bénéficient automatiquement de la mise à jour.

C'est l'application du principe **DRY** (Don't Repeat Yourself) appliqué à l'héritage.

### 🧠 Mnémotechnique

> **"Délègue, ne réécris pas."**
> Le parent sait copier sa propre partie — laisse-le faire.

| Pour copier... | Utilise... |
|---|---|
| Attributs hérités (constructeur de copie) | `: Parent(src)` dans la liste d'init |
| Attributs hérités (operator=) | `Parent::operator=(src);` dans le corps |
| Attributs propres à la classe fille | Liste d'init ou copie manuelle dans le corps |

---

## 💎 L'héritage en diamant

Cas particulier qu'on rencontre au CPP03 : une classe hérite de **deux classes parentes** qui héritent elles-mêmes d'une **classe commune**.

```
         Animal
         /    \
       Dog    Robot
         \    /
       RobotDog   ← double héritage !
```

Sans précaution, `RobotDog` contient **deux exemplaires** d'`Animal` (un via `Dog`, un via `Robot`). Ambiguïté dangereuse !

### ✅ Solution : le mot-clé `virtual` dans la déclaration d'héritage

```cpp
class Dog : virtual public Animal { };     // ← virtual !
class Robot : virtual public Animal { };   // ← virtual !
class RobotDog : public Dog, public Robot { };
```

⚠️ **Attention, deux `virtual` différents en C++** !

| `virtual` | Contexte | Sens |
|---|---|---|
| **Méthode virtuelle** | `virtual void foo();` dans une classe | Permet la redéfinition polymorphique (CPP04) |
| **Héritage virtuel** | `class A : virtual public B` | Évite la duplication d'une base commune en diamant |

Le même mot-clé, deux usages **complètement différents**. Ne pas confondre.

Le `virtual` d'héritage dit : *"il n'existe qu'**un seul** `Animal` dans `RobotDog`, partagé entre `Dog` et `Robot`."* C'est ce qu'on appelle l'**héritage virtuel**.

C'est exactement le sujet de l'**ex03 du CPP03** (la classe `DiamondTrap`).

### 🛠️ Comment initialiser correctement les constructeurs en diamant

L'héritage en diamant impose une **règle particulière** pour les constructeurs : **la classe la plus dérivée doit initialiser explicitement TOUS ses ancêtres**, y compris la base virtuelle.

```cpp
class Animal {                       // base virtuelle
public:
    Animal(std::string name);
};

class Dog : virtual public Animal {
public:
    Dog(std::string name);
};

class Robot : virtual public Animal {
public:
    Robot(std::string name);
};

class RobotDog : public Dog, public Robot {
public:
    RobotDog(std::string name);
};
```

**Pattern d'initialisation correct pour `RobotDog`** :

```cpp
RobotDog::RobotDog(std::string name)
    : Animal(name)   // ← base virtuelle : doit être init par la classe la plus dérivée !
    , Dog(name)      // ← parent 1
    , Robot(name)    // ← parent 2
{
    std::cout << "RobotDog constructor called" << std::endl;
}
```

**Trois choses à initialiser** :

1. **`Animal`** (la base virtuelle) : c'est la classe la plus dérivée (`RobotDog`) qui doit le faire, **pas** `Dog` ni `Robot`. C'est une règle stricte du C++ pour résoudre l'ambiguïté du diamant.
2. **`Dog`** (parent direct 1)
3. **`Robot`** (parent direct 2)

### 🚨 L'erreur classique du compilateur

Si tu oublies d'initialiser un parent, avec `-Wextra -Werror`, le compilateur te lance :

```
error: base class 'class Dog' should be explicitly initialized in the copy constructor
error: base class 'class Robot' should be explicitly initialized in the copy constructor
```

**Diagnostic** : tu as des classes parentes multiples (via héritage en diamant) et tu n'as pas toutes les initialisées dans la liste d'init de ton constructeur.

**Solution** : ajoute tous les parents dans la liste d'init.

### 🎬 La cascade de messages (test de l'héritage virtuel)

Quand tu crées un `RobotDog("Bob")`, voici l'ordre exact des appels :

```
Animal constructor called    ← UNE SEULE FOIS grâce à virtual
Dog constructor called       ← parent 1
Robot constructor called     ← parent 2
RobotDog constructor called  ← le plus dérivé
```

**Test infaillible** : si tu vois **DEUX** `Animal constructor called`, c'est que tu as **oublié le `virtual`** dans `Dog` ou `Robot`. La base commune est dupliquée.

Avec le bon `virtual`, `Animal` n'est construit **qu'une seule fois**, même si `RobotDog` "hérite" deux fois via deux chemins différents.

### 🔧 Pattern pour le constructeur de copie et `operator=`

Même logique : tous les ancêtres doivent être explicitement initialisés ou délégués.

```cpp
// Constructeur de copie
RobotDog::RobotDog(const RobotDog& src)
    : Animal(src)
    , Dog(src)
    , Robot(src)
{
    std::cout << "RobotDog copy constructor called" << std::endl;
}

// Opérateur d'assignation
RobotDog& RobotDog::operator=(const RobotDog& src)
{
    std::cout << "RobotDog assignment operator called" << std::endl;
    if (this != &src)
    {
        Animal::operator=(src);   // base virtuelle
        // Note : Dog::operator= et Robot::operator= n'apportent rien de plus
        //        s'ils n'ont pas d'attributs propres
    }
    return (*this);
}
```

### 💡 Cas pratique : `DiamondTrap` du CPP03

Pour ton ex03 du CPP03, voici comment ça s'applique :

```cpp
class DiamondTrap : public ScavTrap, public FragTrap {
private:
    std::string _name;   // ← attribut propre à DiamondTrap (distinct de celui hérité)
};

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name")   // base virtuelle, nom suffixé
    , ScavTrap(name)
    , FragTrap(name)
    , _name(name)                      // attribut propre
{
    std::cout << "DiamondTrap constructor called" << std::endl;
}
```

Le sujet exige que `DiamondTrap` ait un nom **propre** (`_name`) distinct du nom hérité de `ClapTrap`. C'est pour ça qu'on suffixe `_clap_name` à la base, et qu'on garde le vrai nom dans l'attribut `_name` de `DiamondTrap`.

### 🧠 Mnémotechnique pour le diamant

> **"En diamant, la plus dérivée fait tout."**
>
> La classe la plus en bas (`RobotDog`, `DiamondTrap`) doit initialiser **explicitement** tous ses ancêtres, y compris la base virtuelle. Ne compte pas sur les parents intermédiaires pour s'en occuper.

| Élément | Qui s'en occupe ? |
|---|---|
| Base virtuelle (grand-parent commun) | La classe **la plus dérivée**, toujours |
| Parents directs | La classe la plus dérivée, dans la liste d'init |
| Attributs propres | La classe la plus dérivée, dans la liste d'init ou le corps |

---

## 🎭 Polymorphisme (de sous-type)

📘 **Définition** : le **polymorphisme** (de sous-type, ou *dynamic polymorphism*) est la capacité d'appeler une méthode **via un pointeur/référence de la classe de base**, et que ce soit la version **de la classe réelle de l'objet** qui s'exécute — décidée **à l'exécution**, pas à la compilation.

C'est le 3ᵉ pilier de la POO, au cœur du CPP04.

```cpp
AMateria* m = new Ice();   // type statique : AMateria* | type dynamique : Ice
m->use(target);            // appelle Ice::use, PAS AMateria::use
```

### 🔑 Le mot-clé `virtual` — la liaison dynamique

Sans `virtual`, C++ choisit la méthode selon le **type du pointeur** (liaison statique). Avec `virtual`, il choisit selon le **type réel de l'objet pointé** (liaison dynamique).

```cpp
class AMateria {
public:
    virtual void use(ICharacter& t);   // virtual → liaison dynamique
};
class Ice : public AMateria {
public:
    void use(ICharacter& t);           // redéfinit (override) la version de base
};
```

🎨 **Métaphore** : tu demandes à « un animal » de faire son cri (`makeSound()`). Tu ne sais pas lequel c'est, mais chacun répond à sa façon : le chien aboie, le chat miaule. Tu parles à l'**abstraction** (Animal), l'objet répond selon sa **vraie nature**.

🧠 **Mnémotechnique** : *« `virtual` = l'objet décide, pas le pointeur. »*

### ⚙️ Comment ça marche (la *vtable*)

Une classe avec des méthodes `virtual` possède une **table de fonctions virtuelles** (*vtable*). Chaque objet garde un pointeur caché vers cette table. À l'appel d'une méthode virtuelle, le programme passe par la vtable pour trouver la bonne fonction → coût minime, décidé à l'exécution.

### ⚠️ Pièges classiques

- **Oublier `virtual`** → tu appelles la version de la base (bug silencieux, typique de l'exo *WrongAnimal*).
- **Polymorphisme par valeur** → impossible : il faut un **pointeur ou une référence** de la base. Une copie par valeur provoque du *slicing* (voir section héritage).
- **Destructeur non `virtual`** sur une base manipulée en polymorphisme → fuite mémoire (voir [Destructeur](#-destructeur-destructor)).

---

## 🧩 Fonction virtuelle pure et classe abstraite

📘 **Fonction virtuelle pure** : une méthode `virtual` déclarée `= 0`, **sans implémentation obligatoire** dans la classe qui la déclare. Elle impose aux classes filles de la définir.

```cpp
virtual AMateria* clone() const = 0;   // = 0 → virtuelle PURE
```

📘 **Classe abstraite** : une classe qui contient **au moins une** méthode virtuelle pure. Conséquence directe : **on ne peut pas l'instancier**.

```cpp
AMateria m;            // ❌ ERREUR : AMateria est abstraite
AMateria* p = new Ice; // ✅ OK : Ice est concrète (elle définit clone())
```

🎨 **Métaphore** : « véhicule » est un concept abstrait — tu ne peux pas acheter « un véhicule » en général, seulement une voiture, une moto... concrètes. Mais tout véhicule **promet** d'avoir un `démarrer()`.

🔍 **Abstraite vs concrète** :

| | Au moins 1 méthode pure ? | Instanciable ? | Rôle |
|---|---|---|---|
| **Classe abstraite** | Oui | ❌ Non | Définir un contrat / une base commune |
| **Classe concrète** | Non (toutes définies) | ✅ Oui | Être réellement utilisée |

⚠️ **Piège** : si une classe fille oublie de définir **une seule** méthode pure héritée, elle reste **abstraite** → `new Fille` ne compile pas (« *cannot allocate an object of abstract type* »). C'est exactement l'erreur rencontrée quand `Character`/`MateriaSource` ne déclaraient pas leurs overrides.

🧠 **Mnémotechnique** : *« `= 0` = zéro instance possible. »*

🚀 **Usage 42** : au CPP04 ex02, on rend `Animal` abstraite (`AAnimal`) pour interdire de créer un animal « générique » qui ne fait aucun son.

---

## 🔌 Interface (classe abstraite pure)

📘 **Définition** : une **interface** est une classe abstraite **100 % pure** — elle ne contient **que** des méthodes virtuelles pures + un **destructeur virtuel**, et **aucune donnée**. Le mot-clé `interface` n'existe pas en C++ : on utilise une classe abstraite pure (convention de nommage : préfixe `I`).

```cpp
class ICharacter {
public:
    virtual ~ICharacter() {}                              // destructeur virtuel
    virtual std::string const & getName() const = 0;      // que des
    virtual void equip(AMateria* m) = 0;                  // méthodes
    virtual void unequip(int idx) = 0;                    // virtuelles
    virtual void use(int idx, ICharacter& target) = 0;    // pures
};
```

🎯 **Le rôle d'une interface** : définir un **contrat**. Quiconque implémente `ICharacter` *promet* de fournir ces 4 méthodes. Le reste du code peut alors manipuler n'importe quel `ICharacter*` sans connaître la classe concrète derrière (`Character`).

### ⚠️ Points cruciaux d'une interface

- **Pas d'attribut, pas de logique** : les données (`_name`, l'inventaire...) vivent dans la classe **concrète** (`Character`), jamais dans l'interface.
- **Pas de forme canonique à écrire** : rien à copier → pas de constructeur/copie/`operator=` à déclarer. Le compilateur fournit le constructeur par défaut implicite (rien à initialiser).
- **Destructeur virtuel OBLIGATOIRE** (`virtual ~ICharacter() {}`) : sans lui, `delete` sur un `ICharacter*` qui pointe vers un `Character` est un comportement indéfini.

🔍 **Interface vs classe abstraite « normale »** :

| | Interface (`ICharacter`) | Classe abstraite avec état (`AMateria`) |
|---|---|---|
| Attributs | ❌ aucun | ✅ oui (`_type`) |
| Méthodes | toutes pures | mélange (pures + concrètes) |
| Forme canonique | non | **oui** (elle stocke des données) |
| Exemple 42 | `ICharacter`, `IMateriaSource` | `AMateria` |

🧠 **Mnémotechnique** : *« Interface = contrat creux : que des promesses, zéro donnée, + un destructeur virtuel. »*

---

## 🧬 L'idiome clone() et la copie profonde polymorphique

📘 **Le problème** : tu as un `AMateria*` mais tu ignores si c'est un `Ice` ou un `Cure`. Comment en faire une **copie du bon type** ? Tu ne peux pas écrire `new Ice(...)` puisque tu ne connais pas le type. C'est là qu'intervient `clone()`.

📐 **L'idiome** (aussi appelé *virtual constructor* ou patron *Prototype*) : chaque classe concrète redéfinit `clone()` pour renvoyer une copie d'elle-même.

```cpp
virtual AMateria* clone() const = 0;          // dans la base abstraite

AMateria* Ice::clone() const  { return new Ice(*this); }   // chacun
AMateria* Cure::clone() const { return new Cure(*this); }  // se clone
```

Désormais, `m->clone()` renvoie un `Ice*` si `m` pointe sur un `Ice`, un `Cure*` si c'est un `Cure` — décidé **à l'exécution** grâce à `virtual`.

### 🌊 Copie profonde (*deep copy*) vs copie superficielle (*shallow copy*)

⚠️ Quand une classe possède des **pointeurs vers des objets alloués** (l'inventaire de `Character`, les templates de `MateriaSource`), la copie générée par défaut **copie les pointeurs**, pas les objets → deux objets partagent la même mémoire (*shallow*). Au premier `delete`, l'autre pointe dans le vide → **double-free / crash**.

```cpp
// ❌ SHALLOW : les deux Character pointent vers les MÊMES Materias
this->_inventory[i] = src._inventory[i];

// ✅ DEEP : chaque Character a SES PROPRES Materias
this->_inventory[i] = src._inventory[i]->clone();
```

### 📐 Le pattern complet (copie profonde dans l'OCF)

Dans le **constructeur de copie** : cloner chaque élément non-NULL.
Dans l'**`operator=`** : **d'abord `delete`** l'ancien contenu, **ensuite** cloner le nouveau (sinon fuite).

```cpp
Character& Character::operator=(const Character& src) {
    if (this != &src) {
        _name = src._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) delete _inventory[i];        // 1. libère l'ancien
            _inventory[i] = src._inventory[i]
                ? src._inventory[i]->clone() : NULL;        // 2. clone le nouveau
        }
    }
    return *this;
}
```

🎨 **Métaphore** : copie superficielle = photocopier l'**adresse** d'une maison (deux papiers, une seule maison). Copie profonde = **reconstruire** une maison identique à côté. Si tu démolis l'une, l'autre tient toujours.

🧠 **Mnémotechnique** : *« Pointeur possédé → clone, pas copie. Et dans `operator=` : delete avant clone. »*

🔍 **Checklist mémoire (validée au valgrind)** :

| Situation | À faire |
|---|---|
| Classe possède des pointeurs alloués | Copie profonde (`clone()`) dans copie + `operator=` |
| `operator=` | `delete` l'ancien **avant** de cloner |
| Base manipulée via pointeur | Destructeur **`virtual`** |
| Materia « laissée par terre » (`unequip`, inventaire plein) | La `delete` toi-même (la classe ne la possède plus) |

---

## 🧠 Récap visuel

```
┌─────────────────────────────────────────────────────────┐
│                    CLASSE Animal                        │
│  (le plan / le moule)                                   │
│                                                         │
│  PRIVATE:                                               │
│    • _name (string)            ← ATTRIBUT               │
│    • _age  (int)               ← ATTRIBUT               │
│    • _populationCount (static) ← ATTRIBUT (static)      │
│                                                         │
│  PUBLIC:                                                │
│    • Animal()                  ← MÉTHODE (constructeur) │
│    • ~Animal()                 ← MÉTHODE (destructeur)  │
│    • getName()                 ← MÉTHODE (getter)       │
│    • setName()                 ← MÉTHODE (setter)       │
│    • eat(), makeSound()        ← MÉTHODES (actions)     │
└─────────────────────────────────────────────────────────┘
            │
            │ instanciation
            ▼
┌──────────────┐    ┌──────────────┐    ┌──────────────┐
│  OBJET rex   │    │  OBJET tom   │    │  OBJET kiwi  │
│  _name: Rex  │    │  _name: Tom  │    │  _name: Kiwi │
│  _age: 5     │    │  _age: 3     │    │  _age: 1     │
└──────────────┘    └──────────────┘    └──────────────┘
        chaque objet a sa PROPRE copie de _name et _age
        mais ils PARTAGENT _populationCount (static)
```

---

## 📚 Termes complémentaires à connaître

| Terme | Définition rapide |
|---|---|
| **Membre** | Terme générique qui regroupe attributs **et** méthodes |
| **Getter** | Méthode publique qui *retourne* la valeur d'un attribut privé |
| **Setter** | Méthode publique qui *modifie* la valeur d'un attribut privé |
| **Const member function** | Méthode qui ne modifie pas l'objet (`const` en fin de signature) |
| **Liste d'initialisation** | Syntaxe `: attr(val)` après la signature d'un constructeur |
| **Scope** | Portée d'une variable / d'un identifiant |
| **`::`** | Opérateur de résolution de portée |
| **Polymorphisme ad-hoc** | Nom savant pour la surcharge (même nom, comportements différents) |
| **Polymorphisme** | Capacité d'un objet à se comporter selon plusieurs types (lié à l'héritage) |
| **Classe abstraite** | Classe contenant au moins une méthode virtuelle pure, qu'on ne peut pas instancier |
| **Méthode virtuelle** | Méthode pouvant être redéfinie dans une classe fille (mot-clé `virtual`) |
| **Méthode virtuelle pure** | `virtual void f() = 0;` — doit être redéfinie dans les filles |
| **Interface** | Classe abstraite 100 % pure (que des méthodes pures + destructeur virtuel, aucune donnée) ; convention de nommage `I...` |
| **Liaison dynamique** | Choix de la méthode à l'**exécution** selon le type réel de l'objet (grâce à `virtual`) |
| **vtable** | Table des fonctions virtuelles ; mécanisme interne de la liaison dynamique |
| **`clone()` (virtual constructor)** | Idiome : chaque classe se copie elle-même via `new Type(*this)` — utile quand on ne connaît que le type de base |
| **Copie profonde / superficielle** | *Deep* : duplique les objets pointés (`clone()`) ; *shallow* : copie juste les pointeurs (→ double-free) |
| **Slicing** | Perte de la spécificité d'une classe fille lors d'une copie par valeur vers la classe parente |
| **RAII** | *Resource Acquisition Is Initialization* — l'idiome où un objet acquiert sa ressource à la construction et la libère à la destruction |
| **DRY** | *Don't Repeat Yourself* — principe : éviter la duplication de code |

---

## 🎯 Quiz d'auto-évaluation

Pour vérifier que tu maîtrises le vocabulaire, réponds à ces questions.

### Niveau 1 — Bases

1. Dans `Animal rex;`, comment on appelle l'action ?
2. Dans `class Animal { int _age; };`, `_age` est-il un attribut ou une méthode ?
3. La fonction `getName()` est-elle une fonction libre ou une fonction membre ?
4. Quelle est la différence entre `private` et `public` ?
5. Combien d'instances peuvent partager un attribut `static` ?
6. Quel symbole précède le nom du destructeur ?
7. À quoi sert le mot-clé `this` ?
8. Dans quel fichier (`.hpp` ou `.cpp`) écrit-on l'implémentation des méthodes ?

### Niveau 2 — Mémoire et OCF

9. Quelle est la différence entre constructeur de copie et `operator=` ?
10. Que signifie OCF et combien de fonctions ça impose ?
11. Dans `int& r = x;`, le `&` représente-t-il une référence ou un opérateur "adresse de" ?
12. Que se passe-t-il si on passe un objet par valeur au constructeur de copie (sans `&`) ?
13. Quelle est la différence entre la pile (stack) et le tas (heap) ?
14. Quand le destructeur est-il appelé pour un objet créé sur la pile ?
15. Pourquoi met-on `if (this != &other)` dans `operator=` ?
16. Cite trois cas où la liste d'initialisation est OBLIGATOIRE.

### Niveau 3 — Héritage et avancé

17. Comment dit-on en français qu'une classe `Dog` "est-un" `Animal` ?
18. Quel est l'ordre d'appel des constructeurs entre parent et fille ?
19. Quel est l'ordre d'appel des destructeurs entre parent et fille ?
20. Pourquoi le destructeur d'une classe parente doit-il être `virtual` ?
21. Quelle est la différence entre `virtual` sur une méthode et `virtual` sur un héritage ?
22. Qu'est-ce que le slicing et comment l'éviter ?
23. Dans un héritage en diamant, qui doit initialiser la base virtuelle ?
24. Pourquoi `friend` est utile pour `operator<<` ?

---

## 🎁 Petits rappels avant de fermer le doc

- **Toujours mettre les attributs en `private`** (encapsulation).
- **Toujours retourner par référence** dans `operator=` (chaînage).
- **Toujours initialiser la liste d'init dans l'ordre de déclaration** des attributs.
- **Toujours `virtual`** le destructeur d'une classe destinée à être héritée.
- **Toujours `if (this != &other)`** dans `operator=`.
- **Toujours include guards** dans les `.hpp`.

---

*Lexique POO C++ — référence universelle. Bonne continuation, fducrot !* 🚀
