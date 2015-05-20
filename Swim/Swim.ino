#include <MeggyJrSimple.h> 

int X=1; //player x
int Y=1; //player y

struct Point
{
  int x;
  int y;
};

Point p1 = {6,7}; //enemies kept in an array
Point p2 = {1,7};
Point p3 = {7,0};
Point p4 = {3,4};
Point e[64] = {p1,p2,p3,p4};

boolean gameOver = false; //running game while false, when true displays X
boolean X1Alive = true; // enemy 1 alive
boolean X2Alive = true; // enemy 2 alive
boolean X3Alive = true; //enemy 3 alive
boolean X4Alive = true; //enemy 4 alive
void setup()                 
{
  MeggyJrSimpleSetup();     
}

void loop()                   
{
  while (gameOver == false)
{
  level1();
  level2();
  playerMovement();
  //updateAmmo
  if (X1Alive) //movement
    enemy1();
  if (X2Alive) //movement
    enemy2();
  if (X3Alive) //movement
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
// enemy is moving along with player
// can't fully move player, maybe enemy code is preventing

void enemy2()
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

void enemy3()
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

void enemy4()
{
  if(Button_Left) 
  { 
    if(X>e[3].x)
      e[3].x++;
    if(X<e[3].x)
      e[3].x--;
  }
  if(Button_Right)
  { 
    if(X>e[3].x)
      e[3].x++;
    if(X<e[3].x)
      e[3].x--;
  }  
  if(Button_Up) 
  { 
    if(Y>e[3].y)
      e[3].y++;
    if(Y<e[3].y)
      e[3].y--;
  }
  if(Button_Down) 
  { 
    if(Y>e[3].y)
      e[3].y++;
    if(Y<e[3].y)
      e[3].y--;
  }
}
void flag()
{
  DrawPx(7,2,Blue);
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
    e[0].x=6;
    e[0].y=7;
    e[1].x=1;
    e[1].y=7;
    e[2].x=7;
    e[2].y=0;
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
if(e[0].x==e[3].x && e[0].y==e[3].y)
  {
    X2Alive = false;
    X3Alive = false;
  } 
if(e[1].x==e[3].x && e[1].y==e[3].y)
  {
    X2Alive = false;
    X3Alive = false;
  }   
if(e[2].x==e[3].x && e[2].y==e[3].y)
  {
    X2Alive = false;
    X3Alive = false;
  }   
}


void level1() {
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
}

void level2() {
e[0].x=6,e[0].y=6;
e[1].x=5,e[1].y=1;
e[2].x=0,e[2].y=7;
e[3].x=3,e[3].y=4;
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
  if(X4Alive)
    DrawPx(e[3].x,e[3].y,Yellow); //enemy 3 (drawings) Orange
  else
    DrawPx(e[3].x,e[3].y,Red);    
  DisplaySlate();
  ClearSlate();
}
  
// lv2. e1 (6,6) ; e2(5,1) ; e3(0,7) ; e4(3,4)
// lv3. e1 (6,0) ; e2(7,1) ; e3(3,5) ; e4(2,3) ; e5(0,4)
// don't know if i should add more enemies, becomes near impossible
// how to add levels?? 


   


    
    
