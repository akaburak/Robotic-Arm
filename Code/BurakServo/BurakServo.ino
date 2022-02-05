int servo_1_pin = 10; //big
int servo_3_pin = 9; //beta
int servo_2_pin = 8; //alpha
int servo_4_pin = 11; //grip
const int pulseWidth = 20000;
double degree_entry_big = 800.0;
double degree_entry_alpha = 2000.0;
double degree_entry_beta = 1200.0;
double degree_entry_grip = 2500.0;

int down = 0;
int up = 2;
int change = 4;
int mod = 0;
bool check = false;
bool check_final = true;
void setup() {

  Serial.begin(9600);
  pinMode(servo_3_pin, OUTPUT);
  pinMode(servo_2_pin, OUTPUT);
  pinMode(servo_1_pin, OUTPUT);
  pinMode(servo_4_pin, OUTPUT);
}

void loop() {
  ///////// MAİN LOOP ////////////
  for (int i = 0; i <= 10; i++) {
    PORTD |= (1 << PD0); //
    PORTD |= (1 << PD2); //
    PORTD |= (1 << PD4); //
    if (digitalRead(down) == LOW) {
      check = true;
    }

    if (degree_entry_alpha > 1840) {
      if (check == true) {
        Serial.println("buradaaaaaaaaa");
        degree_entry_alpha -= 1.0;
        degree_entry_big -= 2.0;
        degree_entry_beta -= 1.0;
      }
    }
    if (degree_entry_alpha == 1840) {
      degree_entry_grip -= 50;
    }
    if (degree_entry_grip < 0) {
      delayMicroseconds(2000);
      if (check_final == true) {
        degree_entry_alpha += 1.0;
        degree_entry_big += 2.0;
        degree_entry_beta += 1.0;
      }

      if (degree_entry_big = 800.0) {
        check_final = false;
      }
    }
    digitalWrite(servo_1_pin, HIGH);
    delayMicroseconds(degree_entry_big);
    digitalWrite(servo_1_pin, LOW);
    delayMicroseconds(pulseWidth - degree_entry_big);

    digitalWrite(servo_2_pin, HIGH);
    delayMicroseconds(pulseWidth - degree_entry_alpha);
    digitalWrite(servo_2_pin, LOW);
    delayMicroseconds(degree_entry_alpha);

    digitalWrite(servo_3_pin, HIGH);
    delayMicroseconds(degree_entry_beta);
    digitalWrite(servo_3_pin, LOW);
    delayMicroseconds(pulseWidth - degree_entry_beta);

    digitalWrite(servo_4_pin, HIGH);
    delayMicroseconds(degree_entry_grip);
    digitalWrite(servo_4_pin, LOW);
    delayMicroseconds(pulseWidth - degree_entry_grip);
  }
  Serial.println(degree_entry_big);
  Serial.println(degree_entry_alpha);
  Serial.println(degree_entry_beta);

}
