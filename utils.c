#include "utils.h"

int leer_csv(const char *filename, struct order **orders) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("No se pudo abrir el archivo CSV");
        return -1;
    }

    char line[500];
    fgets(line, sizeof(line), file);

    int size = 0;
    while (fgets(line, sizeof(line), file)) {
        size++;
    }

    rewind(file);
    fgets(line, sizeof(line), file); 

    *orders = (struct order *)malloc(size * sizeof(struct order));
    if (!(*orders)) {
        perror("No se pudo asignar memoria");
        fclose(file);
        return -1;
    }

    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");

        (*orders)[i].pizza_id = atoi(token);
        token = strtok(NULL, ",");
        (*orders)[i].order_id = atoi(token);
        token = strtok(NULL, ",");
        strncpy((*orders)[i].pizza_name_id, token, sizeof((*orders)[i].pizza_name_id));
        token = strtok(NULL, ",");
        (*orders)[i].quantity = atoi(token);
        token = strtok(NULL, ",");
        strncpy((*orders)[i].order_date, token, sizeof((*orders)[i].order_date));
        token = strtok(NULL, ",");
        strncpy((*orders)[i].order_time, token, sizeof((*orders)[i].order_time));
        token = strtok(NULL, ",");
        (*orders)[i].unit_price = atof(token);
        token = strtok(NULL, ",");
        (*orders)[i].total_price = atof(token);
        token = strtok(NULL, ",");
        strncpy((*orders)[i].pizza_size, token, sizeof((*orders)[i].pizza_size));
        token = strtok(NULL, ",");
        strncpy((*orders)[i].pizza_category, token, sizeof((*orders)[i].pizza_category));
        token = strtok(NULL, "\"");
        if (token) {
            snprintf((*orders)[i].pizza_ingredients, sizeof((*orders)[i].pizza_ingredients), "\"%s\"", token);
        }
        token = strtok(NULL, "\n");


        if (token) {
            
            while (*token == ' ' || *token == ',') {
                token++;  
            }

            
            size_t len = strlen(token);
            if (len > 0 && token[len - 1] == '"') {
                token[len - 1] = '\0';  
            }

            if (token[0] == '"') {
                token++;  
            }

            snprintf((*orders)[i].pizza_name, sizeof((*orders)[i].pizza_name), "%s", token);
        }


        i++;
    }

    fclose(file);
    return size;
}
