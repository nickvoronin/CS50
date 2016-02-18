#include <stdio.h>

int main()
{
    int size = 2;
    int n = 3; 
    int orig[n][n];
    int copy[size * n][size * n];
    
    //generate original array
    int t = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            orig[i][j] = t++;
        }
    }
    
    // print originallarray
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", orig[i][j]);
        }
        printf("\n");
    }
    
    // copy array
    for (int i = 0; i < size * n; i++)
    {
        for (int j = 0; j < size * n; j++)
        {
            copy[i][j] = orig[i / n][j / n];
        }
    }
    
    // print copied array
    for (int i = 0; i < size * n; i++)
    {
        for (int j = 0; j < size * n; j++)
        {
            printf("%d ", copy[i][j]);
        }
        printf("\n");
    }
    
    
    
}