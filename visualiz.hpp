#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <map>
#include <functional>

//this class represent the visualiation of the tree on the screen
template <typename T>
class VisualizeTree {
private:
    Tree<T>& tree;//tree
    sf::RenderWindow screen;//window 
    std::map<Node<T>*, sf::Vector2f> m_nodes;//map of nodes that store the position of all the nodes
    sf::Font f;//font 
 
    void positions(Node<T>* node, float x, float y, float z) {
      //check if node exist
        if (!node) return;
        m_nodes[node] = sf::Vector2f(x, y);
        for (size_t i = 0; i < node->get_children().size(); ++i) {
            Node<T>* node_child = node->get_children()[i];
            if (node_child) {positions(node_child,  x - (node->get_children().size() - 1) * z / 2.f + i * z, y + 80.0f, z / 2.2f);}
        }
    }
    
     bool load_font() {
        if (!f.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            std::cerr << "Error " << std::endl;
            return false;
        }
        return true;
    }
//main fonction to draw the tree
    void draw_tree() {
        for (const auto& p : m_nodes) {
            Node<T>* node = p.first;
            sf::Vector2f pos = p.second;

            // draw circle
            sf::CircleShape c(25.0f);
            c.setFillColor(sf::Color::Cyan);
            c.setPosition(pos - sf::Vector2f(21.0f,21.0f));
            screen.draw(c);

            //text in the circle
            sf::Text key;
            key.setFont(f);
            std::ostringstream s;
            s << node->key;
            key.setString(s.str());
            key.setCharacterSize(20);
            key.setFillColor(sf::Color::Black);
            sf::FloatRect bounds = key.getLocalBounds();
            key.setOrigin(bounds.left + bounds.width / 1.8f, bounds.top + bounds.height / 1.8f);
            key.setPosition(pos);
            screen.draw(key);

            for (Node<T>* node_child : node->get_children()) {
                if (node_child) {
                    sf::Vector2f pos2 = m_nodes[node_child];
                    sf::Vertex line[] = {
                        sf::Vertex(pos, sf::Color::Black),
                        sf::Vertex(pos2, sf::Color::Black)
                    };
                    screen.draw(line, 2, sf::Lines);
                }
            }
        }
    }

public:

    //constractor for the visualize the tree
    VisualizeTree(Tree<T>& tree) : tree(tree), screen(sf::VideoMode(800, 1200), "Tree Visualization") {
        if (!load_font()) {
            std::cerr << "Error in the font " << std::endl;
            screen.close();
        }
    }
    
    //print the tree on the window 
    void print_tree() {
        //store the root of the tree
        Node<T>* root = tree.get_root();
        //check if the root exist 
        //if the root exist we calculate the position of all the nodes
        if (root) {
            positions(root, screen.getSize().x / 2.f, 200.0f, 220.0f);
        }
        while (screen.isOpen()) {
            sf::Event ev;
            while (screen.pollEvent(ev)) {
                if (ev.type == sf::Event::Closed){screen.close();}
                  
            }
            screen.clear(sf::Color::White);
            if (root) {draw_tree();}
            screen.display();
        }
    }
};

#endif
