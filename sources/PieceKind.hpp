//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_ENUMS_HPP
#define ZPR_DRAUGHTS_ENUMS_HPP

    enum class PieceKind : uint8_t {
        none,
        blackMen,
        whiteMen,
        blackKing,
        whiteKing,
    };

//TODO: resolve a problem with linking
//
//    std::ostream& operator<<(std::ostream& out, PieceKind kind){
//
//        std::string name;
//
//        switch(kind){
//            case PieceKind::blackMen:
//               name = "blackMen";
//           case PieceKind::whiteMen:
//               name = "whiteMen";
//                break;
//           case PieceKind::blackKing:
//               name = "blackKing";
//                break;
//           case PieceKind::whiteKing:
//               name = "whiteKing";
//                break;
//           case PieceKind::none:
//               name = "none";
//                break;
//           default:
//               throw std::runtime_error("Unexpected value of type PieceKind");
//       }
//
//        out << name;
//
//        return out;
//    }
//


#endif //ZPR_DRAUGHTS_ENUMS_HPP
