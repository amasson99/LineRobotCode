int SENS1 = A3;
int SENS2 = A2;
int SENS3 = A1;
int SENS4 = A0;
int SENS5 = A7;

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

int SENS1_Cal = 0;
int SENS2_Cal = 0;
int SENS3_Cal = 0;
int SENS4_Cal = 0;
int SENS5_Cal = 0;

int SENS_Control = A4;

int Line = 0;

int MA1 = 4;
int MA2 = 3;
int PWMA = 5;
int MB1 = 8;
int MB2 = 9;
int PWMB = 6;
int STBY = 7;

void setup() 
{
  pinMode(SENS1, INPUT);
  pinMode(SENS2, INPUT);
  pinMode(SENS3, INPUT);
  pinMode(SENS4, INPUT);
  pinMode(SENS5, INPUT);

  pinMode(SENS_Control, OUTPUT);

  digitalWrite(SENS_Control, HIGH);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);

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

  Serial.begin(9600);
}

void loop() 
{
  Serial.print(analogRead(SENS1));
  Serial.print(',');
  Serial.print(analogRead(SENS2));
  Serial.print(',');
  Serial.print(analogRead(SENS3));
  Serial.print(',');
  Serial.print(analogRead(SENS4));
  Serial.print(',');
  Serial.println(analogRead(SENS5));

  if(analogRead(SENS1) > 900){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    analogWrite(PWMB, 100);
    analogWrite(PWMA, 0);
    }
   if(analogRead(SENS2) > 900){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    analogWrite(PWMB, 100);
    analogWrite(PWMA, -100);
    }
    if(analogRead(SENS3) > 900){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    analogWrite(PWMB, 100);
    analogWrite(PWMA, 100);
    }
    if(analogRead(SENS4) > 900){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    analogWrite(PWMB, 0);
    analogWrite(PWMA, 100);
    }
    if(analogRead(SENS5) > 900){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    analogWrite(PWMB, 0);
    analogWrite(PWMA, 100);
    }
}
