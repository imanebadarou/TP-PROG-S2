#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}


Node* create_node(int value){
    Node* node { new Node {value, nullptr, nullptr}};
    return node;
}

bool Node::is_leaf() const{
    if(this->left == nullptr && this->right == nullptr){
        return true;
    }
    return false;
}


void Node::insert(int value){
    Node* node = create_node(value);
    if(node->value < this->value){
        this->left = node;
    }
    else{
        this->right = node;
    }
}

int Node::height() const{
    if(this->is_leaf()){
        return 1;
    }
    else{
        int left_height = left->height();
        int right_height = right->height();
        return 1 + std::max(right_height, left_height);
    }
}

void Node::delete_children(){
    if(left != nullptr){
        left->delete_children();
        delete left;
    }
    if(right != nullptr){
        right->delete_children();
        delete right;
    }
}