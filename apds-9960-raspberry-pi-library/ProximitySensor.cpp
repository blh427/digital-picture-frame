#include <iostream>
#include "APDS9960_RPi.h"

using namespace std;

// Pins
#define APDS9960_INT 7 // Needs to be an interrupt pin

// function declarations
void interruptRoutine();

// Global Variables
APDS9960_RPi apds = APDS9960_RPi();
uint8_t proximity_data = 0;
int isr_flag = 0;

void interruptRoutine() {
  isr_flag = 1;
}

int main() {

  // init wiringPi  // BLH
  wiringPiSetup();

  // Initialize Serial port
  cout << endl;
  cout << "------------------------------------" << endl;
  cout << "SparkFun APDS-9960 - ProximitySensor" << endl;
  cout << "------------------------------------" << endl;

  // Initialize interrupt service routine
  wiringPiISR(APDS9960_INT, INT_EDGE_FALLING,  interruptRoutine);
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    cout << "APDS-9960 initialization complete" << endl;
  } else {
    cout << "Something went wrong during APDS-9960 init!" << endl;
  }

  // Adjust the Proximity sensor gain
  if ( !apds.setProximityGain(PGAIN_2X) ) {
    cout << "Something went wrong trying to set PGAIN" << endl;
  }

  // Start running the APDS-9960 proximity sensor (no interrupts)
  //	if ( apds.enableProximitySensor(false) ) {
  //	if ( apds.enableProximitySensor(false) ) {
  if (apds.enableProximitySensor(true) ) {
    cout << "Proximity sensor is now running" << endl;
  } else {
    cout << "Something went wrong during sensor init!" << endl;
  }

  while(1) {

    // Read the proximity value
    if ( !apds.readProximity(proximity_data) ) {
      cout << "Error reading proximity value" << endl;
    } else {
      cout << "Proximity: ";
      cout << int(proximity_data) << endl;
    }

    // Wait 250 ms before next reading
    delay(250);
    // Check to see if an interrupt fired.
    if (isr_flag) {
      printf("i!\n");
      isr_flag = 0;
    }
  }
  return 0;
}
