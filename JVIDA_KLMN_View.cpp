//JVIDA-KLMN - Projeto Jogo da Vida
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

//------------------------------------------------------VIEW CPP------------------------------------------------------

#include "JVIDA_KLMN_View.h"

int fEscolhaInt ()
{
	int escolha;
	scanf("%d", &escolha);
	
	return escolha;
}

char fEscolhaChar()
{
	char opcaoEscolha[2];
	do
	{
		fMensagem ("Opcao: ");
		fflush(stdin); //limpar o buffer
		
		scanf("%c", &opcaoEscolha[0]);
		
		opcaoEscolha[0] = tolower(opcaoEscolha[0]);
		
		if (opcaoEscolha[0] == '\0' || (opcaoEscolha[0] != 's' && opcaoEscolha[0] != 'n')) //caso nada tenha sido digitado
		{
			fMensagem ("\nOpcao invalida.\n\n");
			continue;
		}
		
		break;
		
	} while (1);
	
	return (opcaoEscolha[0]);
}

void fMensagem (char *msg)
{
	printf("%s", msg);
}

void fPrintMenu () {
	
    printf("+---------------------------------------------------------+\n");
    printf("|                     MENU PRINCIPAL                      |\n");
    printf("+---------------------------------------------------------+\n");
    printf("|  1 - Apresentar o Mapa                                  |\n");
    printf("|  2 - Limpar o Mapa                                      |\n");
    printf("|  3 - Incluir/excluir celulas vivas                      |\n");
    printf("|  4 - Mostrar/Esconder os mortos-vizinhos                |\n");
    printf("|  5 - INICIAR O PROCESSO                                 |\n");
    printf("|  6 - Apresentar as Listas                               |\n");
    printf("|  7 - Gravar uma geracao inicial                         |\n");
    printf("|  8 - Recuperar uma geracao inicial cadastrada           |\n");
    printf("|  9 - Limpar o cadastro de geracoes iniciais cadastradas |\n");
    printf("| 10 - Regras de evolucao das celulas                     |\n");
    printf("|  0 - Sair                                               |\n");
    printf("+---------------------------------------------------------+\n");
	
	printf("\nOpcao: ");
}

void fPrintTitulos (int funcao)
{
	switch(funcao)
	{
		case 1:
		{
			printf("\n    ___  ________  ________  ________          ________  ________          ___      ___ ___  ________  ________     \n");
			printf("   |\\  \\|\\   __  \\|\\   ____\\|\\   __  \\        |\\   ___ \\|\\   __  \\        |\\  \\    /  /|\\  \\|\\   ___ \\|\\   __  \\    \n");
			printf("   \\ \\  \\ \\  \\|\\  \\ \\  \\___|\\ \\  \\|\\  \\       \\ \\  \\_|\\ \\ \\  \\|\\  \\       \\ \\  \\  /  / | \\  \\ \\  \\_|\\ \\ \\  \\|\\  \\   \n");
			printf(" __ \\ \\  \\ \\  \\\\\\  \\ \\  \\  __\\ \\  \\\\\\  \\       \\ \\  \\ \\\\ \\ \\   __  \\       \\ \\  \\/  / / \\ \\  \\ \\  \\ \\\\ \\ \\   __  \\  \n");
			printf("|\\  \\\\_\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\ \\  \\\\\\  \\       \\ \\  \\_\\\\ \\ \\  \\ \\  \\       \\ \\    / /   \\ \\  \\ \\  \\_\\\\ \\ \\  \\ \\  \\ \n");
			printf("\\ \\________\\ \\_______\\ \\_______\\ \\_______\\       \\ \\_______\\ \\__\\ \\__\\       \\ \\__/ /     \\ \\__\\ \\_______\\ \\__\\ \\__\\\ \n");
			printf(" \\|________|\\|_______|\\|_______|\\|_______|        \\|_______|\\|__|\\|__|        \\|__|/       \\|__|\\|_______|\\|__|\\|__|\n\n");
			break;
		}
		case 2: //alterar celulas vivas
		{
			printf("\n+-------------------------------------+\n");
			printf("|   DEFINICAO DE CELULAS: GERACAO 1   |");
			printf("\n+-------------------------------------+\n");	
			break;
		}
		case 3: //mostrar ou esconder mortos vizinhos
		{
			if (mostraVizinhos) //se os vizinhos estiverem previamente a mostra
			{
				printf("\n+------------------------------------+\n");
				printf("|     MORTOS VIZINHOS ESCONDIDOS     |");
				printf("\n+------------------------------------+\n");	
				break;
			}
			
			printf("\n+------------------------------------+\n");
			printf("|      MORTOS VIZINHOS A MOSTRA      |");
			printf("\n+------------------------------------+\n");	
			break;
		}
	}
}

void fPrintMatriz () //mostra a matriz de seres
{
	fAtualizarVizinhos();

	printf("\tMapa:\n\n");

    printf("   ");
    for (int j = 0; j < dim; j++) {
        printf("%2d ", j+1);
    }
    printf("\n");

    for (int i = 0 ; i < dim ; i++) {
        printf("%2d ", i+1);
        for (int j = 0; j < dim; j++) {
        	if (mostraVizinhos == false && matriz[i][j] == '+')
        		printf("%2c ", '.');
        	else
        		printf("%2c ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("Geracao %d: %d celulas vivas.\n", geracao, totalVivos);
    
    mostrarCoordVivas();
    mostrarVizinhosMortos();
    
}

void mostrarCoordVivas() //apresenta o indice de cada celula viva
{
	tipoCel *aux;
	aux = primeiraViva;
	int cont = 0; //contagem para que, no terminal, a lista nao ultrapasse os limites da tela
	if (totalVivos > 0) //se houverem celulas vivas
	{
		printf("Celulas Vivas: \n");
		while (aux->next != NULL) //para quando alcancar o ultimo item da lista, que aponta para null
		{
			if (cont == 20)
			{
				putchar('\n');
				cont = 0;
			}
		
			printf("[%d %d] ", (aux->linha)+1, (aux->coluna)+1);
			aux = aux->next; //equivale a i++ em arrays //caminha para o proximo ponteiro
			
			cont++;
		}
		printf("[%d %d]", (aux->linha)+1, (aux->coluna)+1); //imprime a ultima celula
	}
}

void mostrarVizinhosMortos() //apresenta o indice de cada celula viva da proxima geracao
{
	tipoCel *aux;
	aux = primeiraMortaVizinha;
	int cont = 0; //contagem para que, no terminal, a lista nao ultrapasse os limites da tela
	if (totalMortosVizinhos > 0) //se houverem celulas vivas
	{
		printf("\nMortos vizinhos: \n");
		while (aux->next != NULL) //para quando alcancar o ultimo item da lista, que aponta para null
		{
			if (cont == 20)
			{
				putchar('\n');
				cont = 0;
			}
			
			printf("[%d %d] ", (aux->linha)+1, (aux->coluna)+1);
			aux = aux->next; //equivale a i++ em arrays //caminha para o proximo ponteiro
			
			cont++;
		}
		printf("[%d %d]\n", (aux->linha)+1, (aux->coluna)+1); //imprime a ultima celula
	}
}

void mostrarListaSalvamento()
{
	for (int i = 0; i < LVivo.tamanho; i++)
	{
		printf("[%d|%d]\n", LVivo.L[i].linha, LVivo.L[i].coluna);
		system("pause");
	}
}

