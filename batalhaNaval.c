#include <stdio.h>


int main (){

    //Criação do Campo

    int campo[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 3, 0, 3, 3, 3, 0, 3},
                    {3, 3, 3, 0, 0, 0, 0, 0, 0, 3},
                    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,3},
                    {0 ,3,3 ,3 ,0 ,0 ,0 ,0 ,0 ,0},
                    {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
                    {0 ,0 ,0 ,0 ,0 ,0 ,3 ,3 ,3 ,0}};
    

    //Impressão Vertical do Campo
    for (int i = 0; i < 10; i++){

        //Impressão Horizontal do Campo
        for (int j = 0; j < 10; j++){
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }
    



    return 0;
}