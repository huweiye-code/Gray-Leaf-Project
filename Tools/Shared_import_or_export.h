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
* ====--------------Shared_import_or_export.h---------------Language:C++------------====*
* /// file:																				*
*	  Defines the macros to handle shared library impoert or export.                  	*
* 																						*
*****************************************************************************************/
#ifndef _SHARED_IMPORT_OR_EXPORT_H_
#define _SHARED_IMPORT_OR_EXPORT_H_
#include"Config\Config.h"
#if defined(BUILD_STATIC)
#define SHARED_API_IMPORT 
#define SHARED_API_EXPORT
#define SHARED_API
#else 
#if defined(_WIN32)
#if defined(PROJECT_NAME ## EXPORT)
#define SHARED_API_IMPORT __declspec(dllimport)
#define SHARED_API_EXPORT __declspec(dllexport) 
#define SHARED_API SHARED_API_EXPORT
#else
#define SHARED_API_IMPORT __declspec(dllimport)
#define SHARED_API_EXPORT __declspec(dllexport) 
#define SHARED_API SHARED_API_IMPORT
#endif
#elif defined(__linux__) || defined(__APPLE__)
#if defined(PROJECT_NAME ## EXPORT)
#define SHARED_API __attribute__((visibility("default")))
#else
#define SHARED_API __attribute__((visibility("hidden")))
#endif
#else
#define SHARED_API_IMPORT 
#define SHARED_API_EXPORT
#define SHARED_API
#endif
#endif
#endif