#include "graph.hpp"
#include "gc.hpp"

std::string Vertex::getLabel() const {
    return label;
}

std::ostream& operator<<(std::ostream& os, const Vertex& v) {
    if (DEBUG) {
        os << v.label << " (" << &v << ")";
    } else {
        os << v.label;
    }
    return os;
}

Vertex* Edge::getSource() const {
    return source;
}

Vertex* Edge::getDestination() const {
    return destination;
}

Edge::Edge(std::string label1, std::string label2, int w) {
    source = new Vertex{label1};
    destination = new Vertex{label2};
    weight = w;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int w) {
    weight = w;
}

std::ostream& operator<<(std::ostream& os, const Edge& e) {
    if (DEBUG) {
        os << *e.source << " -- " << e.weight << " -- " << *e.destination << " (" << &e << ")";
    } else {
        os << *e.source << " -- " << e.weight << " -- " << *e.destination;
    }
    return os;
}

Vertex* Graph::addVertex(Vertex* v) {
    for (Vertex* vertex : vertices) {
        if (vertex == v) {
            return vertex;
        }
    }
    vertices.push_back(v);
    Gc::ajoutePointeur(v,'V');
    return v;
}

Vertex* Graph::addVertex(std::string label) {
    Vertex* v = new Vertex{label};
    vertices.push_back(v);
    Gc::ajoutePointeur(v,'V');
    return v;
}

Edge* Graph::addEdge(Edge* e) {
    for (Edge* edge : edges) {
        if (edge == e) {
            return edge;
        }
    }
    edges.push_back(e);
    Gc::ajoutePointeur(e,'E');
    addVertex(e->getSource());
    addVertex(e->getDestination());
    return e;
}

Edge* Graph::addEdge(Vertex* v1, Vertex* v2, int w) {
    for (Edge* edge : edges) {
        if (edge->getSource() == v1 && edge->getDestination() == v2 && edge->getWeight() == w) {
            return edge;
        }
    }
    Edge* e = new Edge{v1, v2, w};
    addEdge(e);
    return e;
}

Edge* Graph::addEdge(std::string label1, std::string label2, int w) {
    Vertex* v1 = addVertex(label1);
    Vertex* v2 = addVertex(label2);
    return addEdge(v1, v2, w);
}

int Graph::weight() const {
    int w = 0;
    for (Edge* e : edges) {
        w += e->getWeight();
    }
    return w;
}

void Graph::symetrize() {
    std::vector<Edge*> newEdges;
    for (Edge* e : edges) {
        newEdges.push_back(e);
        newEdges.push_back(new Edge{e->getDestination(), e->getSource(), e->getWeight()});
    }
    edges = newEdges;
}

std::ostream& operator<<(std::ostream& os, const Graph& g) {
    os << "Vertices:" << std::endl;
    for (Vertex* v : g.vertices) {
        os << *v << std::endl;
    }
    os << "Edges:" << std::endl;
    for (Edge* e : g.edges) {
        os << *e << std::endl;
    }
    return os;
}

Graph::~Graph(){
    for (Vertex* vertex : vertices) {
        Gc::tryDeleteV(vertex);

    }
    for (Edge* edge : edges){
        Gc::tryDeleteE(edge);
    }
}