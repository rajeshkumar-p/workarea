/* This Program implements a state Machine for
 * simple switch( ON/OFF) Which does the action to switch ON/OFF bulb.
 * http://amsekharkernel.blogspot.com/search/label/Simple%20Finite%20State%20Machine%20for%20Beginners
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX_STATES 2

typedef enum FSM_STATES
{
   STATE_OFF,
   STATE_ON
}FSM_STATES;

typedef enum FSM_EVENTS
{
   SWITCHOFF_BULB,
   SWITCHON_BULB       
}FSM_EVENTS;

void FSM_Event_Handler_Function(FSM_EVENTS fsm_event);
void SwitchOn_Bulb(FSM_EVENTS fsm_event,  char *p);
void SwitchOff_Bulb(FSM_EVENTS fsm_event,  char *p);

/** Function Pointer, Declare array of pointers.
  * One way of declaring the Array of pointers by using below syntax */ 
typedef void (*action_func)(FSM_EVENTS fsm_event,  char *p);

/*  Array of Action Functions */
action_func  array_of_func_Pointers[MAX_STATES] = { SwitchOff_Bulb,
   SwitchOn_Bulb };

FSM_STATES fsm_state = STATE_OFF;

void SwitchOn_Bulb(FSM_EVENTS fsm_event,  char *p)
{
   printf(" \nBefore Switch On FSM State is :%d\n", fsm_state);

   /* Change the fsm_state */
   fsm_state = STATE_ON;

   printf(" The Event is :%d\n", fsm_event);   
   printf(" The FSM State changed to :%d\n", fsm_state);   
   printf(" The Trigger from this Function :%s\n", p);

}

void SwitchOff_Bulb(FSM_EVENTS fsm_event, char *p)
{
   printf(" \nBefore Switch OFF FSM State is :%d\n", fsm_state);

   /* Change the fsm_state */
   fsm_state = STATE_OFF;

   printf(" The Received Event is :%d\n", fsm_event);   
   printf(" The FSM State changed to  :%d\n", fsm_state);   
   printf(" The Trigger from this Function :%s\n", p);

}

void FSM_Event_Handler_Function(FSM_EVENTS fsm_event)
{
   switch(fsm_event)
   {
      case SWITCHOFF_BULB:
         /* State is ON */
         if(fsm_state == STATE_ON)
         {
            /* OFF THE BULB */
            array_of_func_Pointers[SWITCHOFF_BULB](fsm_event, 
                  " HEY SWITCH OFF THE BULB, SAVE THE POWER \n");
         }
         else       
         {
            if(fsm_state == STATE_OFF)
            {               
               printf("\nHEY ALREADY BULB is in OFF STATE, SO NO ACTION is TAKEN, RELAX \n");

            }
         }
         break;

      case SWITCHON_BULB:
         /* State is OFF */
         if(fsm_state == STATE_OFF)
         {
            /* ON THE BULB */
            array_of_func_Pointers[SWITCHON_BULB](fsm_event,  
               " HEY SWITCH ON THE BULB, HERE VERY DARK \n");
         }
         else       
         {
            if(fsm_state == STATE_ON)
            {               
               printf(" \nHEY ALREADY BULB is in ON STATE, SO No ACTION is TAKEN, RELAX \n");
            }
         }
         break;

      default:
         printf("INVALID EVENT RECIEVED \n");
         break;
   }   
}

int main()
{

   int triggerEvent;

   do
   {
      printf("\n------------------------- \n");
      printf(" Enter the Event to be TRIGGER \n");
      printf(" Enter '0' to Switch Off the BULB \n");
      printf(" Enter '1' to Switch ON the BULB \n");
      printf(" Enter '10' to EXIT \n");
      scanf("%d", &triggerEvent);
      printf("--------------------------- \n");

      /* Call the Handler Function */
      FSM_Event_Handler_Function((FSM_EVENTS) triggerEvent );

   }while(triggerEvent != 10);

}
