
package tarea3;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.ImageObserver;
import javax.swing.ImageIcon;
import javax.swing.JButton;

abstract class Moneda{
    private final int valor;
    public abstract void paint(Graphics g,int x, int y);
    public Moneda(int n){
        valor = n;
    }
    public int getValor(){
        return valor;
    }
    public String toStringMoneda(){
        return "Valor: "+valor+"\nSerie:"+this.toString()+"\n";
    }
}
class Moneda500 extends Moneda{
    private Image coin;
    public Moneda500(){
        super(500);
        coin = new ImageIcon("moneda5002.png").getImage();
    }
    
    @Override
    public void paint(Graphics g, int x , int y) {
        g.drawImage(coin, x, y, 8, 21, null);
    }
}

class Moneda1000 extends Moneda{
    private Image coin;
    public Moneda1000(){
        super(1000);
        coin = new ImageIcon("moneda10002.png").getImage();
    }
    @Override
    public void paint(Graphics g, int x , int y) {
        g.drawImage(coin, x, y, 8, 21, null);
    }
}
class Moneda100 extends Moneda{
    private Image coin;
    private Image coin2;
    public Moneda100(){
        super(100);
        coin = new ImageIcon("moneda1002.png").getImage();
        coin2 = new ImageIcon("moneda100_1.png").getImage();
    }
    public void paint2(Graphics g, int x , int y) {
        g.drawImage(coin2, x, y, 30, 30, null);
    }
    @Override
    public void paint(Graphics g, int x , int y){
        g.drawImage(coin, x, y, 8, 21, null);
    }
}

