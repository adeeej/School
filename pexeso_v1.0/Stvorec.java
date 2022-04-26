
import java.awt.Rectangle;

/**
 * Obdĺžnik, s ktorým možno pohybovať a nakreslí sa na plátno.
 * 
 * @author  Michael Kolling and David J. Barnes
 * @version 1.0  (15 July 2000)
 */

public class Stvorec {
    private int stranaA;
    private int stranaB;
    private int lavyHornyX;
    private int lavyHornyY;
    private String farba;
    private boolean jeViditelny;
    private boolean jeOtoceny;
    private String prednaStrana;
    private String zadnaStrana;
    private Platno canvas;

    /**
     * Vytvor nový obdĺžnik preddefinovanej farby na preddefinovanej pozícii.
     */
    public Stvorec(Platno platno) {
        this.canvas = platno;
        this.stranaA = 30;
        this.stranaB = 60;
        this.lavyHornyX = 0;
        this.lavyHornyY = 0;
        this.farba = "red";
        this.jeViditelny = false;
        this.jeOtoceny = false;
    }

    /**
     * Metóda vracia farbu prednej strany kartičky.
     */
    public String getPrednaStrana() {
        return prednaStrana;       
    }
    
    /**
     * Metóda vracia farbu zadnej strany kartičky.
     */
    public String getZadnaStrana() {
        return zadnaStrana;
    }
    
    /**
     * (Obdĺžnik) Zobraz sa.
     */
    public void zobraz() {
        this.jeViditelny = true;
        this.nakresli();
    }
    
    /**
     * (Obdĺžnik) Skry sa.
     */
    public void skry() {
        this.zmaz();
        this.jeViditelny = false;
    }
    
    /**
     * (Obdĺžnik) Posuň sa vpravo o pevnú dĺžku.
     */
    public void posunVpravo() {
        this.posunVodorovne(20);
    }

    /**
     * (Obdĺžnik) Posuň sa vľavo o pevnú dĺžku.
     */
    public void posunVlavo() {
        this.posunVodorovne(-20);
    }

    /**
     * (Obdĺžnik) Posuň sa hore o pevnú dĺžku.
     */
    public void posunHore() {
        this.posunZvisle(-20);
    }

    /**
     * (Obdĺžnik) Posuň sa dole o pevnú dĺžku.
     */
    public void posunDole() {
        this.posunZvisle(20);
    }

    /**
     * (Obdĺžnik) Posuň sa vodorovne o dĺžku danú parametrom.
     */
    public void posunVodorovne(int vzdialenost) {
        this.zmaz();
        this.lavyHornyX += vzdialenost;
        this.nakresli();
    }

    /**
     * (Obdĺžnik) Posuň sa zvisle o dĺžku danú parametrom.
     */
    public void posunZvisle(int vzdialenost) {
        this.zmaz();
        this.lavyHornyY += vzdialenost;
        this.nakresli();
    }

    /**
     * (Obdĺžnik) Posuň sa pomaly vodorovne o dĺžku danú parametrom.
     */
    public void pomalyPosunVodorovne(int vzdialenost) {
        int delta;

        if (vzdialenost < 0) {
            delta = -1;
            vzdialenost = -vzdialenost;
        } else  {
            delta = 1;
        }

        for (int i = 0; i < vzdialenost; i++) {
            this.lavyHornyX += delta;
            this.nakresli();
        }
    }

    /**
     * (Obdĺžnik) Posuň sa pomaly vodorovne o dĺžku danú parametrom.
     */
    public void pomalyPosunZvisle(int vzdialenost) {
        int delta;

        if (vzdialenost < 0) {
            delta = -1;
            vzdialenost = -vzdialenost;
        } else {
            delta = 1;
        }

        for (int i = 0; i < vzdialenost; i++) {
            this.lavyHornyY += delta;
            this.nakresli();
        }
    }

    /**
     * (Obdĺžnik) Zmeň dĺžky strán na hodnoty dané parametrami.
     * Dĺžka strany musí byť nezáporné celé číslo. 
     */
    public void zmenStrany(int stranaA, int stranaB) {
        this.zmaz();
        this.stranaA = stranaA;
        this.stranaB = stranaB;
        this.nakresli();
    }
    
    public void zmenPolohu(int lavyHornyX, int lavyHornyY) {
        boolean nakresleny = this.jeViditelny;
        this.zmaz();
        this.lavyHornyX = lavyHornyX;
        this.lavyHornyY = lavyHornyY;
        if (nakresleny) {
            this.nakresli();
        }
    }

    /**
     * (Obdĺžnik) Zmeň farbu na hodnotu danú parametrom.
     * Nazov farby musí byť po anglicky.
     * Možné farby sú tieto:
     * červená - "red"
     * žltá    - "yellow"
     * modrá   - "blue"
     * zelená  - "green"
     * fialová - "magenta"
     * čierna  - "black"
     * biela   - "white"
     * hnedá   - "brown"
     */
    public void zmenFarbu(String farba) {
        this.farba = farba;
        this.nakresli();
    }

    /*
     * Draw the square with current specifications on screen.
     */
    private void nakresli() {
        if (this.jeViditelny) {
            this.canvas.draw(this, this.farba,
                        new Rectangle(this.lavyHornyX, this.lavyHornyY, this.stranaA, this.stranaB));
            this.canvas.wait(10);
        }
    }

    /*
     * Erase the square on screen.
     */
    private void zmaz() {
        if (this.jeViditelny) {
            Platno canvas = Platno.dajPlatno();
            canvas.erase(this);
        }
    }
        
    /**
     * Metóda nastavuje farbu prednej strany kartičky.
     */
    public void setPredna(String farba) {
        this.prednaStrana = farba;
    }
        
    /**
     * Metóda nastavuje farbu zadnej strany kartičky.
     */
    public void setZadna(String farba) {
        this.zadnaStrana = farba;
    }
    
    /**
     * Metóda zobrazuje farbu zadnej strany kartičky.
     */
    public void zobrazZadna() {
        this.zmenFarbu(this.zadnaStrana);
        this.jeOtoceny = false;
    }
    
    /**
     * Metóda zobrazuje farbu prednej strany kartičky.
     */
    public void zobrazPredna() {
        this.zmenFarbu(this.prednaStrana);
        this.jeOtoceny = true;
    }
    
    /**
     * Metóda zisťuje, či je kartička otočená.
     */
    public boolean getOtoceny() {
       return this.jeOtoceny;
    }
}
