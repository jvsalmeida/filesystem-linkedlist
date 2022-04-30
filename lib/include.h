#ifndef INCLUDE_H
#define INCLUDE_H

// tamanho do vetor
#define tamV 20   

// quantidade de bytes
#define qntB 3000 

/**
*	Esta struct diz quais são campos que o vetor que armazenará
*	os arquivos terá.
*
*/
typedef struct node {
	int posicao;
	int situacao;
	char *nome;
	char *conteudo;
	struct node *next;
}NODE;


int comando;
char nomeArquivo[500];
char *novo;

FILE *arquivo;
NODE vet[tamV];

#endif