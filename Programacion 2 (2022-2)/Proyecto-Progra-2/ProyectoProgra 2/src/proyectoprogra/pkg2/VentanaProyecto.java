
package proyectoprogra.pkg2;
import javax.swing.JFrame;

public class VentanaProyecto extends JFrame {
    
    public VentanaProyecto(){
        PanelPrincipalProyecto panel = new PanelPrincipalProyecto();
        addKeyListener(panel);
        this.setSize(1280, 720);
        setTitle("Pool");
        this.setResizable(false);
        this.add(panel);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setVisible(true);
        
    }
    
}
