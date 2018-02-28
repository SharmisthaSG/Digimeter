#include < SoftwareSerial.h >

SoftwareSerial mySerial(10, 11); // Rx, Tx of Arduino

void setup() {
  pinMode(2, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(7, OUTPUT);

  digitalWrite(7, LOW);

  Serial.begin(57600);
  while (!Serial) {;
  }

  delay(500);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

}

int nof_pulses = 0;
int initValue, currValue;
float data = 0;
float temp;
int distance() {
  Serial.println(nof_pulses * 5.44); //Least count of the position encoder used = 5.44

  while (Serial.available() >= 0) {
    data = (nof_pulses * 5.44);
    break;
  }
  initValue = digitalRead(2);
}

""
"
This
function takes in the value corresponding to the distance covered
and compares it with the value entered by the user.
Produces a beeping sound in the buzzer
if the two values are equal
i.e The required distance has been covered.
""
"

int distance2(float check) {

  Serial.println(nof_pulses * 5.44);
  float val = nof_pulses * 5.44;

  if (val >= check) {
    Serial.println("reached");
    Serial.println("buzzerbeep");
    tone(12, 440);
    delay(500);
    tone(12, 880);
    delay(1000);
    noTone(12);
    return 1;
  }
  initValue = digitalRead(2);
  return 0;
}

void loop() {
  nof_pulses = 0;
  String s = "";
  if (mySerial.available()) //Checking connection with the Bluetooth module
  {

    char c;
    while ((c = mySerial.read())) {
      Serial.println("reading");
      s += c;
      Serial.println(s);
      delay(10);
      break;
    }

    Serial.println("Received: " + s);

    ""
    "
    Selecting Application 2:
      The device would receive user input
    for the length to be measured.
    The buzzer present would produce a temporary beeping sound after the entered length was covered.

    ""
    "

    if (s.toInt() == 2) {

      Serial.println("in app 2");
      String tomeasure = "";
      int ch1;
      delay(20000);
      tone(12, 440); //beeping sound to indicate beginning of measurement
      delay(500);
      noTone(12);

      if (mySerial.available()) {

        Serial.println("getting data");
        int ch;
        int cnt = 0;
        while ((ch = mySerial.read())) {
          cnt++;
          Serial.println(cnt);
          Serial.println("hello");
          Serial.println(ch);
          tomeasure += String(ch);
          delay(10);
          Serial.println("tomeasure" + tomeasure);
          break;
        }

        while ((ch1 = mySerial.read())) {
          break;
        }

      }

      Serial.println("gotwhat tomeasure");

      float final = tomeasure.toInt() + ch1 * 255 + ch1; // Mapping the value received by the position encoder to actual distance traversed
      Serial.println(final);
      int res = 0;
      while (res != 1) {

        while ((currValue = digitalRead(2)) == initValue)
          delay(5);

        while ((currValue = digitalRead(2)) != initValue)
          delay(5);
        ++nof_pulses;
        res = distance2(final);
      }
      Serial.print("end");
    }
  }
}
