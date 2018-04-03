//Sensor Pins
int SENS1 = A3;
int SENS2 = A2;
int SENS3 = A1;
int SENS4 = A0;
int SENS5 = A7;

int SENS_Control = A4;

int SENS_MIN[5] = {1024,1024,1024,1024,1024};
int SENS_MAX[5] = {0,0,0,0,0};
int SENS_Values[5] = {0,0,0,0,0};

//motor pins
int MA1 = 4;
int MA2 = 3;
int PWMA = 5;
int MB1 = 8;
int MB2 = 9;
int PWMB = 6;
int STBY = 7;

//button pin
int BTN = 2;

//Calibration Variable

bool CAL = false;


//Controller variables
float Left_Error = 0;
float Right_Error = 0;

int Kp = 100;

int Speed = 20;

void setup() {
  pinMode(SENS1, INPUT);
  pinMode(SENS2, INPUT);
  pinMode(SENS3, INPUT);
  pinMode(SENS4, INPUT);
  pinMode(SENS5, INPUT);

  //sensor control pin

  pinMode(SENS_Control, OUTPUT);

  //turn on the sensors

  digitalWrite(SENS_Control, HIGH);

  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);

  digitalWrite(MA1, HIGH);
  digitalWrite(MA2, LOW);
  digitalWrite(MB1, HIGH);
  digitalWrite(MB2, LOW);
  //Serial port
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //calibration state
  if(!digitalRead(BTN)){
    for(int i = 0; i < 300; i++){
      SENS_Values[0] = analogRead(SENS1);
      SENS_Values[1] = analogRead(SENS2);
      SENS_Values[2] = analogRead(SENS3);
      SENS_Values[3] = analogRead(SENS4);
      SENS_Values[4] = analogRead(SENS5);
      //look for mins
      for(int j = 0; j < 5; j++){
        //looking for mininums
        if(SENS_Values[j] < SENS_MIN[j]){
         SENS_MIN[j] = SENS_Values[j];
         }//end if
         //look for maximums
         if(SENS_Values[j] > SENS_MAX[j]){
         SENS_MAX[j] = SENS_Values[j];
         }//end if
        }//end for
        delay(10);
      }//end for
    for(int j = 0; j < 5; j++){
      Serial.print(j);
      Serial.print(": ");
      Serial.print(SENS_MAX[j]);
      Serial.print(',');
      Serial.println(SENS_MIN[j]);
      }//end for
    CAL = true;
    }//end if

    //following the line
    if(CAL)
    {
      SENS_Values[0] = analogRead(SENS1);
      SENS_Values[1] = analogRead(SENS2);
      SENS_Values[2] = analogRead(SENS3);
      SENS_Values[3] = analogRead(SENS4);
      SENS_Values[4] = analogRead(SENS5);
      
      Left_Error = SENS_Values[1] - SENS_MIN[1];
      Right_Error = SENS_Values[3] - SENS_MIN[3];

      Left_Error = Left_Error/(SENS_MAX[1] - SENS_MIN[1]);
      Right_Error = Left_Error/(SENS_MAX[3] - SENS_MIN[3]);

      analogWrite(PWMB, Speed + Kp*Left_Error);
      analogWrite(PWMA, Speed + Kp*Right_Error);
    }

}
