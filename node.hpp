#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
using namespace std;

// this class represents a node
template <typename T>
class Node
{

public:
    T key; // key of the node
    vector<Node<T> *> children; // childrens of the node

    // constractor for node
    Node(T value) : key(value) {}

    // getter(return the key of the node )
    T get_key() const { return key; }

    // getter(return the childrens of the node )
    vector<Node *> &get_children() { return children; }

    // add children to the node
    void add_child(Node<T> *child)
    {
        children.push_back(child);
    }

    // clear the vector of the childrens
    void clear_children()
    {
        children.clear();
    }
};

#endif
