#include "ramassemiettes.hpp"
#include "graphe.hpp"

std::map<void*, std::pair<int, bool>> RamasseMiettes::pointeurs = {};

void RamasseMiettes::suisPointeur(void* p, bool arete) {
    std::cout << "+" << p << "...";
    auto ptr = pointeurs.find(p);
    if (ptr != pointeurs.end()) {
        pointeurs[p].first++;
    } else {
        pointeurs[p].first = 1;
    }      
    std::cout << " OK" << std::endl;
}

void RamasseMiettes::affiche(){
    for (auto it = RamasseMiettes::pointeurs.begin(); it != RamasseMiettes::pointeurs.end(); ++it) std::cout << "=" << it->first << " " << it->second.first << std::endl;
}

void RamasseMiettes::supprimePointeur(void* p){
    auto ptr = pointeurs.find(p);
    if (ptr != pointeurs.end()) {
        pointeurs[p].first -= 1;
        if (pointeurs[p].first == 0) {
            if (DEBUG) std::cout << "-" << p << "...";
            if (pointeurs[p].second) {
                free(static_cast<Sommet*>(p));   
            } else {
                free(static_cast<Arete*>(p));
            }
            pointeurs.erase(p);
            std::cout << " OK" << std::endl;
        }
    }
}