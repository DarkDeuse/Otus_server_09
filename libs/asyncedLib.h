# pragma once
#include <cstdint>
#include <cstdio>
#include <map>
#include <memory>
#include "lib_interpretor.h"

class assyncedLib
{
    public:
        assyncedLib();
        uint64_t connect(size_t&);
        void receive(uint64_t&,  const char *, size_t);
        void disconnect(uint64_t&);

    private:
        std::map<uint64_t, std::shared_ptr<interpreter> > m_inters;
        uint64_t m_counter;
};