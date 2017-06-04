//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
#define ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP

/*!
 * @file
 * @brief Class representing a leave room request.
 * Derives from Signal class
 */

#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Class representing a leave room request.
 * Derives from Signal class
 */
class LeaveRoomSignal : public Signal {

public:
    /*!
     * @brief Constructor used by SignalFactory
     */
    LeaveRoomSignal() {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     */
    LeaveRoomSignal(ConnectionProtocolHandler *hdl) : Signal(hdl) {}

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
    static Register<LeaveRoomSignal> reg;
};


#endif //ZPR_DRAUGHTS_LEAVEROOMSIGNAL_HPP
