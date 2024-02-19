//Mutexes and semaphores are synchronization primitives used to manage access to shared resources and ensure data consistency in concurrent programming. 
//Mutexes provide mutual exclusion, allowing only one thread to access a resource at a time. 
//Semaphores, on the other hand, can allow a certain number of threads to access a resource concurrently, useful for controlling access to a pool of resources or for signaling between threads.

#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);
    // Critical section
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&mutex);
}
