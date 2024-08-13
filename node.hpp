// 206396863
// natalisadikov2318@gmail.com

#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
using namespace std;

template <typename T>
class Node
{

public:
    T key;                     
    vector<Node<T> *> children; 

    Node(T value) : key(value) {}
    
    T get_key() const { return key; }
    
    vector<Node *> &get_children() { return children; }
   
    void add_child(Node<T> *child)
    {
        children.push_back(child);
    }
   
    void clear_children()
    {
        children.clear();
    }
};

#endif
