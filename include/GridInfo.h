#ifndef H_GRIDINFO
#define H_GRIDINFO
	enum GridInfoType { GRIDINFO_TYPE_HORIZONTAL = 0, GRIDINFO_TYPE_VERTICAL = 1 };

	struct GridInfo {
		//Input
		unsigned int id;
		GridInfoType type;
		
		//Output
		unsigned int length;
		unsigned int* number;
	};
	
	bool isGridInfo_Same(GridInfo* gi_a, GridInfo* gi_b);
	bool isGridInfo_Correct(GridInfo* gi_master, GridInfo* gi_check);
#endif