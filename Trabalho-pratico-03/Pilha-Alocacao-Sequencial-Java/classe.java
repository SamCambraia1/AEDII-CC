import java.io.*;
import java.util.*;

class Lista {

    private Player[] array;
    private int n;

    public Lista() {
        this(1000);
    }

    public Lista(int tamanho) {
        array = new Player[tamanho];
        int n = 0;

    }// end construct Lista

    public void inserirInicio(Player x) throws Exception {
        if (n >= array.length) {
            throw new Exception("Erro ao inserir");
        } // end if
        for (int i = n; i > 0; i--) {
            array[i] = array[i - 1];
        }

        array[0] = x;
        n++;
    }// end inserirInicio

    public void inserirFim(Player x) throws Exception {
        if (n >= array.length) {
            throw new Exception("erro ao inserir");
        } // end if

        array[n] = x;
        n++;
    }// end inserirFim

    public void inserir(Player x, int pos) throws Exception {
        if (n >= array.length || pos < 0 || pos > n) {
            throw new Exception("Erro ao inserir");
        } // end if
        for (int i = n; i > pos; i--) {
            array[i] = array[i - 1];
        }

        array[pos] = x;
        n++;
    }// end inserir

    public Player removerInicio() throws Exception {

        if (n == 0) {
            throw new Exception("Erro ao remover Inicio");
        } // end if

        Player saida = array[0];
        n--;

        for (int i = 0; i < n; i++) {
            array[i] = array[i + 1];
        } // end for

        return saida;
    }// end removerInicio

    public Player removerFim() throws Exception {

        if (n == 0) {
            throw new Exception("Erro ao remover Fim");

        } // end if

        Player saida = array[--n];
        return saida;
    }// end removerFim

    public Player remover(int pos) throws Exception {

        // validar remocao
        if (n == 0 || pos < 0 || pos >= n) {
            throw new Exception("Erro ao remover!");
        }

        Player resp = array[pos];
        n--;

        for (int i = pos; i < n; i++) {
            array[i] = array[i + 1];
        }

        return resp;
    }// end remover

    public void mostrar() {
        for (int i = 0; i < n; i++) {
            System.out.print("[" + i + "]");
            array[i].Imprimir();
        }

    }// end mostrar

    public boolean pesquisa(Player x) throws Exception {
        boolean retorno = false;
        for (int i = 0; i < n && retorno == false; i++) {
            retorno = (array[i] == x);
        } // end for
        return retorno;
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

    public void Imprimir() {

        System.out.println(" ## " + getNome() + " ## " + getAltura() + " ## " + getPeso() + " ## " + getAnoNascimento()
                + " ## " + getUniversidade() + " ## " + getCidadeNascimento() + " ## " + getEstadoDeNascimento()
                + " ##");
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

                ply = new Player();
                tratamentoString(leituraArquivo(operacao[1]));

                list.inserirFim(ply);

            } // end if insercao

            if (operacao[0].charAt(0) == 'R') {

                Player temp = list.removerFim();
                System.out.println("(R) " + temp.getNome());

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
