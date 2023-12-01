/*
 * 	main.cpp
 *
 *  Created on: 29/11/23
 *      Author: ric4rd
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <list>
#include <fstream>
#include <algorithm>

#include "dlist.h"
#include "unit.h"
#include "Stc.h"

int main(){
    Stc stc;
    
    //load data
    stc.loadLines("Lines.txt");
    stc.loadStations("Stations.txt");
    stc.loadStationDList("Stations.txt");
    std::vector<std::vector<int>> listInput = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {15, 16}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {26, 27}, {27, 28}, {28, 29}, {29, 30}, {30, 31}, {31, 32}, {32, 33}, {33, 11}, {11, 35}, {35, 36}, {36, 37}, {37, 38}, {38, 39}, {39, 40}, {40, 41}, {41, 42}, {42, 43}, {43, 44}, {45, 46}, {46, 47}, {47, 48}, {48, 49}, {49, 50}, {50, 30}, {30, 52}, {52, 8}, {8, 54}, {54, 55}, {55, 56}, {56, 57}, {57, 58}, {58, 59}, {59, 60}, {60, 61}, {61, 62}, {62, 63}, {63, 64}, {64, 65}};
    stc.loadGraph(listInput, 70);


    //1. print Data
    //  1.1 print lines
    //  1.2 print stations
    //  1.3 print stations in line
    //2. sort Data
    //3. search
    //4. get shortest path
    //5. exit
    
    cout << "|#| WELCOME TO THE MEXICO CITY METRO SYSTEM    |#|\n";
    cout << "|#| Developed by: Ricard Esteve Catala Garfias |#|\n";
    cout << "|#|               A01710071                    |#|\n";
    cout << "|#|                                            |#|\n";
    cout << "|#| IMPORTANT!!!                               |#|\n";
    cout << "|#| -This is a partial implementation of the   |#|\n";
    cout << "|#|  Mexico City Metro System                  |#|\n";
    cout << "|#|                                            |#|\n";
    cout << "|#| -The only lines functioning are L1, L2, L3 |#|\n";
    cout << "|#|                                            |#|\n";
    cout << "|#| -The program is CASE SENSITIVE             |#|\n";
    cout << "|#|                                            |#|\n";
    cout << "|#| -Do not use any accents or enie            |#|\n";
    int option = 0;
    while(option != 5){
        std::cout << "1. Print Data\n";
        std::cout << "2. Sort Data\n";
        std::cout << "3. Search Station/Line \n";
        std::cout << "4. Get shortest path [A --> B]\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter option: ";
        std::cin >> option;
        std::cout << "\n";
        
        if(option == 1){
        int option2 = 0;
        while(option2 != 4){
            std::cout << "1. Print Lines\n";
            std::cout << "2. Print Stations\n";
            std::cout << "3. Print Stations in Line\n";
            std::cout << "4. Back\n";
            std::cout << "Enter option: ";
            std::cin >> option2;
            std::cout << "\n";

            if(option2 == 1){
                std::cout << "Printing Lines...\n";
                std::cout << stc.linestoString2();
                std::cout << "\n";
            }
            else if(option2 == 2){
                std::cout << "Printing Stations...\n";
                std::cout << stc.stationsToString();
                std::cout << "\n";
            }
            else if(option2 == 3){
                std::cout << "Printing Stations in Line...\n";
                std::cout << "  [ L1, L2, L3 ]\n";
                std::cout << "Enter line name: ";
                std::string line;
                std::cin >> line;
                std::cout << "\n";
                std::cout << stc.getLineMap(line);
                std::cout << "\n\n";
                
            }
            else if(option2 == 4){
                std::cout << "Going back...\n";
            }
            else{
                std::cout << "Invalid option\n";
                std::cin.clear();
                while (std::cin.get() != '\n') {
                    continue;
                }
            }
        }
        }
        else if(option == 2){
            //sort by name, length, number of stations, number of trains
            int option2 = 0;
            while(option2 != 5){
                std::cout << "1. Sort by Name\n";
                std::cout << "2. Sort by Length\n";
                std::cout << "3. Sort by Number of Stations\n";
                std::cout << "4. Sort by Number of Trains\n";
                std::cout << "5. Back\n";
                std::cout << "Enter option: ";
                std::cin >> option2;
                std::cout << "\n";

                if(option2 == 1){
                    std::cout << "Sorting by Name...\n";
                    stc.sortLinesName();
                    cout << stc.linestoString2();
                    std::cout << "Sorted successfully\n";
                }
                else if(option2 == 2){
                    std::cout << "Sorting by Length...\n";
                    stc.sortLinesLength();
                    cout << stc.linestoString2();
                    std::cout << "Sorted successfully\n";
                }
                else if(option2 == 3){
                    std::cout << "Sorting by Number of Stations...\n";
                    stc.sortLinesNumStations();
                    cout << stc.linestoString2();
                    std::cout << "Sorted successfully\n";
                }
                else if(option2 == 4){
                    std::cout << "Sorting by Number of Trains...\n";
                    stc.sortLinesNumTrains();
                    cout << stc.linestoString2();
                    std::cout << "Sorted successfully\n";
                }
                else if(option2 == 5){
                    std::cout << "Going back...\n";
                }
                else{
                    std::cout << "Invalid option\n";
                    std::cin.clear();
                    while (std::cin.get() != '\n') {
                        continue;
                    }
                }
            }
 
        }
        else if(option == 3){
            int option2 = 0;
            while(option2 != 3){
                std::cout << "1. Search Line\n";
                std::cout << "2. Search Station\n";
                std::cout << "3. Back\n";
                std::cout << "Enter option: ";
                std::cin >> option2;
                std::cout << "\n";

                if (option2 == 1){
                    std::cout << "Searching Line...\n";
                    std::cout << "  [ L1, L2, L3 ]\n";
                    std::cout << "Enter line number: ";
                    std::string line;
                    std::cin >> line;
                    std::cout << "\n";
                    std::cout << stc.getLineMap(line);
                    std::cout << "\n\n";
                }
                else if (option2 == 2){
                    std::cout << "Searching Station...\n";
                    std::cout << "\n";
                    std::cout << "Enter station name (Example: 'Tacubaya'): ";
                    std::string station;
                    std::cin >> station;
                    std::cout << stc.getStation(station);
                    std::cout << "\n";
                }
                else if (option2 == 3){
                    std::cout << "Going back...\n";
                }
                else{
                    std::cout << "Invalid option\n";
                    std::cin.clear();
                    while (std::cin.get() != '\n') {
                        continue;
                    }
                }
            }
        }
        else if(option == 4){
            std::cout << "Getting shortest path...\n";
            std::cout << "Enter station A: ";
            std::string stationA;
            std::getline(std::cin, stationA);
            std::getline(std::cin, stationA);
            std::cout << "\n";
            std::cout << "Enter station B: ";
            std::string stationB;
            std::getline(std::cin, stationB);
            std::cout << "\n";
            cout << "|#| SHORTEST PATH |#|\n";
            std::cout << stc.getShortestPath(stationA, stationB) << "\n";
            std::cout << "\n";
        }
        else if(option == 5){
            std::cout << "Exiting...\n";
        }
        else{
            std::cout << "Invalid option\n";
            std::cin.clear();
            while (std::cin.get() != '\n') {
                continue;
            }
        }
    }
    return 0;
}
