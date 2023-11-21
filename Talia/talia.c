#include <stdio.h>
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
