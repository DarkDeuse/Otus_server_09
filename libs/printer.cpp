#include "printer.h"

Printer::Printer(size_t size ): m_qthreads{size}{};

Printer::~Printer(){}

void Printer::setEOF() { 
    m_queue.setEOF(); 
}

void Printer::print(std::shared_ptr<Bulk> data){
    m_queue.push(data);
}
