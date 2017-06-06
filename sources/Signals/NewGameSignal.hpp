//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
#define ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP

/*!
 * @file
 * @brief Class representing new game request, sent by a client.
 * Derives from Signal class
 */


#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Class representing new game request, sent by a client.
 * Derives from Signal class
 */
class NewGameSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    NewGameSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     */
    NewGameSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

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
    static Register<NewGameSignal> reg;
};


#endif //ZPR_DRAUGHTS_NEWGAMESIGNAL_HPP
