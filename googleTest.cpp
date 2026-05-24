#include <gtest/gtest.h>
#include <string>
#include "solution1.h"
#include "solution2.h"
#include "solution3.h"
#include "solution4.h"

using namespace std;


TEST(SolutionOneTests, JamesBond) {
    EXPECT_EQ(solution1("James Bond 7", 3), "James Bond 007");
}

TEST(SolutionOneTests, PiDecimal) {
    EXPECT_EQ(solution1("PI=3.14", 2), "PI=03.14");
}

TEST(SolutionOneTests, AlarmClockThreePM) {
    EXPECT_EQ(solution1("It's 3:13pm", 2), "It's 03:13pm");
}

TEST(SolutionOneTests, AlarmClockTwevlePM) {
    EXPECT_EQ(solution1("It's 12:13pm", 2), "It's 12:13pm");
}

TEST(SolutionOneTests, AlphanumericMixed) {
    EXPECT_EQ(solution1("99UR1337", 6), "000099UR001337");
}


TEST(SolutionTwoTests, JamesBond) {
    EXPECT_EQ(solution2("James Bond 7", 3), "James Bond 007");
}

TEST(SolutionTwoTests, PiDecimal) {
    EXPECT_EQ(solution2("PI=3.14", 2), "PI=03.14");
}

TEST(SolutionTwoTests, AlarmClockThreePM) {
    EXPECT_EQ(solution2("It's 3:13pm", 2), "It's 03:13pm");
}

TEST(SolutionTwoTests, AlarmClockTwevlePM) {
    EXPECT_EQ(solution2("It's 12:13pm", 2), "It's 12:13pm");
}

TEST(SolutionTwoTests, AlphanumericMixed) {
    EXPECT_EQ(solution2("99UR1337", 6), "000099UR001337");
}


TEST(SolutionThreeTests, JamesBond) {
    EXPECT_EQ(solution3("James Bond 7", 3), "James Bond 007");
}
TEST(SolutionThreeTests, PiDecimal) {
    EXPECT_EQ(solution3("PI=3.14", 2), "PI=03.14");
}
TEST(SolutionThreeTests, AlarmClockThreePM) {
    EXPECT_EQ(solution3("It's 3:13pm", 2), "It's 03:13pm");
}
TEST(SolutionThreeTests, AlarmClockTwelvePM) {
    EXPECT_EQ(solution3("It's 12:13pm", 2), "It's 12:13pm");
}
TEST(SolutionThreeTests, AlphanumericMixed) {
    EXPECT_EQ(solution3("99UR1337", 6), "000099UR001337");
}


TEST(SolutionFourTests, JamesBond) {
    SLL s;
    EXPECT_EQ(s.upholdChallenge("James Bond 7", 3), "James Bond 007");
}
TEST(SolutionFourTests, PiDecimal) {
    SLL s;
    EXPECT_EQ(s.upholdChallenge("PI=3.14", 2), "PI=03.14");
}
TEST(SolutionFourTests, AlarmClockThreePM) {
    SLL s;
    EXPECT_EQ(s.upholdChallenge("It's 3:13pm", 2), "It's 03:13pm");
}
TEST(SolutionFourTests, AlarmClockTwelvePM) {
    SLL s;
    EXPECT_EQ(s.upholdChallenge("It's 12:13pm", 2), "It's 12:13pm");
}
TEST(SolutionFourTests, AlphanumericMixed) {
    SLL s;
    EXPECT_EQ(s.upholdChallenge("99UR1337", 6), "000099UR001337");
}