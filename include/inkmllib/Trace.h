/*************************************************************************
 * Copyright (c) 2008 Hewlett-Packard Development Company, L.P.
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 **************************************************************************/
/************************************************************************
 * SVN MACROS
 *
 * $Revision: 261 $
 * $Author: mnab $
 * $LastChangedDate: 2008-07-07 17:30:50 +0530 (Mon, 07 Jul 2008) $
 ************************************************************************************/
/************************************************************************
 * FILE DESCR: Trace.h - models the <trace> element of InkML.
 *			   Please refer http://www.w3.org/TR/InkML/#trace for more information.
 * AUTHOR:     Birendra Keshari
 * DATE:       24th July 2007
 * CHANGE HISTORY:
 * Author		Date			Description of change
 * Muthu	   17-June-08		Added comment statements
 * Balaji M N A 18-June-08      Moved class definition methods in .cpp file.
 ************************************************************************/

#ifndef __TRACE_H
#define __TRACE_H

#pragma once

#include "Utility.h"

class Trace
{
private:
	/**
	* Desc - The below variables are used to 
	*        parse the trace data with single diiference <'>.	
	**/
	long lastX, lastY, lastXVel, lastYVel, lastF, lastFVel;
	long FirstX, FirstY, FirstF;

	void setDataCoordinate(CHANNEL coordinate, 
						char *coordinateValue, 
						BoundingBox *boundingBox);
public:
	/**
	* Desc - Reference to the associated TraceFormat.
	**/
	TraceFormat *traceFormatRef; 
	
	/**
	* Desc - To hold channel X data (i.e. X co-ordinate data).
	**/
	vector<long> *vectX;
	/**
	* Desc - To hold channel Y data (i.e. Y co-ordinate data).
	**/
	vector<long> *vectY;
	/**
	* Desc - To hold channel F data (i.e.  Pressure/Force co-ordinate data).
	**/
	vector<int> *vectF;

	/**
	* Desc - constructor.	
	**/
	Trace();

	/**
	* Desc - assign traceFormat of this trace.
	**/
	void setTraceFormatRef(TraceFormat *traceFormatRef)
	{
		this->traceFormatRef = traceFormatRef;
	}
	
	void parseTraceData(char *data, BoundingBox *boundingBox);
};

#endif // __TRACE_H
