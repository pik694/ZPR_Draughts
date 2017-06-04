#ifndef ROOM_MANAGER_HPP
#define ROOM_MANAGER_HPP

#include <list>
#include <memory>
#include <vector>

/*! @file
 * @brief Singleton that manages Room instances.
 */

class Room;
class Player;


/*!
 * @brief Singleton that keeps instances of Room class.
 * It keeps rooms in a list.
 * Maximum number of rooms is 32
 */
class RoomManager {

    using room_ptr = std::shared_ptr<Room>;
    using player_ptr = std::shared_ptr<Player>;


public:

    /*! @static
     * @return Returns valid pointer to the only instance of this class.
     */
    static RoomManager *getInstance();

    /*!
     * @return Returns a vector of ints which represents all the rooms (their IDs) currently being in use.
     */
    std::vector<int> getRooms();

    /*!
     * Returns a room with given ID.
     * @param id demanded room's ID
     * @return valid room or nullptr in case such a room does not exist.
     */
    room_ptr getRoom(int id);

    /*!
     * Tries to create new room.
     * May fail when maximum number of rooms has been reached.
     * @return valid room or nullptr in case this method fails.
     */
    room_ptr newRoom();

    /*!
     * Removes given room. Used only by Room's method when both players left the room.
     * Irresponsible usage may lead to memory leaks and other errors.
     */
    void deleteRoom(room_ptr);

    /*!
     * @deprecated
     * Required when using a singleton design pattern.
     */
    RoomManager(const RoomManager &) = delete;

    /*!
     * Default destructor
     */
    ~RoomManager();

private:


    static RoomManager *instance_;
    static const size_t MAX_NUMBER_OF_ROOMS;

    RoomManager();

    int currentRoomID_;
    std::list<room_ptr> rooms_;
};

#endif // ROOM_MANAGER_HPP