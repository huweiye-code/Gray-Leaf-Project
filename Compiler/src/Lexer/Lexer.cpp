/****************************************************************************************
*	Gray-Leaf Project																	*
*	Copyright (c) 2025 <huweiye-code>													*
*																						*
*	This file is part of Gray-Leaf Project.												*
*																						*
*	Gray-Leaf Project is free software: you can redistribute it and/or modify			*
*	it under the terms of the GNU General Public License as published by				*
*	the Free Software Foundation, either version 3 of the License, or					*
*	(at your option) any later version.													*
*																						*
*	The Gray-Leaf Project is distributed in the hope that it will be useful,			*
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						*
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the						*
*	GNU General Public License for more details.										*
*																						*
*	You should have received a copy of the GNU General Public License					*
*	along with The Gray-Leaf Project. If not, see <http://www.gnu.org/licenses/>.		*
* ====------------------------------------------------------------------------------====*
*	SPDX-License-Identifier: GPL-3.0-only												*
* 	NOTICE: It's part of Gray-Leaf-Project.												*
* ====---------------------------Lexer.cpp------------------Language:C++------------====*
* /// file:																				*
*	  Defines the Lexer's functions.													*
* 																						*
*****************************************************************************************/
#include "..\..\include\Lexer\Lexer.h"

using namespace gl::compiler::lexer;

void gl::compiler::lexer::Lexer::initLexer(const char* bufStart, const char* bufPtr, const char* bufEnd)
{
	bufferBegin = bufStart;
	bufferEnd = bufEnd;
	bufferPtr = bufPtr;

	assert(bufEnd[0] == 0 && "We assume that the input buffer has a null character at the end to simplify lexing!");

	isAtStartOfLine = true;
	isFirstTimeLexingFile = true;

	hasLeadingSpace = false;
	newLinePtr = nullptr;
}
