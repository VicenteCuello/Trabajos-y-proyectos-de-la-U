
package tarea3;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.ArrayList;
import java.awt.Image;
import javax.swing.ImageIcon;
import javax.swing.JLabel;

class Expendedor {
    private Image Exp;
    private Image Fanta;
    private Image Coca;
    private Image Sprite;
    private ArrayList<Deposito> DBebidas;
    private DepositoMonedas DMonedas;
    private ArrayList<Moneda100> DVuelto;
    private int precio;
    private String price;
    private int vueltoTotal;
    private int Cantidad;
    private Bebida soda;
    public Expendedor(int numBebidas, int precioUnico){
        precio = precioUnico;
        price = String.valueOf(precio);
        Cantidad = numBebidas;
        vueltoTotal = 0;
        Exp = new ImageIcon("expendedor.png").getImage();
        Fanta = new ImageIcon("fanta-etiqueta.png").getImage();
        Sprite = new ImageIcon("sprite-etiqueta.png").getImage();
        Coca = new ImageIcon("coca-etiqueta.jpg").getImage();
        DVuelto = new ArrayList<>();
        DMonedas = new DepositoMonedas();
        DBebidas = new ArrayList<>(3);
        DBebidas.add(new Deposito());
        DBebidas.add(new Deposito());
        DBebidas.add(new Deposito());
        for(int i = 0; i < numBebidas; i++){
            DBebidas.get(0).addBebida(new Fanta(100+i));
            DBebidas.get(2).addBebida(new Sprite(300+i));
            DBebidas.get(1).addBebida(new CocaCola(200+i));
        }
    }
    public void pagoCompra(DepositoMonedas DepMonedas){
        for(int i =0 ; i < DepMonedas.getDMonedas().size(); i++){
            DMonedas.addMoneda(DepMonedas.getMoneda(i));
        }
    }
    
    public Bebida comprarBebida(int numero){
        int dineroExpendedor = 0;
        if(DMonedas.getDMonedas().isEmpty()){
            return null;
        }
        for(int i=0; i< DMonedas.getDMonedas().size(); i++){
            dineroExpendedor += DMonedas.getMoneda(i).getValor();    
        }
        if (dineroExpendedor < precio){
           return null;
        }
        if(numero == 1){
            if(DBebidas.get(0).getArrayBebidas().isEmpty()){
                return null;
            }
            if(soda != null){
                System.out.println("Primero debes retirar la bebida del recibidor antes de comprar otra.");
                return null;
            }
            dineroExpendedor = 0;
            while(dineroExpendedor < precio) {
                dineroExpendedor += DMonedas.removeMoneda().getValor();
            }
            vueltoTotal = dineroExpendedor;
            while(DMonedas.getDMonedas().isEmpty() == false){
                vueltoTotal += DMonedas.removeMoneda().getValor();    
            }
            vueltoTotal -= precio;
            while(vueltoTotal != 0){
                DVuelto.add(new Moneda100());
                vueltoTotal -= 100;
            }
            System.out.println("Has comprado una "+DBebidas.get(0).getBebida(0).tipoBebida()+".");
            return soda = DBebidas.get(0).getBebidas();
        }
        if(numero == 2){
            if(DBebidas.get(1).getArrayBebidas().isEmpty()){
                return null;
            }
            if(soda != null){
                System.out.println("Primero debes retirar la bebida del recibidor antes de comprar otra.");
                return null;
            }
            dineroExpendedor = 0;
            while(dineroExpendedor < precio) {
                dineroExpendedor += DMonedas.removeMoneda().getValor();
            }
            vueltoTotal = dineroExpendedor;
            while(DMonedas.getDMonedas().isEmpty() == false){
                vueltoTotal += DMonedas.removeMoneda().getValor();    
            }
            vueltoTotal -= precio;
            while(vueltoTotal != 0){
                DVuelto.add(new Moneda100());
                vueltoTotal -= 100;
            }
            System.out.println("Has comprado una "+DBebidas.get(1).getBebida(0).tipoBebida()+".");
            return soda = DBebidas.get(1).getBebidas();
        }
        if(numero == 3){
            if(DBebidas.get(2).getArrayBebidas().isEmpty()){
                return null;
            }
            dineroExpendedor = 0;
            if(soda != null){
                System.out.println("Primero debes retirar la bebida del recibidor antes de comprar otra.");
                return null;
            }
            while(dineroExpendedor < precio) {
                dineroExpendedor += DMonedas.removeMoneda().getValor();
            }
            vueltoTotal = dineroExpendedor;
            while(DMonedas.getDMonedas().isEmpty() == false){
                System.out.println("A");
                vueltoTotal += DMonedas.removeMoneda().getValor();    
            }
            vueltoTotal -= precio;
            
            while(vueltoTotal != 0){
                DVuelto.add(new Moneda100());
                vueltoTotal -= 100;
            }
            System.out.println("Has comprado una "+DBebidas.get(2).getBebida(0).tipoBebida()+".");
            return soda = DBebidas.get(2).getBebidas();
        }
        return null;
    }
    
    public Bebida getaBebida(){
        Bebida refresco = soda;
        soda = null;
        return refresco;
    }
    public Moneda retornarVuelto(){
        if(DVuelto.isEmpty()== false){
            return DVuelto.remove(0);
        }
        return null;
    }
    public void depositoVacio(){
        if(DBebidas.get(0).getArrayBebidas().isEmpty()){
        for (int i = 0; i < Cantidad; i++) {
           DBebidas.get(0).addBebida(new Fanta(100+i)); 
            }
        }
        if(DBebidas.get(1).getArrayBebidas().isEmpty()){
        for (int i = 0; i < Cantidad; i++) {
           DBebidas.get(1).addBebida(new CocaCola(200+i)); 
            }
        }
        if(DBebidas.get(2).getArrayBebidas().isEmpty()){
        for (int i = 0; i < Cantidad; i++) {
           DBebidas.get(2).addBebida(new Sprite(300+i)); 
            }
        }
    }
    public void paint(Graphics g){
        g.drawImage(Exp,200, 100, 450, 550, null);       
        g.drawImage(Fanta ,547, 360, 80, 30, null);    
        g.drawImage(Coca,547, 395, 80, 30, null);    
        g.drawImage(Sprite,547, 430, 80, 30, null);    
        g.fillRoundRect(547, 283+50, 80, 20, 20, 20);
        Font font = new Font("Space Invaders",Font.BOLD,12);
        g.setFont(font);
        g.setColor(Color.white);
        g.drawString("$"+price, 555, 297+50);
        for (int i = 1; i < DBebidas.get(0).getArrayBebidas().size()+1; i++) {
            if(i < 10){
                DBebidas.get(0).paint(g, 240+30*(i-1), 282, i-1);   
            }
        }
        for (int i = 1; i < DBebidas.get(1).getArrayBebidas().size()+1; i++) {
            if(i < 10){
                DBebidas.get(1).paint(g, 240+30*(i-1), 351,i-1);
            }
        }
        for (int i = 1; i < DBebidas.get(2).getArrayBebidas().size()+1; i++) {
            if(i < 10){
                DBebidas.get(2).paint(g, 240+30*(i-1), 420,i-1);   
            }
        }
        font = new Font("Space Invaders",Font.BOLD,12);
        g.setFont(font);
        g.setColor(Color.BLACK);
        g.fillRect(479, 273, 40, 25); 
        g.fillRect(479, 273+68, 40, 25); 
        g.fillRect(479, 273+68+68, 40, 25); 
        g.setColor(Color.WHITE);
        g.drawRect(479, 273, 40, 25); 
        g.drawRect(479, 273+68, 40, 25); 
        g.drawRect(479, 273+68+68, 40, 25); 
        g.drawString(DBebidas.get(0).getArrayBebidas().size()+"", 487, 290);
        g.drawString(DBebidas.get(2).getArrayBebidas().size()+"", 487, 290+68+68);
        g.drawString(DBebidas.get(1).getArrayBebidas().size()+"", 487, 290+68);
        for(int i = 1; i < DMonedas.getDMonedas().size()+1; i++){
            if(i <=11){
                DMonedas.paint(g, 543+8*(i-1), 500, i-1);
            }
            if(i>11 && i<=22){
                DMonedas.paint(g, 543+8*(i-12), 525, i-1);
            }
            if(i>22 && i <=33){
                DMonedas.paint(g, 543+8*(i-23), 550, i-1);
            }
        }
        for(int i  = 0; i < DVuelto.size(); i++){
            DVuelto.get(i).paint2(g, 280, 500);
        }
        if(soda != null){
            soda.paint(g, 230, 500, 25, 55);
        }
    }
}
