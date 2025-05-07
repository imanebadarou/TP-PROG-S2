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
    if (value < this->value){
        if (this->left == nullptr){
            this->left = create_node(value);
        } else {
            this->left->insert(value);
        }
    } 
    else if (value > this->value){
        if (this->right == nullptr){
            this->right = create_node(value);
        } 
        else{
            this->right->insert(value);
        }
    }
}


int Node::height() const{
    int right_height{};
    int left_height{};
    if(this==nullptr){
        return 0;
    }
    if(this->is_leaf()){
        return 1;
    }
    else{
        if(left != nullptr){
            left_height = left->height();
        }
        if(right != nullptr){
            right_height = right->height();
        }
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

void Node::display_infix() const{
    if (left != nullptr) {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right != nullptr) {
        right->display_infix();
    }
}

std::vector<Node const*> Node::prefix() const{
    std::vector<Node const*> nodes;
    nodes.push_back(this);

    if (left != nullptr){
        auto left_nodes = left->prefix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right != nullptr){
        auto right_nodes = right->prefix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

Node*& most_left(Node*& node){
    if (node->left == nullptr){
        return node;
    }
    return most_left(node->left);
}

bool remove(Node*& node, int value){
    if (node == nullptr){
        return false;
    }
    if (value < node->value){
        return remove(node->left, value);
    }
    else if (value > node->value){
        return remove(node->right, value);
    }
    else{
        // SI FEUILLE
        if (node->is_leaf()){
            delete node;
            node = nullptr;
            return true;
        }
        // SI 1 ENFANT
        else if (node->left == nullptr){
            Node* temp = node;
            node = node->right;
            delete temp;
            return true;
        }
        else if (node->right == nullptr){
            Node* temp = node;
            node = node->left;
            delete temp;
            return true;
        }
        // SI 2 ENFANTS
        else{
            Node*& successor = most_left(node->right);
            node->value = successor->value;
            return remove(node->right, successor->value);
        }
    }
}


void delete_tree(Node* node){
    if (node == nullptr){
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}
