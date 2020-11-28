#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <err.h>

#define MAXTAM 1000
#define bool short
#define true 1
#define false 0

typedef struct Jogador {
  int id;
  int altura;
  int peso;
  char nome[100];
  char universidade[100];
  char anoNascimento[100];
  char cidadeNascimento[100];
  char estadoNascimento[100];
}
Jogador;

typedef struct {
  Jogador players[MAXTAM]; // Elementos da pilha

}
Lista;

//TIPO CELULA ===================================================================
typedef struct Celula {
  Jogador elemento; // Elemento inserido na celula.
  struct Celula * prox; // Aponta a celula prox.
}
Celula;

Celula * novaCelula(Jogador elemento) {
  Celula * nova = (Celula * ) malloc(sizeof(Celula));
  nova -> elemento = elemento;
  nova -> prox = NULL;
  return nova;
}

//PILHA PROPRIAMENTE DITA =======================================================
Celula * topo; // Sem celula cabeca.

/****************************/

void le_Jogador(char PK[]);
char * replace(char * s);
void imprimir(Jogador x, int pos);
void tratamentoString(char ent_dados[]);

/***************************/

void inserirFim(Jogador x);
void mostrar();
void mostrarP(Celula i,int j);
void removerFim();
Jogador remover(char pos[]);
void le_List(char PK[]);
void tratamento_String_list(char ent_dados[]);
void start();

/***************************/

// Jogador p[1000];
int countP = 0;
Jogador p;
Lista list;

int main(int argc, char * argv[]) {
  start();
  char PK[1000];

  scanf("%s", PK);

  while (strcmp(PK, "FIM") != 0) {

    le_Jogador(PK);
    inserirFim(p);
    countP++;
    scanf("%s", PK);

  } //end while

  int count = 0;
  int qtdArquivo = 0;
  char * operacao;
  char * objeto;
  char * posicao;

  scanf("%d", & qtdArquivo);

  while (count < qtdArquivo) {

    scanf(" %[^\n]s", PK);

    if (PK[0] == 'I') {

      operacao = strtok(PK, " ");
      objeto = strtok(NULL, " ");
      le_Jogador(objeto);
      inserirFim(p);

    } //end inserir()
    if (PK[0] == 'R') {

      removerFim();

    } //end remover()

    count++;

  } //end while

  mostrar();
} //end main

void start() {
  topo = NULL;
}

void inserirFim(Jogador x) {

  Celula * tmp = novaCelula(x);
  tmp -> prox = topo;
  topo = tmp;
  tmp = NULL;

} //end inserirFim

void removerFim() {

  if (topo == NULL) {
    errx(1, "Erro ao remover!");
  }

  Jogador resp = topo -> elemento;
  printf("%s%s\n", "(R) ", topo -> elemento.nome);
  Celula * tmp = topo;
  topo = topo -> prox;
  tmp -> prox = NULL;
  free(tmp);
  tmp = NULL;

} //end removerFim

void le_Jogador(char PK[]) {

  char ent_dados[1000];
  char * sep;
  char * separar;
  FILE * jogador = fopen("/tmp/players.csv", "r");

  //fgets(ent_dados,1000,jogador);

  do {

    fgets(ent_dados, 1000, jogador);

    strcpy(ent_dados, replace(ent_dados));

    separar = strdup(ent_dados);

    sep = strsep( & separar, ",");

    if (strcmp(sep, PK) == 0) {
      tratamentoString(ent_dados);
    }

  } while (!feof(jogador) && strcmp(sep, PK) != 0);

  fclose(jogador);

} //end le_Jogador

void tratamentoString(char ent_dados[]) {

  strcpy(ent_dados, strtok(ent_dados, ","));
  p.id = atoi(ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  strcpy(p.nome, ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  p.altura = atoi(ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  p.peso = atoi(ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  strcpy(p.anoNascimento, ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  strcpy(p.universidade, ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  strcpy(p.cidadeNascimento, ent_dados);

  strcpy(ent_dados, strtok(NULL, ","));
  strcpy(p.estadoNascimento, ent_dados);

} //end tratamentoString


char * replace(char s[]) {
  char nova[300] = "";
  int j = 0;
  int ult = strlen(s);

  for (int i = 0; i < strlen(s) - 1; i++) {

    if (s[i] == ',' && s[i - 1] == ',') {
      setbuf(stdin, NULL);
      strcat(nova, "nao informado");
      j = strlen(nova);
    }
    nova[j] = s[i];

    j++;
  }

  if (nova[strlen(nova) - 1] == ',')
    strcat(nova, "nao informado");

  char * saida = nova;
  return saida;
}

void imprimir(Jogador x, int pos) {
  // int tam;

  printf("%s%d%s", "[", pos, "]");
  printf("%s", " ## ");
  printf("%s", x.nome);
  printf("%s", " ## ");
  printf("%d", x.altura);
  printf("%s", " ## ");
  printf("%d", x.peso);
  printf("%s", " ## ");
  printf("%s", x.universidade);
  printf("%s", " ## ");
  printf("%s", x.anoNascimento);
  printf("%s", " ## ");
  printf("%s", x.cidadeNascimento);
  printf("%s", " ## ");
  printf("%s", x.estadoNascimento);
  printf(" ##\n");

} //imprimir

  void mostrarRec(Celula* i , int pos){

      if(i != NULL) {
                mostrarRec(i->prox ,--pos);
                imprimir(i->elemento,pos);
                
      }
   }

void mostrar(){

   mostrarRec(topo, 142);
}
   
