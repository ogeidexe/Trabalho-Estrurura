#include "HeaderTrabalho.h"
#define x3 5000
#define x4 50000
#define x5 500000

int main()
{
    int x,v1[x3],v2[x4],v3[x5];
    int vaux1[x3], vaux2[x4], vaux3[x5];
    float processador[7];  
    
    geraValores(v2,x4);
    geraValores(v3,x5);
    //recebe o apção da função menu
    x=menu();
     switch(x)
     {
         case 1:
            geraValores(v1,x3);
            for(int i;i<x3;i++)
            {
                vaux1[i]=v1[i];
            }
             //Método da Bolha  
            
            processador[0] = bubleSort(v1,x3);
              
            //Recanrregando o vetor 
            for(int i;i<x3;i++)
            {
                vaux1[i]=v1[i];
            }
            //  Método da Bolha melhorado
            processador[1] = bubleSortM(v1,x3);
             //Método de Ordenação Troca e Partição 
            // processador[2] = quickSort(v1);
            //Método de Ordenação Inserção Direta 
    //         processador[3] = inserctSort(v1);
    //         //Método de Ordenação por Incrementos decrecentes 
    //         processador[4] = shellSort(v1);
    //         //Método de Ordenação por inserção direta
    //         processador[5] = selectSort(v1);
    //         //Método de Ordenação tipo arvore
    //         processador[6] = heapSort(v1);
    //         break;
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
    // }
    return 0;
}
 
