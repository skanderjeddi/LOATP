#ifndef __COLLECTE_HPP__
#define __COLLECTE_HPP__

#include "common.hpp"

class GCArete {
    private:
        std::vector<Sommet*> pointeurs;

    public:
        void ajoutePointeur(void* p);
};

class GCGraphe {
    private:
        std::vector<Arete*> pointeurs;

    public:
        void ajoutePointeur(void* p);
};

#endif