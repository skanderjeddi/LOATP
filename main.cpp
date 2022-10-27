#include "common.hpp"
#include "graph.hpp"

bool DEBUG;

int main() {
    DEBUG = true;
    Graph graph1{ std::vector<Edge*>{}, std::vector<Vertex*>{} };
    Vertex* a0 = graph1.addVertex("A");
    Vertex* b0 = graph1.addVertex("B");
    Vertex c{"C"};
    graph1.addVertex(&c);
    Vertex e{"E"};
    graph1.addEdge(a0, b0, 1);
    graph1.addEdge(a0, b0, 2);
    graph1.addEdge(a0, &c, -1);
    graph1.addEdge(&c, &e, 3);
    Edge e1{"F", "G", 4};  
    Edge e2{a0, b0, 1};
    graph1.addEdge(&e1);
    graph1.addEdge(&e2);
    std::cout << graph1;
}