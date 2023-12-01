/*
 * 	tests.cpp
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
#include <fstream>
#include <algorithm>

#include "dlist.h"
#include "graphQ.h"
#include "unit.h"
#include "Stc.h"

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

class Test: public UnitTest {
    public:
        void runTest(){
			Stc stc;
			std::string ans;

			/* TEST 1*/
			std::cout << "\n" << "1.- Testing loadLines method..." << "\n";
			stc.loadLines("Lines.txt");
			std::cout << " #######SUCCESS#######\n";

			/* TEST 2*/
			std::cout << "\n" << "2.- Testing loadStations method..." << "\n";
			stc.loadStations("Stations.txt");
			std::cout << " #######SUCCESS#######\n";

			/* TEST 3*/
			ans = "Number of lines: 12\n\
L2 24 41 Azul 23431\n\
L4 10 14 Cian 10747\n\
L7 14 32 Naranja 18784\n\
L9 12 34 Cafe 15375\n\
L1 20 50 Rosa Mexicano 18828\n\
L8 19 30 Verde 20078\n\
LB 21 36 Verde y Gris 23722\n\
L5 13 25 Amarillo 15675\n\
L3 21 54 Verde Olivo 23609\n\
L12 20 30 Oro 25100\n\
L6 11 15 Rojo 13947\n\
LA 10 33 Morado 17192\n\
";
			cout << "\n" <<"3.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.linestoString() << "\n";
			cout <<	(!ans.compare(stc.linestoString()) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 4*/
			ans = "Number of lines: 12\n\
L4 10 14 Cian 10747\n\
L6 11 15 Rojo 13947\n\
L9 12 34 Cafe 15375\n\
L5 13 25 Amarillo 15675\n\
LA 10 33 Morado 17192\n\
L7 14 32 Naranja 18784\n\
L1 20 50 Rosa Mexicano 18828\n\
L8 19 30 Verde 20078\n\
L2 24 41 Azul 23431\n\
L3 21 54 Verde Olivo 23609\n\
LB 21 36 Verde y Gris 23722\n\
L12 20 30 Oro 25100\n\
";
			stc.sortLinesLength();
			cout << "\n" <<"4.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.linestoString() << "\n";
			cout <<	(!ans.compare(stc.linestoString()) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 5*/
			ans = "Ubicada en la Alcaldia Miguel Hidalgo.	";
			cout << "\n" <<"5.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getStationLocation("Tacubaya") << "\n";
			cout <<	(!ans.compare(stc.getStationLocation("Tacubaya")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 6*/
			ans = "L1";
			cout << "\n" <<"6.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getStationLine("Observatorio") << "\n";
			cout <<	(!ans.compare(stc.getStationLine("Observatorio")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 7*/
			ans = "L2";
			cout << "\n" <<"7.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getStationLine("Cuatro Caminos") << "\n";
			cout <<	(!ans.compare(stc.getStationLine("Cuatro Caminos")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 8*/
			ans = "Palacio";
			cout << "\n" <<"8.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getStationIcon("Bellas Artes") << "\n";
			cout <<	(!ans.compare(stc.getStationIcon("Bellas Artes")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 9*/
			bool ansBool = true;
			cout << "\n" <<"9.- EXPECTED\n" << ansBool << " \nPROGRAM\n" << stc.getStationConection("Tacubaya") << "\n";
			cout <<	(ansBool == stc.getStationConection("Tacubaya") ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 10*/
			ans = "| Name: Tacubaya\n\
| Line: L1\n\
| Icon: Jarron\n\
| Conection: 1\n\
| Location: Ubicada en la Alcaldia Miguel Hidalgo.	\n\
";
			cout << "\n" <<"10.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getStation("Tacubaya") << "\n";
			cout <<	(!ans.compare(stc.getStation("Tacubaya")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 11*/
			ans = "| Name: Viaducto\n\
| Line: L2\n\
| Icon: Trebol\n\
| Conection: 0\n\
| Location: Ubicada en la Alcadia Benito Juarez.	\n\
";
			cout << "\n" <<"11.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getStation("Viaducto") << "\n";
			cout <<	(!ans.compare(stc.getStation("Viaducto")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 12*/
			std::cout << "\n" << "12.- Testing loadStationDlist method..." << "\n";
			stc.loadStationDList("Stations.txt");
			std::cout << " #######SUCCESS#######\n";

			/* TEST 13*/
			ans = "|| L1 Map: \n\
#[Observatorio <-> Tacubaya <-> Juanacatlan <-> Chapultepec <-> Sevilla <-> Insurgentes <-> Cuautemoc <-> Balderas <-> Salto del Agua <-> Isabel la Catolica <-> Pino Suarez <-> Merced <-> Candelaria <-> San Lazaro <-> Moctezuma <-> Balbuena <-> Boulevard Puerto Aereo <-> Gomez Farias <-> Zaragoza <-> Pantitlan]#";
			cout << "\n" <<"13.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getLineMap("L1") << "\n";
			cout <<	(!ans.compare(stc.getLineMap("L1")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 14*/
			ans = "|| L2 Map: \n\
#[Cuatro Caminos <-> Panteones <-> Tacuba <-> Cuitlahuac <-> Popotla <-> Colegio Militar <-> Normal <-> San Cosme <-> Revolucion <-> Hidalgo <-> Bellas Artes <-> Allende <-> Zocalo/Tenochtitlan <-> Pino Suarez <-> San Antonio Abad <-> Chabacano <-> Viaducto <-> Xola <-> Villa de Cortes <-> Nativitas <-> Portales <-> Ermita <-> General Anaya <-> Tasquena]#";
			cout << "\n" <<"14.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.getLineMap("L2") << "\n";
			cout <<	(!ans.compare(stc.getLineMap("L2")) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");
			
			/* TEST 15*/
			std::cout << "\n" << "15.- Testing loadGraph 'g.txt'..." << "\n";
			//std::string g_input = "(0,1) (0,4) (1,2) (1,3) (3,6) (4,5)";
			std::vector<std::vector<int>> g_listInput = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {3, 6}, {4, 5}};
			stc.loadGraph(g_listInput, 7);
			std::cout << " #######SUCCESS#######\n";

			/* TEST 16*/
			ans = "visited: 0 1 4 2 3 5 6 path: 0 1 3 6";
			std::cout << "\n" << "16.- Testing findPath..." << "\n";
			cout << "16.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.findPath(0, 6) << "\n";
			cout <<	(!ans.compare(stc.findPath(0, 6)) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 17*/
			//insurgentes a revolución 6, 26
			std::cout << "\n" << "17.- Testing loadGraph 'stcGraph.txt'..." << "\n";
			//std::string input = "(1, 2) (2, 3) (3, 4) (4, 5) (5, 6) (6, 7) (7, 8) (8, 9) (9, 10) (10, 11) (11, 12) (12, 13) (13, 14) (14, 15) (15, 16) (16, 17) (17, 18) (18, 19) (19, 20) (20, 21) (21, 22) (22, 23) (23, 24) (24, 25) (25, 26) (26, 27) (27, 28) (28, 29) (29, 30) (30, 31) (31, 32) (32, 33) (33, 11) (11, 35) (35, 36) (36, 37) (37, 38) (38, 39) (39, 40) (40, 41) (41, 42) (42, 43) (43, 44) (45, 46) (46, 47) (47, 48) (48, 49) (49, 50) (50, 30) (30, 52) (52, 8) (8, 54) (54, 55) (55, 56) (56, 57) (57, 58) (58, 59) (59, 60) (60, 61) (61, 62) (62, 63) (63, 64) (64, 65)";
			std::vector<std::vector<int>> listInput = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15}, {15, 16}, {16, 17}, {17, 18}, {18, 19}, {19, 20}, {20, 21}, {21, 22}, {22, 23}, {23, 24}, {24, 25}, {25, 26}, {26, 27}, {27, 28}, {28, 29}, {29, 30}, {30, 31}, {31, 32}, {32, 33}, {33, 11}, {11, 35}, {35, 36}, {36, 37}, {37, 38}, {38, 39}, {39, 40}, {40, 41}, {41, 42}, {42, 43}, {43, 44}, {45, 46}, {46, 47}, {47, 48}, {48, 49}, {49, 50}, {50, 30}, {30, 52}, {52, 8}, {8, 54}, {54, 55}, {55, 56}, {56, 57}, {57, 58}, {58, 59}, {59, 60}, {60, 61}, {61, 62}, {62, 63}, {63, 64}, {64, 65}};
			stc.loadGraph(listInput, 70);
			std::cout << " #######SUCCESS#######\n";

			/* TEST 18*/
			ans = "visited: 6 5 7 4 8 3 9 52 54 2 10 30 55 1 11 29 31 50 56 12 33 35 28 32 49 57 13 36 27 48 58 14 37 26 path: 6 7 8 52 30 29 28 27 26";
			std::cout << "\n" << "18.- Testing findPath(6, 26)..." << "\n";
			//insurgentes a revolución 6, 26
			cout << "18.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.findPath(6, 26) << "\n";
			cout <<	(!ans.compare(stc.findPath(6, 26)) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 19*/
			ans = "[ Insurgentes -->  Cuautemoc -->  Balderas -->  Juarez -->  Hidalgo -->  Revolucion -->  San Cosme -->  Normal -->  Colegio Militar --> ARRIVED ]";
			std::cout << "\n" << "19.- Testing printPath(Insurgentes '6', Colegio Militar '26')..." << "\n";
			//insurgentes a revolución 6, 26
			cout << "19.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.printPath(stc.findPath(6, 26)) << "\n";
			cout <<	(!ans.compare(stc.printPath(stc.findPath(6, 26))) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");
			
			/* TEST 20*/
			ans = "visited: 55 54 56 8 57 7 9 52 58 6 10 30 59 5 11 29 31 50 60 4 12 33 path: 55 54 8 9 10 11 33";
			std::cout << "\n" << "20.- Testing findPath(Hospital General to Zocalo/Tenochtitlan)..." << "\n";
			//Hospital General to Zocalo 55, 33
			cout << "20.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.findPath(55, 33) << "\n";
			cout <<	(!ans.compare(stc.findPath(55, 33)) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 21*/
			ans = "[ Hospital General -->  Ninos Heroes/Poder Judicial CDMX -->  Balderas -->  Salto del Agua -->  Isabel la Catolica -->  Pino Suarez -->  Zocalo/Tenochtitlan --> ARRIVED ]";
			std::cout << "\n" << "21.- Testing printPath(Hospital General '55', Zocalo/Tenochtitlan '33')..." << "\n";
			//Hospital General to Zocalo 55, 33
			cout << "21.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.printPath(stc.findPath(55, 33)) << "\n";
			cout <<	(!ans.compare(stc.printPath(stc.findPath(55, 33))) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 22*/
			ans = "visited: 27 26 28 25 29 24 30 23 31 50 52 22 32 49 8 21 33 48 7 9 54 20 11 47 6 10 55 19 12 35 46 5 56 18 13 36 path: 27 28 29 30 31 32 33 11 35 36";
			std::cout << "\n" << "22.- Testing findPath(Normal '27', Chabacano '36')..." << "\n";
			//Normal to Chabacano 27, 36
			cout << "22.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.findPath(27, 36) << "\n";
			cout <<	(!ans.compare(stc.findPath(27, 36)) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

			/* TEST 23*/
			ans = "[ Normal -->  San Cosme -->  Revolucion -->  Hidalgo -->  Bellas Artes -->  Allende -->  Zocalo/Tenochtitlan -->  Pino Suarez -->  San Antonio Abad -->  Chabacano --> ARRIVED ]";
			std::cout << "\n" << "23.- Testing printPath(Normal to Chabacano)..." << "\n";
			//Normal to Chabacano 27, 36
			cout << "23.- EXPECTED\n" << ans << " \nPROGRAM\n" << stc.printPath(stc.findPath(27, 36)) << "\n";
			cout <<	(!ans.compare(stc.printPath(stc.findPath(27, 36))) ? " #######SUCCESS#######\n" : " #######FAIL#######\n");

        }
};

int main (){
    Test test;
    test.runTest();

	Stc stc;
	stc.loadLines("Lines.txt");
	stc.loadStations("Stations.txt");
	stc.loadStationDList("Stations.txt");

	ofstream outputFile;
	outputFile.open("output.txt");

	outputFile << "$$$--LOADED LINES--$$$"<< endl;
	outputFile << stc.linestoString2();
	outputFile << endl;

	outputFile << "$$$--SORTED BY NAME--$$$" << endl;
	stc.sortLinesName();
	outputFile << stc.linestoString2();
	outputFile << endl;

	outputFile << "$$$--SORTED BY LENGHT--$$$" << endl;
	stc.sortLinesLength();
	outputFile << stc.linestoString2();
	outputFile << endl;

	outputFile << "$$$--SORTED BY NUMBER OF STATIONS--$$$" << endl;
	stc.sortLinesNumStations();
	outputFile << stc.linestoString2();
	outputFile << endl;

	outputFile << "$$$--SORTED BY NUMBER OF TRAINS--$$$" << endl;
	stc.sortLinesNumTrains();
	outputFile << stc.linestoString2();
	outputFile << endl;

	outputFile << "$$$--L1 MAP--$$$" << endl;
	outputFile << stc.getLineMap("L1");
	outputFile << endl;

	outputFile << "$$$--L2 MAP--$$$" << endl;
	outputFile << stc.getLineMap("L2");
	outputFile << endl;

	outputFile << "$$$--L3 MAP--$$$" << endl;
	outputFile << stc.getLineMap("L3");
	outputFile << endl;

	outputFile << endl;

	outputFile << "$$$--OBTAINING INFO FROM: 'TACUBAYA' STATION--$$$" << endl;
	outputFile << stc.getStation("Tacubaya");
	outputFile << endl;

	outputFile << "$$$--OBTAINING INFO FROM: 'VIADUCTO' STATION--$$$" << endl;
	outputFile << stc.getStation("Viaducto");
	outputFile << endl;

	outputFile << "$$$--OBTAINING INFO FROM: 'BELLAS ARTES' STATION--$$$" << endl;
	outputFile << stc.getStation("Bellas Artes");
	outputFile << endl;

	outputFile << "$$$--OBTAINING INFO FROM: 'OBSERVATORIO' STATION--$$$" << endl;
	outputFile << stc.getStation("Observatorio");
	outputFile << endl;

	outputFile.close();
    return 0;
}
