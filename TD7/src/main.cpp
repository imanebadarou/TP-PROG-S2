#include "graph.hpp"

int main(){
    std::vector<std::vector<float>> matrix = {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0}
    };

    Graph::WeightedGraph graphe = Graph::build_from_adjacency_matrix(matrix);


    Graph::WeightedGraph graphe_manuel;
        for (int i = 0; i < 5; ++i) {
        graphe_manuel.add_vertex(i);
    }

    graphe_manuel.add_directed_edge(0, 1, 1.0f);
    graphe_manuel.add_directed_edge(0, 4, 2.0f);
    graphe_manuel.add_directed_edge(1, 2, 2.0f);
    graphe_manuel.add_directed_edge(1, 3, 4.0f);
    graphe_manuel.add_directed_edge(2, 3, 1.0f);
    graphe_manuel.add_directed_edge(3, 4, 6.0f);

    if (graphe.adjacency_list == graphe_manuel.adjacency_list) {
        std::cout << "Les deux graphes sont égaux." << std::endl;
    } 
    else {
        std::cout << "Les deux graphes sont différents." << std::endl;
    }

    graphe.print_DFS(0);
    graphe.print_BFS(0);


}