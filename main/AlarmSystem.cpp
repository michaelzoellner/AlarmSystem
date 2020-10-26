#include <ESP8266WiFi.h>
#include "AlarmSystem.h"
#include <Time.h>


AlarmSystem::AlarmSystem()

{


}



void AlarmSystem::setState(int newState) {
  m_oldState = m_state;
  m_state = newState;

}

bool AlarmSystem::checkDoor() {
  val

}

bool AlarmSystem::checkMotion() {
  if (now() - m_bootTime > m_pirWarmUpDuration) {
    long state = digitalRead(m_pirPin);
    if (state == HIGH) {
      Serial.println("Motion detected!")
      m_lastMotionDetected = now();
      return true;
    } else {
      Serial.println("No motion detected.")
      return false;
    }
  } else {
    Serial.println("PIR sensor still warming up...")
    return false;
  }
}


}

void AlarmSystem::stepMachine() {

}
