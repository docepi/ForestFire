#include "Renderer.h"
#include <iostream>

# pragma region Constructors
Renderer::Renderer(void)
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hwnd = GetConsoleWindow();
	if (hwnd != NULL) MoveWindow(hwnd, 0, 0, 800, 400, true);
}

Renderer::Renderer(Controller& Controller)
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hwnd = GetConsoleWindow();
	if (hwnd != NULL) MoveWindow(hwnd, 0, 0, 800, 400, true);
	this->controller = &Controller;
}
#pragma endregion Constructors

#pragma region Public Methods
void Renderer::ChangeConsoleSize(const int width, const int height)
{
	MoveWindow(hwnd, 0, 0, width, height, true);
}

void Renderer::DisplayConditions(void)
{
	displayWeather();
	displayGround();
	displayWindDirection();
	displayFrame();
}

void Renderer::DisplayGrid(const Grid& grid)
{
	std::cout << std::endl;

	for (int x = 0; x < grid.GetRowSize(); x++)
	{
		for (int y = 0; y < grid.GetColSize(); y++)
		{
			displayState(grid.GetCell(x, y));
		}
		std::cout << std::endl;
	}
}

void Renderer::ClearScreen(void)
{
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(consoleHandle, position);
}
#pragma endregion Public Methods

#pragma region Private Methods
void Renderer::displayState(const Cell& cell)
{
	ConsoleColour colour;

	switch (cell.GetState())
	{
	case EMPTY:
		std::cout << " ";
		break;
	case TREE:
		SetConsoleTextAttribute(consoleHandle, colour = GREEN);
		std::cout << "&";
		break;
	case FIRE:
		SetConsoleTextAttribute(consoleHandle, colour = RED);
		std::cout << "*";
		break;
	case BORDER:
		SetConsoleTextAttribute(consoleHandle, colour = WHITE);
		std::cout << "#";
		break;
	}
}

void Renderer::displayWeather(void)
{
	std::cout << "The weather is: ";

	switch (controller->GetWeather())
	{
	case CLEAR:		std::cout << "clear" << std::endl; break;
	case SUNNY:		std::cout << "sunny" << std::endl; break;
	case RAINING:	std::cout << "raining" << std::endl; break;
	}
}

void Renderer::displayGround(void)
{
	std::cout << "The ground is  ";

	switch (controller->GetGround())
	{
	case NORMAL:	std::cout << "normal" << std::endl; break;
	case DRY:		std::cout << "dry" << std::endl; break;
	case WET:		std::cout << "wet" << std::endl; break;
	}
}

void Renderer::displayWindDirection(void)
{
	std::cout << "The current wind direction is: ";

	switch (controller->GetWind())
	{
	case NORTH:			std::cout << "North" << std::endl; break;
	case EAST:			std::cout << "East" << std::endl; break;
	case SOUTH:			std::cout << "South" << std::endl; break;
	case WEST:			std::cout << "West" << std::endl; break;
	}
}

void Renderer::displayFrame(void)
{
	int count = controller->Frame();
	std::cout << "Current frame: " << count << ' ' << std::endl;
}
#pragma endregion Private Methods