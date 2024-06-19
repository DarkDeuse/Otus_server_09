#include <stdlib.h>

#include "../libs/asyncedLib.h"
#include "../libs/Server.h"

int main(int argc, char const *argv[]){


  if(argc != 3) {
    std::cerr << "Wrong number of arguments (expected 2). Usage: bulk_server <port> <bulk_size>. \n" << std::endl;
    return EXIT_FAILURE;
  }

  auto port = std::strtoll(argv[1], nullptr, 0);
  if((port <= 0) || (port > 65535)) {
    std::cerr << "Port must be an integer between 0 and 65535.\n";
    return EXIT_FAILURE;
  }

  auto bulk_size = std::strtoll(argv[2], nullptr, 0);
  if(bulk_size <= 0) {
    std::cerr << "Bulk size must be integer greater than 0.\n";
    return EXIT_FAILURE;
  }

    try {
        Server bulk_server{static_cast<uint16_t>(port), static_cast<size_t>(bulk_size)};
        bulk_server.start();
    } 
        catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
