#include "gtest/gtest.h"
#include "big_int.h"

TEST (constructor_tests, empty_constructor) {
    BigInt a;
    EXPECT_EQ(a.GetString(), "");
}

TEST (constructor_tests, int_constructor) {
    EXPECT_EQ(BigInt(456).GetString(), "456");
    EXPECT_EQ(BigInt(0).GetString(), "0");
    EXPECT_EQ(BigInt(-456).GetString(), "-456");
}

TEST (constructor_tests, string_constructor) {
    EXPECT_EQ(BigInt("123456789123456789").GetString(), "123456789123456789");
    EXPECT_EQ(BigInt("0").GetString(), "0");
    EXPECT_EQ(BigInt("-100").GetString(), "-100");

    try
    {
        BigInt b("ass007");
    }
    catch (const std::logic_error &e)
    {
        EXPECT_STREQ(e.what(), "invalid_argument");
    }
}

TEST (constructor_tests, copy_constructor) {
    BigInt a("123456789123456789");
    BigInt b(a);
    EXPECT_EQ(a.GetString(), b.GetString());
}

TEST (operators_tests, assignment_operator) {
    BigInt a("123456789123456789");
    BigInt b = a;
    EXPECT_EQ(a.GetString(), b.GetString());
}

TEST (binary_operators_tests, not_operator) {
    BigInt a(52);
    a = ~a;
    EXPECT_EQ(a.GetString(),"-203");
}

TEST (operators_tests, increment_operator) {
    BigInt a("123456789123456789");
    a++;
    ++a;
    EXPECT_EQ(a.GetString(),"123456789123456791");
}

TEST (operators_tests, decrement_operator) {
    BigInt a("123456789123456789");
    --a;
    a--;
    EXPECT_EQ(a.GetString(),"123456789123456787");
}

TEST (aritmetic_assignment_tests, addition) {
    BigInt a("123456789123456789");
    a += BigInt("1234568899");
    EXPECT_EQ(a.GetString(),"123456790358025688");

    BigInt b("-123456789123456789");
    b += BigInt("1234568899");
    EXPECT_EQ(b.GetString(),"-123456787888887890");

    BigInt c("-123456789123456789");
    c += BigInt("-1234568899");
    EXPECT_EQ(c.GetString(),"-123456790358025688");

    BigInt d("0");
    d += BigInt("1234568899");
    EXPECT_EQ(d.GetString(),"1234568899");
}

TEST (aritmetic_assignment_tests, multiplication) {
    BigInt a("999999999");
    a *= BigInt("999999999");
    EXPECT_EQ(a.GetString(),"999999998000000001");

    BigInt b("-999999999");
    b *= BigInt("-999999999");
    EXPECT_EQ(b.GetString(),"999999998000000001");

    BigInt c("-999999999");
    c *= BigInt("999999999");
    EXPECT_EQ(c.GetString(),"-999999998000000001");

    BigInt d("999999999");
    d *= BigInt("0");
    EXPECT_EQ(d.GetString(),"0");
}

TEST (aritmetic_assignment_tests, subtraction) {
    BigInt a("123456789123456789");
    a -= BigInt("1234568899");
    EXPECT_EQ(a.GetString(),"123456787888887890");

    BigInt b("-123456789123456789");
    b -= BigInt("1234568899");
    EXPECT_EQ(b.GetString(),"-123456790358025688");

    BigInt c("-123456789123456789");
    c -= BigInt("-1234568899");
    EXPECT_EQ(c.GetString(),"-123456787888887890");


    BigInt d("0");
    d -= BigInt("1234568899");
    EXPECT_EQ(d.GetString(),"-1234568899");
}

TEST (aritmetic_assignment_tests, division) {
    BigInt a(999999999);
    a /= BigInt(666);
    EXPECT_EQ(a.GetString(), "1501501");

    BigInt b(999999999);
    b /= BigInt(-666);
    EXPECT_EQ(b.GetString(), "-1501501");

    BigInt c(-999999999);
    c /= BigInt(666);
    EXPECT_EQ(c.GetString(), "-1501501");

    try
    {
        BigInt d("38");
        BigInt e("0");
        d /= e;

    }
    catch (const std::logic_error &e)
    {
        EXPECT_STREQ(e.what(), "division by zero");
    }
}

TEST (aritmetic_assignment_tests, degree) {
    BigInt a("999999999");
    a ^= BigInt("2");
    EXPECT_EQ(a.GetString(),"999999998000000001");
}

TEST (aritmetic_assignment_tests, remainder_division) {
    BigInt a(999999997);
    a %= BigInt(666);
    EXPECT_EQ(a.GetString(), "331");

    BigInt b(553);
    b %= BigInt(1003);
    EXPECT_EQ(b.GetString(), "553");
}

TEST (binary_operators_tests, and_operator) {
    BigInt a(36);
    a &= BigInt(53);
    EXPECT_EQ(a.GetString(),"36");
}

TEST (binary_operators_tests, or_operator) {
    BigInt a(38);
    a |= BigInt(53);
    EXPECT_EQ(a.GetString(),"55");
}

TEST (unary_operation, unary_operation) {
    BigInt a("123456789123456789");
    +a;
    EXPECT_EQ(a.GetString(),"123456789123456789");

    BigInt b("123456789123456789");
    -b;
    EXPECT_EQ(b.GetString(),"-123456789123456789");
}

TEST (comparison_tests, assignment) {
    EXPECT_TRUE(BigInt(12345678) == BigInt(12345678));
    EXPECT_FALSE(BigInt("-12345678912345678") == BigInt("12345678912345678"));
}

TEST (comparison_tests, not_assignment) {
    EXPECT_FALSE(BigInt(12345678) != BigInt(12345678));
    EXPECT_TRUE(BigInt("-12345678912345678") != BigInt("12345678912345678"));
}

TEST (comparison_tests, less) {
    EXPECT_FALSE(BigInt(12345678) < BigInt(12345678));
    EXPECT_TRUE(BigInt("-12345678912345678") < BigInt("12345678912345678"));
}

TEST (comparison_tests, bigger) {
    EXPECT_FALSE(BigInt(12345678) > BigInt("999999999999"));
    EXPECT_TRUE(BigInt("12345678912345678") > BigInt("-12345678912345678"));
}

TEST (comparison_tests, less_assignment) {
    EXPECT_TRUE(BigInt(12345678) <= BigInt(12345678));
    EXPECT_TRUE(BigInt("-12345678912345678") <= BigInt("12345678912345678"));
}

TEST (comparison_tests, bigger_assignment) {
    EXPECT_FALSE(BigInt(12345678) >= BigInt("999999999999"));
    EXPECT_TRUE(BigInt("12345678912345678") >= BigInt("12345678912345678"));
}

TEST (to_int_tests, to_int) {
    EXPECT_EQ(int(BigInt(123456789)), 123456789);
    try
    {
        int(BigInt("12345678912345678912345687"));
    }
    catch (const std::logic_error &e)
    {
        EXPECT_STREQ(e.what(), "not integer");
    }
}

TEST (aritmetic_tests, addition) {
    BigInt a("123456789123456789");
    BigInt a1("1234568899");
    BigInt aResult = a + a1;
    EXPECT_EQ(aResult.GetString(),"123456790358025688");

    BigInt b("-123456789123456789");
    BigInt b1("1234568899");
    BigInt bResult  = b + b1;
    EXPECT_EQ(bResult.GetString(),"-123456787888887890");

    BigInt c("-123456789123456789");
    BigInt c1("-1234568899");
    BigInt cResult = c + c1;
    EXPECT_EQ(cResult.GetString(),"-123456790358025688");

    BigInt d("0");
    BigInt d1("1234568899");
    BigInt dResult = d + d1;
    EXPECT_EQ(dResult.GetString(), "1234568899");
}

TEST (aritmetic_tests, multiplication) {
    BigInt a("999999999");
    BigInt a1 ("999999999");
    BigInt aResult = a * a1;
    EXPECT_EQ(aResult.GetString(),"999999998000000001");

    BigInt b("-999999999");
    BigInt b1("-999999999");
    BigInt bResult = b * b1;
    EXPECT_EQ(bResult.GetString(),"999999998000000001");

    BigInt c("-999999999");
    BigInt c1("999999999");
    BigInt cResult = c * c1;
    EXPECT_EQ(cResult.GetString(),"-999999998000000001");

    BigInt d("999999999");
    BigInt d1("0");
    BigInt dResult = d * d1;
    EXPECT_EQ(dResult.GetString(),"0");
}

TEST (aritmetic_tests, subtraction) {
    BigInt a("123456789123456789");
    BigInt a1("1234568899");
    BigInt aResult = a - a1;
    EXPECT_EQ(aResult.GetString(),"123456787888887890");

    BigInt b("-123456789123456789");
    BigInt b1("1234568899");
    BigInt bResult = b - b1;
    EXPECT_EQ(bResult.GetString(),"-123456790358025688");

    BigInt c("-123456789123456789");
    BigInt c1("-1234568899");
    BigInt cResult = c - c1;
    EXPECT_EQ(cResult.GetString(),"-123456787888887890");


    BigInt d("0");
    BigInt d1("1234568899");
    BigInt dResult = d - d1;
    EXPECT_EQ(dResult.GetString(),"-1234568899");
}

TEST (aritmetic_tests, division) {
    BigInt a(999999999);
    BigInt a1(666);
    BigInt aResult = a / a1;
    EXPECT_EQ(aResult.GetString(), "1501501");

    BigInt b(999999999);
    BigInt b1(-666);
    BigInt bResult = b / b1;
    EXPECT_EQ(bResult.GetString(), "-1501501");

    BigInt c(-999999999);
    BigInt c1(666);
    BigInt cResult = c / c1;
    EXPECT_EQ(cResult.GetString(), "-1501501");

    try
    {
        BigInt d("38");
        BigInt e("0");
        d = d / e;

    }
    catch (const std::logic_error &e)
    {
        EXPECT_STREQ(e.what(), "division by zero");
    }
}

TEST (aritmetic_tests, degree) {
    BigInt a("999999999");
    BigInt a1 ("2");
    BigInt aResult = a ^ a1;
    EXPECT_EQ(aResult.GetString(),"999999998000000001");
}

TEST (aritmetic_tests, remainder_division) {
    BigInt a(999999997);
    BigInt a1(666);
    BigInt aResult = a % a1;
    EXPECT_EQ(aResult.GetString(), "331");

    BigInt b(553);
    BigInt b1(1003);
    BigInt bResult = b % b1;
    EXPECT_EQ(bResult.GetString(), "553");
}

TEST (binary_tests, and_operator) {
    BigInt a(36);
    BigInt a1(53);
    BigInt aResult = a & a1;
    EXPECT_EQ(aResult.GetString(),"36");
}

TEST (binary_tests, or_operator) {
    BigInt a(38);
    BigInt a1(53);
    BigInt aResult = a | a1;
    EXPECT_EQ(aResult.GetString(),"55");
}

TEST(output_operator_test, output)
{
    std::ostringstream out;
    out << BigInt("123456789455665");
    EXPECT_STREQ(out.str().data(), "123456789455665");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

