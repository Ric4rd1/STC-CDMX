/*
 * Line.h
 *
 *  Created on: 14/10/2023
 *      Author: ricard
 */

#ifndef LINE_H_
#define LINE_H_

#include "exception.h"
#include "Station.h"


#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Line {
    private:
        std::string name;
        int numStations;
        int numTrains;
        std::string color;
        int length;

    public:
        //Constructors
        //default constructor
        Line();
        //Constructor with parameters
        Line(std::string name, int numStations, int numTrains,
             std::string color, int length);
        //Copy constructor
        Line(const Line &l);

        //Getters
        std::string getName() const {return name;}
        int getNumStations() const {return numStations;}
        int getNumTrains() const {return numTrains;}
        std::string getColor() const {return color;}
        int getLength() const {return length;}


        //Setters
        void setName(char name) {this->name = name;}
        void setNumStations(int numStations) {this->numStations = numStations;}
        void setNumTrains(int numTrains) {this->numTrains = numTrains;}
        void setColor(std::string color) {this->color = color;}
        void setLength(int length) {this->length = length;}

};

Line::Line() {
    this->name = "";
    this->numStations = 0;
    this->numTrains = 0;
    this->color = "";
    this->length = 0;
}

Line::Line(std::string name, int numStations, int numTrains,
             std::string color, int length) {
    this->name = name;
    this->numStations = numStations;
    this->numTrains = numTrains;
    this->color = color;
    this->length = length;
}

Line::Line(const Line &l) {
    this->name = l.name;
    this->numStations = l.numStations;
    this->numTrains = l.numTrains;
    this->color = l.color;
    this->length = l.length;
}


#endif /* STATION_H_ */
