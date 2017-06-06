//
// Created by Piotr Żelazko on 01.06.2017.
//

#ifndef ZPR_DRAUGHTS_ROOMSSIGNAL_HPP
#define ZPR_DRAUGHTS_ROOMSSIGNAL_HPP

/*!
 * @file
 * @brief Signal is an answer to a @link RoomsRequestSignal @endlink signal.
 * Derives from Signal class
 */

#include <vector>

#include "Signal.hpp"

/*!
 * @brief Signal is an answer to the @link RoomsRequestSignal @endlink signal.
 * Derives from Signal class
 */

class RoomsSignal : public Signal{
public:

	/*!
 	 * @brief Default constructor.
 	 * @param hdl receiver
 	 * @param avaliable rooms
 	 * @param action //TODO: Michal
 	 */
    RoomsSignal(ConnectionProtocolHandler*, const std::vector<int>&, std::string action);

	/*!
 	 * @brief Reimplemented virtual method from Signal
 	 * Implemented according to the instructions given in @link Signal::acceptDispatcher @endlink documentation.
 	 */
	virtual void acceptDispatcher(MessageDispatcher &){};

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

	/*!
	 * @return vector of currently available rooms
	 */
    const std::vector<int>& getRooms();

private:

	std::string action_;
    const std::vector<int> rooms_;
};


#endif //ZPR_DRAUGHTS_ROOMSSIGNAL_HPP
