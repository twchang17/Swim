
#include <MeggyJrSimple.h>    
int X=1;
int Y=1;
int X1=6;
int Y1=7;
int X2=1;
int Y2=7;
int X3=7;
int Y3=0;
boolean gameOver = false;
boolean X1Alive = true;
boolean X2Alive = true;
boolean X3Alive = true;

void setup()                 
{
  MeggyJrSimpleSetup();     
}

void loop()                   
{
  while (gameOver == false)
{
  DrawPx(X,Y,White);
  if(X1Alive)
    DrawPx(X1,Y1,Green);
  else
    DrawPx(X1,Y1,Red);
  if(X2Alive)
    DrawPx(X2,Y2,Blue);
  else
    DrawPx(X2,Y2,Red);
  if(X3Alive)
    DrawPx(X3,Y3,Orange);
  else
    DrawPx(X3,Y3,Red);
  DisplaySlate();
  ClearSlate(); 
  playerMovement();
  //updateAmmo
  if (X1Alive)
    enemy1();
  if (X2Alive)
    enemy2();
  if (X3Alive)
    enemy3();
  crash();
  collide();
  
                  
}
  displayX();
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
      Y1++;
    if(Y<Y1)
      Y1--;
  }
  if(Button_Down) 
  { 
    if(Y>Y1)
      Y1++;
    if(Y<Y1)
      Y1--;
  }
}
// enemy is moving along with player
// can't fully move player, maybe enemy code is preventing

void enemy2()
{
  if(Button_Left) 
  { 
    if(X>X2)
    X2++;
    if(X<X2)
    X2--;
  }
  if(Button_Right)
  { 
    if(X>X2)
    X2++;
    if(X<X2)
    X2--;
  }  
  if(Button_Up) 
  { 
    if(Y>Y2)
    Y2++;
    if(Y<Y2)
    Y2--;
  }
  if(Button_Down) 
  { 
    if(Y>Y2)
    Y2++;
    if(Y<Y2)
    Y2--;
  }
}

void enemy3()
{
  if(Button_Left) 
  { 
    if(X>X3)
    X3++;
    if(X<X3)
    X3--;
  }
  if(Button_Right)
  { 
    if(X>X3)
    X3++;
    if(X<X3)
    X3--;
  }  
  if(Button_Up) 
  { 
    if(Y>Y3)
    Y3++;
    if(Y<Y3)
    Y3--;
  }
  if(Button_Down) 
  { 
    if(Y>Y3)
    Y3++;
    if(Y<Y3)
    Y3--;
  }
}
void flag()
{
  DrawPx(7,2,Blue);
}

  
void crash() {
 if (X1==X && Y1==Y)
  {
    gameOver=true;
  }
}  
  
void displayX()
{
  for(int i=0; i<8; i++)
    for(int p=0; p<8; p++)
    {
      DrawPx(i,p,6);
    }
  DisplaySlate();
  CheckButtonsPress();
  if(Button_A) {
    gameOver=false;
    X=1;
    Y=1;
    X1=6;
    Y1=7;
    X2=1;
    Y2=7;
    X3=7;
    Y3=0;
    X1Alive = true;
    X2Alive = true;
    X1Alive = true;
    X3Alive = true;
    X2Alive = true;
    X3Alive = true;
    
  ClearSlate();
}
}

void collide() {
if(X1==X2 && Y1==Y2)
  {
    X1Alive = false;
    X2Alive = false;
  }
if(X1==X3 && Y1==Y3)
  {
    X1Alive = false;
    X3Alive = false;
  }  
if(X2==X3 && Y2==Y3)
  {
    X2Alive = false;
    X3Alive = false;
  }  
}


    
    
