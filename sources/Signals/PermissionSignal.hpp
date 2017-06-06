//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
#define ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP

/*!
 * @file
 * @brief Signal is sent as an reply to client's request. Accepts or denies actions demanded by the client.
 * Derives from Signal class
 */

#include <string>
#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Signal is sent as an reply to client's request. Accepts or denies actions demanded by the client.
 * Derives from Signal class
 */
class PermissionSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    PermissionSignal() : givenPermission_(false) {}

    /*!
     * @brief Default constructor.
     * @param hdl receiver
     * @param givenPermission whether the action has been accepted
     * @param action //TODO: Michal
     */
    PermissionSignal(ConnectionProtocolHandler *hdl, bool givenPermission,std::string action=""):
            Signal(hdl),
            givenPermission_(givenPermission),
            action_(action) {}


    /*!
     * @brief Reimplemented virtual method from Signal
     * Implemented according to the instructions given in @link Signal::acceptDispatcher @endlink documentation.
     */
    virtual void acceptDispatcher(MessageDispatcher &);

    /*!
     * @brief parses Json::Value and sets its attributes according to the Json.
     * @param data
     */
    virtual void fillData(Json::Value data){};

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
    static Register<PermissionSignal> reg;

    const bool givenPermission_;
    std::string action_;

};


#endif //ZPR_DRAUGHTS_PERMISSIONSIGNAL_HPP
