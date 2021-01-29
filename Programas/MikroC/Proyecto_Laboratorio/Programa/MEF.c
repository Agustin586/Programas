#include "MEF.h"

void Mef_init(void)
{
   Estado_Actual = ESTATE_INIT;
   SubEst_Menu = SUBM_MENU_INIT;
   
   return;
}

void Mef_Updated(void)
{
   switch(Estado_Actual)
   {
      case ESTATE_INIT:
      {
         Serial_writeInit();  // Send Initicial info
         Display_init();      // Initializacion on lcd tft
         
         Estado_Actual = ESTATE_MENU;
      break;
      }
      case ESTATE_MENU:
      {
         SubEst_MENU_Updated();

         if(echo) Estado_Actual = ESTATE_UART;
      break;
      }
      case ESTATE_OUTPUT:
      {
      break;
      }
      case ESTATE_RTC:
      {
      break;
      }
      case ESTATE_TESTING:
      {
      break;
      }
      case ESTATE_UART:
      {
         if(echo) Echo_Tx(),echo=0;
         
         Estado_Actual = ESTATE_MENU;
      break;
      }
      case ESTATE_THEME:
      {

      break;
      }
   }

   return;
}

void SubEst_MENU_Updated(void)
{
   switch(SubEst_Menu)
   {
      case SUBM_MENU_INIT:
      {
         Pos = 1;
         ChangeTheme();
         SubmMenu_DisplayInit();
         Pos = 0;
         
         SubEst_Menu = SUBM_MENU_SELECT;
      break;
      }
      case SUBM_MENU_SELECT:
      {
      
      break;
      }
   }

   return;
}
