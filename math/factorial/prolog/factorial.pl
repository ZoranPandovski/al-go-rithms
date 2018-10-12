/* *************************************************************************
*    Prolog factorial                                                      *
*    Prolog, factorial with recursion                                      *
*                                                                          *
*    Copyright (C) 2017 by Gabriel De Andrade Duarte                       *
*                                                                          *
*    This program is free software; you can redistribute it and/or modify  *
*    it under the terms of the GNU General Public License as published by  *
*    the Free Software Foundation; either version 2 of the License, or     *
*    (at your option) any later version.                                   *
*                                                                          *
*    This program is distributed in the hope that it will be useful,       *
*    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*    GNU General Public License for more details.                          *
*                                                                          *
*    You should have received a copy of the GNU General Public License     *
*    along with this program; if not, write to the                         *
*    Free Software Foundation, Inc.,                                       *
*    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
*                                                                          *
*    To contact the author, please write to:                               *
*    Gabriel De Andrade Duarte <duarte0904@gmail.com>                      *
*    Webpage: http://github.com/gabrielduuarte                             *
*    Phone: +55 (81) 99855-6315                                            *
* ************************************************************************ *
* 
*/


%stopping criterion
factorial(0, 1) :- !.

%recursion
factorial(N, F) :- 
    N1 is N - 1,
    factorial(N1, N2),
    F is N * N2.

