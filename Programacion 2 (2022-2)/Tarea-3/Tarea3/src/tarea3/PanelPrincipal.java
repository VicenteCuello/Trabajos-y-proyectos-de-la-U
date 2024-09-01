package tarea3;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class PanelPrincipal extends JPanel {
    private Expendedor exp;
    private Comprador com;;
    private JButton m100;
    private JButton m500;
    private JButton m1000;
    private JButton receptorMonedas;
    private JButton fantaBoton;
    private JButton spriteBoton;
    private JButton cocaBoton;
    private JButton sacarBebida;
    private JButton sacarVuelto;
    private JLabel rellenarBebidas;
    private JButton tomarBebida;
    public PanelPrincipal(){
        this.setBackground(Color.darkGray);
        this.setLayout(null);
        exp = new Expendedor(3, 100);
        com = new Comprador(exp);
        Botones();
        clickSaldo();
        elegirBebida();
   
    }
    public void Botones(){
        m500 = new JButton();
        m500.setBounds(685, 200, 50, 50);
        ImageIcon m500i = new ImageIcon("moneda500.png");
        m500.setIcon(new ImageIcon(m500i.getImage().getScaledInstance(m500.getWidth(), m500.getHeight(), Image.SCALE_SMOOTH)));
        this.add(m500);
        
        m100 = new JButton();
        m100.setBounds(685, 140, 50, 50);
        ImageIcon m100i = new ImageIcon("moneda100.png");
        m100.setIcon(new ImageIcon(m100i.getImage().getScaledInstance(m100.getWidth(), m100.getHeight(), Image.SCALE_SMOOTH)));
        this.add(m100);
        
        m1000 = new JButton();
        m1000.setBounds(685, 260, 50, 50);
        ImageIcon m1000i = new ImageIcon("moneda1000.png");
        m1000.setIcon(new ImageIcon(m1000i.getImage().getScaledInstance(m1000.getWidth(), m1000.getHeight(), Image.SCALE_SMOOTH)));
        this.add(m1000);
        
        fantaBoton = new JButton();
        fantaBoton.setBounds(547, 360, 80, 30);
        ImageIcon fantaImage = new ImageIcon("fanta-etiqueta.png");
        fantaBoton.setIcon(new ImageIcon(fantaImage.getImage().getScaledInstance(fantaBoton.getWidth(), fantaBoton.getHeight(), Image.SCALE_SMOOTH)));
        this.add(fantaBoton);
          
        cocaBoton = new JButton();
        cocaBoton.setBounds(547, 395, 80, 30);
        ImageIcon cocaImage = new ImageIcon("coca-etiqueta.jpg");
        cocaBoton.setIcon(new ImageIcon(cocaImage.getImage().getScaledInstance(cocaBoton.getWidth(), cocaBoton.getHeight(), Image.SCALE_SMOOTH)));
        this.add(cocaBoton);
        
        spriteBoton = new JButton();
        spriteBoton.setBounds(547, 430, 80, 30);
        ImageIcon spriteImage = new ImageIcon("sprite-etiqueta.png");
        spriteBoton.setIcon(new ImageIcon(spriteImage.getImage().getScaledInstance(spriteBoton.getWidth(), spriteBoton.getHeight(), Image.SCALE_SMOOTH)));
        this.add(spriteBoton);
        
        receptorMonedas = new JButton();
        receptorMonedas.setBounds(560, 280, 54, 48);
        this.add(receptorMonedas);
        receptorMonedas.setOpaque(false);
        receptorMonedas.setContentAreaFilled(false);
        receptorMonedas.setBorderPainted(false);
        
        sacarBebida = new JButton();
        sacarBebida.setBounds(230, 500, 25, 55);
        this.add(sacarBebida);
        sacarBebida.setOpaque(false);
        sacarBebida.setContentAreaFilled(false);
        sacarBebida.setBorderPainted(false);
        
        sacarVuelto = new JButton();
        sacarVuelto.setBounds(280, 490, 50, 50);
        this.add(sacarVuelto);
        sacarVuelto.setOpaque(false);
        sacarVuelto.setContentAreaFilled(false);
        sacarVuelto.setBorderPainted(false);
        
        tomarBebida = new JButton();
        tomarBebida.setBounds(50, 250, 75, 165);
        this.add(tomarBebida);
        tomarBebida.setOpaque(false);
        tomarBebida.setContentAreaFilled(false);
        tomarBebida.setBorderPainted(false);
        
        
        rellenarBebidas = new JLabel();
        rellenarBebidas.setBounds(200, 100, 450, 550);
        this.add(rellenarBebidas);
    
    }
   public void clickSaldo(){
       MouseAdapter ma1 = new MouseAdapter() {
           @Override
           public void mouseClicked(MouseEvent e) {
                com.agregarSaldo(new Moneda100());
                repaint();
            }
       };m100.addMouseListener(ma1);
       
       MouseAdapter ma2 = new MouseAdapter() {
           @Override
           public void mouseClicked(MouseEvent e) {
                com.agregarSaldo(new Moneda500());
                repaint();
            }
       };m500.addMouseListener(ma2);
       
       MouseAdapter ma3 = new MouseAdapter() {
           @Override
           public void mouseClicked(MouseEvent e) {
                com.agregarSaldo(new Moneda1000());
                repaint();
            }
       };m1000.addMouseListener(ma3);
       
       MouseAdapter ma4 = new MouseAdapter() {
           @Override
           public void mouseClicked(MouseEvent e){
               com.quitarSaldo();
               repaint();
           }
       };receptorMonedas.addMouseListener(ma4);
   }
   public void elegirBebida(){
       MouseAdapter ma1 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e) {
                exp.comprarBebida(1);
                repaint();
            }
       };fantaBoton.addMouseListener(ma1);
       MouseAdapter ma2 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e) {
                exp.comprarBebida(2);
                repaint();
            }
       };cocaBoton.addMouseListener(ma2);
       MouseAdapter ma3 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e) {
                exp.comprarBebida(3);
                repaint();
            }
       };spriteBoton.addMouseListener(ma3);
       MouseAdapter ma4 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e) {
                com.sacarBebida(exp.getaBebida());
                repaint();
            }
       };sacarBebida.addMouseListener(ma4);
       
       MouseAdapter ma5 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e){
                com.agregarSaldo(exp.retornarVuelto());
                repaint();
            }
       };sacarVuelto.addMouseListener(ma5);   
       MouseAdapter ma6 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e){
               exp.depositoVacio();
               repaint();
            }
       };rellenarBebidas.addMouseListener(ma6);
       
        MouseAdapter ma7 = new MouseAdapter() {
          @Override
           public void mouseClicked(MouseEvent e){
               com.beber();
               repaint();
            }
       };tomarBebida.addMouseListener(ma7);
   }  
    @Override
    public void paint(Graphics g){
        super.paint(g);
        exp.paint(g);
        com.paint(g);
    }        
}