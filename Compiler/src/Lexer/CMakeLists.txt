cmake_minimum_required(VERSION 3.10)

add_subdirectory(Token)

ADD_GRAY_LEAF_COMPILER_LIBRARY(Lexer STATIC
SOURCES
	Lexer.cpp
VERSION
	1.0.0
LINK_LIB
	Token
)