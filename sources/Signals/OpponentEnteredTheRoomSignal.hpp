//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP

/*!
 * @file
 * @brief Signal sent when a client enters a room to his opponent.
 * Derives from Signal class
 */

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Signal sent when a client enters a room to his opponent.
 * Derives from Signal class
 */
class OpponentEnteredTheRoomSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    OpponentEnteredTheRoomSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     * @param opponentNick opponent's, who's just entered, nick
     */
    OpponentEnteredTheRoomSignal(ConnectionProtocolHandler *hdl, std::string opponentNick) : Signal(hdl), opponentNick_(
            opponentNick) {}


    /*!
     * @brief Reimplemented virtual method from Signal
     * Implemented according to the instructions given in @link Signal::acceptDispatcher @endlink documentation.
     */
    virtual void acceptDispatcher(MessageDispatcher &);

    /*!
     * @brief Changes an object into Json::Value
     * @return Json::Value of this object
     */
    virtual Json::Value serialize();


    /*!
     *
     * @return oponent's nick
     */
    const std::string &getOpponentNick() const;

private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<OpponentEnteredTheRoomSignal> reg;

    std::string opponentNick_;
};


#endif //ZPR_DRAUGHTS_OPPONENTENTEREDTHEROOMSIGNAL_HPP
