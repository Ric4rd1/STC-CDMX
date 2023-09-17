/*
 * Stc.h
 *
 *  Created on: 
 *      Author: 
 */

#ifndef Stc_H_
#define Stc_H_

#include "exception.h"
#include "Line.h"
#include "Station.h"
#include "Train.h"

#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Stc {
    private:
        std::vector<Line> lines;
    public:
        //Constructors
        //default constructor
        Stc();
        //Constructor with parameters
        Stc(std::vector<Line > lines);
        //Copy constructor
        Stc(const Stc &s);

        //Methods
        void loadLines(string fileName);
        void showLines();
        void sortLinesLength();
};

Stc::Stc() {
    lines = {};
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
#endif /* Stc_H_ */