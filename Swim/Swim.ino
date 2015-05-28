#include <MeggyJrSimple.h> 

int X=1; //player x
int Y=1; //player y
int level=1;
struct Point
{
  int x;
  int y;
};

Point p1 = {6,7}; //enemies kept in an array
Point p2 = {1,7};
Point p3 = {7,0};
Point e[64] = {p1,p2,p3};

boolean gameOver = false; //running game while false, when true displays X
boolean X1Alive = true; // enemy 1 alive
boolean X2Alive = true; // enemy 2 alive
boolean X3Alive = true; //enemy 3 alive

void setup()                 
{
  MeggyJrSimpleSetup();     
}

void loop()                   
{
  while (gameOver == false)
  {
    if(level==1){
      
    DrawPx(X,Y,White); //player
  if(X1Alive)
    DrawPx(e[0].x,e[0].y,Green); //enemy 1 (drawings) Green
  else
    DrawPx(e[0].x,e[0].y,Red);
  if(X2Alive)
    DrawPx(e[1].x,e[1].y,Blue); //enemy 2 (drawings) Blue
  else
    DrawPx(e[1].x,e[1].y,Red);
  if(X3Alive)
    DrawPx(e[2].x,e[2].y,Orange); //enemy 3 (drawings) Orange
  else
    DrawPx(e[2].x,e[2].y,Red);
  DisplaySlate();
  ClearSlate(); 
  playerMovement();
  if (X1Alive) //movement
    enemy1();
  if (X2Alive) //movement
    enemy2();
  if (X3Alive) //movement
    enemy3();
  crash(); // player with enemy collison
  collide(); // enemy with enemy collision
  
   if(X1Alive == false && X2Alive == false && X3Alive == false) //advance to next level
    {
      DrawPx(0,7,Violet);  
      DisplaySlate();  
    }
    if(ReadPx(X,Y) == Violet) 
    {
     level++; //setting up next level coordinates
      X=2;
      Y=7;
      e[0].x=5;
      e[0].y=4;
      e[1].x=5;
      e[1].y=1;
      e[2].x=0;
      e[2].y=3;
 X1Alive = true; // enemy 1 alive again
 X2Alive = true; // enemy 2 alive again
 X3Alive = true; //enemy 3 alive again
    }  
} 
    if (level==2) { 
      
    DrawPx(X,Y,White); //player
  if(X1Alive)
    DrawPx(e[0].x,e[0].y,Green); //enemy 1 (drawings) Green
  else
    DrawPx(e[0].x,e[0].y,Red);
  if(X2Alive)
    DrawPx(e[1].x,e[1].y,Blue); //enemy 2 (drawings) Blue
  else
    DrawPx(e[1].x,e[1].y,Red);
  if(X3Alive)
    DrawPx(e[2].x,e[2].y,Orange); //enemy 3 (drawings) Orange
  else
    DrawPx(e[2].x,e[2].y,Red);
  DisplaySlate();
  ClearSlate(); 
  playerMovement();
  if (X1Alive) //movement
    enemy1();
  if (X2Alive) //movement
    enemy2();
  if (X3Alive) //movement
    enemy3();
  crash(); // player v enemy
  collide(); // enemy v enemy
  
    if(X1Alive == false && X2Alive == false && X3Alive == false) //Win Screen
    {
     DrawPx(5,7,Green);
     DisplaySlate();
    } 
    if (ReadPx(X,Y) == Green) //Win Screen 
    {
      for(int i=0; i<8; i++)
        for(int p=0; p<8; p++)
        {
          DrawPx(i,p,Green);
          
        } 
      }
           DisplaySlate(); 

 } 
 
} 
  displayX(); // purple game over screen
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

void enemy1() //enemy movement
{
  if(Button_Left) 
  { 
    if(X>e[0].x)
      e[0].x++;
    if(X<e[0].x)
      e[0].x--;
  }
  if(Button_Right)
  { 
    if(X>e[0].x)
      e[0].x++;
    if(X<e[0].x)
      e[0].x--;
  }  
  if(Button_Up) 
  { 
    if(Y>e[0].y)
      e[0].y++;
    if(Y<e[0].y)
      e[0].y--;
  }
  if(Button_Down) 
  { 
    if(Y>e[0].y)
      e[0].y++;
    if(Y<e[0].y)
      e[0].y--;
  }
}

void enemy2() // enemy movement
{
  if(Button_Left) 
  { 
    if(X>e[1].x)
      e[1].x++;
    if(X<e[1].x)
      e[1].x--;
  }
  if(Button_Right)
  { 
    if(X>e[1].x)
      e[1].x++;
    if(X<e[1].x)
      e[1].x--;
  }  
  if(Button_Up) 
  { 
    if(Y>e[1].y)
      e[1].y++;
    if(Y<e[1].y)
      e[1].y--;
  }
  if(Button_Down) 
  { 
    if(Y>e[1].y)
    e[1].y++;
    if(Y<e[1].y)
    e[1].y--;
  }
}

void enemy3() // enemy movement
{
  if(Button_Left) 
  { 
    if(X>e[2].x)
      e[2].x++;
    if(X<e[2].x)
      e[2].x--;
  }
  if(Button_Right)
  { 
    if(X>e[2].x)
      e[2].x++;
    if(X<e[2].x)
      e[2].x--;
  }  
  if(Button_Up) 
  { 
    if(Y>e[2].y)
      e[2].y++;
    if(Y<e[2].y)
      e[2].y--;
  }
  if(Button_Down) 
  { 
    if(Y>e[2].y)
      e[2].y++;
    if(Y<e[2].y)
      e[2].y--;
  }
}


void crash() { //player collison with enemy
 if (e[0].x==X && e[0].y==Y)
  {
    gameOver=true;
  }
 if (e[1].x==X && e[1].y==Y)
  {
    gameOver=true;
  }
 if (e[2].x==X && e[2].y==Y)
  {
    gameOver=true;
  } 
 if (e[3].x==X && e[3].y==Y)
  {
    gameOver=true;
  }   
  
}  
  
void displayX() // gameover screen + button A reset
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
    level=1;
    X=1;
    Y=1;
    e[0].x=6;
    e[0].y=7;
    e[1].x=1;
    e[1].y=7;
    e[2].x=7;
    e[2].y=0;
    e[3].x=7;
    e[3].y=7;
    X1Alive = true;
    X2Alive = true;
    X3Alive = true;
    
  ClearSlate();
}
}

void collide() { // enemy v enemy
if(e[0].x==e[1].x && e[0].y==e[1].y)
  {
    X1Alive = false;
    X2Alive = false;
  }
if(e[0].x==e[2].x && e[0].y==e[2].y)
  {
    X1Alive = false;
    X3Alive = false;
  }  
if(e[1].x==e[2].x && e[1].y==e[2].y)
  {
    X2Alive = false;
    X3Alive = false;
  }    
}


    
    
