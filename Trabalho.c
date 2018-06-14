#include "HeaderTrabalho.h"
#define x3 50
#define x4 50000
#define x5 500000

int main()
{
    printf("eu estou aqui");
    int v1[x3],v2[x4],v3[x5];
    int x,vaux1[x3], vaux2[x4], vaux3[x5];
    float processador[21];
    clock_t start_t , end_t;  
    float total[21];
    
    geraValores(v2,x4);
    geraValores(v3,x5);
    //recebe o apção da função menu
    x=menu();
    switch(x)
    {
         case 1:
            geraValores(v1,x3);
            
            recarrega(vaux1,v1,x3);
            
            //Método da Bolha  
            printf("Rodando Buble Sort \n");
            start_t = clock();
            processador[0] = bubleSort(vaux1,x3);
            end_t = clock();
            total[0] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            
            //Recanrregando o vetor 
            recarrega(vaux1,v1,x3);
            
            //  Método da Bolha melhorado
            printf("Rodando Buble Sort Melhorado \n");
            start_t = clock();
            processador[1] = bubleSortM(vaux1,x3);
            end_t = clock();
            total[1] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            
            //Recanrregando o vetor 
            recarrega(vaux1,v1,x3);

            //Método de Ordenação Troca e Partição 
            printf("Rodando Quick Sort \n");
            start_t = clock();
            processador[2] = quickSort(vaux1,0,x3,0.0);
            end_t = clock();
            total[2] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            
            //Recanrregando o vetor 
            recarrega(vaux1,v1,x3);

            //Método de Ordenação Inserção Direta 
            printf("Rodando Inserct Sort \n");
            start_t = clock();
            processador[3] = inserctSort(vaux1,x3);
            end_t = clock();
            total[3] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            
            recarrega(vaux1,v1,x3);

            //Método de Ordenação por Incrementos decrecentes 
            printf("Rodando Shell Sort\n");
            start_t = clock();
            processador[4] = shellSort(vaux1, x3);
            end_t = clock();    
            total[4] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            
            recarrega(vaux1,v1,x3);

            //Método de Ordenação por inserção direta
            printf("Rodando Select sort\n");
            start_t = clock();
            processador[5] = selectSort(vaux1, x3);
            end_t = clock();
            total[5] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            

            recarrega(vaux1,v1,x3);
            
        
            //Método de Ordenação tipo arvore
            printf("Rodando Heap Sort");
            start_t = clock();            
            processador[6] = heapSort(vaux1, x3);
            end_t = clock();
            total[6] = (double) (end_t - start_t) / CLOCKS_PER_SEC;
            x = subMenu();
            break;
             


    //     case 2:
    //         //Método da Bolha 
    //         processador[0] = bubleSort(v2);
    //          //Método da Bolha melhorado 
    //         processador[1] = bubleSortM(v2);
    //         //Método de Ordenação Troca e Partição 
    //         processador[2] = quickSort(v2);
    //         //Método de Ordenação Inserção Direta 
    //         processador[3] = inserctSort(v2);
    //         //Método de Ordenação por Incrementos decrecentes 
    //         processador[4] = shellSort(v2);
    //         //Método de Ordenação por inserção direta
    //         processador[5] = selectSort(v2);
    //         //Método de Ordenação tipo arvore
    //         processador[6] = heapSort(v2);
    //         break;
    //     case 3:
    //         //Método da Bolha 
    //         processador[0] = bubleSort(v3);
    //          //Método da Bolha melhorado 
    //         processador[1] = bubleSortM(v3);
    //         //Método de Ordenação Troca e Partição 
    //         processador[2] = quickSort(v3);
    //         //Método de Ordenação Inserção Direta 
    //         processador[3] = inserctSort(v3);
    //         //Método de Ordenação por Incrementos decrecentes 
    //         processador[4] = shellSort(v3);
    //         //Método de Ordenação por inserção direta
    //         processador[5] = selectSort(v3);
    //         //Método de Ordenação tipo arvore
    //         processador[6] = heapSort(v3);
    //         break;
    //     case 4:
            
    //         break;
    //     case 5:
            
    //         break;
    //     case 6:
            
    //         break; 
    //     case 7:
            
    //         break;
     }
    return 0;
}
 
