#include <main.h>

#define BUT_1   input(PIN_B4)
#define BUT_2   input(PIN_B5)

int a=0,b=0;
#INT_RB
void interrupt()
{
   while(1)
   {
   if(BUT_1==1)
   {
      a=1;
      while(BUT_1==1)
         {delay_ms(1);}
      while(a==1)
      {
         OUTPUT_BIT(PIN_D5,1);
         
         OUTPUT_BIT(PIN_D6,0);
         if(BUT_2==1)
            {
               a=0;
               break;
               while(BUT_2==0)
         {delay_ms(1);}
            }
      }
   }
   if(BUT_2==1)
   {
      b=1;
      while(BUT_2==1)
         {delay_ms(1);}
      while(b==1)
      {
         
         OUTPUT_BIT(PIN_D5,0);
         
         OUTPUT_BIT(PIN_D6,1);
         if(BUT_1==0)
            {
               b=0;
               break;
               while(BUT_1==1)
         {delay_ms(1);}
            }
      }
   }
}}

void main()
{
   output_d(0x00);
   clear_interrupt(INT_RB);
   enable_interrupts(INT_RB);
   enable_interrupts(GLOBAL);  
}
