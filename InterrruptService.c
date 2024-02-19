// Example usage of volatile keyword
volatile int flag = 0;

void interrupt_service_routine() {
    flag = 1; // Set flag in ISR
}

int main() {
    while (!flag) {
        // Wait for flag to be set in ISR
    }
    // Proceed after flag is set
}
