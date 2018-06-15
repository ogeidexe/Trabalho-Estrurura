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

//Fução que calcula o pivo é tabem troca ordenando os dados 
int partiociona(int vet[], int incio, int fim)
{
    int esq, dir, pivo, aux;
    esq =  incio;
    dir = fim;
    pivo = vet[incio];
    while(esq < dir)
    {
        while(vet[esq] <= pivo)
            esq++;
        while(vet[dir] > pivo )
            dir--;
        if (esq < dir)
        {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }
    vet[incio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}
//chama recursivamente a função partiociona 
float quickSort(int vet[], int inicio,int fim, float resultado)
{
    int pivo;
    if(fim > inicio)
    {
        pivo = partiociona(vet, inicio ,fim );
        quickSort(vet, inicio , pivo-1, resultado);
        quickSort(vet ,pivo+1 ,fim , resultado);
    }    
    return resultado;
}


//Método de Ordenação Inserção Direta-----------------------------------------------------
float inserctSort(int vet[], int x)
{
    float resultado = 0;
    int i, j, aux;
    
    for(i = 1; i < x; i++)      
    {
        aux =  vet[i];
        for(j = i;(j > 0) && (aux < vet[j-1]); j--)
        {
            vet[j] = vet[j - 1];
            resultado++;
        }
        vet[j] = aux;
    }
    return resultado;
}
//Método de Ordenação por Incrementos decrecentes---------------------------------------
float shellSort(int vet[], int x)
{
    float resultado = 0;
    int i , j , value;
    int gap = 1;
    while(gap < x) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < x; i++) {
            value = vet[i];
            j = i;
            while (j >= gap && value < vet[j - gap]) {
                vet[j] = vet [j - gap];
                j = j - gap;
                resultado++;
            }
            vet [j] = value;
        }
    }

    return resultado;
}
//Método de Ordenação por inserção direta------------------------------------------------------
float selectSort(int vet[], int tam)
{
    float resultado = 0;
    int i, j, min, aux;
    for (i = 0; i < (tam-1); i++) 
    {
        min = i;
        for (j = (i+1); j < tam; j++) {
        if(vet[j] < vet[min]) 
            min = j;
        }
        if (vet[i] != vet[min]) {
        aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
        }
    }
    return resultado;
}
//Método de Ordenação tipo arvore----------------------------------------------------------------
// void criaHeap(int vet[], int i, int f)
// {
//     int aux = vet[i];
//     int j = i * 2 +1;
    
//     while(i <= f)
//     {
//         if(vet[j] < vet[j + 1])
//         {
//             j = j + 1;
//         }
        
//         if (aux < vet [j]) 
//         {
//            vet[i] = vet [j];
//            i = j;
//            j = 2 * i + 1;
//         }
//         else
//         {
//             j = f + 1;
//         }     
//     }
//     vet[i] =  aux;
// }

// float heapSort(int vet[], int x)
// {
//     float resultado = 0;
//     int i, aux;
//     for(i = (x-1)/2; i >= 0; i--)
//     {
//         criaHeap( vet, i, x-1);
//     }
//     for(i = x - 1;i >= 1; i--)
//     {
//         aux = vet[0];
//         vet [0] = vet [i];
//         vet [i] = aux;
//         criaHeap(vet, 0, i - 1);
//     }

//     return resultado;
// }
float heapSort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   float resultado;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return 0.0;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
   return resultado;
}


//função para apresentar os resultados de cada interação-------------------------------
void resultado(double vet[],int tamResultado)
{
    
    for(int i = 0; i < tamResultado; i++)
    {
        printf("|Tempo|%lf ||  \n",vet[i]);
    }
    
}

void mostraTempoGasto(float vtempo[],int i)
{
    if(i==1)printf("Caso com 5000 Elementos\n");
    if(i==2)printf("Caso com 50.000 Elementos\n");
    if(i==3)printf("Caso com 500.000 Elementos\n");
    printf("                    tempos    |desordenado(aleatorio)   |              para decrecente   |\t        para crescente   |\n");
    printf("1. Método da Bolha            |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[0] ,vtempo[7] ,vtempo[14]);   
    printf("2. Método da Bolha Melhorado  |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[1] ,vtempo[8] ,vtempo[15]);  
    printf("3. Quicksort                  |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[2] ,vtempo[9] ,vtempo[16]);     
    printf("4. Inserção Direta            |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[3] ,vtempo[10] ,vtempo[17]);     
    printf("5. Shellsort                  |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[4] ,vtempo[11] ,vtempo[18]);      
    printf("6. Seleção Direta             |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[5] ,vtempo[12] ,vtempo[19]);      
    printf("7. Heapsort                   |\t %lf \t ms \t| \t %f \t ms \t | \t %f \t ms \t |\n",vtempo[6] ,vtempo[13] ,vtempo[20]);      
}

/////FUNÇOES COMPLEMENTARES///////////

//recarrega os vetores com o mesmo valor para que a mesma amostra seja reutilizada
//onde v1 é o vetor de destino e v2 e o vetor de origem 
void recarrega(int destino[], int origem[],int x)
{
    //printf("recarregando o vetor\n");
    for(int i=0;i<x;i++)
    {
        destino[i]=origem[i];
    }
    printf(" ok ");  
}

int subMenu()
{
    int x;
    printf("\n");
    puts("++++++++++++++++Apos a execução das funções o que deseja fazer ");
    puts("1. Quero ver o tempo  gasto em cada função" );
    puts("2. Quero ver a quantidade de trocas de cada função ");
    puts("3. Quero ver a quantidade de interações de cada função");
    puts("4. Quero ver vetores (devido a uma limitação apenas os primeiros 100 elementos serão mostrados )");
    puts("5. Quero ver tudo");
    scanf("%d",&x);
    return x;
}

//usando quick sort para ordenar os valores de forma decrecente 

void ordemDecrecente(int origem[],int destino[],int x )
{
    int i, j=x-1;
    for(i = 0; i < x; i++,j--)
    {
        destino[i] =  origem [j];
    }
}


 

// //Método de Ordenação Troca e Partição-------------------------------------------------

// //Fução que calcula o pivo é tabem troca ordenando os dados 
// int partiociona(int vet[], int incio, int fim)
// {
//     int esq, dir, pivo, aux;
//     esq =  incio;
//     dir = fim;
//     pivo = vet[incio];
//     while(esq < dir)
//     {
//         while(vet[esq] <= pivo)
//             esq++;
//         while(vet[dir] > pivo )
//             dir--;
//         if (esq < dir)
//         {
//             aux = vet[esq];
//             vet[esq] = vet[dir];
//             vet[dir] = aux;
//         }
//     }
//     vet[incio] = vet[dir];
//     vet[dir] = pivo;
//     return dir;
// }
// //chama recursivamente a função partiociona 
// float ordemDecrecente(int vet[], int inicio,int fim, float resultado)
// {
//     int pivo;
//     if(fim > inicio)
//     {
//         pivo = partiociona(vet, inicio ,fim );
//         ordemDecrecente(vet, inicio , pivo-1, resultado);
//         ordemDecrecente(vet ,pivo+1 ,fim , resultado);
//     }    
//     return resultado;
// }
