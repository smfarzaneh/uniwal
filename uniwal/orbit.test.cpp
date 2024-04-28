#include <gtest/gtest.h>

#include "orbit.hpp"

TEST(OrbitGeneration, CheckReturnCondition) {
    Orbit::Point p1(-2.0, 3.0);
    Orbit::Point p2(1.0, -0.5);
    double radius = 2.5e-5;
    EXPECT_FALSE(Orbit::checkReturn(p1, p2, radius));
    p1 = Orbit::Point(-2.0, 3.0);
    p2 = Orbit::Point(0.5, -0.75);
    EXPECT_TRUE(Orbit::checkReturn(p1, p2, radius));
}
