#include <ESP8266WiFi.h>
#include "AlarmSystem.h"

void AlarmSystem::setState(int newState) {
  m_oldState = m_state;
  m_state = newState;
  
}

void AlarmSystem::stepMachine() {
  
}
