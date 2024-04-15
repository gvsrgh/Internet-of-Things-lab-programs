#include <AFMotor.h>

// Constants
const int motorspeed = 200;

// Parameters
AF_DCMotor motorG(1);
AF_DCMotor motorM(2);

void setup() {
  // Code d'initialisation : s'exécute une seule fois
  
  motorG.setSpeed(motorspeed);
  motorM.setSpeed(motorspeed);
  motorG.run(RELEASE);
  motorM.run(RELEASE);
}

void loop() {
  motorG.run(FORWARD);
  motorM.run(FORWARD);
  delay(5000);

  motorG.run(BACKWARD);
  motorM.run(BACKWARD);
  delay(5000);

  motorG.run(RELEASE);
  motorM.run(RELEASE);
  delay(500);
}
