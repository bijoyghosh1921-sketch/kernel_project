#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Hardware text mode color constants. */
enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_WHITE = 15,
};

static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}

void kernel_main(void) {
    /* VGA text buffer starting address */
    volatile uint16_t* buffer = (volatile uint16_t*) 0xB8000;

    /* Clear the screen (80x25 grid) with black background */
    for (size_t y = 0; y < 25; y++) {
        for (size_t x = 0; x < 80; x++) {
            const size_t index = y * 80 + x;
            buffer[index] = vga_entry(' ', vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK));
        }
    }

    /* Message to print */
    const char* str = "Hello World! Bare-Metal Microkernel Booting...";
    uint8_t color = vga_entry_color(VGA_COLOR_GREEN, VGA_COLOR_BLACK);

    /* Write characters directly to video memory */
    for (size_t i = 0; str[i] != '\0'; i++) {
        buffer[i] = vga_entry(str[i], color);
    }
}