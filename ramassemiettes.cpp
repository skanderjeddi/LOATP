#include "ramassemiettes.hpp"
#include "graphe.hpp"

std::map<void*, std::pair<int, TypePointeur>> RamasseMiettes::pointeurs = {};

void RamasseMiettes::suisPointeur(void* p, TypePointeur type) {
    auto ptr = pointeurs.find(p);
    if (ptr != pointeurs.end()) pointeurs[p].first++;
    else pointeurs[p] = std::make_pair(1, type);  
    if (DEBUG) std::cout << "REG " << p << " [" << pointeurs[p].first << "]\n";
}

void RamasseMiettes::affiche() {
    for (auto it = RamasseMiettes::pointeurs.begin(); it != RamasseMiettes::pointeurs.end(); ++it) std::cout << "REF " << it->first << " " << it->second.first << std::endl;
}

void RamasseMiettes::supprimePointeur(void* p){
    auto ptr = pointeurs.find(p);
    if (ptr != pointeurs.end()) {
        pointeurs[p].first -= 1;
        if (pointeurs[p].first == 0) {
            switch (pointeurs[p].second) {
                case SOMMET: delete (Sommet*) p; break;
                case ARETE: delete (Arete*) p; break;
            }
            pointeurs.erase(p);
            if (DEBUG) std::cout << "DEL " << p << std::endl;
        }
    }
}