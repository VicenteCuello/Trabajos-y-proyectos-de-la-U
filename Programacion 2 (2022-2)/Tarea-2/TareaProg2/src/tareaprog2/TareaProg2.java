package tareaprog2;
import java.util.ArrayList;
import java.util.Date;


public class TareaProg2 {
    
    public static void main(String[] args) throws customException {
        Expendedor e1 = new Expendedor(10,1000);
        Expendedor e2 = new Expendedor(0,1000);
        Expendedor e3 = new Expendedor(20,500);
        Expendedor e4 = new Expendedor(20,100);
        Moneda1000 m1 = new Moneda1000();
        Moneda500 m2 = new Moneda500();
        Moneda100 m3 = new Moneda100();
        Comprador c1 = new Comprador(m1,3,e1);   //coca cola   
        Comprador c2 = new Comprador(m1,1,e1);   //fanta
        Comprador c3 = new Comprador(m1,2,e1);   //sprite
        Comprador c4 = new Comprador(m1,2,e1);   //para comprobar el numero de serie
        //Comprador c5 = new Comprador(m1,2,e2);         //excepcion cuando no hay bebidas
        Comprador c6 = new Comprador(m1,2,e3);    //vuelto cuando vale 500 y pagas con 1000
        Comprador c7 = new Comprador(m1,2,e4);    //vuelto cuando vale 100 y pagas con 1000
        Comprador c8 = new Comprador(m2,2,e4);    //vuelto cuando vale 100 y pagas con 500
        //Comprador c9 = new Comprador(m2,2,e1);        //excepcion cuando no te alcanza
        //Comprador c10 = new Comprador(null,2,e4);       //excepcion cuando no pagas
        System.out.print(c8.beber()+"\n");   //cambie el numero al lado da c para cambiar de comprado
        c8.cuantoVuelto();                  //y probar las posibilidades
        System.out.print(c3.beber()+"\n");
    }
}
