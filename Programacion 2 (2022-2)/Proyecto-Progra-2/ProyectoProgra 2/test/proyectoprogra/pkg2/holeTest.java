/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package proyectoprogra.pkg2;

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
public class holeTest {
    
    public holeTest() {
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
     * Test of enterBall method, of class hole.
     */
    @Test
    public void testEnterBall() {
        System.out.println("enterBall");
        Pelota p = new Pelota(0, 0, 3);
        hole instance = new hole(0, 0);
        boolean expResult = true;
        boolean result = instance.enterBall(p);
        assertEquals(expResult, result);
    }
    
}
