//JVIDA-KLMN - Projeto Jogo da Vida
//GRUPO: F.A.M.I.L.I.A. (Fundacao Amigos da Modernidade Impetuosamente Leviana de Inquietos Anafilaticos)
//Kaua Cordeiro, Luan Capella, Manoela Martedi, Nicolas Mariano

//------------------------------------------------------CONTROLLER H------------------------------------------------------

void fDefinirTamanho(); //SIM nao faz uso de ponteiros
void fIniciarJogo(); //SIM menu e tudo mais
void fGerarMatriz(); //SIM tambem usada para limpar matriz

void fDefinirCelulas(); //IMP
void fAtualizarVizinhos(); //LOG nao faz uso de ponteiros
void fIniciarProcesso(); //IMP
void fProximaGeracao(); //LOG nao faz uso de ponteiros
void fTransferirGeracao(); //LOG transferir listas ligadas para a matriz principal

void fLimparMatriz ();
void fIniciarListas();
void fLiberarLista(tipoCel *aux, int total);
void fSubAdicionarVizinho (int i, int j); //adiciona celula vizinha a lista
bool fSubVerificarVizinho(int i, int j); //verifica se celula ja pertence a lista
void fAdicionarCelula(int i, int j); //inclusao de uma celula na lista de celulas vivas
void fExcluirCelula(int i, int j); //exclui uma celula viva
void fSubAdicionarProxGeracao(int i, int j); //adiciona celula viva para a proxima geracao

void fDeletarConfig();
void fRecuperarCelulas();
void fCarregarConfig();
void fGravarCelulas();