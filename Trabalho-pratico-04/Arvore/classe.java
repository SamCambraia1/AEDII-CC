import java.io.*;
import java.util.*;

class ArvoreBinaria {
	private No raiz; // Raiz da arvore.

	/**
	 * Construtor da classe.
	 */
	public ArvoreBinaria() {
		raiz = null;
	}

	/**
	 * Metodo publico iterativo para pesquisar elemento.
	 * 
	 * @param x Elemento que sera procurado.
	 * @return <code>true</code> se o elemento existir, <code>false</code> em caso
	 *         contrario.
	 */
	public boolean pesquisar(String x) {
		boolean trueOrFalse = false;
		System.out.print(x+" ");
		if (x.equals(raiz.elemento.getNome())) {
			trueOrFalse = true;
			System.out.print("raiz ");
		} else {
			System.out.print("raiz ");
			trueOrFalse = pesquisar(x, raiz);
		}
		if (trueOrFalse == true) {
			System.out.println("SIM");
		} else {
			System.out.println("NAO");
			
		}
		return trueOrFalse;
	}

	/**
	 * Metodo privado recursivo para pesquisar elemento.
	 * 
	 * @param x Elemento que sera procurado.
	 * @param i No em analise.
	 * @return <code>true</code> se o elemento existir, <code>false</code> em caso
	 *         contrario.
	 */
	private boolean pesquisar(String x, No i) {
		boolean resp;
		if (i == null) {
			resp = false;

		} else if (x.compareToIgnoreCase(i.elemento.getNome()) == 0) {
			resp = true;

		} else if (x.compareTo(i.elemento.getNome()) < 0) {
			System.out.print("esq ");
			resp = pesquisar(x, i.esq);

		} else {
			System.out.print("dir ");
			resp = pesquisar(x, i.dir);
		}
		return resp;
	}

	/**
	 * Metodo publico iterativo para exibir elementos.
	 */
	public void caminharCentral() {
		System.out.print("[ ");
		caminharCentral(raiz);
		System.out.println("]");
	}

	/**
	 * Metodo privado recursivo para exibir elementos.
	 * 
	 * @param i No em analise.
	 */
	private void caminharCentral(No i) {
		if (i != null) {
			caminharCentral(i.esq); // Elementos da esquerda.
			System.out.print(i.elemento + " "); // Conteudo do no.
			caminharCentral(i.dir); // Elementos da direita.
		}
	}

	/**
	 * Metodo publico iterativo para exibir elementos.
	 */
	public void caminharPre() {
		System.out.print("[ ");
		caminharPre(raiz);
		System.out.println("]");
	}

	/**
	 * Metodo privado recursivo para exibir elementos.
	 * 
	 * @param i No em analise.
	 */
	private void caminharPre(No i) {
		if (i != null) {
			System.out.print(i.elemento + " "); // Conteudo do no.
			caminharPre(i.esq); // Elementos da esquerda.
			caminharPre(i.dir); // Elementos da direita.
		}
	}

	/**
	 * Metodo publico iterativo para exibir elementos.
	 */
	public void caminharPos() {
		System.out.print("[ ");
		caminharPos(raiz);
		System.out.println("]");
	}

	/**
	 * Metodo privado recursivo para exibir elementos.
	 * 
	 * @param i No em analise.
	 */
	private void caminharPos(No i) {
		if (i != null) {
			caminharPos(i.esq); // Elementos da esquerda.
			caminharPos(i.dir); // Elementos da direita.
			System.out.print(i.elemento + " "); // Conteudo do no.
		}
	}

	/**
	 * Metodo publico iterativo para inserir elemento.
	 * 
	 * @param x Elemento a ser inserido.
	 * @throws Exception Se o elemento existir.
	 */
	public void inserir(Player x) throws Exception {
		raiz = inserir(x, raiz);
	}

	/**
	 * Metodo privado recursivo para inserir elemento.
	 * 
	 * @param x Elemento a ser inserido.
	 * @param i No em analise.
	 * @return No em analise, alterado ou nao.
	 * @throws Exception Se o elemento existir.
	 */
	private No inserir(Player x, No i) throws Exception {
		if (i == null) {
			i = new No(x);

		} else if (x.getNome().compareTo(i.elemento.getNome()) < 0) {
			i.esq = inserir(x, i.esq);

		} else if (x.getNome().compareTo(i.elemento.getNome()) > 0) {
			i.dir = inserir(x, i.dir);

		} else {
			throw new Exception("Erro ao inserir!");
		}

		return i;
	}

	/**
	 * Metodo publico para inserir elemento.
	 * 
	 * @param x Elemento a ser inserido.
	 * @throws Exception Se o elemento existir.
	 */
	public void inserirPai(Player x) throws Exception {
		if (raiz == null) {
			raiz = new No(x);
		} else if (x.getNome().compareTo(raiz.elemento.getNome()) < 0) {
			inserirPai(x, raiz.esq, raiz);
		} else if (x.getNome().compareTo(raiz.elemento.getNome()) > 0) {
			inserirPai(x, raiz.dir, raiz);
		} else {
			throw new Exception("Erro ao inserirPai!");
		}
	}

	/**
	 * Metodo privado recursivo para inserirPai elemento.
	 * 
	 * @param x   Elemento a ser inserido.
	 * @param i   No em analise.
	 * @param pai No superior ao em analise.
	 * @throws Exception Se o elemento existir.
	 */
	private void inserirPai(Player x, No i, No pai) throws Exception {
		if (i == null) {
			if (x.getNome().compareTo(i.elemento.getNome()) < 0) {
				pai.esq = new No(x);
			} else {
				pai.dir = new No(x);
			}
		} else if (x.getNome().compareTo(i.elemento.getNome()) < 0) {
			inserirPai(x, i.esq, i);
		} else if (x.getNome().compareTo(i.elemento.getNome()) > 0) {
			inserirPai(x, i.dir, i);
		} else {
			throw new Exception("Erro ao inserirPai!");
		}
	}

	/**
	 * Metodo publico iterativo para remover elemento.
	 * 
	 * @param x Elemento a ser removido.
	 * @throws Exception Se nao encontrar elemento.
	 */
	public void remover(Player x) throws Exception {
		raiz = remover(x, raiz);
	}

	/**
	 * Metodo privado recursivo para remover elemento.
	 * 
	 * @param x Elemento a ser removido.
	 * @param i No em analise.
	 * @return No em analise, alterado ou nao.
	 * @throws Exception Se nao encontrar elemento.
	 */
	private No remover(Player x, No i) throws Exception {

		if (i == null) {
			throw new Exception("Erro ao remover!");

		} else if (x.getNome().compareTo(i.elemento.getNome()) < 0) {
			i.esq = remover(x, i.esq);

		} else if (x.getNome().compareTo(i.elemento.getNome()) > 0) {
			i.dir = remover(x, i.dir);

			// Sem no a direita.
		} else if (i.dir == null) {
			i = i.esq;

			// Sem no a esquerda.
		} else if (i.esq == null) {
			i = i.dir;

			// No a esquerda e no a direita.
		} else {
			i.esq = antecessor(i, i.esq);
		}

		return i;
	}

	/**
	 * Metodo para trocar no removido pelo antecessor.
	 * 
	 * @param i No que teve o elemento removido.
	 * @param j No da subarvore esquerda.
	 * @return No em analise, alterado ou nao.
	 */
	private No antecessor(No i, No j) {

		// Existe no a direita.
		if (j.dir != null) {
			// Caminha para direita.
			j.dir = antecessor(i, j.dir);

			// Encontrou o maximo da subarvore esquerda.
		} else {
			i.elemento = j.elemento; // Substitui i por j.
			j = j.esq; // Substitui j por j.ESQ.
		}
		return j;
	}

	/**
	 * Metodo publico iterativo para remover elemento.
	 * 
	 * @param x Elemento a ser removido.
	 * @throws Exception Se nao encontrar elemento.
	 */
	public void remover2(Player x) throws Exception {
		if (raiz == null) {
			throw new Exception("Erro ao remover2!");
		} else if (x.getNome().compareTo(raiz.elemento.getNome()) < 0) {
			remover2(x, raiz.esq, raiz);
		} else if (x.getNome().compareTo(raiz.elemento.getNome()) > 0) {
			remover2(x, raiz.dir, raiz);
		} else if (raiz.dir == null) {
			raiz = raiz.esq;
		} else if (raiz.esq == null) {
			raiz = raiz.dir;
		} else {
			raiz.esq = antecessor(raiz, raiz.esq);
		}
	}

	/**
	 * Metodo privado recursivo para remover elemento.
	 * 
	 * @param x   Elemento a ser removido.
	 * @param i   No em analise.
	 * @param pai do No em analise.
	 * @throws Exception Se nao encontrar elemento.
	 */
	private void remover2(Player x, No i, No pai) throws Exception {
		if (i == null) {
			throw new Exception("Erro ao remover2!");
		} else if (x.getNome().compareTo(i.elemento.getNome()) < 0) {
			remover2(x, i.esq, i);
		} else if (x.getNome().compareTo(i.elemento.getNome()) > 0) {
			remover2(x, i.dir, i);
		} else if (i.dir == null) {
			pai = i.esq;
		} else if (i.esq == null) {
			pai = i.dir;
		} else {
			i.esq = antecessor(i, i.esq);
		}
	}

	public Player getRaiz() throws Exception {
		return raiz.elemento;
	}

	public static boolean igual(ArvoreBinaria a1, ArvoreBinaria a2) {
		return igual(a1.raiz, a2.raiz);
	}

	private static boolean igual(No i1, No i2) {
		boolean resp;
		if (i1 != null && i2 != null) {
			resp = (i1.elemento == i2.elemento) && igual(i1.esq, i2.esq) && igual(i1.dir, i2.dir);
		} else if (i1 == null && i2 == null) {
			resp = true;
		} else {
			resp = false;
		}
		return resp;
	}

	public int soma() {
		return soma(raiz);
	}

	public int soma(No i) {
		int resp = 0;
		if (i != null) {
			resp = i.elemento.getAltura() + soma(i.esq) + soma(i.dir);
		}
		return resp;
	}

	public int quantidadePares() {
		return quantidadePares(raiz);
	}

	public int quantidadePares(No i) {
		int resp = 0;
		if (i != null) {
			resp = ((i.elemento.getAltura() % 2 == 0) ? 1 : 0) + quantidadePares(i.esq) + quantidadePares(i.dir);
		}
		return resp;
	}

	public boolean hasDiv11() {
		return hasDiv11(raiz);
	}

	public boolean hasDiv11(No i) {
		boolean resp = false;
		if (i != null) {
			resp = (i.elemento.getAltura() % 11 == 0) || hasDiv11(i.esq) || hasDiv11(i.dir);
		}
		return resp;
	}
}


class No {
    public Player elemento; // Conteudo do no.
    public No esq, dir; // Filhos da esq e dir.

    /**
     * Construtor da classe.
     * 
     * @param elemento Conteudo do no.
     */
    public No(Player elemento) {
        this(elemento, null, null);
    }

    /**
     * Construtor da classe.
     * 
     * @param elemento Conteudo do no.
     * @param esq      No da esquerda.
     * @param dir      No da direita.
     */
    public No(Player elemento, No esq, No dir) {
        this.elemento = elemento;
        this.esq = esq;
        this.dir = dir;
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

    public static ArvoreBinaria tree = new ArvoreBinaria();
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

        while (nomeArq.equals("FIM") != true) {
            array[countPlayers] = new Player();
            tratamentoString(leituraArquivo(nomeArq));
            countPlayers++;
            nomeArq = leitor.readLine();
        } // end while
 

       // desempate(countPlayers);
       
        for (int i = 0; i < countPlayers; i++)
        {   
            tree.inserir( array[i]);
        }
           
        String arrayOps[] = new String[1024];
        int count = 0;
        arrayOps[count] = leitor.readLine();
        while (arrayOps[count].equals("FIM") == false) {
            // System.out.println("chegou");
            count++;
            arrayOps[count] = leitor.readLine();
        }
        for (int i = 0; i < count; i++) {
            // System.out.println(arrayOps[i]);
            tree.pesquisar(arrayOps[i]);
        }

       

    }// end main

}// class Main