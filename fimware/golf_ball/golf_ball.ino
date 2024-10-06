void setup() {
  pinMode(4, OUTPUT); 
  digitalWriteFast(4,LOW);
}

void loop() {
   for(uint8_t i = 0;i<8;i++){
     digitalWriteFast(4,HIGH);
     delayMicroseconds(12);
     digitalWriteFast(4,LOW);
     delayMicroseconds(12);
   }
   delayMicroseconds(650);
}
