
int switchState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH); // Green LED
    digitalWrite(5, LOW); // Yellow LED
    digitalWrite(4, LOW); // Yellow LED
    digitalWrite(6, LOW); // Red LED

  }
  else {
    digitalWrite(3, HIGH); // Green LED
    digitalWrite(4, LOW); // Yellow LED
    digitalWrite(5, LOW); // Yellow LED
    digitalWrite(6, LOW); // Red LED

    delay(1000);
    // Green LED
    digitalWrite(3, LOW); 
    delay(500);
    digitalWrite(3, HIGH);
    delay(500);
    digitalWrite(3, LOW);
    delay(500);
    digitalWrite(3, HIGH); 
    delay(500);
    // First yellow LED
    digitalWrite(4, HIGH); 
    delay(500);
    digitalWrite(4, LOW);
    delay(500);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW); 
    delay(500);
    digitalWrite(4, HIGH); 
    delay(500);
    // Second yellow LED
    digitalWrite(5, HIGH); 
    delay(500);
    digitalWrite(5, LOW);
    delay(500);
    digitalWrite(5, HIGH); 
    delay(500);
    digitalWrite(5, LOW); 
    delay(500);
    digitalWrite(5, HIGH); 
    delay(500);
    // Red LED
    digitalWrite(6, HIGH); 
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
    digitalWrite(6, HIGH); 
    delay(500);
    digitalWrite(6, LOW); 
    delay(500);
    digitalWrite(6, HIGH); 
    delay(2000);
  }
}
