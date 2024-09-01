package tarea3;

public class Tarea3 {

    public static void main(String[] args) {
        Ventana v = new Ventana();
    }
    
}

/*
EXPLICACIÓN DE LOS CONTROLES
El saldo del comprador (Representado en la esquina inferior izquierda mediante "Saldo:")
se inicia en 0. Luego, se puede añadir saldo mediante los 3 botones de la esquina superior
derecha, los cuales cumplen la siguiente función:
- Boton "Moneda 100": Añade una moneda de 100 pesos a la cartera del comprador.
- Boton "Moneda 500": Añade una moneda de 500 pesos a la cartera del comprador.
- Boton "Moneda 1000": Añade una moneda de 1000 pesos a la cartera del comprador.
Luego, existe un boton invisible en la zona de ingreso de monedas del expendedor. Al darle
click a ese boton, todo el saldo del comprador pasa al deposito del expendedor (Representado
numérica y visualmente).
Tambien se muestra en pantalla la cantidad de bebidas respectivas restantes de cada deposito.
Para comprar una bebida, una vez ingresado dinero al deposito de expendedor, se clickea uno de los
tres botones (Fanta, Coca-Cola  o Sprite) y la bebida aparecera en la bandeja de entrega, la cual
se podra tomar dandole click encima. Tambien aparecera una moneda de 100 pesos representando el saldo
(Si es que fuera necesario). Se le dara click a ese boton para recibir el saldo en monedas de 100 pesos,
y desaparecera cuando se reciba el vuelto restante total. La bebida que posee el comprador tambien aparecera
en pantalla en la zona izquierda, y al darle click el comprador podra beberla.
Si el deposito de cualquiera de ellas esta vacio, basta con clickear sobre el expendedor y se rellenara 
automáticamente.
*/


