#ifndef LISTA_SE // Para evitar duplica��o de c�digo.

/**
    Projeto iniciado em 29 de janeiro de 2018
    Finalizado em 29 de janeiro de 2018
    Autor : Roberto N�brega (RN)
    Assunto : Revis�o de Lista Simplesmente Encadeada, que pertence a disciplina Estruturas de Dados.
*/

/* Abaixo, est� criando uma struct, que ser� o n� para cada componente da lista. */
typedef struct no{
    int valor;
    struct no *prox;
}tNo;

/* Abaixo, est� criando uma struct, para apresentar o tamanho e come�o da lista. */
typedef struct{
    int tamanho;
    tNo *cabeca;
}tLista;

/** OBS : A ordem de cria��o das structs acima importa, pois a struct tLista est� 'enxergando' tNo, mas tNo n�o 'enxerga'. */

typedef tNo *tno;

/* Abaixo, temos os prot�tipos das fun��es. */

extern void criarLista(tLista *ini); /* extern indica que est� fazendo alus�o a fun��o, ou seja, em algum lugar deste programa
existe a fun��o criarLista.  */
extern void exibirLista(tLista ini);
extern int inserirNo(tLista *ini, int valor); /* Para inserir, de forma sequencial. */
extern int inserirNoPosicao(tLista *ini, int valor, int pos);
extern int eliminarNo(tLista *ini, int valor);
extern int eliminarNoPosicao(tLista *ini, int pos);
extern int tamanho(tLista ini);
extern int posicaoNo(tLista ini, int valor);
extern int posicaoValor(tLista ini, int pos);
#endif // LISTA_SE
