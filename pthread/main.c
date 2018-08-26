#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex_;
sem_t sem_;

void Cleanup(void* arg) { printf("Start Clean up...\n"); }

void* RunFunc(void* arg) {
    pthread_cleanup_push(Cleanup, NULL);
    printf("In running...\n");
    sleep(1);
    printf("Finished....\n");

    pthread_cleanup_pop(1);
    return NULL;
}

void* Func2(void* arg) {
    while (1) {
        printf("Func2 post...\n");
        sem_post(&sem_);
        printf("Func2 lock...\n");
        pthread_mutex_lock(&mutex_);
        printf("Func2 locked.\n");
    }
    return NULL;
}

void* Func1(void* arg) {
    while (1) {
        printf("Func1 wait...\n");
        sem_wait(&sem_);
        printf("Func1 runing...\n");
        pthread_mutex_unlock(&mutex_);
    }
    return NULL;
}

int main() {
    sem_init(&sem_, 0, 0);
    pthread_mutex_init(&mutex_, 0);

    pthread_t handle1, handle2;
    pthread_create(&handle1, NULL, Func1, NULL);
    pthread_create(&handle2, NULL, Func2, NULL);

    getchar();
    pthread_mutex_destroy(&mutex_);
    sem_destroy(&sem_);
    return 0;
}
