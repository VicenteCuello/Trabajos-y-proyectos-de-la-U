
package proyectoprogra.pkg2;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.ImageIcon;
import javax.swing.JPanel;

/**
 *
 * @author Maximiliano Lopez
 * @author Ivan Zapata
 * @author Vicente Cuello
 * 
 */
public class PanelPrincipalProyecto extends JPanel implements KeyListener {
    
    private final startConfig start;
    private final MesaPool Table;
    private final Image wallpaper;
    
    /**Constructor de Panel en el cual se define la imagen de fondo y se inicializa lo que se mostrara en pantalla */
    public PanelPrincipalProyecto(){
        this.setBackground(Color.LIGHT_GRAY);
        this.setLayout(null);
        start = new startConfig();
        Table = new MesaPool();
        wallpaper = new ImageIcon("sources/wallpaper.jpg").getImage();
        start.startGame(this);
    }
    
    /**
     *Dibuja lo que se vera finalmente en la interfaz
     * @param g
     */
    @Override
    public void paint(Graphics g){
        g.drawImage(wallpaper,0,0, 1280, 720,null);
        Font font = new Font("Space Invaders",Font.BOLD,14);
        g.setFont(font);
        g.setColor(Color.white);
        g.drawString("PULSE", 500, 650);
        g.drawString("PULSE", 500, 670);
        g.drawString("BOTON", 5, 120);
        g.drawString("BOTON", 5, 140);
        g.drawString("BOTON", 5, 160);
        g.drawString("O ", 610, 670);
        g.setColor(Color.green);
        g.drawString("<- ", 570, 670);
        g.drawString("'R' ", 570, 650);
        g.drawString("'A': ", 570-490-15, 120);
        g.setColor(Color.CYAN);
        g.drawString("'G': ", 570-490-15, 160);
        g.setColor(Color.red);
        g.drawString("-> ", 630, 670);
        g.drawString("'M': ", 570-490-15, 140);
        g.setColor(Color.white);
        g.drawString("PARA  REINICIAR  LA  MESA", 600, 650);
        g.drawString("PARA  CAMBIAR LA POTENCIA", 660, 670);
        g.drawString("+ PELOTAS", 600-490-15, 120);
        g.drawString("- PELOTAS", 600-490-15, 140);
        g.drawString("GOLPEAR", 600-490-15, 160);
        Table.paint(g); 
        start.paint(g, this);
        repaint();
    }

    @Override
    public void keyTyped(KeyEvent e) {
       
    }

    /**
     *Detecta eventos de teclado para reiniciar o terminar el juego y añadir o remover pelotas
     * @param e
     */
    @Override
    public void keyPressed(KeyEvent e) {
        if(e.VK_R == e.getKeyCode()){
            start.restart(this);
        }
        if(e.VK_A == e.getKeyCode()){
            start.addBall(17);
        }
        if(e.VK_M == e.getKeyCode()){
            start.removeBall();
        }
        if(e.VK_SPACE == e.getKeyCode()){
            start.finish = false;
            start.startGame(this);
        }
        if(e.VK_G == e.getKeyCode()){
             if(start.turn == true &&  start.Players.get(0).taco.balls(start.ballSetter)){
                start.turn = false;
            }else{
                start.turn = true;
            }
            for (int i = 0; i < start.ballSetter.size(); i++) {
                if(start.ballSetter.get(i).getType() == 16){
                    start.Players.get(0).taco.golpearBola(start.ballSetter.get(i),this, start.ballSetter);
                    start.Players.get(1).taco.golpearBola(start.ballSetter.get(i),this, start.ballSetter);
                }
            }
        }
        if(e.VK_LEFT == e.getKeyCode()){
            start.Players.get(0).taco.lessPower();
            start.Players.get(1).taco.lessPower();
        }
        if(e.VK_RIGHT == e.getKeyCode()){
            start.Players.get(0).taco.morePower();
            start.Players.get(1).taco.morePower();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
       
    }
}
