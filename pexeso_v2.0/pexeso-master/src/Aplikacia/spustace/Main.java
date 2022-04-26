package Aplikacia.spustace;

import Aplikacia.polozky.FarebneHraciePole;
import Aplikacia.polozky.skola.Manazer;

/**
 * Tato trieda je spustacom celej hry.
 */

public class Main {

    public static void main(String[] args) {
        FarebneHraciePole obj = FarebneHraciePole.deserialize();
        FarebneHraciePole hra = new FarebneHraciePole(4);
        Manazer manazer = new Manazer();
        manazer.spravujObjekt(hra);

    }
    
}