#include <stdio.h>
#include<stdlib.h>


struct ponto
{
    float x;
    float y;
    struct ponto* prox;
};

typedef struct ponto Ponto;

//definindo o tamanho como zero
int length=0;

Ponto *primeiroElemento=NULL;//aponta para o primeiro elemento do ponteiro
Ponto *ultimoElemento=NULL;

//funcao para inserir no inicio
void inserirInicio(float x,float y){
    Ponto *p=(Ponto*)malloc(sizeof(Ponto));
    p->x=x;
    p->y=y;
    p->prox=primeiroElemento;//prox ta apontando pra null no 1 elemento pois primeiroElemento começa apontando p NULL //depois p aponta pra primeiroElemento que no caso aponta pro ultimo elemento inserido
    primeiroElemento=p;//primeiroElemento agora aponta pra p//primeiroElemento passa apontar para p inserido na 2x....
    if(p->prox==NULL)
    {
        ultimoElemento=p;
        ultimoElemento->prox=primeiroElemento;
    }
    length++;
}

//funcao para inserir no final
void inserirFinal(float x, float y)
{
    Ponto *p=(Ponto*)malloc(sizeof(Ponto));
    p->x=x;
    p->y=y;
    p->prox=NULL;
    if (primeiroElemento==NULL)//vendo se nao existe  elemento
    {
        primeiroElemento=p;
    }
    else
    {
        Ponto *listaAux=primeiroElemento;
        while(listaAux->prox!=NULL)
        {
            listaAux=listaAux->prox;
        }
        listaAux->prox=p;//AGORA O ANTIGO ULTIMO ELEMENTO APONTA PARA O NOVO PONTO CRIADO
    }
    if(p->prox==NULL)
        {
            ultimoElemento=p;
            ultimoElemento->prox=primeiroElemento;
        }
    length++;
}


//funcao para colocar em posicao arbitraria
void inserirArbitrario(float x, float y, int posicao)
{
    Ponto *p=(Ponto*)malloc(sizeof(Ponto));
    p->x=x;
    p->y=y;

    if(posicao>length)
    {
        printf("Posicao Invalida");
    }

    else
    {
        if(posicao==0)
        {
            p->prox=primeiroElemento;//prox do novo elemento aponta p 
            primeiroElemento=p;

        }
        else
        {
            Ponto* listaAux=primeiroElemento;
            int i=0;
            while(i!=posicao-1)
            {
                listaAux=listaAux->prox;
                i++;
            }
            p->prox=listaAux->prox;
            listaAux->prox=p;
            
        }
        length++;
    }

}

void removePosicao(int posicao)
{
    if(posicao>length||length==0)
    {

    }

}


//recursao
void imprime(Ponto *p)
{
    if(p!=NULL)
    {
        printf("Ponto(%.1f, %.1f)\n", p->x,p->y);
        imprime(p->prox);
    }
    printf("\n");
}


int main()
{

    inserirInicio(1,5);
    inserirInicio(4,3);

    Ponto *auxlista= primeiroElemento;

    imprime(auxlista);

    inserirFinal(7,9);
    imprime(auxlista);



    return 0;
}