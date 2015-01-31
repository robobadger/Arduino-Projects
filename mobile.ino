/*
	Code for an Arduino-powered child's mobile.
	Complete rewrite of code by @robobadger.
	
	Code: @albyr
	Hardware: @robobadger
*/

// Hold LED pin and switch input pin values in arrays.
// Note that arrays are zero-indexed, so the first element is [0], not [1].
int ledPins[] = {12, 11, 10, 9, 8};
int switchPins[] = {A0, A1, A2, A3, A4}; // Actually pins 18-22

// Count the number of assigned LED and switch pins. This will be important when we want to loop through them.
int ledCount = sizeof(ledPins)/sizeof(int);
int switchCount = sizeof(switchPins)/sizeof(int);

// Declare and define flash timing values.
// timerShortIntial is our base flash timing value.
const int timerShortInitial = 300;
// Set timerShort to timerShortInitial to begin with. timerShort will then be decreased every time we loop.
int timerShort = timerShortInitial;
// Set timerLong to twice the length of timerShort. It could also be manually defined.
int timerLong = timerShort * 2;

// Declare and define counting variables.
// Used to count the number of switches set HIGH.
int switchOnCount = 0;
// Used to count the number of loops that the code has run through.
int loopCount = 0;

// Setup
void setup() {
  	// Initialise input and output pins. Using loops here means that adding new LEDs/switches is as simple as including them in the arrays above.
	// Set ledPins as OUTPUTs.
	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
		pinMode(ledPins[currentPin], OUTPUT);
	}
	// Set switchPins as INPUTs.
	for (int currentPin = 0; currentPin < switchCount; currentPin++) {
		pinMode(switchPins[currentPin], INPUT);
	}
}

// Main loop
void loop() {
	// Reset switchOnCount back to zero so that we count the number of switches set HIGH correctly.
	switchOnCount = 0;
	for (int currentPin = 0; currentPin < switchCount; currentPin++) {
		if (digitalRead(switchPins[currentPin]) == HIGH) {
			// If a switch is set HIGH, increment the switchOnCount variable.
			switchOnCount = switchOnCount + 1;
		}
	}
	// If the number of switches set HIGH is equal to the total number of switches ...
	if (switchOnCount == switchCount) {
		// ... then run the knightRider function.
		knightRider();
		}
	// If the number of switches set HIGH is not equal to the number of switches then flash each LED the appropriate number of times.
	else {
		// Loop through each switch.
		for (int currentPin = 0; currentPin < switchCount; currentPin++) {
			// If the switch is set HIGH ...
			if (digitalRead(switchPins[currentPin]) == HIGH) {
				// ... then flash the corresponding LED the appropriate number of times.
				// The "+ 1" takes account of the fact that the ledPins[] and switchPins[] arrays are zero-indexed.
				flashLED(ledPins[currentPin], currentPin + 1);
			}
		}
	}
	// Pause before beginning the next cycle. Without this it's difficult to see how many times each LED is flashing when only one LED is lit.
	delay(timerLong);
	// Increment loopCount variable and print it to the serial monitor for debugging.
	loopCount = loopCount + 1;
	Serial.print("Loop: ");
	Serial.print(loopCount);
	Serial.print("\n");
}

// 'Knight Rider' function
void knightRider() {
	// Loop through the LED pins.
  	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
		// Call the flashLED procedure with flashTimes = 1 for each LED in sequence.
		flashLED(ledPins[currentPin], 1);
    	}
}

// Blink LED function
// Turns the LED with pinNumber on and off the number of times specified by the flashTimes variable.
void flashLED(int pinNumber, int flashTimes) {
  	for (int flashes = 0; flashes < flashTimes; flashes++) {
		// Set the LED pin HIGH.
		digitalWrite(pinNumber, HIGH);
      	// Wait
		delay(timerShort);
  		// Set the LED pin back to LOW.
		digitalWrite(pinNumber, LOW);
      	// Wait. Without this delay, multiple flashes are not visible.
		delay(timerShort);
    }
}