#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAXTAM 1000
#define bool short
#define true 1
#define false 0
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

typedef struct
{
   Jogador players[MAXTAM]; // Elementos da pilha

} Lista;

/****************************/

void le_Jogador(char PK[]);
char *replace(char *s);
void imprimir();
void tratamentoString(char ent_dados[]);

/***************************/

void inserirInicio(Jogador x);
void inserirFim(Jogador x);
void inserir(Jogador x, char pos[]);
Jogador removerInicio();
Jogador removerFim();
Jogador remover(char pos[]);
void le_List(char PK[]);
void tratamento_String_list(char ent_dados[]);

/***************************/

// Jogador p[1000];
int countP = 0;
Jogador p;
Lista list;

int main(int argc, char *argv[])
{

   char PK[1000];

   scanf("%s", PK);

   while (strcmp(PK, "FIM") != 0)
   {

      le_Jogador(PK);
      countP++;
      scanf("%s", PK);

   } //end while
   int count = 0;
   int qtdArquivo = 0;
   char *operacao;
   char *objeto;
   char *posicao;

   scanf("%d", &qtdArquivo);

   while (count < qtdArquivo)
   {

      scanf(" %[^\n]s", PK);

      if (PK[0] == 'I')
      {
         if (PK[1] == 'I')
         {
            operacao = strtok(PK, " ");
            objeto = strtok(NULL, " ");
            le_List(objeto);
            inserirInicio(p);

         } //end inserirInicio
         else if (PK[1] == 'F')
         {
            operacao = strtok(PK, " ");
            objeto = strtok(NULL, " ");
            le_List(objeto);
            inserirFim(p);

         } //end inserirFim
         else
         {
            operacao = strtok(PK, " ");
            posicao = strtok(NULL, " ");
            objeto = strtok(NULL, " ");

            le_List(objeto);
            inserir(p, posicao);

         } //end inserir em qualquer posicao
      }    //end inserir()
      if (PK[0] == 'R')
      {
         if (PK[1] == 'I')
         {

            p = removerInicio();
            printf("%s %s\n", "(R)", p.nome);

         } //end removerInicio
         else if (PK[1] == 'F')
         {
            p = removerFim();
            printf("%s %s\n", "(R)", p.nome);
         } //end removerFim
         else
         {
            operacao = strtok(PK, " ");
            posicao = strtok(NULL, " ");

            p = remover(posicao);
            printf("%s %s\n", "(R)", p.nome);
         } //end remover em qualquer posicao
      }    //end remover()

      count++;

   } //end while

   imprimir();

} //end main

void inserirInicio(Jogador x)
{
   int i;

   //validar insercao
   if (countP >= MAXTAM)
   {
      printf("Erro ao inserir!");
      exit(1);
   }

   //levar elementos para o fim do array
   for (i = countP; i > 0; i--)
   {
      list.players[i] = list.players[i - 1];
   }

   list.players[0] = x;
   countP++;
} //end inserirInicio()

void inserirFim(Jogador x)
{

   //validar insercao
   if (countP >= MAXTAM)
   {
      printf("Erro ao inserir!");
      exit(1);
   }

   list.players[countP] = x;
   countP++;
} //end inserirFim

void inserir(Jogador x, char pos[])
{
   int i;
   int posN = atoi(pos);

   //validar insercao
   if (countP >= MAXTAM || posN < 0 || posN > countP)
   {
      printf("Erro ao inserir!");
      exit(1);
   }

   //levar elementos para o fim do array
   for (i = countP; i > posN; i--)
   {
      list.players[i] = list.players[i - 1];
   }

   list.players[posN] = x;
   countP++;
} //end inserir()

Jogador removerInicio()
{
   int i;
   Jogador resp;

   //validar remocao
   if (countP == 0)
   {
      printf("Erro ao remover!");
      exit(1);
   }

   resp = list.players[0];
   countP--;

   for (i = 0; i < countP; i++)
   {
      list.players[i] = list.players[i + 1];
   }

   return resp;
} // end removerInicio

Jogador removerFim()
{

   //validar remocao
   if (countP == 0)
   {
      printf("Erro ao remover!");
      exit(1);
   }
   countP--;
   return list.players[countP];

} //end removerFim

Jogador remover(char pos[])
{
   int i;
   Jogador resp;
   int posN = atoi(pos);

   //validar remocao
   if (countP == 0 || posN < 0 || posN >= countP)
   {
      printf("Erro ao remover!");
      exit(1);
   }

   resp = list.players[posN];
   countP--;

   for (i = posN; i < countP; i++)
   {
      list.players[i] = list.players[i + 1];
   }

   return resp;
} //end remover()

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
      }

   } while (!feof(jogador) && strcmp(sep, PK) != 0);

   fclose(jogador);

} //end le_Jogador
void le_List(char PK[])
{

   char ent_dados[1000];
   char *sep;
   char *separar;
   FILE *jogador = fopen("/tmp/players.csv", "r");

   do
   {

      fgets(ent_dados, 1000, jogador);

      strcpy(ent_dados, replace(ent_dados));
      separar = strdup(ent_dados);
      sep = strsep(&separar, ",");

      //printf(sep,"sep\n");
      if (strcmp(sep, PK) == 0)
      {
         tratamento_String_list(ent_dados);
      }

   } while (!feof(jogador) && strcmp(sep, PK) != 0);

   fclose(jogador);

} //end le_List
void tratamentoString(char ent_dados[])
{

   strcpy(ent_dados, strtok(ent_dados, ","));
   list.players[countP].id = atoi(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   strcpy(list.players[countP].nome, ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   list.players[countP].altura = atoi(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   list.players[countP].peso = atoi(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   strcpy(list.players[countP].anoNascimento, ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   strcpy(list.players[countP].universidade, ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   strcpy(list.players[countP].cidadeNascimento, ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   strcpy(list.players[countP].estadoNascimento, ent_dados);

} //end tratamentoString

void tratamento_String_list(char ent_dados[])
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

void imprimir()
{
   // int tam;
   for (int i = 0; i < countP; i++)
   {
      printf("%s%d%s", "[", i, "]");
      printf("%s", " ## ");
      printf("%s", list.players[i].nome);
      printf("%s", " ## ");
      printf("%d", list.players[i].altura);
      printf("%s", " ## ");
      printf("%d", list.players[i].peso);
      printf("%s", " ## ");
      printf("%s", list.players[i].universidade);
      printf("%s", " ## ");
      printf("%s", list.players[i].anoNascimento);
      printf("%s", " ## ");
      printf("%s", list.players[i].cidadeNascimento);
      printf("%s", " ## ");
      printf("%s", list.players[i].estadoNascimento);
      printf(" ##\n");
   }

} //imprimir
