/*
* Main Logic to Control DC Motor Speed
* author: ram menon 
* date: 6/28/15
*/

#define POT_VOLTAGE_PIN 0
#define TEMP_VOLTAGE_PIN 1
#define CURRENT_SENSOR_PIN 2
#define PWM_OUTPUT_PIN 3
#define MAX_POT_DELTA 10.0
#define MAX_SAFE_TEMP 1000
#define MAX_SAFE_CURRENT 1000

void setup() {                
  Serial.begin(9600);
}



void loop() {
  static float prevPotVoltage = 0.0;
  
  //read throttle position
  float potVoltage = analogRead(POT_VOLTAGE_PIN);
  
  //compare to previous position
  float diffVoltage = (potVoltage - prevPotVoltage); 
  
  //apply ramp up/down limitations
  if(abs(diffVoltage) > MAX_POT_DELTA) {
    potVoltage += (diffVoltage/abs(diffVoltage))*MAX_POT_DELTA;
  }
  
  
  //safety checks
  
  //temperature
  float temp = analogRead(TEMP_VOLTAGE_PIN);
  if(temp > MAX_SAFE_TEMP) {
    potVoltage = 0.0;
  }

  //current limits
  float current = analogRead(CURRENT_SENSOR_PIN);
  if(temp > MAX_SAFE_CURRENT) {
    potVoltage = 0.0;
  }
  
  
  //calculate and output PWM signal
  float vOutDutyCycle = (potVoltage/1023)*255;
  analogWrite(PWM_OUTPUT_PIN, vOutDutyCycle);
  prevPotVoltage = potVoltage;
}
