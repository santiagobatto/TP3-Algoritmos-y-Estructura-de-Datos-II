#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "array_helpers.h"

/* Menor temperatura minima historica*/
int get_min_temp_historic(WeatherTable a);
/* Mayor temperatura maxima durante un anio para cada anio*/
void get_max_temp(WeatherTable a, int max_temps[YEARS]);
/* Mayor cantidad mensual de precipitaciones por cada anio*/
void most_rainfalls(WeatherTable a, month_t most_rainfalls[YEARS]);

#endif