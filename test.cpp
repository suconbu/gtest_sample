#include "gtest/gtest.h"

int add(int a, int b)
{
    if (a < 0 || b < 0) {
        return 0;
    }
    return a + b;
}

int sub(int a, int b)
{
    if (a < 0 || b < 0) {
        return 0;
    }
    return a - b;
}

TEST(Sample, Add)
{
    EXPECT_EQ(3, add(1, 2));
    EXPECT_EQ(0, add(0, 0));
    EXPECT_EQ(-1, add(1, -2));
    EXPECT_EQ(-3, add(-1, -1));
}

TEST(Sample, Sub)
{
    EXPECT_EQ(-1, sub(1, 2));
    EXPECT_EQ(0, sub(0, 0));
    EXPECT_EQ(3, sub(1, -2));
    EXPECT_EQ(0, sub(-1, -1));
}
