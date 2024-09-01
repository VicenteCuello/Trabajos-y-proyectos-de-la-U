
package proyectoprogra.pkg2;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.ArrayList;
import javax.swing.JPanel;

/**
 *
 * @author Maximiliano Lopez
 * @author Ivan Zapata
 * @author Vicente Cuello
 * 
 */
class Player {
    
    public Taco taco;
    
    private int Score;
    private final ArrayList<Pelota> Puntos;
    
    /**
     *Constructor de jugador, donde se inicializan los objetos con los que interactua principalmente y
     *se determina su puntaje inicial
     * @param state
     */
    public Player(){
        taco = new Taco();
        Puntos = new ArrayList<>();
        Score = 0;
    }
    
    /**
     *Añade o quita puntaje al jugador
     * @param A pelota que equivale a cierta cantidad de puntaje
     */
    public void addPoint(Pelota A){
        if(A.getType() == 16){
            Score--;
            return;
        }
        else{
            if(A.getType() == 8){
                Score +=2;
            }else{
                Score++;
                Puntos.add(A);
            }
        }
    }
    
    /**
     *Añade las pelotas que el jugador logra meter en los agujeros
     * @param p
     */
    public void addPelota(Pelota p){
        if(p.getType() == 16){
            return;
        }
        Puntos.add(p);
    }
    
    /**
     *Reinicia las pelotas que el jugador a metido y reinicia su putnaje a cero
     */
    public void restart(){
        Puntos.removeAll(Puntos);
        Score = 0;
    }
    
    /**
     *Dibuja el nombre de cada jugador, su numero y color asociados
     * @param g
     * @param x entero, posicion de los elementos en x
     * @param y entero, posicion de los elementos en y
     * @param numjugador entero, numero asociado a jugador
     * @param p Pelotas metidas por el jugador en los agujeros
     * @param Frame Panel en el que se dibujaran los elementos
     */
    public void Paint(Graphics g, int x, int y, int numjugador, ArrayList<Pelota> p, JPanel Frame, boolean turn){
        
        g.setColor(Color.BLACK);
        g.fillRect(x, y, 150, 150);
        g.setColor(Color.WHITE);
        g.drawRect(x, y, 150, 150);
        
        Font font = new Font("Space Invaders",Font.BOLD,12);
        Font font2 = new Font("Space Invaders",Font.BOLD,18);
        String score, player;
        switch (numjugador) {
            case 1:
                player = String.valueOf(numjugador);
                g.setColor(Color.red);
                
                g.setFont(font2);
                g.drawString("PLAYER " +player, x+5, y+50);
                
                g.setFont(font);
                score = String.valueOf(Score);
                g.drawString("PUNTAJE: "+score, x+5, y+100);
                taco.updatePosition(Frame);
                if(turn == true){
                    taco.paint(g, Color.red, p, Frame);
                }
                break;
             
            case 2:
                player = String.valueOf(numjugador);
                g.setColor(Color.blue);
                
                g.setFont(font2);
                g.drawString("PLAYER " +player, x+5, y+50);
                
                g.setFont(font);
                score = String.valueOf(Score);
                g.drawString("PUNTAJE: "+score, x+5, y+100);
                taco.updatePosition(Frame); 
                if(turn == false){
                    taco.paint(g, Color.blue, p, Frame);
                }
                break;
        }
    }
}
