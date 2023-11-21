#include <stdio.h>
#include <stdlib.h>

#define nomboperations 35
#define nombreexclusions 20
#define MAX_PRECEDENCES 100

int main() {
    int couleurs[nomboperations + 1];
    for (int i = 0; i <= nomboperations; i++) {
        couleurs[i] = 0;
    }

    int E[nombreexclusions][2];

    FILE *exclusion_file = fopen("exclusion.txt", "r");
    if (exclusion_file == NULL) {
        printf("Probleme dans le fichier d'exclusions\n");
        return 1;
    }

    for (int i = 0; i < nombreexclusions; i++) {
        if (fscanf(exclusion_file, "%d %d", &E[i][0], &E[i][1]) != 2) {
            printf("Probleme dans le fichier des exclusions %d\n", i);
            return 1;
        }
    }

    fclose(exclusion_file);

    int precedences[MAX_PRECEDENCES][2];
    int num_precedences = 0;

    FILE *precedence_file = fopen("precedences.txt", "r");
    if (precedence_file == NULL) {
        printf("Probleme dans le fichier de precedences\n");
        return 1;
    }

    while (fscanf(precedence_file, "%d %d", &precedences[num_precedences][0], &precedences[num_precedences][1]) == 2) {
        num_precedences++;
    }

    fclose(precedence_file);

    int max_station = 0;

    for (int operation = 1; operation <= nomboperations; operation++) {
        int couleurexclus[nomboperations + 1] = {0};
        for (int i = 0; i < nombreexclusions; i++) {
            if (E[i][0] == operation) {
                couleurexclus[couleurs[E[i][1]]] = 1;
            } else if (E[i][1] == operation) {
                couleurexclus[couleurs[E[i][0]]] = 1;
            }
        }

        int min_station = 1;
        for (int j = 0; j < num_precedences; j++) {
            if (operation == precedences[j][1]) {
                int pred_station = couleurs[precedences[j][0]] + 1;
                if (pred_station > min_station) {
                    min_station = pred_station;
                }
            }
        }

        int couleur = min_station;
        if (couleur > max_station) {
            max_station = couleur;
        }
        couleurs[operation] = couleur;
    }

    for (int operation = 1; operation <= nomboperations; operation++) {
        printf("Operation %d: Station %d\n", operation, couleurs[operation]);
    }

    return 0;
}
