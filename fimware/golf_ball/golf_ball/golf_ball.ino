long adc;
int loop_count = 0;
void setup() {
  pinMode(2, OUTPUT); //LED
  pinMode(3, OUTPUT); //MOSFET
  pinMode(4, INPUT); //ADC

  digitalWriteFast(2, LOW);
  digitalWriteFast(3, LOW);
}

void loop() {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWriteFast(3, HIGH);
    delayMicroseconds(12);
    digitalWriteFast(3, LOW);
    delayMicroseconds(12);
  }

  //Takes aproximatli100uS

  adc += analogRead(4);
  if (loop_count == 1000) {
    adc = adc / 1000;

    if (adc < 660) {
      digitalWriteFast(2, HIGH);
      if (adc < 530) {
        while (true) {
          digitalWriteFast(2, HIGH);
          delay(100);
          digitalWriteFast(2, LOW);
          delay(1000);
        }
      }
    }
    else {
      digitalWriteFast(2, LOW);
    }
    loop_count = 0;
  }


  delayMicroseconds(550);


  loop_count++;
}
