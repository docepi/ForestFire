#ifndef RENDERER_H
#define RENDERER_H

#include "Controller.h"
#include <Windows.h>


enum ConsoleColour
{
	GREEN = 10,
	RED = 12,
	WHITE = 15
};


class Renderer
{
public:

	Renderer(void);


	Renderer(Controller& controller);


	void ChangeConsoleSize(const int width, const int height);


	void DisplayConditions(void);


	void DisplayGrid(const Grid& grid);


	void ClearScreen(void);

private:
	Controller* controller;
	HANDLE consoleHandle;
	HWND hwnd;


	void displayState(const Cell& cell);


	void displayWeather(void);


	void displayGround(void);


	void displayWindDirection(void);


	void displayFrame(void);
};

#endif
