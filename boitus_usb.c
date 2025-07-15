#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

// boitus =^ BOIler staTUS
#define VERSION	"--- ANEWAND boitus V1 ---\n"

const uint LED_PIN = 16;
const uint X1_PIN  = 13;

// Return 0 or 1 depending if the boiler is active
// when receiving a get command ("g").
int main()
{
	char request_state;

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
