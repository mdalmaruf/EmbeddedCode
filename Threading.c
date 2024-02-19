//How do you create a thread in C using POSIX threads?
#include <pthread.h>
#include <stdio.h>

void* threadFunction(void* arg) {
    printf("Hello from a thread!\n");
    return NULL;
}

int main() {
    pthread_t threadID;
    pthread_create(&threadID, NULL, threadFunction, NULL);
    pthread_join(threadID, NULL); // Wait for the thread to exit
    return 0;
}
