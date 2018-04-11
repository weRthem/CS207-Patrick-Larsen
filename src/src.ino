    /*
    * Ultrasonic Sensor HC-SR04 and Arduino Tutorial
    *
    * Crated by Dejan Nedelkovski,
    * www.HowToMechatronics.com
    *
    */
    // defines pins numbers
    const int trigPin = 4;
    const int echoPin = 2;
    const int leftSignalLED = 13;
    const int rightSignalLED = 12;
    const int frontWheelOne = 6, frontWheelTwo = 7, frontSpeed = 11,
backWheelOne = 8, backWheelTwo = 9, backSpeed = 10;
    // defines variables
    int randomNumber;
    int randomTurn;
    bool driveMode = true;
    bool ledOn = false;

    int getDistance();
    void turnSignal(int);
    void makeTurn(int, int);
    void fullSpeed();
    void stopCar();
    
    
    void setup() {
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      pinMode(leftSignalLED, OUTPUT); // Sets the leftSignal pin as an Output
      pinMode(rightSignalLED, OUTPUT); // Sets the leftSignal pin as an Output

      pinMode(frontWheelOne, OUTPUT);
      pinMode(frontWheelTwo, OUTPUT);
      pinMode(frontSpeed, OUTPUT);
  
      pinMode(backWheelOne, OUTPUT);
      pinMode(backWheelTwo, OUTPUT);
      pinMode(backSpeed, OUTPUT);
      
      randomNumber = random(0, 10); // Generates initial random number for turn direction
      Serial.begin(9600); // Starts the serial communication
    }
    
    void loop() {
      int distance = getDistance(); //get the distance of the object infront of the car
      if(driveMode == true){
  
         //if an object is close enough start the turn signal for the direction the car will turn
        if(distance < 50 && distance > 30){
          //if the random number generated is greater than 5 turn right else turn left
          if(randomNumber > 5){
            turnSignal(rightSignalLED);
          }else{
            turnSignal(leftSignalLED);
          }
        }else if(distance <= 30 && distance > 5){ //make the turn if the object is close
           if(randomNumber > 5){ //Turn Right
            makeTurn(frontWheelTwo, frontWheelOne);
          }else{ //Turn Left
            makeTurn(frontWheelOne, frontWheelTwo);
          }
        }else if(randomTurn == 1000){ //Turns randomly when a certain number is reached
          for(int i = 0; i < 3; i++){
            if(randomNumber > 5){ //if the random number generated is greater than 5 turn right else turn left
              turnSignal(rightSignalLED);
            }else{
              turnSignal(leftSignalLED);
            }
          } 
        }else if(distance >= 50){
          fullSpeed();
          digitalWrite(leftSignalLED, LOW);
          digitalWrite(rightSignalLED, LOW);
        }else if(distance < 5){
          stopCar();
        }
      }

      randomTurn = random(0, 1000);
    }


    int getDistance(){
      long duration;
      int dist;  
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
      dist= duration*0.034/2;
      // Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(dist);
      return dist;
    }

    void makeTurn(int turnHigh, int turnLow){
      randomNumber = random(0, 10); //generate new random number for next turn
      
      digitalWrite(leftSignalLED, LOW); //turn off the signal led
      digitalWrite(rightSignalLED, LOW); //turn off the signal led

      int distance;
      
      do{  //loops until there is no longer a object infront of the car. runs atleast once for when the car randomly turns.
        digitalWrite(turnHigh, HIGH);
        digitalWrite(turnLow, LOW);
        analogWrite(frontSpeed, 200); //sets the speed of the front motors
        distance = getDistance();
        fullSpeed();
        delay(1000);
      }while(distance <= 5);
      
      digitalWrite(turnHigh, LOW);
      digitalWrite(turnLow, LOW);
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
      analogWrite(backSpeed, 50);
    }

    void fullSpeed(){
      digitalWrite(backWheelOne, LOW);
      digitalWrite(backWheelTwo, HIGH);
      analogWrite(backSpeed, 70);
    }

    void stopCar(){ //stops the car from running
      driveMode = false;
      digitalWrite(backWheelOne, LOW);
      digitalWrite(backWheelTwo, LOW);
      analogWrite(backSpeed, 0);
    }
