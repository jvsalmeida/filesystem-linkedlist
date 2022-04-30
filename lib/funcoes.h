#ifndef FUNCOES_H
#define FUNCOES_H


/**
*	Nesta função, inicializa-se o vetor, que é utilizado como o
*	local de armazamento dos arquivos, de modo que todas as partes de vetor estejam 
*	com valor default. Assim, a situacao é zero, não há nome, não há conteúdo, e o 
*	ponteiro é nulo.
*
*\param um ponteiro para o vetor principal que guarda os arquivos.
*
*/
void inicializar(NODE *);

/**
*	Esta função verifica se a alguma posição do vetor está vazia,
*	assim, retornando a primeira posição livre.
*
*\param um ponteiro para o vetor principal que guarda o conteúdo dos arquivos.
*\return um inteiro, sendo este a primeira posição livre -sem conteúdo- do vetor.
*
*/
int verificacao(NODE *);

/**
*	Esta função insere no vetor, caso tenha espaço suficiente, o arquivo em partes.
*	Isso será determinado pela quantidade de bytes que está sendo lido por vez.
*	Caso tenha espaço, o arquivo será dividido nas posições livres do vetor.
*	Assim, nas posições ocupadas pelo arquivo, a 'situacao' receberá 1 e,
*	aquela posição no campo 'nome', receberá o nome do arquivo.
*
*\param um ponteiro para o vetor principal que guardará o conteúdo dos arquivos.
*\param um ponteiro para uma string que contém o nome do arquivo a ser inserido no vetor.
*
*/
void insercao(NODE *, char *);

/**
*	Esta função recebe o nome de um arquivo e verifica qual é a primeira posição
*	em que o arquivo se encontra. Assim, o arquivo será deletado do sistema, fazendo
*	com que todos os campos das posições em que o arquivo se encontra voltem ao seu valor
*	default.
*\param um ponteiro para o vetor principal que guarda o conteúdo dos arquivos.
*\param	um ponteiro para uma string, que será o nome do arquivo a ser deletado.
*
*/
void delecao(NODE *, char *);

/**
*	Esta função recebe o nome de um arquivo. Deste modo, a função dirá se ele está
*	cadastrado ou não, e assim, dirá quais são os endereços de memória e quantas posições do vetor
*	este ocupa.
*\param um ponteiro para o vetor principal que guarda o conteúdo dos arquivos.
*\param um ponteiro para uma string, que será o nome do arquivo a ser buscado.
*\return um inteiro, que é a primeira posição do vetor em que o arquivo se encontra.
*
*/
int busca(NODE *, char *);


/**
*	Esta função receberá um nome de arquivo e dirá em quais posições do vetor o
*	arquivo se encontra.
*
*\param um ponteiro para o vetor principal que guarda o conteúdo dos arquivos.
*\param um ponteiro para uma string, esta será o nome de um arquivo.
*
*/
void impressaoGrafica(NODE *, char *);

#endif