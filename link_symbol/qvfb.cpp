#include "touch_event.h"

extern "C" void QvfbShow() {
	TouchEvent e;
	e.Show();
	e.Display();
}
