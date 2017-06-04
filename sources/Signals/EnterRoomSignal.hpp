//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP

/*!
 * @file
 * @brief Class representing an enter room request.
 * Derives from Signal class
 */

#include <string>

#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Class representing an enter room request.
 * Derives from Signal class
 */
class EnterRoomSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    EnterRoomSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     * @param roomID room
     */
    EnterRoomSignal(ConnectionProtocolHandler *hdl, int roomID) : Signal(hdl), roomID_(roomID) {}

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
     * @return Demanded room's ID
     */
    int getRoomID() const;


private:

    /*!
     * @static
     * @brief Used to register this type in SignalFactory
     */
    static Register<EnterRoomSignal> reg;

    int roomID_;
    
};


#endif //ZPR_DRAUGHTS_ENTERROOMSIGNAL_HPP
