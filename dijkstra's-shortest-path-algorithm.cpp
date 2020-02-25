#include<bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define INF INT_MAX

int G[23][3] = {
	{1,8},
	{0,22},
	{3,7,22},
	{2,15},
	{6},
	{6,9},
	{4,5,7},
	{2,6,8},
	{0,7,9},
	{5,8,10},
	{9,11,20},
	{10,12,18},
	{11,13,19},
	{12,14,17},
	{13,15,16},
	{3,14},
	{14,17},
	{13,16,18},
	{11,17},
	{12,20},
	{10,19},
	{22},
	{1,2,21}
};

int W[23][3] = {
	{4,4},
	{4,4},
	{8,10,8},
	{8,12},
	{8},
	{16,12},
	{8,16,8},
	{10,8,12},
	{4,12,30},
	{12,30,12},
	{12,20,20},
	{20,8,28},
	{8,14,12},
	{14,4,14},
	{4,8,14},
	{12,8},
	{14,4},
	{14,4,8},
	{28,8},
	{12,20},
	{20,20},
	{14},
	{4,8,14}
};

int Deg[23] = {2,2,3,2,1,2,3,3,3,3,3,3,3,3,3,2,2,3,2,2,2,1,3};

int d[23];

typedef pair<int, int> node;

void ShortestPath(int [][3],char schar) {
	int s = -1;
	
	if (schar == 'A') {
		s = 0;
	}else if (schar == 'B'){
		s = 1;
	}else if (schar == 'C'){
		s = 2;
	}else if (schar == 'D'){
		s = 3;
	}else if (schar == 'E'){
		s = 4;
	}else if (schar == 'F'){
		s = 5;
	}else if (schar == 'G'){
		s = 6;
	}else if (schar == 'H'){
		s = 7;
	}else if (schar == 'I'){
		s = 8;
	}else if (schar == 'J'){
		s = 9;
	}else if (schar == 'K'){
		s = 10;
	}else if (schar == 'L'){
		s = 11;
	}else if (schar == 'M'){
		s = 12;
	}else if (schar == 'N'){
		s = 13;
	}else if (schar == 'O'){
		s = 14;
	}else if (schar == 'P'){
		s = 15;
	}else if (schar == 'Q'){
		s = 16;
	}else if (schar == 'R'){
		s = 17;
	}else if (schar == 'S'){
		s = 18;
	}else if (schar == 'T'){
		s = 19;
	}else if (schar == 'U'){
		s = 20;
	}else if (schar == 'V'){
		s = 21;
	}else if (schar == 'W'){
		s = 22;
	}else{
		s = -1;
	}
	
	if (s != -1){
	priority_queue<node, vector<node>, greater<node> > Q;
	for (int v = 0; v < 23; v++) {
		d[v] = INF;
	}
	d[s] = 0;
	Q.push(make_pair(s,d[s]));
	while (!Q.empty()) {
	    int u = Q.top().first;
	    Q.pop();
	    for (int a = 0; a < Deg[u]; a++) {
	        int v = G[u][a];
	        int weight = W[u][a];
	        if (d[v] > d[u] + weight) {
	            d[v] = d[u] + weight;
	            Q.push(make_pair(v,d[v]));
	        }
	    }
	}
	char min;
	if (d[0] > d[5] and d[5] > d[19]){
	    min = 'T';
	}else if (d[19] > d[0] and d[0] > d[5]){
	    min = 'F';
	}else{
	    min = 'A';
	}
	cout << "The distance of the source vertex " << schar << " from the exits are: " << endl;
	cout << "Exit A: " << d[0] << endl << "Exit F: " << d[5] << endl << "Exit T: " << d[19] << endl;
	cout << "The closest exit from the source vertex is: " << min << endl << endl;
	}else{
		cout << "***SOURCE VERTEX " << schar <<" DOESN'T EXIST IN THE GIVEN NETWORK***" << endl << endl;
	}
}

int main() {
	
	ShortestPath(G,'A');
	ShortestPath(G, 'Z');
	ShortestPath(G, 'M');
	ShortestPath(G, 'G');
	
	return 0;
}
