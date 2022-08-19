/*
 * This file include all info for easy use,
 * but if don't want to rebuild without any change,
 * suggest use the specific header files.
 */

#ifndef ZSTACK_H
#define ZSTACK_H

// Standard C
#include <stdlib.h>
#include <string.h>

// 3rdParty
#include <getopt/getopt.h>

// ZSTACK
#include "types.h"

// system
#include "io.h"
#include "time.h"
#include "network.h"
#include "trace.h"
#include "ui.h"
#include "ipc.h"

// algo
#include "codec.h"
#include "list.h"
#include "ringbuf.h"
#include "string.h"

// graphic
#include "graphic.h"

// misc
#include "misc.h"
#include "bitstream.h"
#include "yuv.h"

#include "thread.h"

#endif
