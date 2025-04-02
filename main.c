// CALCOLATORE DETERMINANTE E RANGO MATRICE, CALCOLATORE INDIPENDENZA LINEARE DI VETTORI

#include <stdio.h>
#include <stdbool.h>

void print_matrix(size_t order, const int matrix[order][order]); 
int determinant(size_t order, const int matrice[order][order]);
bool check_ridotta(size_t order, const int matrice[order][order], int * countPivot);


int main() {
    int *countPivot_ptr;
    size_t order;

    do
    {
        puts("Inserisci ordine matrice 2 o 3:");
        scanf("%zu", &order);
    }
    while(!(order == 2 || order == 3));

    // Inserzione valori matrice
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

    // Stampa matrice
    print_matrix(order, matrix);

    // Calcolo determinante
    printf("Il determinante e': %d\n", determinant(order, matrix));

    // Calcolo rango
    // se la matrice e' ridotta allora il numerio di pivot corrisponde al numero del rango
    if(check_ridotta(order, matrix, countPivot_ptr)) 
    {
        printf("La matrice e' a scalini ed ha rango %d\n", *countPivot_ptr);
    }
    // else se la matrice non e' a scalini va ridotta a scalini e bisogna ricontrollare a quel punto il rango

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

void print_matrix(size_t order, const int matrix[order][order])
{
    // stampa la matrice sul terminale
    for(size_t rows=0; rows<order; rows++)
    {
        for(size_t cols=0; cols<order; cols++)
        {
            printf("%3d ", matrix[rows][cols]);
        }  
        puts("");
    }
    puts("");
}


int determinant(size_t order, const int matrice[order][order])
{
    if(order==2)
    {
        return matrice[0][0]*matrice[1][1] - (matrice[0][1]*matrice[1][0]);
    }
    else if(order == 3)
    {
        int matriceSarrus[order][order+2];
        for(size_t i=0; i<order; i++)
        {
            for(size_t j=0; j<order; j++)
            {
                matriceSarrus[i][j] = matrice[i][j];
            }  
        }
        for(size_t l=0; l<order; l++)
        {
            for(size_t m=order, n=0; n<order; m++, n++)
            {
                matriceSarrus[l][m] = matrice[l][n];
            }
        }
        
        puts("La matrice costruita per Sarrus e': ");
        for(size_t i=0; i<order; i++)
        {
            for(size_t j=0; j<order+2; j++)
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


bool check_ridotta(size_t order, const int matrice[order][order], int * countPivot)
{
    int previousPivot = -1; // assegnamo un valore tale che il confronto if(actualPivot <= previousPivot) e' sempre false 
    // questo perche' nel primo ciclo di controllo l'elemento di posto matrice[0][0] non puo' essere confrontato con nessun altro pivot precedente essendo il primo
    int actualPivot;
    *countPivot = 0; // reset pivot count

    for(size_t riga=0; riga<order; riga++)
    {
        for(size_t elemCol=0; elemCol<order; elemCol++)
        {
            if(matrice[riga][elemCol] != 0)
            {
                actualPivot = elemCol;
                if(actualPivot <= previousPivot)
                {
                    return false;
                    puts("La matrice non e' a scalini");
                }
                else 
                {
                    (*countPivot)++;
                    previousPivot = actualPivot;
                }
                break;
            }
        }
        // condizione di stop è quando arriva a fondo array o quando trova elemento non nullo
    }
    // printf("Ci sono %d pivot\n", *countPivot);
    return true;
}
