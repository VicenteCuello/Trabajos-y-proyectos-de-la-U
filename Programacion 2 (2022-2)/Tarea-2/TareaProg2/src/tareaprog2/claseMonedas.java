
package tareaprog2;

class Moneda{
    private final int valor;
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

class Moneda100 extends Moneda{
    public Moneda100(){
        super(100);
    }
}

class Moneda500 extends Moneda{
    public Moneda500(){
        super(500);
    }
}

class Moneda1000 extends Moneda{
    public Moneda1000(){
        super(1000);
    }
}

