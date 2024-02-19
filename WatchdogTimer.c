// Pseudocode for setting up a watchdog timer in an embedded system
void watchdog_setup() {
    WDTCTL = WDTPW | WDTSSEL__ACLK | WDTIS__512K; // Watchdog setup with ACLK, interval 512K
    SFRIE1 |= WDTIE;                             // Enable WDT interrupt
}

// Watchdog Timer interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR(void) {
    // Reset watchdog timer
    // Typically, you would kick the watchdog like this within your main loop
    WDTCTL = (WDTCTL & 0xff) | WDTPW | WDTCNTCL;
}
