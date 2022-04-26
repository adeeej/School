package Aplikacia.spustace;

import Aplikacia.polozky.ObrazkoveHraciePole;
import Aplikacia.polozky.skola.Manazer;
import Aplikacia.vynimky.SkoreHracaException;

/**
 * Tato trieda je spustacom celej hry.
 */

public class Main2 {

    public static void main(String[] args) throws SkoreHracaException {
        ObrazkoveHraciePole obj = ObrazkoveHraciePole.deserialize();
        System.out.println(obj.ziskajSkoreHraca(1));
        System.out.println(obj.ziskajSkoreHraca(2));          
        ObrazkoveHraciePole hra = new ObrazkoveHraciePole(4, 4);
        Manazer manazer = new Manazer();
        manazer.spravujObjekt(hra);
    }

}

