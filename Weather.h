#ifndef WEATHER_H
#define WEATHER_H

enum WeatherType
{
	CLEAR = 0,
	SUNNY = 1,
	RAINING = 2
};

class Weather
{
public:
	Weather(void);
	Weather(const WeatherType& weatherType);

	WeatherType GetWeatherType(void) const;
	WeatherType GetWeatherType(const int index) const;

	void SetWeathertype(const WeatherType& weatherType);
	float WeatherEffect(void);

private:
	WeatherType weatherType;
	float burnChance;
};

#endif
