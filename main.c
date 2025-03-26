#include "utils.h"
#include "metricas.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <archivo CSV> <metricas>\n", argv[0]);
        return 1;
    }

    struct order *orders;
    int size = leer_csv(argv[1], &orders);
    if (size == -1) {
        return 1;
    }

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "pms") == 0) {
            printf("%s\n", pizza_mas_vendida(&size, orders));
        } else if (strcmp(argv[i], "pls") == 0) {
            printf("%s\n", pizza_menos_vendida(&size, orders));
        } else if (strcmp(argv[i], "dms") == 0) {
            printf("%s\n", fecha_mas_ventas_dinero(&size, orders));
        } else if (strcmp(argv[i], "dls") == 0) {
            printf("%s\n", fecha_menos_ventas_dinero(&size, orders));
        } else if (strcmp(argv[i], "dmsp") == 0) {
            printf("%s\n", fecha_mas_ventas_cantidad(&size, orders));
        } else if (strcmp(argv[i], "dlsp") == 0) {
            printf("%s\n", fecha_menos_ventas_cantidad(&size, orders));
        } else if (strcmp(argv[i], "apo") == 0) {
            printf("%s\n", promedio_pizzas_por_orden(&size, orders));
        } else if (strcmp(argv[i], "apd") == 0) {
            printf("%s\n", promedio_pizzas_por_dia(&size, orders));
        } else if (strcmp(argv[i], "ims") == 0) {
            printf("%s\n", ingrediente_mas_vendido(&size, orders));
        } else if (strcmp(argv[i], "hp") == 0) {
            printf("%s\n", cantidad_pizzas_por_categoria(&size, orders));
        }
    }

    free(orders);
    return 0;
}