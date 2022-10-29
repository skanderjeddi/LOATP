
#include "common.hpp"

class Gc {
    public:
        static std::map<void*, int> Vpointeurs;
        static std::map<void*, int>Epointeurs;
    
       static void ajoutePointeur(void* p, char c);
       static void affiche();
       static void tryDeleteE(void* p);
        static void tryDeleteV(void* p);
};
