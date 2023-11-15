#include<stdio.h>

int potencia(int base, int expoente)
{
    if(expoente==1)
    {
        return base;
    }
   return base*potencia(base,expoente-1);
}

int main()
{
    int valor=potencia(2,4);//16
    return 0;
}