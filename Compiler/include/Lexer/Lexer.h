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
* ====---------------------------Lexer.h--------------------Language:C++------------====*
* /// file:																				*
*	  Defines the Lexer's functions.													*
* 																						*
*****************************************************************************************/
#ifndef _LEXER_H_
#define _LEXER_H_

#include<cassert>

namespace gl {
	namespace compiler {
		namespace lexer {
			// Lexer provides a simple feature that returns a text buffer into a stream of tokens.
			// This provides no support for file reading or buffering,
			// or buffering/seeking of tokens, only forward lexing is supported.
			class Lexer
			{
			private:
				// Start of the buffer.
				const char *bufferBegin;

				// End of the buffer.
				const char *bufferEnd;

				// True if '//' line comments are enabled.
				bool isLineComment;

				// True if this is the first time we're lexing the input file.
				bool isFirstTimeLexingFile;

				// True if the next lexed token should get the "start of line" flag set on it.
				bool isAtStartOfLine;

				// True if this token has a prefix in front.
				bool hasLeadingSpace;

				// Current pointer into the buffer.
				// This is the next character to be lexed.
				const char* bufferPtr;

				// A pointer to new line character '\n' being lexed.
				// For '\r\n', it also points to '\n.'
				const char *newLinePtr;
			private:
				void initLexer(const char* bufStart, const char* bufPtr, const char* bufEnd);
			};
		}
	}
}
#endif // !_LEXER_H_
