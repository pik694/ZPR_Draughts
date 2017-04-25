//
// Created by Piotr Żelazko on 24.04.2017.
//

#ifndef ZPR_DRAUGHTS_PLAYERCOLOUR_HPP
#define ZPR_DRAUGHTS_PLAYERCOLOUR_HPP


    enum class PlayerColour : uint8_t {
        white,
        black,
    };

//TODO: resolve a problem with linking
//     std::ostream& operator<<(std::ostream& out, PlayerColour colour){
//        out << ((colour == PlayerColour::black) ? "back" : "white");
//        return out;
//    }

#endif //ZPR_DRAUGHTS_PLAYERCOLOUR_HPP
