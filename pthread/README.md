# Linux Threads

## How to clean up a thread when it is canceled?

Use *pthread_cleanup_push* to set the cleanup handler.
Use *pthread_cleanup_pop* to decide how to call the cleanup handler 

