#include <gtest/gtest.h>

#include "random.hpp"

TEST(RandomNumberGenerator, FirstThreeNumbers) {
    int seed=-1000;
    Random random(seed);
    EXPECT_NEAR(random.ran1(), 0.464514, 1.0e-6);
    EXPECT_NEAR(random.ran1(), 0.928778, 1.0e-6);
    EXPECT_NEAR(random.ran1(), 0.502077, 1.0e-6);
}

TEST(RandomNumberGenerator, ConstructorReset) {
    int seed=-1000;
    Random random(seed);
    EXPECT_NEAR(random.ran1(), 0.464514, 1.0e-6);
    random = Random(seed);
    EXPECT_NEAR(random.ran1(), 0.464514, 1.0e-6);
}
