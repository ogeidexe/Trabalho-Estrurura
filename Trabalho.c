#include "HeaderTrabalho.h"
#define x3 5000
#define x4 50000
#define x5 500000

int main()
{
    //vetores principais não modificados durante a execução das funçoes 
    int v1[x3],v2[x4],v3[x5];
    
    //vetores auxiliares modificados durante a execução das funçoes 
    int x,vaux1[x3], vaux2[x4], vaux3[x5], indice;

    //vetores responsaveis por recolher as interações e trocas de cada função 
    float processador[14], armazena[48];
    
    //amostra dos vetores ordenado, aleatorio e decrescente
    int amostra1[10], amostra2[10], amostra3[10];

    //vetor que recebe o tempo de execução de cada função 
    float total[21];    

    //variaveis de tempo
    clock_t start_t , end_t;  
    
    //preparando vetores que recebam os resultados 
    for(int j; j < 48; j++)
    {
        armazena[j] = 0.00;
    }

    for(int j; j < 14; j++)
    {
        processador[j] = 0.00;
    }

    for(int j; j < 21 ; j++)
    {
        total[j] = 0.00;
    }

    for(int j; j < 10; j++)
    {
        amostra1[j] = 0.00;
        amostra2[j] = 0.00;
        amostra3[j] = 0.00;
    }

    
    //recebe o apção da função menu
    x=menu();
    switch(x)
    {
         case 1:
            indice = 0;
            geraValores(v1,x3);
            while(indice <= 14)
            {   
                /*faz com que aconteção tres testes na sequite ordem
                *   O Primeiro teste e o teste de variaveis aleatorias no vetor
                *   O Segundo teste e o teste de variaveis decrecentes no vetor 
                *   O ultimo teste e o de variaveis crescentes no vetor 
                */

                if(indice==0)
                printf("Teste Aleatorio\t");

                if(indice==7)
                {
                    shellSort(v1,processador,x3);
                    ordemDecrecente(v1 ,vaux1 ,x3);
                    printf("\nTeste Decrecente");
                    recarrega(v1,v1,x3);
                }

                if(indice==14)
                {
                   quickSort(v1,processador,0,x3,0.0);
                   printf("\nTeste Crescente\t");
                }

                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************

                //Método da Bolha  
                start_t = clock();
                bubleSort(vaux1, processador,x3);
                end_t = clock();
                total[0 + indice ] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1, v1, x3);
                //**********************
                
                //  Método da Bolha melhorado
                start_t = clock();
                bubleSortM(vaux1, processador,x3);
                end_t = clock();
                total[1 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1, v1, x3);
                //**********************

                //Método de Ordenação Troca e Partição 
                start_t = clock();
                quickSort(vaux1, processador,0,x3,0.0);
                end_t = clock();
                total[2 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1, v1, x3);
                //**********************

                //Método de Ordenação Inserção Direta 
                start_t = clock();
                inserctSort(vaux1, processador,x3);
                end_t = clock();
                total[3 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor'
                //++++++++++++++++++++++
                recarrega(vaux1, v1, x3);
                //**********************

                //Método de Ordenação por Incrementos decrecentes
                start_t = clock();
                shellSort(vaux1, processador, x3);
                end_t = clock();    
                total[4 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1, v1, x3);
                //**********************

                //Método de Ordenação por inserção direta
                start_t = clock();
                selectSort(vaux1, processador, x3);
                end_t = clock();
                total[5 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux1,v1,x3);
                //**********************
                
                //Método de Ordenação tipo arvore
                start_t = clock();            
                heapSort(vaux1, processador, x3);
                end_t = clock();
                total[6 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                indice = indice + 7;
                if(indice == 7)
                {
                    for(int j = 0; j < 14 ; j++)
                    {
                        armazena[j] = processador [j];
                    }
                    recolheAmostra(vaux1,amostra1,10);
                }
                if(indice == 14)
                {
                    int k = 14 ;
                    for(int j = 0; j < 14 ; j++ , k++)
                    {
                        armazena[k] = processador [j];
                    }
                    recolheAmostra(vaux1,amostra2,10);
                }
                if(indice == 21)
                {
                    int k = 29 ;
                    for(int j = 0; j < 14 ; j++ , k++)
                    {
                        armazena[k] = processador [j];
                    }
                    recolheAmostra(vaux1, amostra3, 10);
                }
                
            }
            x = subMenu();
            switch(x)
            {
                 case 1:
                    mostraTempoGasto(total , 1);
                    //break;
                 case 2:
                    mostraQtdTrocas(armazena , 1);
                    //break;
                 case 3:
                    mostraQtdInteracao(armazena, 1);
                    //break;
                 case 4:
                    printf("\n");
                    puts("vetor aleatorio");
                    imprimVetor(amostra1, 10);
                    printf("\n");
                    puts("vetor decrescente");
                    imprimVetor(amostra2, 10);
                    printf("\n");
                    puts("vetor crescente");
                    imprimVetor(amostra3, 10);
                    printf("\n");
                 case 5:

                    mostraTempoGasto(total , 1);
                    mostraQtdTrocas(armazena , 1);
                    mostraQtdInteracao(armazena, 1);
                    printf("\n");
                    puts("vetor aleatorio");
                    imprimVetor(amostra1, 10);
                    printf("\n");
                    puts("vetor decrescente");
                    imprimVetor(amostra2, 10);
                    printf("\n");
                    puts("vetor crescente");
                    imprimVetor(amostra3, 10);
                    printf("\n");                   
            }
            //break;
        case 2:
            indice = 0;
            geraValores(v2,x4);
            recolheAmostra(v2,amostra1,10);
            while(indice <= 14)
            {   
                
                /*faz com que aconteção tres testes na sequite ordem
                *   O Primeiro teste e o teste de variaveis aleatorias no vetor
                *   O Segundo teste e o teste de variaveis decrecentes no vetor 
                *   O ultimo teste e o de variaveis crescentes no vetor 
                * 
                */

                if(indice==0)printf("Teste Aleatorio\t");
                if(indice==7)
                {
                    shellSort(v2,processador,x4);
                    ordemDecrecente(v2 ,vaux2 ,x4);
                    printf("\nTeste Decrecente");
                    recolheAmostra(vaux2,amostra2,10);
                }
                if(indice==14)
                {
                   quickSort(v2,processador,0,x4,0.0);
                   printf("\nTeste Crescente\t");
                }

                //++++++++++++++++++++++
                recarrega(vaux2,v2,x4);
                //**********************

                //Método da Bolha  
                start_t = clock();
                bubleSort(vaux2, processador,x4);
                end_t = clock();
                total[0 + indice ] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux2, v2, x4);
                //**********************
                
                //  Método da Bolha melhorado
                start_t = clock();
                bubleSortM(vaux2, processador,x4);
                end_t = clock();
                total[1 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux2, v2, x4);
                //**********************

                //Método de Ordenação Troca e Partição 
                start_t = clock();
                quickSort(vaux2, processador,0,x4,0.0);
                end_t = clock();
                total[2 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux2, v2, x4);
                //**********************

                //Método de Ordenação Inserção Direta 
                start_t = clock();
                inserctSort(vaux2, processador,x4);
                end_t = clock();
                total[3 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux2, v2, x4);
                //**********************

                //Método de Ordenação por Incrementos decrecentes 
                start_t = clock();
                shellSort(vaux2, processador, x4);
                end_t = clock();    
                total[4 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                recolheAmostra(vaux2, amostra3, 10);
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux2, v2, x4);
                //**********************

                //Método de Ordenação por inserção direta
                start_t = clock();
                selectSort(vaux2, processador, x4);
                end_t = clock();
                total[5 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux2,v2,x4);
                //**********************
                
            
                //Método de Ordenação tipo arvore
                start_t = clock();            
                heapSort(vaux2, processador, x4);
                end_t = clock();
                total[6 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;

                indice = indice + 7;
                if(indice == 7)
                {
                    for(int j = 0; j < 14 ; j++)
                    {
                        armazena[j] = processador [j];
                    }
                }
                if(indice == 14)
                {
                    int k = 14 ;
                    for(int j = 0; j < 14 ; j++ , k++)
                    {
                        armazena[k] = processador [j];
                    }
                }
                if(indice == 21)
                {
                    int k = 29 ;
                    for(int j = 0; j < 14 ; j++ , k++)
                    {
                        armazena[k] = processador [j];
                    }
                }
                
            }
            x = subMenu();
            switch(x)
            {
                 case 1:
                    mostraTempoGasto(total , 2);
                    //break;
                 case 2:
                    mostraQtdTrocas(armazena , 2);
                    //break;
                 case 3:
                    mostraQtdInteracao(armazena, 2);
                    //break;
                 case 4:
                    printf("\n");
                    puts("vetor aleatorio");
                    imprimVetor(amostra1, 10);
                    printf("\n");
                    puts("vetor decrescente");
                    imprimVetor(amostra2, 10);
                    printf("\n");
                    puts("vetor crescente");
                    imprimVetor(amostra3, 10);
                    printf("\n");
                 case 5:

                    mostraTempoGasto(total , 2);
                    mostraQtdTrocas(armazena , 2);
                    mostraQtdInteracao(armazena, 2);
                    printf("\n");
                    puts("vetor aleatorio");
                    imprimVetor(amostra1, 10);
                    printf("\n");
                    puts("vetor decrescente");
                    imprimVetor(amostra2, 10);
                    printf("\n");
                    puts("vetor crescente");
                    imprimVetor(amostra3, 10);
                    printf("\n");                   
            }
            //break;
        case 3:
            indice = 0;
            geraValores(v3,x5);
            recolheAmostra(v3,amostra1,10);
            while(indice <= 14)
            {   
                /*faz com que aconteção tres testes na sequite ordem
                *   O Primeiro teste e o teste de variaveis aleatorias no vetor
                *   O Segundo teste e o teste de variaveis decrecentes no vetor 
                *   O ultimo teste e o de variaveis crescentes no vetor 
                * 
                */


                if(indice==0)printf("Teste Aleatorio\t");
                if(indice==7)
                {
                    shellSort(v3,processador,x5);
                    ordemDecrecente(v3 ,vaux3 ,x5);
                    printf("\nTeste Decrecente");
                    recolheAmostra(vaux3,amostra2,10);
                }
                if(indice==14)
                {
                   quickSort(v3,processador,0,x5,0.0);
                   printf("\nTeste Crescente\t");
                }

                //++++++++++++++++++++++
                recarrega(vaux3,v3,x5);
                //**********************

                //Método da Bolha  
                //#pragma omp parallel
                start_t = clock();
                bubleSort(vaux3, processador,x5);
                end_t = clock();
                total[0 + indice ] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux3, v3, x5);
                //**********************
                
                //  Método da Bolha melhorado
                //printf("Rodando Buble Sort Melhorado \n");
                start_t = clock();
                //#pragma omp parallel
                bubleSortM(vaux3, processador,x5);
                end_t = clock();
                total[1 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux3, v3, x5);
                //**********************

                //Método de Ordenação Troca e Partição 
                //printf("Rodando Quick Sort \n");
                start_t = clock();
                quickSort(vaux3, processador,0,x5,0.0);
                end_t = clock();
                total[2 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux3, v3, x5);
                //**********************

                //Método de Ordenação Inserção Direta 
                //printf("Rodando Inserct Sort \n");
                start_t = clock();
                inserctSort(vaux3, processador,x5);
                end_t = clock();
                total[3 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux3, v3, x5);
                //**********************

                //Método de Ordenação por Incrementos decrecentes 
                //printf("Rodando Shell Sort\n");
                start_t = clock();
                shellSort(vaux3, processador, x5);
                end_t = clock();    
                total[4 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                recolheAmostra(vaux3, amostra3, 10);
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux3, v3, x5);
                //**********************

                //Método de Ordenação por inserção direta
                //printf("Rodando Select sort\n");
                start_t = clock();
                selectSort(vaux3, processador, x5);
                end_t = clock();
                total[5 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                
                //Recanrregando o vetor 
                //++++++++++++++++++++++
                recarrega(vaux3,v3,x5);
                //**********************
                
            
                //Método de Ordenação tipo arvore
                //printf("Rodando Heap Sort\n");
                start_t = clock();            
                heapSort(vaux3, processador, x5);
                end_t = clock();
                total[6 + indice] = (double) (end_t - start_t) / CLOCKS_PER_SEC * 1000;
                indice = indice + 7;
                if(indice == 7)
                {
                    for(int j = 0; j < 14 ; j++)
                    {
                        armazena[j] = processador [j];
                    }
                }
                if(indice == 14)
                {
                    int k = 14 ;
                    for(int j = 0; j < 14 ; j++ , k++)
                    {
                        armazena[k] = processador [j];
                    }
                }
                if(indice == 21)
                {
                    int k = 29;
                    for(int j = 0; j < 14 ; j++ , k++)
                    {
                        armazena[k] = processador [j];
                    }
                }
                
            }
            x = subMenu();
            switch(x)
            {
                 case 1:
                    mostraTempoGasto(total , 1);
                    //break;
                 case 2:
                    mostraQtdTrocas(armazena , 1);
                    //break;
                 case 3:
                    mostraQtdInteracao(armazena, 1);
                    //break;
                 case 4:
                    printf("\n");
                    puts("vetor aleatorio");
                    imprimVetor(amostra1, 10);
                    printf("\n");
                    puts("vetor decrescente");
                    imprimVetor(amostra2, 10);
                    printf("\n");
                    puts("vetor crescente");
                    imprimVetor(amostra3, 10);
                    printf("\n");
                 case 5:

                    mostraTempoGasto(total , 3);
                    mostraQtdTrocas(armazena , 3);
                    mostraQtdInteracao(armazena, 3);
                    printf("\n");
                    puts("vetor aleatorio");
                    imprimVetor(amostra1, 10);
                    printf("\n");
                    puts("vetor decrescente");
                    imprimVetor(amostra2, 10);
                    printf("\n");
                    puts("vetor crescente");
                    imprimVetor(amostra3, 10);
                    printf("\n");                   
            }
            break;
     }
    return 0;
}
 
