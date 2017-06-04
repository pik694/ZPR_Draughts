//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP
#define ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP

/*!
 * @file
 * @brief Class representing a signal sent from server to the client, when a game ends.
 * Derives from Signal class
 */

#include "Signal.hpp"
#include "SignalFactory.hpp"

/*!
 * @brief Class representing a signal sent from server to the client, when a game ends.
 * Derives from Signal class
 */
class GameEndSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    GameEndSignal() : won_(false) {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     * @param won whether receiver won or lost
     */
    GameEndSignal(ConnectionProtocolHandler *hdl, bool won) : Signal(hdl), won_(won) {}

    /*!
     * @brief Changes an object into Json::Value
     * @return Json::Value of this object
     */
    virtual Json::Value serialize();

    /*!
     *
     * @return true if receiver won
     */
    const bool getWon() const {
        return won_;
    }

    /*!
     * @brief Reimplemented virtual method from Signal
     * Implemented according to the instructions given in @link Signal::acceptDispatcher @endlink documentation.
     */
    virtual void acceptDispatcher(MessageDispatcher &);


private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<GameEndSignal> reg;

    const bool won_;

};


#endif //ZPR_DRAUGHTS_GAMEENDSIGNAL_HPP
