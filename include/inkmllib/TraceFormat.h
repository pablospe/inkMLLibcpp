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
 * FILE DESCR: TraceFormat.h
 * AUTHOR:     Birendra
 * DATE:       24th July 2007
 * Author		Date			Description of change
 ************************************************************************/
#pragma once

#include <vector>
#include "Channel.h"
#include "tinyxml.h"

using namespace std;

enum CHANNEL{X,Y,F,S,UNKNOWN};

class TraceFormat
{
public:
	char *id;

	/**
	* Desc - By default only X and Y channels are present
	*        This flag is to know whether pressure is present or not
	**/
	bool channelFPresent;

	vector<Channel> *vectChannel;
	vector<CHANNEL> *vectChannelOrder;

	/**
	* Desc - Constructor
	**/
	TraceFormat();
	TraceFormat(char *id);

	void addChannelOrder(CHANNEL c)
	{
		this->vectChannelOrder->push_back(c);
	}

	char * getID()
	{
		return this->id;
	}

	CHANNEL getChannelAtIndex(int index);
	void addChannelOrder(char *c);
	void initializeFromXMLNode(TiXmlNode *node);
};
