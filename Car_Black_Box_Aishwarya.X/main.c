/*
 * File:   main.c
 * Author: Poomani Krishna
 *
 * Created on 28 April, 2026, 5:29 PM
 */

#include "black_box.h"

State_t state;

void init_config()
{
    
    state = e_dashboard;
    init_clcd();
    init_adc();
    init_i2c();
    init_ds1307();
    init_matrix_keypad();
}

void main(void) 
{
    init_config();

    while(1)
    {
        // Detect key press
       key=read_switches(STATE_CHANGE);
       if(key==MK_SW4)//go to main menu
          state = e_main_menu; 
        switch (state)
        {
            case e_dashboard:
                // Display dashboard
                view_dashboard();
                break;
            
            case e_main_menu:
                // Display dashboard
                display_main_menu();
                break;
            
            case e_view_log:
                // Display dashboard
                //view_log();
                break;
                 
            case e_download_log:
                //download_log();
                break;
                
            case e_clear_log:
                //clear_log();
                break;
                
                      
            case e_set_time:
                //set_time();
                break;
                
        }
        
    }
    
}
