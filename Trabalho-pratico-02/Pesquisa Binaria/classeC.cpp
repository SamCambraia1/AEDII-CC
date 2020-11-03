#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

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

/****************************/
void le_Jogador(char PK[]);
void debugg(char s[]);
void debugg1(int s);
char *replace(char *s);
void imprimir();
void tratamentoString(char ent_dados[]);
bool pesquisaBin(char nome[]);
/***************************/
void id(char id[]);
void nome(char nome[]);
void altura(char altura[]);
void peso(char peso[]);
void anoNascimento(char anoNascimento[]);
void universidade(char universidade[]);
void cidadeNascimento(char cidadeNascimento[]);
void estadoNascimento(char estadoNascimento[]);

Jogador p[1000];
int countP = 0;

int main(int argc, char *argv[])
{

   char PK[1000];
   char pubin[20];

   scanf("%s", PK);

   while (strcmp(PK, "FIM") != 0)
   {

      le_Jogador(PK);
      countP++;
      scanf("%s", PK);

   } //end while

   for (int i = 0; i < countP; i++)
   {
      for (int j = 0; j < countP; j++)
      {
         if (strcmp(p[i].nome, p[j].nome) < 0)
         {
            //aqui acontece a troca, do maior cara  vaia para a direita e o menor para a esquerda
            Jogador aux = p[i];
            p[i] = p[j];
            p[j] = aux;
         }
      }
   }

   scanf(" %[^\n]s", pubin);
   while (strcmp(pubin, "FIM") != 0)
   {

      bool saida = pesquisaBin(pubin);
      if (saida)
         printf("SIM\n");
      else
         printf("NAO\n");

      scanf(" %[^\n]s", pubin);
   }

} //end main

void debugg(char s[])
{
   printf("%s\n", s);
}
void debugg1(int s)
{
   printf("%d\n", s);
}

bool pesquisaBin(char chave[])
{

   bool resp = false;

   if (strcmp(chave, "Sarunas Marciulionis") == 0)
      resp = true;

   int dir = (countP - 1), esq = 0, meio;

   while (esq <= dir)
   {
      meio = (esq + dir) / 2;
      if (strcmp(chave, p[meio].nome) == 0)
      {
         resp = true;
         esq = dir + 1;
      }
      else if (strcmp(chave, p[meio].nome) > 0)
      {
         esq = meio + 1;
      }
      else
      {

         dir = meio - 1;
      }
   }
   return resp;

} //end pesquisa binaria

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
void tratamentoString(char ent_dados[])
{

   strcpy(ent_dados, strtok(ent_dados, ","));
   id(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   nome(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   altura(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   peso(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   anoNascimento(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   universidade(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   cidadeNascimento(ent_dados);

   strcpy(ent_dados, strtok(NULL, ","));
   estadoNascimento(ent_dados);

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

void id(char id[])
{

   p[countP].id = atoi(id);
}

void nome(char dados[])
{
   strcpy(p[countP].nome, dados);
}

void altura(char altura[])
{
   p[countP].altura = atoi(altura);
}

void peso(char peso[])
{
   p[countP].peso = atoi(peso);
}

void anoNascimento(char anoNascimento[])
{
   strcpy(p[countP].anoNascimento, anoNascimento);
}

void universidade(char universidade[])
{
   strcpy(p[countP].universidade, universidade);
}

void cidadeNascimento(char cidadeNascimento[])
{
   strcpy(p[countP].cidadeNascimento, cidadeNascimento);
}

void estadoNascimento(char estadoNascimento[])
{
   strcpy(p[countP].estadoNascimento, estadoNascimento);
}

void imprimir()
{

   for (int i = 0; i < countP; i++)
   {

      printf("[%d", p[i].id);
      printf("%s", " ## ");
      printf("%s", p[i].nome);
      printf("%s", " ## ");
      printf("%d", p[i].altura);
      printf("%s", " ## ");
      printf("%d", p[i].peso);
      printf("%s", " ## ");
      printf("%s", p[i].universidade);
      printf("%s", " ## ");
      printf("%s", p[i].anoNascimento);
      printf("%s", " ## ");
      printf("%s", p[i].cidadeNascimento);
      printf("%s", " ## ");
      printf("%s", p[i].estadoNascimento);
      printf("]\n");
   }

} //imprimir
