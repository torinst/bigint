#include <gtest/gtest.h>
#include "bigint"

TEST(ArithmeticTest, Modulo)
{
    bigint a = 256, b = 200;
    EXPECT_EQ(a % b, 256 % 100);
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
