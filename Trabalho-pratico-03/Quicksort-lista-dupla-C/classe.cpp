#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <err.h>

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

//TIPO CELULA ===================================================================
typedef struct CelulaDupla
{
    Jogador elemento;         // Elemento inserido na celula.
    struct CelulaDupla *prox; // Aponta a celula prox.
    struct CelulaDupla *ant;  // Aponta a celula anterior.
} CelulaDupla;

CelulaDupla *novaCelulaDupla(Jogador elemento)
{
    CelulaDupla *nova = (CelulaDupla *)malloc(sizeof(CelulaDupla));
    nova->elemento = elemento;
    nova->ant = nova->prox = NULL;
    return nova;
}

//LISTA PROPRIAMENTE DITA =======================================================

static Jogador array[1000];
static int countGlobal = 0;

CelulaDupla *primeiro;
CelulaDupla *ultimo;

void le_Jogador(char PK[]);
char *replace(char *s);
void imprimir(Jogador x, int pos);
void tratamentoString(char ent_dados[]);

/***************************/

void inserirFim(Jogador x);
void mostrar();
void inserirInicio(Jogador x);
void inserirFim(Jogador x);
void inserir(Jogador x, int pos);
Jogador removerInicio();
Jogador removerFim();
Jogador remover(int pos);
int tamanho();
void le_List(char PK[]);
void tratamento_String_list(char ent_dados[]);
void swap(int i, int j);
void sort();
void quicksortRec(int esq, int dir);
void start();

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
       
        countGlobal++;
        scanf("%s", PK);

    } //end while
    sort();
    start();

   for (int i = 0; i < countGlobal; i++)
    {
        inserirFim(array[i]);
    }


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
                  inserirInicio(array[countGlobal]);

             } //end inserir INICIO

              else if (PK[1] == 'F')
              {

                  operacao = strtok(PK, " ");
                  objeto = strtok(NULL, " ");
                  le_List(objeto);
                  inserirFim(array[countGlobal]);

             } //end inserir FIM
             else
          {                 operacao = strtok(PK, " ");
                 int pos = atoi(posicao = strtok(NULL, " "));
                 objeto = strtok(NULL, " ");

             le_List(objeto);
             inserir(p, pos);

             } //end inserir em qualquer lugar

         } //end inserir()

         if (PK[0] == 'R')
         {
             if (PK[1] == 'I')
             {

                 printf("%s%s\n", "(R) ", removerInicio().nome);

             } //end removerInicio
             else if (PK[1] == 'F')
             {

                 printf("%s%s\n", "(R) ", removerInicio().nome);

             } //end removerFim

             else
             {

                 operacao = strtok(PK, " ");
                 int pos = atoi(posicao = strtok(NULL, " "));
                 printf("%s%s\n", "(R) ", remover(pos).nome);

             } //end remover em qualquer lugar

         } //end remover()

         count++;

    } //end while

    mostrar();
} //end main

void start()
{
    primeiro = novaCelulaDupla(array[0]);
    ultimo = primeiro;
} //end start()

void inserirInicio(Jogador x)
{
    CelulaDupla *tmp = novaCelulaDupla(x);

    tmp->ant = primeiro;
    tmp->prox = primeiro->prox;
    primeiro->prox = tmp;
    if (primeiro == ultimo)
    {
        ultimo = tmp;
    }
    else
    {
        tmp->prox->ant = tmp;
    }
    tmp = NULL;
} //end inserirInicio()

void inserirFim(Jogador x)
{
    ultimo->prox = novaCelulaDupla(x);
    ultimo->prox->ant = ultimo;
    ultimo = ultimo->prox;

} //end inserirFim
void inserir(Jogador x, int pos)
{

    int tam = tamanho();

    if (pos < 0 || pos > tam)
    {
        errx(1, "Erro ao remover (posicao %d/%d invalida!", pos, tam);
    } //end if
    else if (pos == 0)
    {
        inserirInicio(x);
    } //end else if
    else if (pos == tam)
    {
        inserirFim(x);
    } //end else if
    else
    {
        // Caminhar ate a posicao anterior a insercao
        CelulaDupla *i = primeiro;
        int j;
        for (j = 0; j < pos; j++, i = i->prox)
            ;

        CelulaDupla *tmp = novaCelulaDupla(x);
        tmp->ant = i;
        tmp->prox = i->prox;
        tmp->ant->prox = tmp->prox->ant = tmp;
        tmp = i = NULL;
    } //end else
} //end inserir()

Jogador removerInicio()
{
    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover (vazia)!");
    } //end if

    CelulaDupla *tmp = primeiro;
    primeiro = primeiro->prox;
    Jogador resp = primeiro->elemento;
    tmp->prox = primeiro->ant = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
} //end removerInicio

Jogador removerFim()
{
    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover (vazia)!");
    }
    Jogador resp = ultimo->elemento;
    ultimo = ultimo->ant;
    ultimo->prox->ant = NULL;
    free(ultimo->prox);
    ultimo->prox = NULL;
    return resp;
} //end removerFim

Jogador remover(int pos)
{
    Jogador resp;
    int tam = tamanho();

    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover (vazia)!");
    } //end if
    else if (pos < 0 || pos >= tam)
    {
        errx(1, "Erro ao remover (posicao %d/%d invalida!", pos, tam);
    } //end else if
    else if (pos == 0)
    {
        resp = removerInicio();
    } //end else if
    else if (pos == tam - 1)
    {
        resp = removerFim();
    } //end else if
    else
    {
        // Caminhar ate a posicao anterior a insercao
        CelulaDupla *i = primeiro->prox;
        int j;
        for (j = 0; j < pos; j++, i = i->prox)
            ;

        i->ant->prox = i->prox;
        i->prox->ant = i->ant;
        resp = i->elemento;
        i->prox = i->ant = NULL;
        free(i);
        i = NULL;
    } //end else

    return resp;
} //end remover()

int tamanho()
{
    int tamanho = 0;
    CelulaDupla *i;
    for (i = primeiro; i != ultimo; i = i->prox, tamanho++)
        ;
    return tamanho;
} //end tamanho()

void le_Jogador(char PK[])
{

   char ent_dados[1000];
   char *sep;
   char *separar;
   FILE *jogador = fopen("/tmp/players.csv", "r");
   //fgets(ent_dados,1000,jogador);

   do
   {

      fgets(ent_dados,1000,jogador);
   

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
    array[countGlobal].id = atoi(ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].nome, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    array[countGlobal].altura = atoi(ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    array[countGlobal].peso = atoi(ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].anoNascimento, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].universidade, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].cidadeNascimento, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].estadoNascimento, ent_dados);

} //end tratamentoString

void le_List(char PK[])
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
            tratamento_String_list(ent_dados);
        }

    } while (!feof(jogador) && strcmp(sep, PK) != 0);

    fclose(jogador);

} //end le_Jogador

void tratamento_String_list(char ent_dados[])
{

    strcpy(ent_dados, strtok(ent_dados, ","));
    array[countGlobal].id = atoi(ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].nome, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    array[countGlobal].altura = atoi(ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    array[countGlobal].peso = atoi(ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].anoNascimento, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].universidade, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].cidadeNascimento, ent_dados);

    strcpy(ent_dados, strtok(NULL, ","));
    strcpy(array[countGlobal].estadoNascimento, ent_dados);

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

void imprimir(Jogador x, int pos)
{
    // int tam;
    printf("[");
    printf("%d", x.id);
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
    printf("]\n");

} //imprimir

void mostrar()
{
    CelulaDupla *i;
    int j = 0;
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
        imprimir(i->elemento, j);
        j++;
    } //end for
} //end mostrar
void quicksortRec(int esq, int dir)
{
    int i = esq, j = dir;
    Jogador pivo = array[(dir + esq) / 2];
    Jogador temp;
    while (i <= j)
    {
        while (strcmp(array[i].estadoNascimento, pivo.estadoNascimento) < 0 || strcmp(array[i].estadoNascimento, pivo.estadoNascimento) == 0 && strcmp(array[i].nome, pivo.nome) < 0)
            i++;
        while (strcmp(array[j].estadoNascimento, pivo.estadoNascimento) > 0 || strcmp(array[j].estadoNascimento, pivo.estadoNascimento) == 0 && strcmp(array[j].nome, pivo.nome) > 0)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        } //end if
    }     //end while
    if (esq < j)
        quicksortRec(esq, j);
    if (i < dir)
        quicksortRec(i, dir);
} //end quicksortRec()

void sort()
{
    quicksortRec(0, countGlobal - 1);
} //end sort();
void swap(int i, int j)
{
    Jogador temp = array[i];
    array[i] = array[j];
    array[j] = temp;
} //end swap
