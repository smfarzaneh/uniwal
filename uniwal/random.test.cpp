#include <gtest/gtest.h>

#include "random.hpp"

TEST(RandomNumberGenerator, FirstThreeNumbers) {
    int seed=-1000;
    // double temp = 0.0;
    Random random(seed);
    // temp = random.ran1();
    EXPECT_NEAR(random.ran1(), 0.464514, 1.0e-6);
    EXPECT_NEAR(random.ran1(), 0.928778, 1.0e-6);
    EXPECT_NEAR(random.ran1(), 0.502077, 1.0e-6);
}
