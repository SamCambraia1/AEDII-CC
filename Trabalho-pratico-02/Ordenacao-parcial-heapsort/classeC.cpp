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
void heapify(int n, int i);
void organizHeap();
void sort();
void swap(int i, int j);
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
   int parada = 0;
   char PK[1000];

   scanf("%s", PK);

   while (strcmp(PK, "FIM") != 0)
   {

      le_Jogador(PK);
      countP++;
      scanf("%s", PK);

   } //end while
   sort();
   organizHeap();
   imprimir();

} //end main

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

   for (int i = 0; i < 10; i++)
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
   } //for

} //imprimir

void organizHeap()
{

   Jogador temp[2];
   for (int i = 0; i < countP; i++)
   {
      if (p[i].altura == p[i + 1].altura)
      {

         for (int j = i + 1; j < countP; j++)
         {
            if (p[i].altura == p[j].altura)
            {
               if (strcmp(p[i].nome, p[j].nome) > 0)
               {

                  temp[0] = p[i];
                  p[i] = p[j];
                  p[j] = temp[0];
               }
            }
            else
            {
               j = countP;
            }
         }
      }
   }
}

void swap(int i, int j)
{
   Jogador temp;
   temp = p[i];
   p[i] = p[j];
   p[j] = temp;
}

void heapify(int n, int i)
{
   int largest = i;
   int l = 2 * i + 1;
   int r = 2 * i + 2;

   // if left child is larger than root
   if (l < n)
   {
      if (p[l].altura > p[largest].altura)
      {
         largest = l;
      }
      if (p[r].altura == p[largest].altura && strcmp(p[r].nome, p[largest].nome) > 0)
      {
         largest = l;
      }
   }
   // if right child is larger than largest so far
   if (r < n)
   {
      if (p[r].altura > p[largest].altura)
      {

         largest = r;
      }
      if (p[r].altura == p[largest].altura && strcmp(p[r].nome, p[largest].nome) > 0)
      {
         largest = r;
      }
   }

   // if largest is not root
   if (largest != i)
   {
      swap(i, largest);

      // recursively heapify the affected sub-tree
      heapify(n, largest);
   }
}

void sort()
{
   // build heap (rearrange array)
   for (int i = countP / 2 - 1; i >= 0; i--)
      heapify(i, countP);

   // one by one extract an element from heap
   for (int i = countP - 1; i >= 0; i--)
   {
      // move current root to end
      swap(0, i);

      // call max heapify on the reduced heap
      heapify(i, 0);
   }
}
