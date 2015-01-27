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
const int timer = 100;
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
   delay(timer);
   delay(timer);
   delay(timer);
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
   delay(timer);
   delay(timer);
   delay(timer);
   
    
  }
        
  if (SW1state == HIGH && SW2state == HIGH) // if both switch 1 & 2 on flash all 5
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
}
  
  
}
