// 1999-08-16 bkoz

// Copyright (C) 1999, 2000, 2002, 2003 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// 27.6.2.5.4 basic_ostream character inserters

#include <string>
#include <ostream>
#include <sstream>
#include <testsuite_hooks.h>

// ostringstream and large strings number 2
void
test05()
{
  bool test __attribute__((unused)) = true;
  std::string str05, str10;

  typedef std::ostream::pos_type	pos_type;
  typedef std::ostream::off_type	off_type;
  std::string str01;
  const int size = 1000;

  // initialize string
  for(int i=0 ; i < size; i++) {
    str01 += '1';
    str01 += '2';
    str01 += '3';
    str01 += '4';
    str01 += '5';
    str01 += '6';
    str01 += '7';
    str01 += '8';
    str01 += '9';
    str01 += '\n';
  }

  // test 1: out
  std::ostringstream sstr01(str01, std::ios_base::out);
  std::ostringstream sstr02;
  sstr02 << str01;
  str05 = sstr01.str();
  str10 = sstr02.str();
  VERIFY( str05 == str01 );
  VERIFY( str10 == str01 );

  // test 2: in | out 
  std::ostringstream sstr04(str01,  std::ios_base::out | std::ios_base::in);
  std::ostringstream sstr05(std::ios_base::in | std::ios_base::out);
  sstr05 << str01;
  str05 = sstr04.str();
  str10 = sstr05.str();
  VERIFY( str05 == str01 );
  VERIFY( str10 == str01 );
}

int main()
{
  test05();
  return 0;
}
