int button_status = 0;
int active_leds = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT); 
}

void loop() {
  button_status = digitalRead(2);
  if(button_status==HIGH) {
    active_leds++;
  }

  if(active_leds>3) {
    active_leds = 0;
  }

  switch(active_leds) {
    case 1:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    break;
    case 2:
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
    break;
    case 3:
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
    break;
    default:
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    break;
  }
  
  delay(400);
}
