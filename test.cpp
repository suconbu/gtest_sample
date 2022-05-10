#include "gtest/gtest.h"

class TestFixture1 : public ::testing::Test {
protected:
    void SetUp() override
    {
        a_ = 1;
        b_ = 2;
    }

    void TearDown() override
    {
    }

    int a_;
    int b_;
};

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

TEST(Sample, AddTest)
{
    EXPECT_EQ(3, add(1, 2));
    EXPECT_EQ(0, add(0, 0));
    EXPECT_EQ(-1, add(1, -2));
    EXPECT_EQ(-3, add(-1, -1));
}

TEST(Sample, SubTest)
{
    EXPECT_EQ(-1, sub(1, 2));
    EXPECT_EQ(0, sub(0, 0));
    EXPECT_EQ(3, sub(1, -2));
    EXPECT_EQ(0, sub(-1, -1));
}

TEST_F(TestFixture1, Test)
{
    EXPECT_EQ(a_ + b_, add(a_, b_));
    EXPECT_EQ(a_ - b_, sub(a_, b_));
}

class TestFixture2 : public TestFixture1, public ::testing::WithParamInterface<int> {
};

TEST_P(TestFixture2, Test)
{
    auto param = GetParam();
    EXPECT_EQ(1 + param, add(1, param));
    EXPECT_EQ(1 - param, sub(1, param));
}

INSTANTIATE_TEST_SUITE_P(ValueParameterizedTest, TestFixture2, testing::Range(-3, 3));
