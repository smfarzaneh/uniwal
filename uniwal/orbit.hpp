#ifndef ORBIT_HPP
#define ORBIT_HPP

namespace Orbit {
    
    struct Point {
        double x, y;
        Point(double x, double y);
        bool operator==(const Point& p) const;
    };
    
    bool checkReturn(Point p1, Point p2, double radius);
}

#endif // ORBIT_HPP
