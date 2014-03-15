#include <SoftwareSerial.h>

// Blueduino comunicate with BLE module through pin11, pin12 as soft serial.
SoftwareSerial mySerial(11, 12); //RX,TX

String tmp; 

void setup() {
  // It's just for test with "Serial Monitor" of Arduino IDE. It can be removed.
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("hello!");
  
  // Start soft serial
  mySerial.begin(9600); 
};

void loop() {
  // Read soft serial
  while (mySerial.available() > 0)  {
    tmp += char(mySerial.read());
    delay(2);
  }

  // If it got data from soft serial port then display on "Serial Monitor"
  if(tmp.length() > 0) {
    Serial.println(tmp);
    tmp = "";
  }

  // If it got data from hard serial port, then write data to soft serial port.
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
