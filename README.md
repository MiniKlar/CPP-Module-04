# CPP Module 04 — Polymorphism, Abstract Classes & Interfaces

> 42 C++ Piscine · Subtype polymorphism, virtual functions, abstract classes and pure interfaces — built around the classic `Animal` / `Brain` hierarchy and the `Materia` interface system.

---

## 🇬🇧 English

### Theme

Module 04 explores **subtype polymorphism** in C++98. Starting from a base
`Animal` class, derived `Dog` and `Cat` classes override behavior through
**virtual functions** resolved at runtime via the vtable. The module then
contrasts correct virtual dispatch with a `WrongAnimal` hierarchy that lacks
`virtual`, introduces **deep copy** with a `Brain` member, turns the base class
into a true **abstract class** (`AAnimal`), and finishes with a full
**interface** design (`AMateria`, `ICharacter`, `IMateriaSource`).

### Exercises

| Exercise | Binary | Focus | Key classes |
|----------|--------|-------|-------------|
| **ex00** | `Polymorphism` | Subtype polymorphism vs. non-virtual dispatch | `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat` |
| **ex01** | `RezeTime` | Deep copy & owned resources | `Animal`, `Dog`, `Cat`, `Brain` |
| **ex02** | `AbstractionTime` | Abstract base class (pure virtual) | `AAnimal`, `Dog`, `Cat`, `Brain` |
| **ex03** | `InterfaceAndRecap` | Interfaces & a Materia/Character system | `AMateria`, `Ice`, `Cure`, `ICharacter`, `Character`, `IMateriaSource`, `MateriaSource` |

**Details**

- **ex00 — Polymorphism.** A base `Animal` with a `virtual makeSound()` and a
  `virtual` destructor. `Dog` and `Cat` derive from it and override `makeSound()`.
  Calling `makeSound()` through an `Animal*` invokes the derived version. The
  parallel `WrongAnimal` / `WrongCat` pair has **no** `virtual`, so the call is
  statically bound to the base — demonstrating exactly what `virtual` buys you.
- **ex01 — RezeTime.** Each `Dog` and `Cat` owns a `Brain*` (an array of 100
  ideas). Copying an animal must perform a **deep copy** (new `Brain`, copied
  contents) so two animals never share the same heap object — and the destructor
  frees it, avoiding leaks and double-frees.
- **ex02 — AbstractionTime.** `AAnimal` makes `makeSound()` **pure virtual**
  (`= 0`) and gives the destructor a pure-virtual declaration too, so the class
  can no longer be instantiated directly — only concrete `Dog`/`Cat` can.
- **ex03 — InterfaceAndRecap.** A small RPG-style system: `AMateria` is an
  abstract materia with a pure-virtual `clone()`; `Ice` and `Cure` are concrete
  materias. `ICharacter` / `IMateriaSource` are pure interfaces implemented by
  `Character` (a 4-slot inventory) and `MateriaSource` (a materia factory using
  `learnMateria` / `createMateria`).

### Build & Run

Each exercise is self-contained with its own `Makefile`. From the repo root:

```bash
cd ex00 && make && ./Polymorphism
cd ex01 && make && ./RezeTime
cd ex02 && make && ./AbstractionTime
cd ex03 && make && ./InterfaceAndRecap
```

Common Makefile rules: `make` (build), `make clean`, `make fclean`, `make re`.
Compiled with `-Wall -Wextra -Werror -std=c++98`.

### What I learned

- **Subtype polymorphism** — calling derived behavior through a base pointer or
  reference.
- **Virtual functions & the vtable** — how `virtual` enables runtime dispatch,
  and why a non-virtual base call binds statically (the `WrongAnimal` lesson).
- **Virtual destructors** — required so `delete base_ptr` runs the correct
  derived destructor and frees owned resources.
- **Abstract classes** — pure-virtual methods (`= 0`) that make a class
  non-instantiable and force subclasses to implement an interface.
- **Pure interfaces** — abstract classes with only pure-virtual methods, used to
  decouple contracts (`ICharacter`, `IMateriaSource`) from implementations.
- **Deep copy** — owning heap resources (`Brain`, materia inventory) safely via
  the copy constructor, copy assignment and destructor (Rule of Three).

---

## 🇫🇷 Français

### Thème

Le Module 04 explore le **polymorphisme par sous-typage** en C++98. À partir
d'une classe de base `Animal`, les classes dérivées `Dog` et `Cat` redéfinissent
leur comportement grâce aux **fonctions virtuelles**, résolues à l'exécution via
la vtable. Le module oppose ensuite la liaison dynamique correcte à une
hiérarchie `WrongAnimal` dépourvue de `virtual`, introduit la **copie profonde**
avec un membre `Brain`, transforme la classe de base en véritable **classe
abstraite** (`AAnimal`), puis se conclut par une conception complète à base
d'**interfaces** (`AMateria`, `ICharacter`, `IMateriaSource`).

### Exercices

| Exercice | Binaire | Objectif | Classes clés |
|----------|---------|----------|--------------|
| **ex00** | `Polymorphism` | Polymorphisme par sous-typage vs liaison statique | `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat` |
| **ex01** | `RezeTime` | Copie profonde & ressources possédées | `Animal`, `Dog`, `Cat`, `Brain` |
| **ex02** | `AbstractionTime` | Classe abstraite (méthode purement virtuelle) | `AAnimal`, `Dog`, `Cat`, `Brain` |
| **ex03** | `InterfaceAndRecap` | Interfaces & système Materia/Character | `AMateria`, `Ice`, `Cure`, `ICharacter`, `Character`, `IMateriaSource`, `MateriaSource` |

**Détails**

- **ex00 — Polymorphism.** Une classe de base `Animal` avec `virtual makeSound()`
  et un destructeur `virtual`. `Dog` et `Cat` en dérivent et redéfinissent
  `makeSound()`. Appeler `makeSound()` via un `Animal*` invoque la version
  dérivée. Le couple `WrongAnimal` / `WrongCat`, lui, n'a **pas** de `virtual` :
  l'appel est lié statiquement à la base — ce qui montre précisément l'apport de
  `virtual`.
- **ex01 — RezeTime.** Chaque `Dog` et `Cat` possède un `Brain*` (un tableau de
  100 idées). Copier un animal doit réaliser une **copie profonde** (nouveau
  `Brain`, contenu recopié) pour que deux animaux ne partagent jamais le même
  objet sur le tas — et le destructeur le libère, évitant fuites et doubles
  libérations.
- **ex02 — AbstractionTime.** `AAnimal` rend `makeSound()` **purement virtuelle**
  (`= 0`) et déclare aussi le destructeur purement virtuel : la classe ne peut
  plus être instanciée directement — seuls les `Dog`/`Cat` concrets le peuvent.
- **ex03 — InterfaceAndRecap.** Un petit système de type RPG : `AMateria` est une
  materia abstraite avec un `clone()` purement virtuel ; `Ice` et `Cure` sont des
  materias concrètes. `ICharacter` / `IMateriaSource` sont des interfaces pures
  implémentées par `Character` (un inventaire de 4 emplacements) et
  `MateriaSource` (une fabrique de materias via `learnMateria` / `createMateria`).

### Compilation & Lancement

Chaque exercice est autonome avec son propre `Makefile`. Depuis la racine du dépôt :

```bash
cd ex00 && make && ./Polymorphism
cd ex01 && make && ./RezeTime
cd ex02 && make && ./AbstractionTime
cd ex03 && make && ./InterfaceAndRecap
```

Règles Makefile communes : `make` (compilation), `make clean`, `make fclean`,
`make re`. Compilé avec `-Wall -Wextra -Werror -std=c++98`.

### Ce que ça m'a apporté

- **Polymorphisme par sous-typage** — appeler le comportement dérivé via un
  pointeur ou une référence sur la base.
- **Fonctions virtuelles & vtable** — comment `virtual` permet la liaison
  dynamique, et pourquoi un appel non virtuel sur la base est lié statiquement
  (la leçon `WrongAnimal`).
- **Destructeurs virtuels** — indispensables pour que `delete base_ptr` exécute
  le bon destructeur dérivé et libère les ressources possédées.
- **Classes abstraites** — méthodes purement virtuelles (`= 0`) qui rendent une
  classe non instanciable et forcent les sous-classes à implémenter un contrat.
- **Interfaces pures** — classes abstraites ne contenant que des méthodes
  purement virtuelles, pour découpler les contrats (`ICharacter`,
  `IMateriaSource`) de leurs implémentations.
- **Copie profonde** — posséder des ressources sur le tas (`Brain`, inventaire de
  materias) en toute sûreté via le constructeur de copie, l'affectation et le
  destructeur (règle de trois).
