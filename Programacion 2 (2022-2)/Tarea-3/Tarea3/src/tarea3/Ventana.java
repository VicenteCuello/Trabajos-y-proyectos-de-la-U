package tarea3;
import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Ventana extends JFrame{
    public PanelPrincipal panel;
    public Ventana(){
        this.setSize(800, 800);
        setTitle("Maquina expendedora de bebidas");
        this.setResizable(false);

        this.add(new PanelPrincipal());
    
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
    }

}

