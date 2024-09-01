package tarea3;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.util.ArrayList;
import javax.swing.ImageIcon;

class Comprador{
    private DepositoMonedas Cartera;
    private Image Cart;
    private Bebida bebida;
    private int vueltoPendiente;
    private int saldo;
    private String saldoString;
    private Expendedor expCom;
    public Comprador(Expendedor exp){
       Cartera = new DepositoMonedas();
       saldoString = "";
       saldo = 0;
       expCom = exp;
       Cart = new ImageIcon("cartera.png").getImage();
       bebida =  null;
    }
    public void sacarBebida(Bebida soda){
        bebida = soda;
    }
    public void beber(){
        if(bebida != null){
            Bebida aux = bebida;
            bebida = null;
            System.out.println("Bebiendo: "+aux.tipoBebida()+"\nNumero de Serie: "+aux.getSerie()+"\n");
        }
    }
    public void cuantoVuelto(){
        int cont = Cartera.getDMonedas().size();
        for (int i = cont; i > 0; i--){
            System.out.println("100");
        }
    } 
    public void saldo(){
        saldo = 0;
        for(int i=0; i< Cartera.getDMonedas().size(); i++){
            saldo += Cartera.getMoneda(i).getValor();
        }
        saldoString = saldo+"";   
    }
    public void quitarSaldo(){
        expCom.pagoCompra(Cartera);
        while(!Cartera.getDMonedas().isEmpty()){
            Cartera.removeMoneda();
        }
        System.out.println("Has anyadido "+saldo+" pesos al Expendedor.");
        saldo = 0;
    } 
    public void agregarSaldo(Moneda m){
        if(m != null){
            Cartera.addMoneda(m);
            System.out.println("Se ha anyadido una moneda de "+m.getValor()+" pesos a tu cartera.");
        }
    }
    public void paint(Graphics g){
       this.saldo();
       g.setColor(Color.black);
       g.fillRoundRect(15, 515, 130, 20, 30, 30);
       g.setColor(Color.white);
       Font font = new Font("Space Invaders",Font.BOLD,12);
       g.setFont(font);
       g.drawString("Saldo : $"+ saldoString, 20, 529);   
       g.drawImage(Cart, 0, 550, 180, 100, null);
       if(bebida != null){
           bebida.paint(g, 50, 250, 75, 165);
       }
    }
}
