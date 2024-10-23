#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"

using namespace std;

int main() {
    WordCount words;
    // words.incrWordCount("sentence");
    // words.incrWordCount("sentence");
    // words.incrWordCount("is");
    // words.incrWordCount("a");
    words.incrWordCount("fun");
    words.incrWordCount("fun");
    // words.dumpWordsSortedByWord(std::cout);

    words.addAllWords("did-you know this is a potato12314");
    // words.addAllWords("did you know this is a potato12314");

    words.dumpWordsSortedByWord(std::cout);
    words.dumpWordsSortedByOccurence(std::cout);

    return 0;
}