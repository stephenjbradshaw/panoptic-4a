const int ledPin = 13;
const int relay1 = 4;
const int relay2 = 7;
const int relay3 = 8;
const int relay4 = 12;
const int relay5 = 2;
const int relay6 = 3;
const int relay7 = 5;
const int relay8 = 6;
const int footswitch = 9;

int serialvalue;
int started = 0; // flag for whether we've received serial yet

void setup()
{
  Serial.begin(57600);
  pinMode(13, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, INPUT);
}

void loop()
{
  Serial.print("Distance ");
  Serial.print(analogRead(A0));
  Serial.println();
  Serial.print("Footswitch ");
  Serial.print(digitalRead(footswitch));
  Serial.println();
  delay(2); // wait to let ADC stabilise
  
  if (Serial.available()) // check to see if there's serial data in the buffer
  {
    serialvalue = Serial.read(); // read a byte of serial data
    started = 1;
  }

  // loop once serial data has been received
  if (started)
  {
    if (serialvalue == 11)
    {
      digitalWrite(relay1, HIGH);
    }
    if (serialvalue == 10)
    {
      digitalWrite(relay1, LOW);
    }
    if (serialvalue == 21)
    {
      digitalWrite(relay2, HIGH);
    }
    if (serialvalue == 20)
    {
      digitalWrite(relay2, LOW);
    }
    if (serialvalue == 31)
    {
      digitalWrite(relay3, HIGH);
    }
    if (serialvalue == 30)
    {
      digitalWrite(relay3, LOW);
    }
    if (serialvalue == 41)
    {
      digitalWrite(relay4, HIGH);
    }
    if (serialvalue == 40)
    {
      digitalWrite(relay4, LOW);
    }
    if (serialvalue == 51)
    {
      digitalWrite(relay5, HIGH);
    }
    if (serialvalue == 50)
    {
      digitalWrite(relay5, LOW);
    }
    if (serialvalue == 61)
    {
      digitalWrite(relay6, HIGH);
    }
    if (serialvalue == 60)
    {
      digitalWrite(relay6, LOW);
    }
    if (serialvalue == 71)
    {
      digitalWrite(relay7, HIGH);
    }
    if (serialvalue == 70)
    {
      digitalWrite(relay7, LOW);
    }
    if (serialvalue == 81)
    {
      digitalWrite(relay8, HIGH);
    }
    if (serialvalue == 80)
    {
      digitalWrite(relay8, LOW);
    }
  }
}
