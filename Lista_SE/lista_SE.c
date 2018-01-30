#include "lista_SE.h" // Importando a biblioteca criada por mim.
#include <stdlib.h>
#include <stdio.h>

/* Abaixo, est� as fun��es implementadas, em rela��o a parte da biblioteca lista_SE.h  */

void criarLista(tLista *ini){
     ini->tamanho = 0;  /* OBS :   ->  :  Este operador � usado apenas para ponteiro para struct. */
     ini->cabeca = NULL;
}

void exibirLista(tLista ini){
     tNo *aux;
     int pos;
     if(ini.tamanho == 0)
         printf("\n\tA lista est� vazia.\n");
     else
     {
        aux = ini.cabeca;
        for(pos = 1; aux != NULL; ++pos, aux = aux->prox)
            printf("\n\tPosi��o %d : %d",pos,aux->valor);
     }
}

int inserirNo(tLista *ini, int valor){ /*  Esta fun��o vai inserir o n�, de forma sequencial. */
    tno n, aux = ini->cabeca; // n e aux s�o vari�veis de tipo tNo, sendo que s�o ponteiros.
    n = malloc(sizeof(tNo)); /*  malloc : Vai alocar mem�ria suficiente para, no caso, a struct tNo, sendo que vai retornar
    o endere�o de onde esta mem�ria foi alocada. OBS : malloca retorna um ponteiro gen�rico, ou seja, void*   */
    if(n == NULL)
    {
        printf("\n\tFalha ao alocar mem�ria, para criar o n�.\n");
        return 0;
    }
    n->valor = valor;
    n->prox = NULL;
    if(aux == NULL)
        ini->cabeca = n;
    else{
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = n;
    }
    ini->tamanho++;
    return 1;
}

int inserirNoPosicao(tLista *ini, int valor, int pos){
    tno n, aux = ini->cabeca;
    int p;
    n = malloc(sizeof(tNo));
    if(n == NULL){
        printf("\n\tFalhou ao alocar mem�ria para criar o n�.\n");
        return 0;
    }
    n->valor = valor;
    if(ini->tamanho == 0){ // Quando a lista � vazia, ent�o ser� colocada na primeira posi��o.
        n->prox = NULL;
        ini->cabeca = n;
    }else if((pos <= 0) || (pos > (ini->tamanho + 1))){
        printf("\n\tPosi��o %d � inv�lida.\n",pos);
        free(n); /* Serve para desalocar mem�ria. Para este caso, a mem�ria alocada para a struct n foi desalocada. */
        return 0;
    }else{
        for(p = 1; p != pos; ++p){
            if((p + 1 != pos) && (aux->prox != NULL))
                aux = aux->prox;
            if(p + 1 == pos)
                break;
        }
        if(pos == 1){ // Quando a lista n�o � vazia e se quer inserir na primeira posi��o.
            n->prox = ini->cabeca;
            ini->cabeca = n;
        }else{
            n->prox = aux->prox;
            aux->prox = n;
        }
    }
    ini->tamanho++;
    return 1;
}

int eliminarNo(tLista *ini, int valor){
    tno aux = ini->cabeca, aux2 = ini->cabeca;
    if(ini->tamanho == 0){
        printf("\n\tA lista est� vazia.\n");
        return 0;
    }
    while(aux != NULL){
        if(aux2->valor == valor){
            aux->prox = aux2->prox;
            free(aux2);
            ini->tamanho--;
            break;
        }
        if(aux2->prox != NULL){
            aux = aux2;
            aux2 = aux2->prox;
        }else{
            printf("\n\tO valor %d n�o est� presente na lista.\n",valor);
            return 0;
        }
    }
    return 1;
}

int tamanho(tLista ini){
    return ini.tamanho;
}

int posicaoNo(tLista ini, int valor){
    tno aux = ini.cabeca; /* OBS : Se n�o me engano, o operador ponto � para vari�vel de tipo struct. */
    int pos = 1;
    if(ini.tamanho == 0){
        printf("\n\tA lista est� vazia.\n");
        return 0;
    }
    while(aux != NULL){
        if(aux->valor == valor)
            break;
        ++pos;
        aux = aux->prox;
    }
    if(aux == NULL)
    {
        printf("\n\tPosi��o do elemento %d n�o est� na lista.\n",valor);
        return 0;
    }
    return pos;
}

int posicaoValor(tLista ini, int pos){
    tno aux = ini.cabeca;
    int p;
    if(ini.tamanho == 0){
        printf("\n\tA lista est� vazia.\n");
        return 0;
    }else if(pos <= 0 || pos > ini.tamanho){
        printf("\n\tA posi��o %d n�o faz parte desta lista.\n",pos);
        return 0;
    }
    for(p = 1; aux != NULL; ++p, aux = aux->prox)
        if(p == pos)
            break;
    return aux->valor;
}
