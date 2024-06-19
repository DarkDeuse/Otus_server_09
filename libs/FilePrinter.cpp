#include "FilePrinter.h"

FilePrinter::FilePrinter(size_t size): Printer(size)
{
    for (size_t i = 0; i < m_qthreads; ++i)
        m_threads.push_back(std::thread ( &FilePrinter::printThread, this, i ));
}

FilePrinter::~FilePrinter()
{
    for (auto &i : m_threads)
        if (i.joinable())
                i.join();
}

void FilePrinter::printThread(size_t threadNumber){
    
    std::shared_ptr<Bulk> data;
    std::string separator;
    size_t counter{0};
    std::ofstream m_ofstream;

    while(m_queue.pop(data)){
        m_ofstream.open(data->time + "_thread_" + std::to_string(threadNumber) + "_" + std::to_string(++counter) +".log");
        separator = "";
        m_ofstream << "\nbulk: ";
        for (auto &str : data->bulk){
            m_ofstream << separator << str << std::endl;
            separator = ",";
        }

        m_ofstream.close();
    }
}