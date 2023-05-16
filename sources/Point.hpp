//
// Created by asaf7 on 5/9/2023.
//

#ifndef COWBOY_VS_NINJA_A_POINT_HPP
#define COWBOY_VS_NINJA_A_POINT_HPP

#include <string>

using namespace std;
namespace ariel {

    class Point {
    private:
        double x_value;
        double y_value;
    public:
        double distance(const Point &other) const;

        string print() const;

        Point(double x_v, double y_v);

        Point();

        Point moveTowards(const Point &other, double dist) const;

        static Point moveTowards(const Point &point1, const Point &point2, double dist);

        double getX() const;

        double getY() const;

    };

} // ariel

#endif //COWBOY_VS_NINJA_A_POINT_HPP
