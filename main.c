//This is is just a helper program to get the assembly program started
//
void start();

#include <stdio.h>
#include "pico/stdlib.h"

void turnOn();
void turnOff();

int main(){
    //Initialise I/O
    stdio_init_all(); 
	
    // initialise GPIO (Green LED connected to pin 25)
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
	
	char command;
    //Main Loop 
    while(1){

		printf("Enter a command \n(a :on, b: off)\n");
		scanf("%c", &command);
		switch(command) {
			case 'a' :
				turnOn();
				break;
			case 'b' ;
				turnOff();
				break;
			default :
				printf("Invalid command\n" );
	   }
    }
}

void turnOn()
{
	gpio_put(25, 1); // Set pin 25 to high
	printf("LED ON!\n");
	
}
void turnOff()
{
	gpio_put(25, 0); // Set pin 25 to high
	printf("LED OFF\n");
	
}
/*
gpio_put(25, 1); // Set pin 25 to high
printf("LED ON!\n");
sleep_ms(1000); // 0.5s delay

gpio_put(25, 0); // Set pin 25 to low
printf("LED OFF!\n");
sleep_ms(1000); // 0.5s delay
*/
