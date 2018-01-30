#ifndef LISTA_SE // Para evitar duplicação de código.

/**
    Projeto iniciado em 29 de janeiro de 2018
    Finalizado em 29 de janeiro de 2018
    Autor : Roberto Nóbrega (RN)
    Assunto : Revisão de Lista Simplesmente Encadeada, que pertence a disciplina Estruturas de Dados.
*/

/* Abaixo, está criando uma struct, que será o nó para cada componente da lista. */
typedef struct no{
    int valor;
    struct no *prox;
}tNo;

/* Abaixo, está criando uma struct, para apresentar o tamanho e começo da lista. */
typedef struct{
    int tamanho;
    tNo *cabeca;
}tLista;

/** OBS : A ordem de criação das structs acima importa, pois a struct tLista está 'enxergando' tNo, mas tNo não 'enxerga'. */

typedef tNo *tno;

/* Abaixo, temos os protótipos das funções. */

extern void criarLista(tLista *ini); /* extern indica que está fazendo alusão a função, ou seja, em algum lugar deste programa
existe a função criarLista.  */
extern void exibirLista(tLista ini);
extern int inserirNo(tLista *ini, int valor); /* Para inserir, de forma sequencial. */
extern int inserirNoPosicao(tLista *ini, int valor, int pos);
extern int eliminarNo(tLista *ini, int valor);
extern int eliminarNoPosicao(tLista *ini, int pos);
extern int tamanho(tLista ini);
extern int posicaoNo(tLista ini, int valor);
extern int posicaoValor(tLista ini, int pos);
#endif // LISTA_SE
