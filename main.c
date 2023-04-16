//This is is just a helper program to get the assembly program started
//
void start();

#include <stdio.h>
#include "pico/stdlib.h"

void turnOn();
void turnOff();
void flushBuffer();
void getInput();
void inputToBuffer(char character);

char input;
char top_of_buffer = 0;
char input_buffer[25];


int main(){
    //Initialise I/O
    stdio_init_all(); 
	
    // initialise GPIO (Green LED connected to pin 25)
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
	
	
    //Main Loop 
    while(1){
		getInput();
		charToBuffer();
		
		switch(command) {
			case 'a' :
				turnOn();
				break;
			case 'b' :
				turnOff();
				break;
			default :
				printf("Invalid command\n" );
	   }
    }
}



void getInput(){
	scanf("%c", &input);
	charToBuffer(input);
}

void inputToBuffer(char character){
	if(top_of_buffer >= sizeof(input_buffer)){
		flush_buffer();
		printf("\n");	
	}
	printf("%c", character);
	input_buffer[top_of_buffer] = character;
	top_of_buffer++;	
}

void flushBuffer(){
	top_of_buffer = 0;
	
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
