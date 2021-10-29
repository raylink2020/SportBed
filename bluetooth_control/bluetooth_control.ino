int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;
int driverPUL = 7;
int driverDIR = 6;

char state = 'N'; 
int pd = 500; //pulse delay period
int setspeed = 50;
boolean stepperleft = LOW;
boolean stepperright = LOW;

void setup() {
  pinMode(motor1pin1, OUTPUT); 
  pinMode(motor1pin2, OUTPUT); 
  pinMode(motor2pin1, OUTPUT); 
  pinMode(motor2pin2, OUTPUT); 
  pinMode(driverPUL, OUTPUT);
  pinMode(driverDIR, OUTPUT);
  Serial.begin(9600); //communication rate of bluetooth module
}

//BEFORE UPLOADING SKETCH HAVE TXD AND RXD WIRES UNPLUGGED FROM ARDUINO 

// LIGHTS //
void loop() {
  if(Serial.available()>0){ //checks if data is coming from serial
    state = Serial.read(); // reads data from serial port
    Serial.print(state); 
  }
  if(state == 'U'){
    // Linear actuator 1 up
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  }
  else if(state == 'D'){  
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);  // linear acuator 1 down 
  }
  else if(state =='u'){
    // linear actuator 2 up
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
  }
   else if(state =='d'){
    // linear actuator 2 down  
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  } 
   else if(state =='X'){
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    stepperleft = LOW;
    stepperright = LOW;
   }
   else if(state =='Q'){ // Q is fast mode for stepper
    // Sport mode 
    //changes variable speed to equal higher value
    setspeed = 50;
    
  }
   else if(state =='S'){
    // Regular mode 
    //changes variable speed to equal smaller (normal) value
    setspeed = 1000;
  }
  else if(state =='q'){ //stepper goes left
    stepperright = LOW;
    stepperleft = HIGH;
  }
  else if(state =='s'){//stepper goes right
    stepperleft = LOW;
    stepperright = HIGH;
  }
  while (stepperright = HIGH){
  digitalWrite(driverDIR, LOW); //change low to high if going in wrong direction, do same for other direction loop.
  digitalWrite(driverPUL, HIGH);
  delayMicroseconds(setspeed);
  digitalWrite(driverPUL, LOW);
  delayMicroseconds(setspeed);
  }
  while (stepperleft = HIGH){
  digitalWrite(driverDIR, HIGH); //change low to high if going in wrong direction, do same for other direction loop.
  digitalWrite(driverPUL, HIGH);
  delayMicroseconds(setspeed);
  digitalWrite(driverPUL, LOW);
  delayMicroseconds(setspeed);
  }
}
