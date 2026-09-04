/*
 * File:   dashboard.c
 * Author: Poomani Krishna
 *
 * Created on 28 April, 2026, 5:31 PM
 */


//#include <xc.h>
#include"black_box.h"
#include"external_eeprom.h"
void view_dashboard(void)
{
    //display the title on 1st line
    clcd_print("  TIME   EV  SP ", LINE1(0));
   //fetch data from RTC
    get_time();
    //display time
    display_time();
    //fetch data from POT(ADC)
    display_speed();
    //display gear shifting based on switch press
    display_gear_shifting();
}
void display_speed(void)
{
    unsigned short adc_val = read_adc(CHANNEL4)/10.23;//RANGE FROM 0 TO 100
    
    speed[0] = (adc_val/100)+48; //first digit of 100-1
    speed[1] = ((adc_val/10) % 10)+48; //second digit of 100-0
    speed[2] = (adc_val % 10)+48; //last digit of 100-0
    
    clcd_print(speed,LINE2(12));
}
void display_gear_shifting(void)
{
    if(key==MK_SW1)//increment gear
    {
        if(pos<7)
          pos++;
    }
    else if(key==MK_SW2)//decrement gear
    {
        if(pos>1)
          pos--; 
    }
    else if(key==MK_SW3)//collision
        pos = 8;
    clcd_print(events[pos],LINE2(9));
}
void event_store(void)
{
    static unsigned int addr = 0x00,log_count;
    int i;
    for(i=0;i<8;i++)
        write_external_eeprom(addr++,time[i]);
    write_external_eeprom(addr++,events[pos][0]);
    write_external_eeprom(addr++,events[pos][1]);
    for(i=0;i<3;i++)
        write_external_eeprom(addr++,speed[i]);
    if(log_count<10)
    {
        ++log_count;
        write_external_eeprom(130,log_count);
    }
    if(addr == 29)
    {
        addr = 0x00;
    }
    
}

