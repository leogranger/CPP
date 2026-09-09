# CPP

42 core curriculum: the C++ modules piscine. Ten modules (`cpp00` to
`cpp09`), each with several exercises, introducing object-oriented
programming in C++ from the ground up: classes, memory management,
inheritance, polymorphism, exceptions, templates and STL containers.

## Table of contents

- [Requirements](#requirements)
- [Building an exercise](#building-an-exercise)
- [Modules](#modules)
- [Resources](#resources)
- [AI usage](#ai-usage)

## Requirements

- A C++98-compliant compiler (`c++`), as required by the 42 norm for this
  piscine.
- `make`.

## Building an exercise

There is no global Makefile: each exercise has its own, in its own
directory.

```sh
cd cppXX/exYY
make
./<binary_name>
```

## Modules

### cpp00 — Namespaces, classes, member functions, stdio streams, initialization lists, static, const

- **ex00 — Megaphone**: turns command-line arguments into uppercase and
  prints them, introducing basic I/O and string handling in C++.
- **ex01 — PhoneBook**: a `Contact` class stored in a `PhoneBook`, entered
  and displayed through `std::cin`/`std::cout`, illustrating basic
  encapsulation (private members, getters/setters).
- **ex02 — Account**: a `Account` class tracking deposits, withdrawals and
  balances across several instances, using `static` members shared by all
  objects and `const` member functions.

### cpp01 — Memory allocation, pointers to members, references, switch statement

- **ex00/ex01 — Zombies**: allocating a single `Zombie` on the heap versus
  a horde of zombies on the stack, to compare `new`/`delete` with automatic
  storage.
- **ex02 — Pointer, reference**: comparing the memory address and value of
  a variable, a pointer to it, and a reference to it.
- **ex03 — HumanA / HumanB**: `HumanA` holds its `Weapon` by reference,
  `HumanB` by pointer — showing that a reference must always be bound and
  cannot be reassigned, unlike a pointer.
- **ex04 — Sed is for losers**: a simplified `sed`-like program that
  replaces one string with another inside a file, exercising
  `std::string` manipulation.
- **ex05/ex06 — Harl**: a `Harl` class with a `complain(level)` method that
  dispatches to the right member function; ex06 adds a "DEBUG and above"
  mode using fallthrough logic between levels.

### cpp02 — Ad-hoc polymorphism, operator overloading, canonical form

- **ex00/ex01/ex02 — Fixed**: a fixed-point number class (`Fixed`) storing
  a value as a fixed number of fractional bits, first with basic
  getters/setters, then with the full set of comparison and arithmetic
  operators (`+`, `-`, `*`, `/`, `++`, `--`, comparisons), and helper
  `min`/`max` functions.
- **ex03 — BSP**: uses `Fixed` and a `Point` class to determine whether a
  point lies inside a triangle, applying the class built in the previous
  exercises to a geometric problem.

### cpp03 — Inheritance

- **ex00 — ClapTrap**: a base class with health, energy and attack damage,
  introducing the canonical form (default/copy constructor, destructor,
  assignment operator) applied to a "fighting" class.
- **ex01 — ScavTrap**: a first subclass inheriting from `ClapTrap`, with
  its own stats and an extra ability.
- **ex02 — FragTrap**: a second, independent subclass of `ClapTrap`, to
  practice single inheritance again with different behavior.
- **ex03 — DiamondTrap**: `DiamondTrap` inherits from both `ScavTrap` and
  `FragTrap`, which both inherit from `ClapTrap` — the classic "diamond
  problem", solved here with virtual inheritance so `ClapTrap` is only
  instantiated once.

### cpp04 — Subtype polymorphism, abstract classes, interfaces

- **ex00 — Polymorphism**: `Animal`, `Dog` and `Cat` with a virtual
  `makeSound()`, plus a deliberately broken `WrongAnimal`/`WrongCat` pair
  showing what happens when a base class method is *not* virtual.
- **ex01 — I don't want to set the world on fire**: same hierarchy, but
  now paying attention to proper deep copies and destructors, and adding a
  `Brain` member to `Dog`/`Cat` to illustrate composition alongside
  inheritance.
- **ex02 — Abstract class**: `AAnimal` becomes an abstract base class
  (pure virtual `makeSound()`), so it can no longer be instantiated
  directly — only through `Dog` or `Cat`.
- **ex03 — Interface & recap**: a small RPG-like system (`ICharacter`,
  `IMateriaSource`, `AMateria`, `Ice`, `Cure`, `Character`,
  `MateriaSource`) combining interfaces, abstract classes and the
  prototype pattern (`clone()`).

### cpp05 — Repetition and exceptions

- **ex00 — Bureaucrat**: a class with a bounded grade (1 to 150),
  throwing custom exceptions (`GradeTooHighException`,
  `GradeTooLowException`) when that bound is violated.
- **ex01 — Form**: a `Form` that can only be signed by a `Bureaucrat`
  whose grade is high enough, introducing form-specific exceptions.
- **ex02 — No, I need form 28B, not 28C...**: `AForm` becomes an abstract
  base class, with three concrete forms (`ShrubberyCreationForm`,
  `RobotomyRequestForm`, `PresidentialPardonForm`), each overriding an
  `execute()` action.
- **ex03 — At least this beats coding grade trackers**: an `Intern` class
  able to create any of the three forms above by name, using a factory-like
  pattern instead of a long `if`/`else if` chain.

### cpp06 — C++ casts

- **ex00 — Scalar conversion**: `ScalarConverter` converts a literal
  (`char`, `int`, `float`, `double`) given as a string into all the other
  scalar types, handling special values (`nan`, `+inf`, `-inf`) and
  out-of-range cases.
- **ex01 — Serialization**: converts a pointer to a `Data` struct into an
  integer (`uintptr_t`) and back, using `reinterpret_cast`, to show that a
  pointer's value can safely be represented as an integer and restored.
- **ex02 — Identify real type**: given a `Base*` or `Base&` pointing to
  one of `A`, `B` or `C`, uses `dynamic_cast` to identify the real derived
  type at runtime.

### cpp07 — Templates

- **ex00 — Introduction to templates**: generic `swap`, `min` and `max`
  functions working on any comparable type.
- **ex01 — Iter**: a generic `iter` function applying another function
  (or function object) to every element of an array, regardless of its
  type.
- **ex02 — Array**: a generic `Array<T>` class, allocated dynamically,
  with bounds-checked access and a proper canonical form.

### cpp08 — Templated containers, iterators, algorithms

- **ex00 — Easyfind**: a generic function returning an iterator to the
  first occurrence of a value inside any STL container that supports
  `find`.
- **ex01 — Span**: a `Span` class storing up to N integers and able to
  compute the shortest and longest distance between any two of its
  elements.
- **ex02 — Mutated abomination**: `MutantStack`, a `std::stack` adapted to
  expose iterators, so it can be traversed like any other STL container.

### cpp09 — STL

- **ex00 — Bitcoin exchange**: reads a CSV-like database of historical
  Bitcoin prices and a separate input file, and prints the value of each
  input date/amount pair based on that database, with input validation.
- **ex01 — Reverse Polish Notation**: a simple RPN calculator that
  evaluates an expression given as command-line arguments, using a stack.
- **ex02 — PmergeMe**: implements the merge-insertion sort (Ford-Johnson
  algorithm) on both a `std::vector` and a `std::deque`, and compares
  their processing time to show why container choice matters.

## Resources

`resources/` contains personal notes on C++ OOP concepts
(`lexique_poo_cpp.md`, `lexique_poo_cpp_part2.md`), written while working
through this piscine.

## AI usage

In accordance with 42's AI charter, it is stated that artificial
intelligence was used on this project for:

- Debugging.
- Explaining C++ concepts in more depth while working through the
  exercises.

The exercises themselves — the classes, their design and their
implementation — were written by the author.
