
/*Copyright 2018-2020,2021 Thomas E. Dickey
Copyright 1998-2017,2018 Free Software Foundation, Inc.
Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, distribute with modifications, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
THE USE OR OTHER DEALINGS IN THE SOFTWARE.
Except as contained in this notice, the name(s) of the above copyright
holders shall not be used in advertising or otherwise to promote the
sale, use or other dealings in this Software without prior written
authorization.
-- vile:txtmode fc=72
-- $Id: COPYING,v 1.10 2021/01/01 09:54:30 tom Exp $*/

/*    Copyright (C) 2021  Ray Strikers 2D Team (Megh Shah, Ketan Santosh Sabne, Manaswini Nyalapogula, Kodavanti Rama Sravanth)
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include<iostream>
#include<string>
#include"ray.h"
#include<ncurses.h>
#include"level1.h"
#include"level2.h"
#include"level3.h"
#include"level4.h"
#include"level5.h"
#include"level6.h"
#include"level7.h"
#include"level8.h"

//clang++-7 -std=c++17 -lncurses -o main main.cpp ray.cpp  level1.cpp level2.cpp level3.cpp level4.cpp level5.cpp level6.cpp level7.cpp level8.cpp

int main()
{
  initscr();
  if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color.\n");
		exit(1);
	}
  start_color();			
	init_pair(3,COLOR_BLACK +16,COLOR_WHITE+8);
  wbkgd(stdscr,COLOR_PAIR(3));
  char* c;
  printw("\n\n\n\n          Welcome to Ray Strikers 2D");
  
  unsigned count=1;
  unsigned k;
  unsigned l=0;

  
  
  std::string *arra=static_cast<std::string*>(malloc(2000*sizeof(std::string)));
  std::string s="  M1  ";
  int i=0;
  printinstructions();
  getch();
  clear();
  refresh();
   
  
  refresh();
  int choice=0;
  State stte;
  int y=0;


  // for loop implements next level after previous level is  completed
  for (int j=0;j<8;j++)
  { //ends loop if previous level is not complted
    if(y==0)
  {
    y=1;
    i=1;
    arra=stte.ray->arr;
    int sid=stte.ray->side;
 
  while(y==1)
  {stte.onboard();
  if (i==1)
  { s="  M1  ";}
  else if (i==2)
  { s="  M2  ";}
  else if (i==3)
  { s="  M3  ";}
  else if (i==4)
  { s="  M4  ";}
  else if (i==5)
  { s="  M5  ";}
  else if (i==6)
  { s="  M6  ";}
  else if (i==7)
  { s="  M7  ";}
  else if (i==8)
  { s="  M8  ";}
  else if (i==9)
  { s="  M9  ";}
  else if (i==10)
  { s="  M10 ";}
  else if (i==11)
  { s="  M11 ";}
  else if (i==12)
  { s="  M12 ";}
  else if (i==13)
  { s="  M13 ";}
  else if (i==14)
  { s="  M14 ";}
  else if (i==15)
  { s="  M15 ";}

  printw("\n       Choose mirror M%d orientation\n",i);
  refresh();
  scanw("%d",&choice);
  refresh();
  clear();
  refresh();

  //orientation function implementation
  arra=stte.onorient(0,sid,arra,choice,s);
  stte.ray->arr=arra;
  stte.onboard();
  refresh();
  y=stte.onresult();

  if(y==0)
  {
    if(j<8)
    {
    stte.on();
    refresh();
    break;
    }
  }
  
  else if(y==1&&choice<=4 &&choice>0)
  {
    if(i==5&&j==0)
    {
      printw("\n\n        Level 1 not complete. Try again.\n           Press any key to continue\n");
      
      refresh();
      getch();
      refresh();
    break;
    }
    else if (i==7&&j==1)
    {
      printw("\n\n      Level 2 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
      refresh();
     
      break;
    }
  else if (i==9&&j==2)
    {
      printw("\n\n      Level 3 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
      refresh();
      
      break;
    }
  else if (i==15&&j==3)
    {
      printw("\n\n      Level 4 not complete. Try again.\n         Press any key to continue\n");
      
      getch();
      clear();
      refresh();
      
      break;
    }
    else if (i==7&&j==4)
    {
      printw("\n\n      Level 5 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
     
      break;
    }
    else if (i==9&&j==5)
    {
      printw("\n\n      Level 6 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
     
      break;
    }
    else if (i==8&&j==6)
    {
      printw("\n\n      Level 7 not complete. Try again.\n         Press any key to continue\n");
      refresh();
      getch();
     
      break;
    }
     else if (i==8&&j==7)
     {
	     printw("\n\n   Level8 not complete.Try again.\n   Press any key to continue\n");
	     refresh();
	     getch();
	     
	     break;
     }
     
  }
  if(choice==1||choice==2||choice==3||choice==4)
  {i++;}
 
  refresh();
  clear();
  refresh();
  }
   } 
  }
  getch();
  endwin();
  return 0;
}
