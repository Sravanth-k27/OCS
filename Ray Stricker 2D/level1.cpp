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
#include<stdio.h>
#include<string>
#include<cstring>
#include<ncurses.h>
#include"ray.h"
#include"level1.h"
#include"level2.h"
//constructor level1
level1::level1()
  {
  for(int i=0;i<17;i++)
  { 
  
    if (i==2||i==9||i==4||i==11||i==6||i==14||i==5||i==16||i==15)
    {
      arr[4]="   S  ";
      arr[6]="  M2  ";
      arr[2]="  M1  ";
      arr[9]="  M3  ";
      arr[14]="  M4  ";
      arr[15]="  M5  ";
      arr[11]="   E  ";
      arr[5]="......";
      arr[16]="hr";
    }
    else
    {
      arr[i]="      ";
    }
  }
    side=4;
    choice=0;
    s="  M1  ";
  }


//prints the board and string array inside grid
void level1::printboard()
{
  {printw("\n\n\n");
  start_color();
  use_default_colors();
	init_pair(2,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(2));
  printw("    ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<4;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+4*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+4*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+4*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+4*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|   \n");
  refresh();
  }
  
  attroff(COLOR_PAIR(2));
}
}
//returns 0 if level is completed else returns 1
int level1::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <17;i++)
  { 
    if (i==4||i==6||i==14||i==5||i==16||i==15||i==11||i==10)
    {
      result[4]="   S  ";
      result[6]="   \\  ";
      result[14]="   \\  ";
      result[15]="   /  ";
      result[11]="   E  ";
      result[5]="......";
      result[16]="vu";
      result[10]="   :  ";
      
    }
    else
    {
      result[i]="      ";
    }
  }
  for(i=0;i <17;i++)
  {
    if (i==4||i==5||i==6||i==10||i==11||i==14||i==15||i==16)
    {
    if(result[i]==arr[i])
    {
      y=0;
    }
    else if (result[i]!=arr[i])
    {
      y=1;
      break;
    }
    }
  }
  return y;
  }
}
//returns int returned by resultarr
int level1::resultant()
{return resultarr();}
//creates next level
void level1::on(State *st)
{
  
  printw("\n\n     Congrats, Level 1 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level2());
  st->ray->side=6;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
