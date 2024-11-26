#include "Controller.h"
#include "Renderer.h"

#include <iostream>
#include <string>

void Init(void);

int main(void)
{
	Init();
	return 0;
}

void Init(void)
{
	Grid grid = Grid(21, 21);
	Controller controller = Controller();
	Renderer renderer = Renderer(controller);
	std::string input;
	bool redraw = true;

	controller.SetGrid(grid);
	controller.CreateGrid();
	renderer.ChangeConsoleSize(800, 400);
	renderer.DisplayConditions();
	renderer.DisplayGrid(controller.GetGrid());

	while (redraw)
	{
		std::cout << "Press Enter" << std::endl;
		std::getline(std::cin, input);

		if (input != "") redraw = false;
		else
		{
			renderer.ClearScreen();
			controller.UpdateGrid();
			renderer.DisplayConditions();
			renderer.DisplayGrid(controller.GetGrid());
		}
	}
}
