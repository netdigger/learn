#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include "key_event.h"

typedef void (*fn_show)();

int main() {
	KeyEvent e;
	e.Show();
	const char *path = "./libqvfb.so";
	
	void *dl;	
	fn_show fn;
	
	printf("Loading shared library [%s]...", path);
	fflush(stdout);
	
	if ((dl = ::dlopen(path, RTLD_NOW)) == NULL) {
		printf("ERROR\n  [%s]\n", dlerror());
	} else {
		printf("OK.\n");
		
		if ((fn = (fn_show)dlsym(dl, "QvfbShow")) != NULL) {
			fn();
		} else {
			printf("not found show: %s\n", dlerror());
		}
		
		dlclose(dl);
	}
}
