/******************************************************************************

    tiny.c

    mamedriv.c substitute file for "tiny" MAME builds.

    Copyright Nicola Salmoria and the MAME Team.
    Visit http://mamedev.org for licensing and usage restrictions.

    The list of used drivers. Drivers have to be included here to be recognized
    by the executable.

    To save some typing, we use a hack here. This file is recursively #included
    twice, with different definitions of the DRIVER() macro. The first one
    declares external references to the drivers; the second one builds an array
    storing all the drivers.

******************************************************************************/


#include "driver.h"

#ifndef DRIVER_RECURSIVE

#define DRIVER_RECURSIVE

/* step 1: declare all external references */
#define DRIVER(NAME) GAME_EXTERN(NAME);
#include "defendermachine.c"

/* step 2: define the drivers[] array */
#undef DRIVER
#define DRIVER(NAME) &GAME_NAME(NAME),
const game_driver * const drivers[] =
{
#include "defendermachine.c"
	0	/* end of array */
};

#else	/* DRIVER_RECURSIVE */

	DRIVER( defenderg )
	DRIVER( stargate )
	DRIVER(robotron)

#endif	/* DRIVER_RECURSIVE */
