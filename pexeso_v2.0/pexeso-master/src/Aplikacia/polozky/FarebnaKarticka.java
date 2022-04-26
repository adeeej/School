/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia.polozky;

import Aplikacia.polozky.skola.Stvorec;


 /**
 * Tato trieda je zdedena z triedy Stvorec.
 */

public class FarebnaKarticka extends Stvorec {

    protected boolean jeOtoceny;

    
 /**
 * Konstruktor nastavi karticku na hodnotu false - nie je otocena.
 */
    
    public FarebnaKarticka() {

        this.jeOtoceny = false;

    }
   
 /**
 * Tato vrati true aj je karticka otocena, ak nie je vracia false.
 */
    
    public boolean getOtocena() {
        return this.jeOtoceny;
    }

}
