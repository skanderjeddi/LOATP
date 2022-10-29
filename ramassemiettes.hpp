#ifndef __RAMASSE_MIETTES_HPP__
#define __RAMASSE_MIETTES_HPP__

#include "commun.hpp"

class RamasseMiettes {
    private:
        static std::map<void*, std::pair<int, bool>> pointeurs;
        RamasseMiettes() {}

    public:
        static void suisPointeur(void* p, bool type);
        static void affiche();
        static void supprimePointeur(void* p);
};

#endif