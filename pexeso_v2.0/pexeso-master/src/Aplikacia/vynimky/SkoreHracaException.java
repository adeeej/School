/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia.vynimky;

/**
 *Vlastna vynimka pre skore hracov.
 */ 

public class SkoreHracaException extends Exception {
    public SkoreHracaException (String popis) {
        super (popis);
    }
}
