
package proyectoprogra.pkg2;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;

/**
 *Una pelota con la cual interactuar 
 * @author Maximiliano Lopez
 * @author Ivan Zapata
 * @author Vicente Cuello
 * 
 */
class Pelota {
    
    double x, y; 
    double velX, velY;
    final float mass = 2;
    int w = 20, h = 20;
    private final int type;
    private Color color;
    Random randX;
    Random randY; 
    Random randZ;
    int r, gr, b;
    
    /**
     *Constructor de pelota, donde se define su posicion y se define el tipo de pelota que es
     * @param x posicion en x flotante
     * @param y posicion en y flotante
     * @param type tipo de pelota entero
     */
    public Pelota(float x, float y, int type){
        this.x = x;
        this.y = y;
        this.velX = 15;
        this.velY = 15;
        this.type = type;
        randX = new Random();
        randY = new Random();
        randZ = new Random();
        r = randX.nextInt(254);
        gr = randY.nextInt(254);
        b = randZ.nextInt(254);
    }
    
    /**Calcula como se movera la pelota dependiendo de su velocidad */
    public void move(){
        this.x += velX; 
        this.y += velY;
        this.velX *=0.998f;
        this.velY *=0.998f; 
        if(Math.abs(this.velX) < 0.05 && Math.abs(this.velY) < 0.05 ){
            velX = 0;
            velY = 0;
        }
    }
    
    /**
     *Se determina y se calcula como seria la tryectoria de las pelotas cuando colisionan
     * @param G array de segmentos limites de la mesa
     * @param n entero que representa una zona de la mesa
     */
    public void checkCollision(ArrayList<Segmento> G, int n){
        if(n == 1){
            for (int i = 0; i < 10; i++) {
                
                double dx = this.x+10 - G.get(i).cx;
                double dy = this.y+10 - G.get(i).cy;
                
                double cosine = Math.cos(G.get(i).angle);
                double sine = Math.sin(G.get(i).angle);
                
                
                double dx_ = cosine * dx + sine * dy;
                double dy_ = cosine * dy - sine * dx;
                double velX_ = cosine * this.velX + sine * this.velY;
                double velY_ = -sine * this.velX + cosine * this.velY ;
                
                if (dy_ > -10 && this.x+10 >= G.get(i).x1 && this.x+10 < G.get(i).x2){
                    dy_ = -10;
                    velY_ = -0.8*velY_;  
                }
                
                dx = cosine * dx_ - sine * dy_;
                dy = cosine * dy_ + sine * dx_;
                
                this.velX = cosine * velX_ - sine * velY_;
                this.velY = cosine * velY_ + sine * velX_;
                this.x = G.get(i).cx + dx - 10;
                this.y = G.get(i).cy + dy - 10;
                
            }
        }
        
        if(n == 2){
            for (int i = 10; i < 20; i++) {
                
                double dx = this.x+10 - G.get(i).cx;
                double dy = this.y+10 - G.get(i).cy;
                
                double cosine = Math.cos(G.get(i).angle);
                double sine = Math.sin(G.get(i).angle);
                
                double dx_ = cosine * dx + sine * dy;
                double dy_ = cosine * dy - sine * dx;
                double velX_ = cosine * this.velX + sine * this.velY;
                double velY_ = -sine * this.velX + cosine * this.velY ;
                
                if (dy_ < 10 && this.x+10 >= G.get(i).x1 && this.x+10 < G.get(i).x2){
                    dy_ = 10;
                    velY_ = -0.8*velY_;  
                }
                
                dx = cosine * dx_ - sine * dy_;
                dy = cosine * dy_ + sine * dx_;
                
                this.velX = cosine * velX_ - sine * velY_;
                this.velY = cosine * velY_ + sine * velX_;
                this.x = G.get(i).cx + dx - 10;
                this.y = G.get(i).cy + dy - 10;
                
            }
        }
        
        if(n == 3){
            for (int i = 20; i < 25; i++) {
                
                double dx = this.x+10 - G.get(i).cx;
                double dy = this.y+10 - G.get(i).cy;
                
                double cosine = Math.cos(Math.PI - Math.PI/2 -G.get(i).angle);
                double sine = Math.sin(Math.PI - Math.PI/2-G.get(i).angle);
                
                
                double dx_ = cosine * dx + sine * dy;
                double dy_ = cosine * dy - sine * dx;
                double velX_ = cosine * this.velX + sine * this.velY;
                double velY_ = -sine * this.velX + cosine * this.velY ;
                
                if (dx_ < 10 && this.y+10 >= G.get(i).y1 && this.y+10 < G.get(i).y2){
                    dx_ = 10;
                    velX_ = -0.8*velX_;  
                }
                
                dx = cosine * dx_ - sine * dy_;
                dy = cosine * dy_ + sine * dx_;
                
                this.velX = cosine * velX_ - sine * velY_;
                this.velY = cosine * velY_ + sine * velX_;
                this.x = G.get(i).cx + dx - 10;
                this.y = G.get(i).cy + dy - 10;
                
            }
        }
        
        if(n == 4){
            for (int i = 25; i < 30; i++) {     
                
                double dx = this.x+10 - G.get(i).cx;
                double dy = this.y+10 - G.get(i).cy;
                
                double cosine = Math.cos(Math.PI - Math.PI/2 -G.get(i).angle);
                double sine = Math.sin(Math.PI - Math.PI/2-G.get(i).angle);
                
                
                double dx_ = cosine * dx + sine * dy;
                double dy_ = cosine * dy - sine * dx;
                double velX_ = cosine * this.velX + sine * this.velY;
                double velY_ = -sine * this.velX + cosine * this.velY ;
                
                if (dx_ > -10 && this.y+10 >= G.get(i).y1 && this.y+10 < G.get(i).y2){
                    dx_ = -10;
                    velX_ = -0.8*velX_;  
                }
                
                dx = cosine * dx_ - sine * dy_;
                dy = cosine * dy_ + sine * dx_;
                
                this.velX = cosine * velX_ - sine * velY_;
                this.velY = cosine * velY_ + sine * velX_;
                this.x = G.get(i).cx + dx - 10;
                this.y = G.get(i).cy + dy - 10;
                
            }
        }
    }
    
    /**
     *Determina la velocidad de la pelota
     * @param x velocidad en x flotante
     * @param y velocidad en y flotante
     */
    public void setVelocity(float x, float y){
        this.velX = (float)x;
        this.velY = (float)y;
    }
    
    /**
     *Retorna el tipo de pelota
     * @return
     */
    public int getType(){
        return this.type;
    }
    
    /**
     *Se le asigna un diseño a la pelota dependiendo de su numero 
     * @param g
     */
    public void paint(Graphics g){
        Font font = new Font("Space Invaders",Font.BOLD, 8*w/25);
        int x = (int) this.x;
        int y = (int) this.y;
        g.setFont(font);
        switch (type){
            case 1:
                this.color = new Color(255, 215, 0);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 2:
                this.color = new Color(0,0, 139);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 3:
                this.color = new Color(255, 0, 0);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 4:
                this.color = new Color(75, 0, 130);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 5:
                this.color = new Color(255, 69, 0);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 6:
                this.color = new Color(0, 100, 0);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 7:
                this.color = new Color(139, 0, 0);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 8:
                this.color = new Color(0, 0, 0);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 9:
                this.color = new Color(255, 215, 0);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+8, Math.round(y)+12);
                break;
            case 10:
                this.color = new Color(0,0, 139);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+7, Math.round(y)+12);
                break;
            case 11:
                this.color = new Color(255, 0, 0);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+7, Math.round(y)+12);
                break;
            case 12:
                this.color = new Color(75, 0, 130);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+7, Math.round(y)+12);
                break;
            case 13:
                this.color = new Color(255, 69, 0);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+7, Math.round(y)+12);
                break;
            case 14:
                this.color = new Color(0, 100, 0);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+7, Math.round(y)+12);               
                break;
            case 15:
                this.color = new Color(139, 0, 0);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                g.setColor(this.color);
                g.fillRoundRect(Math.round(x), Math.round(y)+4, w, h-8, 8, 8);
                g.setColor(Color.WHITE);
                g.fillArc(Math.round(x)+4, Math.round(y)+4, w-8, h-8, 0, 360);
                g.setColor(Color.BLACK);
                g.drawString(this.type+"", Math.round(x)+7, Math.round(y)+12);
                break;
            case 16:
                this.color = new Color(255, 255, 255);
                g.setColor(this.color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                break;
            case 17:
                this.color = new Color(r, gr, b);
                g.setColor(color);
                g.fillArc(Math.round(x), Math.round(y), w, h, 0, 360);
                break;
        }
    }
}