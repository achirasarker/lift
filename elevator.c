# moving-elevator

//The Elevator Project

#include <stdio.h>
#include <unistd.h>
#include </usr/include/sys/io.h>

#define BASEPORT 0x378 /* parallel or lpl port address */
int currentfloor=1;
int main()
{
ioperm(BASEPORT, 3,1);	// Get permission to access the ports \\	
while(1)

{
	printf("what floor do you most desire . . . sir\n");
	 char userinput=getchar();
	if (userinput=='1')
		{
			if (currentfloor=='1')
				{
				printf("you are already there . . . sir\n");
				}
			 else if (currentfloor=='2')
				{
				outb(1, BASEPORT);	//motor cc
				sleep(6);		// Go up for 6 secs
				outb(0, BASEPORT);
				currentfloor='2';
				}
			else
				{
				outb(1, BASEPORT);	//motor cc
				sleep(12);		// Go up for 12 secs
				outb(0, BASEPORT);
				currentfloor='3';
				}
		}
	else if (userinput=='2')
		{
			if (currentfloor=='1')
				{
				outb(2, BASEPORT);	//motor cc				
		             sleep(6);                  //go up for 6 secs
				outb(0, BASEPORT);
				currentfloor='2';
				}
			else if (currentfloor=='2')
				{
				printf("you are already there . . . sir\n");
				}
			else  
				{
				outb(1, BASEPORT);	//motor cc
				sleep(6);		//go up for 6 secs
				outb(0, BASEPORT);
				currentfloor='3';
				}
		}
	else if (userinput=='3')
		{
			if (currentfloor=='1')
				{
				outb(2, BASEPORT);	//motor ccw
				sleep(12);		//go down for 12 secs
				outb(0, BASEPORT);
				currentfloor='2';
				}
			else if (currentfloor=='2')
				{
				outb(2, BASEPORT);	//motor ccw
				sleep(6);		//go down for 6 secs
				outb(0, BASEPORT);
				currentfloor='2';
				}
			else 
				{
				printf("you are already there . . . sir\n");
				}
		}
	

printf("By your command . . . sir\n");
ioperm(BASEPORT, 1, 0);	//We don't need the ports anymore 
		// release ports for other programs
return 0;
}
/* end of project */
