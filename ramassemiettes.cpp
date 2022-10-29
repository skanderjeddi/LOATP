#include "ramassemiettes.hpp"

std::map<void*, int> RamasseMiettes::pointeurs = {};

void RamasseMiettes::suisPointeur(void* p) {
    std::cout << "+" << p << "...";
    auto ptr = pointeurs.find(p);
    if (ptr != pointeurs.end()) {
        pointeurs[p]++;
    } else {
        pointeurs[p] = 1;
    }      
    std::cout << " OK" << std::endl;
}

void RamasseMiettes::affiche(){
    for (auto it = RamasseMiettes::pointeurs.begin(); it != RamasseMiettes::pointeurs.end(); ++it) std::cout << "=" << it->first << " " << it->second << std::endl;
}

void RamasseMiettes::supprimePointeur(void* p){
    auto ptr = pointeurs.find(p);
    if (ptr != pointeurs.end()) {
        pointeurs[p] -= 1;
        if (pointeurs[p] == 0) {
            if (DEBUG) std::cout << "-" << p << "...";
            delete(p);
            pointeurs.erase(p);
            std::cout << " OK" << std::endl;
        }
    }
}