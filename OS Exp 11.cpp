#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    printf("Hello from Thread %d\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    pthread_create(&thread1, NULL, threadFunction, &id1);
    pthread_create(&thread2, NULL, threadFunction, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main Thread finished.\n");
    return 0;
}
