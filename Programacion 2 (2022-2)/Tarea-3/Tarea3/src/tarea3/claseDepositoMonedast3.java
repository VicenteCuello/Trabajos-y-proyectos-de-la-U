
package tarea3;
import java.awt.Graphics;
import java.util.ArrayList;

class DepositoMonedas {
    private ArrayList<Moneda> M;
    public DepositoMonedas(){
        M = new ArrayList<>();
    }
    public void addMoneda(Moneda m){
        M.add(m);
    }
    public Moneda removeMoneda(){
        return M.remove(0);
    }
    public ArrayList getDMonedas(){
        return M;
    }
    public Moneda getMoneda(int n){
        return M.get(n);
    }
    public void paint(Graphics g, int x, int y, int n){
        M.get(n).paint(g, x, y);
    }
}
