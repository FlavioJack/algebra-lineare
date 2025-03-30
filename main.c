// CALCOLATORE DETERMINANTE E RANGO MATRICE, CALCOLATORE INDIPENDENZA LINEARE DI VETTORI

#include <stdio.h>
#include <stdbool.h>

int determinant(size_t ordine, const int matrice[][ordine]);
bool check_ridotta(size_t ordine, const int matrice[][ordine]);
//int count_pivot(const int matrice[][2]);


int main() {

    int order;
    do
    {
        puts("Inserisci ordine matrice 2 o 3:");
        scanf("%d", &order);
    }
    while(!(order == 2 || order == 3));

    // inserzione valori matrice
    int matrix[order][order];
    puts("| INSERISCI I VALORI DELLA MATRICE |");
    for(size_t i=0; i<order; i++)
    {
        printf("Inserisci i valori della riga %zu\n", i+1);
        for(size_t j=0; j<order; j++)
        {
            scanf("%d", &matrix[i][j]);
        }  
    }
    puts("");

    // stampa la matrice sul terminale
    for(size_t i=0; i<order; i++)
    {
        for(size_t j=0; j<order; j++)
        {
            printf("%3d ", matrix[i][j]);
        }  
        puts("");
    }
    puts("");

    // calcolo determinante
    printf("Il determinante e': %d\n", determinant(order, matrix));
    check_ridotta(order, matrix);
/*
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

    */
    return 0;
}


int determinant(size_t ordine, const int matrice[][ordine])
{
    if(ordine==2)
    {
        return matrice[0][0]*matrice[1][1] - (matrice[0][1]*matrice[1][0]);
    }
    else if(ordine == 3)
    {
        int matriceSarrus[ordine][ordine+2];
        for(size_t i=0; i<ordine; i++)
        {
            for(size_t j=0; j<ordine; j++)
            {
                matriceSarrus[i][j] = matrice[i][j];
            }  
        }
        for(size_t l=0; l<ordine; l++)
        {
            for(size_t m=ordine, n=0; n<ordine; m++, n++)
            {
                matriceSarrus[l][m] = matrice[l][n];
            }
        }
        puts("La matrice costruita per Sarrus e': ");
        for(size_t i=0; i<ordine; i++)
        {
            for(size_t j=0; j<ordine+2; j++)
            {
                printf("%3d ", matriceSarrus[i][j]);
            }  
            puts("");
        }
        int a = matriceSarrus[0][0]*matriceSarrus[1][1]*matriceSarrus[2][2];
        int b = matriceSarrus[0][1]*matriceSarrus[1][2]*matriceSarrus[2][3];
        int c = matriceSarrus[0][2]*matriceSarrus[1][3]*matriceSarrus[2][4];
        int d = matriceSarrus[0][2]*matriceSarrus[1][1]*matriceSarrus[2][0];
        int e = matriceSarrus[0][3]*matriceSarrus[1][2]*matriceSarrus[2][1];
        int f = matriceSarrus[0][4]*matriceSarrus[1][3]*matriceSarrus[2][2];

        return a+b+c-d-e-f;
         
    }
    else
    {
        puts("Ordine non accettato.");
    }
}


bool check_ridotta(size_t ordine, const int matrice[][ordine])
{
    int previousPivot, actualPivot;

    for(size_t riga=0; riga<ordine; riga++)
    {
        for(size_t elemCol=0; elemCol<ordine; elemCol++)
        {
            if(matrice[riga][elemCol] != 0)
            {
                actualPivot = elemCol;
                if(actualPivot <= previousPivot && riga != 0)
                {
                    puts("La matrice non e' a scalini");
                    return false;
                }
                break;
            }
            previousPivot = actualPivot;
        }
        
        // condizione di stop è quando arriva a fondo array o quando trova elemento non nullo
    }
    puts("La matrice e' a scalini");
    return true;
}

/*
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

*/




