//JVIDA-KLMN - Projeto Jogo da Vida
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

//------------------------------------------------------MODEL CPP------------------------------------------------------

#include "JVIDA_KLMN_Model.h"

typedef struct celula
{
 int linha, coluna; //as 2 coordenadas da celula
 struct celula *next; //ponteiro (endereco) para a proxima celula
} tipoCel;

tipoCel *primeiraViva, *primeiraMortaVizinha, *primeiraProxGeracao;

typedef struct celulaSemPonteiro
{
	int linha, coluna;
} tipoCelSP;

typedef struct lista
{
	int tamanho; //conta o tamanho da lista ate no maximo 400 celulas vivas iniciais
	tipoCelSP L[400];
	
} tipoLista;

tipoLista LVivo; //nao contem os ponteiros pois as celulas serao gravadas sequencialmente em disco

//criar o array LConfig para abrigar os conjuntos de celulas vivas iniciais
struct arquivo
{
	tipoLista ListaTot; //lista do total de celulas vivas
} LConfig[50]; //gravacao em disco de ate 50 listas de celulas vivas iniciais