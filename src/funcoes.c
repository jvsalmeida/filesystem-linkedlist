#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/include.h"

void inicializar(NODE *vet) {
	for(int i = 0; i < tamV; ++i) {
		vet[i].posicao = i;
		vet[i].situacao = 0;
		vet[i].nome = "";
		vet[i].conteudo = (char*)malloc(qntB*sizeof(char));	
		vet[i].next = NULL;
	}

	return;
}


int verificacao(NODE *vet) {
	int i;
	for(i = 0; i < tamV; ++i) {
		if(vet[i].situacao == 0)
			return i;
	}

	return -1;
}


void insercao(NODE *vet, char *nomeArquivo) {
	size_t result = 0;
	
	// quantidade total de bytes que o arquivo possui
	long sizeFile = 0;
	long rest = 0;
	long qntBlocos = 0;
	long blocosVazios = 0;
	int ind = 0;
	int ant = 0;

	if((arquivo = fopen(nomeArquivo, "rb")) != NULL) {

		fseek(arquivo, 0, SEEK_END);
		sizeFile = ftell(arquivo);
		rewind(arquivo);

		if(vet[ind].conteudo == NULL) {
			printf("Memory error\n");
			return;
		}

		// ----------------------- verificacao de tamanho ------------------------------
		qntBlocos = sizeFile/qntB;

		for(int i = 0; i < tamV; ++i) {
			if(vet[i].situacao == 0) {
				++blocosVazios;
			}
		}

		if(qntBlocos > blocosVazios) {
			printf("Não há espaço suficiente na memória para armazenar esse arquivo\n");

			fclose(arquivo);
			return;
		}
		// ----------------------------------------------------------------------------

		ind = verificacao(vet);
		ant = ind;

		result = fread(vet[ind].conteudo, 1, qntB, arquivo);
		vet[ind].situacao = 1;
		vet[ind].nome = nomeArquivo;

		if(sizeFile > qntB) {
			rest = sizeFile - qntB;
			
			while(rest > 0) {
				ind = verificacao(vet);
				result = fread(vet[ind].conteudo, 1, qntB, arquivo);
				vet[ind].situacao = 1;
				vet[ind].nome = nomeArquivo;
				vet[ant].next = &vet[ind];
				ant = ind;

				rest = rest - qntB;
			}
		}
		
		fclose(arquivo);
	
	} else
		printf("ERRO na abertura do arquivo!\n");

	return;
}

void delecao(NODE *vet, char *nomeArquivo) {
	int i;
	for(i = 0; i < tamV; ++i) {
		if(strcmp(vet[i].nome, nomeArquivo) == 0)
			break;
	}

	if(i >= tamV) {
		printf("Este arquivo não está cadastrado no sistema\n");
		return;
	}

	NODE *temp = (NODE*)malloc(sizeof(NODE*));
	for(NODE *aux = &vet[i]; aux != NULL;) {
		aux->situacao = 0;
		aux->nome = "";
		memset(aux->conteudo, 0, qntB);

		temp = aux;
		aux = aux->next;
		temp->next = NULL;
	}

	return;
}


int busca(NODE *vet, char *nomeArquivo) {
	int i = 0;
	int count = 0;
	for(i = 0; i < tamV; ++i) {
		if(strcmp(vet[i].nome, nomeArquivo) == 0) {
			printf("O arquivo está cadastrado no sistema!\n");
			printf("O arquivo inicia-se na posicao %d\n", i);
			break;
		}
	}

	if(i >= tamV) {
		printf("O arquivo NÃO está cadastrado no sistema!\n");
		return -1;
	}

	printf("Os enderecos são:\n");
	for(NODE *aux = &vet[i]; aux != NULL; aux = aux->next) {
		printf("%p\n", aux);
		++count;
	}
	printf("A quantidade de blocos que está sendo utilizado eh: %d\n", count);

	return i;
}


void impressaoGrafica(NODE *vet, char *nomeArquivo) {
	int i = busca(vet, nomeArquivo);
	if(i == -1)
		return;

	for(NODE *aux = &vet[i]; aux != NULL; aux = aux->next) {
		printf("%d -> ", aux->posicao);
	}
	printf("NULL\n");

	return;
}