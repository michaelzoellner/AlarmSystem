#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

#include "AlarmSystem.h"
#include <TimeLib.h>


AlarmSystem::AlarmSystem()
:m_trigPin(12)
,m_echoPin(13)
,m_pirPin(5)
,m_ignoreReachAfterDoorOpen(120) // 2 minutes
,m_noReachDurationForLeave(900) // 15 minutes
,m_wifiLogOnDurationGrant(30) // seconds
,m_pirWarmUpDuration(60) // seconds
{


}



void AlarmSystem::setState(int newState) {
  m_oldState = m_state;
  m_state = newState;

}

bool AlarmSystem::checkDoor() {
  return true;
}

bool AlarmSystem::checkMotion() {
  if (now() - m_bootTime > m_pirWarmUpDuration) {
    long state = digitalRead(m_pirPin);
    if (state == HIGH) {
      Serial.println("Motion detected!");
      m_lastMotionDetected = now();
      return true;
    } else {
      Serial.println("No motion detected.");
      return false;
    }
  } else {
    Serial.println("PIR sensor still warming up...");
    return false;
  }
}

void AlarmSystem::stepMachine() {

}
