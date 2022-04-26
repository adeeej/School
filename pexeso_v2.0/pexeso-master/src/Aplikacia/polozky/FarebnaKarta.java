/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia.polozky;


 /**
 * Tato trieda je zdedena z triedy FarebnaKarticka.
 */

public class FarebnaKarta extends FarebnaKarticka {


    private String prednaStrana;
    private String zadnaStrana;
    
    
 /**
 * Bezparametricky konstruktor.
 */

    public FarebnaKarta() {
        
    }

 /**
 * Tato metoda vracia farbu prednej strany ako string.
 */
    
    public String getPrednaStrana() {
        return this.prednaStrana;
    }
    
    
 /**
 * Tato metoda vracia farbu zadnej strany ako string.
 */

    public String getZadnaStrana() {
        return this.zadnaStrana;
    }

    
 /**
 * Tato metoda nastavuje farbu prednej strany.
 */
    
    public void setPrednaStrana(String farba) {
        this.prednaStrana = farba;
    }

 /**
 * Tato metoda nastavuje farbu zadnej strany.
 */
    
    public void setZadnaStrana(String farba) {
        this.zadnaStrana = farba;
    }

 /**
 * Tato metoda zobrazi zadnu stranu karticky.
 */
    
    public void zobrazZadnuStranu() {
        this.zmenFarbu(this.zadnaStrana);
    }
    
 /**
 * Tato metoda zmeni farbu prednej strany, nastavi jeOtoceny na true a nasledne zobrazi prednu stranu karticky.
 */

    public void zobrazPrednuStranu() {
        this.zmenFarbu(this.prednaStrana);
        this.jeOtoceny = true;
    }

}
