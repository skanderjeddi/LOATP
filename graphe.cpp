#include "graphe.hpp"
#include "ramassemiettes.hpp"

std::string Sommet::recupereEtiquette() const {
    return etiquette;
}

std::ostream& operator<<(std::ostream& os, const Sommet& s) {
    if (DEBUG) os << s.etiquette << " [" << &s << "]";
    else os << s.etiquette;
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
    if (DEBUG) os << a.source->recupereEtiquette() << " -- " << a.poids << " -- " << a.destination->recupereEtiquette() << " [" << &a << "]";
    else os << *a.source << " -- " << a.poids << " -- " << *a.destination;
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
        if (sommet == s) return sommet;
    }
    sommets.push_back(s);
    RamasseMiettes::suisPointeur(s, false);
    return s;
}

Sommet* Graphe::ajouteSommet(std::string etiquette) {
    Sommet* s = new Sommet{etiquette};
    sommets.push_back(s);
    RamasseMiettes::suisPointeur(s, false);
    return s;
}

Arete* Graphe::ajouteArete(Arete* a) {
    for (Arete* arete : aretes) {
        if (a->source == arete->source && a->destination == arete->destination && a->poids == arete->poids) return a;
    }
    aretes.push_back(a);
    RamasseMiettes::suisPointeur(a, true);
    ajouteSommet(a->source);
    ajouteSommet(a->destination);
    return a;
}

Arete* Graphe::ajouteArete(Sommet* source, Sommet* destination, int p) {
    for (Arete* a : aretes) {
        if (a->source == source && a->destination == destination && a->poids == p) return a;
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
    std::vector<Arete*> aretessym;
    for (Arete* a : aretes) {
        aretessym.push_back(new Arete{a->destination, a->source, a->poids});
    }
    for (Arete* asym : aretessym) {
        ajouteArete(asym);
    }
}

std::vector<Sommet*> Graphe::recupereSommets() const {
    return sommets;
}

std::vector<Arete*> Graphe::recupereAretes() const {
    return aretes;
}

Graphe* Graphe::kruskal() const {
    Graphe* acm = new Graphe{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
    Graphe copie = Graphe{*this};
    copie.symetrise();
    int i = 1;
    for (Sommet *s : copie.sommets) {
        s->kruskal = i;
        i++;
    }
    auto comparator = [](Arete* a, Arete* b) {
        return a->recuperePoids() < b->recuperePoids();
    };
    std::sort(copie.aretes.begin(), copie.aretes.end(), comparator);
    for (Arete* a : copie.aretes) {
        Sommet* source = a->source;
        Sommet* destination = a->destination;
        if (source->kruskal != destination->kruskal) {
            if (std::find(acm->sommets.begin(), acm->sommets.end(), destination)!=acm->sommets.end()){
                source->kruskal= destination->kruskal;
            }
            else if (std::find(acm->sommets.begin(), acm->sommets.end(), source)!=acm->sommets.end()){
                destination->kruskal = source->kruskal;
            }
            acm->ajouteArete(a->source, a->destination, a->poids);
            for (Sommet* s : copie.sommets) {
                
                if (s->kruskal == source->kruskal || s->kruskal == destination->kruskal) {
                    
                    s->kruskal = source->kruskal;
                }
            }
        }
    }
    return acm;
}

std::ostream& operator<<(std::ostream& os, const Graphe& g) {
    os << "GRAPHE DE POIDS " << g.poids() << std::endl;
    os << "SOMMETS:" << std::endl;
    for (Sommet* v : g.sommets) {
        os << "\t" << *v << std::endl;
    }
    os << "ARETES:" << std::endl;
    for (Arete* e : g.aretes) {
        os << "\t" << *e << std::endl;
    }
    return os;
}

Graphe::~Graphe(){
    for (Sommet* s : sommets) {
        RamasseMiettes::supprimePointeur(s);
    }
    for (Arete* a : aretes) {
        RamasseMiettes::supprimePointeur(a);
    }
}