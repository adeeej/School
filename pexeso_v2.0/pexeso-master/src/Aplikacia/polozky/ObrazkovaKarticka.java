/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia.polozky;

import Aplikacia.polozky.skola.Obrazok;


 /**
 * Tato trieda je je trieda abstraktna a je zdedene z triedy Obrazok.
 */ 

public abstract class ObrazkovaKarticka extends Obrazok {
   
    private int vyska;
    private int sirka;
    

 /**
 * Konstruktor nacita obrazok zo suboru.
 * @param suborSObrazkom cesta k suboru s obrazkom, ktory sa ma vykreslovat
 */  
    
    public ObrazkovaKarticka(String suborSObrazkom) {
        super(suborSObrazkom);
    }
    
    
 /**
 * Tato metoda vracia vysku obrazka.
 */
    
    public abstract int getVyska();
    
    
 /**
 * Tato metoda meni vysku obrazka.
 */
    public void setVyska(int vyska) {
        this.vyska = vyska;
    }
    
    
 /**
 * Tato metoda vracia sirku obrazka.
 */
    
    public abstract int getSirka();
    
    
 /**
 * Tato metoda meni sirku obrazka.
 */
    
    public void setSirka(int sirka) {
        this.sirka = sirka;
    }
}
