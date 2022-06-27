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
#ifndef __RAY_H
#define __RAY_H
#include <iostream>
#include <array>

void printinstructions();

class State
{
  public:
  class raystriker *ray;
  
  void setstate(raystriker *r);
  State();
  std::string* onorient(int _i,int side,std::string *arr,int choice,std::string s);
  int onresult();
  void onboard(); 
  void on();
  
};

class raystriker
{
  protected :
  std::string* orientation(int _i,int side,std::string *arr,int choice,std::string s);
 
  public :
  State *st;
  int side;
  std::string* arr=static_cast<std::string*>(malloc(20000));
  int choice;
  std::string s;
  virtual void printboard();
  virtual int resultarr();
  std::string* orient(int _i,int side,std::string *arr,int choice,std::string s);
  virtual void on(State *st);
  virtual int resultant();
};


#endif
