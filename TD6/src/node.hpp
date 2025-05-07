#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;

    void insert(int value);
    int height() const;

    void delete_children();

    void display_infix() const;
    std::vector<Node const*> prefix() const;
};

Node* create_node(int value);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);


