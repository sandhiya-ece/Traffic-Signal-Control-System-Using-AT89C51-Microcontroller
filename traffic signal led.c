#include <reg51.h>

sbit GREEN   = P2^0;
sbit YELLOW = P2^1;
sbit RED  = P2^2;

unsigned char seg[] =
{
    0x66,
    0x4F, 
    0x5B, 
    0x06, 
    0x3F  
};

void delay()
{
    unsigned int i, j;
    for(i = 0; i < 200; i++)
        for(j = 0; j < 1275; j++);
}

void countdown()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        P3 = seg[i];   
        delay();
    }
}

void main()
{

    while(1)
    {
        
        GREEN = 1; YELLOW = 0; RED = 0;
        countdown();

        
        GREEN = 0; YELLOW = 1; RED = 0;
        countdown();

			
        
        GREEN = 0; YELLOW = 0; RED = 1;
        countdown();
    }
}         