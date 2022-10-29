#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include "common.hpp"
#include "gc.hpp"
class Vertex {
    private:
        std::string label;
        int kruskal;

    public:
        Vertex(std::string label) : label{label} {};
        Vertex(const Vertex& v) : label{v.label} {};
        std::string getLabel() const;
        friend std::ostream& operator<<(std::ostream& os, const Vertex& v);
};

class Edge {
    private:
        Vertex *source, *destination;
        int weight;

    public:
        Edge(std::string label1, std::string label2, int weight);
        Edge(Vertex* v1, Vertex* v2, int weight) : source{v1}, destination{v2}, weight{weight} {}
        Edge(const Edge& e) : source{e.source}, destination{e.destination}, weight{e.weight} {}
        Vertex* getSource() const;
        Vertex* getDestination() const;
        int getWeight() const;
        void setWeight(int w);
        friend std::ostream& operator<<(std::ostream& os, const Edge& e);
};

class Graph {
    private:
        std::vector<Vertex*> vertices;
        std::vector<Edge*> edges;
     
    public:
        Graph( std::vector<Edge*> edges, std::vector<Vertex*> vertices) : vertices{vertices}, edges{edges}{}
        Graph(const Graph& g) : vertices{g.vertices}, edges{g.edges} {}
        Vertex* addVertex(Vertex* v);
        Vertex* addVertex(std::string label);
        Edge* addEdge(Edge* e);
        Edge* addEdge(Vertex* v1, Vertex* v2, int w);
        Edge* addEdge(std::string label1, std::string label2, int w);
        int weight() const;
        void symetrize();
        std::vector<Vertex*> getVertices() const;
        std::vector<Edge*> getEdges() const;
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);
        virtual ~Graph();
};

#endif