#include <CapacitiveSensor.h>
#include <Keyboard.h>

CapacitiveSensor sensors[] = {CapacitiveSensor(4,5), CapacitiveSensor(3,2)};
bool keyDown[] = {false, false};
long diff[] = {0, 0};
char letter[] = {'z', 'x'};
int threshold = 75;

void setup()                    
{
   sensors[0].set_CS_AutocaL_Millis(1000);
   sensors[1].set_CS_AutocaL_Millis(1000);
   Serial.print("start");
   Serial.begin(250000);
}

void loop()                    
{
    for (int x = 0; x < 2; x++) {
      long start = millis();
      diff[x] = sensors[x].capacitiveSensor(10);
      if (diff[x] >= threshold) {
        if (!keyDown[x]) {
          Serial.print(letter[x]);
          Serial.print(" down\t");
          Serial.print(millis() - start);
          Serial.print("\t");
          Serial.println(diff[x]);
          Keyboard.press(letter[x]);
          keyDown[x] = true;
        }
      } else{
        if (keyDown[x]) {
          Serial.print(letter[x]);
          Serial.print(" keyup\t");
          Serial.print(millis() - start);
          Serial.print("\t");
          Serial.println(diff[x]);
          Keyboard.release(letter[x]);
          keyDown[x] = false;
        }
      }
  }
}
