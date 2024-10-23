#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
int main() {
    WordCount words;

    // words.incrWordCount("hElLO");
    ASSERT_EQUALS(1, words.incrWordCount("foo"));
    std::cout << words.makeValidWord("--$$--");
    // ASSERT_EQUALS(2 , words.getTotalWords());
    // ASSERT_EQUALS(1 , words.getNumUniqueWords());
    // words.incrWordCount("I am here");
    // ASSERT_EQUALS(2, words.getWordCount("hello"));
    // words.decrWordCount("hello");
    // ASSERT_EQUALS(1, words.getWordCount("hello"));

    // ASSERT_EQUALS("monkeys", words.makeValidWord("12mOnkEYs-$"));
    // ASSERT_EQUALS("paive", words.makeValidWord(" Pa55ive   1231"));
    // std::cout << words.makeValidWord(" Pa55ive   1231") << std::endl;
    // words.decrWordCount("hello");
    // ASSERT_EQUALS(1, words.getTotalWords());
    // words.incrWordCount("");
    // ASSERT_EQUALS(1, words.getTotalWords());
    // ASSERT_EQUALS("can't", words.makeValidWord("123120938019 can't -1231412"));
    // ASSERT_EQUALS("good-willed", words.makeValidWord("213123-1231 good-wiLLeD 12301"));

    return 0;
}