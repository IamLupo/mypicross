#include "Grid.h"

#include <iostream>
using namespace std;

/* --- INIT --- */
void initGrid(Grid* g, unsigned int length) {
	//Length
	if(length == 0 || length > 25)
		throw ERROR_GRID_LENGTH;
	else
		(*g).length = length;
	
	//Data
	(*g).data = (bool*)calloc((length * length), sizeof(bool));
	if((*g).data == NULL)
		throw ERROR_GRID_DATA;
	
	//Horizontal
	(*g).horizontal = (GridInfo*)calloc(length, sizeof(GridInfo));
	if((*g).horizontal == NULL)
		throw ERROR_GRID_HORIZONTAL;
	
	//Vertical	
	(*g).vertical = (GridInfo*)calloc(length, sizeof(GridInfo));
	if((*g).vertical == NULL)
		throw ERROR_GRID_VERTICAL;
}

/* --- GET --- */
void getGrid_Info(Grid* g, GridInfo* gi) {
	unsigned int i, id, count;
	bool empty;
	
	unsigned int length = (*g).length;
	bool* grid = (*g).data;
	
	//Get count lines in row
	count = 0;
	empty = true;
	for(i = 0; i < length; i++) {
		//Get id
		if((*gi).type == GRIDINFO_TYPE_HORIZONTAL)
			id = ((*gi).id * length) + i;
		else if((*gi).type == GRIDINFO_TYPE_VERTICAL)
			id = (i * length) + (*gi).id;
			
		//Check
		if(grid[id] == true && empty == true) {
			count++;
			empty = false;
		}
		else if(grid[id] == false && empty == false) {
			empty = true;
		}
	}
	(*gi).length = count;
	
	//reserve space
	(*gi).number = (unsigned int*)calloc(count, sizeof(unsigned int));
	
	//Get length of line(s)
	count = 0;
	empty = true;
	for(i = 0; i < length; i++) {
		//Get id
		if((*gi).type == GRIDINFO_TYPE_HORIZONTAL)
			id = ((*gi).id * length) + i;
		else if((*gi).type == GRIDINFO_TYPE_VERTICAL)
			id = (i * length) + (*gi).id;
		
		//Check
		if(grid[id] == true && empty == true) {
			empty = false;
			(*gi).number[count] = 1;
		}
		else if(grid[id] == true){
			(*gi).number[count] = (*gi).number[count] + 1;
		}
		else if(grid[id] == false && empty == false) {
			empty = true;
			count++;
		}
	}
}

void getGrid_Horizontal_Info(Grid* g, GridInfo* gi, unsigned int id) {
	if(id >= (*g).length)
		throw ERROR_GRID_INPUT_ID;

	(*gi).type = GRIDINFO_TYPE_HORIZONTAL;
	(*gi).id = id;
	getGrid_Info(g, gi);
}

unsigned int getGrid_Horizontal_MaxLength(Grid* g) {
	unsigned int i, j, length, max_length;
	GridInfo* gi;
	
	max_length = 0;
	length = (*g).length;
	
	for(i = 0; i < length; i++) {
		gi = &((*g).horizontal[i]);
		
		if((*gi).length > max_length)
			max_length = (*gi).length;
	}
	
	return max_length;
}

void getGrid_Vertical_Info(Grid* g, GridInfo* gi, unsigned int id) {
	if(id >= (*g).length)
		throw ERROR_GRID_INPUT_ID;
	
	(*gi).type = GRIDINFO_TYPE_VERTICAL;
	(*gi).id = id;
	getGrid_Info(g, gi);
}

unsigned int getGrid_Vertical_MaxLength(Grid* g) {
	unsigned int i, j, length, max_length;
	GridInfo* gi;
	
	max_length = 0;
	length = (*g).length;
	
	for(i = 0; i < length; i++) {
		gi = &((*g).vertical[i]);
		
		if((*gi).length > max_length)
			max_length = (*gi).length;
	}
	
	return max_length;
}

/* --- SET --- */
void setGrid_Horizontal_Info(Grid* g, unsigned int id, unsigned int length, unsigned int data[]) {
	unsigned int i;
	GridInfo* gi;
	
	if(id >= (*g).length)
		throw ERROR_GRID_INPUT_ID;
	
	//Get GridInfo
	gi = &((*g).horizontal[id]);
	(*gi).length = length;
	(*gi).number = (unsigned int*)calloc(length, sizeof(unsigned int));
	
	for(i = 0; i < length; i++) {
		(*gi).number[i] = data[i];
	}
}

void setGrid_Vertical_Info(Grid* g, unsigned int id, unsigned int length, unsigned int data[]) {
	unsigned int i;
	GridInfo* gi;
	
	if(id >= (*g).length)
		throw ERROR_GRID_INPUT_ID;
	
	//Get GridInfo
	gi = &((*g).vertical[id]);
	(*gi).length = length;
	(*gi).number = (unsigned int*)calloc(length, sizeof(unsigned int));
	
	for(i = 0; i < length; i++) {
		(*gi).number[i] = data[i];
	}
}

void setGrid_Field_Value(Grid* g, unsigned int id, bool value) {
	unsigned int length, max;
	
	length = (*g).length;
	max = length * length;
	
	if(id >= max)
		throw ERROR_GRID_INPUT_ID;
	
	(*g).data[id] = value;
}

void setGrid_EnableFields(Grid* g, unsigned int length, unsigned int data[]) {
	unsigned int i, id, max, g_length;
	
	g_length = (*g).length;
	max = g_length * g_length;
	
	for(i = 0; i < length; i++) {
		id = data[i];
		if(id >= max)
			throw ERROR_GRID_INPUT_ID;
		(*g).data[id] = true;
	}
}

/* --- IS --- */
bool isGrid_Solved(Grid* g) {
	unsigned int i, length;
	GridInfo* gi;
	
	length = (*g).length;
	
	//Horizontal
	for(i = 0; i < length; i++) {
		if(!isGrid_Horizontal_SolvedById(g, i))
			return false;
	}
	
	//Vertical
	for(i = 0; i < length; i++) {
		if(!isGrid_Vertical_SolvedById(g, i))
			return false;
	}
	
	return true;
}

bool isGrid_Horizontal_Correct(Grid* g, unsigned int id) {
	GridInfo* gi;
	GridInfo temp_gi;
		
	gi = &((*g).horizontal[id]);
	getGrid_Horizontal_Info(g, &temp_gi, id);
	
	if(!isGridInfo_Correct(gi, &temp_gi)) {
		return false;
	}
	
	return true;
}

bool isGrid_Horizontal_SolvedById(Grid* g, unsigned int id) {
	GridInfo* gi;
	GridInfo temp_gi;
		
	gi = &((*g).horizontal[id]);
	getGrid_Horizontal_Info(g, &temp_gi, id);
	
	if(!isGridInfo_Same(gi, &temp_gi))
		return false;
	
	return true;
}

bool isGrid_Vertical_Correct(Grid* g, unsigned int id) {
	GridInfo* gi;
	GridInfo temp_gi;
		
	gi = &((*g).vertical[id]);
	getGrid_Vertical_Info(g, &temp_gi, id);
	
	if(!isGridInfo_Correct(gi, &temp_gi))
		return false;
	
	return true;
}

bool isGrid_Vertical_SolvedById(Grid* g, unsigned int id) {
	GridInfo* gi;
	GridInfo temp_gi;
		
	gi = &((*g).vertical[id]);
	getGrid_Vertical_Info(g, &temp_gi, id);
	
	if(!isGridInfo_Same(gi, &temp_gi))
		return false;
	
	return true;
}

bool isGrid_Data_CheckByID(Grid* g, unsigned int id) {
	unsigned int length, x, y;
	
	length = (*g).length;
	x = ( id / length);
	y = ( id % length);
	
	//Horizontal
	if(y + 1 == length) {
		if(!isGrid_Horizontal_SolvedById(g, x))
			return false;
	} else {
		if(!isGrid_Horizontal_Correct(g, x))
			return false;
	}
	
	//Vertical
	if(x + 1 == length) {
		if(!isGrid_Vertical_SolvedById(g, y))
			return false;
	} else {
		if(!isGrid_Vertical_Correct(g, y))
			return false;
	}
	
	return true;
}

/* --- SOLVE --- */
bool solveGrid(Grid* g) {
	unsigned int length;
	
	length = (*g).length;
	
	if(solveGrid_Generation(g, 0, length * length))
		return true;
	
	return false;
}

bool solveGrid_Generation(Grid* g, unsigned int level, unsigned int max_level) {
	if(level == max_level) //Finished
		return isGrid_Solved(g);
	
	setGrid_Field_Value(g, level, true);
	if(isGrid_Data_CheckByID(g, level))
		if(solveGrid_Generation(g, level + 1, max_level))
			return true;
	
	setGrid_Field_Value(g, level, false);
	if(isGrid_Data_CheckByID(g, level))
		if(solveGrid_Generation(g, level + 1, max_level))
			return true;
	
	return false;
}

