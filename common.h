#pragma once

#include <inttypes.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define vu8 volatile u8
#define vu16 volatile u16
#define vu32 volatile u32
#define vu64 volatile u64

#define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })
#define min(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a < _b ? _a : _b; })
#define getbe16(d) \
    (((d)[0]<<8) | (d)[1])
#define getbe32(d) \
    ((((u32) getbe16(d))<<16) | ((u32) getbe16(d+2)))
#define getbe64(d) \
    ((((u64) getbe32(d))<<32) | ((u64) getbe32(d+4)))
#define getle16(d) (*((u16*) (d)))
#define getle32(d) (*((u32*) (d)))
#define getle64(d) (*((u64*) (d)))
#define align(v,a) \
    (((v) % (a)) ? ((v) + (a) - ((v) % (a))) : (v))
    
#define fsu(s) \
    ((s >= (1<<30)) ? "GB" : (s >= (1<<30)) ? "MB" : \
     (s >= (1<<10)) ? "kB" : "B")
#define fss(s) \
    ((s >= (1<<30)) ? (s>>30) : (s >= (1<<20)) ? (s>>20) : \
     (s >= (1<<10)) ? (s>>10) : s)
    
// work files / directories
#define GAME_DIR "/D9Game"
#define WORK_DIR "/Decrypt9"
#define LOG_FILE "Decrypt9.log"

inline char* strupper(const char* str) {
    char* buffer = (char*)malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); ++i)
        buffer[i] = toupper((unsigned)str[i]);
    return buffer;
}

inline char* strlower(const char* str) {
    char* buffer = (char*)malloc(strlen(str) + 1);
    for (int i = 0; i < strlen(str); ++i)
        buffer[i] = tolower((unsigned)str[i]);
    return buffer;
}
