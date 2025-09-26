#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// S0 counter USB
#define CHANNELS	1 // currently limited from 1 to 9
#define VERSION		"--- S0 counter V1 with " CHANNELS " channels ---\n"

const uint LED_PIN = 16;


const uint pins[CHANNELS] = { 0 };

// Return counter value of selected channel starting by 1
// e.g.: to read channel 2 send "2"
int main()
{
	char request_state;

	pins(0) = 13; // later as for


	// define LED PIN as output
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);

	// define level pins as inputs
	gpio_init(X1_PIN);
	gpio_set_dir(X1_PIN, GPIO_IN);


	stdio_init_all();

	printf(VERSION);

	while (1) {
		scanf("%c", &request_state);
		if (request_state == 'g') {
			// LED on while working
			gpio_put(LED_PIN, 1);

			// X1
			if (gpio_get(X1_PIN)) {
				printf("1\n");
			} else {
				printf("0\n");
			}
		}
		// LED OFF
		gpio_put(LED_PIN, 0);
	} // while
} // main
