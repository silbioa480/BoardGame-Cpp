#ifndef __C_PRINT_OMOK_H__
#define __C_PRINT_OMOK_H__
#include "CPrintNarrow.h"

class CPrintOmok : public CPrintNarrow
{
private:
	virtual void printUITop()
	{
		cout << " 0 1 2 3 4 5 6 7 8 9 a b c d e f";
		cout << "\n";
	}

public:
	CPrintOmok(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintNarrow(a_dat, a_nRowSize, a_nColSize) {};
};
#endif