#pragma once
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <curses.h>
#include <windows.h>

#define mw 70
#define mh 24
#define msize (mw+1)*mh
#define RAND_CHAR rand()%60+'A'
#define RAND_NUM rand()%10+'0'
char *tb;