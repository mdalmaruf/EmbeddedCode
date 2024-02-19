typedef enum { STATE_A, STATE_B, STATE_C } State;

void handleStateA() { /* Handle State A */ }
void handleStateB() { /* Handle State B */ }
void handleStateC() { /* Handle State C */ }

void transitionState(State* currentState, State newState) {
    *currentState = newState;
}

int main() {
    State currentState = STATE_A;

    while (true) {
        switch (currentState) {
            case STATE_A:
                handleStateA();
                transitionState(&currentState, STATE_B);
                break;
            case STATE_B:
                handleStateB();
                transitionState(&currentState, STATE_C);
                break;
            case STATE_C:
                handleStateC();
                transitionState(&currentState, STATE_A);
                break;
        }
    }
}
