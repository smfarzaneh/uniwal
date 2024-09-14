#include <gtest/gtest.h>

#include "orbit.hpp"

TEST(ReturnCondition, CheckNormalCases) {
    Orbit::Point p1(-2.0, 3.0);
    Orbit::Point p2(1.0, -0.5);
    double radius = 2.5e-5;
    EXPECT_FALSE(Orbit::checkReturn(p1, p2, radius));
    p1 = Orbit::Point(-2.0, 3.0);
    p2 = Orbit::Point(0.5, -0.75);
    EXPECT_TRUE(Orbit::checkReturn(p1, p2, radius));
}

TEST(ReturnCondition, HandleEqualPoints) {
    Orbit::Point p1(1.0, 1.0);
    Orbit::Point p2(1.0, 1.0);
    double radius = 2.5e-5;
    EXPECT_FALSE(Orbit::checkReturn(p1, p2, radius));
    p1 = Orbit::Point(1.0e-5, 1.0e-5);
    p2 = Orbit::Point(1.0e-5, 1.0e-5);
    EXPECT_TRUE(Orbit::checkReturn(p1, p2, radius));
}

TEST(ReturnCondition, HandleOrigin) {
    Orbit::Point p1(0.0, 0.0);
    Orbit::Point p2(0.0, 0.0);
    double radius = 2.5e-5;
    EXPECT_TRUE(Orbit::checkReturn(p1, p2, radius));
}
