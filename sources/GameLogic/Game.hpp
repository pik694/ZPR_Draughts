#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include <memory>

#include "PlayerColour.hpp"
#include "Board.hpp"
#include "GameObserver.hpp"
#include "PieceKind.hpp"
#include "Point.hpp"

/*! \file
 *
 * @brief Game class represents whole the logic of draughts.
 *
 * Class is responsible for creating game, starting and ending it, deciding whether game has finished or not. Informing GameObserver when such an events happens.
 * Game also validates moves, updates board and updates player whose turn it is.
 *
 */

/*!
* @brief Game class represents whole the logic of draughts.
*
* Class is responsible for creating game, starting and ending it, deciding whether game has finished or not. Informing GameObserver when such an events happens.
* Game also validates moves, updates board and updates player whose turn it is.
*
*/
class Game {
public:


    /*!
     * Default constructor.
     */
    Game() : gameObserver_(nullptr), duringGame_(false){
    }

    /*!
     * @brief Constructor used in testing.
     *
     * Used because provides useful option to load generated board instead of making hundreds of moves in order to get the  needed board.
     * @param board Board with which game starts.
     */
    Game(Board &&board) : board_(board), gameObserver_(nullptr) {


        currentTurn_ = PlayerColour::white;

        blackPieces_ = whitePieces_ = 0;

        for (int i = 0; i < Board::BOARD_SIZE; ++i){
            for (int j = 0; j < Board::BOARD_SIZE; ++j) {
                PieceKind currPiece = board_.getPieceAt(Point(i, j), PlayerColour::white);

                if (currPiece == PieceKind::whiteMen || currPiece == PieceKind::whiteKing){
                    ++whitePieces_;
                }
                else if (currPiece == PieceKind::blackMen || currPiece == PieceKind::blackKing){
                    ++blackPieces_;
                }

            }
        }

        duringGame_ = true;

    }


    /*!
     * @brief Sets GameObserver which will be informed when game ends (one player wins).
     * @param gameObserver
     */
    void setGameObserver(GameObserver* gameObserver);


    /*!
     * @brief Starts game
     *
     * Resets board, player whose move it is and other necessary things.
     */
    void startGame();

    /*!
     * @brief Stops game when it is in progress.
     *
     * Blocks future moves - makes them invalid. Used usually when a player leaves room and there is no point in continuing this game.
     */
    void stopGame();

    /*!
     * @brief Checks whether the game is in progress.
     * @return true when the game is in progress.
     */
    bool isInProcess();


    /*!
     * @brief Makes move from the given path.
     *
     * Checks whether all the conditions are fulfilled and if so makes the move.
     * @return true if given move was valid and was made.
     */
    bool makeMove(PlayerColour, const std::vector<Point> &);


    /*!
     * @brief Makes move from the given path.
     *
     * Checks whether all the conditions are fulfilled and if so makes the move.
     * @return true if given move was valid and was made.
     */
    bool makeMove(PlayerColour, Point, Point);


    /*!
     * @return Returns current board.
     */
    Board getBoard(PlayerColour) const;


    /*!
     *
     * @return returns \link PlayerColour \endlink  whose turn it is.
     */
    PlayerColour whoseTurn() const;

private:

    bool validatePoints(PieceKind, Point begin, Point end);

    bool validateMove(PlayerColour, const std::vector<Point> &);

    void movePiece(PlayerColour, const std::vector<Point> &);

    int findDirection(int begin, int end);

    void changeIntoAKing(PieceKind &);

    Board board_;
    PlayerColour currentTurn_;

    bool duringGame_;

    int whitePieces_;
    int blackPieces_;

    GameObserver* gameObserver_;

};

#endif // GAME_HPP