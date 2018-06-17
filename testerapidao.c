#include <stdio.h>
#include <math.h>

int main()
{
    long long y;
    long double x=1;
    unsigned long long int numero;
    int i;
    printf("%Lf\n",x);
    //x = x + (double)11111111111111.0;
    // for(i=0;i<30;i++)
    // {
    //     x = x *10;
    // }
    x = 1e+21;
    x = x+40000.00;
    x = x + 9e+1;
    printf("%Lf \n",x);
    printf("%ld", sizeof(x));
    
}


