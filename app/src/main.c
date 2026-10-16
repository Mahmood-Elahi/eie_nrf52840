/**
 * @file main.c
 */

#include <inttypes.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 1000

int main(void) {
    printk("Lesson 3: Program starting\n");

    if (BTN_init() < 0) {
        printk("Button initialization failed\n");
        return 0;
    }

    if (LED_init() < 0) {
        printk("LED initialization failed\n");
        return 0;
    }

    printk("Initialization complete\n");

    int counter = 0;

    while (1) {
        printk("Before increment: %d\n", counter);

        counter++;

        printk("After increment: %d\n", counter);

        k_msleep(SLEEP_MS);
    }

    return 0;
}
