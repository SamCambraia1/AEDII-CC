import java.io.*;
import java.util.*;

class Celula {
    public Player elemento;
    public Celula ant;
    public Celula prox;


     public Celula(){
         this(new Player());
     }
    /**
     * Construtor da classe.
     * 
     *
     */
    public Celula(Player elemento) {
        this.elemento = elemento;
        this.ant = this.prox = null;
    }// end construtor
}// end Celula

class Player {

    private int id;
    private String universidade;
    private int altura;
    private String nome;
    private int peso;
    private String cidadeNascimento;
    private int anoNascimento;
    private String estadoNascimento;

    public Player() {
        id = 0;
        altura = 0;
        peso = 0;
        anoNascimento = 0;
        nome = "";
        universidade = "";
        cidadeNascimento = "";
        estadoNascimento = "";

    }// end construtor padrao

    public Player(String nome, String universidade, String cidadeNascimento, String estadoNascimento, int id,
            int altura, int peso, int anoNascimento) {
        this.nome = nome;
        this.universidade = universidade;
        this.cidadeNascimento = cidadeNascimento;
        this.estadoNascimento = estadoNascimento;
        this.id = id;
        this.altura = altura;
        this.peso = peso;
        this.anoNascimento = anoNascimento;

    }

    public void setId(int id) {
        this.id = id;
    }// end setId

    public int getId() {
        return id;
    }// end getId

    public void setAltura(int altura) {
        this.altura = altura;
    }// end setAltura

    public int getAltura() {
        return altura;
    }// end getAltura

    public void setPeso(int peso) {
        this.peso = peso;
    }// end setPesoo

    public int getPeso() {
        return peso;
    }// end getPeso

    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }// end setAnoNascimento

    public int getAnoNascimento() {
        return anoNascimento;
    }// end getAnoNascimento

    public void setNome(String nome) {
        this.nome = nome;
    }// end setNome

    public String getNome() {
        return nome;
    }// end getNome

    public void setUniversidade(String universidade) {
        this.universidade = universidade;
    }// end setUniversidade

    public String getUniversidade() {
        return universidade;
    }// end getUniversidade

    public void setCidadeNascimento(String cidadeNascimento) {
        this.cidadeNascimento = cidadeNascimento;
    }// end setCidadeNascimento

    public String getCidadeNascimento() {
        return cidadeNascimento;
    }// end GetCidadeNascimento

    public void setEstadoDeNascimento(String estadoNascimento) {
        this.estadoNascimento = estadoNascimento;
    }// end setEstadoDeNascimento

    public String getEstadoDeNascimento() {
        return estadoNascimento;
    }// end setEstadoDeNascimento

    public Player clone(Player x) {

        x.id = id;
        x.nome = nome;
        x.altura = altura;
        x.peso = peso;
        x.universidade = universidade;
        x.cidadeNascimento = cidadeNascimento;
        x.estadoNascimento = estadoNascimento;
        x.anoNascimento = anoNascimento;

        return x;
    }// end func clone

    public void Imprimir() {

        System.out.println("["+getId()+" ## " + getNome() + " ## " + getAltura() + " ## " + getPeso() + " ## " + getAnoNascimento()
                + " ## " + getUniversidade() + " ## " + getCidadeNascimento() + " ## " + getEstadoDeNascimento()
                + "]");
    } // end imprimir

}// class objeto

class Lista {

    private Celula primeiro;
    private Celula ultimo;

    /**
     * Construtor da classe que cria uma lista dupla sem elementos (somente no
     * cabeca).
     */
    public Lista() {
       this(new Player());
    }// end construtor

    public Lista(Player elemento) {
        primeiro = new Celula(elemento);
        ultimo = primeiro;
    }

    public void inserirInicio(Player x) {
        Celula tmp = new Celula(x);

        tmp.ant = primeiro;
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if (primeiro == ultimo) {
            ultimo = tmp;
        } else {
            tmp.prox.ant = tmp;
        }
        tmp = null;
    }// end inserirInicio

    public void inserirFim(Player x) {
        ultimo.prox = new Celula(x);
        ultimo.prox.ant = ultimo;
        ultimo = ultimo.prox;
    }// end inserirFim

    public void inserir(Player x, int pos) throws Exception {

        int tamanho = tamanho();

        if (pos < 0 || pos > tamanho) {
            throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
        } else if (pos == 0) {
            inserirInicio(x);
        } else if (pos == tamanho) {
            inserirFim(x);
        } else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox)
                ;

            Celula tmp = new Celula(x);
            tmp.ant = i;
            tmp.prox = i.prox;
            tmp.ant.prox = tmp.prox.ant = tmp;
            tmp = i = null;
        }
    }// end inserir

    public Player removerInicio() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");
        }

        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        Player resp = primeiro.elemento;
        tmp.prox = primeiro.ant = null;
        tmp = null;
        return resp;
    }
    // end removerInicio

    public Player removerFim() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");
        }
        Player resp = ultimo.elemento;
        ultimo = ultimo.ant;
        ultimo.prox.ant = null;
        ultimo.prox = null;
        return resp;
    }// end removerFim

    public Player remover(int pos) throws Exception {
        Player resp;
        int tamanho = tamanho();

        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");

        } else if (pos < 0 || pos >= tamanho) {
            throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
        } else if (pos == 0) {
            resp = removerInicio();
        } else if (pos == tamanho - 1) {
            resp = removerFim();
        } else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro.prox;
            for (int j = 0; j < pos; j++, i = i.prox)
                ;

            i.ant.prox = i.prox;
            i.prox.ant = i.ant;
            resp = i.elemento;
            i.prox = i.ant = null;
            i = null;
        }

        return resp;
    }// end remover

    public void mostrar() {
        // Comeca a mostrar.
        int temp = 0;
        
        for (Celula i = primeiro; i != null; i = i.prox,temp++) {
           if( temp > 0)
            i.elemento.Imprimir();
        }
        
    }// end mostrar

    public int tamanho() {
        int tamanho = 0;
        for (Celula i = primeiro; i != ultimo; i = i.prox, tamanho++)
            ;
        return tamanho;
    }// end tamanho

}// end class Lista

public class classe {

    public static Lista list = new Lista();
    public static Player[] array = new Player[1000];
    public static Player ply;
    
    public static int countPlayers = 0;

    public static void swap(int i, int j) {
        Player temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }// end swap

    public static void sort(int esq, int dir, int k) {
        int i = esq, j = dir;
        Player pivo = array[(dir + esq) / 2];
        while (i <= j) {
            while (array[i].getEstadoDeNascimento().compareTo(pivo.getEstadoDeNascimento()) < 0 ||
                   array[i].getEstadoDeNascimento().compareTo(pivo.getEstadoDeNascimento()) == 0 && 
                   array[i].getNome().compareTo(pivo.getNome()) < 0)
                i++;
                while (array[j].getEstadoDeNascimento().compareTo(pivo.getEstadoDeNascimento()) > 0 ||
                array[j].getEstadoDeNascimento().compareTo(pivo.getEstadoDeNascimento()) == 0 && 
                array[j].getNome().compareTo(pivo.getNome()) > 0)

                j--;
            if (i <= j) {
                swap( i, j);
                i++;
                j--;
            }
        }
        if (esq < j)
            sort( esq, j, k);
        if (i < k && i < dir) {
            sort( i, dir, k);
        }
    }
    public static void desempate(int n) {

        Player temp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (array[i].getEstadoDeNascimento().compareTo(array[j].getEstadoDeNascimento()) == 0) {
                    if (array[i].getNome().compareTo(array[j].getNome()) > 0) {
                        temp = array[i];
                        array[i] = array[j];
                        array[j] = temp;
                    }//end if
                }//end if
                 else {
                    j = n;
                }//end else
            }//end for
        }//end for
    }//end desempate


    public static void tratamentoString(String s) throws Exception {
        int tam = s.length();
        if (s.charAt(tam - 1) == ',')
            s = s + "nao informado";
        s = s.replaceAll(",,", ",nao informado,");
        String vetor[] = s.split(",");

        int id = Integer.parseInt(vetor[0]);

        array[countPlayers].setId(id);

        array[countPlayers].setNome(vetor[1]);

        int altura = Integer.parseInt(vetor[2]);

        array[countPlayers].setAltura(altura);

        int peso = Integer.parseInt(vetor[3]);

        array[countPlayers].setPeso(peso);

        array[countPlayers].setUniversidade(vetor[4]);

        int anoNascimento = Integer.parseInt(vetor[5]);

        array[countPlayers].setAnoNascimento(anoNascimento);

        array[countPlayers].setCidadeNascimento(vetor[6]);

        array[countPlayers].setEstadoDeNascimento(vetor[7]);

    }// end tratamentoString

    public static String leituraArquivo(String nomeArq) throws Exception {
        String linha = "";
        BufferedReader file = new BufferedReader(new InputStreamReader(new FileInputStream("/tmp/players.csv")));

        linha = file.readLine();
        while (linha != null) {
            String[] id = linha.split(",");
            if (id[0].equals(nomeArq) == true)
                return linha;
            linha = file.readLine();
        } // end while
        String s = "";
        System.out.println(s);
        return s;
    } // end leituraArquivo



    public static void main(String[] args) throws Exception {

        String nomeArq = "";
        String casos = "";
        BufferedReader leitor = new BufferedReader(new InputStreamReader(System.in));

        nomeArq = leitor.readLine();

        while (nomeArq.equals("FIM") != true) {
            array[countPlayers] = new Player();
            tratamentoString(leituraArquivo(nomeArq));
            countPlayers++;
            nomeArq = leitor.readLine();
        } // end while
         int k = countPlayers;
        sort(0, countPlayers -1 , k);
       // desempate(countPlayers);
       
        for (int i = 0; i < countPlayers; i++)
        {   
            list.inserirFim( array[i]);
        }
        
    

        list.mostrar();

    }// end main

}// class Main