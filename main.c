// CALCOLATORE DETERMINANTE E RANGO MATRICE, CALCOLATORE INDIPENDENZA LINEARE DI VETTORI

#include <stdio.h>

int main() {
    int v1[2] = {2, 1};
    int v2[2] = {1, 1};
    int matrice[2][2];
    
    //scelgo valori dei vettori
    puts("Inserisci i valori del vettore v1:");
    scanf("%d %d", &v1[0], &v1[1]);
    puts("Inserisci i valori del vettore v2:");
    scanf("%d %d", &v2[0], &v2[1]);
    printf("I vettori sono: v1(%d,%d) v2(%d,%d)\n", v1[0], v1[1], v2[0], v2[1]);
    
    //inserisco vettori nella matrice
    for(size_t i=0; i<2; i++) //righe
    {
        matrice[i][0] = v1[i];
        matrice[i][1] = v2[i];
    }
    
    printf("La matrice e':\n| %d %d |\n| %d %d |\n", v1[0], v2[0], v1[1], v2[1]);
    
    //calcolo det
    int det;
    det = matrice[0][0]*matrice[1][1] - (matrice[0][1]*matrice[1][0]);
    printf("Il determinante e': %d", det);
    //calcolo rango

    return 0;
}