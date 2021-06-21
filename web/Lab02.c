#include <reg51.h>
#include <absacc.h>
#define PORTA XBYTE(0xD0000)

sbit P10 = P1^0;

void Delay(unsigned int ms)
{
    unsigned int x,y;
    for(x = ms;x>0;x--)
        for (y = 123;y>0;y--);   
}
void main(void)
{
    unsigned int i;
    P10 = ~p10;
    P10 = !P10;
    PORTA = 0x0f; //四面红灯
    Delay(1000);

    while(1){
        PORTA = 0x5A;
        Delay(20000);
        //for_blink
        for(i= 0 ; i<3 ;i++){
            PORTA = 0x5A;
            Delay(300);

            PORTA = 0xFA;
            Delay(300);
        }
        PORTA = 0x50;
        Delay(1000);
        PORTA = 0xA5;
        Delay(20000);
        for(i= 0 ; i<3 ;i++){
            PORTA = 0xA5;
            Delay(300);
            PORTA = 0xF5;
            Delay(300);
        }

        PORTA = 0xA0;
        Delay(1000);
        
    
        

    }
}