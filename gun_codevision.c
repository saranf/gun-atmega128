#include <mega128.h>                                                                                                                       
#include <delay.h>
#include <stdlib.h>

unsigned char count = 0, timer = 0x60, sec;
unsigned int n = 0;
void score();
void Start()
{                                                                                                                       
    
    PORTD = 0x00; delay_ms(50); PORTD = 0x01; PORTF = 0x03; delay_ms(950);      // 시작 카운트다운 3초
    PORTD = 0x00; delay_ms(50); PORTD = 0x01; PORTF = 0x02; delay_ms(950);    // 시작 카운트다운 2초
    PORTD = 0x00; delay_ms(50); PORTD = 0x01; PORTF = 0x01; delay_ms(950);    // 시작 카운트다운 1초
    PORTD = 0x00; PORTF = 0x00; delay_ms(950); PORTD = 0x01;  delay_ms(50); 
}

void End()
{
    PORTD = 0x00; delay_ms(50); PORTD = 0x01; delay_ms(50); PORTD = 0x00; delay_ms(50); PORTD = 0x01; delay_ms(350);
}
void buzzer()
{
    PORTD = 0x00;delay_ms(50);
    PORTD = 0x01;
}

void main()
{   
    
    DDRF = 0xff;     // 7447연결
    PORTF = 0x00;      
    DDRA = 0x0f;
    PORTA = 0xf0;   //내부풀업저항 Active.
    DDRB = 0xf0;
    PORTB = 0x0f;   //내부풀업저항 Active.            
    DDRE = 0x0f;
    PORTE = 0xf0;   //내부풀업저항 Active.
   
    DDRC = 0xff;     //7447연결
    
    DDRG = 0b11101111;    //시작스위치
    PORTG = 0x00;
    DDRD = 0xff;
    PORTC = 0x00;
    PORTD = 0x01;
    PORTE = 0x00;
    PORTB = 0x00;
    
    TCCR0 = 0x01;

    SREG |= 0x80;
   
    while(PING == 0x10);
    Start();
    
    TIMSK = 0x04;   //60초 카운트다운을 위한 타이머 카운트 인터럽트
    TCCR1A = 0x81;
    TCCR1B = 0x05;
    TCNT1 = 0x0000;
    
    PORTF = timer; 
    
    while(1)
    {                                                                                      
        switch((rand()*TCNT0)%12) //타이머 g카운트를 이용한 랜덤함수
        {  
            case 0 : PORTA.0 = 1; while(1){if(PINA.4 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTA.0 = 0;delay_ms(250);break;
            case 1 : PORTA.1 = 1; while(1){if(PINA.5 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTA.1 = 0;delay_ms(250); break;
            case 2 : PORTA.2 = 1; while(1){if(PINA.6 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTA.2 = 0;delay_ms(250); break;
            case 3 : PORTA.3 = 1; while(1){if(PINA.7 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTA.3 = 0;delay_ms(250); break;
            case 4 : PORTB.4 = 1; while(1){if(PINB.0 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTB.4 = 0;delay_ms(250); break;
            case 5 : PORTB.5 = 1; while(1){if(PINB.1 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTB.5 = 0;delay_ms(250); break;
            case 6 : PORTB.6 = 1; while(1){if(PINB.2 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTB.6 = 0;delay_ms(250); break;
            case 7 : PORTB.7 = 1; while(1){if(PINB.3 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTB.7 =  0;delay_ms(250); break;
            case 8 : PORTE.0 = 1; while(1){if(PINE.4 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTE.0 = 0;delay_ms(250); break;
            case 9 : PORTE.1 = 1; while(1){if(PINE.5 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTE.1 = 0;delay_ms(250); break;
            case 10 : PORTE.2 = 1; while(1){if(PINE.6 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}}PORTE.2 = 0;delay_ms(250); break;
            case 11 : PORTE.3 = 1; while(1){if(PINE.7 == 0){count += 0x10;if(count > 0x90){count = 0x01; PORTC = count;}PORTC = count;n = 0;buzzer();break;}delay_ms(1);n++;if(n >= 1250){n = 0;break;}} PORTE.3 = 0;delay_ms(250); break;
        }
        if(count > 0x90){count = 0x01; PORTC = count;}
 if(count > 0x91){count = 0x02; PORTC = count;}
 if(count > 0x92){count = 0x03; PORTC = count;}
        delay_ms(500);       
    }
}

interrupt [TIM1_OVF] void timer_int1(void)
{
    sec++;
    if(sec == 34)
    {                            
        timer--;
        if(timer == 0x5f){timer = 0b01011001;}
        if(timer == 0x4f){timer = 0b01001001;}
        if(timer == 0x3f){timer = 0b00111001;}
        if(timer == 0x2f){timer = 0b00101001;}
        if(timer == 0x1f){timer = 0b00011001;}
        if(timer == 0x0f){timer = 0b00001001;}
        if(timer == 0x00){PORTF = timer; PORTC=0x00;End(); End(); End();while(1);}
        PORTF = timer;                             
        sec = 0;
    }
}