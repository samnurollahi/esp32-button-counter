#include <Arduino.h>

void setup()
{
  Serial.begin(9600);

  pinMode(23, INPUT_PULLUP);

  Serial.println("Button Counter");
  Serial.println("Ready!");
}

unsigned long long counter = 0;
bool pressed = false;
unsigned long lastPressTime = 0;
void loop()
{
  bool btnState = digitalRead(23);
  if (!btnState && !pressed && (millis() - lastPressTime > 50))
  {
    counter++;
    Serial.print("Button pressed: ");
    Serial.println(counter);
    pressed = true;
  }
  else if (btnState)
  {
    pressed = false;
    lastPressTime = millis();
  }
}