/*
 * Station.h
 *
 *  Created on: 14/10/2023
 *      Author: ricard
 */

#ifndef STATION_H_
#define STATION_H_

#include "exception.h"
#include "Line.h"

#include <vector>
#include <list>
#include <string>


class Station {
    private:
        std::string name;
        std::string line;
        std::string icon;
        bool conection;
        std::string location;

    public:
        //Constructors
        //Default constructor
        Station();
        //Constructor with parameters
        Station(std::string, std::string,std::string, bool, std::string);
        //Copy constructor
        Station(const Station &s);

        //Getters
        std::string getName() const {return name;}
        std::string getLine() const {return line;}
        std::string getIcon() const {return icon;}
        bool getConection() const {return conection;}
        std::string getLocation() const {return location;}

        //Setters
        void setName(std::string name) {this->name = name;}
        void setLine(std::string line) {this->line = line;}
        void setIcon(std::string icon) {this->icon = icon;}
        void setConection(bool conection) {this->conection = conection;}
        void setLocation(std::string location) {this->location = location;}

};

Station::Station() {
    name = "";
    line = "";
    icon = "";
    conection = false;
    location = "";
}

Station::Station( std::string name, std::string line ,std::string icon, bool conection, std::string location) {
    this->name = name;
    this->line = line;
    this->icon = icon;
    this->conection = conection;
    this->location = location;

}

Station::Station(const Station &s) {
    name = s.name;
    line = s.line;
    icon = s.icon;
    conection = s.conection;
    location = s.location;
}

#endif /* STATION_H_ */
