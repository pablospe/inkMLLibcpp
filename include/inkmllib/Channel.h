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
 * $Revision: 242 $
 * $Author: mnab $
 * $LastChangedDate: 2008-07-02 16:28:29 +0530 (Wed, 02 Jul 2008) $
 ************************************************************************************/
/************************************************************************
 * FILE DESCR: Channel.h - models the <channel> element in InkML specification. 
 *      				   Please refer http://www.w3.org/TR/InkML/#channel for more information.
 * AUTHOR:     Birendra Keshari
 * DATE:       16th June 2007
 * Author		Date			Description of change
 * Muthu	    17-June-08      Added constructor with name parameter 
 *                              only and added comments.                                
 * Balaji M N A 18-June-08      Moved class definition methods in .cpp file.
 ************************************************************************/

#pragma once
#include <string.h>

// enumeration for different units supported for channel data
enum INKML_UNITS {Dev, Inches, Centimeters, 
                  Degrees, Radians, 
                  Seconds, Pounds, Grams};

class Channel
{
public:
	// to store the 'name' attribute value. It is a mandatory field.
	char* name; 
	// to store the 'min' attribute value. 
	// It gives the min range of channel data value.	
	long min; 
	// to store the 'max' attribute value. 
	// It gives the max range of channel data value.	
	long max;
	// If value not given for min and/or max then 
	// the channel value is unbounded in either direction
	// to store the 'units' attribute value.
	INKML_UNITS units;

public:
	Channel(char *name, long min, long max, char *units);
	Channel(char *name, long min, long max, INKML_UNITS units);
	Channel(char *name);
	INKML_UNITS getUnit(){ return units;}
	char * getName(){ return name;}
private:
	INKML_UNITS getUnit(char *units);
};
