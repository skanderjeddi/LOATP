#ifndef __COLLECTE_HPP__
#define __COLLECTE_HPP__

#include "common.hpp"

class Collecte {
    private:
        Collecte() {}
        std::vector<void*> pointeurs;

    public:
        static Collecte& instance() {
            static Collecte singleton;
            return singleton;
        }
        void ajoutePointeur(void* p);
        ~Collecte();
};

#endif