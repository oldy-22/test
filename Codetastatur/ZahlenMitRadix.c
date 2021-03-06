/*
 * ZahlenMitRadix.cpp
 *
 * Das Programm sucht nach Zahlen, in denen sich die Ziffern nicht wiederholen
 * und zählt lediglich diese, als zB: 12345, aber nicht 12342
 *
 *  Created on: 24.05.2022
 *      Author: hroptatyr
 */

#include <stdio.h>
#include <stdint.h>

static int repeats(size_t i)
{
    unsigned char ziffernZaehler[10U] = {0};
    do {
            if (ziffernZaehler[(i % 10U)]++ >= 1) {
                    return 0; // wenn nicht 0 in Zelle gab es schon vorher Treffer
            }				// damit ist Ziifer nicht mehr unique
    } while (i /= 10U);     // eine Stelle nach links rücken
    return 1;
}

int main() {
    int counter = 0; // zaehlt Zahlen ohne Wiederholungen von Ziffern in der Zahl

	printf("ZahlenMitRadix\n");
    for (size_t i=1000; i<999999999; ++i) {
            counter += repeats(i);
    }
    printf("%d\n\r", counter);
    return 0;
}
