#include <ESP8266WiFi.h>
#include "AlarmSystem.h"

void AlarmSystem::setState(int newState) {
  m_oldState = m_state;
  m_state = newState;
  
}

bool AlarmSystem::checkDoor() {
  val 
  
}

bool AlarmSystem::checkMotion() {
  val pirSensor = digitalRead(m_pirPin);
  if (val==1) {
    m_lastMotionDetected = now();
    return 1; 
  }  else {
    return 0;
  }
}
    
    
}

void AlarmSystem::stepMachine() {
  
}
