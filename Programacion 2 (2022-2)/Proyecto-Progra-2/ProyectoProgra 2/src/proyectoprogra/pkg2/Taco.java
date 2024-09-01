
package proyectoprogra.pkg2;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.MouseInfo;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import javax.swing.JPanel;

/**
 *
 * @author Maximiliano Lopez
 * @author Ivan Zapata
 * @author Vicente Cuello
 * 
 */
final class Taco extends MouseAdapter{
    private final int ball = 16;
    private double MousePositionX, MousePositionY;
    private double BallPositionX, BallPositionY;
    int power;
    MouseListener ma;
    
    /**
     *Constructor de Taco, donde se define el estado del turno de los jugadores
     */
    public Taco(){
        power = 1;
    }
    
    public void morePower(){
        if(power == 9){
        }else{
            power += 4;
        }
    }
    
    public void lessPower(){
        if(power == 1){
        }else{
            power -= 4;
        }
    }
    
    /**
     *Se actualiza la posicion del taco dependiendo de la posicion del cursor 
     * @param Frame
     */
    public void updatePosition(JPanel Frame){
        JPanel XY = Frame;
        MousePositionX = MouseInfo.getPointerInfo().getLocation().x - XY.getLocationOnScreen().x;
        MousePositionY = MouseInfo.getPointerInfo().getLocation().y - XY.getLocationOnScreen().y;
    }
    
    /**
     *Se calcula la posiocion en pantalla de el taco respecto una pelota
     * @param x double posicion en x
     * @param y double posicion en y
     * @param vx double velocidad de la pelota en x
     * @param vy double velocidad de la pelota en y
     */
    public void BallPosition(double x, double y, double vx, double vy){
        BallPositionX = x+10;
        BallPositionY = y+10;
        double distX = MousePositionX - BallPositionX;
        double distY = MousePositionY - BallPositionY;
        double angle = Math.atan2(distY, distX);
        if(Math.sqrt(distX*distX+distY*distY) < Math.sqrt((BallPositionX-(BallPositionX + 20*Math.cos(angle)))*(BallPositionX-(BallPositionX + 20*Math.cos(angle)))+(BallPositionY-(BallPositionY + 20*Math.sin(angle)))*(BallPositionY-(BallPositionY + 20*Math.sin(angle))))){
            double deltaX = MousePositionX -BallPositionX - 20*Math.cos(angle);
            double deltaY = MousePositionY -BallPositionY - 20*Math.sin(angle);
            MousePositionX =BallPositionX + Math.sqrt(deltaX*deltaX+deltaY*deltaY)*Math.cos(angle)+Math.cos(angle);
            MousePositionY =BallPositionY + Math.sqrt(deltaX*deltaX+deltaY*deltaY)*Math.sin(angle)+Math.sin(angle);
        }else{
            BallPositionX =(float) (BallPositionX + 20*Math.cos(angle));
            BallPositionY =(float) (BallPositionY + 20*Math.sin(angle));
        }
    }
    
    /**
     * Cuando todas las pelotas estan quietas, si el taco golpea a la pelota, se cambia la velocidad y direccion de la misma
     * @param bola peltota que el taco golpea
     * @param Frame
     * @param p
     */
    public void golpearBola(Pelota bola, JPanel Frame, ArrayList<Pelota> p){
        if(balls(p) == true){
            double distX = MousePositionX - BallPositionX;
            double distY = MousePositionY - BallPositionY;
            double angle = Math.atan2(distY, distX);
            bola.setVelocity((float)((-1)*(power*Math.cos(angle))), (float)((-1)*(power*Math.sin(angle))));
        }
    }
    
    /**
     *Detecta si las peltoas estan quietas o en movimiento
     * @param setter
     * @return
     */
    public Boolean balls(ArrayList<Pelota> setter){
        Boolean lector = true;
        for (int i = 0; i < setter.size(); i++) {
            if(setter.get(i).velX != 0 && setter.get(i).velY != 0){
                lector = false;
            }
        }
        return lector;
    }
    
    /**
     *Dibuja la linea que representa el taco, cambiando de color segun el turno del jugador
     * @param g
     * @param c color que adquiere el taco segun que turno sea
     * @param A array de pelotas
     * @param Frame
     */
    public void paint(Graphics g, Color c, ArrayList<Pelota> A, JPanel Frame){
        g.setColor(c);
        this.balls(A);
        double distX = MousePositionX - BallPositionX;
        double distY = MousePositionY - BallPositionY;
        double angle = Math.atan2(distY, distX);
        int x1 = (int)(BallPositionX + 350*Math.cos(angle));
        int y1 = (int)(BallPositionY + 350*Math.sin(angle));
        int x2 = (int)Math.round(BallPositionX);
        int y2 = (int)Math.round(BallPositionY);
        this.updatePosition(Frame);
        if(this.balls(A) == true){
            g.drawLine(x1, y1, x2, y2);
        }
        Font font = new Font("Space Invaders",Font.BOLD, 15);
        g.setFont(font);
        g.setColor(Color.BLACK);
        g.fillRect(515, 30, 230, 30);
        g.setColor(Color.WHITE);
        g.drawRect(515, 30, 230, 30);
        g.setColor(c);
        g.drawString("POTENCIA: ", 535, 50);
        if(power == 1){
            g.setColor(Color.GREEN);
            g.fillRect(635, 35, 30, 15);
        }
        if(power == 5){
            g.setColor(Color.GREEN);
            g.fillRect(635, 35, 30, 15);
            g.setColor(Color.YELLOW);
            g.fillRect(635+30, 35, 30, 15);
        }
        if(power == 9){
            g.setColor(Color.GREEN);
            g.fillRect(635, 35, 30, 15);
            g.setColor(Color.YELLOW);
            g.fillRect(635+30, 35, 30, 15);
            g.setColor(Color.RED);
            g.fillRect(635+30+30, 35, 30, 15);
        }
            
    }
}

