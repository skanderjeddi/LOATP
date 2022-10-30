#include "commun.hpp"
#include "graphe.hpp"

bool DEBUG;

int main() {
    // Cette variable controle l'affichage des messages de debug (principalement les adresses des pointeurs)
    DEBUG = true;

    // On cree un graphe avec 3 sommets et 3 aretes qu'on affiche ensuite
    std::cout << "CREATION DE G1\n";
    if (DEBUG) std::cout << std::endl;
    Graphe graphe1{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
    Sommet* a0 = graphe1.ajouteSommet("A");
    Sommet* b0 = graphe1.ajouteSommet("B");
    Sommet* c0 = graphe1.ajouteSommet("C");
    Arete* a0b0 = graphe1.ajouteArete(a0, b0, 1);
    Arete* a0c0 = graphe1.ajouteArete(a0, c0, 2);
    Arete* d0e0 = graphe1.ajouteArete("D", "E", 3);
    graphe1.ajouteArete(b0, c0, 3);
    if (DEBUG) std::cout << std::endl;
    std::cout << "AFFICHAGE DE G1\n";
    std::cout << graphe1;

    std::cout << std::endl;

    // On cree un graphe dans un bloc temporaire qui a des sommets et aretes en commun avec le graphe precedent
    {
        std::cout << "CREATION DE G2\n";
        if (DEBUG) std::cout << std::endl;
        Graphe graphe2{ std::vector<Arete*> {
            a0b0,
            a0c0,
        }, std::vector<Sommet*> {
            a0,
            b0,
            c0,
        } };
        Sommet* x0 = graphe2.ajouteSommet("X");
        graphe2.ajouteArete(a0, x0, 4);
        graphe2.ajouteArete(x0, b0, 5);
        if (DEBUG) std::cout << std::endl;
        std::cout << "AFFICHAGE DE G2\n";
        std::cout << graphe2;
        if (DEBUG) { std::cout << std::endl; RamasseMiettes::affiche(); std::cout << std::endl; }
        std::cout << "SUPPRESSION DE G2\n";  
    }
    std::cout << std::endl;

    // On cree un graphe vide qu'on va assigner dans le bloc ci-dessous
    std::cout << "CREATION DE G3\n";
    std::cout << std::endl;
    Graphe graphe3 = Graphe{ std::vector<Arete*> {}, std::vector<Sommet*> {} };
    {
        // On cree un graphe temporaire dans le bloc pour tester l'operateur d'affectation
        std::cout << "CREATION DE G4\n";
        if (DEBUG) std::cout << std::endl;
        Graphe graphe4 = Graphe{ std::vector<Arete*> {}, std::vector<Sommet*> {} };
        graphe4.ajouteArete("Y", "W", 7);
        if (DEBUG) std::cout << std::endl;
        std::cout << "AFFICHAGE DE G4\n";
        std::cout << graphe4;

        std::cout << std::endl;

        // On assigne le graphe temporaire au le graphe vide
        std::cout << "ASSIGNATION DE G4 A G3\n";
        if (DEBUG) std::cout << std::endl;
        graphe3 = Graphe{ graphe4 };
        if (DEBUG) std::cout << std::endl;
        std::cout << "SUPPRESSION DE G4\n";
        std::cout << std::endl;
    }
    std::cout << "AFFICHAGE DE G3\n";
    std::cout << graphe3;

    std::cout << std::endl;

    // On symetrise le graphe
    std::cout << "SYMETRISATION DE G3\n";
    if (DEBUG) std::cout << std::endl;
    graphe3.symetrise();
    if (DEBUG) std::cout << std::endl;
    std::cout << "AFFICHAGE DE G3\n";
    std::cout << graphe3;
    
    std::cout << std::endl;

    if (DEBUG) { RamasseMiettes::affiche(); std::cout << std::endl; }

    // On cree un graphe a partir du graphe precedent
    std::cout << "CREATION DE G5 A PARTIR DE G3\n";
    if (DEBUG) std::cout << std::endl;
    Graphe graphe5 = Graphe{ graphe3 };
    // On ajoute une arete au graphe
    graphe5.ajouteArete(d0e0);
    // On ajoute un sommet isole au graphe
    graphe5.ajouteSommet(a0);
    if (DEBUG) std::cout << std::endl;
    std::cout << "AFFICHAGE DE G5\n";
    std::cout << graphe5;

    std::cout << std::endl;

    /**
     * Kruskal
    **/

    std::cout << "CREATION DE G(k)\n";
    if (DEBUG) std::cout << std::endl;
    Graphe grapheK{ std::vector<Arete*>{}, std::vector<Sommet*>{} };
    for (int i = 0; i < 4; i++) {
        grapheK.ajouteSommet(std::to_string(i));
    }
    std::vector<Sommet*> sommets = grapheK.recupereSommets();
    grapheK.ajouteArete(sommets[0], sommets[1], 10);
    grapheK.ajouteArete(sommets[1], sommets[3], 15);
    grapheK.ajouteArete(sommets[2], sommets[3], 4);
    grapheK.ajouteArete(sommets[2], sommets[0], 6);
    grapheK.ajouteArete(sommets[0], sommets[3], 5);
    if (DEBUG) std::cout << std::endl;
    std::cout << "AFFICHAGE DE G(k)\n";
    std::cout << grapheK;
    std::cout << std::endl;
    std::cout << "CALCUL D'UN ARBRE COUVRANT MINIMAL DE G(k)\n";
    if (DEBUG) std::cout << std::endl;
    Graphe* acm = grapheK.kruskal();
    if (DEBUG) std::cout << std::endl;
    std::cout << "ARBRE COUVRANT MINIMAL\n";
    std::cout << *acm;
    if (DEBUG) std::cout << std::endl;
    std::cout << "SUPPRESSION DE l'A.C.M.\n";
    delete acm;
    if (DEBUG) std::cout << std::endl << "FIN DU PROGRAMME, NETTOYAGE DES POINTEURS\n";
}