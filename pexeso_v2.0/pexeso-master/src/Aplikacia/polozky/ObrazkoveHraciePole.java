package Aplikacia.polozky;

import Aplikacia.polozky.skola.Obrazok;
import Aplikacia.polozky.skola.Stvorec;
import Aplikacia.vynimky.SkoreHracaException;
import java.io.*;
import java.util.HashMap;
import java.util.Random;

/**
 * Trieda ObrazkoveHraciePole slúži na vykreslenie hracej plochy s obrazkami.
 * Vyuzivame dva final atributy, jeden pre serializaciu a druhy ako pocet hracov, ktory mozu tuto hru hrat.
 */

public class ObrazkoveHraciePole implements Serializable, IPolickovy {

    private static final long serialVersionUID = 56465456416684L;

    private transient final int pocetHracov = 2;

    private transient Stvorec[][] prednaStrana;
    private transient ObrazkovaKarta[][] zadnaStrana;
    private transient String[][] nazvyObrazkov;
    private transient int klikPocet;
    private transient int pocetRiadkov;
    private transient int pocetStlpcov;
    private HashMap<Integer, Integer> skoreHracov;
    private transient Vyhodnocovac vyhodnocovac;
    private transient int aktualnyHrac;
    private transient boolean exit;

 /**
 * Konstruktor priradi nazvy polickam, zamiesa ich, vytvori zadne a predne strany.
 * Vlozim prveho a druheo hraca do hashMapy ako indexy 1 a 2.
 */
    
    public ObrazkoveHraciePole(int riadok, int stlpec) {
        this.pocetRiadkov = riadok;
        this.pocetStlpcov = stlpec;
        this.klikPocet = 0;
        this.skoreHracov = new HashMap<>();
        this.nazvyObrazkov = new String[riadok][stlpec];
        this.zadnaStrana = new ObrazkovaKarta[riadok][stlpec];
        this.prednaStrana = new Stvorec[riadok][stlpec];
        this.priradNazvyObrazkov();
        this.zamiesaj();
        this.vytvorZadneStrany();
        this.vytvorPredneStrany();
        this.vyhodnocovac = new Vyhodnocovac();
        this.exit = false;

        this.skoreHracov.put(1, 0);
        this.skoreHracov.put(2, 0);

        this.aktualnyHrac = 1;
    }

 /**
 * Tato metoda serializuje skore hracov.
 */
    
    public void serialize() {
        try {
            FileOutputStream file = new FileOutputStream("serialize.ser");
            ObjectOutputStream out = new ObjectOutputStream(file);

            out.writeObject(this);

            out.close();
            file.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    
 /**
 * Tato metoda deserializuje skore hracov.
 */
    
    public static ObrazkoveHraciePole deserialize() {
        try {
            FileInputStream file = new FileInputStream("serialize.ser");
            ObjectInputStream in = new ObjectInputStream(file);

            ObrazkoveHraciePole obj = (ObrazkoveHraciePole)in.readObject();

            in.close();
            file.close();

            return obj;

        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        return null;
    }

 /**
 * Tato metoda priradi nazvy k jednotlivym hracim polickam zo suboru.
 */
    
    public void priradNazvyObrazkov() {
        int pomocna = 0;
        if ((this.pocetRiadkov * this.pocetStlpcov) % 2 == 0) {
            for (int i = 0; i < this.nazvyObrazkov.length; i++) {
                this.nazvyObrazkov[i] = new String[this.pocetStlpcov];
                for (int j = 0; j < this.nazvyObrazkov[i].length; j++) {
                    this.nazvyObrazkov[i][j] = "pics/obrazok" + (pomocna / 2) + ".png";
                    pomocna++;

                }
            }
        }

    }

/**
 * Tato metoda zamiesa jednotlive hracie policka.
 */
    
    public void zamiesaj() {
        Random rnd = new Random();
        String nazov;

        int pomocna = 500 + rnd.nextInt(300);
        int riadok1 = -1;
        int stlpec1 = -1;
        int riadok2 = -1;
        int stlpec2 = -1;
        for (int p = 1; p < pomocna; p++) {
            riadok1 = rnd.nextInt(this.pocetRiadkov);
            riadok2 = rnd.nextInt(this.pocetRiadkov);
            stlpec1 = rnd.nextInt(this.pocetStlpcov);
            stlpec2 = rnd.nextInt(this.pocetStlpcov);

            nazov = this.nazvyObrazkov[riadok1][stlpec1];
            this.nazvyObrazkov[riadok1][stlpec1] = this.nazvyObrazkov[riadok2][stlpec2];
            this.nazvyObrazkov[riadok2][stlpec2] = nazov;

        }

    }

/**
 * Tato metoda vytvori zadne strany hracich policok.
 */
    
    public void vytvorZadneStrany() {
        for (int i = 0; i < this.zadnaStrana.length; i++) {
            this.zadnaStrana[i] = new ObrazkovaKarta[this.pocetStlpcov];
            for (int j = 0; j < this.zadnaStrana[i].length; j++) {
                this.zadnaStrana[i][j] = new ObrazkovaKarta(this.nazvyObrazkov[i][j]);
                this.zadnaStrana[i][j].zmenPolohu(25 + (i * 69), 25 + (j * 69));
                this.zadnaStrana[i][j].setStavObrazku(Stavy.ZAKRYTY);
                this.zadnaStrana[i][j].zobraz();

            }
        }
    }

 /**
 * Tato metoda vytvori predne strany hracich policok.
 */

    public void vytvorPredneStrany() {
        for (int i = 0; i < this.prednaStrana.length; i++) {
            this.prednaStrana[i] = new Stvorec[this.pocetStlpcov];
            for (int j = 0; j < this.prednaStrana[i].length; j++) {
                this.prednaStrana[i][j] = new Stvorec();
                this.prednaStrana[i][j].zmenStranu(64);
                this.prednaStrana[i][j].zmenPolohu(25 + (i * 69),  25 + (j * 69 ));
                this.prednaStrana[i][j].zmenFarbu("blue");
                this.prednaStrana[i][j].setStavStvorca(Stavy.ODKRYTY);
                this.prednaStrana[i][j].zobraz();
            }
        }
    }

 /**
 * Tato metoda zobrazi vsetky predne strany hracich policok.
 */

    public void zobrazVsetkyPredneStrany() {
        for (int i = 0; i < this.prednaStrana.length; i++) {
            for (int j = 0; j < this.prednaStrana[i].length; j++)
                this.prednaStrana[i][j].zobraz();
        }
    }

/**
 * Tato metoda skryje vsetky predne strany hracich policok.
 */
    
    public void skryVsetkyPredneStrany() {
        for (int i = 0; i < this.prednaStrana.length; i++) {
            for (int j = 0; j < this.prednaStrana[i].length; j++)
                this.prednaStrana[i][j].skry();
        }
    }

/**
 * Tato metoda zobrazi vsetky zadne strany hracich policok, teda Obrazky.
 */
    
    public void ukazVsetky() {
        for (int i = 0; i < this.zadnaStrana.length; i++) {
            for (int j = 0; j < this.zadnaStrana[i].length; j++)
                this.zadnaStrana[i][j].zobraz();
        }
    }

/**
 * Tato metoda skryje vsetky zadne strany hracich policok, teda Obrazky.
 */
    
    public void skryVsetky() {
        for (int i = 0; i < this.zadnaStrana.length; i++) {
            for (int j = 0; j < this.zadnaStrana[i].length; j++)
                this.zadnaStrana[i][j].skry();
        }
    }

/**
 * Touto metodou po kliknuti mysou sa zobrazi dane policko.
 */
    
    public void vyberSuradnice(int x, int y) {
        Stvorec prvy  = null;
        Obrazok druhy = null;

        if (this.klikPocet < 2) {
            for (int i = 0; i < this.prednaStrana.length; i++) {
                for (int k = 0; k < this.prednaStrana[i].length; k++) {
                    if (this.prednaStrana[i][k].obsahujeBod(x, y)) {
                        if (this.zadnaStrana[i][k].getStavObrazka().equals(Stavy.ZAKRYTY)) {
                            this.prednaStrana[i][k].setStavStvorca(Stavy.ZAKRYTY);
                            this.zadnaStrana[i][k].setStavObrazku(Stavy.ODKRYTY);
                            prvy = this.prednaStrana[i][k];
                            druhy = this.zadnaStrana[i][k];
                            this.klikPocet++;
                            break;
                        }
                    }
                }
                if (prvy != null) { 
                    prvy.skry();
                }
            }
        } else if (this.klikPocet == 2) {
            boolean spravne = this.vyhodnocovac.vyhodnot();

            this.vypisSkore();

            if (!spravne) {
                this.aktualnyHrac++;
                if (this.aktualnyHrac > 2) {
                    this.aktualnyHrac = 1;
                }
            }
        }

        if (this.jeKoniec()) {
            this.exit = true;
        }

    }

    
 /**
 * Tato trieda sluzi ako tzv. inner trieda.
 */
    
    private class Vyhodnocovac {
        private String string1 = null;
        private String string2 = null;
        private ObrazkovaKarta obrazok1 = null;
        private ObrazkovaKarta obrazok2 = null;
        private Stvorec stvorec1 = null;
        private Stvorec stvorec2 = null;

        
 /**
 * Tato metoda sluzi na vyhodnotenie po kliknuti mysou. 
 * Ak sa dve karticky zhoduju tak ich zmaze.
 * Ak sa nezhoduju ukaze predne strany.
 */
        
        public boolean vyhodnot() {
            this.string1 = null;
            this.string2 = null;
            this.obrazok1 = null;
            this.obrazok2 = null;
            this.stvorec1 = null;
            this.stvorec2 = null;

            for (int i = 0; i < ObrazkoveHraciePole.this.prednaStrana.length; i++) {
                for (int j = 0; j < ObrazkoveHraciePole.this.prednaStrana[i].length; j++) {
                    if (ObrazkoveHraciePole.this.zadnaStrana[i][j].getStavObrazka().equals(Stavy.ODKRYTY) && this.string1 == null) {
                        this.string1 = ObrazkoveHraciePole.this.nazvyObrazkov[i][j];
                        this.obrazok1 = ObrazkoveHraciePole.this.zadnaStrana[i][j];
                        this.stvorec1 = ObrazkoveHraciePole.this.prednaStrana[i][j];
                    } else if (ObrazkoveHraciePole.this.zadnaStrana[i][j].getStavObrazka().equals(Stavy.ODKRYTY) && this.obrazok1 != null) {
                        this.string2 = ObrazkoveHraciePole.this.nazvyObrazkov[i][j];
                        this.obrazok2 = ObrazkoveHraciePole.this.zadnaStrana[i][j];
                        this.stvorec2 = ObrazkoveHraciePole.this.prednaStrana[i][j];
                        break;
                    }
                }
            }

            serialize();

            boolean spravne = this.porovnajKarticky();

            if (spravne) {
                ObrazkoveHraciePole.this.upravSkore();
                return true;
            }

            return false;
        }

        
 /**
 * Tato metoda porovnava dve dane karticky.
 */
        
        public boolean porovnajKarticky() {
            if (this.string1.equals(this.string2)) {
                this.obrazok1.skry();
                this.obrazok2.skry();
                this.obrazok1.setStavObrazku(Stavy.ZMAZANY);
                this.obrazok2.setStavObrazku(Stavy.ZMAZANY);
                ObrazkoveHraciePole.this.klikPocet = 0;

                return true;

            } else {
                this.stvorec1.zobraz();
                this.stvorec2.zobraz();
                this.stvorec1.setStavStvorca(Stavy.ODKRYTY);
                this.stvorec2.setStavStvorca(Stavy.ODKRYTY);
                this.obrazok1.setStavObrazku(Stavy.ZAKRYTY);
                this.obrazok2.setStavObrazku(Stavy.ZAKRYTY);
                ObrazkoveHraciePole.this.klikPocet = 0;
            }

            return false;
        }

    }
    
 /**
 * Tato metoda rata pocet otocenych karticiek.
 */
    
    public int getPocetOtocenych() {
        
        int pomocna = 0;
        for (int i = 0; i < this.zadnaStrana.length; i++) {
            for (int j = 0; j < this.zadnaStrana[i].length; j++) {
               if (this.zadnaStrana[i][j].equals(Stavy.ODKRYTY)) {
                    pomocna++;
                }
               
            }
            
        }
        
        return pomocna;
    }
    
    
 /**
 * Tato metoda rata pocet neotocenych karticiek.
 */
    
    public int getPocetNeotocenych() {
        
        int pomocna = 0;
         for (int i = 0; i < this.prednaStrana.length; i++) {
            for (int j = 0; j < this.prednaStrana[i].length; j++) {
               if (this.prednaStrana[i][j].equals(Stavy.ZAKRYTY)) {
                    pomocna++;
                }
               
            }
            
        }
        
        return pomocna;
        
    }
    
 /**
 * Tato metoda je sukromna a upravuje skore jednotlivym hracom.
 */
    
    private void upravSkore() {
        this.skoreHracov.put(this.aktualnyHrac, this.skoreHracov.get(this.aktualnyHrac) + 1);
    }

    
 /**
 * Tato metoda rata pocet zmazanych karticiek.
 */
    
    public int pocetOdstranenychKarticiek() {
        int pocetOdstranenych = 0;
        for (int i = 0; i < this.prednaStrana.length; i++) {
            for (int j = 0; j < this.prednaStrana[i].length; j++) {
                if (this.zadnaStrana[i][j].getStavObrazka().equals(Stavy.ZMAZANY)) {
                    pocetOdstranenych++;
                }
            }
        }
        return pocetOdstranenych;
    }



 /**
 * Tato metoda vyhodnoti ci je koniec hry alebo nie.
 */
    
    public boolean jeKoniec() {
        if (this.pocetRiadkov * this.pocetStlpcov == pocetOdstranenychKarticiek()) {
            return true;
        } else {
            return false;
        }
    }

    
    
 /**
 * Touto metodou sa da ziskat jednotlive skore danych hracov.
 */
    
    public int ziskajSkoreHraca(int idHraca)throws SkoreHracaException {
        
        if (idHraca < 0) {
            //return false;
            throw new SkoreHracaException("Zadane ID hraca musi byt kladne!");
        }
        
        return this.skoreHracov.get(idHraca);
    }

    
    
 /**
 * Tato metoda vypise skore hracov.
 */
    
    public void vypisSkore() {
        System.out.println("Aktualny hrac: " + this.aktualnyHrac + ", Skore 1: " + this.skoreHracov.get(1) + ", Skore 2: " + this.skoreHracov.get(2));
    }

    
 /**
 * Tato metoda vracia true alebo false od toho ci je koniec hry alebo nie.
 */
    
    public boolean getExit() {
        return this.exit;
    }
    
    
 /**
 * Tato metoda uklada jednotlive skore hracov do binarneho suboru.
 */
    
    public boolean ulozDoSuboru (String nazovSuboru) {
        File subor = new File(nazovSuboru);
        PrintWriter zapisovac = null;
        
        try {
            zapisovac =  new PrintWriter(subor);
            zapisovac.println(this.toString());
            
            
        } catch (IOException ex) {
            return false;
        } finally {
            if (zapisovac != null) {
                zapisovac.close();;
            }
        }
        
        return true;
    }
    
    public int hashCode() {
        return super.hashCode() *
               this.aktualnyHrac *
                this.klikPocet *
                this.pocetHracov *
                this.pocetRiadkov *
                this.pocetStlpcov *
                this.prednaStrana.hashCode() *
                this.zadnaStrana.hashCode() *
                this.nazvyObrazkov.hashCode() *
                this.skoreHracov.hashCode() *
                this.vyhodnocovac.hashCode() *
               (this.getExit() ? 1 : 2);
    }
    
    public boolean equals(Object o) {
        if (o == null) {
            return false;
        }
        
        if (!(o instanceof ObrazkoveHraciePole)) {
            return false;
        }
        
        ObrazkoveHraciePole param = (ObrazkoveHraciePole)o;
        
       
        if (this.aktualnyHrac != param.aktualnyHrac) {
            return false;
        }
        
        
        if (this.klikPocet != param.klikPocet) {
            return false;
        }
        
        
        if (this.pocetHracov != param.pocetHracov) {
            return false;
        }
        
        
        if (this.pocetRiadkov != param.pocetRiadkov) {
            return false;
        }
        
        
        if (this.pocetStlpcov != param.pocetStlpcov) {
            return false;
        }
        
        
        if (this.nazvyObrazkov != param.nazvyObrazkov) {
            return false;
        }
        
        
        if (this.skoreHracov != param.skoreHracov) {
            return false;
        }
        
        
        if (this.vyhodnocovac != param.vyhodnocovac) {
            return false;
        }
                
        
        if (!prednaStrana.equals(param.prednaStrana)) {
            return false;
        }
        
        if (!zadnaStrana.equals(param.zadnaStrana)) {
            return false;
        }
        
        if (!(this.exit = param.exit)) {
            return false;
        }
        
        return true;
                
    }
    

 /**
 * Metodou toString mozeme vidiet vypis ako dopadli jednotlivi hraci.
 */
    
    public String toString() {
        StringBuilder sb = new StringBuilder();
        
        sb.append("Aktualny hrac na tahu:" + this.aktualnyHrac);
        sb.append("\nSkore hraca cislo 1: " + this.skoreHracov.get(1));
        sb.append("\nSkore hraca cislo 2: " + this.skoreHracov.get(2));
        
        return sb.toString();
    }
}



