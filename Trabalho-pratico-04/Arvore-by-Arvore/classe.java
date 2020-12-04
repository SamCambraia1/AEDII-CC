import java.io.*;
import java.util.*;

class Node {
	public int elemento; // Elemento inserido na celula.
	public Node esq, dir;  // Filhos da esq e dir.
	public Node2 outro;
	
	public Node(int elemento) { 
	   this.elemento = elemento;
	   this.esq = this.dir = null;
	   this.outro = null;
	}
 
	public Node(int elemento, Node esq, Node dir,Node2 outro) {
	   this.elemento = elemento;
	   this.esq = esq;
	   this.dir = dir;
	   this.outro = outro;
	}
	
 }
 
 
 
 class Node2 {
	public String elemento; // Conteudo do Node.
	public Node2 esq; // Node da esquerda.
	public Node2 dir; // Node da direita.
	 
 
	Node2(String elemento) {
	   this.elemento = elemento;
	   this.esq = this.dir = null;
	}
 
	Node2(String elemento, Node2 esq, Node2 dir) {
	   this.elemento = elemento;
	   this.esq = esq;
	   this.dir = dir;
	}
 }
 
 
 
 class Arvore {
	private Node raiz; // Raiz da arvore.
 
	public Arvore() {
	   raiz = null;
	}
	
 
	
	public boolean pesquisar(String x){
	   
	   if(raiz != null){
		  System.out.print(" raiz");
	   }
	   return pesquisar(x,raiz);
	} 
   
	private boolean pesquisar(String x,Node i){
	   boolean resp= false;
	   if(i != null){    
	   
		  resp=pesquisar2(x,i.outro);
		  
		  if(resp == false){ 
			 System.out.print(" esq");
			resp= pesquisar(x,i.esq);
		  }
		  if(resp == false){ 
			System.out.print(" dir");
			 resp=pesquisar(x,i.dir);
		  }
	   }
	
	 
	   return resp;
	}
 
 
 
	private boolean pesquisar2(String x, Node2 i) {
	   boolean resp= false;
	   if(i != null){
		  
		  if (x.compareTo(i.elemento)==0) {
			 resp = true;
		
		  } 
		  else{
		  
		  System.out.print(" ESQ");
			 resp = pesquisar2(x, i.esq);
		  
			 if(resp == false){
			 System.out.print(" DIR");
				resp = pesquisar2(x, i.dir);
			 }
		  }
	   }
	   return resp;
	}
	
 
   
	public void inserir(int x) throws Exception {
	   raiz = inserir(x, raiz);
	}
 
 
	private Node inserir(int x, Node i) throws Exception {
	   if (i == null) {
		  i = new Node(x);  
	   } 
	   else if (x <i.elemento ){
		  i.esq = inserir(x, i.esq);
	   
	   } 
	   else if (x > i.elemento ){
		  i.dir = inserir(x, i.dir);
	   
	   } 
	   else {
		  throw new Exception("Erro ao inserir!");
	   }
	
	   return i;
	}
   
   
 
   
	public void inserir2(String x,int y) throws Exception {
	   inserir2(x,y,raiz);
	}
 
 
	private void inserir2(String x,int y,Node i) throws Exception {
	   if (i.elemento == y) {
		  i.outro=inserir3(x,i.outro);
	   } 
	   else if (y < i.elemento ){
		  inserir2(x,y,i.esq);
	   
	   } 
	   else if (y > i.elemento ){
		  inserir2(x,y,i.dir);
	   
	   } 
	   else {
		  throw new Exception("Erro ao inserir!");
	   }
	
	}
 
 
   
	private Node2 inserir3(String x, Node2 i)throws Exception{
	 
	   if(i == null ){
		  i = new Node2(x);
	   }
	   else  
		  if(x.compareTo(i.elemento)<0) 
			 i.esq=inserir3(x,i.esq);
		  else
			 if(x.compareTo(i.elemento)>0)
				i.dir=inserir3(x,i.dir);
			 else {
				throw new Exception("Erro ao inserir!");
			 }
	   return i;
	
	}
  
  
  
 
 }
 

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



public class classe {

    public static Arvore tree = new Arvore();
    public static Player[] array = new Player[1000];
    public static Player ply;
    
    public static int countPlayers = 0;



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

        tree.inserir(7);
        tree.inserir(3);
        tree.inserir(11);
        tree.inserir(1);
        tree.inserir(5);
        tree.inserir(9);
        tree.inserir(12);
        tree.inserir(0);
        tree.inserir(2);
        tree.inserir(4);
        tree.inserir(6);
        tree.inserir(8);
        tree.inserir(10);
        tree.inserir(13);
        tree.inserir(14); 



        while (nomeArq.equals("FIM") != true) {
            array[countPlayers] = new Player();
            tratamentoString(leituraArquivo(nomeArq));
            countPlayers++;
            nomeArq = leitor.readLine();
        } // end while
 

      
       
        for (int i = 0; i < countPlayers; i++)
        {   
              int val = array[i].getAltura() % 15;
              tree.inserir2( array[i].getNome(),val);
        }
           
        String nomeEnt;
        boolean pesq = false;
        
      
        nomeEnt = leitor.readLine();
        while (nomeEnt.equals("FIM") == false) {
            
            System.out.print(nomeEnt);
            System.out.print( (pesq = tree.pesquisar(nomeEnt))? " SIM\n": " NAO\n");
            
            nomeEnt = leitor.readLine();
        }
             

    }// end main

}// class Main