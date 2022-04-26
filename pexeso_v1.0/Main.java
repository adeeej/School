import java.util.Scanner;

public class Main {

    /** 
     * Main slúži ako spúšťač hry pexeso.
     * Pre použitie ťahu je potrebné použiť písmenko r
     * Vzor pre ťah: r suradnicaX suradnicaY.
     * Pre zastavenie programu použi písmenko k.
     * Ak hráč hru dohrá, na konci hry sa mu vypíše počet jeho ťahov.
     */
    public static void main() {

        int velkost = 4;
        HraciePole p = new HraciePole(velkost);
        char vyber;
        int pocitadlo = 0;

        Scanner klav = new Scanner(System.in);
        System.out.println("\f");
        System.out.println("Vitajte v hre pexeso!");
        System.out.println("Pre použitie ťahu použi písmenko r, pre zastavenie programu použi písmenko k");
        System.out.println("Vzor pre ťah: r suradnicaX suradnicaY");

        program: while(true) {
            
            if(p.getPocetOtocenych() == 2) {
                p.vyhodnot();

            }

            if(p.koniecHry()) {
                System.out.println("Vyhrali ste!");
                System.out.println("");
                break;
            }

            vyber = klav.next().charAt(0);

            switch(vyber) {
                case 'r':           
                p.ukazRub(klav.nextInt(), klav.nextInt());
                break;
                case 'k':
                System.out.println("Program bol skonceny! Vas pocet tahov je neplatny!");
                break program;
                default:
                System.out.println("Nespravny zapis!");
            }

            if(p.getPocetOtocenych() == 2) {
                pocitadlo = pocitadlo + 1;
            }

        }

        if (p.koniecHry()) {
            System.out.println("Gratulujem! Vyhrali ste!");
            System.out.println("Váš počet ťahov je: " + pocitadlo);
        }

    }

}
