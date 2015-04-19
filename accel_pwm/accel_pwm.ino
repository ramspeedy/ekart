#define POT_VOLTAGE_PIN 0
#define PWM_OUTPUT_PIN 2

void setup() {                
  Serial.begin(9600);
}



void loop() {
    

  float potVoltage = analogRead(POT_VOLTAGE_PIN);
  float vOutDutyCycle = (potVoltage/1023)*255;
  analogWrite(PWM_OUTPUT_PIN, vOutDutyCycle);
  Serial.println(potVoltage);
  //Serial.println(vOutDutyCycle);
  
  
}
