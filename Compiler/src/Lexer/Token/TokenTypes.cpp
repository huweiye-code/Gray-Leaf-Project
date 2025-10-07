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
* 	NOTICE: It's part of Gray-Leaf-Project.												*									*
* ====-------------------------TokenTypes.cpp---------------Language:C++------------====*
* /// file:																				*
*	  Defines the TokenType and TypeTrait's support functions.							*
* 																						*
*****************************************************************************************/
#include"..\..\..\include\Lexer\Token\TokenTypes.h"

using namespace gl::compiler::lexer::token;

static constexpr const char* const TokenNames[] = {
	#define TOKEN(X) #X,
	#define KEYWORD(X,VER) #X,
	#include"..\..\..\include\Lexer\Token\TokenTypes.def"
	nullptr
};

static constexpr const char* const TypeTraitNames[] = {
	#define TYPE_TRAIT(N, S, NAME, VER) #NAME,
	#include "..\..\..\include\Lexer\Token\TokenTypes.def"
};

static constexpr const char* const TypeTraitSpellings[] = {
	#define TYPE_TRAIT(N, S, NAME, VER) #S,
	#include "..\..\..\include\Lexer\Token\TokenTypes.def"
};

static constexpr const uint8_t TypeTraitElements[] = {
	#define TYPE_TRAIT(N, S, NAME, VER) N,
	#include "..\..\..\include\Lexer\Token\TokenTypes.def"
};

const char* gl::compiler::lexer::token::getTokenName(TokenType Type)
{
	if (Type < TokenType::ENUM_CLASS_TOKEN_END)
		return TokenNames[static_cast<TokenIndex>(Type)];
	throw "Unknown Token";
	return nullptr;
}

const char* gl::compiler::lexer::token::getPunctuatorSpelling(TokenType Type)
{
	switch (Type)
	{
		#define PUNCTUATOR(X,Y) case TokenType::pu_ ## X: return Y;
		#include"..\..\..\include\Lexer\Token\TokenTypes.def"
	default:
		break;
	}
	return nullptr;
}

const char* gl::compiler::lexer::token::getKeywordSpelling(TokenType Type)
{
	switch (Type)
	{
		#define KEYWORD(X,VER) case TokenType::kw_ ## X: return #X;
		#define TYPE_TRAIT(N, S, NAME, VER) case TokenType::kw_type_trait_ ## S: return #S;
		#include"..\..\..\include\Lexer\Token\TokenTypes.def"
	default:
		break;
	}
	return nullptr;
}

bool gl::compiler::lexer::token::isAnnotation(TokenType Type)
{
	switch (Type)
	{
		#define ANNOTATION(X) case TokenType::annot_ ## X: return true;
		#include"..\..\..\include\Lexer\Token\TokenTypes.def"
	default:
		break;
	}
	return false;
}

const char* gl::compiler::lexer::token::getTraitName(TypeTrait TT)
{
	assert(TT < TypeTrait::ENUM_CLASS_TOKEN_TYPE_TRAIT_END && "Invalid value.");
	return TypeTraitNames[static_cast<TokenIndex>(TT)];
}

const char* gl::compiler::lexer::token::getTraitSpelling(TypeTrait TT)
{
	assert(TT < TypeTrait::ENUM_CLASS_TOKEN_TYPE_TRAIT_END && "Invalid value.");
	if (TT == TypeTrait::IsDeducible)
	{
		assert(std::strlen(TypeTraitSpellings[static_cast<TokenIndex>(TT)]) == 0);
		return "__is_deducible";
	}
	return TypeTraitSpellings[static_cast<TokenIndex>(TT)];
}

const uint8_t gl::compiler::lexer::token::getTypeTraitElements(TypeTrait TT)
{
	assert(TT < TypeTrait::ENUM_CLASS_TOKEN_TYPE_TRAIT_END && "Invalid value.");
	return TypeTraitElements[static_cast<TokenIndex>(TT)];
}