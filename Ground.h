#ifndef GROUND_H
#define GROUND_H


enum GroundType
{
	DRY = 0,
	NORMAL = 1,
	WET = 2
};


class Ground
{
public:

	Ground(void);
	Ground(const GroundType& groundtype);

	float GroundEffect(void);

	GroundType GetGroundType(void) const;

	void SetGroundType(const GroundType& groundType);

private:
	GroundType groundType;
	float regeneration;
};

#endif
