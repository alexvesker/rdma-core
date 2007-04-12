/*
 * Copyright (c) 2006-2007 The Regents of the University of California.
 * Copyright (c) 2004-2006 Voltaire Inc.  All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef _IBDIAG_COMMON_H_
#define _IBDIAG_COMMON_H_

#include <stdio.h>
#include <inttypes.h>

extern char *argv0;
extern int   ibdebug;

/*========================================================*/
/*                External interface                      */
/*========================================================*/

/**
 * Switch map interface.
 * It is OK to pass NULL for the switch_map[_fp] parameters.
 */
FILE *open_switch_map(char *switch_map);
void  close_switch_map(FILE *switch_map_fp);
char *lookup_switch_name(FILE *switch_map_fp, uint64_t target_guid,
			char *nodedesc);
	/* NOTE: parameter "nodedesc" may be modified here. */

#undef DEBUG
#define	DEBUG	if (ibdebug || verbose) IBWARN
#define	VERBOSE	if (ibdebug || verbose > 1) IBWARN
#define IBERROR(fmt, args...)	iberror(__FUNCTION__, fmt, ## args)

void  iberror(const char *fn, char *msg, ...);

/* NOTE: this modifies the parameter "nodedesc". */
char *clean_nodedesc(char *nodedesc);

#endif	/* _IBDIAG_COMMON_H_ */
