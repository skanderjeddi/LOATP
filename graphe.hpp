#ifndef __GRAPHE_HPP__
#define __GRAPHE_HPP__

#include "common.hpp"
#include "collecte.hpp"

class Sommet {
    private:
        std::string etiquette;
        int kruskal;

    public:
        Sommet(std::string etiquette) : etiquette{etiquette} {}
        Sommet(const Sommet& s) : etiquette{s.etiquette} {}
        std::string getEtiquette() const;
        void* operator new(size_t size) {
            void * p = ::operator new(size);
            Collecte::instance().ajoutePointeur(p);
            return p;
        }
        friend std::ostream& operator<<(std::ostream& os, const Sommet& s);
};

class Arete {
    private:
        const Sommet *sommet1, *sommet2;
        int poids;
    
    public:
        Arete(std::string etiquette1, std::string etiquette2, int poids);
        Arete(const Sommet* s1, const Sommet* s2, int poids) : sommet1{s1}, sommet2{s2}, poids{poids} {}
        Arete(const Arete& a) : sommet1{a.sommet1}, sommet2{a.sommet2}, poids{a.poids} {}
        const Sommet* getSommet1() const;
        const Sommet* getSommet2() const;
        int getPoids() const;
        void setPoids(int p);
        void* operator new(size_t size) {
            void * p = ::operator new(size);
            Collecte::instance().ajoutePointeur(p);
            return p;
        }
        friend std::ostream& operator<<(std::ostream& os, const Arete& a);
};

class Graphe {
    private:
        std::vector<const Sommet*> sommets;
        std::vector<Arete*> aretes;

    public:
        Graphe(std::vector<Arete*> aretes, std::vector<const Sommet*> sommets) : sommets{sommets}, aretes{aretes} {}
        Graphe(const Graphe& g) : sommets{g.sommets}, aretes{g.aretes} {}
        Sommet* ajouteSommet(Sommet* s);
        Sommet* ajouteSommet(std::string etiquette);
        Arete* ajouteArete(Arete* a);
        Arete* ajouteArete(const Sommet* s1, const Sommet* s2, int p);
        Arete* ajouteArete(std::string etiquette1, std::string etiquette2, int p);
        int poids() const;
        void symetrise();
        std::vector<const Sommet*> getSommets() const;
        std::vector<Arete*> getAretes() const;
        friend std::ostream& operator<<(std::ostream& os, const Graphe& g);
};

#endif