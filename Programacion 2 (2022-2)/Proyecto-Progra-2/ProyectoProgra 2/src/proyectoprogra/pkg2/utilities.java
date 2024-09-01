package proyectoprogra.pkg2;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.JPanel;

/**
 *
 * @author Maximiliano Lopez
 * @author Ivan Zapata
 * @author Vicente Cuello
 * 
 */
class hole{
    int x, y, w=20, h=20;
    public hole(int x, int y){
        this.x = x;
        this.y = y;
    }

    /**
     *Detecta cuando entra una pelota en un agujero
     * @param p
     * @return
     */
    public boolean enterBall(Pelota p){
        boolean detector = false;
        double x1 = x + w/2;
        double y1 = y + h/2;
        double x2 = p.x+p.w/2;
        double y2 = p.y+p.h/2;
        double dx = x1-x2;
        double dy = y1-y2;
        if(Math.sqrt(dx*dx+dy*dy) < 20){
            detector = true;
        }
        return detector;
    }
}

/**
 *Inicia todos los objetos que aparecen en pantalla
 * @author maxil
 */
class startConfig {
    
    ArrayList<Pelota> ballSetter;
    MesaPool Table;
    ArrayList<Player> Players;  
    ArrayList<hole> Agujeros;
    boolean finish;
    boolean turn;

    /**
     *Se inicializa todos los objetos que apareceran en interfaz
     */
    public startConfig(){
        Agujeros = new ArrayList();
        Agujeros.add(new hole(199+6,108+6));
        Agujeros.add(new hole(199+430,108+5));
        Agujeros.add(new hole(199+856,108+6));
        Agujeros.add(new hole(199+430,108+477));
        Agujeros.add(new hole(199+6,108+477));
        Agujeros.add(new hole(199+856,108+477));
        ballSetter = new ArrayList<>();
        Table = new MesaPool();
        Players = new ArrayList<>();
        Players.add(new Player());
        Players.add(new Player());
        finish = false;
        turn = true;
    }
    /**
     *Añade pelotas
     * @param n
     * 
     */
    public void addBall(int n){
        boolean colDetector;
        Pelota aux;
        do{
            colDetector = false;
            Random randX = new Random();
            Random randY = new Random();
            int x = 251 + randX.nextInt(600);
            int y = 164 + randY.nextInt(300);
            aux = new Pelota(x,y, n);
            for(int j = 0; j < ballSetter.size(); j++){
                if(bCollision(aux, ballSetter.get(j)) == true){
                    ballSetter.get(j).setVelocity(0,0);
                    colDetector = true;
                }
            }
        }while(colDetector == true);
        aux.setVelocity(0, 0);
        ballSetter.add(aux);
    }
    /**
     *Remueve las pelotas 
     */
    public void removeBall(){
        for (int i = 0; i < ballSetter.size(); i++) {
            if(ballSetter.get(i).getType() == 17){
                ballSetter.remove(i);
                return;
            }
        }
    }

    /**
     *Comprueba si una pelota entro a un agujero
     * @param p
     * @return true si la pelota entro, false si no entro
     */
    public boolean enterCheck(Pelota p){
        for (int i = 0; i < Agujeros.size(); i++) {
            if(Agujeros.get(i).enterBall(p) == true){
                return true;
            }
        }
        return false;
    }

    /**
     *Inicializa las pelotas para jugar y detecta los golpes a la pelota
     * @param Frame
     */
    public void startGame(PanelPrincipalProyecto Frame){
        ballSetter = new ArrayList<>();
        boolean colDetector;
        Pelota aux;
        for(int i = 0; i < 16; i++){
            do{
                colDetector = false;
                Random randX = new Random();
                Random randY = new Random();
                int x = 251 + randX.nextInt(740);
                int y = 164 + randY.nextInt(360);
                aux = new Pelota(x,y,i+1);
                for(int j = 0; j < ballSetter.size(); j++){
                    if(bCollision(aux, ballSetter.get(j)) == true && aux.getType()!= ballSetter.get(j).getType()){
                        colDetector = true;
                        ballSetter.get(j).setVelocity(0, 0);
                    }
                }
            }while(colDetector == true);
            ballSetter.add(aux);
            ballSetter.get(i).setVelocity(0, 0);
        }
    }

    /**
     *Reinicia el juego, se cambia el puntaje de ambos jugadores a cero y se disponen las pelotas en la mesa nuevamente
     * @param Frame
     */
    public void restart(PanelPrincipalProyecto Frame){
        for(int i=0; i<2; i++){
            Players.get(i).restart();
        }
        this.ballSetter.removeAll(this.ballSetter);
        this.startGame(Frame);
    }

    /**
     *Se comprueba y calcula como interactuan las peltoas entre si cuando colisionan
     * @param A primera pelota a comprobar
     * @param B segunda pelota a comprobar
     * @return
     */
    public boolean bCollision(Pelota A, Pelota B){
        double dx = B.x- A.x;
        double dy = B.y - A.y;
        double dist = Math.sqrt(dx*dx + dy*dy);
        if(dist < 20){
            
            double angle = Math.atan2(dy, dx);
            double sin = Math.sin(angle);
            double cos = Math.cos(angle);
            
            double x1 = 0, y1  = 0;
            double x2 = dx*cos+dy*sin;
            double y2 = dy*cos-dx*sin;
            
            double vx1 = A.velX*cos+A.velY*sin;
            double vy1 = A.velY*cos-A.velX*sin;
            double vx2 = B.velX*cos+B.velY*sin;
            double vy2 = B.velY*cos-B.velX*sin;
            
            double vx1final = ((A.mass-B.mass)*vx1+2*B.mass*vx2)/(A.mass+B.mass);
            double vx2final = ((B.mass-A.mass)*vx2+2*A.mass*vx1)/(A.mass+B.mass);
            
            vx1 = vx1final;
            vx2 = vx2final;
            
            double absV = Math.abs(vx1)+Math.abs(vx2);
            double overlap = (20)-Math.abs(x1-x2);
            x1 += vx1/absV*overlap;
            x2 += vx2/absV*overlap;
            
            double x1final = x1*cos-y1*sin;
            double y1final = y1*cos+x1*sin;
            double x2final = x2*cos-y2*sin;
            double y2final = y2*cos+x2*sin;
            
            B.x = A.x + x2final;
            B.y = A.y + y2final;
    
            A.x = A.x + x1final;
            A.y = A.y + y1final;
            
            A.velX = vx1*cos-vy1*sin;
            A.velY = vy1*cos+vx1*sin;
            B.velX = vx2*cos-vy2*sin;
            B.velY = vy2*cos+vx2*sin;
            return true;
        }
        return false;
    }
    
    /**
     *Dibuja las colisiones de los objetos y administra los eventos del juego
     * @param g
     * @param Frame
     */
    public void paint(Graphics g, JPanel Frame){
        if(finish == false){
        for(int i = 0; i < ballSetter.size(); i++){
            ballSetter.get(i).checkCollision(Table.Bordes, 1);
            ballSetter.get(i).checkCollision(Table.Bordes, 2);
            ballSetter.get(i).checkCollision(Table.Bordes, 3);
            ballSetter.get(i).checkCollision(Table.Bordes, 4);
            if(ballSetter.get(i).getType()==16){
                Players.get(0).taco.BallPosition(ballSetter.get(i).x, ballSetter.get(i).y, ballSetter.get(i).velX, ballSetter.get(i).velY);
                Players.get(1).taco.BallPosition(ballSetter.get(i).x, ballSetter.get(i).y, ballSetter.get(i).velX, ballSetter.get(i).velY);
            }
            ballSetter.get(i).move();
            ballSetter.get(i).paint(g);
        }
        for (int i = 0; i < ballSetter.size(); i++) {
            if(this.enterCheck(ballSetter.get(i)) == true){
                if(ballSetter.get(i).getType() == 16){
                        this.addBall(16);
                 }
                if(turn == false){
                    Players.get(0).addPoint(ballSetter.get(i));
                    Players.get(0).addPelota(ballSetter.get(i));
                    ballSetter.remove(i);
                }
                if(turn == true){
                    Players.get(1).addPoint(ballSetter.get(i));
                    Players.get(1).addPelota(ballSetter.get(i));
                    ballSetter.remove(i);
                }
            }
        }
        for(int i = 0; i < ballSetter.size()-1; i++){
            for(int j = i+1; j<ballSetter.size(); j++){
                bCollision(ballSetter.get(i), ballSetter.get(j));
            }
        }
        Players.get(0).Paint(g, 1100, 100,1, ballSetter, Frame, turn); 
        Players.get(1).Paint(g, 1100, 300,2, ballSetter, Frame, turn);
        if(ballSetter.size() == 1){
            finish =  true;
        }
    }else{
            Font font = new Font("Space Invaders",Font.BOLD,25);
            g.setFont(font);
            g.setColor(Color.red);
            g.drawString("JUEGO TERMINADO",500,300);
        }
    }

    void paint(Class<Graphics> g, JPanel Frame) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }
}
