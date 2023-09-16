/*
 * STC.h
 *
 *  Created on: 
 *      Author: 
 */

#ifndef STC_H_
#define STC_H_

#include "exception.h"
#include "Line.h"
#include "Station.h"
#include "Train.h"

#include <vector>
#include <list>
#include <string>

class STC {
    private:
        std::vector<Line> lines;
    public:
        //Constructors
        //default constructor
        STC();
        //Constructor with parameters
        STC(std::vector<Line > lines);
        //Copy constructor
        STC(const STC &s);

        //Methods
        void sortLinesLength();
};

#endif /* STC_H_ */