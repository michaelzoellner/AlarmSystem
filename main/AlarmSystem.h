#include <ESP8266WiFi.h>
#include <Pinger.h>
#include <ArduinoSTL.h>

class AlarmSystem
{
public:
  AlarmSystem()   // Konstruktor
  int m_ignoreReachAfterDoorOpen = 2; // minutes
  int m_noReachDurationForLeave = 15; // minutes
  int m_wifiLogOnDurationGrant = 30; // seconds
  bool m_motionDetected;
  int m_lastMotionDetected;
  bool m_doorOpen;
  int m_lastDoorOpen;
  int m_state;
  int m_oldState:
  Vector<IPAddress> m_addresses;
  m_addresses.push_back(IPAddress(192,168,178,20));
  m_addresses.push_back(IPAddress(192,168,178,125));

  void setState(int newState);
  void stepMachine();

private:

}
