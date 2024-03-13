import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import java.io.*;
import javax.swing.ImageIcon;


public class App extends JFrame implements WindowListener, ActionListener {
    JButton botao1, botao2;
    JTextField[] informacao;
    JTextField times;
    int caractere, variavel = 0;
    String[] caminhosImagens;
    String dados, lista[];
    String[][] listaindividual;
    FileInputStream arquivo;
    DataInputStream leitor;

    public App() {
        setLayout(null);
        setResizable(false);
        setTitle("Dados Pessoais");
        setBounds(100, 200, 640, 480);
        getContentPane().setBackground(Color.gray);

        botao1 = new JButton("voltar");
        botao1.setEnabled(false);
        botao1.setBounds(150, 400, 120, 25);

        botao2 = new JButton("proximo");
        botao2.setBounds(380, 400, 120, 25);


        leArquivoTexto("dados.txt");

        lista = dados.split("\n\r");
        this.listaindividual = new String[lista.length][];

        for (int i = 0; i < lista.length; i++) {
            this.listaindividual[i] = lista[i].split(";");
        }
        
        informacao = new JTextField[listaindividual[0].length];
        System.out.println(variavel);

        caminhosImagens = new String[listaindividual.length];

         caminhosImagens[0] = "Fotos/palmeiras.png";
         caminhosImagens[1] = "Fotos/sp.png";
         caminhosImagens[2] = "Fotos/corinthians.png";
         caminhosImagens[3] = "Fotos/santos.png";
         caminhosImagens[4] = "Fotos/flamengo.png";
         caminhosImagens[5] = "Fotos/fluminense.png";
         caminhosImagens[6] = "Fotos/vasco.png";
         caminhosImagens[7] = "Fotos/botafogo.png";
         caminhosImagens[8] = "Fotos/galo.png";
         caminhosImagens[9] = "Fotos/cruzeiro.png";

        reloadtela();

        System.out.println(listaindividual[0][0]);
        System.out.println(lista.length);


        getContentPane().add(botao1);
        getContentPane().add(botao2);

        botao1.addActionListener(this);
        botao2.addActionListener(this);

        addWindowListener(this);
    }

    public void leArquivoTexto(String nomeArquivo) {
        try {
            dados = "";
            arquivo = new FileInputStream(nomeArquivo);
            leitor = new DataInputStream(arquivo);
            caractere = 0;
            while (caractere != -1) {
                caractere = leitor.read();
                if (caractere != -1) {
                    dados = dados + (char) caractere;
                }
            }
            arquivo.close();
        } catch (IOException erro) {
            System.out.println("Arquivo não existe...");
            System.out.println(erro.getMessage());
        }
    }

    public void reloadtela(){

        for (int j = 0; j < listaindividual[variavel].length-1; j++) {
            System.out.println(listaindividual[variavel][j]);
            System.out.println("Caminho da imagem: " + caminhosImagens[variavel]);
            informacao[j] = new JTextField(listaindividual[variavel][j]);
            informacao[j].setEditable(false);
            informacao[j].setBounds(220, 150 + 30 * j, 200, 25);
            getContentPane().add(informacao[j]);
        }
            ImageIcon imagemIcon = new ImageIcon(caminhosImagens[variavel]);
            JLabel imagemLabel = new JLabel(imagemIcon);
            imagemLabel.setBounds(-20, 100, 250, 250);
            getContentPane().add(imagemLabel);

            times = new JTextField("Times");
            times.setEditable(false);
            times.setBounds(300, 50, 40, 35);
            times.setBackground(Color.darkGray);
            times.setForeground(Color.WHITE);
            getContentPane().add(times);
    }
    

    @Override
    public void windowOpened(WindowEvent we) {
    }

    @Override
    public void windowClosing(WindowEvent we) {
        this.dispose();
        System.exit(1);
    }

    @Override
    public void windowClosed(WindowEvent we) {
        this.dispose();
        System.exit(1);
    }

    @Override
    public void windowIconified(WindowEvent we) {
    }

    @Override
    public void windowDeiconified(WindowEvent we) {
    }

    @Override
    public void windowActivated(WindowEvent we) {
    }

    @Override
    public void windowDeactivated(WindowEvent evento) {
    }

    public static void main(String[] args) {
        App app = new App();
        app.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent evento) {
    if (evento.getSource() == botao1) {

        
        System.out.println("Voltar");
        if (variavel > 0) {
            variavel = variavel - 1;

        getContentPane().removeAll();

            informacao = new JTextField[listaindividual[variavel].length];

            reloadtela();

            getContentPane().add(botao1);
            getContentPane().add(botao2);

            repaint();

        }
        botao2.setEnabled(true);

        if (variavel == 0) {
            botao1.setEnabled(false);
        }

    }

    if (evento.getSource() == botao2) {
        System.out.println("Proximo");
        botao1.setEnabled(true);

        if (variavel < listaindividual.length - 1) {
            variavel = variavel + 1;

            getContentPane().removeAll();

            informacao = new JTextField[listaindividual[variavel].length];
            
            reloadtela();

            getContentPane().add(botao1);
            getContentPane().add(botao2);

            repaint();

            botao2.setEnabled(variavel < listaindividual.length - 1);
            }
        }
    }
}
