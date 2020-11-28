#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXTAM 5
#include <stdbool.h>
#include <math.h>

int numeroFila = 0;
double soma = 0;

int countPly = 0;

typedef struct Jogador
{
   int id;
   int altura;
   int peso;
   char nome[100];
   char universidade[100];
   char anoNascimento[100];
   char cidadeNascimento[100];
   char estadoNascimento[100];
} Jogador;

typedef struct Fila
{
   Jogador players[1000];
   /* data */
} Fila;

Jogador players[1000];
int contG = 0;

typedef struct Celula
{
   Jogador elemento;    // Elemento inserido na celula.
   struct Celula *prox; // Aponta a celula prox.
   struct Celula *ant;  // Aponta a celula anterior.
} CelulaDupla;

Celula *novaCelula(Jogador elemento)
{
   Celula *nova = (Celula *)malloc(sizeof(Celula));
   nova->elemento = elemento;
   nova->ant = nova->prox = NULL;
   return nova;
}

//LISTA PROPRIAMENTE DITA
Celula *primeiro;
Celula *ultimo;

/****************************/

void le_Jogador(char PK[]);
char *replace(char *s);
void imprimir();
void tratamentoString(char ent_dados[]);

/***************************/
void start(Jogador generico);
void inserir(Jogador x);
void remover();
void imprimir(Jogador x, int i);
void mostrar();
void imprimirR(Jogador x);
bool isFim(char s[]);

/***************************/

// Jogador p[1000];
int countP = 0;
Jogador p;

int main(int argc, char *argv[])
{
   
      //Jogadores *jogadores= (Jogadores*) malloc(sizeof(jogadores));
      start(players[0]);
      bool x;
      int maior = 0, temp2 = 0, cont = 0;
      char temp[100];
      char entrada[1000], entrada2[200];
      fgets(entrada, 1000, stdin);
      entrada[strlen(entrada) - 1] = '\0';

      int numero = 0;

      while (isFim(entrada) != true)
      {
         strcpy(temp, entrada);
         // temp2 = atoi(temp);

         le_Jogador(temp);

         inserir(players[contG]);
         contG++;
         fgets(entrada, 1000, stdin);
         entrada[strlen(entrada) - 1] = '\0';
         cont++;
      }

      cont = 0;
      int cont2 = 0;
      char info[1000];
      int acoes;
      scanf("%d\n", &acoes);
      char letras[10], id[10], posicao[10];

      for (int i = 0; i < acoes+1; i++)
      {
         fgets(info, 1000, stdin);
         info[strlen(info) - 1] = '\0';
        
         for (int j = 0; j < strlen(info); j++)
         {

            // INCERIR
            if (info[0] == 'I')
            {
               if (cont == 0)
               {
                  if (info[j] != ' ')
                  {
                     letras[cont2] = info[j];
                     cont2++;
                  }
                  else if (info[0] == 'I')
                  {
                     cont++;
                     cont2 = 0;
                  }
               }
               else if (cont == 1)
               {
                  id[cont2] = info[j];
                  cont2++;
               }
            }

            // REMOVER

            if (info[0] == 'R')
            {
               remover();
            }
         }

         temp2 = atoi(id);
         le_Jogador(id);
         memset(id, 0, sizeof(id));
         cont = 0, cont2 = 0;

         if (info[0] == 'I')
            inserir(players[contG]);
      }
      mostrar();

      return 0;
   } //end main

   void start(Jogador generico)
   {
      primeiro = novaCelula(generico);
      ultimo = primeiro;

   } //end start

   void inserir(Jogador x)
   {

      if (numeroFila >= MAXTAM)
      {
         CelulaDupla *tmp = primeiro;

         if (tmp->elemento.altura == 0)
         {
            tmp = primeiro->prox;

            soma = soma - tmp->elemento.altura;

            numeroFila--;
            primeiro = primeiro->prox->prox;
            tmp->prox = primeiro->ant = NULL;
         }
         else
         {

            soma = soma - tmp->elemento.altura;

            numeroFila--;

            primeiro = primeiro->prox;
            tmp->prox = primeiro->ant = NULL;
         }
      }

      ultimo->prox = novaCelula(x);
      ultimo->prox->ant = ultimo;
      ultimo = ultimo->prox;

      numeroFila++;
      double media = 0;
      soma = soma + x.altura;
      media = soma / numeroFila;

      int temp2 = 0;
      temp2 = round(media);

      printf("%d\n", temp2);

   } //end inserir()

   void remover()
   {

      if (primeiro == ultimo)
      {
         printf(" Erro ao remover (vazio)! ");
      }

      Celula *tmp = primeiro;

      soma = soma - tmp->elemento.altura;
      imprimirR(tmp->elemento);

      primeiro = primeiro->prox;
      tmp->prox = primeiro->ant = NULL;

      numeroFila--;

      tmp = NULL;
   } //end remover

   void le_Jogador(char PK[])
   {

      char ent_dados[1000];
      char *sep;
      char *separar;
      FILE *jogador = fopen("players.csv", "r");

      //fgets(ent_dados,1000,jogador);

      do
      {

         fgets(ent_dados, 1000, jogador);

         strcpy(ent_dados, replace(ent_dados));

         separar = strdup(ent_dados);

         sep = strsep(&separar, ",");

         if (strcmp(sep, PK) == 0)
         {
            tratamentoString(ent_dados);
         } //end if

      } while (!feof(jogador) && strcmp(sep, PK) != 0);

      fclose(jogador);

   } //end le_Jogador

   void tratamentoString(char ent_dados[])
   {

      strcpy(ent_dados, strtok(ent_dados, ","));
      players[contG].id = atoi(ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      strcpy(players[contG].nome, ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      players[contG].altura = atoi(ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      players[contG].peso = atoi(ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      strcpy(players[contG].anoNascimento, ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      strcpy(players[contG].universidade, ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      strcpy(players[contG].cidadeNascimento, ent_dados);

      strcpy(ent_dados, strtok(NULL, ","));
      strcpy(players[contG].estadoNascimento, ent_dados);

   } //end tratamentoString

   char *replace(char s[])
   {
      char nova[300] = "";
      int j = 0;
      int ult = strlen(s);

      for (int i = 0; i < strlen(s) - 1; i++)
      {

         if (s[i] == ',' && s[i - 1] == ',')
         {
            setbuf(stdin, NULL);
            strcat(nova, "nao informado");
            j = strlen(nova);
         }
         nova[j] = s[i];

         j++;
      }

      if (nova[strlen(nova) - 1] == ',')
         strcat(nova, "nao informado");

      char *saida = nova;
      return saida;
   }

   void imprimir(Jogador x, int i)
   {
      printf("[%d] ## %s ## %d ## %d ## %s ## %s ## %s ## %s ##\n", i, x.nome, x.altura, x.peso,
             x.anoNascimento, x.universidade, x.cidadeNascimento, x.estadoNascimento);

   } //imprimir

   void mostrar()
   {
      int j = 0;
      Celula *i;
      for (i = primeiro; i != NULL; i = i->prox)
      {
         imprimir(i->elemento, j);
         j++;
      } //end if
   }    //end mostrar
   void imprimirR(Jogador x)
   {
      printf("%s%s\n", "(R) ", x.nome);
   } //end imprimirR()
bool isFim(char s[])
{
	bool resp = false;
	if (strlen(s) >= 3 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M')
	{
		resp = true;
	}	//teste de parada
	return resp;
}	//fim do isFim
void mostrarRec(){
      int j=0;
          Celula* i;
      for (i = primeiro; i != NULL; i = i->prox) {
                imprimir(i->elemento,j);
                 j++;
      }
   }