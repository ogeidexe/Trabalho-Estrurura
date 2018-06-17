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
        printf("%d. %d \t",i,vet[i]);
    }

}

//Método da Bolha---------------------------------------------------------------------
double bubleSort(int vet[], float vetR[], int x)
{
    int i,j,aux;
    double resultado=0;
    j=x;
    for(i=0;i<x-1;i++)
    {
        for(j=1;j<x-i;j++)
        {
            if(vet[j]>vet[j+1])
            {
                aux = vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
                vetR[0]++;
            }
        }
    vetR[1]++;
    }
    return resultado;
}
//Método da Bolha melhorado-------------------------------------------------------
double bubleSortM(int vet[], float vetR[], int x)
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
                vetR[2]++;
            }
        }
        if(troucou==0)break;
        vetR[3]++;
    }
    return resultado;
}
//Método de Ordenação Troca e Partição-------------------------------------------------

//Fução que calcula o pivo é tabem troca ordenando os dados 
int partiociona(int vet[],float vetR[], int incio, int fim)
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
            vetR[4]++;
        }
    }
    vet[incio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}
//chama recursivamente a função partiociona 
float quickSort(int vet[],float vetR[], int inicio,int fim, float resultado)
{
    vet[5]++;
    int pivo;
    if(fim > inicio)
    {
        pivo = partiociona(vet, vetR, inicio ,fim );
        quickSort(vet, vetR, inicio , pivo-1, resultado);
        quickSort(vet , vetR, pivo+1 ,fim , resultado);
    }    
    return resultado;
}


//Método de Ordenação Inserção Direta-----------------------------------------------------
float inserctSort(int vet[],float vetR[], int x)
{
    float resultado = 0;
    int i, j, aux;
    
    for(i = 1; i < x; i++)      
    {
        aux =  vet[i];
        for(j = i;(j > 0) && (aux < vet[j-1]); j--)
        {
            vet[j] = vet[j - 1];
            vetR[6]++;
        }
        vet[j] = aux;
        vetR[7]++;
    }
    return resultado;
}
//Método de Ordenação por Incrementos decrecentes---------------------------------------
float shellSort(int vet[],float vetR[], int x)
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
                vetR[8]++;
            }
            vet [j] = value;
        vetR[9]++;
        }
    }

    return resultado;
}
//Método de Ordenação por inserção direta------------------------------------------------------
float selectSort(int vet[],float vetR[], int tam)
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
        vetR[10]++;
        }
    vetR[11]++;
    }
    return resultado;
}
//Método de Ordenação tipo arvore----------------------------------------------------------------
float heapSort(int a[], float vetR[], int n) {
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
             vetR[12]++;
          } else {
             break;
          }
      }
      a[pai] = t;
   vetR[13]++;
   }
   return resultado;
}


//função para apresentar os resultados de cada interação-------------------------------
void mostraTempoGasto(float vtempo[],int i)
{
    puts("=============================TEMPO GASTO COM CADA FUNÇÃO===========================");
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

void mostraQtdInteracao(float processador[],int i)
{
    puts("=========================Quantidade de interações por tipo de vetor=============== ");
    if(i==1)printf("Caso com 5000 Elementos\n");
    if(i==2)printf("Caso com 50.000 Elementos\n");
    if(i==3)printf("Caso com 500.000 Elementos\n");
    printf("                              |desordenado(aleatorio)   |para decrecente               \t|para crescente   |\n");
    printf("1. Método da Bolha            |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[1] ,processador[15] ,processador[29]);   
    printf("2. Método da Bolha Melhorado  |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[3] ,processador[17] ,processador[31]);  
    printf("3. Quicksort                  |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[5] ,processador[19] ,processador[33]);     
    printf("4. Inserção Direta            |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[7] ,processador[21] ,processador[35]);     
    printf("5. Shellsort                  |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[9] ,processador[23] ,processador[37]);      
    printf("6. Seleção Direta             |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[11] ,processador[25] ,processador[39]);      
    printf("7. Heapsort                   |\t %.0f                \t|%.0f                          \t|\t%.0f       \t   interações|\n",processador[13] ,processador[27] ,processador[41]);      

}

void mostraQtdTrocas(float processador[],int i)
{
    puts("=========================Quantidade de trocas por tipo de vetor=========================");
    if(i==1)printf("Caso com 5000 Elementos\n");
    if(i==2)printf("Caso com 50.000 Elementos\n");
    if(i==3)printf("Caso com 500.000 Elementos\n");
    printf("                              |desordenado(aleatorio)         |para decrecente               \t|para crescente   |\n");
    printf("1. Método da Bolha            |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[1-1] ,processador[15-1] ,processador[29-1]);   
    printf("2. Método da Bolha Melhorado  |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[3-1] ,processador[17-1] ,processador[31-1]);  
    printf("3. Quicksort                  |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[5-1] ,processador[19-1] ,processador[33-1]);     
    printf("4. Inserção Direta            |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[7-1] ,processador[21-1] ,processador[35-1]);     
    printf("5. Shellsort                  |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[9-1] ,processador[23-1] ,processador[37-1]);      
    printf("6. Seleção Direta             |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[11-1] ,processador[25-1] ,processador[39-1]);      
    printf("7. Heapsort                   |\t %.0f                      \t|%.0f               \t|%.0f    \t\t trocas|\n",processador[13-1] ,processador[27-1] ,processador[41-1]);      

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
    puts("4. Quero ver vetores (devido a uma limitação apenas os primeiros 10 elementos serão mostrados )");
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

 void recolheAmostra(int origem[], int destino[], int n)
 {
     for(int k=0; k < n; k++)
     {
         destino[k] = origem [k];
     }
 }