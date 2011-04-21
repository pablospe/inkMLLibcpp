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
 * FILE DESCR: utility.h - This class contains miscellaneous utility methods 
 *						   and enumeration, constant data members
 * AUTHOR:     Birendra
 * DATE:       24th July 2007
 * Author		Date			Description of change
 * Muthu	   17-June-08		Added comment statements
 * Balaji M N A18-June-08       1. Moved Drawline and DrawBezier methods into 
 *                                 Renderer class.
 *                              2. Global functions move to GlobalFunction class   
 ************************************************************************/
#pragma once

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <vector>

using namespace std;

#define SUCCESS true

/**
* Desc - structure to define the BoundingBox of the trace data 
*        and hence helps in normalizing trace co-ordinate data 
*        to fit in the rendering area co-ordinate.
**/
typedef struct structBoundingBox{
	long minX;
	long minY;
	long maxX;
	long maxY;
}BoundingBox;

/**
* Desc - Error constants
**/
enum InkMLError{NoError, 
				NoInkRoot, 
				MalFormedXml,
				TinyXmlError};

#define E_NOINKROOT 1
#define E_XMLPARSE 2


class GlobalFunction
{
public:
	static char* tinyXmlError;
	static char* checkAndRemoveHash(char *str);
	static char* removeVelocity(char *str);
	static char* decodeError(InkMLError errorNo);
	static char* toLower(char *s);
};


