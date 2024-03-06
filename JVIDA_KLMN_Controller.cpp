//JVIDA-KLMN - Projeto Jogo da Vida
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

//------------------------------------------------------CONTROLLER CPP------------------------------------------------------

#include "JVIDA_KLMN_Controller.h"
#include "JVIDA_KLMN_View.cpp"

void fDefinirTamanho () { //define o tamanho para o mundo

	fPrintTitulos(1);
	do
	{
		fMensagem("\nEscolha um tamanho para seu mundo (entre 10 e 60): ");
		dim = fEscolhaInt();
		if (dim>60 || dim<10)
		{
			printf("\nOpcao invalida.\n\n");
			continue;
		}
		break;
	} while (1);
}

void fGerarMatriz () {
	
	int i, j;
	fIniciarListas();
	
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			matriz[i][j] = '.';
}

void fLimparMatriz () {
	
	int i, j;
	
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			matriz[i][j] = '.';
}

void fIniciarListas() //iniciar as listas vazias
{
	fLiberarLista(primeiraViva, totalVivos);
	fLiberarLista(primeiraMortaVizinha, totalMortosVizinhos);
	fLiberarLista(primeiraProxGeracao, totalProxGeracao);
	
	primeiraViva = primeiraMortaVizinha = primeiraProxGeracao = NULL; //inicializar os ponteiros como vazios
	totalVivos = totalMortosVizinhos = totalProxGeracao = 0; //inicialmente listas vazias
}

void fLiberarLista(tipoCel *aux, int total) //libera memoria de uma Lista
{
	if(aux == NULL || total == 0) //ja esta liberada
		return;
		
	tipoCel *aux2;
	
	do
	{
		aux2 = aux;
		aux = aux->next;
		free(aux2); //libera memoria
		
	} while(aux != NULL);
}

void fIniciarJogo () //inicio do jogo
{
	
	fGerarMatriz();
	putchar('\n');
	
	int opcMenu;
    
    do
	{
		putchar('\n');
		
		fPrintMenu();
		
		opcMenu = fEscolhaInt(); //guardar a opcao escolhida pelo usuario
		
		switch(opcMenu) //opcao para cada saida do menu
		{
			case 1: //apresenta o mapa
			{
				system("cls");
				fPrintTitulos(1);
				fPrintMatriz();
				break;
			}
			case 2: //limpa o mapa
			{
				system("cls");
				fPrintTitulos(1);
				fGerarMatriz();
				break;
			}
			case 3: //altera celulas vivas
			{
				system("cls");
				fPrintTitulos(1);
				fDefinirCelulas();
				break;
			}
			case 4: //mostra ou esconde mortos vizinhos
			{
				system("cls");
				fPrintTitulos(1);
				fPrintTitulos(3);
				mostraVizinhos = (mostraVizinhos == true) ? false : true;
				break;
			}
			case 5: //inicia o processo
			{
				system("cls");
				fPrintTitulos(1);
				fIniciarProcesso();
				break;
			}
			case 6: //apresenta as listas
			{
				system("cls");
				fPrintTitulos(1);
				mostrarCoordVivas();
				mostrarVizinhosMortos();
				break;
			}
			case 7: //grava uma geracao inicial
			{
				system("cls");
				fPrintTitulos(1);
				fGravarCelulas();
				break;
			}
			case 8: //recupera uma geracao inicial cadastrada
			{
				system("cls");
				fPrintTitulos(1);
				fRecuperarCelulas();
				break;
			}
			case 9: //limpa o cadastro
			{
				system("cls");
				fPrintTitulos(1);
				fDeletarConfig();
				break;
			}
			case 10: //imprime regras
			{
				system("cls");
				fPrintTitulos(1);
				fMensagem("\nFuncao ainda nao implementada.\n\n");
				break;
			}
			case 0: //sair do jogo
			{
				system("cls");
				fPrintTitulos(1);
				fIniciarListas();
				fMensagem ("\nSaindo...\n");
				return;
			}
			default: //invalido
			{
				system("cls");
				fPrintTitulos(1);
				fMensagem ("\nOpcao invalida.");
				break;
			}
		}
	} while (opcMenu != 0); //condicao de parada
}

void fDefinirCelulas () { //opcao 3 do menu

	int linha, coluna;
	char opcaoExclui[2];

	fPrintTitulos(2); //mostrar o segundo titulo da funcao

	do {
		
		fPrintMatriz(); //mostrar a matriz atualizada
		
		do
		{
			fMensagem("\nDigite a linha (-1 para sair): ");
			
			linha = fEscolhaInt();
			
			if (linha == -1)
			{
				system("cls");
				fPrintTitulos(1);
				fMensagem("\nSaindo...\n");
				return;
			}
				
			if (linha > dim || linha < 1)
			{
				fMensagem("\nValor Invalido.\n");
				continue;
			}
			
			linha = linha-1;

			break;
		} while (1);
		
		do
		{
			fMensagem("\nDigite a coluna (-1 para sair): ");
			
			coluna = fEscolhaInt();
			
			if (coluna == -1)
			{
				system("cls");
				fPrintTitulos(1);
				fMensagem("\nSaindo...\n");
				return;
			}
				
			if (coluna > dim || coluna < 1)
			{
				fMensagem("\nValor Invalido.\n");
				continue;
			}
			
			coluna = coluna-1;

			break;
		} while (1);
		
		if (matriz[linha][coluna] == 'O') {
			fMensagem ("\nA coordenada ja possui uma celula. Deseja exclui-la? (s/n)\n");
			opcaoExclui[0] = fEscolhaChar();
			
			system("cls");
			fPrintTitulos(1);
			fPrintTitulos(2); //mostrar o segundo titulo da funcao
			
			if (opcaoExclui[0] == 's')
			{
				fExcluirCelula(linha, coluna);
				fMensagem("\nExclusao feita com sucesso.\n\n");
			}
			continue;
		}
		
		fAdicionarCelula(linha, coluna);
		
		system("cls");
		fPrintTitulos(1);
		fPrintTitulos(2); //mostrar o segundo titulo da funcao

	} while (1);
	
}

//exclui uma celula viva
void fExcluirCelula(int i, int j)
{
	tipoCel *aux, *aux2; //define 2 ponteiros auxiliares
	aux = primeiraViva; aux2 = aux;
	
	//aux 2 tem o papel de guardar a celula anterior a aux;
	//necessaria pra quando deletar aux, a anterior apontar para a posterior a aux
	
	if (totalVivos == 0)
		return;
	
	while (aux -> linha != i || aux -> coluna != j)
	{
		aux2 = aux;
		aux = aux -> next;
	}
	if (aux -> linha == i && aux -> coluna == j)
	{
		if (aux2 == aux)
			primeiraViva = aux -> next;
		else
			aux2 -> next = aux -> next;
		free(aux);
	}
	
	//aux agora possui o endereco da celula a ser deletada
	//aux2 possui o endereco da celula anterior a aux na lista
	matriz[i][j] = '.';
	totalVivos--;
	
}

//inclusao de uma celula na lista de celulas vivas
void fAdicionarCelula(int i, int j)
{
	tipoCel *aux;
	aux = (tipoCel*)malloc(sizeof(tipoCel));
	if (aux == NULL)
	{
		fMensagem("Sem espaco na memoria para inclusao de uma celula viva.\n\n");
		return;
	}
	
	aux -> linha = i; aux -> coluna = j;
	
	if (totalVivos == 0) //lista vazia
	{
		//primeiro elemento colocado na ultima posicao
		primeiraViva = aux;
		primeiraViva -> next = NULL; //aponta para NULL
	}
	else
	{
		//novas celulas colocadas na posicao anterior a ultima
		aux -> next = primeiraViva;
		primeiraViva = aux;
	}
	
	matriz[i][j] = 'O';
	totalVivos++;
}

//percorre a lista de celulas vivas e define as 8 vizinhas de cada uma
void fAtualizarVizinhos() {

	int ii, jj;
	struct
	{
		int lin, col;
	} a, b, c, d, e, f, g, h;
	
	totalMortosVizinhos = 0; //lista sera reiniciada
	
	//ponteiro auxiliar aponta para o inicio da lista de celulas vivas
	tipoCel *aux; aux = primeiraViva;
	
	if (totalVivos == 0) //sem celulas vivas para ter vizinhos
		return;
	
	do
	{
		
		//i e j recebem as linhas e colunas de cada celula viva (repeticao)
		ii = aux->linha;
		jj = aux->coluna;
		
		a.lin = ii-1; a.col = jj-1;
		b.lin = ii-1; b.col = jj;
		c.lin = ii-1; c.col = jj+1;
		d.lin = ii; d.col = jj-1;
		e.lin = ii; e.col = jj+1;
		f.lin = ii+1; f.col = jj-1;
		g.lin = ii+1; g.col = jj;
		h.lin = ii+1; h.col = jj+1;
		
		fSubAdicionarVizinho(a.lin, a.col);
		fSubAdicionarVizinho(b.lin, b.col);
		fSubAdicionarVizinho(c.lin, c.col);
		fSubAdicionarVizinho(d.lin, d.col);
		fSubAdicionarVizinho(e.lin, e.col);
		fSubAdicionarVizinho(f.lin, f.col);
		fSubAdicionarVizinho(g.lin, g.col);
		fSubAdicionarVizinho(h.lin, h.col);
		
		if (aux -> next == NULL)
			break;
		
		aux = aux -> next;

	} while (1);
	
}

//inclui uma celula na lista de mortos vizinhos SE ELA NAO ESTIVER INCLUSA AINDA
void fSubAdicionarVizinho (int i, int j)
{
	
	if (i < 0 || i > dim || j < 0 || j > dim) //fora dos limites
		return;
	if (matriz[i][j] == 'O') //celula viva
		return;
	if (fSubVerificarVizinho(i, j) == true) //true: morto-vizinho ja na lista
		return;
	
	//aloca memoria para um novo morto vizinho na lista
	tipoCel *aux = (tipoCel*)malloc(sizeof(tipoCel));
	if (aux == NULL) //erro
	{
		fMensagem("Sem espaco na memoria para inclusao de celula morta-vizinha.\n\n");
		return;
	}
	
	aux -> linha = i; aux -> coluna = j;
	
	if (totalMortosVizinhos == 0)
	{
		//ponteiro primeiraMortaVizinha guarda o endereco da primeira celula da lista
		primeiraMortaVizinha = aux;
		//como aux e a primeira celula a ser adicionada, ela aponta para o fim da lista (NULL).
		primeiraMortaVizinha -> next = NULL;
	}
	else
	{
		//nova celula, colocada no comeco da lista, aponta para a antiga primeira celula
		aux -> next = primeiraMortaVizinha;
		//ponteiro primeiraMortaVizinha guarda o endereco da primeira celula da lista
		primeiraMortaVizinha = aux;
	}
	
	matriz[i][j] = '+';
	totalMortosVizinhos++;
		
}

//percorre a lista de mortos vizinhos e verifica se algum deles possui a linha i e coluna j
bool fSubVerificarVizinho(int i, int j)
{
	tipoCel *aux; aux = primeiraMortaVizinha;
	
	if (totalMortosVizinhos == 0)
		return false;
	
	do
	{
		if (aux -> linha == i && aux -> coluna == j)
			return true;
		
		aux = aux -> next;
		
	} while (aux != NULL);
}

void fIniciarProcesso() {
	
	int geracoes, tempo;
	int cont = 1;
	char tecla;
	
	do
	{
		fMensagem("\nQuantidade de Geracoes (-1 para sair): ");
		geracoes = fEscolhaInt();
		
		if (geracoes == -1)
			return;
		else if (geracoes < 1)
		{
			fMensagem("\nNumero invalido.\n");
			continue;
		}
		
		break;
		
	} while (1);
	
	do
	{
		fMensagem("\nVelocidade da simulacao em segundos (0 = passo-a-passo): ");
		tempo = fEscolhaInt();
		
		if (tempo < 0)
		{
			fMensagem("\nTempo invalido.\n");
			continue;
		}
		
		break;
		
	} while (1);
	
	do
	{
		system("cls");
		fPrintTitulos(1);
		fPrintMatriz();
		
		if (tempo == 0)
		{
			fMensagem("\nPressione 1 para continuar.\n");
			do
			{
				tecla = getch();
			} while (tecla != '1'); 
		}
		else
		{
			sleep(tempo);
		}
		
		fLimparMatriz(); //limpa a matriz original para receber os novos valores da proxima geracao por meio das listas ligadas
		fProximaGeracao(); //armazenar na lista ligada de ponteiro primeiraProxGeracao
		fTransferirGeracao(); //ETAPA 3: transfere a matrix auxiliar para a principal
		//ALTERAR transferirGeracao de forma que ela transcreva as listas ligadas para a matriz principal
		
		cont++;
		geracao++;
	
	} while (cont < geracoes);
	
	system("cls");
	fPrintTitulos(1);
	fPrintMatriz();
	
	fMensagem("\nFim das Geracoes.\nPressione uma tecla para continuar.\n");
	getch();
	
	system("cls");
	fPrintTitulos(1);
	
	return;
	
}

void fProximaGeracao() { //ESSA FUNCAO ESTA CORRETA
	
	int ii, jj, vii, vjj, qtdVizinhos;
	
	fLiberarLista(primeiraProxGeracao, totalProxGeracao); //limpa lista da proxima geracao
	primeiraProxGeracao = NULL;
	
	mostrarCoordVivas();
	
	if (primeiraViva == NULL)
		return;

	tipoCel *aux, *aux2;
	aux = primeiraViva;
	
	do
	{
		
		qtdVizinhos = 0;
		
		ii = aux->linha; jj = aux->coluna;
		aux2 = primeiraViva;
		
		do //inicia-se a contagem de celulas vizinhas
		{
			
			vii = aux2->linha;
			vjj = aux2->coluna;
			
			if (vii != ii || vjj != jj) //se nao for a mesma celula
				if(abs(ii-vii) <= 1 && abs(jj-vjj) <= 1) //se e vizinho
				{
					qtdVizinhos++;
					//obs: abs = funcao que recebe o modulo (valor ABSoluto)
				}
			
			aux2 = aux2->next;
			
		} while(aux2 != NULL);

		//ATITUDE sobre a celula viva conforme a qtd.de vizinhos
		if (qtdVizinhos == 2 || qtdVizinhos == 3)
			fSubAdicionarProxGeracao(ii,jj); //sobrevive na proxima geracao
			
		aux = aux->next;
		
	} while(aux != NULL);
	
	if (primeiraMortaVizinha == NULL)
		return;
	
	aux = primeiraMortaVizinha;
	
	do
	{
		qtdVizinhos = 0;
		
		ii = aux -> linha; jj = aux -> coluna;
		
		aux2 = primeiraViva;
		
		do
		{
			vii = aux2->linha; vjj = aux2->coluna;
			
			if (abs(ii-vii) <= 1 && abs(jj-vjj) <= 1)
			{
				qtdVizinhos++;
				//obs: abs = funcao que recebe o modulo (valor ABSoluto)
			}
			
			aux2 = aux2 -> next;
			
		} while (aux2 != NULL);
		
		//ATITUDE sobre a celula morta conforme a quantidade de vizinhos vivos
		if (qtdVizinhos == 3)
			fSubAdicionarProxGeracao(ii,jj); //sobrevive na proxima geracao
			
		aux = aux -> next;
		
	} while(aux != NULL);
	
}

void fSubAdicionarProxGeracao(int i, int j)
{
	tipoCel *aux;
	
	aux = (tipoCel*)malloc(sizeof(tipoCel)); //define o ponteiro e aloca memoria para uma celula
	if (aux == NULL) //erro
	{
		fMensagem("Sem espaco na memoria para inclusao de uma celula viva para a proxima geracao.\n\n");
		return;
	}
	
	aux -> linha = i; //usa-se -> para acessar um elemento de uma estrutura quando utilizamos ponteiros
	aux -> coluna = j; //linha e coluna recebem as coordenadas digitadas em fDefinirCelulas
	
	if (totalProxGeracao == 0)
	{ //o primeiro elemento da lista vai ser colocado na ultima posicao, e assim por diante
		primeiraProxGeracao = aux; //agora a lista contem 1 celula
		primeiraProxGeracao -> next = NULL; //esta unica celula aponta para o nada, por ser a ultima
	}
	else //lista nao esta vazia
	{ //novas celulas sao colocadas na posicao anterior a ultima celula
		aux -> next = primeiraProxGeracao; //a nova celula aponta para a celula anterior
		primeiraProxGeracao = aux; //o inicio da lista passa a ser a nova celula
	}
	
	totalProxGeracao++; //total de celulas vivas incrementado
}

void fTransferirGeracao()
{
	
	fLiberarLista(primeiraViva, totalVivos);
	fLiberarLista(primeiraMortaVizinha, totalMortosVizinhos);
	
	if (totalProxGeracao == 0)
		return;
	
	primeiraViva = primeiraProxGeracao;
	totalVivos = totalProxGeracao;
	
	primeiraProxGeracao = NULL;
	totalProxGeracao = 0;
	
	//fLiberarLista(primeiraProxGeracao, totalProxGeracao);
	
	tipoCel *aux; aux = primeiraViva;
	
	if (totalVivos == 0)
		return;
	
	do
	{
		matriz[aux -> linha][aux -> coluna] = 'O';
		aux = aux -> next;
		
	} while (aux != NULL);

}

//varre as celulas vivas, coloca suas coordenadas no LConfig e grava uma-a-uma
//num arquivo CONFIG_INIC.
void fGravarCelulas()
{
	int k, indLV; //indice do vetor L da estrutura lVivo
	k = qtdConfig;
	
	if (totalVivos == 0)
		return;
	
	tipoCel *aux;
	aux = primeiraViva;
	indLV = 0; //indice do vetor L da estrutura lVivo
	do
	{
		LVivo.L[indLV].linha = aux->linha;
		LVivo.L[indLV].coluna = aux->coluna;
		indLV++;
		aux = aux->next;
	} while (aux != NULL);
	LVivo.tamanho = totalVivos;
	
	LConfig[k].ListaTot = LVivo;
	
	FILE *fp;
	if ((fp=fopen("CONFIG_INIC", "w")) == NULL)
	{
		fMensagem("ERRO: o arquivo CONFIG_INIC nao pode ser aberto para gravacao.\n");
		return;
	}
	for (int i = 0; i <= qtdConfig; i++)
	{
		if (fwrite(&LConfig[i], sizeof(tipoLista), 1, fp) != 1)
		{
			fMensagem("ERRO: gravacao do arquivo CONFIG_INIC mal sucedida.\n");
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	qtdConfig++;
	fMensagem("Configuracao gravada com sucesso.\n");
}

//carrega o arquivo contendo todas as configuracoes iniciais que foram
//gravadas em disco.
void fCarregarConfig()
{
	int i;
	FILE* fp;

	if ((fp=fopen("CONFIG_INIC", "r")) != NULL)
	{
		qtdConfig = 0;
		i = 0;
		while (!feof(fp)) //enquanto nao for fim de arquivo
		{
			if (fread(&LConfig[i], sizeof(tipoLista), 1, fp) != 1)
			{
				fclose(fp);
				return;
			}
			qtdConfig++;
			i++;
		}
		fclose(fp);
	}
}

void fRecuperarCelulas()
{
	
	fCarregarConfig(); //carregando arquivo com configurações
	
	if (qtdConfig == 0)
	{
		fMensagem("ERRO: nao existe configuracao a recuperar.\n");
		return;
	}
	
	fGerarMatriz ();
	fLiberarLista (primeiraViva, totalVivos); //limpar para receber arquivo
	primeiraViva = NULL; // limpando slot
	totalVivos = 0;

	int k;

	k = ultimaRecup + 1; //indice de LConfig onde estao as celulas a serem recuperadas
	if (k >= qtdConfig)
		k = 0; //volta ao primeiro conjunto de celulas
		
	LVivo = LConfig[k].ListaTot; //obtem a lista das celulas a serem recuperadas
	ultimaRecup = k;
	
	//recuperar a lista de celulas vivas
	//fLiberarLista(primeiraViva, totalVivos);
	
	for (int i = 0; i < LVivo.tamanho; i++)
	{
		fAdicionarCelula(LVivo.L[i].linha, LVivo.L[i].coluna);
	}
	
	fAtualizarVizinhos();//Define vizinhos
	fMensagem("Geracao carregada com sucesso!\n");
	fPrintMatriz();

}

void fDeletarConfig()
{
	if (remove("CONFIG_INIC") != 0)
	{
		fMensagem("ERRO: o arquivo CONFIG_INIC nao pode ser removido.\n");
		return;
	}
	qtdConfig = 0;
	fMensagem("Cadastro removido com sucesso.");
}
