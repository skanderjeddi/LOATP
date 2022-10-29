#include "commun.hpp"
#include "graphe.hpp"

bool DEBUG;

int main() {
    DEBUG = true;
    Graphe graphe1{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
    Sommet* a0 = graphe1.ajouteSommet("A");
    Sommet* b0 = graphe1.ajouteSommet("B");
    Sommet* c = graphe1.ajouteSommet("C");
    Sommet* e = graphe1.ajouteSommet("E");
    graphe1.ajouteArete(a0, b0, 1);
    graphe1.ajouteArete(a0, b0, 2);
    graphe1.ajouteArete(a0, c, 1);
    graphe1.ajouteArete(c, e, 3);
    Arete* fg = graphe1.ajouteArete("F", "G", 4);  
    Arete* a0b0 = graphe1.ajouteArete(a0, b0, 1);
    {
        Graphe graphe2{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
        graphe2.ajouteArete(a0b0);
        graphe2.ajouteArete(a0, b0, 2);
        graphe2.ajouteSommet(c);
        graphe2.ajouteSommet("X");
        graphe2.ajouteArete(fg);
        std::cout << graphe2;
        if (DEBUG) RamasseMiettes::affiche();           
    }
    Graphe graphe3 = Graphe{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
    {
        Graphe graphe4 = Graphe{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
        graphe4.ajouteArete("Y", "W", 7);
        std::cout << graphe4;
        graphe3 = Graphe{ graphe4 };
        std::cout << graphe3;
    }
    graphe1.symetrise();
    std::cout << graphe1;
    if (DEBUG) RamasseMiettes::affiche();
    std::cout << graphe3;
    if (DEBUG) RamasseMiettes::affiche();
}