
#include <gtest/gtest.h>
#include <string>
#include "solution.cpp"

using namespace std;

TEST(PadDigitGroupsTests, JamesBond) {
    EXPECT_EQ(padDigitGroups("James Bond 7", 3), "James Bond 007");
}

TEST(PadDigitGroupsTests, PiDecimal) {
    EXPECT_EQ(padDigitGroups("PI=3.14", 2), "PI=03.14");
}

TEST(PadDigitGroupsTests, AlarmClockThreePM) {
    EXPECT_EQ(padDigitGroups("It's 3:13pm", 2), "It's 03:13pm");
}

TEST(PadDigitGroupsTests, AlarmClockTwelvePM) {
    EXPECT_EQ(padDigitGroups("It's 12:13pm", 2), "It's 12:13pm");
}

TEST(PadDigitGroupsTests, AlphanumericMixed) {
    EXPECT_EQ(padDigitGroups("99UR1337", 6), "000099UR001337");
}

TEST(PadDigitGroupsTests, LongerGroupUnchanged) {
    EXPECT_EQ(padDigitGroups("abc12345def", 3), "abc12345def");
}

TEST(PadDigitGroupsTests, NoDigits) {
    EXPECT_EQ(padDigitGroups("abcdef", 3), "abcdef");
}

TEST(PadDigitGroupsTests, EmptyString) {
    EXPECT_EQ(padDigitGroups("", 3), "");
}

TEST(PadDigitGroupsTests, TrailingNonDigit) {
    EXPECT_EQ(padDigitGroups("a1b", 3), "a001b");
}

TEST(PadDigitGroupsTests, MixedWidths) {
    EXPECT_EQ(padDigitGroups("a1b22c333", 2), "a01b22c333");
}

TEST(PadDigitGroupsTests, ZeroWidth) {
    EXPECT_EQ(padDigitGroups("a1b22", 0), "a1b22");
}
