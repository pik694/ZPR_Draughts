#ifndef SERVER_HPP
#define SERVER_HPP

/*!
 * @file
 * @brief Class representing server, it starts throught run() function
 */ 


#include <list>
#include <map>
#include <set>

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/connection.hpp>
#include <boost/asio/signal_set.hpp>

#include "Signals/Signal.hpp"
#include "Action.hpp"


class ConnectionProtocolHandler;

class Player;

using websocketpp::connection_hdl;
using websocketpp::lib::mutex;
using websocketpp::lib::condition_variable;
typedef websocketpp::server<websocketpp::config::asio> server;
typedef server::message_ptr message_ptr;



class ConnectionProtocolHandler;

/*!
 * @brief Class representing server, it starts throught run() function
 */ 
class Server {
public:


    /*! @static
     * @brief Method through which one can access the only instance of the Server class.
     * return valid pointer to the instance of Server class.
     */

    static Server *getInstance() {
        if (instance_ == nullptr) {
            instance_ = new Server();
        }

        return instance_;
    }

    ~Server();


     /*!
     * @brief Method through which one can run server
     * @param port which server will run on
     */
    void run(int port);


    /*!
     * @brief Method through which one can put messages in output queue
     * @param message to put in output queue
     */
    void putMessageInQueue(std::shared_ptr<Signal>);

    Server(const Server &) = delete;

private:

    static Server *instance_;

    Server();

    void stopServer();

     
    void onOpen(connection_hdl hdl);

    void onClose(connection_hdl hdl);

    void processMessages();
    websocketpp::server<websocketpp::config::asio> webSocketServer_;
    typedef std::set<connection_hdl, std::owner_less<connection_hdl> > con_list;

    con_list m_connections;

    std::vector<ConnectionProtocolHandler*> connections_;
    //std::queue<Action> m_actions;

    mutex m_connection_lock;
    mutex m_action_lock;
    condition_variable m_action_cond;
    std::queue<Action> m_actions;


};

#endif //SERVER_HPP