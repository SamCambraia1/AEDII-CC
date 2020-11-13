#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define MAXTAM 5
#define bool short
#define true 1
#define false 0

int primeiro; // Remove do indice "primeiro".
int ultimo;   // Insere no indice "ultimo".
int numeroFila = 0;
int countPly = 0;
double soma = 0;

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
   Jogador players[MAXTAM + 1]; // Elementos da pilha
   /* data */
} Fila;

/****************************/

void le_Jogador(char PK[]);
char *replace(char *s);
void imprimir();
void tratamentoString(char ent_dados[]);

/***************************/
void start();
Fila inserir(Jogador x, Fila fila);
Fila remover(Fila fila);
void imprimir(Jogador x, int i);
void mostrar();
void imprimirR(Jogador x);

/***************************/

// Jogador p[1000];
int countP = 0;
Jogador p;
Fila fila;

int main(int argc, char *argv[])
{
   start();
   int somaT = 0;
   char PK[100];
   scanf("%s", PK);

   while (strcmp(PK, "FIM") != 0)
   {

      le_Jogador(PK);
      fila = inserir(p, fila);

      scanf("%s", PK);
   } //end while

   int count = 0;
   int qtdArquivo = 0;
   char *separado;
   scanf("%d", &qtdArquivo);

   while (count < qtdArquivo)
   {

      scanf(" %[^\n]s", PK);

      if (PK[0] == 'I')
      {
         separado = strtok(PK, " ");
         separado = strtok(NULL, " ");
         //printf("%s%s\n", " INSERIR",separado);
         le_Jogador(separado);
         fila = inserir(p, fila);
      } //end inserir()
      if (PK[0] == 'R')
      {
         fila = remover(fila);
      } //end remover()

      count++;

   } //end while
   mostrar();
} //end main

void start()
{

   ultimo = primeiro = 0;

} //end start

Fila inserir(Jogador x, Fila fila)
{
   Jogador temp[MAXTAM];

   if (numeroFila >= MAXTAM)
   {
      temp[0] = fila.players[0];
      soma = soma - temp[0].altura;
      numeroFila--;
      for (int i = 0; i < numeroFila; i++)
      {
         fila.players[i] = fila.players[i + 1];
      }
   }//end if
   fila.players[numeroFila] = x;
   numeroFila++;
   double media = 0;
   soma = soma + x.altura;
   media = soma / numeroFila;
   round(media);
   printf("%.0f\n", media);
   return fila;
}//end inserir()

Fila remover(Fila fila)
{

   Jogador temp[MAXTAM];
   if (numeroFila == 0)
   {
      printf("Erro ao remover ( Fila vazia )!");
   }//end if
   else
   {

      temp[0] = fila.players[0];
      soma = soma - temp[0].altura;
      imprimirR(temp[0]);
      numeroFila--;
      for (int i = 0; i < numeroFila; i++)
      {
         fila.players[i] = fila.players[i + 1];
      }//end for
   }//end else
   return fila;
} //end remover

void le_Jogador(char PK[])
{

   char ent_dados[1000];
   char *sep;
   char *separar;
   FILE *jogador = fopen("/tmp/players.csv", "r");

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
      }//end if

   } while (!feof(jogador) && strcmp(sep, PK) != 0);

   fclose(jogador);

} //end le_Jogador

void tratamentoString(char ent_dados[])
{

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
   printf("[%d] ## %s ## %d ## %d ## %s ## %s ## %s ## %s ##", i, x.nome, x.altura, x.peso,
          x.anoNascimento, x.universidade, x.cidadeNascimento, x.estadoNascimento);

} //imprimir

void mostrar()
{
   for (int i = 0; i < numeroFila; i++)
   {
      imprimir(fila.players[i], i);
   }//end if
}//end mostrar
void imprimirR(Jogador x)
{
   printf("%s%s\n", "(R) ", x.nome);
}//end imprimirR()