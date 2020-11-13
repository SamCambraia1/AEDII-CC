import java.io.*;
import java.util.*;

class Celula {
    public Player elemento; // Elemento inserido na celula.
    public Celula prox; // Aponta a celula prox.

    /**
     * Construtor da classe.
     */
    public Celula() {
        this(new Player());
    }// end construtor Celula

    /**
     * Construtor da classe.
     * 
     * @param elemento int inserido na celula.
     */
    public Celula(Player elemento) {
        this.elemento = elemento;
        this.prox = null;
    }// end public Celula

}// end class Celula

class Lista {

    private Celula primeiro;
    private Celula ultimo;

    public Lista() {
        primeiro = new Celula();
        ultimo = primeiro;
    }// end construtor Celula

    public void inserirInicio(Player x) throws Exception {
        Celula tmp = new Celula(x);
        tmp.prox = primeiro.prox;
        primeiro.prox = tmp;
        if (primeiro == ultimo) {
            ultimo = tmp;
        }
        tmp = null;
    }// end inserirInicio

    public void inserirFim(Player x) {
        ultimo.prox = new Celula(x);
        ultimo = ultimo.prox;
    }// end inserirFim

    public Player removerInicio() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");
        }

        Celula tmp = primeiro;
        primeiro = primeiro.prox;
        Player resp = primeiro.elemento;
        tmp.prox = null;
        tmp = null;
        return resp;
    }// end removerInicio

    public Player removerFim() throws Exception {
        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");
        }

        // Caminhar ate a penultima celula:
        Celula i;
        for (i = primeiro; i.prox != ultimo; i = i.prox)
            ;

        Player resp = ultimo.elemento;
        ultimo = i;
        i = ultimo.prox = null;

        return resp;
    }// end removerFim

    public void inserir(Player x, int pos) throws Exception {

        int tamanho = tamanho();

        if (pos < 0 || pos > tamanho) {
            throw new Exception("Erro ao inserir posicao (" + pos + " / tamanho = " + tamanho + ") invalida!");
        } // end if
        else if (pos == 0) {
            inserirInicio(x);
        } // end else if
        else if (pos == tamanho) {
            inserirFim(x);
        } // end else if
        else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox);

            Celula tmp = new Celula(x);
            tmp.prox = i.prox;
            i.prox = tmp;
            tmp = i = null;
        } // end else
    }// end inserir (I* - insere um elemento em qualquer lugar)

    public Player remover(int pos) throws Exception {
        Player resp;
        int tamanho = tamanho();

        if (primeiro == ultimo) {
            throw new Exception("Erro ao remover (vazia)!");

        } // end if
        else if (pos < 0 || pos >= tamanho) {
            throw new Exception("Erro ao remover (posicao " + pos + " / " + tamanho + " invalida!");
        } // end else if
        else if (pos == 0) {
            resp = removerInicio();
        } // end else if
        else if (pos == tamanho - 1) {
            resp = removerFim();
        } // end else if
        else {
            // Caminhar ate a posicao anterior a insercao
            Celula i = primeiro;
            for (int j = 0; j < pos; j++, i = i.prox)
                ;

            Celula tmp = i.prox;
            resp = tmp.elemento;
            i.prox = tmp.prox;
            tmp.prox = null;
            i = tmp = null;
        } // end else

        return resp;
    }// end remover ( R* - Remove em qualquer posicao selecionada)

    public int tamanho() {
        int tamanho = 0;
        for (Celula i = primeiro; i != ultimo; i = i.prox, tamanho++)
            ;
        return tamanho;
    }// end tamanho

    public void mostrar() {
        int x = 0;
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            i.elemento.Imprimir(x);
            x++;
        } // end for

    }// end mostrar

    public boolean pesquisar(Player x) {
        boolean resp = false;
        for (Celula i = primeiro.prox; i != null; i = i.prox) {
            if (i.elemento == x) {
                resp = true;
                i = ultimo;
            } // end if
        } // end for
        return resp;
    }// end pesquisa

}// end class Lista

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

    public void Imprimir(int i) {

        System.out.println("[" + i + "]" + " ## " + getNome() + " ## " + getAltura() + " ## " + getPeso() + " ## "
                + getAnoNascimento() + " ## " + getUniversidade() + " ## " + getCidadeNascimento() + " ## "
                + getEstadoDeNascimento() + " ##");
    } // end imprimir

}// class objeto

public class classe {

    public static Lista list = new Lista();
    public static Player ply = new Player();
    public static int countPlayers = 0;

    public static void tratamentoString(String s) throws Exception {
        int tam = s.length();
        if (s.charAt(tam - 1) == ',')
            s = s + "nao informado";
        s = s.replaceAll(",,", ",nao informado,");
        String vetor[] = s.split(",");

        int id = Integer.parseInt(vetor[0]);

        ply.setId(id);

        ply.setNome(vetor[1]);

        int altura = Integer.parseInt(vetor[2]);

        ply.setAltura(altura);

        int peso = Integer.parseInt(vetor[3]);

        ply.setPeso(peso);

        ply.setUniversidade(vetor[4]);

        int anoNascimento = Integer.parseInt(vetor[5]);

        ply.setAnoNascimento(anoNascimento);

        ply.setCidadeNascimento(vetor[6]);

        ply.setEstadoDeNascimento(vetor[7]);

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

    public static void tratamentoCasos(BufferedReader leitor) throws Exception {

        // BufferedReader leitor = new BufferedReader(new InputStreamReader(System.in));
        String entrada = "";
        int count = 0;
        String casos = leitor.readLine();
        while (count < Integer.parseInt(casos)) {

            entrada = leitor.readLine();

            String[] operacao = entrada.split(" ");

            if (operacao[0].charAt(0) == 'I') {

                if (operacao[0].charAt(1) == 'I') {
                    ply = new Player();
                    tratamentoString(leituraArquivo(operacao[1]));

                    list.inserirInicio(ply);

                } // end (II) inserir inicio
                else if (operacao[0].charAt(1) == 'F') {

                    ply = new Player();
                    tratamentoString(leituraArquivo(operacao[1]));

                    list.inserirFim(ply);

                } // end (IF) inserir fim
                else {

                    ply = new Player();
                    tratamentoString(leituraArquivo(operacao[2]));

                    list.inserir(ply, Integer.parseInt(operacao[1]));

                } // end (I*) inserir em qualquer lugar

            } // end if insercao

            if (operacao[0].charAt(0) == 'R') {

                if (operacao[0].charAt(1) == 'I') {
                    Player temp = list.removerInicio();
                    System.out.println("(R) " + temp.getNome());
                } // end (RI) remover inicio
                else if (operacao[0].charAt(1) == 'F') {

                    Player temp = list.removerFim();
                    System.out.println("(R) " + temp.getNome());
                } // end (RF) remover fim
                else {
                    Player temp = list.remover(Integer.parseInt(operacao[1]));
                    System.out.println("(R) " + temp.getNome());
                } // end (R*) Remover local selecionado

            } // end if remocao
            count++;

        } // end while

    }// end tratamentoCasos

    public static void main(String[] args) throws Exception {

        String nomeArq = "";
        String casos = "";
        BufferedReader leitor = new BufferedReader(new InputStreamReader(System.in));

        nomeArq = leitor.readLine();

        while (nomeArq.equals("FIM") != true) {
            ply = new Player();
            tratamentoString(leituraArquivo(nomeArq));
            list.inserirFim(ply);

            nomeArq = leitor.readLine();
        } // end while

        tratamentoCasos(leitor);

        list.mostrar();

    }// end main

}// class Main
