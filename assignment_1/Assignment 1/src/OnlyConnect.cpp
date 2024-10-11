/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 * PUZZLE: NCPTN
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
using namespace std;

string onlyConnectize_recur(string phrase) {
    if (phrase.empty()) {
        return "";
    }

    char check = phrase.at(0);
    if (!isalpha(check) || check == 'A' || check == 'E' || check == 'I' || check == 'O' || check == 'U') {
        return onlyConnectize_recur(phrase.substr(1));
    }

    return charToString(check) + onlyConnectize_recur(phrase.substr(1));
}

string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    phrase = toUpperCase(phrase);
    return onlyConnectize_recur(phrase);
}


/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */

STUDENT_TEST("Handles empty string") {
    EXPECT_EQUAL(onlyConnectize(""), "");
}

STUDENT_TEST("Handles charactor Y") {
    EXPECT_EQUAL(onlyConnectize("Y"), "Y");
    EXPECT_EQUAL(onlyConnectize("CSY"), "CSY");
    EXPECT_EQUAL(onlyConnectize("CYS"), "CYS");
}

STUDENT_TEST("Handles vowel") {
    EXPECT_EQUAL(onlyConnectize("AEIOU"), "");
}

