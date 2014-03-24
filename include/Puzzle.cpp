#include "Puzzle.h"

//5x5 Grid
void loadPuzzle_5_1(Grid* g) {
	initGrid(g, 5);
	
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

void loadPuzzle_5_2(Grid* g) {
	initGrid(g, 5);
	
	unsigned int horizon_0[1] = {5};
	unsigned int horizon_1[1] = {1};
	unsigned int horizon_2[1] = {5};
	unsigned int horizon_3[1] = {1};
	unsigned int horizon_4[1] = {5};
	
	setGrid_Horizontal_Info(g, 0, 1, horizon_0);
	setGrid_Horizontal_Info(g, 1, 1, horizon_1);
	setGrid_Horizontal_Info(g, 2, 1, horizon_2);
	setGrid_Horizontal_Info(g, 3, 1, horizon_3);
	setGrid_Horizontal_Info(g, 4, 1, horizon_4);
	
	unsigned int vertical_0[1] = {5};
	unsigned int vertical_1[3] = {1, 1, 1};
	unsigned int vertical_2[3] = {1, 1, 1};
	unsigned int vertical_3[3] = {1, 1, 1};
	unsigned int vertical_4[3] = {1, 1, 1};
	
	setGrid_Vertical_Info(g, 0, 1, vertical_0);
	setGrid_Vertical_Info(g, 1, 3, vertical_1);
	setGrid_Vertical_Info(g, 2, 3, vertical_2);
	setGrid_Vertical_Info(g, 3, 3, vertical_3);
	setGrid_Vertical_Info(g, 4, 3, vertical_4);
}

void loadPuzzle_5_3(Grid* g) {
	initGrid(g, 5);
	
	unsigned int horizon_0[1] = {5};
	unsigned int horizon_1[2] = {1, 1};
	unsigned int horizon_2[2] = {1, 1};
	unsigned int horizon_3[2] = {1, 1};
	unsigned int horizon_4[1] = {5};
	
	setGrid_Horizontal_Info(g, 0, 1, horizon_0);
	setGrid_Horizontal_Info(g, 1, 2, horizon_1);
	setGrid_Horizontal_Info(g, 2, 2, horizon_2);
	setGrid_Horizontal_Info(g, 3, 2, horizon_3);
	setGrid_Horizontal_Info(g, 4, 1, horizon_4);
	
	unsigned int vertical_0[1] = {5};
	unsigned int vertical_1[2] = {1, 1};
	unsigned int vertical_2[2] = {1, 1};
	unsigned int vertical_3[2] = {1, 1};
	unsigned int vertical_4[1] = {5};
	
	setGrid_Vertical_Info(g, 0, 1, vertical_0);
	setGrid_Vertical_Info(g, 1, 2, vertical_1);
	setGrid_Vertical_Info(g, 2, 2, vertical_2);
	setGrid_Vertical_Info(g, 3, 2, vertical_3);
	setGrid_Vertical_Info(g, 4, 1, vertical_4);
}

//10x10 Grid
void loadPuzzle_10_1(Grid* g) {
	initGrid(g, 10);
	
	unsigned int horizon_0[1] = {2};
	unsigned int horizon_1[1] = {4};
	unsigned int horizon_2[1] = {6};
	unsigned int horizon_3[1] = {8};
	unsigned int horizon_4[1] = {10};
	unsigned int horizon_5[1] = {10};
	unsigned int horizon_6[1] = {10};
	unsigned int horizon_7[3] = {2, 2, 2};
	unsigned int horizon_8[1] = {2};
	unsigned int horizon_9[1] = {4};
	
	setGrid_Horizontal_Info(g, 0, 1, horizon_0);
	setGrid_Horizontal_Info(g, 1, 1, horizon_1);
	setGrid_Horizontal_Info(g, 2, 1, horizon_2);
	setGrid_Horizontal_Info(g, 3, 1, horizon_3);
	setGrid_Horizontal_Info(g, 4, 1, horizon_4);
	setGrid_Horizontal_Info(g, 5, 1, horizon_5);
	setGrid_Horizontal_Info(g, 6, 1, horizon_6);
	setGrid_Horizontal_Info(g, 7, 3, horizon_7);
	setGrid_Horizontal_Info(g, 8, 1, horizon_8);
	setGrid_Horizontal_Info(g, 9, 1, horizon_9);
	
	unsigned int vertical_0[1] = {3};
	unsigned int vertical_1[1] = {5};
	unsigned int vertical_2[1] = {6};
	unsigned int vertical_3[2] = {6, 1};
	unsigned int vertical_4[1] = {10};
	unsigned int vertical_5[1] = {10};
	unsigned int vertical_6[2] = {6, 1};
	unsigned int vertical_7[1] = {6};
	unsigned int vertical_8[1] = {5};
	unsigned int vertical_9[1] = {3};
	
	setGrid_Vertical_Info(g, 0, 1, vertical_0);
	setGrid_Vertical_Info(g, 1, 1, vertical_1);
	setGrid_Vertical_Info(g, 2, 1, vertical_2);
	setGrid_Vertical_Info(g, 3, 2, vertical_3);
	setGrid_Vertical_Info(g, 4, 1, vertical_4);
	setGrid_Vertical_Info(g, 5, 1, vertical_5);
	setGrid_Vertical_Info(g, 6, 2, vertical_6);
	setGrid_Vertical_Info(g, 7, 1, vertical_7);
	setGrid_Vertical_Info(g, 8, 1, vertical_8);
	setGrid_Vertical_Info(g, 9, 1, vertical_9);
}

//25x25 Grid
void loadPuzzle_25_1_1(Grid* g) {
	initGrid(g, 25);
	
	unsigned int horizon_0[1] = {0};
	unsigned int horizon_1[1] = {0};
	unsigned int horizon_2[1] = {2};
	unsigned int horizon_3[1] = {3};
	unsigned int horizon_4[1] = {2};
	unsigned int horizon_5[1] = {4};
	unsigned int horizon_6[1] = {5};
	unsigned int horizon_7[1] = {5};
	unsigned int horizon_8[1] = {6};
	unsigned int horizon_9[1] = {7};
	unsigned int horizon_10[2] = {1, 6};
	unsigned int horizon_11[2] = {1, 6};
	unsigned int horizon_12[2] = {2, 5};
	unsigned int horizon_13[2] = {3, 5};
	unsigned int horizon_14[3] = {13, 2, 5};
	unsigned int horizon_15[3] = {4, 7, 4};
	unsigned int horizon_16[3] = {3, 3, 3};
	unsigned int horizon_17[3] = {3, 1, 3};
	unsigned int horizon_18[3] = {4, 2, 2};
	unsigned int horizon_19[3] = {4, 5, 1};
	unsigned int horizon_20[2] = {5, 7};
	unsigned int horizon_21[3] = {6, 6, 2};
	unsigned int horizon_22[3] = {6, 5, 4};
	unsigned int horizon_23[3] = {5, 4, 5};
	unsigned int horizon_24[4] = {4, 4, 4, 2};
	
	setGrid_Horizontal_Info(g, 0, 1, horizon_0);
	setGrid_Horizontal_Info(g, 1, 1, horizon_1);
	setGrid_Horizontal_Info(g, 2, 1, horizon_2);
	setGrid_Horizontal_Info(g, 3, 1, horizon_3);
	setGrid_Horizontal_Info(g, 4, 1, horizon_4);
	setGrid_Horizontal_Info(g, 5, 1, horizon_5);
	setGrid_Horizontal_Info(g, 6, 1, horizon_6);
	setGrid_Horizontal_Info(g, 7, 1, horizon_7);
	setGrid_Horizontal_Info(g, 8, 1, horizon_8);
	setGrid_Horizontal_Info(g, 9, 1, horizon_9);
	setGrid_Horizontal_Info(g, 10, 2, horizon_10);
	setGrid_Horizontal_Info(g, 11, 2, horizon_11);
	setGrid_Horizontal_Info(g, 12, 2, horizon_12);
	setGrid_Horizontal_Info(g, 13, 2, horizon_13);
	setGrid_Horizontal_Info(g, 14, 3, horizon_14);
	setGrid_Horizontal_Info(g, 15, 3, horizon_15);
	setGrid_Horizontal_Info(g, 16, 3, horizon_16);
	setGrid_Horizontal_Info(g, 17, 3, horizon_17);
	setGrid_Horizontal_Info(g, 18, 3, horizon_18);
	setGrid_Horizontal_Info(g, 19, 3, horizon_19);
	setGrid_Horizontal_Info(g, 20, 2, horizon_20);
	setGrid_Horizontal_Info(g, 21, 3, horizon_21);
	setGrid_Horizontal_Info(g, 22, 3, horizon_22);
	setGrid_Horizontal_Info(g, 23, 3, horizon_23);
	setGrid_Horizontal_Info(g, 24, 4, horizon_24);
	
	unsigned int vertical_0[1] = {3};
	unsigned int vertical_1[1] = {5};
	unsigned int vertical_2[1] = {6};
	unsigned int vertical_3[2] = {6, 1};
	unsigned int vertical_4[1] = {10};
	unsigned int vertical_5[1] = {10};
	unsigned int vertical_6[2] = {6, 1};
	unsigned int vertical_7[1] = {6};
	unsigned int vertical_8[1] = {5};
	unsigned int vertical_9[1] = {3};
	
	setGrid_Vertical_Info(g, 0, 1, vertical_0);
	setGrid_Vertical_Info(g, 1, 1, vertical_1);
	setGrid_Vertical_Info(g, 2, 1, vertical_2);
	setGrid_Vertical_Info(g, 3, 2, vertical_3);
	setGrid_Vertical_Info(g, 4, 1, vertical_4);
	setGrid_Vertical_Info(g, 5, 1, vertical_5);
	setGrid_Vertical_Info(g, 6, 2, vertical_6);
	setGrid_Vertical_Info(g, 7, 1, vertical_7);
	setGrid_Vertical_Info(g, 8, 1, vertical_8);
	setGrid_Vertical_Info(g, 9, 1, vertical_9);
}
