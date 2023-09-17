/*
 * Line.h
 *
 *  Created on: 
 *      Author: 
 */

#ifndef LINE_H_
#define LINE_H_

#include "exception.h"
#include "Station.h"
#include "Train.h"

#include <vector>
#include <list>
#include <string>

class Line {
    private:
        std::string name;
        int numStations;
        int numTrains;
        std::string color;
        int length;
        std::vector<Station> stations;
        std::vector<Train> trains;
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
        std::vector<Station > getStations() const {return stations;}
        std::vector<Train > getTrains() const {return trains;}

        //Setters
        void setName(char name) {this->name = name;}
        void setNumStations(int numStations) {this->numStations = numStations;}
        void setNumTrains(int numTrains) {this->numTrains = numTrains;}
        void setColor(std::string color) {this->color = color;}
        void setLength(int length) {this->length = length;}
        void setStations(std::vector<Station > stations) 
                         {this->stations = stations;}
        void setTrains(std::vector<Train > trains) {this->trains = trains;}

        //Methods
        void addStation(Station s);
        void addTrain(Train t);
        void removeStation(Station s);
        void removeTrain(Train t);
        

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