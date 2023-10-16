/*
 * Stc.h
 *
 *  Created on: 14/10/2023
 *      Author: ricard
 */

#ifndef Stc_H_
#define Stc_H_

#include "exception.h"
#include "Line.h"
#include "Station.h"
#include "Train.h"
//#include "dlist.h"

#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Stc {
    private:
        std::vector<Line> lines;
        //std::list <Station> stations;
        //stations map
        std::map<std::string, Station> stations;
        //DList<int> stationsList;

    public:
        //Constructors
        //default constructor
        Stc();
        //Constructor with parameters
        Stc(std::vector<Line > lines);
        //Copy constructor
        Stc(const Stc &s);

        //Getters
        std::vector<Line> getLines() const {return lines;}
        std::map<std::string, Station> getStations() const {return stations;}


        //Methods
        //Lines
        void loadLines(string fileName);
        void showLines();
        void sortLinesLength();
        std::string linestoString() const;
        
        //Stations
        void addStation(Station);
        void loadStations(std::string);
        void showStations() const;
        std::string getStationLine(std::string) const;
        std::string getStationIcon(std::string) const;
        bool getStationConection(std::string) const;
        std::string getStationLocation(std::string) const;
        std::string getStation(std::string) const;

};

Stc::Stc() {
    lines = {};
    stations = {};

}

Stc::Stc(std::vector<Line > lines) {
    this->lines = lines;
}

Stc::Stc(const Stc &s) {
    lines = s.lines;
}

void Stc::loadLines(string fileName) {
    string name;
    string numStations;
    string numTrains;
    string color;
    string length;

    int numLines = 0; //number of lines
    ifstream file(fileName); //opening the file.

    //checking if the file is open
    if (file.is_open()){
        //while the file is not at the end of the file
        while(!file.eof()){
            //reading the file
            getline(file, name, '\t');
            getline(file, numStations, '\t');
            getline(file, numTrains, '\t');
            getline(file, color, '\t');
            getline(file, length, '\n'); //new line

            //converting the strings to the correct data type
            /*
            char nameChar[3]; 
            nameChar[0] = nameL[0];
            nameChar[1] = name[0];
            if (name[1] == '\0'){
                nameChar[2] = ' ';
            } else{
                nameChar[2] = name[1];
            }
            */
            int numStationsInt = stoi(numStations);
            int numTrainsInt = stoi(numTrains);
            int lengthInt = stoi(length);

            //creating a new line object
            Line* newLine = new Line(name, numStationsInt, numTrainsInt, color, lengthInt);
            //adding the new line to the vector
            lines.push_back(*newLine);
            
            //increment number of lines
            numLines += 1;
        }
        file.close(); //closing the file
    } else {
        cout << ("File could not be opened");
    }
}

void Stc::showLines() {
    cout << "Number of lines: " << lines.size() << endl;
    for (int i = 0; i < lines.size(); i++){
        cout << lines[i].getName() << " " << lines[i].getNumStations() << " " << lines[i].getNumTrains() << " " << lines[i].getColor() << " " << lines[i].getLength() << endl;
    }
}

void Stc::sortLinesLength() {
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines.size(); j++){
            if (lines[i].getLength() < lines[j].getLength()){
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

std::string Stc::linestoString() const {
    std::stringstream aux;
    aux << "Number of lines: " << lines.size() << std::endl;
    for (int i = 0; i < lines.size(); i++){
        aux << lines[i].getName() << " " << lines[i].getNumStations() << " " << lines[i].getNumTrains() << " " << lines[i].getColor() << " " << lines[i].getLength() << std::endl;
    }
    return aux.str();
}

void Stc::addStation(Station s) {
    stations[s.getName()] = s;
}

void Stc::loadStations(std::string fileName) {
    std::string name;
    std::string line;
    std::string icon;
    std::string conection;
    std::string location;

    int numLines = 0; //number of lines
    ifstream file(fileName); //opening the file.

    //checking if the file is open
    if (file.is_open()){
        //while the file is not at the end of the file
        while(!file.eof()){
            //reading the file
            getline(file, name, '\t');
            getline(file, line, '\t');
            getline(file, icon, '\t');
            getline(file, conection, '\t');
            getline(file, location, '\n'); //new line
        
        bool boolConection = (bool)stoi(conection);

        //creating a new line object
        Station* newStation = new Station(name, line, icon, boolConection, location);
        //addStation(*newStation);
        stations[name] = *newStation;

        numLines++; 
        }  
        file.close(); //closing the file
    } else {
        cout << ("File could not be opened");
    }
    
}
// std::cout << stations.toString() << std::endl;
void Stc::showStations() const {
    cout << "Number of stations: " << stations.size() << endl;
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        std::cout << "[ " << it->first << " ]"<<std::endl;
    }
   
}

std::string Stc::getStationLine(std::string name) const {
    std::string line = stations.at(name).getLine();
    return line;
}

std::string Stc::getStationIcon(std::string name) const {
    std::string icon = stations.at(name).getIcon();
    return icon;
}

bool Stc::getStationConection(std::string name) const {
    bool conection = stations.at(name).getConection();
    return conection;
}

std::string Stc::getStationLocation(std::string name) const {
    std::string location = stations.at(name).getLocation();
    return location;
}

//Display all the staition information
std::string Stc::getStation(std::string name) const {
    std::stringstream aux;
    aux << "| Name: " << name << std::endl;
    aux << "| Line: " << getStationLine(name) << std::endl;
    aux << "| Icon: " << getStationIcon(name) << std::endl;
    aux << "| Conection: " << getStationConection(name) << std::endl;
    aux << "| Location: " << getStationLocation(name) << std::endl;
    return aux.str();
}

#endif /* Stc_H_ */