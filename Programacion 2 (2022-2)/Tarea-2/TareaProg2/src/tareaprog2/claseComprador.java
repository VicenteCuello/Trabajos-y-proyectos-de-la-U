package tareaprog2;

class Comprador{
    private DepositoMonedas Cartera;
    private Bebida bebida;
    private int vueltoPendiente;
    public Comprador(Moneda coin, int cualBebida, Expendedor maquina) throws customException{
        Cartera = new DepositoMonedas();
        Cartera.addMoneda(coin);
        bebida = maquina.comprarBebida(Cartera.removeMoneda(), cualBebida);
        vueltoPendiente = maquina.valorVuelto(cualBebida);
        for(int i = vueltoPendiente; i > 0; i-=100){
            Cartera.addMoneda(maquina.getVuelto());
        }
        vueltoPendiente = 0;
    }
    public String beber(){
        Bebida aux = bebida;
        bebida = null;
        return "Bebiendo: "+aux.tipoBebida()+"\nNumero de Serie: "+aux.getSerie()+"\n";
    }
    public void cuantoVuelto(){
        int cont = Cartera.getDMonedas().size();
        for (int i = cont; i > 0; i--){
            System.out.println("100");
        }
    }
}
