//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_SIGNAL_HPP
#define ZPR_DRAUGHTS_SIGNAL_HPP

/*!
 * @file
 * @brief Base class for all the Signals sent through the program.
 */

#include <jsoncpp/json/json.h>
#include "ConnectionProtocolHandler.hpp"
#include "MessageDispatcher.hpp"


/*!
 * @brief This class is a base class for all the signals being sent through the program.
 * Implements visitor design pattern, so dispatching messages is easily customisable and scalable.
 */
class Signal {
public:
	/*!
	 * @deprecated
	 */
	Signal() {} //TODO : this constructor should not be used

	/*!
	 * Default constructor.
	 * @param hdl pointer to the sender.
	 */
    Signal(ConnectionProtocolHandler* hdl);

	/*!
	 * @brief Method belongs to the interface to conform to the visitor design pattern.
	 *
	 * Each derived class should implement this method in this way:
	 *  @code {.cpp}
	 *  	dispatcher.dispatch(*this);
	 *  @endcode
	 */
    virtual void acceptDispatcher(MessageDispatcher& dispatcher) = 0;

	/*!
	 * @brief parses Json::Value and sets its attributes according to the Json.
	 * @param data
	 */
    virtual void fillData(Json::Value data) {}

	/*!
	 * @brief Sets connection to the sender/receiver.
	 */
    virtual void fillProtocolHandler(ConnectionProtocolHandler *);

	/*!
	 * @brief Changes an object into Json::Value
	 * @return Json::Value of this object
	 */
    virtual Json::Value serialize() {return nullptr;}

	/*!
	 * @brief Default destructor.
	 */
    virtual ~Signal() {}


	/*!
	 * @return Returns sender's/receiver's ConnectionProtocolHandler
	 */
    ConnectionProtocolHandler* getConnectionProtocolHandler();

private:
    ConnectionProtocolHandler* connectionProtocolHandler_;

};


#endif //ZPR_DRAUGHTS_SIGNAL_HPP
