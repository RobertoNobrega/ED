#include "lista_SE.h"
#include <locale.h>
#include <stdio.h>

/**
        Projeto iniciado em 29 de janeiro de 2018
        Finalizado em 29 de janeiro de 2018
        Autor : Roberto Nóbrega (RN)
        Assunto : Revisão de Lista Simplesmente Encadeada, que pertence a disciplina Estruturas de Dados.
*/

int main()
{
    tLista lista1;
    int valor;
    setlocale(LC_ALL,"portuguese"); /* Para reconhecer caracteres e acentuações em Língua Portuguesa. */
    criarLista(&lista1);
    for(valor = 25; valor < 31; ++valor)
        inserirNo(&lista1,valor);
    exibirLista(lista1);
    printf("\n\n\n\n");
    inserirNoPosicao(&lista1,78,5);
    exibirLista(lista1);
    eliminarNo(&lista1, 55);
    printf("\n\n\n\n");
    exibirLista(lista1);
    printf("\n\n\n\n");
    printf("\n\tTamanho da Lista : %d \n\tConfirmando o tamanho : %d \n",lista1.tamanho,tamanho(lista1));
    printf("\n\tPosição do elemento %d : %d \n",78,posicaoNo(lista1,78));
    printf("\n\tElemento na posição %d : %d \n",6,posicaoValor(lista1,6));
    return 0;
}
