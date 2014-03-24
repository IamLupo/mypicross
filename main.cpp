#include <stdlib.h>
#include <iostream>

#include "include/Grid.h"
#include "include/Puzzle.h"

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
	
	//Space
	empty_space = (char*)calloc(horizontal_maxlength + 1, sizeof(char));
	for(i = 0; i < horizontal_maxlength; i++) {
		empty_space[i] = ' ';
	}
	empty_space[horizontal_maxlength] = '\0';
	
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

void drawGrid_Data(Grid* g) {
	unsigned int i, j, length;
	bool* grid;
	
	length = (*g).length;
	grid = (*g).data;
	
	for(i = 0; i < length; i++) {
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
int main() {
	Grid g;
	GridInfo gi;
	
	try {
		//Init
		loadPuzzle_5_3(&g);
		
		drawGrid(&g);
		cout << endl;
		
		if(solveGrid(&g)) {
			cout << "Solved!" << endl;
			drawGrid_Data(&g);
			cout << endl;
		} else {
			cout << "No solution Found!" << endl;
			cout << endl;
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