#include <cstdlib>

#include <boost/asio.hpp>

#include "asyncedLib.h"

using namespace boost::asio;


class ClientSession : public std::enable_shared_from_this<ClientSession> {
    public:
        explicit ClientSession(assyncLib&, size_t, ip::tcp::socket);
        ~ClientSession() = default;
        void start();
    
    private:
        void handle_read();

        static constexpr size_t buf_len = 1024;
        assyncLib&                  m_assync;
        std::array<char, buf_len>   m_buf;
        ip::tcp::socket             m_sock;
        uint64_t                    m_handle{};
        std::shared_ptr<ClientSession>     m_self;
        size_t                      m_bulkSize;
        
};