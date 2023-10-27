#include "at89c51ed2.h"
#include "stdint.h"

/**
 * @brief Initialises the UART to use the Internal BRG and sets the baud rate to 57600.
 * 
 */
void init_uart();

/**
 * @brief This function is called when Fclk is at minimum. This sets the UART baud rate to 1355bps
 * 
 */
void init_uart_slow();

/**
 * @brief Initalises the clock in X2 mode and at full frequency.
 * 
 */
void init_clocks();
/**
 * @brief Intialises the INT0 as a falling edge trigger.
 * 
 */
void init_INT0();

/**
 * @brief Resets the watchdog timer.
 * 
 */
void reset_WDT();
