/*
Copyright (c) 2010, Sean Kasun
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.
*/


// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef WIN32
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#endif

#include "cache.h"
#include "MinewaysMap.h"
#include "ObjFileManip.h"
#include "nbt.h"
#include "region.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#ifndef clamp
#define clamp(a,min,max)	((a)<(min)?(min):((a)>(max)?(max):(a)))
#endif

#ifndef swapint
#define swapint(a,b)	{int tempint = (a); (a)=(b); (b)=tempint;}
#endif


#ifdef WIN32
#define PORTAFILE HANDLE
#define PortaOpen(fn) CreateFile(fn,GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL)
// TODO: should probably check if file exists, etc.?
#define PortaCreate(fn) CreateFileW(fn,GENERIC_WRITE,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,0,NULL)
#define PortaSeek(h,ofs) SetFilePointer(h,ofs,NULL,FILE_BEGIN)==INVALID_SET_FILE_POINTER
#define PortaRead(h,buf,len) !ReadFile(h,buf,len,&br,NULL)
#define PortaWrite(h,buf,len) !WriteFile(h,buf,(DWORD)len,&br,NULL)
#define PortaClose(h) CloseHandle(h)
#endif

#ifndef WIN32
#define strncpy_s(f,n,w,m) strncpy(f,w,m)
#define strncat_s(f,n,w,m) strncat(f,w,m)
#define sprintf_s snprintf
#define PORTAFILE FILE*
#define PortaOpen(fn) fopen(fn,"rb")
#define PortaCreate(fn) fopen(fn,"w")
#define PortaSeek(h,ofs) fseek(h,ofs,SEEK_SET)
#define PortaRead(h,buf,len) fread(buf,len,1,h)!=1
#define PortaWrite(h,buf,len) fwrite(buf,len,1,h)!=1
#define PortaClose(h) fclose(h)
#endif

#if __STDC_VERSION__ >= 199901L
#define C99
#endif
