    /*
    * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
    *
    * Crated by Dejan Nedelkovski,
    * www.HowToMechatronics.com
    *
    */
    // defines pins numbers
    const int trigPin = 9;
    const int echoPin = 10;
    const int leftSignalLED = 11;
    const int rightSignalLED = 8;
    // defines variables
    long duration;
    int distance;
    int randomNumber;
    bool ledOn = false;
    
    void setup() {
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      pinMode(leftSignalLED, OUTPUT); // Sets the leftSignal pin as an Output
      pinMode(rightSignalLED, OUTPUT); // Sets the leftSignal pin as an Output
      randomNumber = random(0, 10); // Generates initial random number for turn direction
      Serial.begin(9600); // Starts the serial communication
    }
    
    void loop() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);

    //if an object is close enough start the turn signal for the direction the car will turn
      if(distance < 20 && distance > 10){
        //if the random number generated is greater than 5 turn right else turn left
        if(randomNumber > 5){
          turnSignal(rightSignalLED);
        }else{
          turnSignal(leftSignalLED);
        }
      }else if(distance > 20 && ledOn == true){  //if a object is far away and the signal led is still on turn it off
          digitalWrite(leftSignalLED, LOW);
          digitalWrite(rightSignalLED, LOW);
          ledOn = false;
      }else if(distance <= 5){ //make the turn if the object is close
         makeTurn();
      }
    }

    void makeTurn(){
      randomNumber = random(0, 10); //generate new random number for next turn
      digitalWrite(leftSignalLED, LOW); //turn off the signal led
      digitalWrite(rightSignalLED, LOW); //turn off the signal led
      ledOn = false;
    }

    // Turns on and off the correct led for the direction the car will turn
    void turnSignal(int signalSide){ 
      if(ledOn == true){
        digitalWrite(signalSide, LOW);
        delay(100);
        ledOn = false;
      }else{
        digitalWrite(signalSide, HIGH);
        delay(100);
        ledOn = true;
      } 
    }
