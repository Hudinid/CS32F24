# CXX=clang++
CXX=g++

lab06Test: lab06Test.o WordCount.o tddFuncs.o
	${CXX} lab06Test.o WordCount.o tddFuncs.o -o lab06Test

# lab06Test.o: lab06Test.cpp
# 	${CXX} -c lab06Test.cpp

# WordCount.o: WordCount.cpp
# 	${CXX} -c WordCount.cpp


clean: 
	/bin/rm -f *.o lab06Test 