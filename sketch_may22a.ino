int IR1 = 8;
int IR2 = 12;
int IR3 = 13;
int LDR = 7;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int val1;
int val2;
int val3;
int val4;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(LDR, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val1 = digitalRead(IR1);
  val2 = digitalRead(IR2);
  val3 = digitalRead(IR3);
  val4 = digitalRead(LDR);
  
  Serial.print("val1: ");
  Serial.println(val1);
  delay(1000);
  Serial.print("val4: ");
  Serial.println(val4);
  Serial.print("val2: ");
  Serial.println(val2);
  delay(1000);
  Serial.print("val3: ");
  Serial.println(val3);

  // If all IR sensors detect an object and it is dark (LDR == 1)
  if (val1 == 1 && val4 == 0 && val2 == 1 && val3 == 1) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  // If all IR sensors detect an object and it is light (LDR == 1)
  else if (val1 == 1 && val4 == 1 && val2 == 1 && val3 == 1) {
    analogWrite(led1, 20);
    analogWrite(led2, 20);
    analogWrite(led3, 20);
  }
  // If IR1 doesn't detect an object but others do, and it is light
  else if (val1 == 0 && val4 == 1 && val2 == 1 && val3 == 1) {
    analogWrite(led1, 500);
    analogWrite(led2, 20);
    analogWrite(led3, 20);
  }
  // If IR2 doesn't detect an object but others do, and it is light
  else if (val1 == 1 && val4 == 1 && val2 == 0 && val3 == 1) {
    analogWrite(led1, 20);
    analogWrite(led2, 500);
    analogWrite(led3, 20);
  }
  // If IR3 doesn't detect an object but others do, and it is light
  else if (val1 == 1 && val4 == 1 && val2 == 1 && val3 == 0) {
    analogWrite(led1, 20);
    analogWrite(led2, 20);
    analogWrite(led3, 500);
  }
}
