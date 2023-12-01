/*
 * Stc.h
 *
 *  Created on: 14/10/2023
 *      Author: ricard
 */

#ifndef Stc_H_
#define Stc_H_

#include "dlist.h"
#include "graphQ.h"
#include "exception.h"
#include "Line.h"
#include "Station.h"

#include <algorithm>
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
        Graph graph;
        std::vector<std::pair<std::string, int>> locationCode;
        std::string locationArray[100];
        //std::list <Station> stations;
        //stations map
        std::map<std::string, Station> stations;
        DList<std::string> L1Stations;
        DList<std::string> L2Stations;
        DList<std::string> L3Stations;
        DList<std::string> L4Stations;
        DList<std::string> L5Stations;
        DList<std::string> L6Stations;
        DList<std::string> L7Stations;
        DList<std::string> L8Stations;
        DList<std::string> L9Stations;
        DList<std::string> LAStations;
        DList<std::string> LBStations;
        DList<std::string> L12Stations;

        //Methods
        bool linesNameComparisonAscending(Line*, Line*);

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

        //sort lines
        void sortLinesLength();
        void sortLinesName();
        void sortLinesNumStations();
        void sortLinesNumTrains();
        void sortLines();

        //toString
        std::string linestoString() const;
        std::string linestoString2() const;

        
        
        //Stations Map
        void addStation(Station);
        void loadStations(std::string);
        void showStations() const;
        std::string stationsToString() const;
        std::string getStationLine(std::string) const;
        std::string getStationIcon(std::string) const;
        bool getStationConection(std::string) const;
        std::string getStationLocation(std::string) const;
        std::string getStation(std::string) const;

        //Stations DList
        void loadStationDList(std::string);
        std::string getLineMap(std::string) const;

        //Stations Graph
        void loadGraph(std::vector<std::vector<int>>, int);
        void loadLocations(std::string);
        std::string findPath(int, int);
        std::string printPath(const std::string&);
        std::string getShortestPath(std::string, std::string);


};

Stc::Stc() {
    lines = {};
    stations = {};
    loadLocations("locationGraph.txt");

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

std::string Stc :: stationsToString() const {
    std::stringstream aux;
    aux << "Number of stations: " << stations.size() << std::endl;
    for (auto it = stations.begin(); it != stations.end(); ++it) {
        aux << "[ " << it->first << " ]"<<std::endl;
    }
    return aux.str();
}

/*
bool Stc::linesNameComparisonAscending(Line* l1, Line* l2) {
    string name1 = l1->getName();
    string name2 = l2->getName();
    if (name1.compare(name2) < 0) {
        return 1;
    } else {
        return 0;
    }
}

void Stc::sortLines() {
    std::sort(lines.begin(), lines.end(), linesNameComparisonAscending);
}
*/

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

void Stc::sortLinesName() {
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines.size(); j++){
            string name1 = lines[i].getName();
            string name2 = lines[j].getName();
            if (name1[0] == 'L'){
                name1.erase(0,1);
            }
            if (name2[0] == 'L'){
                name2.erase(0,1);
            }
            if (name1[0] == 'A'){
                name1.erase(0,1);
                name1 = "10" + name1;
            }
            if (name2[0] == 'A'){
                name2.erase(0,1);
                name2 = "10" + name2;
            }
            if (name1[0] == 'B'){
                name1.erase(0,1);
                name1 = "11" + name1;
            }
            if (name2[0] == 'B'){
                name2.erase(0,1);
                name2 = "11" + name2;
            }
            if (stoi(name1) < stoi(name2)){
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

void Stc::sortLinesNumStations() {
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines.size(); j++){
            if (lines[i].getNumStations() < lines[j].getNumStations()){
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

void Stc::sortLinesNumTrains() {
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines.size(); j++){
            if (lines[i].getNumTrains() < lines[j].getNumTrains()){
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


std::string Stc::linestoString2() const {
    std::stringstream aux;
    aux << "Number of lines: " << lines.size() << std::endl;
    aux << "Name\t" << "NumStations\t" << "NumTrains\t" << "Color\t\t\t" << "Length (KM)" << std::endl;
    aux << "--------------------------------------------------------------------------------" << std::endl;
    for (int i = 0; i < lines.size(); i++){
        aux << lines[i].getName() << "\t\t" << lines[i].getNumStations() << "\t\t\t" << 
        lines[i].getNumTrains() << "\t\t\t" << lines[i].getColor() << "\t\t\t" << lines[i].getLength() << std::endl;
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
    if (stations.find(name) == stations.end()) {
    aux << "Station not found" << std::endl;
    } else {
    aux << "| Name: " << name << std::endl;
    aux << "| Line: " << getStationLine(name) << std::endl;
    aux << "| Icon: " << getStationIcon(name) << std::endl;
    aux << "| Conection: " << getStationConection(name) << std::endl;
    aux << "| Location: " << getStationLocation(name) << std::endl;
    }

    return aux.str();
}


void Stc::loadStationDList(std::string fileName) {
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
        
        //bool boolConection = (bool)stoi(conection);

        //adding the station to the DList depending on which line it belongs to
        if (line == "L1"){
            L1Stations.add(name);
        } else if (line == "L2"){
            L2Stations.add(name);
        } else if (line == "L3"){
            L3Stations.add(name);
        } else if (line == "L4"){
            L4Stations.add(name);
        } else if (line == "L5"){
            L5Stations.add(name);
        } else if (line == "L6"){
            L6Stations.add(name);
        } else if (line == "L7"){
            L7Stations.add(name);
        } else if (line == "L8"){
            L8Stations.add(name);
        } else if (line == "L9"){
            L9Stations.add(name);
        } else if (line == "LA"){
            LAStations.add(name);
        } else if (line == "LB"){
            LBStations.add(name);
        } else if (line == "L12"){
            L12Stations.add(name);
        } else {
            cout << "Error: Line not found" << endl;
        }

        numLines++; 
        }  
        file.close(); //closing the file
    } else {
        cout << ("File could not be opened");
    }
}

std::string Stc::getLineMap(std::string line) const {
    std::stringstream aux;
    if (line == "L1"){
        aux << "|| L1 Map: " << endl;
        aux << L1Stations.toString();
    } else if (line == "L2"){
        aux << "|| L2 Map: " << endl;
        aux << L2Stations.toString();
    } else if (line == "L3"){
        aux << "|| L3 Map: " << endl;
        aux << L3Stations.toString();
    } else if (line == "L4"){
        aux << "|| L4 Map: " << endl;
        aux << L4Stations.toString();
    } else if (line == "L5"){
        aux << "|| L5 Map: " << endl;
        aux << L5Stations.toString();
    } else if (line == "L6"){
        aux << "|| L6 Map: " << endl;
        aux << L6Stations.toString();
    } else if (line == "L7"){
        aux << "|| L7 Map: " << endl;
        aux << L7Stations.toString();
    } else if (line == "L8"){
        aux << "|| L8 Map: " << endl;
        aux << L8Stations.toString();
    } else if (line == "L9"){
        aux << "|| L9 Map: " << endl;
        aux << L9Stations.toString();
    } else if (line == "LA"){
        aux << "|| LA Map: " << endl;
        aux << LAStations.toString();
    } else if (line == "LB"){
        aux << "|| LB Map: " << endl;
        aux << LBStations.toString();
    } else if (line == "L12"){
        aux << "|| L12 Map: " << endl;
        aux << L12Stations.toString();
    } else {
        cout << "Error: Line not found" << endl;
    }
    return aux.str();
}

void Stc::loadGraph(std::vector<std::vector<int>> data, int a) {
    graph.loadGraphMat(data, a, a);
    graph.loadGraphList(data, a);
    //cout << graph.printAdjMat();
}

std::string Stc::findPath(int start, int end) {
    std::stringstream aux;
    aux << graph.BFS(start, end);

    return aux.str();
}

void Stc::loadLocations(std::string fileName){
    std::string name;
    std::string code;

    int numLines = 0; //number of lines
    ifstream file(fileName); //opening the file.

    //checking if the file is open
    if (file.is_open()){
        //while the file is not at the end of the file
        while(!file.eof()){
            //reading the file
            getline(file, name, '\t');
            getline(file, code, '\n'); //new line
        
        //adding the station to the DList depending on which line it belongs to
        locationCode.push_back(make_pair(name, stoi(code)));
        locationArray[stoi(code)] = name;
        //cout << "Array index: " << stoi(code) << " with name: " << locationArray[stoi(code)] << endl;
        //cout << locationCode[numLines].first << " " << locationCode[numLines].second << endl;

        numLines++; 
        }  
        file.close(); //closing the file
    } else {
        cout << ("File could not be opened");
    }
    

}

std::string Stc::printPath(const std::string& path) {
    std::stringstream aux;
    int temp;
    int pos = path.find("path: ")+6;
    aux << "[ ";
    for(int i = pos; i < path.size(); i++){
        if (path[i] == ' '){
            aux << " ";
        } else {
            temp = path[i] - '0';
            if (path[i+1] != ' '){
                temp = temp*10 + (path[i+1] - '0');
                i++;
            }
            aux << locationArray[temp] << " --> ";
        }  
    }
    aux << "ARRIVED";
    aux << " ]";
    return aux.str();

}

std::string Stc::getShortestPath(std::string stationA, std::string stationB) {
    //use locationCode to find the code of the station and use printPath to print the path
    std::stringstream aux;
    int codeA;
    int codeB;
    for (int i = 0; i < locationCode.size(); i++){
        if (locationCode[i].first == stationA){
            codeA = locationCode[i].second;
            //cout << "Code A: " << codeA << endl;
        }
        if (locationCode[i].first == stationB){
            codeB = locationCode[i].second;
            //cout << "Code B: " << codeB << endl;
        }
    }
    aux << printPath(findPath(codeA, codeB));
    return aux.str();
}


#endif /* Stc_H_ */
