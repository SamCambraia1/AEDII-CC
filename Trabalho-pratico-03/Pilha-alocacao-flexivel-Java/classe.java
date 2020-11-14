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
    }// end construtor celula

    /**
     * Construtor da classe.
     * 
     * @param elemento int inserido na celula.
     */
    public Celula(Player elemento) {
        this.elemento = elemento;
        this.prox = null;
    }// end public celula
}// end class Celula

class Pilha {

    private Celula topo;

    public Pilha() {
        topo = null;
    }

    public void inserir(Player x) {
       
        Celula tmp = new Celula(x);
        tmp.prox = topo;
        topo = tmp;
        tmp = null;

    }// inserir

    public Player remover() throws Exception {
        if (topo == null) {
            throw new Exception("Erro ao remover!");
        }
        Player resp = topo.elemento;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        return resp;
    }// end remover

    public void mostrar() {
        int x = 0;
        for (Celula i = topo; i != null; i = i.prox) {
            i.elemento.Imprimir(x);
            x++;
		}
	}

	public void mostraPilha() {
        mostraPilha(topo,142);
	}

	private void mostraPilha(Celula i,int x) {
         
        
        if (i != null) {
        
            mostraPilha(i.prox,--x);    
            i.elemento.Imprimir(x);
		}
	}

   

}// end class pilha

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

        System.out.println("["+i+"]"+" ## " + getNome() + " ## " + getAltura() + " ## " + getPeso() + " ## " + getAnoNascimento()
                + " ## " + getUniversidade() + " ## " + getCidadeNascimento() + " ## " + getEstadoDeNascimento()
                + " ##");
    } // end imprimir

}// class objeto

public class classe {

    public static Pilha pill = new Pilha();
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

                pill.inserir(ply);

            } // end if insercao

            if (operacao[0].charAt(0) == 'R') {

                Player temp = pill.remover();
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
            pill.inserir(ply);

            nomeArq = leitor.readLine();
        } // end while
       
        tratamentoCasos(leitor);

        pill.mostraPilha();

    }// end main

}// class Main
