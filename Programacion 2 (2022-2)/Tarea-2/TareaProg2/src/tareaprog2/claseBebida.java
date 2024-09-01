package tareaprog2;

abstract class Bebida{
   public abstract String tipoBebida();
   private int serie;
   public Bebida (int numSerie){
       serie = numSerie;
   }
    public int getSerie() {
        return serie;
    }
}

class CocaCola extends Bebida{
    public CocaCola(int numSerie){
        super(numSerie);
    }
    @Override
    public String tipoBebida(){
        return "Coca-Cola";
    }
}
class Sprite extends Bebida{
    public Sprite(int numSerie){
        super(numSerie);
    }
    @Override
    public String tipoBebida(){
        return "Sprite";
    }
}
class Fanta extends Bebida{
    public Fanta(int numSerie){
        super(numSerie);
    }
    @Override
    public String tipoBebida(){
        return "Fanta";
    }
}
