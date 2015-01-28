/* Light flashing programme for child's toy project, cobbled together by Phil Saunders
 *Flash sequence built from the following 
 *Knight Rider 1
 * Basically an extension of Blink_LED.
 * (cleft) 2005 K3, Malmo University
 * @author: David Cuartielles
 * @hardware: David Cuartielles, Aaron Hallborg
 * Button Change adapted from  http://arduino.cc/en/Tutorial/ButtonStateChange 
 */

// set 5 x LED pins (12-8), timer as an easy to change variable for flashing and 5 x Switch Pins (A0-A4)
 
const int LED1 = 12;
const int LED2 = 11;
const int LED3 = 10;
const int LED4 = 9;
const int LED5 = 8;
const int timer = 250;
const int longtimer = 1000;
const int SW1 = A0;
const int SW2 = A1;
const int SW3 = A2;
const int SW4 = A3;
const int SW5 = A4;

// set states for each of the switches to be read later

int SW1state = 0; // variable for state of switch 1
int SW2state = 0; // variable for state of switch 2
int SW3state = 0; // variable for state of switch 3
int SW4state = 0; // variable for state of switch 4
int SW5state = 0; // variable for state of switch 5

//set up last states for switches

int SW1last = 0; // last state of switch 1
int SW2last = 0; // last state of switch 2
int SW3last = 0; // last state of switch 3
int SW4last = 0; // last state of switch 4
int SW5last = 0; // last state of switch 5

// set pinmodes for the LEDs (outputs) and Switches (inputs)

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
  pinMode(SW5, INPUT);
}

void loop() {
  
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
  
  
  // check to see if switch 1 is on. If so, commence flashing
  
  if (SW1state == HIGH) { // if switch 1 on, flash LED 1
  
   digitalWrite(LED1, HIGH);
   delay(timer);
   digitalWrite(LED1, LOW);
   delay(longtimer);
 
switchcheck (); // read the states of all the switches
switchchange (); // look for any switch changes

// check to see if switch 2 is on. If so, commence flashing

 if (SW2state == HIGH) { // if switch 2 only on just flash LED 2 twice
  
 flashLED2 (); // flash LED 2
   digitalWrite(LED2, HIGH);
   delay(timer);
   digitalWrite(LED2, LOW);
   delay(longtimer);
   
  }

switchcheck (); // read the states of all the switches
switchchange (); // look for any switch changes

  // check to see if switch 3 is on. If so, commence flashing

if (SW3state == HIGH) { // if switch 3 only on just flash LED 3 thrice
  
 flashLED3 (); // flash LED 3
 flashLED3 (); // flash LED 3
 flashLED3 (); // flash LED 3
   digitalWrite(LED3, HIGH);
   delay(timer);
   digitalWrite(LED3, LOW);
   delay(longtimer);
   
  }
  
switchcheck (); // read the states of all the switches
switchchange (); // look for any switch changes
  
  // check to see if switch 4 is on. If so, commence flashing
  
 if (SW4state == HIGH) { // if switch 4 only on just flash LED 4 fourice
  
flashLED4 (); // flash LED 4
flashLED4 (); // flash LED 4
flashLED4 (); // flash LED 4
   digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(longtimer);
  }  
  // read all the switch states
  
switchcheck (); // read the states of all the switches
switchchange (); // look for any switch changes
  
  // check to see if switch 5 is on. If so, commence flashing
  
  if (SW5state == HIGH) { // if switch 5 only on just flash LED 5 fivice
  
 flashLED5 (); // flash LED 5
 flashLED5 (); // flash LED 5
 flashLED5 (); // flash LED 5
 flashLED5 (); // flash LED 5
   digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(longtimer);
   
  }  
  all5:
  
  SW1last = SW1state;
  SW2last = SW2state;
  SW3last = SW3state;
  SW4last = SW4state;
  SW5last = SW5state;
  
   // check to see if all switches are on. If so, commence awesome flashing
  
  while (SW1state == HIGH && SW2state == HIGH && SW3state == HIGH && SW4state == HIGH && SW5state == HIGH ) 
  
  // if all switches on flash all 5 until a switch
 {

   digitalWrite(LED1, HIGH);
   delay(timer);
   digitalWrite(LED1, LOW);
   delay(timer);
   
flashLED2 (); // flash LED 2
flashLED3 (); // flash LED 3
flashLED4 (); // flash LED 4
flashLED5 (); // flash LED 5
   
switchcheck (); // check the states of all the switches
}
  
}


void switchcheck () { // checks the state of all switches
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
}

void switchchange () { // checks to see if switches have changed states
  if (SW1state != SW1last) { //has switch 1 changed?
  goto all5; }
  if (SW2state != SW2last) {//has switch 1 changed?
  goto all5; }
  if (SW3state != SW3last) {//has switch 1 changed?
  goto all5; }
  if (SW4state != SW4last) {//has switch 1 changed?
  goto all5; }
  if (SW5state != SW5last) {//has switch 1 changed?
  goto all5; }
}

void flashLED2 () {
    digitalWrite(LED2, HIGH);
   delay(timer);
   digitalWrite(LED2, LOW);
   delay(timer);
}

void flashLED3 () {
    digitalWrite(LED3, HIGH);
   delay(timer);
   digitalWrite(LED3, LOW);
   delay(timer);
}

void flashLED4 () {
    digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(timer);
}

void flashLED5 () {
    digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(timer);
}


