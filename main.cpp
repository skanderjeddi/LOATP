#include "graphe.hpp"
#include "common.hpp"

bool DEBUG;

int main() {
    DEBUG = true;
    Graphe g1{ std::vector<Arete*>{}, std::vector<const Sommet*>{} };
    Sommet* a = g1.ajouteSommet("A");
    Sommet* b = g1.ajouteSommet("B");
    Sommet c{"C"};
    g1.ajouteSommet(&c);
    Sommet e{"E"};
    Sommet* ap = g1.ajouteSommet("A'");
    g1.ajouteArete(a, b, 1);
    g1.ajouteArete(a, &c, 2);
    g1.ajouteArete(b, &e, 3);
    Arete a1{"F", "G", 4};
    Arete a2{a, &e, 5};
    g1.ajouteArete(&a1);
    g1.ajouteArete(&a2);
    g1.symetrise();
    std::cout << g1;
    Graphe g2{ std::vector<Arete*>{}, std::vector<const Sommet*>{} };
    g2.ajouteArete(&a1);
    g2.ajouteArete(new Arete{ap, &e, -2});
    std::cout << g2;
    return 0;
}