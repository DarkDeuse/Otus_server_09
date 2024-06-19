#include "asyncedLib.h"

assyncedLib::assyncedLib() : m_counter{0} {}

uint64_t assyncedLib::connect(size_t& size)  {
    
    std::shared_ptr<interpreter> inter1 = std::make_shared<interpreter>(size);

    inter1->addPrinter(std::make_shared<ConsolePrinter>());
    inter1->addPrinter(std::make_shared<FilePrinter>(3));
    inter1->StartTread();
    m_inters.emplace(++m_counter, inter1);
    return m_counter;
}

void assyncedLib::receive(uint64_t& id,  const char * buff, size_t size) {
    auto toInsert = m_inters.find(id);
    if (toInsert != m_inters.end())
        toInsert->second->putString(std::string(buff, size));
}

void assyncedLib::disconnect(uint64_t& id) {
    auto toDel = m_inters.find(id);
    if (toDel != m_inters.end())
        m_inters.erase(toDel); 
}
