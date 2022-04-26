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
public class FarebnaKartaTest {
    
    public FarebnaKartaTest() {
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
     * Test of getPrednaStrana method, of class FarebnaKarta.
     */
    @Test
    public void testGetPrednaStrana() {
        System.out.println("getPrednaStrana");
        FarebnaKarta instance = new FarebnaKarta();
        String expResult = "";
        String result = instance.getPrednaStrana();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of getZadnaStrana method, of class FarebnaKarta.
     */
    @Test
    public void testGetZadnaStrana() {
        System.out.println("getZadnaStrana");
        FarebnaKarta instance = new FarebnaKarta();
        String expResult = "";
        String result = instance.getZadnaStrana();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of setPrednaStrana method, of class FarebnaKarta.
     */
    @Test
    public void testSetPrednaStrana() {
        System.out.println("setPrednaStrana");
        String farba = "";
        FarebnaKarta instance = new FarebnaKarta();
        instance.setPrednaStrana(farba);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of setZadnaStrana method, of class FarebnaKarta.
     */
    @Test
    public void testSetZadnaStrana() {
        System.out.println("setZadnaStrana");
        String farba = "";
        FarebnaKarta instance = new FarebnaKarta();
        instance.setZadnaStrana(farba);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of zobrazZadnuStranu method, of class FarebnaKarta.
     */
    @Test
    public void testZobrazZadnuStranu() {
        System.out.println("zobrazZadnuStranu");
        FarebnaKarta instance = new FarebnaKarta();
        instance.zobrazZadnuStranu();
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of zobrazPrednuStranu method, of class FarebnaKarta.
     */
    @Test
    public void testZobrazPrednuStranu() {
        System.out.println("zobrazPrednuStranu");
        FarebnaKarta instance = new FarebnaKarta();
        instance.zobrazPrednuStranu();
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
    
}
