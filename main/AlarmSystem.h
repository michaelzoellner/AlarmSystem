#include <ESP8266WiFi.h>
#include <Pinger.h>
#include <ArduinoSTL.h>

class AlarmSystem
{
public:
  AlarmSystem()   // Konstruktor

  // Setting PINs
  const int m_trigPin = 12;
  const int m_echoPin = 13;
  const int m_pirPin = 5;

  // Parameters
  const int m_ignoreReachAfterDoorOpen = 2 * 60 * 1000; // 2 minutes
  const int m_noReachDurationForLeave = 15 * 60 * 1000; // 15 minutes
  const int m_wifiLogOnDurationGrant = 30 * 1000; // 30 seconds

  // Resident addresses
  Vector<IPAddress> m_addresses;
  m_addresses.push_back(IPAddress(192,168,178,20));
  m_addresses.push_back(IPAddress(192,168,178,125));

  // Operating variables
  float m_bootTime;
  bool m_motionDetected;
  int m_lastMotionDetected;
  bool m_doorOpen;
  int m_lastDoorClosed;
  int m_state;
  int m_oldState;

  void setState(int newState);
  void stepMachine();
  void checkDoor();
  void checkMotion();
  void resetSystem();

private:

}
