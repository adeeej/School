package Aplikacia.polozky;

import Aplikacia.polozky.skola.Platno;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Random;


/**
 * Trieda FarebneHraciePole slúži na vykreslenie hracej plochy s farbami.
 * Jednotlivé kartičky su zamiešané a sú im pridelené jednotlivé súradnice.
 * Trieda využíva jeden final atribút s názvom FARBY typu String[], ide o jednorozmerné pole stringov, kde sa uchovávajú jednotlivé farbičky kariet.
 */

public class FarebneHraciePole implements Serializable, IPolickovy {
    private Platno canvas;
    private FarebnaKarta[][] pole;
    private static final String[] FARBY = {"blue", "black", "yellow", "green", "magenta", "orange", "pink", "gray"};
    private FarebnaKarta otocena1;
    private FarebnaKarta otocena2;
    private int velkost;
    private int pocetKlikov;

    /**
     * Konštruktor HraciePole je parametrický a ako parameter berie rozmer poľa(int).
     * Konštruktor vie vytvoriť pole len o veľkosti 4x4, ak bude zadaná veľkost iná, potom sa vypíše do terminálu chyba.
     * Konštruktor pole vytvorí a následne zamieša kartičky.
     */

    public FarebneHraciePole(int rozmer) {
        this.pocetKlikov = 0;

        if (rozmer == 4) {
            this.pole = new FarebnaKarta[rozmer][rozmer];
            this.velkost = rozmer;

            for (int x = 0; x < rozmer; x++) {
                for (int y = 0; y < rozmer; y++) {
                    String zadnaFarba = "red";
                    FarebnaKarta karta = new FarebnaKarta();
                    karta.posunVodorovne(75 * x);
                    karta.posunZvisle(75 * y);
                    karta.zmenStranu(70);
                    karta.zmenFarbu(zadnaFarba);
                    karta.zobraz();
                    karta.setZadnaStrana(zadnaFarba);
                    this.pole[x][y] = karta;
                }
            }

            this.zamiesaj();
        } else {
            System.out.println("Nesprávny rozmer plochy!");
        }
    }

    /**
     * Metóda vyhodnot vyhodnocuje dve kartičky pexesa.
     * Ak sú kartičky rovnaké, ukáže sa ich rúb.
     * Naopak ak sú kartičky rozdielné, otočia sa naspäť.
     */
    
    public void vyhodnot() {
        if (this.otocena1.getPrednaStrana().equals(this.otocena2.getPrednaStrana())) {
            this.otocena1.zobrazPrednuStranu();
            this.otocena2.zobrazPrednuStranu();

        } else {
            this.otocena1.zobrazZadnuStranu();
            this.otocena2.zobrazZadnuStranu();
            //karty su roznej farby
        }

        this.pocetKlikov = 0;

    }

    /**
     * Metóda zamiesaj random zamieša kartičky.
     */
    
    @Override
    public void zamiesaj() {
        ArrayList<FarebnaKarta> ar = new ArrayList<FarebnaKarta>();
        for (int i = 0; i < this.pole.length; i++) {
            for (int j = 0; j < this.pole[i].length; j++) {
                ar.add(this.pole[i][j]);
            }
        }

        Random rnd = new Random();
        for (int i = 0; i < FARBY.length; i++) {
            String farba = FARBY[i];
            int index = rnd.nextInt(ar.size());
            FarebnaKarta karta1 = ar.get(index);
            karta1.setPrednaStrana(farba);
            ar.remove(index);
            index = rnd.nextInt(ar.size());
            FarebnaKarta karta2 = ar.get(index);
            karta2.setPrednaStrana(farba);
            ar.remove(index);

        }
    }

    
 /**
 * Touto metodou si mozeme po zadani suradnic otocit dane policko na zadanej pozicii.
 */
    
    public void vyberSuradnice(int x, int y) {

        for (int i = 0; i < this.pole.length; i++) {
            for (int j = 0; j < this.pole[i].length; j++) {
                if (this.pole[i][j].obsahujeBod(x, y)) {
                    if (this.pocetKlikov == 0) {
                        this.otocena1 = this.pole[i][j];
                        break;
                    } else if (this.pocetKlikov == 1) {
                        this.otocena2 = this.pole[i][j];
                        break;
                    }
                }
            }
        }

        if (this.pocetKlikov == 0) {
            if (this.otocena1.getOtocena()) {
                this.otocena1.zobrazPrednuStranu();
            } else {
                this.otocena1.zobrazZadnuStranu();
                this.pocetKlikov--;
            }
        }

        if (this.pocetKlikov == 1) {
            if (this.otocena2.getOtocena()) {
                this.otocena2.zobrazPrednuStranu();
            } else {
                this.otocena2.zobrazZadnuStranu();
                this.pocetKlikov--;
            }
        }

        this.pocetKlikov++;

        if (this.pocetKlikov == 2) {
            this.vyhodnot();
            return;
        }

        System.out.println(this.pocetKlikov);
    }

    
 /**
 * Tato metoda serializuje cely objekt.
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
 * Tato metoda desearizuje cely objekt.
 */
    
    public static FarebneHraciePole deserialize() {
        try {
            FileInputStream file = new FileInputStream("serialize.ser");
            ObjectInputStream in = new ObjectInputStream(file);

            FarebneHraciePole obj = (FarebneHraciePole)in.readObject();

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
     * Metóda ukazVsetky otočí všetky kratičky pexesa(ukáže ich rúb).
     */
    
    public void ukazVsetky() {
        for (int i = 0; i < this.pole.length; i++) {
            for (int j = 0; j < this.pole[i].length; j++) {
                this.pole[i][j].zobrazPrednuStranu();
            }
        }
    }

    /**
     * Metóda skryVsetky otočí všetky kratičky pexesa naspäť(ukáže ich líce).
     */
    
    public void skryVsetky() {
        for (int i = 0; i < this.pole.length; i++) {
            for (int j = 0; j < this.pole[i].length; j++) {
                this.pole[i][j].zobrazZadnuStranu();
            }
        }
    }
    
    
 /**
 * Tato metoda vracia pocet otocenych karticiek.
 */
    
    public int getPocetOtocenych() {
        int pomocna = 0;
        
    
        for (int i = 0; i < this.pole.length; i++) {
            for (int j = 0; j < this.pole[i].length; j++) {
                
                pomocna++;
            }
        }
        return pomocna;
    }

    /**
     * Metóda zisti ci je koniec hry. Bud vrati false ak nie je alebo vrati true ak je koniec hry.
     */
    
    public boolean jeKoniec() {
        for (int i = 0; i < this.velkost; i++) {
            for (int j = 0; j < this.velkost; j++) {
                if (!this.pole[i][j].getOtocena()) {
                    return false;
                }
            }
        }
        return true;
    }
}


