#include <stdio.h>
#include <stdlib.h>
#include<reg51.h>

unsigned int digi_val[10] = {0x40,0xF9,0x24,0x30,0x19,0x12,0x02,0xF8,0x00,0x10}; // Hex value corresponding to the digits 0 to 9
sbit output_on_pin = P2^0; // Enable pin to enable the seven segment.
sbit stop_pin = P2^1; // Stop pin to reset the buzzer.
sbit buzzer_pin = P0^7; // Buzzer pin to sound the buzzer.
int flag;

void delay() // Time delay function
{
    int i,j;
    for(i=0;i<200;i++)
        for(j=0;j<1275;j++);
}

void display(unsigned int current_dig) // Function to display the resultant digit on the seven segment and sound the buzzer.
{
    P3=digi_val[current_dig];
    output_on_pin = 1;
    buzzer_pin=0;
        delay();
    buzzer_pin=1;
    while(stop_pin != 0);
}

void buzzer() //Function to monitor the input switches
{
    flag = 0;

    while(1)
    {
        while (P1 == 0xFF);

        while (P1 == 0xFE) //Check if switch 1 is pressed
        {
            flag = 1;
            display(1);
        }

        while (P1 == 0xFD) //Check if switch 2 is pressed
        {
            flag = 2;
            display(2);
        }

        while (P1 == 0xFB ) //Check if switch 3 is pressed
        {
            flag = 3;
            display(3);
        }

        while (P1 == 0xF7 ) //Check if switch 4 is pressed
        {
            flag = 4;
            display(4);
        }

        while (P1 == 0xEF ) //Check if switch 5 is pressed
        {
            flag = 5;
            display(5);
        }

        while (P1 == 0xDF) //Check if switch 6 is pressed
        {
            flag = 6;
            display(6);
        }

        while (P1 == 0xBF ) //Check if switch 7 is pressed
        {
            flag = 7;
            display(7);
        }

        while (P1 == 0x7F ) //Check if switch 8 is pressed
        {
            flag = 8;
            display(8);
        }

        P1 = 0xFF;
        stop_pin = 1;
        output_on_pin = 0;
    }
}

void main()
{
     P1 = 0XFF;
     output_on_pin = 0;
     stop_pin = 1;
     P1 = 0xFF;

     buzzer();
}
