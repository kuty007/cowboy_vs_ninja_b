//
// Created by asaf7 on 5/9/2023.
//
#include <cmath>
#include <stdexcept>
#include "Point.hpp"

namespace ariel {
    double Point::distance(const Point &other) const {
        return sqrt(pow(this->x_value - other.x_value, 2) + pow(this->y_value - other.y_value, 2));
    }
    double Point::getX() const {
        return this->x_value;
    }

    double Point::getY() const {
        return this->y_value;
    }

    string Point::print() const {
        return "(" + to_string(this->x_value) + "," + to_string(this->y_value) + ")";
    }

    Point::Point(double x, double y) {
        this->x_value = x;
        this->y_value = y;
    }
      Point Point::moveTowards(const Point &point1, const Point &point2, double dist)  {
        return point1.moveTowards(point2, dist);
    }

    Point Point::moveTowards(const Point &other, double dist) const {
        if (dist < 0) {
            throw  std::invalid_argument("distance cannot be negative");
        }
        double x = this->x_value;
        double y = this->y_value;
        double x2 = other.x_value;
        double y2 = other.y_value;
        double distance = this->distance(other);
        if (distance <= dist) {
            return other;
        }
        double x3 = x + (dist * (x2 - x) / distance);
        double y3 = y + (dist * (y2 - y) / distance);
        return {x3, y3};
    }


    Point::Point() {
        this->x_value = 0;
        this->y_value = 0;
    }
} // ariel