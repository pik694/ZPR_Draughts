#ifndef ZPR_DRAUGHTS_ACTION_HPP
#define ZPR_DRAUGHTS_ACTION_HPP
#include <websocketpp/config/asio_no_tls.hpp>

#include <websocketpp/server.hpp>
typedef websocketpp::server<websocketpp::config::asio> server;
using websocketpp::connection_hdl;
enum action_type {
    SUBSCRIBE,
    UNSUBSCRIBE,
    MESSAGE
};

struct Action {
    Action(action_type t, connection_hdl h) : type(t), hdl(h) {}
    Action(action_type t, connection_hdl h, server::message_ptr m)
      : type(t), hdl(h), msg(m) {}

    action_type type;
    websocketpp::connection_hdl hdl;
    server::message_ptr msg;
};

#endif