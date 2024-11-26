#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

class Grid
{
public:
	Grid(void);
	Grid(const int rows, const int columns);

	int GetRowSize(void) const;
	int GetColSize(void) const;

	Cell GetCell(const int x, const int y) const;

	void ResizeGrid(const int rows, const int columns);
	void SetCell(const Cell& cell);

private:
	int rowSize;
	int colSize;
	std::vector < std::vector<Cell> >grid;
};

#endif
