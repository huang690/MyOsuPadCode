#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(3,2); //2 is sensor, 3 is ground
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,5); //5 is sensor, 4 is ground

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(1000);
   cs_4_6.set_CS_AutocaL_Millis(1000);
   Serial.begin(250000);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(10);
    long total2 =  cs_4_6.capacitiveSensor(10);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");
    Serial.print(total1);
    Serial.print("\t");
    Serial.println(total2);
}
