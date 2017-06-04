//
// Created by Piotr Żelazko on 23.04.2017.
//

#ifndef ZPR_DRAUGHTS_POINT_H
#define ZPR_DRAUGHTS_POINT_H

/*! @file
 * @brief Simple point structure.
 *
 */


/*!
 * @brief Simple point structure.
 *
 *  Structure consists of two attributes which represent coordinates in two-dimensional space. /br
 *  Implements necessary operators and constructors.
 *
 */

struct Point {

    /*!
     * @brief Default constructor
     *
     * Construct an instance with given coordinates.
     * @param x x - coordinate
     * @param y y - coordinate
     */
    Point(int x, int y) : x_(x), y_(y) {}


    /*!
     * @brief Operator +=
     *
     * Works as adding vectors.
     * @param _rv R-value point
     * @return returns const reference to the instance after having added given point.
     */
    Point &operator+=(const Point &_rv) {
        this->y_ += _rv.y_;
        this->x_ += _rv.x_;
        return *this;
    }


    /*!
     * @brief Operator +
     *
     * Enables to add two points to each other.
     *
     * @param _rv R-value point
     * @return returns new Point which is the result of adding two given points.
     */
    Point operator+(const Point &_rv) const {

        return Point(this->x_ + _rv.x_, this->y_ + _rv.y_);
    }


    /*!
     * @brief Operator -
     *
     * Enables to subtract two points from each other.
     *
     * @param _rv R-value point
     * @return returns new Point which is the result of subtracting given point from the instance on which it is called.
     */
    Point operator-(const Point &_rv) const {
        return Point(this->x_ - _rv.x_, this->y_ - _rv.y_);
    }

    /*!
     * @brief Operator==. Compares if both coordinates are the same
     * @param _rv point with which the instance is compared
     * @return true if and only if both coordinates are equal.
     */
    bool operator==(const Point &_rv) const {
        return this->x_ == _rv.x_ && this->y_ == _rv.y_;
    }

    /*!
    * @brief Operator!=. Compares if both coordinates differ
    * @param _rv point with which the instance is compared
    * @return false if and only if both coordinates are equal.
    */
    bool operator!=(const Point &_rv) const {
        return !operator==(_rv);
    }

    int x_; //!< X coordinate
    int y_; //!< Y coordinate

};


#endif //ZPR_DRAUGHTS_POINT_H
