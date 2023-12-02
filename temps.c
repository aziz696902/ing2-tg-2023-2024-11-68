#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERATIONS 100

typedef struct {
    int operation;
    float time;
} Operation;

int main() {
    Operation operations[MAX_OPERATIONS];
    int total_operations = 0;

    // Lecture du fichier operations.txt
    FILE *operations_file = fopen("operations.txt", "r");
    if (operations_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier operations.txt\n");
        return 1;
    }

    while (fscanf(operations_file, "%d %f", &operations[total_operations].operation, &operations[total_operations].time) == 2) {
        total_operations++;
    }
    fclose(operations_file);

    // Lecture du fichier temps_cycle.txt
    float temps_cycle;
    FILE *temps_cycle_file = fopen("temps_cycle.txt", "r");
    if (temps_cycle_file == NULL) {
        printf("Erreur lors de l'ouverture du fichier temps_cycle.txt\n");
        return 1;
    }

    fscanf(temps_cycle_file, "%f", &temps_cycle);
    fclose(temps_cycle_file);

    // Tri des opérations par temps d'exécution croissant
    for (int i = 0; i < total_operations - 1; i++) {
        for (int j = i + 1; j < total_operations; j++) {
            if (operations[i].time > operations[j].time) {
                Operation temp = operations[i];
                operations[i] = operations[j];
                operations[j] = temp;
            }
        }
    }

    // Répartition des opérations dans les stations en respectant le temps de cycle
    float stations[MAX_OPERATIONS] = {0};
    int num_stations = 0;
    int operation_station[MAX_OPERATIONS] = {0}; // Ajout d'un tableau pour stocker la station de chaque opération

    for (int i = 0; i < total_operations; i++) {
        int assigned = 0;
        for (int j = 0; j < num_stations; j++) {
            if (stations[j] + operations[i].time <= temps_cycle) {
                stations[j] += operations[i].time;
                operation_station[operations[i].operation] = j + 1; // Stockage de la station de l'opération
                printf("Operation %d attribue a la station %d\n", operations[i].operation, j + 1);
                assigned = 1;
                break;
            }
        }

        if (!assigned) {
            num_stations++;
            stations[num_stations - 1] = operations[i].time;
            operation_station[operations[i].operation] = num_stations; // Stockage de la station de l'opération
            printf("Operation %d attribue a la nouvelle station %d\n", operations[i].operation, num_stations);
        }
    }

    // Calcul et affichage de la durée totale des opérations dans chaque station
    printf("\nDuree totale des operations dans chaque station :\n");
    for (int i = 0; i < num_stations; i++) {
        printf("Station numero %d : %f\n", i + 1, stations[i]);
    }

    return 0;
}
