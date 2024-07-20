#include <Servo.h>

  // rear.write(60);
  // front.write(140);
  // pen.write(0);
  // //100 for extended pen

    // front.attach(9); 
  // rear.attach(10);
  // pen.attach(11);

   // delay(2000);
  // one();
  // delay(200);
  // pen.write(100);
  // delay(1000);
  // two();

Servo front;
Servo pen;
Servo rear;

int currentRearPos = 60;
int currentFrontPos = 140;
int delayTime = 20;

// int stepDelay = 20;     
// unsigned long previousMillis = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5000); 
  pinMode(13, OUTPUT);

  rear.write(60);
  front.write(140);
  pen.write(0);
  //100 for extended pen

  front.attach(9); 
  rear.attach(10);
  pen.attach(11);
}

bool processing = false;

void loop() {

  if ((Serial.available() > 0) && !processing) {
    // digitalWrite(13, HIGH);
    String incomingMessage = Serial.readStringUntil('\n');
    if (incomingMessage.length() > 0) {
      // digitalWrite(13, HIGH); 
      // delay(100);
      // Serial.print("Received: ");
      // Serial.println(incomingMessage);
      processMessage(incomingMessage);
      // digitalWrite(13, LOW); 
      // delay(100);
    }
  }
}

void processMessage(String message) {
  processing = true;
  // Serial.println();
  int numbers[16] = { };
  int counter = 0;

  // Serial.println(message);
  int startIndex = 0;

  for (int i = 0; i <= message.length(); i++) {
    if (message.charAt(i) == ';') {
      String numberStr = message.substring(startIndex, i);
      int number = numberStr.toInt();
      startIndex = i + 1;

      // Serial.print(number);
      // Serial.print(", ");
      // if(number > 16) {
      //   digitalWrite(13, HIGH); 
      //   delay(100);
      //   digitalWrite(13, LOW); 
      // }

      if(number > 16) {
        digitalWrite(13, HIGH); 
        delay(200);
        digitalWrite(13, LOW); 

        break;
      }

      numbers[counter] = number;
      counter++;
    }
  }

  for(int i=0; i<=16; i++) {
    if(numbers[i] != 0) {

      // if(numbers[i] > 16) {
      //   Serial.println(message);
      // }

      callFunction(numbers[i]);
      delay(200);

      if(i == 0) {
        delay(200);
        pen.write(100);
        delay(200);
      }
    } else {
      delay(200);
      pen.write(0);
      delay(100);
      break;
    }
  }

    processing = false;
}

void callFunction(int number) {
  switch (number) {
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
    case 10:
      ten();
      break;
    case 11:
      eleven();
      break;
    case 12:
      twelve();
      break;
    case 13:
      thirteen();
      break;
    case 14:
      fourteen();
      break;
    case 15:
      fifteen();
      break;
    case 16:
      sixteen();
      break;
    default:
      // digitalWrite(13, HIGH); 
      // delay(100);
      // digitalWrite(13, LOW); 

      Serial.print("No function defined for number: ");
      Serial.println(number);
      break;
  }
}


void one() {
  int rearPos = 48;
  int frontPos = 47;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void two() {
  int rearPos = 37;
  int frontPos = 41;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void three() {
  int rearPos = 29;
  int frontPos = 35;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void four() {
  int rearPos = 20;
  int frontPos = 31;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void five() {
  int rearPos = 45;
  int frontPos = 37;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void six() {
  int rearPos = 36;
  int frontPos = 32;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void seven() {
  int rearPos = 26;
  int frontPos = 28;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void eight() {
  int rearPos = 17;
  int frontPos = 23;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void nine() {
  int rearPos = 44;
  int frontPos = 29;

   moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void ten() {
  int rearPos = 34;
  int frontPos = 24;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void eleven() {
  int rearPos = 21;
  int frontPos = 17;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void twelve() {
  int rearPos = 12;
  int frontPos = 12;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void thirteen() {
  int rearPos = 44;
  int frontPos = 21;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void fourteen() {
  int rearPos = 34;
  int frontPos = 16;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void fifteen() {
  int rearPos = 21;
  int frontPos = 9;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

void sixteen() {
  int rearPos = 9;
  int frontPos = 2;

  moveServosTogether(currentRearPos, rearPos, rear, currentFrontPos, frontPos, front);
  // moveServo(currentRearPos, rearPos, rear);
  // moveServo(currentFrontPos, frontPos, front);

  currentRearPos = rearPos;
  currentFrontPos = frontPos;
}

// void moveServo(int currentPos, int targetPos, Servo myServo) {
//     if (currentPos < targetPos) {
//         for (int pos = currentPos; pos <= targetPos; pos++) {
//             myServo.write(pos);
//             delay(delayTime);
//         }
//     } else {
//         for (int pos = currentPos; pos >= targetPos; pos--) {
//             myServo.write(pos);
//             delay(delayTime);
//         }
//     }
// }

void moveServosTogether(int currentRearPos, int targetRearPos, Servo &rearServo, int currentFrontPos, int targetFrontPos, Servo &frontServo) {
    int stepsRear = abs(targetRearPos - currentRearPos);
    int stepsFront = abs(targetFrontPos - currentFrontPos);
    int steps = max(stepsRear, stepsFront);  

    for (int i = 0; i <= steps; i++) {
        int rearPos = currentRearPos + ((2 * i) * (targetRearPos - currentRearPos)) / (2 * steps);
        int frontPos = currentFrontPos + ((2 * i) * (targetFrontPos - currentFrontPos)) / (2 * steps);

        rearServo.write(rearPos);
        frontServo.write(frontPos);

        delay(delayTime);
    }
}

// void moveServo(int currentPos, int targetPos, Servo &myServo) {
//   int steps = abs(targetPos - currentPos);
//   for (int i = 0; i <= steps; i++) {
//     float t = (float)i / steps;
//     float easedT = t * t * (3 - 2 * t); 
//     int pos = currentPos + easedT * (targetPos - currentPos);
//     myServo.write(pos);
//     delay(delayTime);
//   }
// }

// void moveServo(int currentPos, int targetPos, Servo myServo) {
//   unsigned long currentMillis = millis();

//   if (currentPos != targetPos) {
//     if (currentMillis - previousMillis >= stepDelay) {
//       previousMillis = currentMillis;
      
//       if (currentPos < targetPos) {
//         currentPos++;
//       } else if (currentPos > targetPos) {
//         currentPos--;
//       }

//       myServo.write(currentPos);
//     }
//   }
// }


// void one() {
//   rear.write(48); 
//   front.write(47); 
// }

// void two() {
//   rear.write(40); //47
//   front.write(43); //50
// }

// void three() {
//   rear.write(32);
//   front.write(37);
// }

// void four() {
//   rear.write(21);
//   front.write(32);
// }


// void five() {
//   rear.write(47);
//   front.write(39);
// }

// void six() {
//   rear.write(36);
//   front.write(32);
// }

// void seven() {
//   rear.write(28);
//   front.write(28);
// }

// void nine() {
//   rear.write(46);
//   front.write(30);
// }

// void eight() {
//   rear.write(19);
//   front.write(24);
// }

// void ten() {
//   rear.write(35);
//   front.write(24);
// }

// void eleven() {
//   rear.write(25);
//   front.write(20);
// }

// void twelve() {
//   rear.write(14);
//   front.write(15);
// }

// void thirteen() {
//   rear.write(47);
//   front.write(24);
// }

// void fourteen() {
//   rear.write(35);
//   front.write(17);
// }

// void fifteen() {
//   rear.write(23);
//   front.write(11);
// }

// void sixteen() {
//   rear.write(10);
//   front.write(4);
// }

