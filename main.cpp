#include <stdlib.h>
#include <iostream>

#include "include/Grid.h"

using namespace std;

/* --- DRAW --- */
void drawGrid(Grid* g) {
	unsigned int i, j, length, horizontal_maxlength, vertical_maxlength;
	char* empty_space;
	bool* grid;
	GridInfo* gi;
	
	length = (*g).length;
	grid = (*g).data;
	horizontal_maxlength = getGrid_Horizontal_MaxLength(g);
	vertical_maxlength = getGrid_Vertical_MaxLength(g);
	
	//Init
	empty_space = (char*)calloc(horizontal_maxlength + 1, sizeof(char));
	for(i = 0; i < horizontal_maxlength; i++) {
		empty_space[i] = ' ';
	}
	empty_space[horizontal_maxlength] = '\0';
	
	//Info
	//cout << "Horizontal MaxLength = " << horizontal_maxlength << endl;
	//cout << "Vertical MaxLength = " << vertical_maxlength << endl;
	//cout << endl;
	
	//Draw Vertical
	for(i = 0; i < vertical_maxlength; i++) {
		cout << empty_space;
		for(j = 0; j < length; j++) {
			gi = &((*g).vertical[j]);
			if((*gi).length > i)
				cout << (*gi).number[i];
			else
				cout << " ";
		}
		cout << endl;
	}
	
	for(i = 0; i < length; i++) {
		//Draw Horizontal
		gi = &((*g).horizontal[i]);
		for(j = 0; j < horizontal_maxlength; j++) {
			if((*gi).length > j)
				cout << (*gi).number[j];
			else
				cout << " ";
		}
		
		//Draw Grid
		for(j = 0; j < length; j++) {
			if(grid[((i * length) + j)] == true)
				cout << "X";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void drawGridInfo(GridInfo* gi) {
	unsigned int i;
	for(i = 0; i < (*gi).length; i++) {
		cout << "gi.number[" << i << "] = " << (*gi).number[i] << endl;
	}
}

/* --- Main --- */
void initSettings(Grid* g) {
	unsigned int horizon_0[2] = {2, 1};
	unsigned int horizon_1[2] = {3, 1};
	unsigned int horizon_2[2] = {1, 3};
	unsigned int horizon_3[2] = {1, 2};
	unsigned int horizon_4[2] = {1, 1};
	
	setGrid_Horizontal_Info(g, 0, 2, horizon_0);
	setGrid_Horizontal_Info(g, 1, 2, horizon_1);
	setGrid_Horizontal_Info(g, 2, 2, horizon_2);
	setGrid_Horizontal_Info(g, 3, 2, horizon_3);
	setGrid_Horizontal_Info(g, 4, 2, horizon_4);
	
	unsigned int vertical_0[1] = {5};
	unsigned int vertical_1[1] = {2};
	unsigned int vertical_2[1] = {2};
	unsigned int vertical_3[1] = {2};
	unsigned int vertical_4[1] = {5};
	
	setGrid_Vertical_Info(g, 0, 1, vertical_0);
	setGrid_Vertical_Info(g, 1, 1, vertical_1);
	setGrid_Vertical_Info(g, 2, 1, vertical_2);
	setGrid_Vertical_Info(g, 3, 1, vertical_3);
	setGrid_Vertical_Info(g, 4, 1, vertical_4);
}

int main() {
	Grid g;
	GridInfo gi;
	
	try {
		//Init
		initGrid(&g, 5);
		initSettings(&g);
		
		//Solution
		unsigned int enable[16] = {
									0, 2, 4,
									5, 6, 7, 9,
									10, 12, 13, 14,
									15, 18, 19,
									20, 24 };
		setGrid_EnableFields(&g, 16, enable);
		
		if(isGrid_Solved(&g)) {
			cout << "Solved!" << endl;
		}
				
		//Draw
		drawGrid(&g);
		cout << endl;
		
		unsigned int i;
		for(i = 0; i < g.length; i++) {
			if(isGrid_Horizontal_Correct(&g, i))
				cout << "Horizontal Correct " << i << endl;
		}
		
		for(i = 0; i < g.length; i++) {
			if(isGrid_Vertical_Correct(&g, i))
				cout << "Vertical Correct " << i << endl;
		}
	}
	catch (Error_Grid error) {
		cout << "Grid error: " << error << endl;
	}
	catch (int error) {
		cout << "Unknown error: " << error << endl;
	}
	
	return 0;
}