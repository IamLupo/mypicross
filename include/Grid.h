#ifndef H_GRID
#define H_GRID
	#include <stdlib.h>
	#include "GridInfo.h"

	enum Error_Grid {
						ERROR_GRID_LENGTH,
						ERROR_GRID_DATA,
						ERROR_GRID_HORIZONTAL,
						ERROR_GRID_VERTICAL,
						ERROR_GRID_INPUT_ID };
	
	struct Grid {
		GridInfo* horizontal;
		GridInfo* vertical;
		
		unsigned int length;
		bool* data;
	};
	
	/* --- INIT --- */
	void initGrid(Grid* g, unsigned int length);
	
	/* --- GET --- */
	void getGrid_Info(Grid* g, GridInfo* gi);
	void getGrid_Horizontal_Info(Grid* g, GridInfo* gi, unsigned int id);
	unsigned int getGrid_Horizontal_MaxLength(Grid* g);
	void getGrid_Vertical_Info(Grid* g, GridInfo* gi, unsigned int id);
	unsigned int getGrid_Vertical_MaxLength(Grid* g);
	
	/* --- SET --- */
	void setGrid_Horizontal_Info(Grid* g, unsigned int id, unsigned int length, unsigned int data[]);
	void setGrid_Vertical_Info(Grid* g, unsigned int id, unsigned int length, unsigned int data[]);
	void setGrid_EnableFields(Grid* g, unsigned int length, unsigned int data[]);
	
	/* --- IS --- */
	bool isGrid_Solved(Grid* g);
	bool isGrid_Horizontal_Correct(Grid* g, unsigned int id);
	bool isGrid_Horizontal_SolvedById(Grid* g, unsigned int id);
	bool isGrid_Vertical_Correct(Grid* g, unsigned int id);
	bool isGrid_Vertical_SolvedById(Grid* g, unsigned int id);
	
	/* --- SOLVE --- */
	void solverGrid(Grid* g);
	bool solverGrid_Generation(Grid* g, unsigned int level, unsigned int max_level, bool value);
	
#endif