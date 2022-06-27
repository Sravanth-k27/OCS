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
#include"level2.h"
#include"level3.h"
level2::level2()
  {
    for(int i=0;i <37;i++)
  { 
    if (i==0||i==1||i==2||i==3||i==6||i==14||i==21||i==22||i==25||i==34||i==35||i==36)
    {
      arr[0]="   S  ";
      arr[1]="......";
      arr[2]="......";
      arr[3]="  M1  ";
      arr[6]="  M2  ";
      
      arr[14]="  M4  ";
      
      arr[21]="  M3  ";
      arr[22]="  M5  ";
      arr[25]="  M6  ";
      arr[34]="  M7  ";
      
      arr[35]="   E  ";
      arr[36]="hr";
    }
    else
    {
      arr[i]="      ";
    }
  }


    side=6;
    choice=0;
    s="  M1  ";
  }



  void level2::printboard()
{
  {printw("\n\n\n");
	start_color();
  use_default_colors();
	init_pair(4,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(4));
  printw("    ______ ______ ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<6;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+6*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+6*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|______|______|   \n");
  refresh();
  }
  attroff(COLOR_PAIR(4));
}
}

int level2::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <37;i++)
  { 
    if (i==0||i==1||i==2||i==3||i==9||i==15||i==21||i==22||i==28||i==34||i==35||i==36)
    {
      result[0]="   S  ";
      result[1]="......";
      result[2]="......";
      result[3]="   \\  ";
      result[9]="   :  ";
      result[15]="   :  ";
      result[21]="   \\  ";
      result[22]="   \\  ";
      result[28]="   :  ";
      result[34]="   \\  ";
      result[35]="   E  ";
      result[36]="hr";
    }
    else
    {
      result[i]="      ";
    }
  }
  for(i=0;i <37;i++)
  {
    if (i==0||i==1||i==2||i==3||i==9||i==15||i==21||i==22||i==28||i==34||i==35||i==36)
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

int level2::resultant()
{return resultarr();}

void level2::on(State *st)
{
  
  printw("\n\n     Congrats, Level 2 complete.\n      Press any key to continue\n\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level3());
  st->ray->side=8;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
