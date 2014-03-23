#include "Grid.h"

/* --- IS --- */
bool isGridInfo_Same(GridInfo* gi_a, GridInfo* gi_b) {
	unsigned int i, length;
	length = (*gi_a).length;
	
	if((*gi_b).length != length)
		return false;
	
	for(i = 0; i < length; i++) {
		if((*gi_a).number[i] != (*gi_b).number[i])
			return false;
	}
	
	return true;
}

/*
	Checks if the GridInfo can still evolve to the master GridInfo
*/
bool isGridInfo_Correct(GridInfo* gi_master, GridInfo* gi_check) {
	unsigned int i, length;
	length = (*gi_check).length;
	
	if((*gi_master).length < length)
		return false;
	
	for(i = 0; i < length; i++) {
		if(i == (length - 1))
		{
			if((*gi_master).number[i] < (*gi_check).number[i])
				return false;
		} else {
			if((*gi_master).number[i] != (*gi_check).number[i])
				return false;
		}
	}
	
	return true;
}
