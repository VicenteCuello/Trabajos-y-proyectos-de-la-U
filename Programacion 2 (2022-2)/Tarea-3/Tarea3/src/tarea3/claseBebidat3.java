package tarea3;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.ImageObserver;
import javax.swing.ImageIcon;

abstract class Bebida{
   public abstract String tipoBebida();
   public abstract void paint(Graphics g, int x, int y, int w, int h);
   private int serie;
   public Bebida (int numSerie){
       serie = numSerie;
   }
    public String getSerie() {
        return serie+"";
    }   
}
class CocaCola extends Bebida{
    private Image coca;
    public CocaCola(int numSerie){
        super(numSerie);
        coca = new ImageIcon("coke.png").getImage();
    }
    @Override
    public void paint(Graphics g, int x, int y, int w, int h) {
        g.drawImage(coca, x, y, w, h, null);
        g.setColor(Color.red);
        g.fill3DRect(x, y+23*h/55, 25*w/25, 10*h/55, true);
        g.setColor(Color.BLACK);
        g.draw3DRect(x, y+23*h/55, 25*w/25, 10*h/55, true);
        Font font = new Font("Space Invaders",Font.BOLD, 8*w/25);
        g.setFont(font);
        g.setColor(Color.WHITE);
        g.drawString(this.getSerie(), x+5*w/25, y+32*h/55);
    }
    @Override
    public String tipoBebida(){
        return "Coca-Cola";
    }
}

class Sprite extends Bebida{
    private Image esprait;
    public Sprite(int numSerie){
        super(numSerie);
        esprait = new ImageIcon("sprite.png").getImage();
    }
    @Override
    public void paint(Graphics g, int x, int y, int w, int h) {
        g.drawImage(esprait, x, y, w, h, null);
        g.setColor(Color.green);
        g.fill3DRect(x, y+23*h/55, 25*w/25, 10*h/55, true);
        g.setColor(Color.BLACK);
        g.draw3DRect(x, y+23*h/55, 25*w/25, 10*h/55, true);
        Font font = new Font("Space Invaders",Font.BOLD, 8*w/25);
        g.setFont(font);
        g.setColor(Color.BLUE);
        g.drawString(this.getSerie(), x+5*w/25, y+32*h/55);
    }
    @Override
    public String tipoBebida(){
        return "Sprite";
    }
}
class Fanta extends Bebida{
    private Image phanta;
    public Fanta(int numSerie){
        super(numSerie);
        phanta = new ImageIcon("fanta.png").getImage();
    }
    @Override
     public void paint(Graphics g, int x, int y, int w, int h) {
        g.drawImage(phanta, x, y, w, h, null); 
        g.setColor(Color.orange);
        g.fill3DRect(x, y+23*h/55, 25*w/25, 10*h/55, true);
        g.setColor(Color.BLACK);
        g.draw3DRect(x, y+23*h/55, 25*w/25, 10*h/55, true);
        Font font = new Font("Space Invaders",Font.BOLD, 8*w/25);
        g.setFont(font);
        g.drawString(this.getSerie(), x+5*w/25, y+32*h/55);
    }
    @Override
    public String tipoBebida(){
        return "Fanta";
    }
}