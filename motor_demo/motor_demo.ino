int MB1 = 8;
int MB2 = 9;
int PWMB = 6;
int STBY = 7;

void spin_up_down();

void setup() 
{
  // Setup output pins
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(STBY, OUTPUT);
  pinMode(PWMB, OUTPUT);

  // Set spin direction  
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);

  // Take H-Bridge out of standby
  digitalWrite(STBY, HIGH);

  // Motor short brake
  analogWrite(PWMB, 0);

  // Start serial communication
  Serial.begin(115200);
}

void loop() 
{
  // spin up CW
  // Set spin direction  
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
  // loop through different PWMs
  spin_up_down();

  // spin up CCW
  // Set spin direction  
  digitalWrite(MB1, LOW);
  digitalWrite(MB2, HIGH);
  // loop through different PWMs
  spin_up_down();
}

void spin_up_down()
{
  for(int counter = 0; counter < 256; counter++)
  {
    // update speed
    analogWrite(PWMB, counter);
    // print out speed
    Serial.println(counter);
    // wait 25 ms
    delay(25);  
  }

  for(int counter = 255; counter > 0; counter--)
  {
    // update speed
    analogWrite(PWMB, counter);
    // print out speed
    Serial.println(counter);
    // wait 25 ms
    delay(25);  
  }
}

