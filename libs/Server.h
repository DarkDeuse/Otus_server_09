
#include <cstdlib>

#include <boost/asio.hpp>

#include "Client.h"

using namespace boost::asio;

class Server {

public:
    explicit Server(uint16_t port, size_t bulk_size);
    ~Server();
    void start();

private:
    void handle_accept();
    void handle_stop();

    assyncedLib         m_assync;
    io_service        m_service{};
    ip::tcp::acceptor m_acceptor;
    ip::tcp::socket   m_sock;
    size_t            m_bulkSize;   
};