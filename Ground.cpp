#include "Ground.h"

#pragma region Constructors
Ground::Ground(void)
{
	groundType = NORMAL;
}

Ground::Ground(const GroundType& groundType)
{
	this->groundType = groundType;
}
#pragma endregion Constructors

#pragma region Public Methods
GroundType Ground::GetGroundType(void) const
{
	return groundType;
}

void Ground::SetGroundType(const GroundType& groundType)
{
	this->groundType = groundType;
}

float Ground::GroundEffect(void)
{
	if (groundType == DRY)		regeneration = 0.25f;
	else if (groundType == NORMAL)	regeneration = 0.5f;
	else if (groundType == WET)		regeneration = 0.75f;
	return regeneration;
}
#pragma endregion Public Methods