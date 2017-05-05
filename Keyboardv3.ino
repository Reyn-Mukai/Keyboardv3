#include <Keyboard.h>

#define debounceTime 10

/*
Buttons : LED's
1: 1 | 7
2: MOSI | 8
3: A2 | A0
4: A4 | A3
5: A5 | 0
6: 2 | A1
7: 3 | 9
8: 4 | 10
9: 5 | 11
0: 6 | 12
*/

#define BUTTON0 6
#define BUTTON1 1
#define BUTTON2 MOSI
#define BUTTON3 A2
#define BUTTON4 A4
#define BUTTON5 A5
#define BUTTON6 2
#define BUTTON7 3
#define BUTTON8 4
#define BUTTON9 5
#define LED0 12
#define LED1 7
#define LED2 8
#define LED3 A0
#define LED4 A3
#define LED5 0
#define LED6 A1
#define LED7 9
#define LED8 10
#define LED9 11

int kflag0, kflag1, kflag2, kflag3, kflag4, kflag5, kflag6, kflag7, kflag8, kflag9 = 0;
unsigned long timer0, timer1, timer2, timer3, timer4, timer5, timer6, timer7, timer8, timer9 = 0;
int key0, key1, key2, key3, key4, key5, key6, key7, key8, key9;

void setup() {
  pinMode(BUTTON0, INPUT_PULLUP);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);
  pinMode(BUTTON4, INPUT_PULLUP);
  pinMode(BUTTON5, INPUT_PULLUP);
  pinMode(BUTTON6, INPUT_PULLUP);
  pinMode(BUTTON7, INPUT_PULLUP);
  pinMode(BUTTON8, INPUT_PULLUP);
  pinMode(BUTTON9, INPUT_PULLUP);
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);

  /*if(digitalRead(BUTTON0) == HIGH && digitalRead(BUTTON1) == HIGH){
    key0 = 0x30;
    key1 = 0x31;
    key2 = 0x32;
    key3 = 0x33;
    key4 = 0x34;
    key5 = 0x35;
    key6 = 0x36;
    key7 = 0x37;
    key8 = 0x38;
    key9 = 0x39;
  }*/
  //else{
    key0 = 0xB0;
    key1 = 0x7A;
    key2 = 0x78;
    key3 = 0xD8;
    key4 = 0xD9;
    key5 = 0xD7;
    key6 = 0xB1;
    key7 = 0xC3;
    key8 = 0x63;
    key9 = 0xDA;
  //}
  Serial.begin(115200);
  Keyboard.begin();
}

void loop() {
  kbPress(BUTTON0, LED0, key0, &kflag0, &timer0);
  kbPress(BUTTON1, LED1, key1, &kflag1, &timer1);
  kbPress(BUTTON2, LED2, key2, &kflag2, &timer2);
  kbPress(BUTTON3, LED3, key3, &kflag3, &timer3);
  kbPress(BUTTON4, LED4, key4, &kflag4, &timer4);
  kbPress(BUTTON5, LED5, key5, &kflag5, &timer5);
  kbPress(BUTTON6, LED6, key6, &kflag6, &timer6);
  kbPress(BUTTON7, LED7, key7, &kflag7, &timer7);
  kbPress(BUTTON8, LED8, key8, &kflag8, &timer8);
  kbPress(BUTTON9, LED9, key9, &kflag9, &timer9);
}

void kbPress(int pin, int led, int key, int *flag, unsigned long *timer){
  if(digitalRead(pin) == LOW && *flag == 0){
    digitalWrite(led, HIGH);
    Keyboard.press(key);
    *timer = millis();
    *flag = 1;
  }
  if(digitalRead(pin) == HIGH && *flag == 1 && millis()-*timer > debounceTime){
    digitalWrite(led, LOW);
    Keyboard.release(key);
    *flag = 0;
  }
}

void writeAll(int state){
  digitalWrite(LED0,state);
  digitalWrite(LED1,state);
  digitalWrite(LED2,state);
  digitalWrite(LED3,state);
  digitalWrite(LED4,state);
  digitalWrite(LED5,state);
  digitalWrite(LED6,state);
  digitalWrite(LED7,state);
  digitalWrite(LED8,state);
  digitalWrite(LED9,state);
}

