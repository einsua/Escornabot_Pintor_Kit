#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "EscornabotDIY.h"
#include <Servo.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double dist;
double ang;
double ang_abajo;
double ang_arriba;
double posicion;
double espera;
Servo servo_11;
EscornabotDIY escornabot;



void setup(){
    dist = 15;
    ang = 360;
    ang_abajo = 3;
    ang_arriba = 25;
    posicion = 1;
    espera = 0.25;
    servo_11.attach(11); // init pin
    servo_11.write(ang_arriba); // write to servo
    _delay(espera);
    
}

void loop(){
    
    if(escornabot.isButtonPressed("FORWARD")){
        if(((posicion)==(1))){
            servo_11.write(ang_abajo); // write to servo
            _delay(espera);
        }else{
            servo_11.write(ang_arriba); // write to servo
            _delay(espera);
        }
        posicion = (posicion) * (-1);
    }
    if(escornabot.isButtonPressed("TURN LEFT")){
        servo_11.write(ang_abajo); // write to servo
        _delay(espera);
        escornabot.turn(-ang);
        servo_11.write(ang_arriba); // write to servo
        _delay(espera);
    }
    if(escornabot.isButtonPressed("TURN RIGHT")){
        servo_11.write(ang_abajo); // write to servo
        _delay(espera);
        escornabot.turn(ang);
        servo_11.write(ang_arriba); // write to servo
        _delay(espera);
    }
    if(escornabot.isButtonPressed("BACKWARD")){
        servo_11.write(ang_abajo); // write to servo
        _delay(espera);
        escornabot.move(-dist);
        servo_11.write(ang_arriba); // write to servo
        _delay(espera);
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

