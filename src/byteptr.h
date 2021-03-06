// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright (C) 1998-2000 by DooM Legacy Team.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//-----------------------------------------------------------------------------
/// \file
/// \brief Macros to read/write from/to a byte *,
///        used for packet creation and such

#if defined (__arm__) || defined (__mips__)
#define DEALIGNED
#endif

#ifndef __BIG_ENDIAN__
//
// Little-endian machines
//
#ifdef DEALIGNED
#define WRITEBYTE(p,b)      do {    byte *p_tmp = (void *)p; const    byte tv = (   byte)(b); memcpy(p, &tv, sizeof(   byte)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITECHAR(p,b)      do {    char *p_tmp = (void *)p; const    char tv = (   char)(b); memcpy(p, &tv, sizeof(   char)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITESHORT(p,b)     do {   short *p_tmp = (void *)p; const   short tv = (  short)(b); memcpy(p, &tv, sizeof(  short)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEUSHORT(p,b)    do {  USHORT *p_tmp = (void *)p; const  USHORT tv = ( USHORT)(b); memcpy(p, &tv, sizeof( USHORT)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITELONG(p,b)      do {    long *p_tmp = (void *)p; const    long tv = (   long)(b); memcpy(p, &tv, sizeof(   long)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEULONG(p,b)     do {   ULONG *p_tmp = (void *)p; const   ULONG tv = (  ULONG)(b); memcpy(p, &tv, sizeof(  ULONG)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEFIXED(p,b)     do { fixed_t *p_tmp = (void *)p; const fixed_t tv = (fixed_t)(b); memcpy(p, &tv, sizeof(fixed_t)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEANGLE(p,b)     do { angle_t *p_tmp = (void *)p; const angle_t tv = (angle_t)(b); memcpy(p, &tv, sizeof(angle_t)); p_tmp++; p = (void *)p_tmp; } while (0)
#else
#define WRITEBYTE(p,b)      do {    byte *p_tmp = (   byte *)p; *p_tmp = (   byte)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITECHAR(p,b)      do {    char *p_tmp = (   char *)p; *p_tmp = (   char)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITESHORT(p,b)     do {   short *p_tmp = (  short *)p; *p_tmp = (  short)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEUSHORT(p,b)    do {  USHORT *p_tmp = ( USHORT *)p; *p_tmp = ( USHORT)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITELONG(p,b)      do {    long *p_tmp = (   long *)p; *p_tmp = (   long)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEULONG(p,b)     do {   ULONG *p_tmp = (  ULONG *)p; *p_tmp = (  ULONG)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEFIXED(p,b)     do { fixed_t *p_tmp = (fixed_t *)p; *p_tmp = (fixed_t)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEANGLE(p,b)     do { angle_t *p_tmp = (angle_t *)p; *p_tmp = (angle_t)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#endif

#ifdef __GNUC__
#ifdef DEALIGNED
#define READBYTE(p)         ({    byte *p_tmp = (void *)p;    byte b; memcpy(&b, p, sizeof(   byte)); p_tmp++; p = (void *)p_tmp; b; })
#define READCHAR(p)         ({    char *p_tmp = (void *)p;    char b; memcpy(&b, p, sizeof(   char)); p_tmp++; p = (void *)p_tmp; b; })
#define READSHORT(p)        ({   short *p_tmp = (void *)p;   short b; memcpy(&b, p, sizeof(  short)); p_tmp++; p = (void *)p_tmp; b; })
#define READUSHORT(p)       ({  USHORT *p_tmp = (void *)p;  USHORT b; memcpy(&b, p, sizeof( USHORT)); p_tmp++; p = (void *)p_tmp; b; })
#define READLONG(p)         ({    long *p_tmp = (void *)p;    long b; memcpy(&b, p, sizeof(   long)); p_tmp++; p = (void *)p_tmp; b; })
#define READULONG(p)        ({   ULONG *p_tmp = (void *)p;   ULONG b; memcpy(&b, p, sizeof(  ULONG)); p_tmp++; p = (void *)p_tmp; b; })
#define READFIXED(p)        ({ fixed_t *p_tmp = (void *)p; fixed_t b; memcpy(&b, p, sizeof(fixed_t)); p_tmp++; p = (void *)p_tmp; b; })
#define READANGLE(p)        ({ angle_t *p_tmp = (void *)p; angle_t b; memcpy(&b, p, sizeof(angle_t)); p_tmp++; p = (void *)p_tmp; b; })
#else
#define READBYTE(p)         ({    byte *p_tmp = (   byte *)p;    byte b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READCHAR(p)         ({    char *p_tmp = (   char *)p;    char b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READSHORT(p)        ({   short *p_tmp = (  short *)p;   short b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READUSHORT(p)       ({  USHORT *p_tmp = ( USHORT *)p;  USHORT b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READLONG(p)         ({    long *p_tmp = (   long *)p;    long b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READULONG(p)        ({   ULONG *p_tmp = (  ULONG *)p;   ULONG b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READFIXED(p)        ({ fixed_t *p_tmp = (fixed_t *)p; fixed_t b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READANGLE(p)        ({ angle_t *p_tmp = (angle_t *)p; angle_t b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#endif
#else
#define READBYTE(p)         *((   byte *)p)++
#define READCHAR(p)         *((   char *)p)++
#define READSHORT(p)        *((  short *)p)++
#define READUSHORT(p)       *(( USHORT *)p)++
#define READLONG(p)         *((   long *)p)++
#define READULONG(p)        *((  ULONG *)p)++
#define READFIXED(p)        *((fixed_t *)p)++
#define READANGLE(p)        *((angle_t *)p)++
#endif




/// Super annoying 2.0.6 cross compatibility




//
// Little-endian machines
//
#ifdef DEALIGNED
#define WRITEUINT8(p,b)     do {   UINT8 *p_tmp = (void *)p; const   UINT8 tv = (  UINT8)(b); memcpy(p, &tv, sizeof(  UINT8)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITESINT8(p,b)     do {   SINT8 *p_tmp = (void *)p; const   SINT8 tv = (  UINT8)(b); memcpy(p, &tv, sizeof(  UINT8)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEINT16(p,b)     do {   INT16 *p_tmp = (void *)p; const   INT16 tv = (  INT16)(b); memcpy(p, &tv, sizeof(  INT16)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEUINT16(p,b)    do {  UINT16 *p_tmp = (void *)p; const  UINT16 tv = ( UINT16)(b); memcpy(p, &tv, sizeof( UINT16)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEINT32(p,b)     do {   INT32 *p_tmp = (void *)p; const   INT32 tv = (  INT32)(b); memcpy(p, &tv, sizeof(  INT32)); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEUINT32(p,b)    do {  UINT32 *p_tmp = (void *)p; const  UINT32 tv = ( UINT32)(b); memcpy(p, &tv, sizeof( UINT32)); p_tmp++; p = (void *)p_tmp; } while (0)
#else
#define WRITEUINT8(p,b)     do {   UINT8 *p_tmp = (  UINT8 *)p; *p_tmp = (  UINT8)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITESINT8(p,b)     do {   SINT8 *p_tmp = (  SINT8 *)p; *p_tmp = (  SINT8)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEINT16(p,b)     do {   INT16 *p_tmp = (  INT16 *)p; *p_tmp = (  INT16)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEUINT16(p,b)    do {  UINT16 *p_tmp = ( UINT16 *)p; *p_tmp = ( UINT16)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEINT32(p,b)     do {   INT32 *p_tmp = (  INT32 *)p; *p_tmp = (  INT32)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#define WRITEUINT32(p,b)    do {  UINT32 *p_tmp = ( UINT32 *)p; *p_tmp = ( UINT32)(b); p_tmp++; p = (void *)p_tmp; } while (0)
#endif

#ifdef __GNUC__
#ifdef DEALIGNED
#define READUINT8(p)        ({   UINT8 *p_tmp = (void *)p;   UINT8 b; memcpy(&b, p, sizeof(  UINT8)); p_tmp++; p = (void *)p_tmp; b; })
#define READSINT8(p)        ({   SINT8 *p_tmp = (void *)p;   SINT8 b; memcpy(&b, p, sizeof(  SINT8)); p_tmp++; p = (void *)p_tmp; b; })
#define READINT16(p)        ({   INT16 *p_tmp = (void *)p;   INT16 b; memcpy(&b, p, sizeof(  INT16)); p_tmp++; p = (void *)p_tmp; b; })
#define READUINT16(p)       ({  UINT16 *p_tmp = (void *)p;  UINT16 b; memcpy(&b, p, sizeof( UINT16)); p_tmp++; p = (void *)p_tmp; b; })
#define READINT32(p)        ({   INT32 *p_tmp = (void *)p;   INT32 b; memcpy(&b, p, sizeof(  INT32)); p_tmp++; p = (void *)p_tmp; b; })
#define READUINT32(p)       ({  UINT32 *p_tmp = (void *)p;  UINT32 b; memcpy(&b, p, sizeof( UINT32)); p_tmp++; p = (void *)p_tmp; b; })
#else
#define READUINT8(p)        ({   UINT8 *p_tmp = (  UINT8 *)p;   UINT8 b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READSINT8(p)        ({   SINT8 *p_tmp = (  SINT8 *)p;   SINT8 b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READINT16(p)        ({   INT16 *p_tmp = (  INT16 *)p;   INT16 b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READUINT16(p)       ({  UINT16 *p_tmp = ( UINT16 *)p;  UINT16 b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READINT32(p)        ({   INT32 *p_tmp = (  INT32 *)p;   INT32 b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READUINT32(p)       ({  UINT32 *p_tmp = ( UINT32 *)p;  UINT32 b = *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#endif
#else
#define READUINT8(p)        *((  UINT8 *)p)++
#define READSINT8(p)        *((  SINT8 *)p)++
#define READINT16(p)        *((  INT16 *)p)++
#define READUINT16(p)       *(( UINT16 *)p)++
#define READINT32(p)        *((  INT32 *)p)++
#define READUINT32(p)       *(( UINT32 *)p)++
#endif




// 2.06 cross compatability

#else //__BIG_ENDIAN__
//
// definitions for big-endian machines with alignment constraints.
//
// Write a value to a little-endian, unaligned destination.
//
FUNCINLINE static ATTRINLINE void writeshort(void *ptr, int val)
{
	char *cp = ptr;
	cp[0] = val; val >>= 8;
	cp[1] = val;
}

FUNCINLINE static ATTRINLINE void writelong(void *ptr, int val)
{
	char *cp = ptr;
	cp[0] = val; val >>= 8;
	cp[1] = val; val >>= 8;
	cp[2] = val; val >>= 8;
	cp[3] = val;
}

#define WRITEBYTE(p,b)      do {   byte *p_tmp = (   byte *)p; *p_tmp       = (   byte)(b) ; p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITECHAR(p,b)      do {   char *p_tmp = (   char *)p; *p_tmp       = (   char)(b) ; p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITESHORT(p,b)     do {  short *p_tmp = (  short *)p; writeshort (p, (  short)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEUSHORT(p,b)    do { USHORT *p_tmp = ( USHORT *)p; writeshort (p, ( USHORT)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITELONG(p,b)      do {   long *p_tmp = (   long *)p; writelong  (p, (   long)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEULONG(p,b)     do {  ULONG *p_tmp = (  ULONG *)p; writelong  (p, (  ULONG)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEFIXED(p,b)     do {fixed_t *p_tmp = (fixed_t *)p; writelong  (p, (fixed_t)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEANGLE(p,b)     do {angle_t *p_tmp = (angle_t *)p; writelong  (p, (angle_t)(b)); p_tmp++; p = (void *)p_tmp;} while (0)


// More stupid 2.0.6 stuff

#define WRITEUINT8(p,b)     do {  UINT8 *p_tmp = (  UINT8 *)p; *p_tmp       = (  UINT8)(b) ; p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITESINT8(p,b)     do {  SINT8 *p_tmp = (  SINT8 *)p; *p_tmp       = (  SINT8)(b) ; p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEINT16(p,b)     do {  INT16 *p_tmp = (  INT16 *)p; writeshort (p, (  INT16)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEUINT16(p,b)    do { UINT16 *p_tmp = ( UINT16 *)p; writeshort (p, ( UINT16)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEINT32(p,b)     do {  INT32 *p_tmp = (  INT32 *)p; writelong  (p, (  INT32)(b)); p_tmp++; p = (void *)p_tmp;} while (0)
#define WRITEUINT32(p,b)    do { UINT32 *p_tmp = ( UINT32 *)p; writelong  (p, ( UINT32)(b)); p_tmp++; p = (void *)p_tmp;} while (0)

// 2.0.6 stuff


// Read a signed quantity from little-endian, unaligned data.
//
FUNCINLINE static ATTRINLINE short readshort(void *ptr)
{
	char *cp  = ptr;
	u_char *ucp = ptr;
	return (cp[1] << 8) | ucp[0];
}

FUNCINLINE static ATTRINLINE USHORT readushort(void *ptr)
{
	u_char *ucp = ptr;
	return (ucp[1] << 8) | ucp[0];
}

FUNCINLINE static ATTRINLINE long readlong(void *ptr)
{
	char *cp = ptr;
	u_char *ucp = ptr;
	return (cp[3] << 24) | (ucp[2] << 16) | (ucp[1] << 8) | ucp[0];
}

FUNCINLINE static ATTRINLINE ULONG readulong(void *ptr)
{
	u_char *ucp = ptr;
	return (ucp[3] << 24) | (ucp[2] << 16) | (ucp[1] << 8) | ucp[0];
}

#define READBYTE(p)         ({    byte *p_tmp = (   byte *)p;    byte b =        *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READCHAR(p)         ({    char *p_tmp = (   char *)p;    char b =        *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READSHORT(p)        ({   short *p_tmp = (  short *)p;   short b =  readshort(p); p_tmp++; p = (void *)p_tmp; b; })
#define READUSHORT(p)       ({  USHORT *p_tmp = ( USHORT *)p;  USHORT b = readushort(p); p_tmp++; p = (void *)p_tmp; b; })
#define READLONG(p)         ({    long *p_tmp = (   long *)p;    long b =   readlong(p); p_tmp++; p = (void *)p_tmp; b; })
#define READULONG(p)        ({   ULONG *p_tmp = (  ULONG *)p;   ULONG b =  readulong(p); p_tmp++; p = (void *)p_tmp; b; })
#define READFIXED(p)        ({ fixed_t *p_tmp = (fixed_t *)p; fixed_t b =   readlong(p); p_tmp++; p = (void *)p_tmp; b; })
#define READANGLE(p)        ({ angle_t *p_tmp = (angle_t *)p; angle_t b =  readulong(p); p_tmp++; p = (void *)p_tmp; b; })

// Final stupid 2.0.6 stuff

#define READUINT8(p)        ({   UINT8 *p_tmp = (  UINT8 *)p;   UINT8 b =        *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READSINT8(p)        ({   SINT8 *p_tmp = (  SINT8 *)p;   SINT8 b =        *p_tmp; p_tmp++; p = (void *)p_tmp; b; })
#define READINT16(p)        ({   INT16 *p_tmp = (  INT16 *)p;   INT16 b =  readshort(p); p_tmp++; p = (void *)p_tmp; b; })
#define READUINT16(p)       ({  UINT16 *p_tmp = ( UINT16 *)p;  UINT16 b = readushort(p); p_tmp++; p = (void *)p_tmp; b; })
#define READINT32(p)        ({   INT32 *p_tmp = (  INT32 *)p;   INT32 b =   readlong(p); p_tmp++; p = (void *)p_tmp; b; })
#define READUINT32(p)       ({  UINT32 *p_tmp = ( UINT32 *)p;  UINT32 b =  readulong(p); p_tmp++; p = (void *)p_tmp; b; })

// end stupid 2.0.6 stuff

#endif //__BIG_ENDIAN__

#undef DEALIGNED

#define WRITESTRINGN(p,s,n) { size_t tmp_i = 0; for (; tmp_i < n && s[tmp_i] != '\0'; tmp_i++) WRITECHAR(p, s[tmp_i]); WRITECHAR(p, '\0');}
#define WRITESTRING(p,s)    { size_t tmp_i = 0; for (;              s[tmp_i] != '\0'; tmp_i++) WRITECHAR(p, s[tmp_i]); WRITECHAR(p, '\0');}
#define WRITEMEM(p,s,n)     { memcpy(p, s, n); p += n; }

#define SKIPSTRING(p)       while (READBYTE(p) != 0)

#define READSTRINGN(p,s,n)  { size_t tmp_i = 0; for (; tmp_i < n && (s[tmp_i] = READCHAR(p)) != '\0'; tmp_i++); s[tmp_i] = '\0';}
#define READSTRING(p,s)     { size_t tmp_i = 0; for (;              (s[tmp_i] = READCHAR(p)) != '\0'; tmp_i++); s[tmp_i] = '\0';}
#define READMEM(p,s,n)      { memcpy(s, p, n); p += n; }

