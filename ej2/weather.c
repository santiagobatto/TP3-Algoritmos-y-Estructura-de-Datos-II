/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ; // 6 variables in weather struct

Weather weather_from_file(FILE* file){
  Weather weather;

  if(file == NULL){
    fprintf(stderr, "Error: Archivo no valido\n");
    exit(EXIT_FAILURE);
  }  
  
  //uso & porque fscanf espera un puntero a la variable
  int res = fscanf(file, EXPECTED_WEATHER_FILE_FORMAT,
                   &weather._average_temp, &weather._max_temp,
                   &weather._min_temp, &weather._pressure,
                   &weather._moisture, &weather._rainfall
                  );
  
  if(res != AMOUNT_OF_WEATHER_VARS){
    fprintf(stderr, "Error: Cantidad de parametros invalido");
    exit(EXIT_FAILURE);
  }

  return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
