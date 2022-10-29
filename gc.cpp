#include "gc.hpp"
std::map<void*, int> Gc::Vpointeurs ={};
std::map<void*, int> Gc::Epointeurs ={};
  void Gc::ajoutePointeur(void* p, char c) {
      
    if (c=='V'){
        
        auto it = Vpointeurs.find(p);
        if (it!=Vpointeurs.end()){
            Vpointeurs[p]+=1;
        }
        else {
            void* p1;
            p1 = p;
            Vpointeurs[p1] = 1;
        }
    }
    else if (c=='E'){
        auto it = Epointeurs.find(p);
        if (it!=Epointeurs.end()){
            Epointeurs[p]+=1;
        }
        else {
            void* p1;
            p1 = p;
            Epointeurs[p1] = 1;
        }

    }

}
void Gc::affiche(){
    for (auto it = Gc::Vpointeurs.begin(); it !=Gc::Vpointeurs.end();++it){

    
    std::cout<< it->first<<","<< it->second << std::endl;
    }
     for (auto it = Gc::Epointeurs.begin(); it !=Gc::Epointeurs.end();++it){

    
    std::cout<< it->first<<","<< it->second << std::endl;
    }
}
void Gc::tryDeleteV(void* p){
    auto it = Vpointeurs.find(p);
        if (it!=Vpointeurs.end()){
            Vpointeurs[p]-=1;
            if (Vpointeurs[p]==0){
                std::cout<< "suppression de "<<p<<std::endl;
                
                delete(p);
                Epointeurs.erase(p);
            }
        }
        
            //mettre un else? gerer l'erreur? jsp comment on fait.
        
}
void Gc::tryDeleteE(void* p){
    auto it = Epointeurs.find(p);
        if (it!=Epointeurs.end()){
            Epointeurs[p]-=1;
            if (Epointeurs[p]==0){
                std::cout<< "suppression de "<<p<<std::endl;
                delete(p);
                Epointeurs.erase(p);
            }
        }
        
            //mettre un else? gerer l'erreur? jsp comment on fait.
        
}