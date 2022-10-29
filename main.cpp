#include "common.hpp"
#include "graph.hpp"

bool DEBUG;

int main() {
    DEBUG = true;
    Graph graph1{ std::vector<Edge*>{}, std::vector<Vertex*>{} };
    Vertex* a0 = graph1.addVertex("A");
    Vertex* b0 = graph1.addVertex("B");
    Vertex* c = graph1.addVertex("C");
    graph1.addVertex(c);
    Vertex* e = graph1.addVertex("E");
    graph1.addEdge(a0, b0, 1);
    graph1.addEdge(a0, b0, 2);
    graph1.addEdge(a0, c, -1);
    graph1.addEdge(c, e, 3);
    Edge* e1 = graph1.addEdge("F", "G", 4);  
    Edge* e2 = graph1.addEdge(a0, b0, 1);
    graph1.addEdge(e1);
    graph1.addEdge(e2);
    {
        Graph graph2{ std::vector<Edge*>{}, std::vector<Vertex*>{} };
        graph2.addEdge(a0, b0, 1);
        graph2.addEdge(a0, b0, 2);
        graph2.addVertex(c);
        graph2.addVertex("X");
        graph2.addEdge(e1);
        std::cout << graph2;
        if (DEBUG) GC::display();           
    }
    graph1.symetrize();
    std::cout << graph1;
    if (DEBUG) GC::display();
}