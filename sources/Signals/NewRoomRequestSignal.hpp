//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP

/*!
 * @file
 * @brief Class representing a new room request, sent by a client.
 * Derives from Signal class
 */

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"

/*!
 * @brief Class representing a new room request, sent by a client.
 * Derives from Signal class
 */
class NewRoomRequestSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    NewRoomRequestSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     * @param roomID
     */
    NewRoomRequestSignal(ConnectionProtocolHandler *hdl, std::string roomID) : Signal(hdl) {}

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
     * @brief parses Json::Value and sets its attributes according to the Json.
     * @param data
     */
    virtual void fillData(Json::Value data);

private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<NewRoomRequestSignal> reg;
};


#endif //ZPR_DRAUGHTS_NEWROOMREQUESTSIGNAL_HPP
