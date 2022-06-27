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
#include"level7.h"
#include"level8.h"

level7::level7(){

    for (int i=0;i<82;i++){
    
  if(i==0||i==2||i==13||i==15||i==26||i==54||i==65||i==67||i==78||i==80||i==81)
  {
         arr[0]="  M1  ";
         arr[2]="  M2  ";
         arr[13]="  M5  ";
         arr[15]="  M6  ";
         arr[26]="   E  ";
         arr[54]="   S  ";
         arr[65]="  M3  ";
         arr[67]="  M4  ";
         arr[78]="  M7  ";
         arr[80]="  M8  ";
         arr[81]="vu";
  }
  else if (i%9==0 && i<54)
      {arr[i]="   :  ";}

  else {arr[i]="      ";}
  }
    side=9;
    choice=0;
    s="  M1  ";
 }
  void level7::printboard()
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

int level7::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
      result[79]="......";
      result[80]="   /  ";
      result[81]="vu";

      if(result[79]==arr[79] && result[80]==arr[80] && result[81]==arr[81])
      {y = 0;}
    return y;
  }
}

int level7::resultant()
{
return resultarr();
}
void level7::on(State *st)
{
  
  printw("\n\n     Congrats, Level 7 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level8());
  st->ray->side=10;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
