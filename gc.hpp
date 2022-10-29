#ifndef __GC_HPP__
#define __GC_HPP__

#include "common.hpp"

class GC {
    private:
        static std::map<void*, int> pointers;
        GC() {}

    public:
        static void trackPointer(void* p);
        static void display();
        static void deletePointer(void* p);
};

#endif