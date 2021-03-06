// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// Copyright (C) 1993-1996 by id Software, Inc.
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
//---------------------------------------------------------------------
/// \file
/// \brief Zone Memory Allocation, perhaps NeXT ObjectiveC inspired

#ifndef __Z_ZONE__
#define __Z_ZONE__

#include <stdio.h>

#ifdef __GNUC__ // __attribute__ ((X))
#if (__GNUC__ > 4) || (__GNUC__ == 4 && (__GNUC_MINOR__ >= 3 || (__GNUC_MINOR__ == 2 && __GNUC_PATCHLEVEL__ >= 4)))
#define FUNCALLOC(X) __attribute__((alloc_size(X)))
#endif // odd, it is documented in GCC 4.3.0 but it exists in 4.2.4, at least
#endif

#ifndef FUNCALLOC
#define FUNCALLOC(x)
#endif

#define ZDEBUG

//
// ZONE MEMORY
// PU - purge tags.
// Tags < 100 are not overwritten until freed.
#define PU_STATIC               1 // static entire execution time // SRB2CBTODO: If it's static, use real malloc
#define PU_SOUND                2 // static while playing
#define PU_MUSIC                3 // static while playing
#define PU_HUDGFX               4 // static until WAD added

#define PU_HWRPATCHINFO         5 // Hardware GLPatch_t struct for OpenGL texture cache
								  // SRB2CBTODO: Optimize OpenGL by not using this
#define PU_LEVEL               50 // Memory is freed upon loading/reloading a level
#define PU_LEVSPEC             51 // A special thinker in a level, freed upon level load
// Tags >= PU_PURGELEVEL are purgable whenever needed
#define PU_PURGELEVEL         100
#define PU_CACHE              101 // Often used to flag things such as level graphics, sound, etc. to be freed
#define PU_HWRCACHE           102 // 'second-level' cache for graphics
                                  // stored in hardware format and downloaded as needed

void Z_Init(void);
void Z_FreeTags(int lowtag, int hightag);

#ifdef PARANOIA
void Z_ChangeTag2(void *ptr, int tag, const char *file, int line);
#else
void Z_ChangeTag2(void *ptr, int tag);
#endif

#ifdef ZDEBUG
#define Z_Free(p) Z_Free2(p, __FILE__, __LINE__)
void Z_Free2(void *ptr, const char *file, int line);
#define Z_Malloc(s,t,u) Z_Malloc2(s, t, u, 0, __FILE__, __LINE__)
#define Z_MallocAlign(s,t,u,a) Z_Malloc2(s, t, u, a, __FILE__, __LINE__)
void *Z_Malloc2(size_t size, int tag, void *user, int alignbits, const char *file, int line) FUNCALLOC(1);
#define Z_Calloc(s,t,u) Z_Calloc2(s, t, u, 0, __FILE__, __LINE__)
#define Z_CallocAlign(s,t,u,a) Z_Calloc2(s, t, u, a, __FILE__, __LINE__)
void *Z_Calloc2(size_t size, int tag, void *user, int alignbits, const char *file, int line) FUNCALLOC(1);
#define Z_Realloc(p,s,t,u) Z_Realloc2(p, s, t, u, 0, __FILE__, __LINE__)
#define Z_ReallocAlign(p,s,t,u,a) Z_Realloc2(p,s, t, u, a, __FILE__, __LINE__)
void *Z_Realloc2(void *ptr, size_t size, int tag, void *user, int alignbits, const char *file, int line) FUNCALLOC(2);
#else
void Z_Free(void *ptr);
void *Z_MallocAlign(size_t size, int tag, void *user, int alignbits) FUNCALLOC(1);
#define Z_Malloc(s,t,u) Z_MallocAlign(s, t, u, 0)
void *Z_CallocAlign(size_t size, int tag, void *user, int alignbits) FUNCALLOC(1);
#define Z_Calloc(s,t,u) Z_CallocAlign(s, t, u, 0)
void *Z_ReallocAlign(void *ptr, size_t size, int tag, void *user, int alignbits) FUNCALLOC(2) ;
#define Z_Realloc(p, s,t,u) Z_ReallocAlign(p, s, t, u, 0)
#endif

size_t Z_TagUsage(int tagnum);

char *Z_StrDup(const char *in);

// This is used to get the local FILE : LINE info from CPP
// prior to really call the function in question.
//
#ifdef PARANOIA
#define Z_ChangeTag(p,t) Z_ChangeTag2(p, t, __FILE__, __LINE__)
#else
#define Z_ChangeTag(p,t) Z_ChangeTag2(p, t)
#endif

#endif
