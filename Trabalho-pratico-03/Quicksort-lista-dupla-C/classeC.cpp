// -----------define-----------
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <err.h>

#define MAXTAM 150
#define bool short
#define true 1
#define false 0

using namespace std;

// -----------classe-----------
class Jogador
{
private:
    int id = 0;
    string nome = "";
    int altura = 0;
    int peso = 0;
    string universidade = "";
    string anoNascimento = "";
    string cidadeNascimento = "";
    string estadoNascimento = "";

public:
    Jogador()
    {
        id = 0;
        nome = "";
        altura = 0;
        peso = 0;
        universidade = "";
        anoNascimento = "";
        cidadeNascimento = "";
        estadoNascimento = "";
    }

    ~Jogador()
    {
    }

    // set
    void setId(int Id)
    {
        id = Id;
    }

    void setNome(string Nome)
    {
        nome = Nome;
    }

    void setAltura(int Altura)
    {
        altura = Altura;
    }

    void setPeso(int Peso)
    {
        peso = Peso;
    }

    void setUniversidade(string Universidade)
    {
        universidade = Universidade;
    }

    void setAnoNascimento(string AnoNascimento)
    {
        anoNascimento = AnoNascimento;
    }

    void setCidadeNascimento(string CidadeNascimento)
    {
        cidadeNascimento = CidadeNascimento;
    }

    void setEstadoNascimento(string EstadoNascimento)
    {
        estadoNascimento = EstadoNascimento;
    }

    // get
    int getId()
    {
        return id;
    }

    string getNome()
    {
        return nome;
    }

    int getAltura()
    {
        return altura;
    }

    int getPeso()
    {
        return peso;
    }

    string getUniversidade()
    {
        return universidade;
    }

    string getAnoNascimento()
    {
        return anoNascimento;
    }

    string getCidadeNascimento()
    {
        return cidadeNascimento;
    }

    string getEstadoNascimento()
    {
        return estadoNascimento;
    }
    void imprimir()
    {
        cout << "[";
        cout << getId();
        cout << " ## ";
        cout << getNome();
        cout << " ## ";
        cout << getAltura();
        cout << " ## ";
        cout << getPeso();
        cout << " ## ";
        cout << getAnoNascimento();
        cout << " ## ";
        cout << getUniversidade();
        cout << " ## ";
        cout << getCidadeNascimento();
        cout << " ## ";
        cout << getEstadoNascimento();
        cout << "]\n";
    }

    string ReplaceAll(std::string str, const std::string &from, const std::string &to)
    {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos)
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
        }
        return str;
    }

    void tratamento(string s)
    {
        string nova = ReplaceAll(s, ",,", ",nao informado,");
        int aux = nova.length();
        if (nova.at(aux - 1) == ',')
        {
            nova += "nao informado";
        }
        // --------------------
        string delimiter = ",";
        string Id = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string Nome = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string Altura = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string Peso = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string Universidade = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string anoDeNascimento = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string cidadeDeNascimento = nova.substr(0, nova.find(delimiter));
        nova.erase(0, nova.find(delimiter) + delimiter.length());
        string estadoDeNascimento = nova.substr(0, nova.find("\n"));
        if (estadoDeNascimento == "")
        {
            estadoDeNascimento += "nao informado";
        }
        setId(stoi(Id));
        setNome(Nome);
        setAltura(stoi(Altura));
        setPeso(stoi(Peso));
        setUniversidade(Universidade);
        setAnoNascimento(anoDeNascimento);
        setCidadeNascimento(cidadeDeNascimento);
        setEstadoNascimento(estadoDeNascimento);
    }
    void ler(string id)
    {
        string s = "";
        char sc[300];
        string delimiter = ",";
        string saux = "";
        FILE *arq;
        if ((arq = fopen("/tmp/players.csv", "r")) == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            abort();
        }
        bool flag = false;
        fgets(sc, 300, arq);
        s = sc;
        while (!feof(arq) && flag == false)
        {
            saux = s.substr(0, s.find(delimiter));
            if (saux == id)
            {
                flag = true;
                tratamento(s);
            }
            fgets(sc, 300, arq);
            s = sc;
        }
    }
};

// -----------lista-----------
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

static Jogador array[1024];
static int countGlobal = 0;

CelulaDupla *primeiro;
CelulaDupla *ultimo;

/**
 * Cria uma lista dupla sem elementos (somente no cabeca).
 */
    void start()
    {
        primeiro = novaCelulaDupla(array[0]);
        ultimo = primeiro;
    }

/**
 * Insere um elemento na primeira posicao da lista.
 * @param x int elemento a ser inserido.
 */
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
}

/**
 * Insere um elemento na ultima posicao da lista.
 * @param x int elemento a ser inserido.
 */
void inserirFim(Jogador x)
{
    ultimo->prox = novaCelulaDupla(x);
    ultimo->prox->ant = ultimo;
    ultimo = ultimo->prox;
}

/**
 * Remove um elemento da primeira posicao da lista.
 * @return resp int elemento a ser removido.
 */
Jogador removerInicio()
{
    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover (vazia)!");
    }

    CelulaDupla *tmp = primeiro;
    primeiro = primeiro->prox;
    Jogador resp = primeiro->elemento;
    tmp->prox = primeiro->ant = NULL;
    free(tmp);
    tmp = NULL;
    return resp;
}

/**
 * Remove um elemento da ultima posicao da lista.
 * @return resp int elemento a ser removido.
 */
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
}

/**
 *  Calcula e retorna o tamanho, em numero de elementos, da lista.
 *  @return resp int tamanho
 */
int tamanho()
{
    int tamanho = 0;
    CelulaDupla *i;
    for (i = primeiro; i != ultimo; i = i->prox, tamanho++)
        ;
    return tamanho;
}

/**
 * Insere um elemento em uma posicao especifica considerando que o 
 * primeiro elemento valido esta na posicao 0.
 * @param x int elemento a ser inserido.
 * @param pos int posicao da insercao.
 * @throws Exception Se <code>posicao</code> invalida.
 */
void inserir(Jogador x, int pos)
{

    int tam = tamanho();

    if (pos < 0 || pos > tam)
    {
        errx(1, "Erro ao remover (posicao %d/%d invalida!", pos, tam);
    }
    else if (pos == 0)
    {
        inserirInicio(x);
    }
    else if (pos == tam)
    {
        inserirFim(x);
    }
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
    }
}

/**
 * Remove um elemento de uma posicao especifica da lista
 * considerando que o primeiro elemento valido esta na posicao 0.
 * @param posicao Meio da remocao.
 * @return resp int elemento a ser removido.
 * @throws Exception Se <code>posicao</code> invalida.
 */
Jogador remover(int pos)
{
    Jogador resp;
    int tam = tamanho();

    if (primeiro == ultimo)
    {
        errx(1, "Erro ao remover (vazia)!");
    }
    else if (pos < 0 || pos >= tam)
    {
        errx(1, "Erro ao remover (posicao %d/%d invalida!", pos, tam);
    }
    else if (pos == 0)
    {
        resp = removerInicio();
    }
    else if (pos == tam - 1)
    {
        resp = removerFim();
    }
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
    }

    return resp;
}

/**
 * Mostra os elementos da lista separados por espacos.
 */
void mostrar()
{
    CelulaDupla *i;
    for (i = primeiro->prox; i != NULL; i = i->prox)
    {
        i->elemento.imprimir();
    }
}

/**
 * Mostra os elementos da lista de forma invertida 
 * e separados por espacos.
 */

// -----------tratamento-----------

Jogador pesquisar(string key)
{
    array[countGlobal].ler(key);
    countGlobal++;
    return array[countGlobal - 1];
}

void tratamentoOps(string arrayOps)
{
    string delimiter = " ";
    string op = arrayOps.substr(0, arrayOps.find(delimiter));
    arrayOps.erase(0, arrayOps.find(delimiter) + delimiter.length());
    if (op.at(1) == '*')
    {
        if (op.at(0) == 'I')
        {
            string tmp = arrayOps.substr(0, arrayOps.find(delimiter));
            arrayOps.erase(0, arrayOps.find(delimiter) + delimiter.length());
            string key = arrayOps.substr(0, arrayOps.find(delimiter));
            int pos = stoi(tmp);
            inserir(pesquisar(key), pos);
        }
        else
        {
            // cout << arrayOps << "\n";
            string tmp = arrayOps.substr(0, arrayOps.find(delimiter));
            arrayOps.erase(0, arrayOps.find(delimiter) + delimiter.length());
            // cout << "chegou " << tmp << "\n";
            int pos = stoi(tmp);
            cout << "(R) " << remover(pos).getNome() << "\n";
        }
    }
    else
    {
        if (op.at(0) == 'I')
        {
            if (op == "II")
            {
                string tmp = arrayOps.substr(0, arrayOps.find(delimiter));
                arrayOps.erase(0, arrayOps.find(delimiter) + delimiter.length());
                inserirInicio(pesquisar(tmp));
            }
            else
            {
                string tmp = arrayOps.substr(0, arrayOps.find(delimiter));
                arrayOps.erase(0, arrayOps.find(delimiter) + delimiter.length());
                inserirFim(pesquisar(tmp));
            }
        }
        else
        {
            if (op == "RI")
            {
                cout << "(R) " << removerInicio().getNome() << "\n";
            }
            else
            {
                cout << "(R) " << removerFim().getNome() << "\n";
            }
        }
    }
}
// -----------quick----------

void swap(int i, int j)
{
    Jogador temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quicksortRec(int esq, int dir)
{
    int i = esq, j = dir;
    Jogador pivo = array[(dir + esq) / 2];
    Jogador temp;
    while (i <= j)
    {
        while (array[i].getEstadoNascimento().compare(pivo.getEstadoNascimento()) < 0 || array[i].getEstadoNascimento().compare(pivo.getEstadoNascimento()) == 0 && array[i].getNome().compare(pivo.getNome()) < 0)
            i++;
        while (array[j].getEstadoNascimento().compare(pivo.getEstadoNascimento()) > 0 || array[j].getEstadoNascimento().compare(pivo.getEstadoNascimento()) == 0 && array[j].getNome().compare(pivo.getNome()) > 0)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (esq < j)
        quicksortRec(esq, j);
    if (i < dir)
        quicksortRec(i, dir);
}

void sort()
{
    quicksortRec(0, countGlobal - 1);
}

// -----------main-----------

int main(void)
{
    string arrayID = "";
    cin >> arrayID;
    while (arrayID != "FIM")
    {
        array[countGlobal].ler(arrayID);
        countGlobal++;
        cin >> arrayID;
    }
    for (int i = 0; i < countGlobal; i++)
    {
        // array[i].imprimir();
    }
    sort();

    start();

    for (int i = 1; i < countGlobal; i++)
    {
        inserirFim(array[i]);
    }

    mostrar();
}
