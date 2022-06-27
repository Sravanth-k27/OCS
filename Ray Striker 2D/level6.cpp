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
#include"level6.h"
#include"level7.h"
level6::level6(){

 for(int i=0;i<101;i++){
   if(i==13||i==15||i==30||i==31||i==32||i==33||i==25||i==27||i==57||i==58||i==88||i==89||i==79||i==100){
      arr[13]="  M2  ";
      arr[15]="  M3  ";
      arr[30]="   S  ";
      arr[31]="......";
      arr[32]="......";
      arr[33]="  M1  ";
      arr[25]="  M4  ";
      arr[27]="  M5  "; 
      arr[57]="  M6  ";
      arr[58]="  M7  ";
      arr[88]="  M8  ";
      arr[89]="  M9  ";
      arr[79]="   E  ";
      arr[100]="hr";
     
   }
   else {
        arr[i]="      ";
        
       }
 }
    side=10;
    choice=0;
    s="  M1  ";
}
 
void level6::printboard()
{
  {printw("\n\n\n");
	start_color();
  use_default_colors();
	init_pair(4,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(4));
  printw(" ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ \n");
  refresh();
  for(int i=0;i<10;i++)
  {printw("|");
  wprintw(stdscr,(arr+0+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+7+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+8+10*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+9+10*i)->data());
  refresh();
  printw("|\n");
  refresh();
  printw("|______|______|______|______|______|______|______|______|______|______|\n");
  refresh();
  }
  attroff(COLOR_PAIR(4));
}
}
int level6::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <101;i++)
  { 
    if(i==30||i==31||i==32||i==33||i==23||i==13||i==14||i==15||i==25||i==26||i==27||i==37||i==47||i==57||i==58||i==68||i==78||i==88||i==89||i==79||i==100){
      result[30]="   S  ";
      result[31]="......";
      result[32]="......";
      result[33]="   /  ";
      result[23]="   :  ";
      result[13]="   /  ";
      result[14]="......";
      result[15]="   \\  ";
      result[25]="   \\  ";
      result[26]="......";
      result[27]="   \\  ";
      result[37]="   :  ";
      result[47]="   :  ";
      result[57]="   \\  ";
      result[58]="   \\  ";
      result[68]="   :  ";
      result[78]="   :  ";
      result[88]="   \\  ";
      result[89]="   /  ";
      result[79]="   E  ";
      result[100]="vu";
    }
    else {
      result[i]="      ";
    }
    }
    for(i=0;i<101;i++)
    {
     if(i==30||i==31||i==32||i==33||i==23||i==13||i==14||i==15||i==25||i==26||i==27||i==37||i==47||i==57||i==58||i==68||i==78||i==88||i==89||i==79||i==100)
      {
       if(result[i]==arr[i]){
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
int level6::resultant()
{return resultarr();}

void level6::on(State *st)
{
  
  printw("\n\n     Congrats, Level 6 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level7());
  st->ray->side=9;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
