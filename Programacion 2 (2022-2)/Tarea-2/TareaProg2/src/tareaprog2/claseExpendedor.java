
package tareaprog2;
import java.util.ArrayList;

class Expendedor {
    private ArrayList<Deposito> D;
    private int precio;
    private int vueltoTotal;
    public Expendedor(int numBebidas, int precioUnico){
        precio = precioUnico;
        vueltoTotal = 0;
        D = new ArrayList<>(3);
        D.add(new Deposito());
        D.add(new Deposito());
        D.add(new Deposito());
        for(int i = 0; i < numBebidas; i++){
            D.get(0).addBebida(new Fanta(1000+i));
            D.get(1).addBebida(new Sprite(2000+i));
            D.get(2).addBebida(new CocaCola(3000+i));
        }
    }
    public Bebida comprarBebida(Moneda m, int numero) throws customException{
        if (m == null){
            throw new customException("PagoIncorrectoException");
        }
        if(numero == 1){
            return D.get(0).getBebida(m, precio);
        }
        if(numero == 2){
            return D.get(1).getBebida(m, precio);
        }
        if(numero == 3){
            return D.get(2).getBebida(m, precio);
        }
        throw new customException("NoHayBebidaException");
    }
    public int valorVuelto(int n){
        if(n == 1){
            vueltoTotal = D.get(0).darVuelto();
        }
        if(n == 2){
            vueltoTotal = D.get(1).darVuelto();
        }
        if(n == 3){
            vueltoTotal = D.get(2).darVuelto();
        }
        return vueltoTotal;
    }
    public Moneda getVuelto(){
        if(vueltoTotal > 0){
            vueltoTotal -= 100;
            return new Moneda100();
        }
        return null;
    }
}
