#include "touch_event.h"
#include <stdio.h>

TouchEvent::TouchEvent() {}

void TouchEvent::Show() {
	::printf("TouchEvent Show\n");
}

void TouchEvent::Display() {
	::printf("TouchEvent Display\n");
}
