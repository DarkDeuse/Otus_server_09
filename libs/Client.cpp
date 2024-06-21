#include "Client.h"

ClientSession::ClientSession(assyncedLib& _assync, size_t bulk_size, ip::tcp::socket sock) : 
    m_assync{_assync}, m_bulkSize{bulk_size}, m_sock{std::move(sock)}{}

void ClientSession::start()
{
    m_handle = m_assync.connect(m_bulkSize);
    m_self = shared_from_this();
    handle_read();
}

void ClientSession::handle_read()
{
    auto interpreter = [this](const boost::system::error_code& ec, 
                            std::size_t len){
        if (!ec){
            m_assync.receive(m_handle, m_buf.data(), buf_len);
            handle_read();
        }
        else{
            m_assync.disconnect(m_handle);
            m_sock.close();
            m_self.reset();
        }
    };
    m_sock.async_read_some(buffer(m_buf),interpreter );
}