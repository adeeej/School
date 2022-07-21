#include "databaza_uzemnych_celkov.h"
#include "spustac.h"
#include "structures/common/heap_monitor.h"

int main() {
	initHeapMonitor();
	//DatabazaUzemnychCelkov databaza;
	//databaza.nacitajData("uzemne_jednotky.csv", "vzdelanie_a_vek.csv");
	
	Spustac spustac;
	spustac.spusti();

	
	
	return 0;
}