/*#include <stdio.h>
int main() {
    int matrice[36][36];
    int a,b;
    FILE *file = fopen("exclusion.txt", "r");
    if (file == NULL) {
        printf("probleme dans le fichier\n");
        return 1;
    }
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < 36; j++) {
            matrice[i][j]=1; //remettre un -1
        }
    }
    for (int i = 0; i < 20; i++) {
        fscanf(file, "%d %d",&a,&b);
        matrice[a][b]=0;

    }
    for (int i = 1; i < 36; i++) {
        for (int j = 1; j < 36; j++) {
            printf("%d",matrice[i][j]);
        }
        printf("\n");
    }
    fclose(file);
    return 0;
}
*/
#include <stdio.h>

#define nomboperations 35
#define nombreexclusions 20

int main() {
    int couleurs[nomboperations + 1];
    for (int i = 0; i <= nomboperations; i++) {
        couleurs[i] = 0;
    }

    int maxcouleur = 0;

    int E[nombreexclusions][2];

    FILE *file = fopen("exclusion.txt", "r");
    if (file == NULL) {
        printf("probleme dans le fichier\n");
        return 1;
    }

    for (int i = 0; i < nombreexclusions; i++) {
        if (fscanf(file, "%d %d", &E[i][0], &E[i][1]) != 2) {
            printf("Probleme dans le fichier des exclusions %d\n", i);
            return 1;
        }
    }

    fclose(file);


    for (int operation = 1; operation <= nomboperations; operation++) {

        int couleurexclus[nomboperations + 1] = {0};
        for (int i = 0; i < nombreexclusions; i++) {
            if (E[i][0] == operation) {
                couleurexclus[couleurs[E[i][1]]] = 1;
            } else if (E[i][1] == operation) {
                couleurexclus[couleurs[E[i][0]]] = 1;
            }
        }


        int couleur;
        for (couleur = 1; couleur <= maxcouleur ; couleur++) {
            if (!couleurexclus[couleur]) {
                break;
            }
        }
        if (couleur > maxcouleur) {
            maxcouleur = couleur;
        }
        couleurs[operation] = couleur;
    }

    for (int operation = 1; operation <= nomboperations; operation++) {
        printf("Operation %d: Station %d\n", operation, couleurs[operation]);
    }

    return 0;
}
