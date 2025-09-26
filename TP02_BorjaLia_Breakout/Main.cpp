#include "Utils_Borja.h"
#include "StateManager.h"

void main() {
	while (shouldReset) {
		shouldReset = false;
		GameLoop();
	}
}