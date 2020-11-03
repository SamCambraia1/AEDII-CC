import java.io.*;
import java.util.*;

class Player {
  private int id;
  private String universidade;
  private int altura;
  private String nome;
  private int peso;
  private String cidadeNascimento;
  private int anoNascimento;
  private String estadoNacimento;

  public Player() {
    id = 0;
    altura = 0;
    peso = 0;
    anoNascimento = 0;
    nome = "";
    universidade = "";
    cidadeNascimento = "";
    estadoNacimento = "";
  } //end construtor padrao

  public void setId(int id) {
    this.id = id;
  } //end setId

  public int getId() {
    return id;
  } //end getId

  public void setAltura(int altura) {
    this.altura = altura;
  } //end setAltura

  public int getAltura() {
    return altura;
  } //end getAltura

  public void setPeso(int peso) {
    this.peso = peso;
  } //end setPesoo

  public int getPeso() {
    return peso;
  } //end getPeso

  public void setAnoNascimento(int anoNascimento) {
    this.anoNascimento = anoNascimento;
  } //end setAnoNascimento

  public int getAnoNascimento() {
    return anoNascimento;
  } //end getAnoNascimento

  public void setNome(String nome) {
    this.nome = nome;
  } //end setNome

  public String getNome() {
    return nome;
  } //end getNome

  public void setUniversidade(String universidade) {
    this.universidade = universidade;
  } //end setUniversidade

  public String getUniversidade() {
    return universidade;
  } //end getUniversidade

  public void setCidadeNascimento(String cidadeNascimento) {
    this.cidadeNascimento = cidadeNascimento;
  } //end setCidadeNascimento

  public String getCidadeNascimento() {
    return cidadeNascimento;
  } //end GetCidadeNascimento

  public void setEstadoDeNascimento(String estadoNascimento) {
    this.estadoNacimento = estadoNascimento;
  } //end setEstadoDeNascimento

  public String getEstadoDeNascimento() {
    return estadoNacimento;
  } //end setEstadoDeNascimento
} //class objeto

public class classe {
  public static Player[] ply = new Player[1000];
  public static int coutPlayers = 0;


  public static void Count( int n){

    Player temp; 
   
      for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
             if(ply[i].getAltura() == ply[j].getAltura()){
                if(ply[i].getNome().compareTo(ply[j].getNome())>0){
                   temp=ply[i];
                   ply[i]=ply[j];
                   ply[j]=temp;
                 }
             }else{
                j=n;     
              }
          }
      }
   }
   public static void sort(){ 
     //Array para contar o numero de ocorrencias de cada elemento
     int[] count = new int[getMaior(ply,coutPlayers) + 1];
     Player[] ordenado = new Player[coutPlayers];

     //Inicializar cada posicao do array de contagem 
   for (int i = 0; i < count.length; count[i] = 0, i++);

     //Agora, o count[i] contem o numero de elemento iguais a i
     for (int i = 0; i < coutPlayers; count[ply[i].getAltura()]++, i++);

     //Agora, o count[i] contem o numero de elemento menores ou iguais a i
     for(int i = 1; i < count.length; count[i] += count[i-1], i++);

     //Ordenando
     for(int i = coutPlayers-1; i >= 0; ordenado[count[ply[i].getAltura()]-1] = ply[i], count[ply[i].getAltura()]--, i--);

     //Copiando para o array original
     for(int i = 0; i < coutPlayers; ply[i] = ordenado[i], i++);
  }


 public static int getMaior(Player temp[],int n) {
    int maior = temp[0].getAltura();
    String nome = temp[0].getNome();
   for (int i = 0; i < n; i++) {
        if(maior < temp[i].getAltura()  ){
           maior = temp[i].getAltura();
        }
   }
    return maior;	
 }

  public static void Imprimir() {
   
   for(int i = 0; i < coutPlayers; i ++){

       System.out.println(
           "[" +
           ply[i].getId() +
           " ## " +
           ply[i].getNome() +
           " ## " +
           ply[i].getAltura() +
           " ## " +
           ply[i].getPeso() +
           " ## " +
           ply[i].getAnoNascimento() +
           " ## " +
           ply[i].getUniversidade() +
           " ## " +
           ply[i].getCidadeNascimento() +
           " ## " +
           ply[i].getEstadoDeNascimento() +
           "]"
           );
        } 
  } //end imprimir

  public static void tratamentoString(String s) throws Exception {
    int tam = s.length();
    if (s.charAt(tam - 1) == ',') s = s + "nao informado";
    s = s.replaceAll(",,", ",nao informado,");
    String vetor[] = s.split(",");

    int id = Integer.parseInt(vetor[0]);
    ply[coutPlayers].setId(id);

    ply[coutPlayers].setNome(vetor[1]);

    int altura = Integer.parseInt(vetor[2]);
    ply[coutPlayers].setAltura(altura);

    int peso = Integer.parseInt(vetor[3]);
    ply[coutPlayers].setPeso(peso);

    ply[coutPlayers].setUniversidade(vetor[4]);

    int anoNascimento = Integer.parseInt(vetor[5]);
    ply[coutPlayers].setAnoNascimento(anoNascimento);

    ply[coutPlayers].setCidadeNascimento(vetor[6]);

    ply[coutPlayers].setEstadoDeNascimento(vetor[7]);
  } //end tratamentoString

  public static String leituraArquivo(String nomeArq) throws Exception {
    String linha = "";
    BufferedReader file = new BufferedReader(
      new InputStreamReader(new FileInputStream("/tmp/players.csv"))
    );

    linha = file.readLine();
    while (linha != null) {
      String[] id = linha.split(",");
      if (id[0].equals(nomeArq) == true) return linha;
      linha = file.readLine();
    } //end while
    String s = "";

    return s;
  } //end leituraArquivo

  public static void main(String[] args) throws Exception {
    String nomeArq = "";
    BufferedReader leitor = new BufferedReader(
      new InputStreamReader(System.in)
    );

    nomeArq = leitor.readLine();

    while (nomeArq.equals("FIM") != true) {
      ply[coutPlayers] = new Player();
      
      tratamentoString(leituraArquivo(nomeArq));
      coutPlayers += 1;
      nomeArq = leitor.readLine();
    } //end while
    sort();
    Count(coutPlayers);
    Imprimir();
} //end main
} //class
