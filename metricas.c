#include "metricas.h"
// Funcion entrega la pizza mas vendida
char* pizza_mas_vendida(int *size, struct order *orders) {
    static char result[100];
    struct pizza_count {
        char pizza_name[100];
        int total_quantity;
    };
    
    struct pizza_count pizza_counts[100];
    int pizza_count_size = 0;
    
    for (int i = 0; i < *size; i++) {
        int found = 0;
        for (int j = 0; j < pizza_count_size; j++) {
            if (strcmp(pizza_counts[j].pizza_name, orders[i].pizza_name) == 0) {
                pizza_counts[j].total_quantity += orders[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(pizza_counts[pizza_count_size].pizza_name, orders[i].pizza_name, sizeof(pizza_counts[pizza_count_size].pizza_name));
            pizza_counts[pizza_count_size].total_quantity = orders[i].quantity;
            pizza_count_size++;
        }
    }

    int max_quantity = 0;
    char most_sold_pizza[100] = "";
    for (int i = 0; i < pizza_count_size; i++) {
        if (pizza_counts[i].total_quantity > max_quantity) {
            max_quantity = pizza_counts[i].total_quantity;
            strncpy(most_sold_pizza, pizza_counts[i].pizza_name, sizeof(most_sold_pizza));
        }
    }

    snprintf(result, sizeof(result), "Pizza más vendida: %s", most_sold_pizza);
    return result;
}
// Funcion que entrega la pizza menos vendida
char* pizza_menos_vendida(int *size, struct order *orders) {
    static char result[100];
    int min_quantity = orders[0].quantity;
    char least_sold_pizza[100] = "";
    strncpy(least_sold_pizza, orders[0].pizza_name, sizeof(least_sold_pizza));

    for (int i = 1; i < *size; i++) {
        if (orders[i].quantity < min_quantity) {
            min_quantity = orders[i].quantity;
            strncpy(least_sold_pizza, orders[i].pizza_name, sizeof(least_sold_pizza));
        }
    }

    snprintf(result, sizeof(result), "Pizza menos vendida: %s", least_sold_pizza);
    return result;
}

// Funcion que devuelve la fecha con mas ingresos de dinero
char* fecha_mas_ventas_dinero(int *size, struct order *orders) {
    static char result[200]; // Aseguramos espacio suficiente para la salida
    float max_revenue = 0;
    char max_revenue_date[20] = "";

    struct date_sales {
        char date[20];
        float total_sales;
    };

    struct date_sales sales[100];
    int sales_size = 0;

    // Recorrer todas las órdenes y acumular ventas por fecha
    for (int i = 0; i < *size; i++) {
        int found = 0;
        for (int j = 0; j < sales_size; j++) {
            if (strcmp(sales[j].date, orders[i].order_date) == 0) {
                sales[j].total_sales += orders[i].total_price;
                found = 1;
                break;
            }
        }
        if (!found) {
            // Si no se encontró la fecha, agregarla a la lista
            strncpy(sales[sales_size].date, orders[i].order_date, sizeof(sales[sales_size].date));
            sales[sales_size].total_sales = orders[i].total_price;
            sales_size++;
        }
    }

    // Buscar la fecha con más ventas
    for (int i = 0; i < sales_size; i++) {
        if (sales[i].total_sales > max_revenue) {
            max_revenue = sales[i].total_sales;
            strncpy(max_revenue_date, sales[i].date, sizeof(max_revenue_date));
        }
    }

    snprintf(result, sizeof(result), "Fecha con más ventas en dinero: %s con $%.2f", max_revenue_date, max_revenue);
    return result;
}
// Funcion que devuelve la fecha con menos ingresos de dinero
char* fecha_menos_ventas_dinero(int *size, struct order *orders) {
    static char result[200]; 
    float min_revenue = 99999999.99; 
    char min_revenue_date[20] = "";

    struct date_sales {
        char date[20];
        float total_sales;
    };

    struct date_sales sales[100];
    int sales_size = 0;

    
    for (int i = 0; i < *size; i++) {
        int found = 0;
        for (int j = 0; j < sales_size; j++) {
            if (strcmp(sales[j].date, orders[i].order_date) == 0) {
                sales[j].total_sales += orders[i].total_price;
                found = 1;
                break;
            }
        }
        if (!found) {
            
            strncpy(sales[sales_size].date, orders[i].order_date, sizeof(sales[sales_size].date));
            sales[sales_size].total_sales = orders[i].total_price;
            sales_size++;
        }
    }

    
    for (int i = 0; i < sales_size; i++) {
        if (sales[i].total_sales < min_revenue) {
            min_revenue = sales[i].total_sales;
            strncpy(min_revenue_date, sales[i].date, sizeof(min_revenue_date));
        }
    }

    snprintf(result, sizeof(result), "Fecha con menos ventas en dinero: %s con $%.2f", min_revenue_date, min_revenue);
    return result;
}
// Funcion que devuelve la fecha con mas ventas
char* fecha_mas_ventas_cantidad(int *size, struct order *orders) {
    static char result[100];
    struct fecha_count {
        char order_date[20];
        int total_quantity;
    };

    struct fecha_count fechas[100];
    int fecha_count_size = 0;

   
    for (int i = 0; i < *size; i++) {
        int found = 0;
        for (int j = 0; j < fecha_count_size; j++) {
            if (strcmp(fechas[j].order_date, orders[i].order_date) == 0) {
                fechas[j].total_quantity += orders[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(fechas[fecha_count_size].order_date, orders[i].order_date, sizeof(fechas[fecha_count_size].order_date));
            fechas[fecha_count_size].total_quantity = orders[i].quantity;
            fecha_count_size++;
        }
    }

    
    int max_quantity = 0;
    char max_quantity_date[20] = "";
    for (int i = 0; i < fecha_count_size; i++) {
        if (fechas[i].total_quantity > max_quantity) {
            max_quantity = fechas[i].total_quantity;
            strncpy(max_quantity_date, fechas[i].order_date, sizeof(max_quantity_date));
        }
    }

    snprintf(result, sizeof(result), "Fecha con más ventas en cantidad de pizzas: %s con %d pizzas", max_quantity_date, max_quantity);
    return result;
}
// Funcion que devuelve la fecha con menos ventas
char* fecha_menos_ventas_cantidad(int *size, struct order *orders) {
    static char result[100];
    struct fecha_count {
        char order_date[20];
        int total_quantity;
    };

    struct fecha_count fechas[100];
    int fecha_count_size = 0;

 
    for (int i = 0; i < *size; i++) {
        int found = 0;
        for (int j = 0; j < fecha_count_size; j++) {
            if (strcmp(fechas[j].order_date, orders[i].order_date) == 0) {
                fechas[j].total_quantity += orders[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
            strncpy(fechas[fecha_count_size].order_date, orders[i].order_date, sizeof(fechas[fecha_count_size].order_date));
            fechas[fecha_count_size].total_quantity = orders[i].quantity;
            fecha_count_size++;
        }
    }


    int min_quantity = fechas[0].total_quantity;
    char min_quantity_date[20] = "";
    strncpy(min_quantity_date, fechas[0].order_date, sizeof(min_quantity_date));

    for (int i = 1; i < fecha_count_size; i++) {
        if (fechas[i].total_quantity < min_quantity) {
            min_quantity = fechas[i].total_quantity;
            strncpy(min_quantity_date, fechas[i].order_date, sizeof(min_quantity_date));
        }
    }

    snprintf(result, sizeof(result), "Fecha con menos ventas en cantidad de pizzas: %s con %d pizzas", min_quantity_date, min_quantity);
    return result;
}
// Funcion que saca el promedio de pizzas por orden
char* promedio_pizzas_por_orden(int *size, struct order *orders) {
    static char result[100];
    int total_pizzas = 0;
    for (int i = 0; i < *size; i++) {
        total_pizzas += orders[i].quantity;
    }
    float average = (float)total_pizzas / *size;
    snprintf(result, sizeof(result), "Promedio de pizzas por orden: %.2f", average);
    return result;
}
// Funcion que saca el promedio de pizzas por dia
char* promedio_pizzas_por_dia(int *size, struct order *orders) {
    static char result[100];
    int total_pizzas = 0;
    int total_days = 0;
    char last_date[20] = "";
    for (int i = 0; i < *size; i++) {
        if (strcmp(orders[i].order_date, last_date) != 0) {
            total_days++;
            strncpy(last_date, orders[i].order_date, sizeof(last_date));
        }
        total_pizzas += orders[i].quantity;
    }
    float average = (float)total_pizzas / total_days;
    snprintf(result, sizeof(result), "Promedio de pizzas por día: %.2f", average);
    return result;
}


void trim_spaces_and_quotes(char *str) {
        int start = 0;
        int end = strlen(str) - 1;

       
        while (start <= end && isspace((unsigned char)str[start])) {
            start++;
        }

    
        while (end >= start && isspace((unsigned char)str[end])) {
            end--;
        }

      
        if (str[start] == '"') {
            start++;
        }
        if (str[end] == '"') {
            end--;
        }

     
        memmove(str, str + start, end - start + 1);
        str[end - start + 1] = '\0';  
    }
// Funcion para contar la cantidad de ingredientes totales entre todas las ordenes 
char* ingrediente_mas_vendido(int *size, struct order *orders) {
    static char result[100];

    
    struct ingredient_count {
        char ingredient[200];
        int total_count;
    };

    struct ingredient_count ingredients[100];
    int ingredient_count_size = 0;

  
    

   
    for (int i = 0; i < *size; i++) {
        
        char pizza_ingredients_copy[200]; 
        strncpy(pizza_ingredients_copy, orders[i].pizza_ingredients, sizeof(pizza_ingredients_copy)); 

       
        char *ingredient = strtok(pizza_ingredients_copy, ",");
        while (ingredient) {
            
            trim_spaces_and_quotes(ingredient);

            int found = 0;
           
            for (int j = 0; j < ingredient_count_size; j++) {
                if (strcmp(ingredients[j].ingredient, ingredient) == 0) {
                    
                    ingredients[j].total_count++;
                    found = 1;
                    break;
                }
            }

           
            if (!found) {
                
                strncpy(ingredients[ingredient_count_size].ingredient, ingredient, sizeof(ingredients[ingredient_count_size].ingredient));
                ingredients[ingredient_count_size].total_count = 1;
                ingredient_count_size++;
            }
            ingredient = strtok(NULL, ",");
        }
    }

    
    int max_count = 0;
    char most_sold_ingredient[200] = "";
    for (int i = 0; i < ingredient_count_size; i++) {
        if (ingredients[i].total_count > max_count) {
            max_count = ingredients[i].total_count;
            strncpy(most_sold_ingredient, ingredients[i].ingredient, sizeof(most_sold_ingredient));
        }
    }

    snprintf(result, sizeof(result), "Ingrediente más vendido: %s", most_sold_ingredient);
    return result;
}
// Funcion para contar la cantidad de pizzas que existen por categoria
char* cantidad_pizzas_por_categoria(int *size, struct order *orders) {
    static char result[500];
    result[0] = '\0'; 

    struct category_count {
        char category[20];
        int total_count;
    };

    struct category_count categories[100];
    int category_count_size = 0;

    
    for (int i = 0; i < *size; i++) {
        int found = 0;
        for (int j = 0; j < category_count_size; j++) {
            if (strcmp(categories[j].category, orders[i].pizza_category) == 0) {
                categories[j].total_count += orders[i].quantity;
                found = 1;
                break;
            }
        }
        if (!found) {
           
            strncpy(categories[category_count_size].category, orders[i].pizza_category, sizeof(categories[category_count_size].category));
            categories[category_count_size].total_count = orders[i].quantity;
            category_count_size++;
        }
    }


    for (int i = 0; i < category_count_size; i++) {
        char temp[100]; 
        snprintf(temp, sizeof(temp), "Categoria %s: %d pizzas\n", categories[i].category, categories[i].total_count);
        strncat(result, temp, sizeof(result) - strlen(result) - 1); 
    }

    return result;
}