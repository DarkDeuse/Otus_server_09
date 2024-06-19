#include "ConsolePrinter.h"

ConsolePrinter::ConsolePrinter() : Printer(1)
{
    for (size_t i = 0; i < m_qthreads; ++i)
        m_threads.push_back(std::thread ( &ConsolePrinter::printThread, this, i ));
}

ConsolePrinter::~ConsolePrinter()
{
    for (auto &i : m_threads)
        if (i.joinable())
                i.join();
}

void ConsolePrinter::printThread(size_t threadNumber) {
    (void)(threadNumber);
    std::shared_ptr<Bulk> data;
    std::string separator;
    while(m_queue.pop(data)){
        separator = "";
        std::cout << "bulk: ";
        for (auto &str : data->bulk){
            std::cout << separator << str;
            separator = ",";
        }
        std::cout << std::endl;
    }
    
}