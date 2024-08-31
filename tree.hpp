#ifndef TREE_HPP
#define TREE_HPP
#include <vector>
#include <iomanip>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include "node.hpp"
#include "complex.hpp"
using namespace std;

// this class represents a tree
template <typename T>
class Tree
{
private:
    Node<T> *root; // root of the tree
    size_t k;  // max number of children for a node

public:
    // constractor for the tree
    // default value of the k is 2
    explicit Tree(size_t k = 2) : root(nullptr), k(k) {}

    // destractor
    ~Tree() {}

    // add root to the tree
    void add_root(Node<T> &node)
    {
        // if the root not exist we update the root
        if (!root)
        {
            root = &node;
        }
        // if the root exist we throw a error
        else
        {
            throw runtime_error("Error .Root of the the tree exists");
        }
    }

    // return the root of the tree
    Node<T> *get_root() const
    {
        return root;
    }

    // add  a node to the tree
    void add_sub_node(Node<T> &parent, Node<T> &ch)
    {
        // if not exist we throw a error
        if (!root)
        {
            throw runtime_error("The Tree is empty");
        }
        // check if the number of children of the node is < k and add the node
        if (parent.children.size() < k)
        {
            parent.add_child(&ch);
        }
        // if the number of children > k we throw a error
        else
        {
            throw runtime_error("Error in the number of childrens");
        }
    }

    // this class represent the preorder iterator
public:
    class PreOrderIterator
    {
    private:
        stack<Node<T> *> st1; // stack for the preorder

    public:
        PreOrderIterator() = default;

        // constractor for the preorder iterator
        PreOrderIterator(Node<T> *root)
        {
            // check if the root exist and we add the root to the stack
            if (root)
            {
                st1.push(root);
            }
        }

        // operator!= for preorder iteraotor
        // check is the stack is empty
        bool operator!=(const PreOrderIterator &other) const
        {
            return !st1.empty();
        }

        // operator* for preorder iteraotor
        // return the top of the stack
        Node<T> &operator*() const
        {
            return *st1.top();
        }

        // operator-> for preorder iteraotor
        // return the pointer of  top of the stack
        Node<T> *operator->() const
        {
            return st1.top();
        }

        // operator++ for preorder iteraotor
        PreOrderIterator &operator++()
        {
            // store the top of the stack
            Node<T> *node = st1.top();
            // remove the top of the stack
            st1.pop();
            // add the children of the top of the stack to the stack
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
            {
                st1.push(*i);
            }
            return *this;
        }
    };

    // this class represent the postorder iterator
    class PostOrderIterator
    {
    private:
        stack<Node<T> *> st1, st2; // stacks for  postorder

    public:
        PostOrderIterator() = default;

        // constractor for postorder iterator
        PostOrderIterator(Node<T> *root)
        {
            // check if the root exist and add the root to the stack1
            if (root)
            {
                st1.push(root);
                // check if the stack1 is empty
                while (!st1.empty())
                {
                    // store the top of stack1
                    Node<T> *node = st1.top();
                    // remove the top of the stack1
                    st1.pop();
                    // add the top of the stack1 to the stack2
                    st2.push(node);
                    // add the childrens of the top of stack1 to the stack1
                    for (auto ch : node->children)
                    {
                        st1.push(ch);
                    }
                }
            }
        }

        // operator!= for postorder iteraotor
        // check is the stack2 is empty
        bool operator!=(const PostOrderIterator &other) const
        {
            return !st2.empty();
        }

        // operator* for postorder iteraotor
        // return the top of the stack2
        Node<T> &operator*() const
        {
            return *st2.top();
        }

        // operator-> for postorder iteraotor
        // return the pointer of the top of the stack2
        Node<T> *operator->() const
        {
            return st2.top();
        }

        // operator++ for postorder iteraotor
        // return the top of the stack2
        PostOrderIterator &operator++()
        {
            // remove the top of the stack2
            st2.pop();
            return *this;
        }
    };

    // this class represent the bfs iterator
    class BFSIterator
    {
    private:
        queue<Node<T> *> queu_bfs; // queu for bfs iterator

    public:
        BFSIterator() = default;

        // constractor for the bfs iterator
        BFSIterator(Node<T> *root)
        {
            // check if the root exists and add the root of the queu of bfd
            if (root)
            {
                queu_bfs.push(root);
            }
        }

        // operator!= for bfs iteraotor
        // check is the queue is empty
        bool operator!=(const BFSIterator &other) const
        {
            return !queu_bfs.empty();
        }

        // operator* for bfs iteraotor
        // return the front of the queu
        Node<T> &operator*() const
        {
            return *queu_bfs.front();
        }

        // operator-> for bfs iteraotor
        // return the pointer of the front  of the queu
        Node<T> *operator->() const
        {
            return queu_bfs.front();
        }

        // operator++ for bfs iteraotor
        BFSIterator &operator++()
        {
            // store the front of the queu of the bfs
            Node<T> *node = queu_bfs.front();
            // remove the front of the queu
            queu_bfs.pop();
            // add the childrens of the front of the queu to the queu_bfs
            for (auto ch : node->children)
            {
                queu_bfs.push(ch);
            }
            return *this;
        }
    };

    // this class represent the inorder  iterator
    class InOrderIterator
    {
    private:
        stack<Node<T> *> st1;  // stack for inorder iterator
        Node<T> *current_node; // current node

        // push left
        void push_left(Node<T> *node)
        {
            while (node)
            {
                // add the node to the stack
                st1.push(node);
                // if the vector of childrens of the node is not empty
                // update the node to be the left children of node
                if (!node->children.empty())
                {
                    node = node->children[0];
                }
                // if the vector of childrens of the node is empty
                // update the node to be null
                else
                {
                    node = nullptr;
                }
            }
        }

    public:
        InOrderIterator() = default;

        // constractor for  inorder iterator
        InOrderIterator(Node<T> *root) : current_node(root)
        {
            push_left(root);
        }
        // operator!= for inorder iterator
        // check if the stack is empty
        bool operator!=(const InOrderIterator &other) const
        {
            return !st1.empty();
        }
        // operator* for inorder iterator
        // return the top of the stack
        Node<T> &operator*() const
        {
            return st1.top();
        }
        // operator-> for inorder iterator
        // return the pointer of the top of the stack
        Node<T> *operator->() const
        {
            return st1.top();
        }

        // operator++ for inorder iterator
        InOrderIterator &operator++()
        {
            // store the top of the stack
            Node<T> *node = st1.top();
            // remove the top of the stack
            st1.pop();
            // if the children of the node is not empty
            if (!node->children.empty())
            {
                // doo push left on each children of the node
                for (size_t i = 1; i < node->children.size(); ++i)
                {
                    push_left(node->children[i]);
                }
            }
            return *this;
        }
    };

    // this class represent the dfs iterator
    class DFSIterator
    {
    private:
        stack<Node<T> *> st1; // stack for the dfs iterator

    public:
        DFSIterator() = default;

        // constractor for dfs iterator
        DFSIterator(Node<T> *root)
        {
            // chec if the root exist
            // if yes add the root to the stack
            if (root)
            {
                st1.push(root);
            }
        }
        // operator!= for dfs iterator
        // check if the stack is empty
        bool operator!=(const DFSIterator &other) const
        {
            return !st1.empty();
        }

        // operator* for inorder iterator
        // return the top of the stack
        Node<T> &operator*()
        {
            return *st1.top();
        }

        // operator-> for inorder iterator
        // return the pointer of the top of the stack
        Node<T> *operator->()
        {
            return st1.top();
        }

        // operator++ for inorder iterator
        DFSIterator &operator++()
        {
            // store the top of the stack
            Node<T> *node = st1.top();
            // remove the top of the stack
            st1.pop();
            // add childrens f the node to the stack
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
            {
                st1.push(*i);
            }
            return *this;
        }
    };

    // this class represent the heap iterator
    class HeapIterator
    {
    private:
        vector<Node<T> *> vec_heap_iterator; // vector fot the heap iterator

        // struct for nodeComparator
        struct NodeCompartor
        {
            bool operator()(Node<T> *n1, Node<T> *n2)
            {
                return n1->get_key() > n2->get_key();
            }
        };

        // this function collect the nodes
        void collect_nodes(Node<T> *node)
        {
            // check if node exists
            if (node)
            {
                // add the node to the vector for heap iterator
                vec_heap_iterator.push_back(node);
                // continue by recursion on all childrens of the node
                for (auto ch : node->get_children())
                {
                    collect_nodes(ch);
                }
            }
        }

    public:
        HeapIterator() = default;

        // constractor for the heap iterator
        HeapIterator(Node<T> *root, size_t k)
        {
            // if the k is different of 2 throw error
            if (k != 2)
            {
                throw runtime_error("The k must be 2 to heap tree");
            }
            // if k=2
            // ckeck if root exists
            if (root)
            {
                // collet nodes
                collect_nodes(root);
                // make heap
                make_heap(vec_heap_iterator.begin(), vec_heap_iterator.end(), NodeCompartor());
            }
        }

        // operator != for heap iterator
        // check if empty the vec_heap
        bool operator!=(const HeapIterator &other) const
        {
            return !vec_heap_iterator.empty() != !other.vec_heap_iterator.empty();
        }
        // operator ->for heap iterator
        // return the pointer of the front of the vec_heap
        Node<T> *operator->() const
        {
            return vec_heap_iterator.front();
        }

        // operator* for heap iterator
        // return  the front of the vec_heap
        Node<T> &operator*() const
        {
            return *vec_heap_iterator.front();
        }
        // operator ++ for heap iterator
        HeapIterator &operator++()
        {
            // check if the vec_heap is not empty
            if (!vec_heap_iterator.empty())
            {
                // pop heap
                pop_heap(vec_heap_iterator.begin(), vec_heap_iterator.end(), NodeCompartor());
                vec_heap_iterator.pop_back();
            }
            return *this;
        }
    };

    // we declare the begin and the end for all iterator
    auto begin_pre_order() const { return PreOrderIterator(root); }
    auto end_pre_order() const { return PreOrderIterator(); }
    auto begin_post_order() const { return PostOrderIterator(root); }
    auto end_post_order() const { return PostOrderIterator(); }
    auto begin_in_order() const { return InOrderIterator(root); }
    auto end_in_order() const { return InOrderIterator(); }
    auto begin_heap() const { return HeapIterator(root, k); }
    auto end_heap() const { return HeapIterator(); }
    auto begin_bfs_scan() const { return BFSIterator(root); }
    auto end_bfs_scan() const { return BFSIterator(); }
    auto begin_dfs_scan() const { return DFSIterator(root); }
    auto end_dfs_scan() const { return DFSIterator(); }
};

#endif
