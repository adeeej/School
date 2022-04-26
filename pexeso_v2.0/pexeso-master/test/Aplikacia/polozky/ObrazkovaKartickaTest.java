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
public class ObrazkovaKartickaTest {
    
    public ObrazkovaKartickaTest() {
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
     * Test of getVyska method, of class ObrazkovaKarticka.
     */
    @Test
    public void testGetVyska() {
        System.out.println("getVyska");
        ObrazkovaKarticka instance = null;
        int expResult = 0;
        int result = instance.getVyska();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of setVyska method, of class ObrazkovaKarticka.
     */
    @Test
    public void testSetVyska() {
        System.out.println("setVyska");
        int vyska = 0;
        ObrazkovaKarticka instance = null;
        instance.setVyska(vyska);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of getSirka method, of class ObrazkovaKarticka.
     */
    @Test
    public void testGetSirka() {
        System.out.println("getSirka");
        ObrazkovaKarticka instance = null;
        int expResult = 0;
        int result = instance.getSirka();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of setSirka method, of class ObrazkovaKarticka.
     */
    @Test
    public void testSetSirka() {
        System.out.println("setSirka");
        int sirka = 0;
        ObrazkovaKarticka instance = null;
        instance.setSirka(sirka);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    public class ObrazkovaKartickaImpl extends ObrazkovaKarticka {

        public ObrazkovaKartickaImpl() {
            super("");
        }

        public int getVyska() {
            return 0;
        }

        public int getSirka() {
            return 0;
        }
    }
    
}
