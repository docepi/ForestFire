#include "Controller.h"

#pragma region Constructors
Controller::Controller(void)
{
	weather = Weather();
	ground = Ground();
	wind = Wind();

	burnChance = weather.WeatherEffect();
	regeneration = ground.GroundEffect();
	frame = 0;
}
#pragma endregion Constructors

#pragma region Public Methods
void Controller::CreateGrid(void)
{
	int rowSize = grid.GetRowSize();
	int colSize = grid.GetColSize();

	for (int x = 0; x < rowSize; x++)
	{
		for (int y = 0; y < colSize; y++)
		{
			if (x == 0 || x == rowSize - 1) grid.SetCell(Cell(x, y, BORDER));
			else if (y == 0 || y == colSize - 1) grid.SetCell(Cell(x, y, BORDER));
			else grid.SetCell(Cell(x, y, TREE));
		}
	}
	grid.SetCell(Cell(10, 10, FIRE));
}

void Controller::UpdateGrid(void)
{
	frame = UpdateEnvironment(frame);
	if (isAllTrees()) spawnFire();

	for (int x = 1; x < grid.GetRowSize() - 1; x++)
	{
		for (int y = 1; y < grid.GetColSize() - 1; y++)
		{
			Cell cell = grid.GetCell(x, y);
			if (cell.GetState() == FIRE) fireCells.push_back(cell);
			else if (cell.GetState() == EMPTY) emptyCells.push_back(cell);
		}
	}

	spreadFire(fireCells);
	respawnTree(emptyCells);
	fireCells.clear();
	emptyCells.clear();
}

int Controller::UpdateEnvironment(int frame)
{
	bool enable = false;

	if (frame == 10)
	{
		if (GetWeather() == SUNNY && GetGround() != DRY) SetGround(DRY);
		else if (GetWeather() == RAINING && GetGround() != WET) SetGround(WET);
		else if (GetWeather() == CLEAR && GetGround() != NORMAL) SetGround(NORMAL);
	}

	if (frame == 20)
	{
		DynamicWeather();
		DynamicWind();
		frame = 0;
	}

	frame++;
	return frame;
}

void Controller::DynamicWeather()
{
	random = rand() % 3;
	WeatherType type = weather.GetWeatherType(random);
	SetWeather(type);
}

void Controller::DynamicWind()
{
	random = rand() % 8 + 1;
	WindDirection direction = wind.GetWindDirection(random);
	SetWindDirection(direction);
}

void Controller::SetWeather(const WeatherType& weatherType)
{
	this->weather.SetWeathertype(weatherType);
	burnChance = weather.WeatherEffect();
}

void Controller::SetGround(const GroundType& GroundType)
{
	this->ground.SetGroundType(GroundType);
	regeneration = ground.GroundEffect();
}

void Controller::SetWindDirection(const WindDirection& windDirection)
{
	this->wind.SetWindDirection(windDirection);
}

void Controller::SetGrid(const Grid& grid)
{
	this->grid = grid;
}

WeatherType Controller::GetWeather(void) const
{
	return weather.GetWeatherType();
}

GroundType Controller::GetGround(void) const
{
	return ground.GetGroundType();
}

WindDirection Controller::GetWind(void) const
{
	return wind.GetWindDirection();
}

Grid Controller::GetGrid(void) const
{
	return grid;
}

int Controller::Frame(void) const
{
	return frame;
}
#pragma endregion Public Methods

#pragma region Private Methods
bool Controller::isAllTrees(void)
{
	bool allTrees = true;

	for (int x = 1; x < grid.GetRowSize() - 1; x++)
	{
		for (int y = 1; y < grid.GetColSize() - 1; y++)
		{
			Cell cell = grid.GetCell(x, y);
			if (cell.GetState() == FIRE) allTrees = false;
		}
	}

	return allTrees;
}

void Controller::spreadFire(const std::vector<Cell>& cellList)
{
	Cell fireCell;
	std::vector<Cell> dirCell;

	for (int i = 0; i < cellList.size(); i++)
	{
		fireCell = cellList[i];
		dirCell = wind.WindEffect(fireCell, grid);

		for (int j = 0; j < dirCell.size(); j++)
		{
			Cell cell = dirCell[j];
			random = rand() % 100 + 1;

			if (cell.GetState() == TREE && random < (burnChance * 100)) cell.SetState(FIRE);
			grid.SetCell(cell);
		}

		fireCell.SetState(EMPTY);
		grid.SetCell(fireCell);
	}
}

void Controller::respawnTree(const std::vector<Cell>& cellList)
{
	Cell regenCell;

	for (int i = 0; i < cellList.size(); i++)
	{
		regenCell = cellList[i];
		random = rand() % 100 + 1;

		if (random < (regeneration * 100)) regenCell.SetState(TREE);
		grid.SetCell(regenCell);
	}
}

void Controller::spawnFire(void)
{
	for (int i = 0; i < 20; i++)
	{
		int x = random = rand() % 20 + 1;
		int y = random = rand() % 20 + 1;

		Cell cell = grid.GetCell(x, y);
		if (cell.GetState() == TREE) cell.SetState(FIRE);
		grid.SetCell(cell);
	}
}
#pragma endregion Private Methods