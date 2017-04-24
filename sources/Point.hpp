//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_POINT_H
#define ZPR_DRAUGHTS_POINT_H


struct Point {

    Point(uint8_t x, uint8_t y): x_(x), y_(y) { }

    uint8_t x_;
    uint8_t y_;

};


#endif //ZPR_DRAUGHTS_POINT_H
