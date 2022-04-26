package Aplikacia.polozky;


 /**
 * Tato trieda je zdedene z triedy ObrazkovaKarticka.
 */

public class ObrazkovaKarta extends ObrazkovaKarticka {
       
    private Stavy stavKarty;
    private static final int VYSKA_SIRKA = 40;
    
    
 /**
 *Konstruktor nacita obrazok o suborau.
 * @param suborSObrazkom cesta k suboru s obrazkom, ktory sa ma vykreslovat na platno.
 */
    
    public ObrazkovaKarta(String suborSObrazkom) {
        super(suborSObrazkom);
        
    } 
    
 /**
 * Tato metoda meni stav obrazku pomocou daneho enumu.
 */
    public void setStavObrazku (Stavy stavKarty) {
        this.stavKarty = stavKarty;
    }
    
    
 /**
 * Tato metoda vracia stav obrazku.
 */
    
    public Stavy getStavObrazka() {
        return this.stavKarty;
    }

    
 /**
 * Tato metoda vracia vysku obrazka.
 */
    
    public int getVyska() {
       return this.VYSKA_SIRKA;
    }
    
    
 /**
 * Tato metoda vracia sirku obrazka.
 */
    
    public int getSirka() {
        return this.VYSKA_SIRKA;
    }
}
