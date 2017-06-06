//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP

/*!
 * @file
 * @brief Class representing a nick request, sent by a client.
 * Server always replies to this signal - accepts nick if available.
 * Derives from Signal class
 */

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"

/*!
 * @brief Class representing a nick request, sent by a client.
 * Server always replies to this signal - accepts nick if available.
 * Derives from Signal class
 */

class NickRequestSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    NickRequestSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     */
    NickRequestSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

    /*!
     * @brief parses Json::Value and sets its attributes according to the Json.
     * @param data
     */
    virtual void fillData(Json::Value data);

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
     * @return requested nick
     */
    const std::string &getNick() const;


private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<NickRequestSignal> reg;

    std::string nick_;
};


#endif //ZPR_DRAUGHTS_NICKREQUESTSIGNAL_HPP
