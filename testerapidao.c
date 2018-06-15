#include <stdio.h>

void ordemDecrecente(int vet1[],int aux2[],int x )
{
    int i, j=x-1;
    for(i = 0; i < x; i++,j--)
    {
        aux2[i] =  vet1 [j];
    }
}

int main()
{
    int vet[]={1,2,3,4,5},vet2[5],i;
    ordemDecrecente(vet,vet2,5);
    for(i=0;i<5;i++)
    {
        printf("%d ",vet2[i]);
    }
     return 0;
}


