#include "node.hpp"



int main() {
    std::vector<int> valeurs  = {5, 3, 7, 2, 4, 6, 8, 1, 9, 0};
    Node* root = new Node(valeurs[0]);

    for (int val : valeurs) {
        root->insert(val);
    }

    std::cout << "Affichage infixe : ";
    root->display_infix();
    std::cout << "\n";


    auto prefix_nodes = root->prefix();
    int somme = 0;
    for (auto node : prefix_nodes) {
        somme += node->value;
    }

    std::cout << "\nSomme des valeurs : " << somme << "\n";

    std::cout << "Hauteur de l’arbre : " << root->height() << "\n";

    delete_tree(root);
    root = nullptr;

    return 0;
}
