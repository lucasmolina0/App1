#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct order {
    int pizza_id;
    int order_id;
    char pizza_name_id[50];
    int quantity;
    char order_date[20];
    char order_time[20];
    float unit_price;
    float total_price;
    char pizza_size[10];
    char pizza_category[20];
    char pizza_ingredients[200];
    char pizza_name[100];
};

int leer_csv(const char *filename, struct order **orders);

#endif
