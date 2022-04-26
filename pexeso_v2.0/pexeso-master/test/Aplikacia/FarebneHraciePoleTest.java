
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia;

import Aplikacia.polozky.FarebneHraciePole;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;


/**
 * Tato testovacia trieda testuje dane metody z triedy FarebneHraciePole.
 */ 

public class FarebneHraciePoleTest {
    
    private FarebneHraciePole p;
    
    public FarebneHraciePoleTest() {
    }
    
 /**
 *Inicializujeme tento objekt.
 */
    
    @Before
    public void setUp() {
        this.p = new FarebneHraciePole(4);
    }
    
    
    @After
    public void tearDown() {
    }

 /**
 *Testujeme ci nam ukaze vsetky hracie policka.
 */
    
    @Test
    public void testUkazVsetky() {
        this.p.ukazVsetky();
        assertTrue(this.p.getPocetOtocenych() == 16);
    }
    
 /**
 *Testujeme ci je koniec hry.
 */  
     
    @Test
   public void testJeKoniec() {   
        
        if (this.p.jeKoniec()) {
            assertTrue(this.p.getPocetOtocenych() == 16);
        }
    }
}
