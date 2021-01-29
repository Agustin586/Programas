#include "Display.h"

// **DISPLAY MAINS MENUS** //
// --BEGIN MENU --> INIT-- //
void Display_init(void)
{
   unsigned int _load=0;
   struct button load = {5,300,240-27,240-2,CL_BLUE};
   
   //TFT_Set_Brush(1,CL_GREEN,0,0,0,0);
   //TFT_Rectangle( 90, 90, 160, 110);
   //TFT_Set_Font(Broadway_Italic_27x16, CL_BLACK, FO_HORIZONTAL);
   
   // Write Initial information ///
   TFT_Fill_Screen(CL_WHITE);
   x=2,y=2;
   TFT_Set_Pen(CL_BLACK, 2);
   TFT_Rectangle(x,y,x+298,y+60);

   x=5,y=5;
   TFT_Set_Font(TFT_defaultFont, CL_RED, FO_HORIZONTAL);
   TFT_Write_Const_Text(autor,x,y);
   y+=20;
   TFT_Write_Const_Text(fecha,x,y);
   y+=20;
   TFT_Write_Const_Text(progm,x,y);
   // End write //
   
   x=2;
   TFT_Set_Pen(CL_BLUE, 2);
   TFT_Rectangle(load.Xs,load.Ys,load.Xe+3,load.Ye);
   Delay_ms(30);
   
   TFT_Set_Brush(1,load.backgroundColour,0,0,0,0);
   
   // Animation load //
   for(_load=5;_load<301;_load++)
   {
      TFT_Rectangle(_load,load.Ys,(load.Xs-2)+_load,load.Ye);
      Delay_ms(10);
   }
   Delay_ms(1500);
   // End animation //

   return;
}
// --END MENU --> INIT-- //
// END //

// **DISPLAY SUBMENUS** //
// --BEGIN SUBMENU --> MENU-- //
void SubmMenu_DisplayInit(void)
{
   StaticDisplay();
   MenuGenerator(4,10,2);
   
   return;
}
// --END SUBMENU --> MENU-- //
// END //

void ChangeTheme(void)
{
   struct theme dark_green = {CL_BLACK,CL_WHITE,CL_LIME,CL_GREEN};
   struct theme fuchsia_black = {CL_FUCHSIA,CL_BLACK,CL_FUCHSIA,CL_BLACK};
   struct theme blue_white = {CL_BLUE,CL_WHITE,CL_AQUA,CL_BLACK};
   struct theme white_blue = {CL_WHITE,CL_BLUE,CL_AQUA,CL_BLACK};

   if(Pos==1)        actual_theme = dark_green;
   else if(Pos==2)   actual_theme = fuchsia_black;
   else if(Pos==3)   actual_theme = blue_white;
   else if(Pos==4)   actual_theme = white_blue;

   ThemeUpdated();

   return;
}


// **FOR ALL MENUS AND SUBMENUS** //
void MenuGenerator(unsigned char menu_cant,unsigned char separacion,unsigned char _widthEdge)
{
   char i=1;
   unsigned char width=((316/(menu_cant/2))-(separacion*2));
   unsigned char high=((213/(menu_cant/2))-(separacion*2));
   
   // Button Structure adn setup //
   struct button button1;
   button1.Xs = 2;
   button1.Ys = 25;
   button1.Xe = button1.Xs + width;
   button1.Ye = button1.Ys + high;
   button1.backgroundColour = actual_theme.backgroundletterColour;
   button1.edgeColour = actual_theme.edgeColour;
   button1.width = _widthEdge;
   // End //
   
   // Set background and edge colour //
   TFT_Set_Pen(button1.edgeColour,button1.width);
   TFT_Set_Brush(1,button1.backgroundColour,0,0,0,0);
   // End //
   
   // Generator buttons //
   for(i=1;i<=menu_cant;i++)
   {
      TFT_Rectangle_Round_Edges(button1.Xs+separacion,button1.Ys+separacion,button1.Xe,button1.Ye,12);
      button1.Xs = button1.Xe;
      button1.Xe = separacion + width;
      button1.Ys = button1.Ye;
      button1.Ye = separacion + high;
   }
   // End //
   ThemeUpdated();

   return;
}

void Selector(unsigned char estate)
{
   if(estate==_ESTATE_MENU)
   {
   
   }
   else if(estate==_ESTATE_OUTPUT)
   {
   
   }
   else if(estate==_ESTATE_THEME)
   {
   
   }

   return;
}

void StaticDisplay(void)
{
   TFT_Fill_Screen(actual_theme.screenColour);
//   TFT_Set_Brush(0,actual_theme.backgroundletterColour,0,0,0,0);
//   TFT_Set_Pen(actual_theme.edgeColour, 3);
   TFT_Rectangle(1,1,319,239);
   TFT_H_Line(10,310,25);

   DateUpdated();

   return;
}

void DateUpdated(void)
{
   char buffer1[4];
   
   // Clear Position for write //
   TFT_Set_Brush(1,actual_theme.screenColour,0,0,0,0);
   TFT_Set_Pen(actual_theme.screenColour, 3);
   TFT_Rectangle(200,4,316,22);
   ThemeUpdated();
   // End //
   
   // Write Date //
   x=210;
   y=4;
   IntToStr(day,buffer1),TFT_Write_Text("11/11/11   12:12",x,y);
//   x=200+28,TFT_Write_Text("/",x,y);
   
//   x=x+14;
//   IntToStr(week,buffer1),TFT_Write_Text(buffer1,x,y);
//   x=x+28;
//   TFT_Write_Text("/",x,y);
//
//   x=x+14;
//   IntToStr(year,buffer1),TFT_Write_Text(buffer1,x,y);
//   x=x+28;
//   TFT_Write_Text("/",x,y);
   // End write date //
   
   // Write Time //
//   sprintf(buffer4,"%02d:",hour);
//   sprintf(buffer5,"%02d",minute);
//   IntToStr(buffer4,hour);
//   IntToStr(buffer5,minute);
//   strcat(buffer3,buffer4);
//   strcat(buffer4,buffer5);

   // End write time //
   
   return;
}

void ThemeUpdated(void)
{
   TFT_Set_Font(TFT_defaultFont,actual_theme.letterColour,FO_HORIZONTAL);
   TFT_Set_Brush(0,actual_theme.backgroundletterColour,0,0,0,0);
   TFT_Set_Pen(actual_theme.edgeColour, 1);

   return;
}
// **END FOR ALL MENUS AND SUBMENUS** //



