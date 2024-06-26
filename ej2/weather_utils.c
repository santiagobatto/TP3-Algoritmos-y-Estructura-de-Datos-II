#include "weather_utils.h"
#include <limits.h>// es para usar INT_MAX y INT_MIN que son los valores maximos y minimos de un int

/* Menor temperatura historica*/
int get_min_temp_historic(WeatherTable a){
    int res = INT_MAX;
    for(unsigned int i = 0; i < YEARS; i++){
        for(unsigned int j = january; j < MONTHS; j++){
            for(unsigned int k = 0; k < DAYS; k++){
                if(a[i][j][k]._min_temp < res){
                    res = a[i][j][k]._min_temp;
                }
            }
        } 
    }
    return res;
}

/* Mayor temperatura maxima durante un anio para cada anio*/
void get_max_temp(WeatherTable a, int max_temps[YEARS]){
    int aux = INT_MIN; 

    for(unsigned int i = 0; i < YEARS; i++){
        for(unsigned int j = january; j < MONTHS; j++){
            for(unsigned int k = 0; k < DAYS; k++){
                if(a[i][j][k]._max_temp > aux){
                    aux = a[i][j][k]._max_temp;
                }
            }
        } 
        max_temps[i] = aux;
        aux = INT_MIN;
    }
}

/* Mes del anio con mayor cantidad de precipitaciones por cada anio*/
void most_rainfalls(WeatherTable a, month_t most_rainfalls[YEARS]){
    unsigned int cont = 0;
    unsigned int rainfalls = 0; 
    month_t mes;

    for(unsigned int i = 0; i < YEARS; i++){
        for(unsigned int j = january; j < MONTHS; j++){
            for(unsigned int k = 0; k < DAYS; k++){
                cont = cont + a[i][j][k]._rainfall; //precipitaciones por dia
            }
            if (cont > rainfalls){
                rainfalls = cont; //si las precipitaciones de ese mes son mayores a las anteriores, se guardan
                mes = j; //se guarda el mes
            }
            cont = 0; //reset de precipitaciones mensuales
        }
        most_rainfalls[i] = mes;
        rainfalls = 0; //reset de precipitaciones anuales
    }
}