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
void bolha(int n);
void swap(int a, int b);
void ordena(int n);
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

   scanf("%s", PK);

   while (strcmp(PK, "FIM") != 0)
   {

      le_Jogador(PK);
      countP++;
      scanf("%s", PK);

   } //end while
   bolha(countP);
   //ordena(countP);
   imprimir();

} //end
void swap(int a, int b)
{
   Jogador temp = p[a];
   p[a] = p[b];
   p[b] = temp;
}
void bolha(int n)
{

   int i, j;
   for (i = (n - 1); i > 0; i--)
   {
      for (j = 0; j < i; j++)
      {
         if (strcmp(p[j].anoNascimento, p[j + 1].anoNascimento) > 0 || strcmp(p[j].anoNascimento, p[j + 1].anoNascimento) == 0 && strcmp(p[j].nome, p[j + 1].nome) > 0)
         {
            swap(j, j + 1);
         }
      }
   }
}

void ordena(int n)
{

   Jogador temp;

   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         if (strcmp(p[i].anoNascimento, p[j].anoNascimento) == 0)
         {
            if (strcmp(p[i].nome, p[j].nome) < 0)
            {
               temp = p[i];
               p[i] = p[j];
               p[j] = temp;
            }
         }
         else
         {
            j = n;
         }
      }
   }
}

void debugg(char s[])
{
   printf("%s\n", s);
}
void debugg1(int s)
{
   printf("%d\n", s);
}
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

   p[countP].id = atoi(strtok(ent_dados, ","));
   strcpy(p[countP].nome, strtok(NULL, ","));
   p[countP].altura = atoi(strtok(NULL, ","));
   p[countP].peso = atoi(strtok(NULL, ","));
   strcpy(p[countP].universidade, strtok(NULL, ","));
   strcpy(p[countP].anoNascimento, strtok(NULL, ","));
   strcpy(p[countP].cidadeNascimento, strtok(NULL, ","));
   strcpy(p[countP].estadoNascimento, strtok(NULL, ","));

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
      printf("%s", p[i].anoNascimento);
      printf("%s", " ## ");
      printf("%s", p[i].universidade);
      printf("%s", " ## ");
      printf("%s", p[i].cidadeNascimento);
      printf("%s", " ## ");
      printf("%s", p[i].estadoNascimento);
      printf("]\n");
   }

} //imprimir
