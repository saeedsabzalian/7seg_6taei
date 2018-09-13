
#include <mega16a.h>
#include <delay.h>

void main(void)
{
unsigned int yekan,dahgan,sadgan,hezargan,i;
unsigned char seg_code[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; 
unsigned int a,b;
long int number;
// Port C initialization
// Function: Bit7=In Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(0<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=T Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(0<<DDD7) | (0<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=T Bit6=T Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

while (1)
      {
      for(number=0;number<1000000;number++)
      {
      yekan=number%10;
      dahgan=number/10%10;
      sadgan=number/100%10;
      hezargan=number/1000%10;  
      a=number/10000%10;
      b=number/100000;
       for(i=0;i<30;i++)
       {
        PORTC=seg_code[yekan];
        PORTD=0XDF;
        delay_ms(2);
        PORTD=0xff;
        
        PORTC=seg_code[dahgan];
        PORTD=0XEF;
        delay_ms(2);
        PORTD=0xff;
        
        PORTC=seg_code[sadgan];
        PORTD=0XF7;
        delay_ms(2);
        PORTD=0xff;
        
        PORTC=seg_code[hezargan];
        PORTD=0XFB;
        delay_ms(2);
        PORTD=0xff;
        
        PORTC=seg_code[a];
        PORTD=0XFD;
        delay_ms(2);
        PORTD=0xff;
        
        PORTC=seg_code[b];
        PORTD=0XFE;
        delay_ms(2);
        PORTD=0xff;
        }
        }
      }
}
