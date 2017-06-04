//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_TEXTMESSAGE_HPP
#define ZPR_DRAUGHTS_TEXTMESSAGE_HPP

/*!
 * @file
 * @brief Class representing text message sent between two clients.
 * Derives from Signal class
 */

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"

class Signal;

/*!
 * @brief Class representing text message sent between two clients.
 * Derives from Signal class.
 */
class TextMessage : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    TextMessage() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     * @param message
     */
    TextMessage(ConnectionProtocolHandler *hdl, std::string message) : Signal(hdl), message_(message) {}

    /*!
     * @brief Reimplemented virtual method from Signal
     * Implemented according to the instructions given in @link Signal::acceptDispatcher @endlink documentation.
     */
    virtual void acceptDispatcher(MessageDispatcher &);

    /*!
     * @brief parses Json::Value and sets its attributes according to the Json.
     * @param data
     */
    virtual void fillData(Json::Value data);

    /*!
     * @brief Changes an object into Json::Value
     * @return Json::Value of this object
     */
    virtual Json::Value serialize();

    /*!
     *
     * @return  sent text message
     */
    const std::string &getMessage() const;

private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<TextMessage> reg;

    std::string message_;

};


#endif //ZPR_DRAUGHTS_TEXTMESSAGE_HPP
