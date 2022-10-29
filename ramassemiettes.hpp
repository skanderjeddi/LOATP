#ifndef __RAMASSE_MIETTES_HPP__
#define __RAMASSE_MIETTES_HPP__

#include "commun.hpp"

class RamasseMiettes {
    private:
        static std::map<void*, int> pointeurs;
        RamasseMiettes() {}

    public:
        static void suisPointeur(void* p);
        static void affiche();
        static void supprimePointeur(void* p);
};

#endif