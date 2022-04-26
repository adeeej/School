import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;
import java.lang.String;

public class HraciePole {
    private Platno canvas = Platno.dajPlatno();
    private Stvorec[][] pole;
    private static final String[] FARBY = {"blue","black","yellow","green","magenta","orange","pink","gray"};
    private int pocetOtocenych;
    private Stvorec otocena1;
    private Stvorec otocena2;
    private int velkost;

    
    public HraciePole(int rozmer) {

        if (rozmer == 4) {
            this.pole = new Stvorec[rozmer][rozmer];
            this.pocetOtocenych = 0;
            this.velkost = rozmer;

            for(int x=0; x<rozmer; x++) {
                for(int y=0; y<rozmer; y++) {
                    String zadnaFarba = "red";
                    Stvorec karta = new Stvorec(canvas);
                    karta.posunVodorovne(75 * x);
                    karta.posunZvisle(75 * y);
                    karta.zmenStrany(70, 70);
                    karta.zmenFarbu(zadnaFarba);
                    karta.zobraz();
                    karta.setZadna(zadnaFarba);
                    pole[x][y] = karta;
                }
            }

            this.zamiesaj();
        } else { 
            System.out.println("Nespravny rozmer plochy!");
        }
    }

    /** 
     * Metóda vyhodnot vyhodnocuje dve kartičky pexesa.
     * Ak sú kartičky rovnaké, ukáže sa ich rúb.
     * Naopak ak sú kartičky rozdielné, otočia sa naspäť.  
     */
    public void vyhodnot(){
        if (otocena1.getPrednaStrana().equals(otocena2.getPrednaStrana())) {
            otocena1.zobrazPredna();
            otocena2.zobrazPredna();
            pocetOtocenych = 0;
            //karty su rovnakej farby
        } else {
            canvas.wait(2000);
            otocena1.zobrazZadna();
            otocena2.zobrazZadna();
            pocetOtocenych = 0;
            //karty su roznej farby
        }        

    }

    /** 
     * Metóda zamiesaj random zamieša kartičky.
     */
    private void zamiesaj() {
        ArrayList<Stvorec> ar = new ArrayList<Stvorec>();
        for(int i = 0; i < pole.length; i++) {
            for(int j = 0; j < pole[i].length; j++) {
                ar.add(pole[i][j]);               
            }
        }

        Random rnd = new Random();
        for(int i=0; i<FARBY.length; i++) {
            String farba = FARBY[i];
            int index = rnd.nextInt(ar.size());
            Stvorec karta1 = ar.get(index);
            karta1.setPredna(farba);
            ar.remove(index);
            index = rnd.nextInt(ar.size());
            Stvorec karta2 = ar.get(index);
            karta2.setPredna(farba);
            ar.remove(index);

        }
    }

    /** 
     * Metóda ukazRub otočí kartičku na danej pozícii [x,y].
     * Ak používateľ zvolí hodnoty mimo intervalu vypíše mu "Nesprávny ťah!" a musí hodnoty zadaž znovu.   
     */
    public void ukazRub(int x, int y) {
        if (x > 0 && x < 5 || y > 0 && y < 5) {
            Stvorec vyber = pole[y - 1][x - 1];
            if(vyber.getOtoceny() == true) {
                System.out.println("Zla volba");
            } else {

                vyber.zobrazPredna();
                if(pocetOtocenych == 0) {
                    otocena1 = vyber;
                }
                if(pocetOtocenych == 1) {
                    otocena2 = vyber;
                }
                pocetOtocenych++;
            }
        } else {
            System.out.println("Nespravny tah!");
        }
    }

    /** 
     * Metóda ukazLice otočí otočenú kartičku naspäť na danej pozícii [x,y].
     * Ak používateľ zvolí hodnoty mimo intervalu vypíše mu "Nesprávny ťah!" a musí hodnoty zadaž znovu.   
     */
    public void ukazLice(int x, int y) {
        if (x > 0 && x < 5 || y > 0 && y < 5) {
            pole[x - 1][y - 1].zobrazZadna();
        } else {
            System.out.println("Nesprávny ťah!");
        }

    }

    /** 
     * Metóda ukazvsetky otočí všetky kratičky pexesa(ukáže ich rúb).  
     */
    public void ukazVsetky() {
        for(int i = 0; i < pole.length; i++) {
            for(int j = 0; j < pole[i].length; j++) {
                pole[i][j].zobrazPredna();               
            }
        }
    }

    /** 
     * Metóda skryVsetky otočí všetky kratičky pexesa naspäť(ukáže ich líce).  
     */
    public void skryVsetky() {
        for(int i = 0; i < pole.length; i++) {
            for(int j = 0; j < pole[i].length; j++) {
                pole[i][j].zobrazZadna();               
            }
        }
    }

    /** 
     * Metóda getPocet otočených vracia počet otočených kartičiek pexesa.  
     */
    public int getPocetOtocenych() {
        return pocetOtocenych;
    }

    /** 
     * Metóda koniecHry ukončí hru.  
     */
    public boolean koniecHry() {
        for(int i = 0; i < velkost; i++) {
            for(int j = 0; j < velkost; j++) {
                if(pole[i][j].getOtoceny() == false) {
                    return false;
                }
            }
        }
        return true;
    }
}

