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
// Set timerShort to timerShortInitial to begin with. timerShort will then be decreased every time we loop inside the 'Knight Rider' function.
int timerShort = timerShortInitial;
// Set timerLong to a multiple of the length of timerShort.
int timerLongMultiplier = 2;
int timerLong = timerShort * timerLongMultiplier;
// Used to control the rate at which the timerShort value decays within repeating 'Knight Rider' loops.
// Larger values mean faster decays. Needs to be float because it contains a decmial point.
// Using timerShortInitial = 300 ms and decayFactor = 0.15 means flashing is invisible to naked eye after twenty loops.
const float decayFactor = 0.15;

// Declare and define counting variables.
// Used to count the number of switches set HIGH.
int switchOnCount = 0;
// Used to count the number of 'Knight Rider' loops.
int knightRiderLoopCount = 0;

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
	// If all switches are set LOW ...
	else if (switchOnCount == 0) {
		// ... then reset the timerShort value ...
		timerShort = timerShortInitial;
		timerLong = timerShort * timerLongMultiplier;
		// ... and the knightRiderLoopCount value.
		knightRiderLoopCount = 0;
	}
	// If the number of switches set HIGH is not equal to the number of switches then flash each LED the appropriate number of times.
	else {
		// Reset timerShort/timerLong values before beginning flash sequence, because we don't want to use the values from the 'Knight Rider' sequence.
		timerShort = timerShortInitial;
		timerLong = timerShort * timerLongMultiplier;
		// And we also need to reset the knightRiderLoopCount value.
		knightRiderLoopCount = 0;
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
}

// 'Knight Rider' function
void knightRider() {
	// Loop through the LED pins.
  	for (int currentPin = 0; currentPin < ledCount; currentPin++) {
		// Call the flashLED procedure with flashTimes = 1 for each LED in sequence.
		flashLED(ledPins[currentPin], 1);
    	}
	// Calculate timerShort value for next loop.
	// Calculate new exponent.
	float exponent = -1 * decayFactor * knightRiderLoopCount;
	// Calculate new timerShort value. Using negative powers of two creates exponential decay rather than a step-like decrease.
	// The "+1" term ensures timerShort and timerLong are never equal to zero.
	timerShort = (timerShortInitial * (pow(2, exponent))) + 1;
  	timerLong = (timerShort * timerLongMultiplier) + 1;
	// Increment loop count. Putting it here, at the end of the loop, ensures that the first loop uses the initial timerShort/timerLong values.
	knightRiderLoopCount = knightRiderLoopCount + 1;	
}

// Blink LED function
// Turns the LED with pinNumber on and off the number of times specified by the flashTimes variable.
void flashLED(int pinNumber, int flashTimes) {
  	for (int flashes = 0; flashes < flashTimes; flashes++) {
		// Set the LED pin HIGH and wait.
		digitalWrite(pinNumber, HIGH);
		delay(timerShort);
  		// Set the LED pin back to LOW.
		digitalWrite(pinNumber, LOW);
      	// Wait. Without this delay, multiple flashes are not visible.
		delay(timerShort);
    }
}