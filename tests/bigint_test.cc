#include "../bigint"
#include <gtest/gtest.h>

// arithmetic test
struct ArithmeticCase
{
    std::string __l, __r;
    char op;
    std::string expected;
};

class ArithmeticParamTest
  : public ::testing::TestWithParam<ArithmeticCase>
{ };

TEST_P(ArithmeticParamTest, Run)
{
    auto p = GetParam();
    bigint l(p.__l), r(p.__r), ret;
    if (p.op == '+')
        ret = l + r;
    else if (p.op == '-')
        ret = l - r;
    else if (p.op == '*')
        ret = l * r;
    else if (p.op == '/')
        ret = l / r;
    else if (p.op == '%')
    // There is a known issue here: 256 % 200 -> 54
        ret = l % r;
    EXPECT_EQ(ret, p.expected) << "l = " << p.__l << ", r = " << p.__r;
}

INSTANTIATE_TEST_SUITE_P(ArithmeticTests,
                         ArithmeticParamTest,
                         ::testing::Values
   (ArithmeticCase{"0", "0", '+', "0"},
    ArithmeticCase{"1", "1", '+', "2"},
    ArithmeticCase{"999", "1", '+', "1000"},
    ArithmeticCase{"123456789", "987654321", '+', "1111111110"},
    ArithmeticCase{"-5", "3", '+', "-2"},
    ArithmeticCase{"-1000", "-24", '+', "-1024"},
    ArithmeticCase{"1000", "999", '-', "1"},
    ArithmeticCase{"1", "1000", '-', "-999"},
    ArithmeticCase{"123456789", "987654321", '-', "-864197532"},
    ArithmeticCase{"-5", "3", '-', "-8"},
    ArithmeticCase{"12345", "6789", '*', "83810205"},
    ArithmeticCase{"-123", "45", '*', "-5535"},
    ArithmeticCase{"123456789", "0", '*', "0"},
    ArithmeticCase{"1", "1", '+', "2"},
    ArithmeticCase{"100", "4", '/', "25"},
    ArithmeticCase{"123456789", "10000", '/', "12345"},
    ArithmeticCase{"100", "3", '%', "1"},
    ArithmeticCase{"987654321", "10", '%', "1"},
    ArithmeticCase{"-7", "3", '%', "-1"},
    ArithmeticCase{"-12345", "-100", '%', "-45"},
    ArithmeticCase{"1267650600228229401496703205376",  // 2 ^ 100 + 1
        "1", '+', "1267650600228229401496703205377"})
);

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
