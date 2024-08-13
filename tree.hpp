// 206396863
// natalisadikov2318@gmail.com

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


template <typename T>
class Tree
{
private:
    Node<T> *root; 
    size_t k;      

public:
    explicit Tree(size_t k = 2) : root(nullptr), k(k) {}
    ~Tree() {}

    void add_root(Node<T> &node)
    {
        if (!root)
        {
            root = &node;
        }
        else
        {
            throw runtime_error("Error .Root of the the tree exists");
        }
    }

    Node<T> *get_root() const
    {
        return root;
    }

    void add_sub_node(Node<T> &parent, Node<T> &ch)
    {
        if (!root)
        {
            throw runtime_error("The Tree is empty");
        }
        if (parent.children.size() < k)
        {
            parent.add_child(&ch);
        }
        else
        {
            throw runtime_error("Error in the number of childrens");
        }
    }

public:
    class PreOrderIterator
    {
    private:
        stack<Node<T> *> st1; 

    public:
        PreOrderIterator() = default;

        PreOrderIterator(Node<T> *root)
        {
            if (root)
            {
                st1.push(root);
            }
        }

        bool operator!=(const PreOrderIterator &other) const
        {
            return !st1.empty();
        }

        Node<T> &operator*() const
        {
            return *st1.top();
        }

        Node<T> *operator->() const
        {
            return st1.top();
        }

        PreOrderIterator &operator++()
        {

            Node<T> *node = st1.top();
            st1.pop();
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
            {
                st1.push(*i);
            }
            return *this;
        }
    };

    class PostOrderIterator
    {
    private:
        stack<Node<T> *> st1, st2; 

    public:
        PostOrderIterator() = default;


        PostOrderIterator(Node<T> *root)
        {
            if (root)
            {
                st1.push(root);
                while (!st1.empty())
                {
                   
                    Node<T> *node = st1.top();
                    st1.pop();
                    st2.push(node);
                    for (auto ch : node->children)
                    {
                        st1.push(ch);
                    }
                }
            }
        }

        bool operator!=(const PostOrderIterator &other) const
        {
            return !st2.empty();
        }

        Node<T> &operator*() const
        {
            return *st2.top();
        }

        Node<T> *operator->() const
        {
            return st2.top();
        }

        PostOrderIterator &operator++()
        {
            st2.pop();
            return *this;
        }
    };

    class BFSIterator
    {
    private:
        queue<Node<T> *> queu_bfs;

    public:
        BFSIterator() = default;

        BFSIterator(Node<T> *root)
        {
            if (root)
            {
                queu_bfs.push(root);
            }
        }

        bool operator!=(const BFSIterator &other) const
        {
            return !queu_bfs.empty();
        }

        Node<T> &operator*() const
        {
            return *queu_bfs.front();
        }

        Node<T> *operator->() const
        {
            return queu_bfs.front();
        }

        BFSIterator &operator++()
        {
            Node<T> *node = queu_bfs.front();
            queu_bfs.pop();
            for (auto ch : node->children)
            {
                queu_bfs.push(ch);
            }
            return *this;
        }
    };

    class InOrderIterator
    {
    private:
        stack<Node<T> *> st1; 
        Node<T> *current_node;

        void push_left(Node<T> *node)
        {

            while (node)
            {
                st1.push(node);
                if (!node->children.empty())
                {
                    node = node->children[0];
                }
                else
                {
                    node = nullptr;
                }
            }
        }

    public:
        InOrderIterator() = default;

        InOrderIterator(Node<T> *root) : current_node(root)
        {
            push_left(root);
        }

        bool operator!=(const InOrderIterator &other) const
        {
            return !st1.empty();
        }

        Node<T> &operator*() const
        {
            return st1.top();
        }

        Node<T> *operator->() const
        {
            return st1.top();
        }


        InOrderIterator &operator++()
        {

            Node<T> *node = st1.top();
            st1.pop();
            if (!node->children.empty())
            {
                for (size_t i = 1; i < node->children.size(); ++i)
                {
                    push_left(node->children[i]);
                }
            }
            return *this;
        }
    };

    class DFSIterator
    {
    private:
        stack<Node<T> *> st1; 

    public:
        DFSIterator() = default;

        DFSIterator(Node<T> *root)
        {
            if (root)
            {
                st1.push(root);
            }
        }

        bool operator!=(const DFSIterator &other) const
        {
            return !st1.empty();
        }

        Node<T> &operator*()
        {
            return *st1.top();
        }

        Node<T> *operator->()
        {
            return st1.top();
        }

        DFSIterator &operator++()
        {
            Node<T> *node = st1.top();
            st1.pop();
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i)
            {
                st1.push(*i);
            }
            return *this;
        }
    };

    class HeapIterator
    {
    private:
        vector<Node<T> *> vec_heap_iterator; 
        struct NodeCompartor
        {
            bool operator()(Node<T> *n1, Node<T> *n2)
            {
                return n1->get_key() > n2->get_key();
            }
        };

        void collect_nodes(Node<T> *node)
        {
            if (node)
            {
                vec_heap_iterator.push_back(node);
                for (auto ch : node->get_children())
                {
                    collect_nodes(ch);
                }
            }
        }

    public:
        HeapIterator() = default;

        HeapIterator(Node<T> *root, size_t k)
        {
            if (k != 2)
            {
                throw runtime_error("The k must be 2 to heap tree");
            }

            if (root)
            {
                collect_nodes(root);
                make_heap(vec_heap_iterator.begin(), vec_heap_iterator.end(), NodeCompartor());
            }
        }

        bool operator!=(const HeapIterator &other) const
        {
            return !vec_heap_iterator.empty() != !other.vec_heap_iterator.empty();
        }
        Node<T> *operator->() const
        {
            return vec_heap_iterator.front();
        }

        Node<T> &operator*() const
        {
            return *vec_heap_iterator.front();
        }

        HeapIterator &operator++()
        {
            if (!vec_heap_iterator.empty())
            {
                pop_heap(vec_heap_iterator.begin(), vec_heap_iterator.end(), NodeCompartor());
                vec_heap_iterator.pop_back();
            }
            return *this;
        }
    };

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
