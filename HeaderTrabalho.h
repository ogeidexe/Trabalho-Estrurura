#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <time.h>

int geraValores(int vet[],int x){
    int i;
    printf("gerando valores aleatórios na faixa de 0 a %d \n", x);
    //Reseta o tempo no programa para que os valores sejão aleatorios para cada execução 
    srand(time(NULL));
    for (i=0; i < x; i++)
     {  
           vet[i]=rand() % (x);
     }
}
int menu()
{
    int x;
    puts("Selecione o caso para teste");
    puts("1.Caso 1 com 5000 elementos");
    puts("2.Caso 2 com 50000 elementos");
    puts("3.Caso 3 com 500000 elementos");
    puts("4.ver tabela");
    puts("0.Sair");
    scanf("%d",&x);
    if(x==0)exit(0);
    return x;
}

void imprimVetor(int vet[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d. %d\n",i,vet[i]);
    }

}

//Método da Bolha---------------------------------------------------------------------
double bubleSort(int vet[], int x)
{
    puts("ordenado metodo bolha");
    int i,j,aux;
    double resultado=0;
    j=x;
    //#pragma omp parallel for 
    for(i=0;i<x-1;i++)
    {
        //#pragma omp parallel for //13034.666000
        for(j=1;j<x-i;j++)
        {
            if(vet[j]>vet[j+1])
            {
                aux = vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
                resultado++;
            }
        }

    }
    return resultado;
}
//Método da Bolha melhorado-------------------------------------------------------
double bubleSortM(int vet[], int x)
{
    puts("ordenado metodo bolha melhorado");
    int i,j,aux,troucou;
    double resultado=0;
    j=x;
    for(i=0;i<x-1;i++)
    {
        troucou=0;
        for(j=1;j<x-i;j++)
        {
            if(vet[j]>vet[j+1])
            {
                aux = vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
                troucou=1;
                resultado++;
            }
        }
        if(troucou==0)break;

    }
    return resultado;
}
//Método de Ordenação Troca e Partição-------------------------------------------------
quickSort(int vet[], int x)
{
    float resultado;
    return resultado;
}
//Método de Ordenação Inserção Direta-----------------------------------------------------
inserctSort(int vet[], int x)
{
    float resultado;
    return resultado;
}
//Método de Ordenação por Incrementos decrecentes---------------------------------------
shellSort(int vet[], int x)
{
    float resultado;
    return resultado;
}
//Método de Ordenação por inserção direta------------------------------------------------------
selectSort(int vet[], int x)
{
    float resultado;
    return resultado;
}
//Método de Ordenação tipo arvore----------------------------------------------------------------
heapSort(int vet[], int x)
{
    float resultado;
    return resultado;
}
//função para apresentar os resultados de cada interação-------------------------------
void resultado(double vet[],int tamResultado)
{
    
    for(int i = 0; i < tamResultado; i++)
    {
        printf("|Tempo|%lf ||  \n");
    }
    
}