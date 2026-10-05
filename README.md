# Assembly-Line Workstation Balancing in C

Academic C project exploring how manufacturing operations can be assigned to workstations while respecting practical constraints such as cycle time, precedence relationships, and operation exclusions.

## Project objective

The project models a simplified assembly-line balancing problem.

Given a set of operations, execution times, and compatibility constraints, the programs attempt to distribute operations across workstations while keeping the assignment consistent with the available constraints.

The repository contains several experimental implementations produced during the project rather than a single production application.

## Main concepts explored

- workstation assignment;
- operation execution times;
- cycle-time constraints;
- precedence relationships;
- mutual-exclusion constraints;
- graph-based reasoning;
- greedy assignment strategies;
- dynamic memory allocation in C;
- file-based input processing.

## Example: cycle-time assignment

One implementation reads operation durations and a target cycle time, sorts operations by execution time, and assigns them to stations while ensuring that the accumulated duration of a station does not exceed the cycle-time limit.

Simplified flow:

```text
operations + durations
        |
        v
sort / evaluate operations
        |
        v
current workstation capacity
        |
        +---- fits ----> assign operation
        |
        +-- no fit ----> create another workstation
```

## Exclusion constraints

Other experiments model pairs of operations that should not be assigned to the same workstation.

A graph-colouring-style approach is used in some implementations:

- operations are treated as vertices;
- exclusion relationships act as edges;
- workstation identifiers are represented as colours;
- incompatible operations receive different assignments.

## Technologies

- C
- standard C file I/O
- pointers and dynamic memory allocation
- arrays and structures
- basic graph/constraint algorithms

## Repository notes

This repository reflects an early engineering-school project and contains multiple approaches developed by team members while exploring the problem.

The code is intentionally preserved as part of the project history. Some files represent intermediate experiments rather than the final implementation.

## Building an individual C file

With GCC:

```bash
gcc temps.c -o temps
./temps
```

On Windows:

```powershell
gcc temps.c -o temps.exe
.\temps.exe
```

Individual source files may expect input files such as operation durations, cycle-time values, precedence data, or exclusion pairs to be present in the working directory.

## What this project demonstrates

Although this is an early academic project, it covers several useful programming fundamentals:

- translating a constraint problem into code;
- reading structured data from files;
- using structures and pointers;
- managing dynamically allocated memory;
- designing simple allocation heuristics;
- experimenting with graph-colouring concepts;
- collaborating through a shared Git repository.

## Context

This work was completed as a collaborative engineering-school assignment. It is kept public as an example of early C programming and algorithmic problem solving.
