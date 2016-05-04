#include <CapacitiveSensor.h>
#include <Keyboard.h>

//#define debug
#define minPressTime 10
#define threshold 10

CapacitiveSensor sensors[] = {CapacitiveSensor(4,5), CapacitiveSensor(3,2)};
bool keyDown[] = {false, false};
long diff[] = {0, 0};
char letter[] = {'z', 'x'};
int pressTime[] = {0, 0};
long keyPressedTime[] = {0, 0};

void setup()
{
	#ifdef debug
		Serial.print("start");
		Serial.begin(250000);
	#endif
	Keyboard.begin();
}

#ifdef debug
void debugPrint(bool down, int x,  long start) {
	long currentTime = millis();
	Serial.print(letter[x]);
	if (down) {
		Serial.print(" keydown\t");
		keyPressedTime[x] = currentTime;
	} else {
		Serial.print(" keyup\t\t");
	}
	Serial.print(currentTime - start);
	Serial.print("\t");
	Serial.print(diff[x]);
	if (!down) {
		Serial.print("\t");
		Serial.print(currentTime - keyPressedTime[x]);
	}
	Serial.println();
}
#endif

void loop()
{
	for (int x = 0; x < 2; x++) {
		long start = millis();
		diff[x] = sensors[x].capacitiveSensorRaw(1);
		if (diff[x] >= threshold) {
			if (!keyDown[x]) {
				#ifdef debug
					debugPrint(true, x, start);
				#endif
				Keyboard.press(letter[x]);
				pressTime[x] = minPressTime;
				keyDown[x] = true;
			}
		} else {
			if (keyDown[x]) {
				if (pressTime[x]-- == 0) {
					#ifdef debug
						debugPrint(false, x, start);
					#endif
					Keyboard.release(letter[x]);
					keyDown[x] = false;
				}
			}
		}
	}
}
