#include "HeaderTrabalho.h"
#define x3 5000
#define x4 50000
#define x5 500000

int main()
{
    printf("eu estou aqui");
    int v1[x3],v2[x4],v3[x5];
    int x,vaux1[x3], vaux2[x4], vaux3[x5], indice;
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
            indice = 0;
            geraValores(v1,x3);
            while(indice <= 14)
            {   
                if(indice==0)printf("Teste Aleatorio\t");
                if(indice==7)
                {
                    quickSort(vaux1,0,x3,0.0);
                    ordemDecrecente(v1 ,vaux1 ,x3);
                    printf("\nTeste Decrecente");
                }
                if(indice==14)
                {
                   quickSort(v1,0,x3,0.0);
                   printf("\nTeste Crescente\t");
                }

                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************
                //Método da Bolha  
                //printf("Rodando Buble Sort \n");
                start_t = clock();
                processador[0+indice] = bubleSort(vaux1,x3);
                end_t = clock();
                total[0 + indice ] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************
                
                //  Método da Bolha melhorado
                //printf("Rodando Buble Sort Melhorado \n");
                start_t = clock();
                processador[1+indice] = bubleSortM(vaux1,x3);
                end_t = clock();
                total[1 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************

                //Método de Ordenação Troca e Partição 
                //printf("Rodando Quick Sort \n");
                start_t = clock();
                processador[2+indice] = quickSort(vaux1,0,x3,0.0);
                end_t = clock();
                total[2 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************

                //Método de Ordenação Inserção Direta 
                //printf("Rodando Inserct Sort \n");
                start_t = clock();
                processador[3+indice] = inserctSort(vaux1,x3);
                end_t = clock();
                total[3 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************

                //Método de Ordenação por Incrementos decrecentes 
                //printf("Rodando Shell Sort\n");
                start_t = clock();
                processador[4+indice] = shellSort(vaux1, x3);
                end_t = clock();    
                total[4 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************

                //Método de Ordenação por inserção direta
                //printf("Rodando Select sort\n");
                start_t = clock();
                processador[5+indice] = selectSort(vaux1, x3);
                end_t = clock();
                total[5 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************
                
            
                //Método de Ordenação tipo arvore
                //printf("Rodando Heap Sort\n");
                start_t = clock();            
                processador[6+indice] = heapSort(vaux1, x3);
                end_t = clock();
                total[6 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                indice = indice + 7;
            }
            x = subMenu();
            switch(x)
            {
                 case 1:
                    mostraTempoGasto(total , 1);
            }
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
 
