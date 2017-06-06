//
// Created by Piotr Żelazko on 31.05.2017.
//

#ifndef ZPR_DRAUGHTS_MOVESIGNAL_HPP
#define ZPR_DRAUGHTS_MOVESIGNAL_HPP

/*!
 * @file
 * @brief Class representing an attempt to make a move, is always sent by a client.
 * Derives from Signal class.
 */



#include <vector>

#include <GameLogic/Point.hpp>
#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Class representing an attempt to make a move, is always sent by a client.
 * Derives from Signal class.
 */

class MoveSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
	MoveSignal() {}

    /*!
     * @brief Default constructor.
     * @param path points that create path - represent the move
     * @param hdl sender
     */
    MoveSignal(std::initializer_list<Point> path, ConnectionProtocolHandler *hdl) :
            Signal(hdl),
            move_(path) {}

    /*!
     *
     * @return vector of Points representing a move.
     */
    const std::vector<Point> &getMove() const;

    /*!
     * @brief parses Json::Value and sets its attributes according to the Json.
     * @param data
     */
    virtual void fillData(Json::Value);

    /*!
     * @brief Changes an object into Json::Value
     * @return Json::Value of this object
     */
    virtual Json::Value serialize();

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
    static Register<MoveSignal> reg;

    std::vector<Point> move_;

};


#endif //ZPR_DRAUGHTS_MOVESIGNAL_HPP
