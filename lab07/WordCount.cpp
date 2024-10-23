// WordCount.cpp

#include "WordCount.h"
#include "WordCount.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <map>
#include <string.h>
using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int ret = 0;
	for(size_t i = 0; i < CAPACITY; i++) {
		for(size_t j = 0; j < table[i].size(); j ++) {
			ret += table[i][j].second;
		}
	}
	
	return ret;
	return -1;
}

int WordCount::getNumUniqueWords() const {
	int ret = 0;
	vector<std::string> wordsSeen;

	for(size_t i = 0; i < CAPACITY; i++) {
		for(size_t j = 0; j < table[i].size(); j ++) {
			for(size_t k = 0; k < wordsSeen.size(); k++ ) {
				if(wordsSeen[k] == table[i][j].first) {
					break;
				}
			}
			ret ++;
			wordsSeen.push_back(table[i][j].first);
		}
	}

	return ret;
}

int WordCount::getWordCount(std::string word) const {
	int ret = 0;
	word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	word = makeValidWord(word);
	int index = hash(word);

	for(size_t j = 0; j < table[index].size(); j ++) {
		if(word == table[index][j].first) {
			ret += table[index][j].second;
		}
	}

	return ret;
}
	
int WordCount::incrWordCount(std::string word) {
	int ret = 0;
	word = makeValidWord(word);

	if(word.size() == 0) { return 0; }
	word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	
	size_t index = hash(word);
	
	for(size_t i = 0; i < table[index].size(); i ++) {

		if(table[index][i].first == word) {
			table[index][i].second += 1;
			ret = table[index][i].second;
			return ret;
		}
	}
	std::pair<std::string, int> ins;
	ins.first = word;
	ins.second = 1;
	ret = 1;
	table[index].push_back(ins);

	return ret;
}

int WordCount::decrWordCount(std::string word) {
	// STUB
	int ret = 0;
	word = makeValidWord(word);

	if(word.size() == 0) { return -1; }

	word.erase(std::remove_if(word.begin(), word.end(), ::isspace), word.end());
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	
	size_t index = hash(word);

	for(size_t i = 0; i < table[index].size(); i ++) {
		if(table[index][i].first == word) {
			table[index][i].second -= 1;
			ret = table[index][i].second;
			
			if(table[index][i].second == 0) {
				ret = 0;
				
				table[index].erase(table[index].begin()+i);		
			}
			return ret;
		}
	}

	return -1;
}


bool WordCount::isWordChar(char c) {
	// STUB
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	std::string ret = "";
	for(size_t i = 0; i < word.size(); i ++) {
		if(isWordChar(word[i])) {
			ret += tolower(word[i]);
		}
		else if(word[i] == '\'' && i != 0 && i != word.size()-1) {
			if(isWordChar(word[i-1]) && isWordChar(word[i+1])) {
				ret += '\'';
			}
		}
		else if(word[i] == '-' && i != 0 && i != word.size()-1) {
			if(isWordChar(word[i-1]) && isWordChar(word[i+1])) {
				ret += '-';
			}
		}
		else {
			continue;
		}
	}
	return ret;
}

void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	// STUB
	std::vector < std::pair<std::string, int>> ret;
	for(size_t i = 0; i < CAPACITY; i ++) {
		for(size_t j = 0; j < table[i].size(); j++) {
			ret.push_back(table[i][j]);
		}
	}

	std::sort(ret.rbegin(), ret.rend());
	
	for(auto elem : ret) {
		out << elem.first << "," << elem.second << std::endl;
	}

	return;
}

bool occurenceHelperSort(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
	if(a.second == b.second) { 
		// std::cout<< a.first.compare(b.first) << std::endl;
		// std::cout<< b.first.compare(a.first) << std::endl;
		return a.first.compare(b.first) < 0;
	}
	else {
		return a.second < b.second;
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	std::vector < std::pair<std::string, int>> ret;
	for(size_t i = 0; i < CAPACITY; i ++) {
		for(size_t j = 0; j < table[i].size(); j++) {
			ret.push_back(table[i][j]);
		}
	}

	std::sort(ret.begin(), ret.end(), occurenceHelperSort);
	
	for(auto elem : ret) {
		out << elem.first << "," << elem.second << std::endl;
	}

	return;
}

void WordCount::addAllWords(std::string text) {
	// STUB
	std::string temp = "";
	for(size_t i = 0; i < text.size(); i ++) {
		if(text[i] != ' ' && text[i] != '\n' && text[i] != '\t') {
			temp += text[i];
		}
		else {
			incrWordCount(temp);
			temp = "";
		}
	}
	incrWordCount(temp);
	return;
}
