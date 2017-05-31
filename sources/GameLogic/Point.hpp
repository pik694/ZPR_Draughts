//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_POINT_H
#define ZPR_DRAUGHTS_POINT_H


struct Point {

    Point(int x, int y) : x_(x), y_(y) {}

    Point &operator+=(const Point &_rv) {
        this->y_ += _rv.y_;
        this->x_ += _rv.x_;
        return *this;
    }

    Point operator+(const Point &_rv) const {

        return Point(this->x_ + _rv.x_, this->y_ + _rv.y_);
    }

    Point operator-(const Point &_rv) const {
        return Point(this->x_ - _rv.x_, this->y_ - _rv.y_);
    }

    bool operator==(const Point &_rv) const {
        return this->x_ == _rv.x_ && this->y_ == _rv.y_;
    }

    bool operator!=(const Point &_rv) const {
        return !operator==(_rv);
    }

    int x_;
    int y_;

};


#endif //ZPR_DRAUGHTS_POINT_H
