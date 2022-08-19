/*
 * This file include all TRACE(TC_INFO,  for easy use,
 * but if don't want to rebuild without any change,
 * suggest use the specific header files.
 */

#ifndef ZSTACK_H
#define ZSTACK_H

#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

//=============================================================================
// ANSI C
//=============================================================================

//=============================================================================
// Standard C 1989
//=============================================================================

//=============================================================================
// Standard C (1999)
//=============================================================================

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <errno.h>

//=============================================================================
// 3rdParty
//=============================================================================

#include <getopt/getopt.h>
#include "mpeg2.h"

//=============================================================================
// Windows
//=============================================================================

#ifdef _WIN32
#include <Windows.h>
#endif

//=============================================================================
// Linux
//=============================================================================

#ifdef __linux__
#include <sys/mman.h>
#endif

//=============================================================================
// POSIX
//=============================================================================

#include <fcntl.h>
#include <time.h>

//=============================================================================
// V-Silicon
//=============================================================================

#include <v-silicon/v-silicon.h>

//=============================================================================
// ZSTACK
//=============================================================================
#include <zstack/types.h>

// system
#include <zstack/io.h>
#include <zstack/time.h>
#include <zstack/network.h>
#include <zstack/trace.h>
#include <zstack/ui.h>
#include <zstack/ipc.h>

// algo
#include <zstack/codec.h>
#include <zstack/list.h>
#include <zstack/ringbuf.h>
#include <zstack/string.h>

// graphic
#include <zstack/graphic.h>

// misc
#include <zstack/misc.h>
#include <zstack/bit.h>
#include <zstack/bitstream.h>
#include <zstack/yuv.h>

#include <zstack/thread.h>

#endif
