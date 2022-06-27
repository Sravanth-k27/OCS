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
#include"level3.h"
#include"level4.h"

 level3::level3(){

    for (int i=0;i<65;i++){

  if(i==5||i==11||i==16||i==17||i==18||i==19||i==29||i==30||i==43||i==45||i==55||i==62||i==63||i==64)
  {
         arr[5]="  M1  ";
         arr[11]="  M2  ";
         arr[16]="   S  ";
         arr[17]="......";
         arr[18]="......";
         arr[19]="  M3  ";
         arr[29]="  M6  ";
         arr[30]="  M7  ";
         arr[43]="  M4  ";
         arr[45]="  M5  ";
         arr[55]="   E  ";
         arr[62]="  M8  ";
         arr[63]="  M9  ";
         arr[64]="hr";
  }
       
       else {
        arr[i]="      ";
        
       }
    }
    side=8;
    choice=0;
    s="  M1  ";
 }
 

void level3::printboard()
{
  {printw("\n\n\n");
	start_color();
  use_default_colors();
	init_pair(4,COLOR_BLACK+16,COLOR_YELLOW+8);
  
  attron(COLOR_PAIR(4));
  printw("    ______ ______ ______ ______ ______ ______ ______ ______    \n");
  refresh();
  for(int i=0;i<8;i++)
  {printw("   |");
  wprintw(stdscr,(arr+0+8*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+1+8*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+2+8*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+3+8*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+4+8*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+5+8*i)->data());
  refresh();
  printw("|");
  wprintw(stdscr,(arr+6+8*i)->data());
  refresh();
  printw("|");
   wprintw(stdscr,(arr+7+8*i)->data());
  refresh();
  printw("|   \n");
  refresh();
  printw("   |______|______|______|______|______|______|______|______|   \n");
  refresh();
  }
  attroff(COLOR_PAIR(4));
}
}

int level3::resultarr()
{
  {
  std::string* result=static_cast<std::string*>(malloc(20000*sizeof(std::string)));
  int i=0;
  int y=1;
   for(i=0;i <65;i++)
  { 
    if(i==16||i==17||i==18||i==19||i==27||i==29||i==30||i==35||i==37||i==38||i==43||i==44||i==45||i==46||i==54||i==55||i==62||i==63||i==64){
      result[16]="   S  ";
      result[17]="......";
      result[18]="......";
      result[19]="   \\  ";
      result[27]="   :  ";
      result[29]="   /  ";
      result[30]="   \\  ";
      result[35]="   :  ";
      result[37]="   :  ";
      result[38]="   :  ";
      result[43]="   \\  ";
      result[44]="......";
      result[45]="   /  ";
      result[46]="   :  ";
      result[54]="   :  ";
      result[55]="   E  ";
      result[62]="   \\  ";
      result[63]="   /  ";
      result[64]="vu";
    }
    else {
      result[i]="      ";
    }
    }
    for(i=0;i<65;i++)
    {
     if(i==16||i==17||i==18||i==19||i==27||i==29||i==30||i==35||i==37||i==38||i==43||i==44||i==45||i==46||i==54||i==55||i==62||i==63||i==64)
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

int level3::resultant()
{return resultarr();}

void level3::on(State *st)
{
 
  printw("\n\n     Congrats, Level 3 complete.\n      Press any key to continue\n");
  refresh();
  getch();
  refresh();
  clear();
  refresh();
  st->setstate(new level4());
  st->ray->side=9;
  st->ray->choice=0;
  st->ray->s="  M1  ";
  delete this;
}
