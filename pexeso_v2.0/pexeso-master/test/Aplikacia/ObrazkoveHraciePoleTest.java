/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia;

import Aplikacia.polozky.ObrazkoveHraciePole;
import Aplikacia.vynimky.SkoreHracaException;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;


/**
 * Tato testovacia trieda testuje dane metody z triedy ObrazkoveHraciePole.
 */ 

public class ObrazkoveHraciePoleTest {
    
    private ObrazkoveHraciePole p;
    
    public ObrazkoveHraciePoleTest() {
    }
       
 /**
 *Inicializujeme tento objekt.
 */ 
    @Before
    public void setUp() {
        this.p = new ObrazkoveHraciePole(4, 4);
    }
    
    
    @After
    public void tearDown() {
    }

 /**
 *Testujeme ci nam skryje vsetky hracie policka.
 */ 
    
    @Test
    public void testSkryVsetky() {
        this.p.skryVsetky();
        assertTrue(this.p.getPocetOtocenych() == 0);
    }
    
 /**
 *Testujeme ziskane skore danych hraco.
 */ 
    
    @Test
     public void testZiskajSkoreHraca() throws SkoreHracaException {
        assertTrue(this.p.ziskajSkoreHraca(1) <= 16 && this.p.ziskajSkoreHraca(1) >= 0);
        assertTrue(this.p.ziskajSkoreHraca(2) <= 16 && this.p.ziskajSkoreHraca(2) >= 0);
    }
    
 /**
 *Testujeme ci je koniec hry.
 */ 
     
    @Test
    public void testJeKoniec() {   
        
        if (this.p.jeKoniec()) {
            assertTrue (this.p.pocetOdstranenychKarticiek() == 16);
        }
    }
}
