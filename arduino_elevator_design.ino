const int motorPin1 = 8;  
const int motorPin2 = 9;  

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;

const int led1 = 5;
const int led2 = 6;
const int led3 = 7;

int currentFloor = 1;

void setup() {
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  updateLEDs();  
}

void loop() {
  int targetFloor = currentFloor;

  if (digitalRead(button1) == HIGH) {
    targetFloor = 1;
  } else if (digitalRead(button2) == HIGH) {
    targetFloor = 2;
  } else if (digitalRead(button3) == HIGH) {
    targetFloor = 3;
  }

  if (targetFloor != currentFloor) {
    moveToFloor(targetFloor);
    currentFloor = targetFloor;
    updateLEDs();
  }
}

void moveToFloor(int targetFloor) {
  int delayPerFloor = 2000; 

  int floorDiff = targetFloor - currentFloor;

  if (floorDiff > 0) {
   
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(delayPerFloor * floorDiff);
  } else if (floorDiff < 0) {
   
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(delayPerFloor * abs(floorDiff));
  }

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void updateLEDs() {
  digitalWrite(led1, currentFloor == 1 ? HIGH : LOW);
  digitalWrite(led2, currentFloor == 2 ? HIGH : LOW);
  digitalWrite(led3, currentFloor == 3 ? HIGH : LOW);
}
