//
// Created by Piotr Żelazko on 28.05.2017.
//

#ifndef ZPR_DRAUGHTS_BOARDSIGNAL_HPP
#define ZPR_DRAUGHTS_BOARDSIGNAL_HPP

/*!
 * @file
 * @brief Class representing a board. Sent when game conditions change.
 * Derives from Signal class.
 */

#include "GameLogic/Board.hpp"
#include "Signal.hpp"
#include "SignalFactory.hpp"


/*!
 * @brief Class representing a board. Sent when game conditions change.
 * Derives from Signal class.
 */
class BoardSignal : public Signal {
public:

    /*!
     * @brief Constructor used by SignalFactory
     */
    BoardSignal() : isPlayersMove_(false) {}

    /*!
     * @brief Default constructor.
     * @param hdl sender
     * @param board current board state
     * @param isPlayersMove true if it is receivers move to be made
     * @param team ???? //TODO: what does parameter this mean ?
     */
    BoardSignal(ConnectionProtocolHandler *hdl, Board board, bool isPlayersMove,std::string team) : Signal(hdl), board_(board),
                                                                                   isPlayersMove_(isPlayersMove),team_(team) {}
    /*!
     *
     * @return current board state
     */
    const Board &getBoard() const;

    /*!
     * @return true if it is receivers move to be made
     */
    const bool isPlayersMove() const;

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
    static Register<BoardSignal> reg;


    const Board board_;
    const bool isPlayersMove_;
    std::string team_;


};


#endif //ZPR_DRAUGHTS_BOARDSIGNAL_HPP
