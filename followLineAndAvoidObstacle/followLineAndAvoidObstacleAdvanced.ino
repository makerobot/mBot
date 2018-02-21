#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);		

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 2){
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 4){
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
				
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void lineFollow();
double moveSpeed;
double lineFollowerSensor;
double lineDirIndex;
MeLineFollower linefollower_2(2);
void obstacleAvoidance();
void makeCircle();
void forward();
void backward();
void stop();
void turnLeft();
void turnRight();
double dist;
MeUltrasonicSensor ultrasonic_3(3);


void lineFollow()
{
    if((moveSpeed) > (230)){
        moveSpeed = 230;
    }
    
    lineFollowerSensor = linefollower_2.readSensors();
    
    if(((lineFollowerSensor)==(0))){
        forward();
        lineDirIndex = 10;
    }else{
        if(((lineFollowerSensor)==(1))){
            forward();
            if((lineDirIndex) > (1)){
                lineDirIndex = (lineDirIndex) - (1);
            }
        }else{
            if(((lineFollowerSensor)==(2))){
                forward();
                if((lineDirIndex) < (20)){
                    lineDirIndex = (lineDirIndex) + (1);
                }
            }else{
                if(((lineDirIndex)==(10))){
                    backward();
                }
                if((lineDirIndex) < (10)){
                    turnLeft();
                }
                if((lineDirIndex) > (10)){
                    turnRight();
                }
            }
        }
    }
    
}

void obstacleAvoidance()
{
    turnLeft();
    
    _delay(0.6);
    
    stop();
    
    makeCircle();
    
}

void makeCircle()
{
    motor_10.run((10)==M1?-((moveSpeed) - (75)):((moveSpeed) - (75)));
    
    motor_9.run((9)==M1?-((moveSpeed) + (30)):((moveSpeed) + (30)));
    
    while(!((linefollower_2.readSensors()) < (3)))
    {
        _loop();
    }
    
    stop();
    
}

void forward()
{
    motor_9.run((9)==M1?-(moveSpeed):(moveSpeed));
    
    motor_10.run((10)==M1?-(moveSpeed):(moveSpeed));
    
}

void backward()
{
    motor_9.run((9)==M1?-((0) - (moveSpeed)):((0) - (moveSpeed)));
    
    motor_10.run((10)==M1?-((0) - (moveSpeed)):((0) - (moveSpeed)));
    
}

void stop()
{
    move(1,0);
    
}

void turnLeft()
{
    motor_9.run((9)==M1?-((moveSpeed) / (10)):((moveSpeed) / (10)));
    
    motor_10.run((10)==M1?-(moveSpeed):(moveSpeed));
    
}

void turnRight()
{
    motor_9.run((9)==M1?-(moveSpeed):(moveSpeed));
    
    motor_10.run((10)==M1?-((moveSpeed) / (10)):((moveSpeed) / (10)));
    
}


void setup(){
    moveSpeed = 150;
    lineDirIndex = 10;
    pinMode(A7,INPUT);
    while(!((0^(analogRead(A7)>10?0:1))))
    {
        _loop();
        dist = ultrasonic_3.distanceCm();
        if(((dist) < (  9)) && ((dist) > (1))){
            obstacleAvoidance();
        }else{
            lineFollow();
        }
    }
    
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

