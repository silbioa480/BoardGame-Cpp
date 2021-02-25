#ifndef __C_PRINT_BINGO_H__
#define __C_PRINT_BINGO_H__
#include "CPrintWide.h"

class CPrintBingo : public CPrintWide
{
private:

public:
	CPrintBingo(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintWide(a_dat, a_nRowSize, a_nColSize + 1) {}
};
#endif