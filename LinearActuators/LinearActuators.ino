/*  
 *  Controlling DC Linear Actuators with L298N Motor Driver
 *  Without Speed Changes
 *  Credit to Ryan Chan -- July 17, 2020 -- Tutorial
 *  created 2021
 *  Raymond Link
 */ 

 //define pins that L298N are inserted in
 int motor1pin1 = 2;
 int motor1pin2 = 3;

 int motor2pin1 = 4;
 int motor2pin2 = 5;

 void setup() {
  //define pin modes to be outputs (controlling the motors)
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
 }
 
 void loop() {
  //uncomment these voids to run the loops of what you need
  inoutboth();
  //oneinoneout();
  //bothbackin();
  //BLEControl();
 }

 void inoutboth() {
  //making pin1 HIGH and pin2 LOW causes the polarity to be pos on pin1
  //and neg on pin2, if you flip it, the motor will spin opposite.
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(10000);

  //now the opposite direction for 10s
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(10000);
 }

 void oneinoneout() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(10000);

  //now the opposite direction for 10s
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(10000);
 }

 void bothbackin() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(20000);
 }
