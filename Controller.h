#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Cell.h"
#include "Grid.h"
#include "Weather.h"
#include "Ground.h"
#include "Wind.h"

#include <vector>

class Controller
{
public:
	Controller(void);

	void CreateGrid(void);
	void UpdateGrid(void);
	int UpdateEnvironment(int count);
	void DynamicWeather(void);
	void DynamicWind(void);
	void SetWeather(const WeatherType& weatherType);
	void SetGround(const GroundType& GroundType);
	void SetWindDirection(const WindDirection& windDirection);
	void SetGrid(const Grid& grid);

	WeatherType GetWeather(void) const;
	GroundType GetGround(void) const;
	WindDirection GetWind(void) const;
	Grid GetGrid(void) const;

	int Frame(void) const;

private:
	float regeneration;
	float burnChance;
	std::vector<Cell> fireCells;
	std::vector<Cell> emptyCells;
	int random;
	int frame;

	Cell burnDirection;
	Grid grid;
	Weather weather;
	Ground ground;
	Wind wind;

	bool isAllTrees(void);
	void spreadFire(const std::vector<Cell>& cellList);
	void respawnTree(const std::vector<Cell>& cellList);
	void spawnFire(void);
};

#endif