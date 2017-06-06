//
// Created by Piotr Żelazko on 01.06.2017.
//

#ifndef ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP
#define ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP

#include "Signal.hpp"
#include "SignalFactory.hpp"

class RoomsRequestSignal : public Signal{
public:

	 /*!
 	 * @brief Constructor used by SignalFactory
 	 */
	RoomsRequestSignal() {}

	/*!
 	 * @brief Default constructor.
	 * @param hdl sender
	 */
    RoomsRequestSignal(ConnectionProtocolHandler*);

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

private:

	/*!
 	 * @static
 	 * @brief Used to register this type in SignalFactory
 	 */
    static Register<RoomsRequestSignal> reg;

};


#endif //ZPR_DRAUGHTS_ROOMSREQUESTSIGNAL_HPP
