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
#include"level4.h"
#include"level5.h"

level4::level4(){

    for (int i=0;i<82;i++){
    
  if(i==0||i==8||i==9||i==16||i==19||i==24||i==29||i==32||i==39||i==48||i==50||i==56||i==60||i==64||i==70||i==72||i==80||i==81)
  {
         arr[0]="   S  ";
         arr[8]="  M1  ";
         arr[9]="  M4  ";
         arr[16]="  M5  ";
         arr[19]="  M8  ";
         arr[24]="  M9  ";
         arr[29]="  M12 ";
         arr[32]="  M13 ";
         arr[39]="   E  ";
         arr[48]="  M15 ";
         arr[50]="  M14 ";
         arr[56]="  M11 ";
         arr[60]="  M10 ";
         arr[64]="  M7  ";
         arr[70]="  M6  ";
         arr[72]="  M3  ";
         arr[80]="  M2  ";
         arr[81]="hr";
  }
  else if (i==1||i==2||i==3||i==4||i==5||i==6||i==7)
      {arr[i]="......";}

  else {arr[i]="      ";}
  }
    side=9;
    choice=0;
    s="  M1  ";
 }
  void level4::printboard()
{ printw("\n\n\n");
  start_color();
  use_default_colors();
	init_pair(5,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(5));
   printw("    ______ ______ ______ ______ ______ ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<9;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7+9*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+8+9*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|______|______|______|______|______|   \n");
  refresh();
  }
  attroff(COLOR_PAIR(5));
}

int level4::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
      result[49]="......";
      result[48]="   \\  ";
      result[81]="vu";

      if(result[48]==arr[48] && result[49]==arr[49] && result[81]==arr[81])
      {y = 0;}
    return y;
  }
}

int level4::resultant()
{
return resultarr();
}
void level4::on(State *st)
{
  
  printw("\n\n     Congrats, Level 4 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level5());
  st->ray->side=10;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
