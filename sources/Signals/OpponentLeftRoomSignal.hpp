//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP

/*!
 * @file
 * @brief Signal sent when a client leaves a room to his opponent.
 * Derives from Signal class
 */

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"

/*!
 * @brief Signal sent when a client leaves a room to his opponent.
 * Derives from Signal class
 */
class OpponentLeftRoomSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    OpponentLeftRoomSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     */
    OpponentLeftRoomSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

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

private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<OpponentLeftRoomSignal> reg;
};


#endif //ZPR_DRAUGHTS_OPPONENTLEFTROOMSIGNAL_HPP
