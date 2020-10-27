
class AlarmSystem
{
public:
  AlarmSystem();   // Konstruktor

  // Setting PINs
  const int m_trigPin;
  const int m_echoPin;
  const int m_pirPin;

  // Parameters
  const int m_ignoreReachAfterDoorOpen;
  const int m_noReachDurationForLeave;
  const int m_wifiLogOnDurationGrant;
  const int m_pirWarmUpDuration;

  // Resident addresses
  //Vector<IPAddress> m_addresses;
  //m_addresses.push_back(IPAddress(192,168,178,20));
  //m_addresses.push_back(IPAddress(192,168,178,125));

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
  bool checkDoor();
  bool checkMotion();
  void resetSystem();

private:

};
