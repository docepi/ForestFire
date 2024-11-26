#ifndef WIND_H
#define WIND_H

#include "Cell.h"
#include "Grid.h"
#include <vector>

enum WindDirection
{
	NORTH = 1,
	EAST = 2,
	SOUTH = 3,
	WEST = 4,
};


class Wind
{
public:

	Wind(void);
	Wind(const WindDirection& windDirection);

	WindDirection GetWindDirection(void) const;
	WindDirection GetWindDirection(const int index) const;

	void SetWindDirection(const WindDirection& windDirection);

	std::vector<Cell> WindEffect(const Cell& cell, const Grid& grid);

private:
	WindDirection windDirection;
};

#endif
