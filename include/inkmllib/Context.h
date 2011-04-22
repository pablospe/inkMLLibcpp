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
 * $Revision: 245 $
 * $Author: mnab $
 * $LastChangedDate: 2008-07-04 15:49:12 +0530 (Fri, 04 Jul 2008) $
 ************************************************************************************/
/************************************************************************
 * FILE DESCR: context.h - models the <context> element of InkML.
 *			   Please refer http://www.w3.org/TR/InkML/#contextElement for more information.
 * AUTHOR:     Birendra Keshari
 * DATE:       24th July 2007
 * CHANGE HISTORY:
 * Author		Date			Description of change
 * Muthu	   17-June-08		Added comment statements
 ************************************************************************/

#ifndef __CONTEXT_H
#define __CONTEXT_H

#pragma once

#include "TraceFormat.h"

class Context
{
public:
	/**
	* Desc - The reference to derive the traceFormat from exiting 
	* <traceFormat> element other attributes such as 
	* brush, canvas, canvasTransForm, inkSource are not yet implimented
	**/
	TraceFormat *traceFormatRef;

public:
	/** 
	* Desc - constructor
	**/
	Context()
	{
		traceFormatRef = NULL;
	}

	/**
	* Desc - setter method for assigning value to the 
	* traceFormat of the context.
	**/
	void setTraceFormat(TraceFormat *traceFormat)
	{
		this->traceFormatRef = traceFormat;
	}

	/**
	* Desc - Getter method for getting value of the traceFormat of the context.
	**/
	TraceFormat* getTraceFormat()
	{
		return this->traceFormatRef;
	}

};

#endif // __CONTEXT_H
