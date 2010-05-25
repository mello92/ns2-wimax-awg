/* -*-	Mode:C++; c-basic-offset:8; tab-width:8; indent-tabs-mode:t -*- */

/*
 * utilities.cc
 * Copyright (C) 1997 by the University of Southern California
 * $Id: utilities.cc,v 1.1.1.1 2008/04/11 18:40:20 rouil Exp $
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 *
 * The copyright of this module includes the following
 * linking-with-specific-other-licenses addition:
 *
 * In addition, as a special exception, the copyright holders of
 * this module give you permission to combine (via static or
 * dynamic linking) this module with free software programs or
 * libraries that are released under the GNU LGPL and with code
 * included in the standard release of ns-2 under the Apache 2.0
 * license or under otherwise-compatible licenses with advertising
 * requirements (or modified versions of such code, with unchanged
 * license).  You may copy and distribute such a system following the
 * terms of the GNU GPL for this module and the licenses of the
 * other code concerned, provided that you include the source code of
 * that other code when and as the GNU GPL requires distribution of
 * source code.
 *
 * Note that people who make modified versions of this module
 * are not obligated to grant this special exception for their
 * modified versions; it is their choice whether to do so.  The GNU
 * General Public License gives permission to release a modified
 * version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this
 * exception.
 *
 */

//
// utilities.cc
//      Debugging routines.
//
// Author:
//   Mohit Talwar (mohit@catarina.usc.edu)
// 
// $Header: /home/rouil/cvsroot/ns-2.31/rap/utilities.cc,v 1.1.1.1 2008/04/11 18:40:20 rouil Exp $

#include <stdarg.h>
#include "utilities.h"

// Constants...

#ifndef NAME_MAX
// Maximum length of a file name
// In case that it's not defined in limits.h
#define NAME_MAX 14
#endif

//----------------------------------------------------------------------
// DebugEnable
//      Enable DEBUG messages.
//----------------------------------------------------------------------

FILE * DebugEnable(unsigned int nodeid)
{
  FILE *log;			// Logfile for debug messages
  char logFileName[NAME_MAX];

  sprintf(logFileName, "rap.%u.log", nodeid);
  log = fopen(logFileName, "w"); 
  assert(log != NULL);

  return log;
}
  
//----------------------------------------------------------------------
// Debug
//      Print a debug message if debugFlag is enabled. Like printf.
//----------------------------------------------------------------------

void Debug(int debugFlag, FILE *log, char *format, ...)
{
  if (debugFlag) 
    {
      va_list ap;
      va_start(ap, format);
      vfprintf(log, format, ap);
      va_end(ap);
      fflush(log);
    }
}

// Data structures
void DoubleList::destroy()
{
	DoubleListElem *p = head_, *q;
	while (p != NULL) {
		q = p;
		p = p->next();
		delete q;
	}
	head_ = tail_ = NULL;
}

