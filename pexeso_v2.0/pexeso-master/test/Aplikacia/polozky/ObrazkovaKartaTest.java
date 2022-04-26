/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia.polozky;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Ado
 */
public class ObrazkovaKartaTest {
    
    public ObrazkovaKartaTest() {
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
     * Test of setStavObrazku method, of class ObrazkovaKarta.
     */
    @Test
    public void testSetStavObrazku() {
        System.out.println("setStavObrazku");
        Stavy stavKarty = null;
        ObrazkovaKarta instance = null;
        instance.setStavObrazku(stavKarty);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of getStavObrazka method, of class ObrazkovaKarta.
     */
    @Test
    public void testGetStavObrazka() {
        System.out.println("getStavObrazka");
        ObrazkovaKarta instance = null;
        Stavy expResult = null;
        Stavy result = instance.getStavObrazka();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of getVyska method, of class ObrazkovaKarta.
     */
    @Test
    public void testGetVyska() {
        System.out.println("getVyska");
        ObrazkovaKarta instance = null;
        int expResult = 0;
        int result = instance.getVyska();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of getSirka method, of class ObrazkovaKarta.
     */
    @Test
    public void testGetSirka() {
        System.out.println("getSirka");
        ObrazkovaKarta instance = null;
        int expResult = 0;
        int result = instance.getSirka();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
    
}
