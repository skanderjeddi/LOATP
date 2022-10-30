#ifndef __RAMASSE_MIETTES_HPP__
#define __RAMASSE_MIETTES_HPP__

#include "commun.hpp"

enum TypePointeur {
    SOMMET, ARETE
};

class RamasseMiettes {
    private:
        static std::map<void*, std::pair<int, TypePointeur>> pointeurs;
        RamasseMiettes() {}

    public:
        static void suisPointeur(void* p, TypePointeur type);
        static void affiche();
        static void supprimePointeur(void* p);
        ~RamasseMiettes();
};

#endif