# Tree Visualization Project

This project implements a generic tree data structure in C++ with various methods and a visualization component using SFML.

## Features

- Generic tree implementation supporting any data type
- Multiple tree traversal methods:
  - Pre-order
  - Post-order
  - In-order
  - Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Heap-order (for binary trees)
- Tree visualization using SFML
- Support for complex numbers as node values

## Files

- `node.hpp`: Defines the Node class template
- `tree.hpp`: Implements the Tree class template with various iterators
- `complex.hpp`: Defines a Complex number class
- `visualiz.hpp`: Implements the VisualizeTree class for graphical representation
- `main.cpp`: Contains example usage of the implemented classes


## Class Overview

### Node<T>
- Template class representing a node in the tree
- Stores a key of type T and a vector of child nodes

### Tree<T>
- Template class representing the tree structure
- Supports adding nodes and various traversal methods
- Includes nested iterator classes for different traversal orders

### Complex
- Represents complex numbers
- Supports basic operations and comparisons

### VisualizeTree<T>
- Uses SFML to create a graphical representation of the tree

## Example

The `main.cpp` file contains example usage of the implemented classes, including:
- Creating trees with integer and string values
- Demonstrating different traversal methods
- Visualizing the trees using SFML
