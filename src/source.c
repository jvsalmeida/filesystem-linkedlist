#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/include.h"
#include "../lib/funcoes.h"


int main() {
	inicializar(vet);

	while(comando != 6) {
		printf("-------------------------------------------\n");
		printf("Digite 1 para Inserir um arquivo no sistema\n");
		printf("Digite 2 para Remover um arquivo do sistema\n");
		printf("Digite 3 para Buscar  um arquivo no sistema\n");
		printf("Digite 4 para Imprimir Graficamente um arquivo do sistema\n");
		printf("Digite 5 para Imprimir a atual situacao do vetor\n");
		printf("Digite 6 para Sair\n");
		printf("-------------------------------------------\n");

		scanf(" %d", &comando);

		// insercao
		if(comando == 1) {
			printf("Digite o nome do arquivo a ser inserido:\n");
			scanf(" %s", nomeArquivo);
			novo = strdup(nomeArquivo);
			insercao(vet, novo);

		// remocao  	
		} else if(comando == 2) {
			printf("Digite o nome do arquivo a ser deletado:\n");
			scanf(" %s", nomeArquivo);
			novo = strdup(nomeArquivo);
			delecao(vet, novo);
		
		// busca
		} else if(comando == 3) {
			printf("Digite o nome do arquivo que será buscado:\n");
			scanf(" %s", nomeArquivo);
			novo = strdup(nomeArquivo);
			busca(vet, novo);
		}

		// impressao grafica
		else if(comando == 4) {
			printf("Digite o nome do arquivo que será impresso:\n");
			scanf(" %s", nomeArquivo);
			novo = strdup(nomeArquivo);
			impressaoGrafica(vet, novo);	
		}

		// imprimir
		else if(comando == 5) {
			printf("Obs: se a Situação for 0, quer dizer que aquela posição está vazia.\n");
			printf("Obs: se a Situação for 1, quer dizer que aquela posição está preenchida por um arquivo.\n");
			printf("NOME         SITUACAO   POSICAO \n");
			for(int i = 0; i < tamV; ++i) {
				printf("%s ---- %d -------- %d\n", vet[i].nome, vet[i].situacao, i);
			}
			printf("-----------------------------------------\n");
		}
	}

	return 0;
}