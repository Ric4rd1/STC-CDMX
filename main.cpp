/*
 * main.cpp
 *
 *  Created on: 14/09/23
 *      Author: ric4rd
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <list>

#include "unit.h"

template <class T>
std::string arrayToString(const std::vector<T> &v) {
	std::stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string listToString(const std::list<T> &v) {
	typename std::list<T>::const_iterator itr;
	std::stringstream aux;

	itr = v.begin();
	aux << "[" << *itr++;
	for (; itr != v.end(); itr++) {
		aux << ", " << *itr;
	}
	aux << "]";
	return aux.str();
}

class SortsTest: public UnitTest {
    public:
        void runTest(){

        }
};

int main (){
    SortsTest test;

    test.runTest();
    return 0;
}