/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package proyectoprogra.pkg2;

import java.awt.Graphics;
import javax.swing.JPanel;
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
public class startConfigTest {
    
    public startConfigTest() {
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
     * Test of addBall method, of class startConfig.
     */
    @Test
    public void testAddBall() {
        System.out.println("addBall");
        int n = 0;
        startConfig instance = new startConfig();
        instance.addBall(n);
    }

    /**
     * Test of removeBall method, of class startConfig.
     */
    @Test
    public void testRemoveBall() {
        System.out.println("removeBall");
        startConfig instance = new startConfig();
        instance.removeBall();
    }

    /**
     * Test of enterCheck method, of class startConfig.
     */
    @Test
    public void testEnterCheck() {
        System.out.println("enterCheck");
        Pelota p = new Pelota(0, 0, 1);
        startConfig instance = new startConfig();
        boolean expResult = false;
        boolean result = instance.enterCheck(p);
        assertEquals(expResult, result);
    }

    /**
     * Test of startGame method, of class startConfig.
     */
    @Test
    public void testStartGame() {
        System.out.println("startGame");
        PanelPrincipalProyecto Frame = new PanelPrincipalProyecto();
        startConfig instance = new startConfig();
        instance.startGame(Frame);
    }

    /**
     * Test of restart method, of class startConfig.
     */
    @Test
    public void testRestart() {
        System.out.println("restart");
        PanelPrincipalProyecto Frame = new PanelPrincipalProyecto();
        startConfig instance = new startConfig();
        instance.restart(Frame);
    }

    /**
     * Test of bCollision method, of class startConfig.
     */
    @Test
    public void testBCollision() {
        System.out.println("bCollision");
        Pelota A = new Pelota(0, 0, 16);
        Pelota B = new Pelota(0, 0, 1);
        startConfig instance = new startConfig();
        boolean expResult = true;
        boolean result = instance.bCollision(A, B);
        assertEquals(expResult, result);
    }
    
}
