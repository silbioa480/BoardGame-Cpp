#ifndef __C_PRINT_OTHELLO_H__
#define __C_PRINT_OTHELLO_H__
#include "CPrintWide.h"

class CPrintOthello : public CPrintWide
{
private:
	virtual void printUITop()
	{
		cout << "  0   1   2   3   4   5   6   7";
		cout << "\n";
	}

public:
	CPrintOthello(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintWide(a_dat, a_nRowSize + 1, a_nColSize + 1) {}
};
#endif