#ifndef CELL_H
#define CELL_H


enum CellState
{
	EMPTY = 0,
	TREE = 1,
	FIRE = 2,
	BORDER = 3
};


class Cell
{
public:
	explicit Cell(void);
	explicit Cell(const int x, const int y, const CellState state);

	int GetX(void) const;
	int GetY(void) const;

	CellState GetState(void) const;

	void SetX(const int x);
	void SetY(const int y);
	void SetState(const CellState state);

private:
	int x;
	int y;
	CellState state;
};

#endif