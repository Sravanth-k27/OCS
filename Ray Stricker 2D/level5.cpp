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
#include"level5.h" 
#include "level6.h"
level5::level5()
{
  for(int i=0;i<101;i++)
  {
    if(i==4||i==22||i==25||i==45||i==48||i==63||i==93||i==96||i==100)
    {
      arr[4]="  M1  ";
      arr[22]="   S  ";
      arr[23]="......";
      arr[24]="......";
      arr[25]="  M2  ";
      arr[45]="  M3  ";
      arr[48]="  M4  ";
      arr[68]="  M5  ";
      arr[63]="  M6  ";
      arr[93]="  M7  ";
      arr[96]="   E  ";
      arr[100]="hr";
    }
    else
    {
      arr[i]="      ";
    }
  }

  side=10;
  choice=0;
  s="  M1  ";
}

void level5::printboard()
{ printw("\n\n\n");
  start_color();
  use_default_colors();
  init_pair(5,COLOR_BLACK+16,COLOR_YELLOW+8);

  attron(COLOR_PAIR(5));
   printw(" ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
  refresh();
 
 for(int n=0;n<10;n++)
 { printw("|");
  wprintw(stdscr,(arr+0+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+8+10*n)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+9+10*n)->data());
  refresh();
  printw("|\n");
  refresh();
  printw("|______|______|______|______|______|______|______|______|______|______|\n");
  refresh();
 }
  
attroff(COLOR_PAIR(5));
}

int level5::resultarr()
{  
  
    std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
    int i=0;
    int y=1;
    for(i=0;i<101;i++)
    {
      if(i==22||i==23||i==24||i==25||i==35||i==45||i==46||i==47||i==48||i==58||i==68||i==67||i==66||i==65||i==64||i==63||i==73||i==83||i==93||i==94||i==95||i==96||i==100)
      {
      result[22]="   S  ";
      result[23]="......";
      result[24]="......";
      result[25]="   \\  ";
      result[35]="   :  ";
      result[45]="   \\  ";
      result[46]="......";
      result[47]="......";
      result[48]="   \\  ";
      result[58]="   :  ";
      result[68]="   /  ";
      result[67]="......";
      result[66]="......";
      result[65]="......";
      result[64]="......";
      result[63]="   /  ";
      result[73]="   :  ";
      result[83]="   :  ";
      result[93]="   \\  ";
      result[94]="......";
      result[95]="......";
      result[96]="   E  ";
      result[100]="hr";
      }
    
    else
    {
      result[i]="      ";
    }
    }
    for(i=0;i<101;i++)
    {
      if(i==22||i==23||i==24||i==25||i==35||i==45||i==46||i==47||i==48||i==58||i==68||i==67||i==66||i==65||i==64||i==63||i==73||i==83||i==93||i==94||i==95||i==96)
      { if(result[i]==arr[i])
      {y=0;}
      else if(result[i]!=arr[i])
      {y=1;
       break;}
      }
    }
return y;
}

int level5::resultant()
{
  return resultarr();
}

void level5::on(State *st)
{
  
  printw("\n \n      Congrats,level5 is complete. \n  Press any key to continue.\n");
  refresh();
  getch();
  refresh();       clear();
  refresh();
  st->setstate(new level6());
  st->ray->side=10;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
