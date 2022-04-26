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
public class FarebnaKartickaTest {
    
    public FarebnaKartickaTest() {
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
     * Test of getOtocena method, of class FarebnaKarticka.
     */
    @Test
    public void testGetOtocena() {
        System.out.println("getOtocena");
        FarebnaKarticka instance = new FarebnaKarticka();
        boolean expResult = false;
        boolean result = instance.getOtocena();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
    
}
