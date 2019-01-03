

#include <Servo.h>
#include <Wire.h>
#include <MPU6050_tockn.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>


//Defining constants for PID control

float kp;
float ki;
float kd;
float err=0;
float sum_err = 0;
float dif_err = 0;
float lastInput = 0;
float maximum = 90;
float minimum = -90;
float output = 0;

float roll_correction;
float pitch_correction;
float roll;
float pitch;

Servo xaxis_servo;
Servo yaxis_servo;

void gimbal(int x, int y) {
  int x_pos = x + 90;
  int y_pos = y + 90;

  xaxis_servo.write(x_pos);
  yaxis_servo.write(y_pos);
  
}

float pid_correction(float setpoint, float input, float dt)
{ 
   //Integral portion of PID Controller is commented out

   
   err = setpoint -input;
   //sum_err += err*ki*dt;
   dif_err = -kd/dt * (input -lastInput);
   //output = kp*err + sum_err + dif_err;
   output = kp*err + dif_err;
   //if (output > maximum) {
   //  sum_err = 0;
   //  output = maximum;
   //}
   //else if (output < minimum){
   //  sum_err = 0;
   //  output = minimum;
   //}
   lastInput=input;
   return output;
}


void setup() {
  kp = 0.25;
  //ki = 0.01;
  kd = 0.34;
  Serial.begin(9600);
  while(!Serial);
  xaxis_servo.attach(9);
  yaxis_servo.attach(10);
  //Entering in alignment/acceleration data  
  //Debugging input
  //roll = 90;
  roll = 0;
  pitch = 0;
  gimbal(-90,-90);
  gimbal(90,90);
  gimbal(0,0);

}

void loop() {
  delay(100);
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.println("Current Roll/Pitch:");
  Serial.println(roll);
  Serial.println(pitch);
  Serial.println("Correction Roll/Pitch:");
  Serial.println(roll_correction);
  Serial.println(pitch_correction);  
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
  roll_correction = pid_correction(0, roll, 1);
  pitch_correction = pid_correction(0, pitch, 1);
  gimbal(roll_correction, pitch_correction);
  
  // Debugging Code:
  //roll = roll + roll_correction;
  

}
