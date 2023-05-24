//
// Created by asaf7 on 5/9/2023.
//
#include <cmath>
#include <stdexcept>
#include "Point.hpp"

namespace ariel {
    /**
     *
     * @param other
     * @return double that represent the distance between two points
     */
    double Point::distance(const Point &other) const {
        return sqrt(pow(this->x_value - other.x_value, 2) + pow(this->y_value - other.y_value, 2));
    }
    /**
     *
     * @return double that represent the x value of the point
     */

//    double Point::getX() const {
//        return this->x_value;
//    }
//
//    double Point::getY() const {
//        return this->y_value;
//    }
/**
 *
 * @return string that represent the point
 */
    string Point::print() const {
        return "(" + to_string(this->x_value) + "," + to_string(this->y_value) + ")";
    }
    /**
     * constructor
     * @param x
     * @param y
     */

    Point::Point(double x, double y) {
        this->x_value = x;
        this->y_value = y;
    }
/**
 *  move the point towards other point
 * @param point1
 * @param point2
 * @param dist
 * @return new point with the new location
 */
    Point Point::moveTowards(const Point &point1, const Point &point2, double dist) {
        return point1.moveTowards(point2, dist);
    }
/**
 * move the point towards other point
 * @param other
 * @param dist
 * @return
 */
    Point Point::moveTowards(const Point &other, double dist) const {
        if (dist < 0) {
            throw std::invalid_argument("distance cannot be negative");
        }
        double distance = this->distance(other);
        if (distance <= dist) {
            return other;
        }
        return Point{
                this->x_value + (dist * (other.x_value - this->x_value) / distance),
                this->y_value + (dist * (other.y_value - this->y_value) / distance),
        };
    }

/**
 * constructor that initialize the point to (0,0)
 */
    Point::Point() {
        this->x_value = 0;
        this->y_value = 0;
    }
} // ariel