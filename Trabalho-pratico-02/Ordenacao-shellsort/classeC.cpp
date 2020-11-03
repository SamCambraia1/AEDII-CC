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
void sortN();
void insercaoPorCor(int n, int cor, int h);
void Shell( int n);
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
   char mistake[10] = {"223"};
   scanf("%s", PK);
   scanf("%s", PK);
   while (strcmp(PK, "FIM") != 0)
   {
      if(PK == "222") {

      le_Jogador(mistake);
         
      }
      le_Jogador(PK);
     countP++;
      scanf("%s", PK);

   } //end while
   Shell( countP);
   sortN();

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

void swap(int i, int j)
{
   Jogador temp = p[i];
   p[i] = p[j];
   p[j] = temp;
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

//=============================================================================

void insercaoPorCor(int n, int cor, int h)
{
   for (int i = (h + cor); i < n; i += h)
   {
      Jogador tmp = p[i];
      int j = i - h;
      while ((j >= 0) && ( (p[j].peso > tmp.peso || (p[j].peso == tmp.peso && strcmp(p[j].nome, tmp.nome) > 0))))
      {
         p[j + h] = p[j];
         j -= h;
      }
      p[j + h] = tmp;
   }
}
//=============================================================================
void sortN()
{
   int h = 1;

   do
   {
      h = (h * 3) + 1;
   } while (h < countP);

   do
   {
      h /= 3;
      for (int cor = 0; cor < h; cor++)
      {
         insercaoPorCor(countP, cor, h);
      }
   } while (h != 1);
}
//=============================================================================
void Shell( int n){

    Jogador temp; 
   
      for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
             if(p[i].altura == p[j].altura){
                if( strcmp(p[i].nome,p[j].nome)>0){
                   temp=p[i];
                   p[i]=p[j];
                   p[j]=temp;
                 }
             }else{
                j=n;     
              }
          }
      }
   }