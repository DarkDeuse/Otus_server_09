#pragma once

#include <fstream>
#include "printer.h"

class FilePrinter : public  Printer
{
    public:
        FilePrinter(size_t size);
        ~FilePrinter();
        void printThread(size_t threadNumber) override;
        
};
