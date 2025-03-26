#ifndef METRICAS_H
#define METRICAS_H

#include "utils.h"

// Funciones de métricas

char* pizza_mas_vendida(int *size, struct order *orders);
char* pizza_menos_vendida(int *size, struct order *orders);
char* fecha_mas_ventas_dinero(int *size, struct order *orders);
char* fecha_menos_ventas_dinero(int *size, struct order *orders);
char* fecha_mas_ventas_cantidad(int *size, struct order *orders);
char* fecha_menos_ventas_cantidad(int *size, struct order *orders);
char* promedio_pizzas_por_orden(int *size, struct order *orders);
char* promedio_pizzas_por_dia(int *size, struct order *orders);
char* ingrediente_mas_vendido(int *size, struct order *orders);
void trim_spaces_and_quotes(char *str);
char* cantidad_pizzas_por_categoria(int *size, struct order *orders);

#endif
