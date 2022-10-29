#include "graphe.hpp"
#include "ramassemiettes.hpp"

std::string Sommet::recupereEtiquette() const {
    return etiquette;
}

std::ostream& operator<<(std::ostream& os, const Sommet& s) {
    if (DEBUG) {
        os << s.etiquette << " [" << &s << "]";
    } else {
        os << s.etiquette;
    }
    return os;
}

Sommet* Arete::recupereSource() const {
    return source;
}

Sommet* Arete::recupereDestination() const {
    return destination;
}

Arete::Arete(std::string etiquette1, std::string etiquette2, int p) {
    source = new Sommet{etiquette1};
    destination = new Sommet{etiquette2};
    poids = p;
}

int Arete::recuperePoids() const {
    return poids;
}

void Arete::changePoids(int p) {
    poids = p;
}

std::ostream& operator<<(std::ostream& os, const Arete& a) {
    if (DEBUG) {
        os << a.source->recupereEtiquette() << " -- " << a.poids << " -- " << a.destination->recupereEtiquette() << " [" << &a << "]";
    } else {
        os << *a.source << " -- " << a.poids << " -- " << *a.destination;
    }
    return os;
}

Graphe::Graphe(std::vector<Arete*> aretes, std::vector<Sommet*> sommets) {
    for (Arete* a : aretes) {
        ajouteArete(a);
    }
    for (Sommet* s : sommets) {
        ajouteSommet(s);
    }
}

Graphe::Graphe(const Graphe& copie) {
    for (Arete* a : copie.aretes) {
        ajouteArete(a);
    }
    for (Sommet* s : copie.sommets) {
        ajouteSommet(s);
    }
}

Sommet* Graphe::ajouteSommet(Sommet* s) {
    for (Sommet* sommet : sommets) {
        if (sommet == s) {
            return sommet;
        }
    }
    sommets.push_back(s);
    RamasseMiettes::suisPointeur(s);
    return s;
}

Sommet* Graphe::ajouteSommet(std::string etiquette) {
    Sommet* s = new Sommet{etiquette};
    sommets.push_back(s);
    RamasseMiettes::suisPointeur(s);
    return s;
}

Arete* Graphe::ajouteArete(Arete* a) {
    for (Arete* arete : aretes) {
        if (arete == a) {
            return arete;
        }
    }
    aretes.push_back(a);
    RamasseMiettes::suisPointeur(a);
    ajouteSommet(a->recupereSource());
    ajouteSommet(a->recupereDestination());
    return a;
}

Arete* Graphe::ajouteArete(Sommet* source, Sommet* destination, int p) {
    for (Arete* a : aretes) {
        if (a->recupereSource() == source && a->recupereDestination() == destination && a->recuperePoids() == p) {
            return a;
        }
    }
    Arete* a = new Arete{source, destination, p};
    ajouteArete(a);
    return a;
}

Arete* Graphe::ajouteArete(std::string etiquette1, std::string etiquette2, int p) {
    Sommet* source = ajouteSommet(etiquette1);
    Sommet* destination = ajouteSommet(etiquette2);
    return ajouteArete(source, destination, p);
}

int Graphe::poids() const {
    int p = 0;
    for (Arete* a : aretes) {
        p += a->recuperePoids();
    }
    return p;
}

void Graphe::symetrise() {
    for (Arete* a : aretes) {
        Arete* asym = new Arete{a->recupereDestination(), a->recupereSource(), a->recuperePoids()};
        ajouteArete(asym);
    }
}

std::ostream& operator<<(std::ostream& os, const Graphe& g) {
    os << std::endl;
    os << "GRAPHE DE POIDS " << g.poids() << std::endl;
    os << "SOMMETS:" << std::endl;
    for (Sommet* v : g.sommets) {
        os << "\t" << *v << std::endl;
    }
    os << "ARETES:" << std::endl;
    for (Arete* e : g.aretes) {
        os << "\t" << *e << std::endl;
    }
    os << std::endl;
    return os;
}

Graphe::~Graphe(){
    for (Sommet* s : sommets) {
        RamasseMiettes::supprimePointeur(s);
    }
    for (Arete* a : aretes){
        RamasseMiettes::supprimePointeur(a);
    }
}