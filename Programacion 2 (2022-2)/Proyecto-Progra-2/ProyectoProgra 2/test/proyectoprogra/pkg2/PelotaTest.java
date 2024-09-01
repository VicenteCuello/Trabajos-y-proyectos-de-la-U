/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package proyectoprogra.pkg2;

import java.awt.Graphics;
import java.util.ArrayList;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author maxil
 */
public class PelotaTest {
    
    public PelotaTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of move method, of class Pelota.
     */
    @Test
    public void testMove() {
        System.out.println("move");
        Pelota instance = new Pelota(0, 0, 1);
        instance.move();
    }

    /**
     * Test of checkCollision method, of class Pelota.
     */
    @Test
    public void testCheckCollision() {
        System.out.println("checkCollision");
        ArrayList<Segmento> G = new ArrayList<>();
        int n = 0;
        Pelota instance = new Pelota(n, n, 1);
        instance.checkCollision(G, n);
    }

    /**
     * Test of setVelocity method, of class Pelota.
     */
    @Test
    public void testSetVelocity() {
        System.out.println("setVelocity");
        float x = 0.0F;
        float y = 0.0F;
        Pelota instance = new Pelota(0, 0, 1);
        instance.setVelocity(x, y);
    }

    /**
     * Test of getType method, of class Pelota.
     */
    @Test
    public void testGetType() {
        System.out.println("getType");
        Pelota instance = new Pelota(0, 0, 16);
        int expResult = 16;
        int result = instance.getType();
        assertEquals(expResult, result);
    }
    
}
