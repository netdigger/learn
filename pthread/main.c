#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Cleanup(void* arg) {
	printf("Start Clean up...\n");
}

void* RunFunc(void* arg) {
	pthread_cleanup_push(Cleanup, NULL);
	printf("In running...\n");
	sleep(1);
	printf("Finished....\n");

	pthread_cleanup_pop(1);
	return NULL;
}

int main() {
	pthread_t handle;
	pthread_create(&handle, NULL, RunFunc, NULL);
	//pthread_cancel(handle);

	getchar();
	return 0;
}
