//JVIDA-KLMN - Projeto Jogo da Vida
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

//------------------------------------------------------MODEL H------------------------------------------------------

int dim = 60; //inicializando dim como 60
int opc;
int qtdCelulas = 0; //inicializando a quantidade de celulas como 0 
int geracao = 1; //inicializa a geracao como 1
bool mostraVizinhos = false;
char matriz[60][60]; //inicializando a matriz das celulas
char aux[60][60]; //inicializando a matriz auxiliar - USADA ATE A ETAPA 3

int totalVivos, totalMortosVizinhos, totalProxGeracao;

//para LConfig[50]
int qtdConfig; //quantidade de configuracoes iniciais cadastradas
int ultimaRecup = -1; //indice da ultima configuracao recuperada (0 a 49)