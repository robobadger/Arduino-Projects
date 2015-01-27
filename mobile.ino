/* Light flashing programme for child's toy project, cobbled together by Phil Saunders
 *Flash sequence built from the following 
 *
 *Knight Rider 1
 * --------------
 *
 * Basically an extension of Blink_LED.
 *
 *
 * (cleft) 2005 K3, Malmo University
 * @author: David Cuartielles
 * @hardware: David Cuartielles, Aaron Hallborg
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
 
  // read all the switch states
  
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
 
 
  }
  // check last button states
  if (SW1state != SW1last) {
  goto all5;
  }
   // check last button states
  if (SW2state != SW2last) {
  goto all5;
  }
   // check last button states
  if (SW3state != SW3last) {
  goto all5;
  }
   // check last button states
  if (SW4state != SW4last) {
  goto all5;
  }
   // check last button states
  if (SW5state != SW5last) {
  goto all5;
  }
// check to see if switch 2 is on. If so, commence flashing

 if (SW2state == HIGH) { // if switch 2 only on just flash LED 2 twice
  
   digitalWrite(LED2, HIGH);
   delay(timer);
   digitalWrite(LED2, LOW);
   delay(timer);
   digitalWrite(LED2, HIGH);
   delay(timer);
   digitalWrite(LED2, LOW);
   delay(longtimer);
   
  }
   
    // read all the switch states
  
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
   
   
    // check last button states
  if (SW1state != SW1last) {
  goto all5;
  }
   // check last button states
  if (SW2state != SW2last) {
  goto all5;
  }
   // check last button states
  if (SW3state != SW3last) {
  goto all5;
  }
   // check last button states
  if (SW4state != SW4last) {
  goto all5;
  }
   // check last button states
  if (SW5state != SW5last) {
  goto all5;
  }
        
  // check to see if switch 3 is on. If so, commence flashing

if (SW3state == HIGH) { // if switch 3 only on just flash LED 3 thrice
  
   digitalWrite(LED3, HIGH);
   delay(timer);
   digitalWrite(LED3, LOW);
   delay(timer);
   digitalWrite(LED3, HIGH);
   delay(timer);
   digitalWrite(LED3, LOW);
   delay(timer);
   digitalWrite(LED3, HIGH);
   delay(timer);
   digitalWrite(LED3, LOW);
   delay(longtimer);
   
  }
  
   // read all the switch states
  
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
  
   // check last button states
  if (SW1state != SW1last) {
  goto all5;
  }
   // check last button states
  if (SW2state != SW2last) {
  goto all5;
  }
   // check last button states
  if (SW3state != SW3last) {
  goto all5;
  }
   // check last button states
  if (SW4state != SW4last) {
  goto all5;
  }
   // check last button states
  if (SW5state != SW5last) {
  goto all5;
  }
  
  
 if (SW4state == HIGH) { // if switch 4 only on just flash LED 4 fourice
  
   digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(timer);
   digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(timer);
   digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(timer);
   digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(longtimer);
   
  }  
  // read all the switch states
  
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
  
   // check last button states
  if (SW1state != SW1last) {
  goto all5;
  }
   // check last button states
  if (SW2state != SW2last) {
  goto all5;
  }
   // check last button states
  if (SW3state != SW3last) {
  goto all5;
  }
   // check last button states
  if (SW4state != SW4last) {
  goto all5;
  }
   // check last button states
  if (SW5state != SW5last) {
  goto all5;
  }
  
  
  if (SW5state == HIGH) { // if switch 5 only on just flash LED 5 fivice
  
   digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(timer);
   digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(timer);
   digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(timer);
   digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(timer);
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
    
   digitalWrite(LED2, HIGH);
   delay(timer);
   digitalWrite(LED2, LOW);
   delay(timer);

   digitalWrite(LED3, HIGH);
   delay(timer);
   digitalWrite(LED3, LOW);
   delay(timer);

   digitalWrite(LED4, HIGH);
   delay(timer);
   digitalWrite(LED4, LOW);
   delay(timer);

   digitalWrite(LED5, HIGH);
   delay(timer);
   digitalWrite(LED5, LOW);
   delay(timer);
   
  SW1state = digitalRead(SW1); // read the state of switch 1
  SW2state = digitalRead(SW2); // read the state of switch 2
  SW3state = digitalRead(SW3); // read the state of switch 3
  SW4state = digitalRead(SW4); // read the state of switch 4
  SW5state = digitalRead(SW5); // read the state of switch 5
}
  
  
}
