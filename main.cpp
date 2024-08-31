
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "visualiz.hpp"
#include "complex"

using namespace std;

int main(){
    // Create nodes 
    Node<int> root(1);
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);
    Node<int> n6(7);
    Node<int> n7(8);
    Node<int> n8(9);
    Node<int> n9(10);
    Node<int> n10(11);
    
    Tree<int> t1; // create tree
    t1.add_root(root);
    t1.add_sub_node(root, n1);
    t1.add_sub_node(root, n2);
    t1.add_sub_node(n1, n3);
    t1.add_sub_node(n1, n4);
    t1.add_sub_node(n2, n5);
    //display the t1 on the screen
    VisualizeTree<int> d1(t1);
    d1.print_tree();

    //print all iterators

    cout << "Preorder : " << endl;
    for (auto node = t1.begin_pre_order(); node != t1.end_pre_order(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "Postorder: " << endl;
    for (auto node = t1.begin_post_order(); node != t1.end_post_order(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "Min Heap :" << endl;
    for (auto node = t1.begin_heap(); node != t1.end_heap(); ++node){
        cout << node->get_key() << endl;
    } 
        cout << "Inorder : " << endl;
    for (auto node = t1.begin_in_order(); node != t1.end_in_order(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "BFS : " << endl;
    for (auto node = t1.begin_bfs_scan(); node != t1.end_bfs_scan(); ++node){
        cout << node->get_key() << endl;
    } 

    cout << "DFS : " << endl;
    for (auto node = t1.begin_dfs_scan(); node != t1.end_dfs_scan(); ++node){
        cout << node->get_key() << endl;
    } 
    
    root.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();
    
    Tree<int> t2(3); 
    t2.add_root(root);
    t2.add_sub_node(root, n1);
    t2.add_sub_node(root, n2);
    t2.add_sub_node(root, n3);
    t2.add_sub_node(n1, n4);
    t2.add_sub_node(n1, n5);
    t2.add_sub_node(n1, n6);
    t2.add_sub_node(n2, n7);
    t2.add_sub_node(n2, n8);
    t2.add_sub_node(n3, n9);
    t2.add_sub_node(n3, n10);
    //display the t2 on the screen
    VisualizeTree<int> d2(t2);
    d2.print_tree();
    
    //print all iterators
 
    cout << "Postorder: " << endl;
    for (auto node = t2.begin_post_order(); node != t2.end_post_order(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "Inorder : " << endl;
    for (auto node = t2.begin_in_order(); node != t2.end_in_order(); ++node){
        cout << node->get_key() << endl;
    }

       cout << "BFS : " << endl;
    for (auto node = t2.begin_bfs_scan(); node != t2.end_bfs_scan(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "DFS : " << endl;
    for (auto node = t2.begin_dfs_scan(); node != t2.end_dfs_scan(); ++node){
        cout << node->get_key() << endl;
    }

     cout << "Preorder : " << endl;
    for (auto node = t2.begin_pre_order(); node != t2.end_pre_order(); ++node){
        cout << node->get_key() << endl;
    }
    
    root.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();
    
    
    
    Node<string> root1("a");
    Node<string> n11("b");
    Node<string> n22("c");
    Node<string> n33("d");
    Node<string> n44("e");
    
    
    Tree<string> t3(2); 
    t3.add_root(root1);
    t3.add_sub_node(root1, n11);
    t3.add_sub_node(root1, n22);
    t3.add_sub_node(n11, n33);
    t3.add_sub_node(n11, n44);
    //display the t3 on the screen
    VisualizeTree<string> d3(t3);
    d3.print_tree();
    
    //print all iterators
 
    cout << "Postorder: " << endl;
    for (auto node = t3.begin_post_order(); node != t3.end_post_order(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "Inorder : " << endl;
    for (auto node = t3.begin_in_order(); node != t3.end_in_order(); ++node){
        cout << node->get_key() << endl;
    }

       cout << "BFS : " << endl;
    for (auto node = t3.begin_bfs_scan(); node != t3.end_bfs_scan(); ++node){
        cout << node->get_key() << endl;
    }

    cout << "DFS : " << endl;
    for (auto node = t3.begin_dfs_scan(); node != t3.end_dfs_scan(); ++node){
        cout << node->get_key() << endl;
    }

     cout << "Preorder : " << endl;
    for (auto node = t3.begin_pre_order(); node != t3.end_pre_order(); ++node){
        cout << node->get_key() << endl;
    }

    root.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();
    

    // Create nodes with complex numbers
    Node<Complex> complex_root(Complex(1.0, 1.0));
    Node<Complex> complex_n1(Complex(2.0, 2.0));
    Node<Complex> complex_n2(Complex(3.0, 3.0));
    Node<Complex> complex_n3(Complex(4.0, 4.0));
    Node<Complex> complex_n4(Complex(5.0, 5.0));
    Node<Complex> complex_n5(Complex(6.0, 6.0));

    // Create a tree with complex numbers
    Tree<Complex> complexTree;

     // Build the tree structure
    complexTree.add_root(complex_root);
    complexTree.add_sub_node(complex_root, complex_n1);
    complexTree.add_sub_node(complex_root, complex_n2);
    complexTree.add_sub_node(complex_n1, complex_n3);
    complexTree.add_sub_node(complex_n1, complex_n4);
    complexTree.add_sub_node(complex_n2, complex_n5);


    // Visualize the tree
    VisualizeTree<Complex> visualizer(complexTree);
    visualizer.print_tree();

    // Demonstrate different tree traversals
    std::cout << "Preorder traversal:" << std::endl;
    for (auto it = complexTree.begin_pre_order(); it != complexTree.end_pre_order(); ++it) {
        std::cout << it->get_key() << " ";
    }
    std::cout << std::endl;

    std::cout << "Postorder traversal:" << std::endl;
    for (auto it = complexTree.begin_post_order(); it != complexTree.end_post_order(); ++it) {
        std::cout << it->get_key() << " ";
    }
    std::cout << std::endl;

    std::cout << "Inorder traversal:" << std::endl;
    for (auto it = complexTree.begin_in_order(); it != complexTree.end_in_order(); ++it) {
        std::cout << it->get_key() << " ";
    }
    std::cout << std::endl;

    std::cout << "BFS traversal:" << std::endl;
    for (auto it = complexTree.begin_bfs_scan(); it != complexTree.end_bfs_scan(); ++it) {
        std::cout << it->get_key() << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS traversal:" << std::endl;
    for (auto it = complexTree.begin_dfs_scan(); it != complexTree.end_dfs_scan(); ++it) {
        std::cout << it->get_key() << " ";
    }
    std::cout << std::endl;



}
