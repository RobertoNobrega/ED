#include "lista_SE.h" // Importando a biblioteca criada por mim.
#include <stdlib.h>
#include <stdio.h>

/* Abaixo, está as funções implementadas, em relação a parte da biblioteca lista_SE.h  */

void criarLista(tLista *ini){
     ini->tamanho = 0;  /* OBS :   ->  :  Este operador é usado apenas para ponteiro para struct. */
     ini->cabeca = NULL;
}

void exibirLista(tLista ini){
     tNo *aux;
     int pos;
     if(ini.tamanho == 0)
         printf("\n\tA lista está vazia.\n");
     else
     {
        aux = ini.cabeca;
        for(pos = 1; aux != NULL; ++pos, aux = aux->prox)
            printf("\n\tPosição %d : %d",pos,aux->valor);
     }
}

int inserirNo(tLista *ini, int valor){ /*  Esta função vai inserir o nó, de forma sequencial. */
    tno n, aux = ini->cabeca; // n e aux são variáveis de tipo tNo, sendo que são ponteiros.
    n = malloc(sizeof(tNo)); /*  malloc : Vai alocar memória suficiente para, no caso, a struct tNo, sendo que vai retornar
    o endereço de onde esta memória foi alocada. OBS : malloca retorna um ponteiro genérico, ou seja, void*   */
    if(n == NULL)
    {
        printf("\n\tFalha ao alocar memória, para criar o nó.\n");
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
        printf("\n\tFalhou ao alocar memória para criar o nó.\n");
        return 0;
    }
    n->valor = valor;
    if(ini->tamanho == 0){ // Quando a lista é vazia, então será colocada na primeira posição.
        n->prox = NULL;
        ini->cabeca = n;
    }else if((pos <= 0) || (pos > (ini->tamanho + 1))){
        printf("\n\tPosição %d é inválida.\n",pos);
        free(n); /* Serve para desalocar memória. Para este caso, a memória alocada para a struct n foi desalocada. */
        return 0;
    }else{
        for(p = 1; p != pos; ++p){
            if((p + 1 != pos) && (aux->prox != NULL))
                aux = aux->prox;
            if(p + 1 == pos)
                break;
        }
        if(pos == 1){ // Quando a lista não é vazia e se quer inserir na primeira posição.
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
        printf("\n\tA lista está vazia.\n");
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
            printf("\n\tO valor %d não está presente na lista.\n",valor);
            return 0;
        }
    }
    return 1;
}

int tamanho(tLista ini){
    return ini.tamanho;
}

int posicaoNo(tLista ini, int valor){
    tno aux = ini.cabeca; /* OBS : Se não me engano, o operador ponto é para variável de tipo struct. */
    int pos = 1;
    if(ini.tamanho == 0){
        printf("\n\tA lista está vazia.\n");
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
        printf("\n\tPosição do elemento %d não está na lista.\n",valor);
        return 0;
    }
    return pos;
}

int posicaoValor(tLista ini, int pos){
    tno aux = ini.cabeca;
    int p;
    if(ini.tamanho == 0){
        printf("\n\tA lista está vazia.\n");
        return 0;
    }else if(pos <= 0 || pos > ini.tamanho){
        printf("\n\tA posição %d não faz parte desta lista.\n",pos);
        return 0;
    }
    for(p = 1; aux != NULL; ++p, aux = aux->prox)
        if(p == pos)
            break;
    return aux->valor;
}
