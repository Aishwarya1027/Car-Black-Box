/* 
 * File:   black_box.h
 * Author: Poomani Krishna
 *
 * Created on 28 April, 2026, 5:32 PM
 */

#ifndef BLACK_BOX_H
#define	BLACK_BOX_H

#include <xc.h>
#include"clcd.h"
#include"adc.h"
#include"i2c.h"
#include"ds1307.h"
#include"matrix_keypad.h"

/* Enum for maintaining the app state */
typedef enum {
    e_dashboard, e_main_menu, e_view_log, e_set_time, e_download_log, e_clear_log
} State_t;


extern State_t state; // App state
unsigned char speed[4];
unsigned char events[9][3]={"ON","GN","G1","G2","G3","G4","G5","GR"," C"};
int pos;
unsigned char key;

//Function declarations

//Dashboard function declaration
void view_dashboard(void);

//Storing events function declaration
void event_store(void);


//main menu function declaration
void display_main_menu(void);

//View log function declaration
void view_log(void);

//Reading events function declaration
void event_reader(void);

//Set time function declaration
void set_time(void);

//Download log function_decleration
void download_log(void);

//Clear log function declaration
void clear_log(void);
//display speed
void display_speed(void);
 //display gear shifting based on switch press
  void  display_gear_shifting(void);
#endif	/* BLACK_BOX_H */

