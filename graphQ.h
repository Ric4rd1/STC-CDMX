/*
*  autor: Benjamin Valdes Aguirre
*  fecha: Diciembre 2020
*  programa: act 4.1 Implementacion Grafos
*  desc: estos programas son solciones parciales a algunos de
*  las actividades planteadas en el curso TC1031
*
*
*  Extiende este archivo para completar tu soución.
*
*	Ricard
*/

#ifndef Graph_H_
#define Graph_H_

#include <string>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;


class Graph {
private:
		int edgesList;
		int edgesMat;
		int nodes;
    vector<int> *adjList;
		int *adjMatrix;
		//vector<Type> *vect = new vector<Type>

public:
		Graph(int);
		Graph();
		
		void loadGraphMat(std::vector<std::vector<int>>, int, int);
		void loadGraphList(const std::vector<std::vector<int>>&, int);
		
		void addEdgeAdjMatrix(int, int);
		void addEdgeAdjList(int, int);
		
		string printAdjMat();
		string printAdjMat_clean();
		string printAdjList();
		
		bool contains(list<int>, int);
		void sortAdjList();

		string DFS(int, int);
		string depthHelper(int, int, stack<int>&, list<int>&, vector<vector<int>>&);
		string BFS(int, int);
		string breadthHelper(int, int, queue<int>&, list<int>&, vector<vector<int>>&);
		
		string print_visited(list<int>);
		string print_path(vector<vector<int>>&, int, int);
};

Graph::Graph() {
	edgesList = edgesMat = 0;
}

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for (int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = edgesMat = 0;
}


//load GraphMat considering the data is a string that can be 1 or 2 digits
//format example: int g_listInput = {{0,1},{0,4},{1,2},{1,3},{3,6},{4,5}};

void Graph::loadGraphMat(std::vector<std::vector<int>> data, int a, int b) {
    adjMatrix = new int[a * b];
    nodes = a;
    for (int i = 0; i < a * b; i++)
        adjMatrix[i] = 0;

    for (const auto& pair : data) {
        if (pair.size() >= 2) {
            int u = pair[0];
            //cout << u << endl;
            int v = pair[1];
            //cout << v << endl;
            //cout << "----------------" << endl;
            addEdgeAdjMatrix(u, v);
        }
    }
}




void Graph::loadGraphList(const std::vector<std::vector<int>>& data, int a) {
    adjList = new std::vector<int>[a];
    nodes = a;

    for (const auto& pair : data) {
        if (pair.size() >= 2) {
            int u = pair[0];
            int v = pair[1];
            addEdgeAdjList(u, v);
        }
    }

    sortAdjList();
}


/*
void Graph::loadGraphMat(string data, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
	int u, v, i = 0;
	while (i < data.size()) {
		u = (int)data[i+1] - 48;
		v = (int)data[i+3] - 48;
		i = i + 6;
		addEdgeAdjMatrix(u,v);
	}
}

void Graph::loadGraphList(string data, int a){
	adjList = new vector<int>[a];
	nodes = a;
	int u, v, i = 0;
	while ( i < data.size()) {
			u = (int)data[i+1] - 48;
			v = (int)data[i+3] - 48;
			i = i + 6;
			addEdgeAdjList(u,v);
	}
	sortAdjList();
}
*/


/*
void Graph::loadGraphMat(string name, int a, int b){
	adjMatrix = new int [a*b];
	nodes = a;
	for (int i = 0; i < a*b; i++)
		adjMatrix[i] = 0;
		string line;
		ifstream lee (name);
		int u, v;
		if (lee.is_open()){
			while (getline(lee, line)){
				u = stoi(line.substr(1,1));
				v = stoi(line.substr(4,1));
				addEdgeAdjMatrix(u,v);
			}
			lee.close(); // Closes the file
		} else {
			cout << "Unable to open file";
		}
}


void Graph::loadGraphList(string name, int a, int b){
	adjList = new vector<int>[a];
	nodes = a;
	string line;
	ifstream lee (name);
	int u, v;
	if (lee.is_open()){
		while (getline(lee, line)){
			u = stoi(line.substr(1,1));
			v = stoi(line.substr(4,1));
			addEdgeAdjList(u,v);
		}
		lee.close(); // Closes the file
	} else {
		cout << "Unable to open file";
	}
	sortAdjList();
}
*/





void Graph::addEdgeAdjMatrix(int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
    //cout << "edge added: " << u << " " << v << endl;
}

void Graph::addEdgeAdjList(int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}

bool Graph::contains(list<int> ls, int node){
		list<int>::iterator it;
		it = find(ls.begin(), ls.end(), node);
		if(it != ls.end())
			return true;
		else
			return false;
}

void Graph::sortAdjList(){
	for (int i = 0; i < nodes; i++){
		sort(adjList[i].begin(), adjList[i].end());
	}
}


string Graph::printAdjList(){
	  stringstream aux;
		for (int i = 0; i < nodes; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjList[i].size(); j ++){
							 aux << " " << adjList[i][j];
					}
	        aux << " ";
    }
		return aux.str();

}

string Graph::printAdjMat(){
	stringstream aux;
	for (int i = 0; i < nodes; i++){
	   for (int j = 0; j < nodes; j++){
			 aux << adjMatrix[i*nodes+j] << " ";
		 }
  }
	return aux.str();
}

string Graph::printAdjMat_clean(){
	stringstream aux;
	aux << "\n nodes \t|";
	for (int i = 0; i < nodes; i++){
			aux << "\t" << i ;
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
			aux << "____";
	}
	aux << "\n";
	for (int i = 0; i < nodes; i++){
		 aux << i << "\t|";
	   for (int j = 0; j < nodes; j++){
			 aux << "\t" << adjMatrix[i*nodes+j];
		 }
	   aux << "\n";
  }
	return aux.str();
}

string Graph::print_visited(list<int> q){
	stringstream aux;
	aux << "visited: ";
	while (!q.empty()){
		aux << q.front() << " ";
		q.pop_front();
    }
	return aux.str();
}

string Graph::print_path(vector<vector <int>> &path, int start, int goal){
	int node =  path[goal][0];
	stack<int> reverse;
	reverse.push(goal);
	stringstream aux;
	aux  << "path:";
	while (node != start) {
		reverse.push(node);
    	node = path[node][0];
    }
	reverse.push(start);
	while (!reverse.empty()) {
		aux << " " << reverse.top() ;
		reverse.pop();
    }
	return aux.str();
}

string Graph::DFS(int start, int goal){
	stack <int> st;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(1, -1));
	st.push(start);
	string ans = depthHelper(start, goal, st, visited, paths);
	ans = ans + print_path(paths, start, goal);
	return ans;
}

string Graph::depthHelper(int current, 
						  int goal, 
						  stack<int>& st, 
						  list<int>& visited, 
						  vector<vector<int>>& paths){
	if(current == goal){
		return print_visited(visited);
	} else if(st.empty()){
		return " node not found";
	} else {
		current = st.top();
		st.pop();
		visited.push_back(current);
		for (int i = 0; i < adjList[current].size(); i++)
			if (!contains(visited, adjList[current][i])){
				st.push(adjList[current][i]);
				paths[adjList[current][i]][0] = current;
			}
		return depthHelper(current, goal, st, visited, paths);
	}
}

string Graph::BFS(int start, int goal) {
	queue<int> qu;
	list<int> visited;
	vector<vector<int>> paths(nodes, vector<int>(1,0));
	qu.push(start);
	visited.push_back(start);
	string ans = breadthHelper(start, goal, qu, visited, paths);
	ans += print_path(paths, start, goal);
	return ans;
}

string Graph::breadthHelper(int current,
							int goal,
							queue<int> &qu,
							list<int> &visited,
							vector<vector<int>> &paths) {
	if (current == goal) {
		return print_visited(visited);
	} else if (!qu.empty()) {
		current = qu.front();
		qu.pop();
		for (int i = 0; i < adjList[current].size(); i++) {
			if (!contains(visited, adjList[current][i])) {
				qu.push(adjList[current][i]);
				visited.push_back(adjList[current][i]);
				paths[adjList[current][i]][0] = current;
				if (adjList[current][i] == goal) return print_visited(visited);
			}
		}
		return breadthHelper(current, goal, qu, visited, paths);
	}

	return " node not found";
}

#endif /* Graph_H_ */
