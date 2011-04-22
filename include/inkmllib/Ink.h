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
 * FILE DESCR: Ink.h - models the <ink> element of InkML.
 *			   Please refer http://www.w3.org/TR/InkML/#inkElement for more information.
 * CONTENTS:   
 * AUTHOR:     Birendra Keshari
 * DATE:       24th July 2007
 * CHANGE HISTORY:
 * Author		Date			Description of change
 * Muthu	   17-June-08		Added comment statements
 ************************************************************************/
#ifndef __INK_H
#define __INK_H

#pragma once

#include "Definitions.h"
#include "Trace.h"
#include "Context.h"

class Ink{
	/** 
	* Desc - To store definition state of this ink document
	**/
	Definitions *definitions;
public:
	/** 
	* Desc - To capture the boundary of the rectangle inside whice the 
	*        traces of this ink document would be rendered.
	**/
	BoundingBox *boundingBox;
	/** 
	* Desc - To hold all traces of this ink document.
	**/
	vector<Trace> *vectTrace;
	/** 
	* Desc - handle to the current context of this ink document.
	**/
	Context *currentContext;

	/** 
	* Desc - constructor to create an ink document.
	**/
	Ink();

	/** 
	* Desc - assign the definitions state of this ink document.
	**/	
	void addDefinitions(Definitions *definitions)
	{
		this->definitions = definitions;
	}

	/** 
	* Desc - function to get the definitions state of this ink document.
	**/	
	Definitions * getDefinitions()
	{
		return this->definitions;
	}

	/** 
	* Desc - function to add a Trace to this ink document.
	**/		
	void addTrace(Trace trace)
	{
		vectTrace->push_back(trace);
	}

	/** 
	* Desc - function to normalize trace sample point data to fit within 
	*        the given boundary box for rendering.
	**/	
	void normalizeTracePoint(long width, long height);
};

#endif // __INK_H
