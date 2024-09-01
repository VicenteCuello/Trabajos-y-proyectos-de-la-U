
package tareaprog2;
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
}
