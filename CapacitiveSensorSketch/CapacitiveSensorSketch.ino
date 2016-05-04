#include <CapacitiveSensor.h>

CapacitiveSensor   cs1 = CapacitiveSensor(3,2); //2 is sensor, 3 is ground
CapacitiveSensor   cs2 = CapacitiveSensor(4,5); //5 is sensor, 4 is ground

void setup()
{
    Serial.begin(250000);
}

void loop()
{
    long start = millis();
    long total1 =  cs1.capacitiveSensorRaw(1);
    long total2 =  cs2.capacitiveSensorRaw(1);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");
    Serial.print(total1);
    Serial.print("\t");
    Serial.println(total2);
}
