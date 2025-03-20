// CALCOLATORE DETERMINANTE E RANGO MATRICE, CALCOLATORE INDIPENDENZA LINEARE DI VETTORI

#include <stdio.h>
#include <stdbool.h>

int determinant(const int matrice[][2]);
bool check_ridotta(const int matrice[][2]);
int count_pivot(const int matrice[][2]);

int main() {
    int v1[2], v2[2];
    int matrice[2][2];
    
    puts("Inserisci i valori del vettore v1:"); // scelgo valori dei vettori
    scanf("%d %d", &v1[0], &v1[1]);
    puts("Inserisci i valori del vettore v2:");
    scanf("%d %d", &v2[0], &v2[1]);
    printf("I vettori sono: v1(%d,%d) v2(%d,%d)\n", v1[0], v1[1], v2[0], v2[1]);
    
    // inserisco vettori nella matrice
    for(size_t i=0; i<2; i++) 
    {
        matrice[i][0] = v1[i];
        matrice[i][1] = v2[i];
    }
    
    printf("La matrice e':\n| %d %d |\n| %d %d |\n", v1[0], v2[0], v1[1], v2[1]);
    
    //calcolo det
    printf("Il determinante e': %d\n", determinant(matrice));
    

    
    // CALCOLO RANGO

    // Creo una matrice copia dove salvo la nuova matrice a scalini
    int mRidotta[2][2];
    for(size_t i=0; i<2; i++)
    {
        for(size_t j=0; j<2; j++)
        {
            mRidotta[i][j] = matrice[i][j];
        }
    }

    // controllo se una delle due colonne e' nulla e l'altra no
    if( ((matrice[0][0] != 0 && matrice[1][0] != 0) && (matrice[0][1] == 0 && matrice[1][1] == 0)) || ((matrice[0][0] == 0 && matrice[1][0] == 0) && (matrice[0][1] != 0 && matrice[1][1] != 0)) )
    {
        puts("Rango = 1");
    }
    // se e' nulla
    else if(matrice[0][0] == 0 && matrice[0][1] == 0 && matrice[1][0] == 0 && matrice[1][1] == 0)
    {
        puts("La matrice e' nulla");
        puts("Rango = 0");
    }
    else if(check_ridotta(matrice))
    {
        puts("La matrice e' ridotta a scalini");
        puts("Rango = 2");
    }
    // se e' piena si riduce a scalini
    else
    {
        int alpha = -(matrice[1][0]/matrice[0][0]);
        mRidotta[1][0] = matrice[1][0] + (alpha*matrice[0][0]);  
        mRidotta[1][1] = matrice[1][1] + (alpha*matrice[0][1]);
        printf("La matrice ridotta e':\n| %d %d |\n| %d %d |\n", mRidotta[0][0], mRidotta[0][1], mRidotta[1][0], mRidotta[1][1]);
        printf("Rango = %d\n", count_pivot(mRidotta));
    }

    
    return 0;
}




int determinant(const int matrice[][2])
{
    int det;
    det = matrice[0][0]*matrice[1][1] - (matrice[0][1]*matrice[1][0]);
}

bool check_ridotta(const int matrice[][2])
{
    if(matrice[0][0] != 0 && matrice[1][0] == 0 && matrice[1][1] != 0)
    {
        return true;
    }
    else return false;
}

int count_pivot(const int matrice[][2])
{
    if(check_ridotta(matrice))
    {
        puts("La matrice e' ridotta a scalini");
        return 2;
    }
    else if(matrice[0][0] != 0)
    {
        return 1;
    }
}