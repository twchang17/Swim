
#include <MeggyJrSimple.h>    
int X=1;
int Y=1;
int X1;
int X2;
int X3;
int Y1;
int Y2;
int Y3;
void setup()                 
{
  MeggyJrSimpleSetup();     
}

void loop()                   
{
  DrawPx(X,Y,1);
  DrawPx(X1,X2,Green);
  DisplaySlate();
  ClearSlate(); 
  playerMovement();
  //updateEnemies
  //updateAmmo
  enemy1();
  
                  
}

void playerMovement()
{
  CheckButtonsPress(); //up
  if (Button_Up)
  {
    Y++;
  }
  
  if (Button_Down) //down
  {
    Y--;
  }  
  
  if(Button_Left) //left
  {
    X--; 
  }
  
  if(Button_Right) //right
  {
    X++;
  }     
  
  if(X>7)
  {  
    X--;
  }
  
  if(X<0)
  {
    X++;
  }
  
  if(Y>7)
  {
    Y--;
  }
  
  if(Y<0)
  {
    Y++;
  }
}

void enemy1()
{
  if(Button_Left) 
  { 
    if(X>X1)
    X1++;
    if(X<X1)
    X1--;
  }
  if(Button_Right)
  { 
    if(X>X1)
    X1++;
    if(X<X1)
    X1--;
  }  
  if(Button_Up) 
  { 
    if(Y>Y1)
    Y++;
    if(Y<Y1)
    Y--;
  }
  if(Button_Down) 
  { 
    if(Y>Y1)
    Y++;
    if(Y<Y1)
    Y--;
  }
}
// enemy is moving along with player
// can't fully move player, maybe enemy code is preventing
void flag()
{
  DrawPx(7,2,Blue);
}

  
  

    
    
