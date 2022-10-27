#include "graphe.hpp"

std::string Sommet::getEtiquette() const {
    return etiquette;
}

std::ostream& operator<<(std::ostream& os, const Sommet& s) {
    os << s.etiquette << " (" << &s << ")";
    return os;
}

const Sommet* Arete::getSommet1() const {
    return sommet1;
}

const Sommet* Arete::getSommet2() const {
    return sommet2;
}

Arete::Arete(std::string etiquette1, std::string etiquette2, int poids) {
    sommet1 = new Sommet{etiquette1};
    sommet2 = new Sommet{etiquette2};
    this->poids = poids;
}

int Arete::getPoids() const {
    return poids;
}

void Arete::setPoids(int p) {
    poids = p;
}

std::ostream& operator<<(std::ostream& os, const Arete& a) {
    os << *a.sommet1 << " -- " << a.poids << " -- " << *a.sommet2 << " (" << &a << ")";
    return os;
}

Sommet* Graphe::ajouteSommet(Sommet* s) {
    sommets.push_back(s);
    return s;
}

Sommet* Graphe::ajouteSommet(std::string etiquette) {
    Sommet* s = new Sommet{etiquette};
    sommets.push_back(s);
    return s;
}

Arete* Graphe::ajouteArete(Arete* a) {
    aretes.push_back(a);
    if (std::find(sommets.begin(), sommets.end(), a->getSommet1()) == sommets.end()) {
        sommets.push_back(a->getSommet1());
    }
    if (std::find(sommets.begin(), sommets.end(), a->getSommet2()) == sommets.end()) {
        sommets.push_back(a->getSommet2());
    }
    return a;
}

Arete* Graphe::ajouteArete(const Sommet* s1, const Sommet* s2, int p) {
    Arete* a = new Arete{s1, s2, p};
    aretes.push_back(a);
    if (std::find(sommets.begin(), sommets.end(), s1) == sommets.end()) {
        sommets.push_back(s1);
    }
    if (std::find(sommets.begin(), sommets.end(), s2) == sommets.end()) {
        sommets.push_back(s2);
    }
    return a;
}

Arete* Graphe::ajouteArete(std::string e1, std::string e2, int p) {
    Sommet* s1 = new Sommet{e1};
    sommets.push_back(s1);
    Sommet* s2 = new Sommet{e2};
    sommets.push_back(s2);
    Arete* a = new Arete{s1, s2, p};
    aretes.push_back(a);
    return a;
}

int Graphe::poids() const {
    int p = 0;
    for (const Arete* a : aretes) {
        p += a->getPoids();
    }
    return p;
}

void Graphe::symetrise() {
    std::vector<Arete*> aretes2;
    for (Arete* a : aretes) {
        aretes2.push_back(a);
        Arete* a2 = new Arete{a->getSommet2(), a->getSommet1(), a->getPoids()};
        aretes2.push_back(a2);
    }
    aretes = aretes2;
}

std::ostream &operator<<(std::ostream& os, const Graphe& g) {
    int poids = g.poids();
    os << "Poids du graphe: " << poids << std::endl;
    os << "Sommets: " << std::endl;
    for (const Sommet* s : g.sommets) {
        os << *s << std::endl;
    }
    os << "Aretes: " << std::endl;
    for (Arete* a : g.aretes) {
        os << *a << std::endl;
    }
    return os;
}