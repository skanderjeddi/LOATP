#ifndef __GRAPHE_HPP__
#define __GRAPHE_HPP__

#include "commun.hpp"
#include "ramassemiettes.hpp"

class Sommet {
    private:
        Sommet() {}
        Sommet(std::string etiquette) : etiquette{etiquette} {};
        Sommet(const Sommet& copie) : etiquette{copie.etiquette} {};
        std::string etiquette;
        int kruskal;
        friend class Arete;
        friend class Graphe;

    public:
        std::string recupereEtiquette() const;
        friend std::ostream& operator<<(std::ostream& os, const Sommet& v);
};

class Arete {
    private:
        Sommet *source, *destination;
        Arete() {}
        Arete(std::string etiquette1, std::string etiquette2, int poids);
        Arete(Sommet* source, Sommet* destination, int poids) : source{source}, destination{destination}, poids{poids} {}
        Arete(const Arete& copie) : source{copie.source}, destination{copie.destination}, poids{copie.poids} {}
        int poids;
        friend class Graphe;

    public:
        Sommet* recupereSource() const;
        Sommet* recupereDestination() const;
        int recuperePoids() const;
        void changePoids(int p);
        friend std::ostream& operator<<(std::ostream& os, const Arete& a);
};

class Graphe {
    private:
        std::vector<Sommet*> sommets;
        std::vector<Arete*> aretes;
     
    public:
        Graphe(std::vector<Arete*> aretes, std::vector<Sommet*> sommets); /** : sommets{sommets}, aretes{aretes}{} **/
        Graphe(const Graphe& copie); /**  : sommets{copie.sommets}, aretes{copie.aretes} {} **/
        Sommet* ajouteSommet(Sommet* s);
        Sommet* ajouteSommet(std::string etiquette);
        Arete* ajouteArete(Arete* a);
        Arete* ajouteArete(Sommet* source, Sommet* destination, int poids);
        Arete* ajouteArete(std::string etiquette1, std::string etiquette2, int poids);
        int poids() const;
        void symetrise();
        std::vector<Sommet*> recupereSommets() const;
        std::vector<Arete*> recupereAretes() const;
        friend std::ostream& operator<<(std::ostream& os, const Graphe& g);
        Graphe& operator=(const Graphe& copie) {
            for (Arete* a : copie.aretes) {
                ajouteArete(a);
            }
            for (Sommet* s : copie.sommets) {
                ajouteSommet(s);
            }
            return *this;
        }
        ~Graphe();
};

#endif