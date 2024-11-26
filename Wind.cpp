#include "Wind.h"

Wind::Wind(void)
{
	windDirection = NORTH;
}

Wind::Wind(const WindDirection& windDirection)
{
	this->windDirection = windDirection;
}

WindDirection Wind::GetWindDirection(void) const
{
	return windDirection;
}

WindDirection Wind::GetWindDirection(const int index) const
{
	switch (index)
	{
	case 1:	return NORTH;
	case 2: return EAST;
	case 3: return SOUTH;
	case 4: return WEST;
	default: return NORTH;
	}
}

void Wind::SetWindDirection(const WindDirection& windDirection)
{
	this->windDirection = windDirection;
}

std::vector<Cell> Wind::WindEffect(const Cell& cell, const Grid& grid)
{
	std::vector<Cell> neighbours(3);
	switch (windDirection)
	{
	case NORTH:
		neighbours[0] = grid.GetCell(cell.GetX() - 1, cell.GetY() - 1);
		neighbours[1] = grid.GetCell(cell.GetX() - 1, cell.GetY());
		neighbours[2] = grid.GetCell(cell.GetX() - 1, cell.GetY() + 1);
		return neighbours;

	case EAST:
		neighbours[0] = grid.GetCell(cell.GetX() - 1, cell.GetY() + 1);
		neighbours[1] = grid.GetCell(cell.GetX(), cell.GetY() + 1);
		neighbours[2] = grid.GetCell(cell.GetX() + 1, cell.GetY() + 1);
		return neighbours;

	case SOUTH:
		neighbours[0] = grid.GetCell(cell.GetX() + 1, cell.GetY() + 1);
		neighbours[1] = grid.GetCell(cell.GetX() + 1, cell.GetY());
		neighbours[2] = grid.GetCell(cell.GetX() + 1, cell.GetY() - 1);
		return neighbours;

	case WEST:
		neighbours[0] = grid.GetCell(cell.GetX() + 1, cell.GetY() - 1);
		neighbours[1] = grid.GetCell(cell.GetX(), cell.GetY() - 1);
		neighbours[2] = grid.GetCell(cell.GetX() - 1, cell.GetY() - 1);
		return neighbours;
	}
	return neighbours;
}