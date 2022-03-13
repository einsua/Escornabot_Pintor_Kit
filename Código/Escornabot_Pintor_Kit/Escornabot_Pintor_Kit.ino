#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include "EscornabotDIY.h"
#include <Servo.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double dist;
double ang;
double dist_eje_punta;
double ang_abajo;
double ang_arriba;
double espera;
double posicion_servo;
Servo servo_11;
EscornabotDIY escornabot;



void setup(){
    dist = 5;
    ang = 60;
    dist_eje_punta = 5.75;
    ang_abajo = 3;
    ang_arriba = 25;
    espera = 0.25;
    posicion_servo = 1;
    servo_11.attach(11); // init pin
    servo_11.write(ang_arriba); // write to servo
    _delay(espera);
    
}

void loop(){
    
    if(escornabot.isButtonPressed("FORWARD")){
        escornabot.beep(2637);
        servo_11.write(ang_abajo); // write to servo
        _delay(espera);
        escornabot.move(dist);
        servo_11.write(ang_arriba); // write to servo
        _delay(espera);
    }
    if(escornabot.isButtonPressed("BACKWARD")){
        escornabot.beep(3520);
        servo_11.write(ang_abajo); // write to servo
        _delay(espera);
        escornabot.move(-dist);
        servo_11.write(ang_arriba); // write to servo
        _delay(espera);
    }
    if(escornabot.isButtonPressed("TURN LEFT")){
        escornabot.beep(2217);
        escornabot.move(-dist_eje_punta);
        escornabot.turn(-ang);
        escornabot.move(dist_eje_punta);
        _delay(espera);
    }
    if(escornabot.isButtonPressed("TURN RIGHT")){
        escornabot.beep(4434);
        escornabot.move(-dist_eje_punta);
        escornabot.turn(ang);
        escornabot.move(dist_eje_punta);
        _delay(espera);
    }
    if(escornabot.isButtonPressed("GO")){
        escornabot.beep(4699);
        if(((posicion_servo)==(1))){
            servo_11.write(ang_abajo); // write to servo
            _delay(espera);
        }else{
            servo_11.write(ang_arriba); // write to servo
            _delay(espera);
        }
        posicion_servo = (posicion_servo) * (-1);
    }
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    
}

