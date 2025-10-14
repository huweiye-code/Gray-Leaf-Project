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
* ====----------------Dll_import_or_export.h----------------Language:C++------------====*
* /// file:																				*
*	  Defines the macros to handle dll impoert or export.                             	*
* 																						*
*****************************************************************************************/
#ifndef _DLL_IMPORT_OR_EXPORT_H_
#define _DLL_IMPORT_OR_EXPORT_H_
#include"Config\Config.h"
#if defined(BUILD_STATIC)
#define DLL_IMPORT 
#define DLL_EXPORT
#define DLL
#else 
#if defined(_WIN32)
#if defined(PROJECT_NAME ## EXPORT)
#define DLL_IMPORT __declspec(dllimport)
#define DLL_EXPORT __declspec(dllexport) 
#define DLL DLL_EXPORT
#else
#define DLL_IMPORT __declspec(dllimport)
#define DLL_EXPORT __declspec(dllexport) 
#define DLL DLL_IMPORT
#endif
#elif defined(__linux__) || defined(__APPLE__)
#if defined(PROJECT_NAME ## EXPORT)
#define DLL __attribute__((visibility("default")))
#endif
#else
#define DLL_IMPORT 
#define DLL_EXPORT
#define DLL
#endif
#endif
#endif