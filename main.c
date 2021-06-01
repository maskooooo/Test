#include "led.h"
#include "keyboard.h"

enum LedState{LED_LEFT, LED_RIGHT, LED_STOP};

void Delay(int ms){
	int wait1;
	int wait2;
	for (wait1 = 0; wait1 < ms; wait1++){
		for (wait2 = 0; wait2 < 6000; wait2++){}
	}
}


int main(void){
	enum LedState eLedState = LED_STOP;
	KeyboardInit();
	LedInit();
	
	while(1){
		switch(eLedState){
			case LED_LEFT:
				LedStepLeft();
				if (KeyboardRead() == BUTTON_1){
						eLedState = LED_STOP;
				}
				break;
			case LED_STOP:
				if (KeyboardRead() == BUTTON_2){
					eLedState = LED_RIGHT;
				}
				else if (KeyboardRead() == BUTTON_0){
					eLedState = LED_LEFT;
					}
				break;
			case LED_RIGHT:
				LedStepRight();
				if (KeyboardRead() == BUTTON_1){
					eLedState = LED_STOP;
				}
				break;
		}
		Delay(100);
	}
}
