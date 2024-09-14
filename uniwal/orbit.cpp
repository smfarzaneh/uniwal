#include <cmath>

#include "orbit.hpp"

Orbit::Point::Point(double x, double y) : x(x), y(y) {};

bool Orbit::Point::operator==(const Point& p) const {
    return this->x == p.x && this->y == p.y;
}

bool Orbit::checkReturn(Point p1, Point p2, double radius) {
    double distanceFromOrigin = std::numeric_limits<double>::infinity();
    if (p1 == p2) 
        distanceFromOrigin = std::sqrt(p1.x * p1.x + p1.y * p1.y);
    else {
        double dx = p2.x - p1.x;
        double dy = p2.y - p1.y;
        double segmentLength = std::sqrt(dx * dx + dy * dy); 
        distanceFromOrigin = std::abs(-dx * p1.y + p1.x * dy) / segmentLength;
    }
    if (distanceFromOrigin < radius) 
        return true;
    else
        return false;
}
