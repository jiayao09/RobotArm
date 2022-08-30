#include <Servo.h>
void armDataCmd(char serialCmd);
void reportStatus();
void armIniPos();
void action();
void armJoyCmd(char serialCmd);
int checkStatus(int servoData, int maxInput, int minInput);
void servoCmd(char serialName, int servoData, int Delay);
Servo base, fArm, rArm, claw;

int basePos = 90;
int rArmPos = 90;
int fArmPos = 90;
int clawPos = 50;

int DSD = 15;  // Defailt Servo Delay

const int baseMin = 30;
const int baseMax = 150;
const int rArmMin = 45;
const int rArmMax = 130;
const int fArmMin = 45;
const int fArmMax = 150;
const int clawMin = 0;
const int clawMax = 50;

bool mode; // mode = 1: command contorl, mode = 0: keyboard control
int moveStep = 3;

void setup() {
  base.attach(11);     // base 伺服舵机连接引脚11 舵机代号'b'
  delay(200);
  rArm.attach(10);     // rArm 伺服舵机连接引脚10 舵机代号'r'
  delay(200);
  fArm.attach(9);      // fArm 伺服舵机连接引脚9  舵机代号'f'
  delay(200);
  claw.attach(6);      // claw 伺服舵机连接引脚6  舵机代号'c'
  delay(200);
  
  base.write(basePos);
  delay(10);
  fArm.write(fArmPos);
  delay(10);
  rArm.write(rArmPos);
  delay(10);
  claw.write(clawPos);
  delay(10);
  
  Serial.begin(9600);
  Serial.println("Input control signal");
}

void loop() {
  if (Serial.available()>0){
    char serialCmd = Serial.read();
    if(mode == 1){
      armDataCmd(serialCmd);
    } else{
      armJoyCmd(serialCmd);
    }
  }
}

void armDataCmd(char serialCmd){
  Serial.print("Serial commod = ");
  Serial.print(serialCmd); 
  Serial.print("     "); 
  if (serialCmd == 'b' || serialCmd == 'c' || serialCmd == 'f' || serialCmd == 'r'){
      int servoData = Serial.parseInt();
      servoCmd(serialCmd, servoData, DSD);
  } else {
  switch(serialCmd){
    case 'o':
      reportStatus();
      break;
    case 'i':
      armIniPos();
      break;
    case 'a':
        action();
        break;
    case 'm':
      mode = 0;
      Serial.println("Command: Switch mode");
      break;   
    default:
      Serial.println("Unknown Command");
    }
  }
}

void armJoyCmd(char serialCmd){
  int baseJoyPos;
  int rArmJoyPos;
  int fArmJoyPos;
  int clawJoyPos;
  switch(serialCmd){
    case 'a':
      baseJoyPos = base.read() - moveStep;
      servoCmd('b', baseJoyPos, DSD);
      break;
    case 'd':
      baseJoyPos = base.read() + moveStep;
      servoCmd('b', baseJoyPos, DSD);
      break;
    case 'w':
      rArmJoyPos = rArm.read() + moveStep;
      servoCmd('r', rArmJoyPos, DSD);
      break;
    case 's':
      rArmJoyPos = rArm.read() - moveStep;
      servoCmd('r', rArmJoyPos, DSD);
      break;
    case 'e':
      fArmJoyPos = fArm.read() + moveStep;
      servoCmd('f', fArmJoyPos, DSD);
      break;
    case 'f':
      fArmJoyPos = fArm.read() - moveStep;
      servoCmd('f', fArmJoyPos, DSD);
      break;
    case 'r':
      clawJoyPos = claw.read() + moveStep;
      servoCmd('c', clawJoyPos, DSD);
      break;
    case 't':
      clawJoyPos = claw.read() - moveStep;
      servoCmd('c', clawJoyPos, DSD);
      break;
    case 'm':
      mode = 1;
      Serial.println("Command: Switch mode");
      break;
    case 'o':
      servoCmd('b', basePos, DSD);
      servoCmd('r', fArmPos, DSD);
      servoCmd('f', rArmPos, DSD);
      servoCmd('c', 0, DSD);     
    case 'i':
      armIniPos();
      break;      
    default:
      Serial.println("Unknown Command");
  }
}
    
void action(){
  armIniPos();
  delay(2000);
  int robotactionArray[4][3] = {
    {'c',0,DSD},
    {'b',120,DSD},
    {'f',120,DSD},
    {'r',45,DSD},
  };
  for(int i = 0; i < 4; i++){
    servoCmd(robotactionArray[i][0], robotactionArray[i][1], robotactionArray[i][2]);
    delay(200);
  }
}
  
void armIniPos(){
  servoCmd('b', basePos, DSD);
  servoCmd('r', fArmPos, DSD);
  servoCmd('f', rArmPos, DSD);
  servoCmd('c', clawPos, DSD);
}

void reportStatus(){
  Serial.println("++++++++++ Robot-Arm Status Report +++++");
  Serial.print("Claw Postition: clawPos = "); Serial.println(claw.read());
  Serial.print("Base Position: basePos = "); Serial.println(base.read());
  Serial.print("Rear Arm Position : rArmPos = "); Serial.println(rArm.read());
  Serial.print("Front Arm Position : fArmPos = "); Serial.println(fArm.read());  
  Serial.println("++++++++++++++++++++++++++++++++++++++++");
}

int checkStatus(int servoData, int maxInput, int minInput){
  int servo = 0;
  if (servoData >= minInput && servoData <= maxInput) {
    servo = servoData;
  } else if (servoData < minInput) {
    servo = minInput;
    Serial.println(" "); Serial.print("Warning: Servo Value is out of Limit!");
    Serial.print("Choose range between "); Serial.print(minInput);Serial.print(" and ");Serial.println(maxInput);
  }
  else {
    servo = maxInput;
    Serial.print("Warning: Servo Value is out of Limit! ");
    Serial.print("Choose range between "); Serial.print(minInput);Serial.print(" and ");Serial.println(maxInput);
  }
  Serial.print("Target angle = "); 
  Serial.println(servo); 
  return(servo);
}


void servoCmd(char serialName, int servoData, int Delay){
  Servo servo2go;
  int fromPos;
  int toPos;
  switch(serialName){
    case 'b':
      servo2go = base;
      fromPos = base.read();
      toPos = checkStatus(servoData, baseMax, baseMin);
      break;
    case 'r':
      servo2go = rArm;
      fromPos = rArm.read();
      toPos = checkStatus(servoData, rArmMax, rArmMin);
      break;
    case 'f':
      servo2go = fArm;
      fromPos = fArm.read();
      toPos = checkStatus(servoData, fArmMax, fArmMin);
      break;
    case 'c':
      servo2go = claw;
      fromPos = claw.read();
      toPos = checkStatus(servoData, clawMax, clawMin);
      Delay = 1;
      break;
  }
  
  if (fromPos <= toPos){
    for(int i = fromPos; i<= toPos; i++){
      servo2go.write(i);
      delay(Delay);
    } 
  }  else {
      for(int i = fromPos; i >= toPos; i--){
      servo2go.write(i);
      delay(Delay);
      }
  }
}
