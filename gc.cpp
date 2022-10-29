#include "gc.hpp"

std::map<void*, int> GC::pointers = {};

void GC::trackPointer(void* p) {
    auto ptr = pointers.find(p);
    if (ptr != pointers.end()) {
        pointers[p]++;
    } else {
        pointers[p] = 1;
    }      
}

void GC::display(){
    for (auto it = GC::pointers.begin(); it != GC::pointers.end(); ++it) std::cout << it->first <<", "<< it->second << std::endl;
}

void GC::deletePointer(void* p){
    auto ptr = pointers.find(p);
    if (ptr != pointers.end()){
        pointers[p] -= 1;
        if (pointers[p] == 0) {
            if (DEBUG) std::cout << "DELETING " << p << std::endl;
            delete(p);
            pointers.erase(p);
        }
    }    
}