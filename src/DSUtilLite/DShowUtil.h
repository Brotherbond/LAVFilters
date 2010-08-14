/*
 *      Copyright (C) 2005-2010 Team XBMC
 *      http://www.xbmc.org
 *
 *      Copyright (C) 2010 Hendrik Leppkes
 *      http://www.1f0.de
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 */

#pragma once

#include <list>
#include <string>

#define LCID_NOSUBTITLES			-1

// some common macros
#define SAFE_DELETE(pPtr) { delete pPtr; pPtr = NULL; }
#define CHECK_HR(hr) if (FAILED(hr)) { goto done; }
#define QI(i) (riid == __uuidof(i)) ? GetInterface((i*)this, ppv) :
#define QI2(i) (riid == IID_##i) ? GetInterface((i*)this, ppv) :
#define countof( array ) ( sizeof( array )/sizeof( array[0] ) )

// Filter Registration
extern void RegisterSourceFilter(const CLSID& clsid, const GUID& subtype2, LPCWSTR chkbytes, ...);
extern void RegisterSourceFilter(const CLSID& clsid, const GUID& subtype2, std::list<LPCWSTR> chkbytes, ...);
extern void UnRegisterSourceFilter(const GUID& subtype);

// Locale
extern std::string ISO6391ToLanguage(LPCSTR code);
extern std::string ISO6392ToLanguage(LPCSTR code);
extern std::string ProbeLangForLanguage(LPCSTR code);
extern LCID ISO6391ToLcid(LPCSTR code);
extern LCID ISO6392ToLcid(LPCSTR code);
extern LCID ProbeLangForLCID(LPCSTR code);
extern std::string ISO6391To6392(LPCSTR code);
extern std::string ISO6392To6391(LPCSTR code);
