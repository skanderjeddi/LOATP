#include "collecte.hpp"
#include "graphe.hpp"

void Collecte::ajoutePointeur(void* p) {
    pointeurs.push_back(p);
}

Collecte::~Collecte()  {
    for (void* p : pointeurs) {
        delete p;
    }
}