// CALCOLATORE DETERMINANTE E RANGO MATRICE, CALCOLATORE INDIPENDENZA LINEARE DI VETTORI

#include <stdio.h>
#include <stdbool.h>

void print_matrix(size_t order, const int matrix[order][order]); 
int determinant(size_t order, const int matrix[order][order]);
bool check_reduced(size_t order, const int matrix[order][order], int * countPivot); //reduced row echelon form function


int main() {
    int *countPivot_ptr;
    // inserisco ordine della matrice
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
    // se la matrice e' ridotta allora il numeri di pivot corrisponde al numero del rango
    if(check_reduced(order, matrix, countPivot_ptr)) 
    {
        printf("La matrice e' a scalini ed ha rango %d\n", *countPivot_ptr);
    }
    // se la matrice non e' a scalini va ridotta a scalini e bisogna ricontrollare a quel punto il rango
    // else 

    // Creo una matrice copia dove salvo la nuova matrice a scalini
    int reducedMatrix[order][order];
    for(size_t i=0; i<order; i++)
    {
        for(size_t j=0; j<order; j++)
        {
            reducedMatrix[i][j] = matrix[i][j];
        }
    }

    
    
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


int determinant(size_t order, const int matrix[order][order])
{
    if(order==2)
    {
        return matrix[0][0]*matrix[1][1] - (matrix[0][1]*matrix[1][0]);
    }
    else if(order == 3)
    {
        int matrixSarrus[order][order+2];
        for(size_t i=0; i<order; i++)
        {
            for(size_t j=0; j<order; j++)
            {
                matrixSarrus[i][j] = matrix[i][j];
            }  
        }
        for(size_t l=0; l<order; l++)
        {
            for(size_t m=order, n=0; n<order; m++, n++)
            {
                matrixSarrus[l][m] = matrix[l][n];
            }
        }
        
        puts("La matrice costruita per Sarrus e': ");
        for(size_t i=0; i<order; i++)
        {
            for(size_t j=0; j<order+2; j++)
            {
                printf("%3d ", matrixSarrus[i][j]);
            }  
            puts("");
        }

        int a = matrixSarrus[0][0]*matrixSarrus[1][1]*matrixSarrus[2][2];
        int b = matrixSarrus[0][1]*matrixSarrus[1][2]*matrixSarrus[2][3];
        int c = matrixSarrus[0][2]*matrixSarrus[1][3]*matrixSarrus[2][4];
        int d = matrixSarrus[0][2]*matrixSarrus[1][1]*matrixSarrus[2][0];
        int e = matrixSarrus[0][3]*matrixSarrus[1][2]*matrixSarrus[2][1];
        int f = matrixSarrus[0][4]*matrixSarrus[1][3]*matrixSarrus[2][2];

        return a+b+c-d-e-f;
         
    }
    else
    {
        puts("Ordine non accettato.");
        return 1;
    }
}

/* su processore arm del mac M1 compare errore "zsh: bus error" - risolvere con malloc */
bool check_reduced(size_t order, const int matrix[order][order], int * countPivot)
{
    int previousPivot = -1; // assegnamo un valore tale che il confronto if(actualPivot <= previousPivot) e' sempre false 
    // questo perche' nel primo ciclo di controllo l'elemento di posto matrice[0][0] non puo' essere confrontato con nessun altro pivot precedente essendo il primo
    int actualPivot;
    *countPivot = 0; // reset pivot count

    for(size_t row=0; row<order; row++)
    {
        for(size_t elemCol=0; elemCol<order; elemCol++)
        {
            if(matrix[row][elemCol] != 0)
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
