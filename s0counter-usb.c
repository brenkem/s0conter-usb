#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/sync.h"

// Definition der GPIO-Pins (entspricht PCB Pins 4, 9, 12)
const uint PIN_S0_1 = 2; // PCB Pin 4
const uint PIN_S0_2 = 6; // PCB Pin 9
const uint PIN_S0_3 = 9; // PCB Pin 12

// Volatile Variablen für die Interrupt-Service-Routine
volatile uint16_t pulse_count_1 = 0;
volatile uint16_t pulse_count_2 = 0;
volatile uint16_t pulse_count_3 = 0;

// Callback-Funktion für die Interrupts
void gpio_callback(uint gpio, uint32_t events) {
	if (gpio == PIN_S0_1) {
		pulse_count_1++;
	} else if (gpio == PIN_S0_2) {
		pulse_count_2++;
	} else if (gpio == PIN_S0_3) {
		pulse_count_3++;
	}
}

int main() {
	// Initialisierung der Standard-IO (USB-Seriell)
	stdio_init_all();

	// GPIOs konfigurieren
	const uint pins[] = {PIN_S0_1, PIN_S0_2, PIN_S0_3};
	for (int i = 0; i < 3; i++) {
		gpio_init(pins[i]);
		gpio_set_dir(pins[i], GPIO_IN);
		// Externer 470 Ohm Pull-Down: Deaktivierung aller PULLS
		gpio_disable_pulls(pins[i]);

		// Interrupt bei steigender Flanke aktivieren (S0 schaltet auf 3V3)
		gpio_set_irq_enabled_with_callback(pins[i], GPIO_IRQ_EDGE_RISE,
								true, &gpio_callback);
	}

	while (true) {
		// Kontrolliere auf Kommando unf warte 1 ms (CPU sleep)
		int c = getchar_timeout_us(1000);

		if (c == 'g') {
			// Interrupts kurz anhalten für konsistentes Auslesen/Reset
			uint32_t status = save_and_disable_interrupts();

			// Ausgabe der Werte im CSV-Format: Zähler1,Zähler2,Zähler3
			printf("%u,%u,%u\n", pulse_count_1,
						pulse_count_2,
						pulse_count_3);

			// Zähler wie gewünscht zurücksetzen
			pulse_count_1 = 0;
			pulse_count_2 = 0;
			pulse_count_3 = 0;

			restore_interrupts(status);
		}
	}

	return 0;
}
