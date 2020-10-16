#include "mbed.h"

PwmOut myLed(LED1);
PwmOut redLed(p21);
PwmOut piezo(p22);
DigitalIn sw1(p19,PullDown);
DigitalIn sw2(p20,PullDown);

float frequency1[]={960,1140}; //frequency array for switch 1
float frequency2[]={1200,1225,1250,1275,1300,1325,1350,1375,1400}; //frequency array for switch 2

int main() {
    redLed = 1;
    myLed = 0;
    piezo = 0;
    
    while(1) {
        if (sw1 == 1) {
            piezo = 0.5;
            for (int i=0; i<=1; i++) {
                piezo.period(1/(2*frequency1[i])); 
                myLed = i;
                redLed = i;
                wait(0.7);
            }
        }
        
        if (sw2 == 1) {
            piezo = 0.5;
            for (int i=0; i<=8; i++) {
                piezo.period(1/(2*frequency2[i])); 
                redLed = i/8; 
                wait(0.03125);
            }
            for (int i=8; i>=0; i--) {
                piezo.period(1/(2*frequency2[i])); 
                redLed = i/8; 
                wait(0.03125);
            }
        }
        redLed = 1;
        myLed = 0;
        piezo = 0;
    }
}
