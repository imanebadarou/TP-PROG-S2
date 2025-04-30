#include "graph.hpp"

void Graph::WeightedGraph::add_vertex(int const id){
    if(adjacency_list.find(id) == adjacency_list.end()){
        adjacency_list.insert({id, {}});
    }   
}

void Graph::WeightedGraph::add_directed_edge(int const from, int const to, float const weight){
    if(adjacency_list.find(to) == adjacency_list.end()){
        add_vertex(to);
    }
    if(adjacency_list.find(from) == adjacency_list.end()){
        add_vertex(from);
    }

    adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight){
    add_directed_edge(from, to, weight);
    add_directed_edge(to, from, weight);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(std::vector<std::vector<float>> const& adjacency_matrix){
    WeightedGraph graph {};

    for(int i{0}; i<adjacency_matrix.size(); i++){
        graph.add_vertex(i);
        for(int j{0}; j < adjacency_matrix[i].size(); j++){
            if(adjacency_matrix[i][j]!=0){
                graph.add_directed_edge(i, j,adjacency_matrix[i][j]);
            }
        }
    }
    return graph;
}