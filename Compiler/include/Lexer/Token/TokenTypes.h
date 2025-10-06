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
*																						*
* ====-------------------------TokenTypes.h-----------------Language:C++------------====*
* /// file:																				*
*	  Defines the TokenType enum and support functions.									*
* 																						*
*****************************************************************************************/
#ifndef _TOKEN_TYPES_H_
#define _TOKEN_TYPES_H_

#include<cstdint>

namespace gl
{
	namespace compiler
	{
		namespace lexer
		{
			namespace token
			{
				using TokenIndex = uint16_t;

				enum class TokenType : TokenIndex
				{
					#define TOKEN(X) X,
					#include"TokenTypes.def"
					ENUM_CLASS_TOKEN_END
				};

				// Determines the name of a token.
				const char* getTokenName(TokenType Type);

				// Determines the spelling of simple punctuation tokens like '!' or '%'.
				const char* getPunctuatorSpelling(TokenType Type);

				// Determines the spelling of simple keyword and contextual keyword tokens like 'auto'
				const char* getKeywordSpelling(TokenType Type);

				// Return true if this is a raw identifier or an identifier type.
				inline bool isAnyIdentifier(TokenType Type) {
					return (Type == TokenType::identifier) || (Type == TokenType::raw_identifier);
				}

				// Return true if this is a "literal" types.
				inline bool isLiteral(TokenType Type) {
					return (Type == TokenType::numeric_constant) || (Type == TokenType::char_constant) ||
						(Type == TokenType::string_literal) || (Type == TokenType::package_name);
				}

				// Return true if this is any of annotation types.
				bool isAnnotation(TokenType Type);
			}
		}
	}
}
#endif