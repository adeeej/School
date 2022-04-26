/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aplikacia.polozky;


 /**
 * Tento interface sluzi pre triedy FarebneHraciePole a ObrazkoveHraciePole.
 */

public interface IPolickovy {
    void zamiesaj();
    void ukazVsetky();
    void skryVsetky();
    void vyberSuradnice(int x, int y);
    boolean jeKoniec();
    
    
    
    
}
