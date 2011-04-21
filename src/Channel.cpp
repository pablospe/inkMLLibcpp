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
 * FILE DESCR: Channel.cpp 
 * AUTHOR:     Birendra
 * DATE:       16th June 2007
 * Author		Date			Description of change
 * Balaji M N A 18-June-08      Moved class definition methods into .cpp file 
 *                              from .h file.
 ************************************************************************/
#include "Channel.h"

/**
*Desc - constructors
**/
Channel::Channel(char *name, long lMin, long lMax, char *units)
        : min(lMin), max(lMax)
{
	this->units = getUnit(units);
	this->name = name;
}

Channel::Channel(char *name, long min, long max, INKML_UNITS units)
{
	this->units = units;
	this->min = min;
	this->max = max;
	this->name = name;
}

Channel::Channel(char *name)
{
	this->name = name;
}

/**
*Desc - method to map the 'units' attribute value in string 
*       type to the corresponding enum value.
**/
INKML_UNITS Channel::getUnit(char *units)
{
	if(strcmp(units, "dev")==0)
		return Dev;

	else if(strcmp(units, "in")==0)
		return Inches;

	else if(strcmp(units, "cm")==0)
		return Centimeters;
	
	else if(strcmp(units, "deg")==0)
		return Degrees;
	
	else if(strcmp(units, "rad")==0)
		return Radians;

	else if(strcmp(units, "s")==0)
		return Seconds;
	
	return Grams;
	
}