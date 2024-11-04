#define ENA 3        
#define IN1 5        
#define IN2 6        
#define IN3 9      
#define IN4 10       
#define ENB 11      

#define irLeft A0   
#define irRight A1   

int threshold = 500; 

void setup() {
  
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  
  
  Serial.begin(9600);
}

void loop() {
 
  int leftSensorValue = analogRead(irLeft);
  int rightSensorValue = analogRead(irRight);

  
  Serial.print("Left Sensor: ");
  Serial.print(leftSensorValue);
  Serial.print("\tRight Sensor: ");
  Serial.println(rightSensorValue);

 
  if (leftSensorValue > threshold && rightSensorValue > threshold) {
    
    moveForward();
  } else if (leftSensorValue > threshold) {
    
    turnRight();
  } else if (rightSensorValue > threshold) {
    
    turnLeft();
  } else {
   
    stopMotors();
  }

  delay(100); 
}


void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}


void turnLeft() {
  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
}


void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, HIGH);
}


void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
