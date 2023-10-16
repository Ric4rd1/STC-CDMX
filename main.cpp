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
#include "Stc.h"
//#include "dlist.h"

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

			//DList<int> list;
			/*
			cout << endl;
			cout << "Lines sorted by length in Km: " << endl;
			stc.sortLinesLength();
			stc.showLines();
			cout << endl;
			stc.showStations();
			*/
        }
};

int main (){
    SortsTest test;
    test.runTest();
	
    return 0;
}