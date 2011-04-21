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
 * $Revision: 264 $
 * $Author: mnab $
 * $LastChangedDate: 2008-07-07 18:26:51 +0530 (Mon, 07 Jul 2008) $
 ************************************************************************************/
/************************************************************************
 * FILE DESCR: Trace.cpp
 * AUTHOR:     Birendra
 * DATE:       24th July 2007
 * Author		Date			Description of change
 * Balaji M N A 18-June-08      Moved class definition methods into .cpp file 
 *                              from .h file.
 ************************************************************************/
#include "TraceFormat.h"
#include "Trace.h"

/**
*Desc - constructor
**/
Trace::Trace()
{
	vectX = new vector<long>();
	vectY = new vector<long>();
	vectF = new vector<int>();
	traceFormatRef = new TraceFormat();
	lastX = lastY = lastF = lastXVel = lastYVel = lastFVel = -1;
}

/**
*Desc - function to parse traceData.
*       It uses the setDataCoordinate method to process 
*       and strore co-ordinate values.
**/
void Trace::parseTraceData(char *data, BoundingBox *boundingBox)
{
	if(NULL == data )
		return;

	char *point = strtok(data, ",");
	vector<char *> *vectPoints = new vector<char *>();

	while(point!=NULL)
	{
		vectPoints->push_back(point);
		point = strtok(NULL, ",");
	}

	this->FirstX = 0;
	this->FirstY = 0;
	this->FirstF = 0;
	for(int i = 0; i<(int)vectPoints->size();i++)
	{
		point = vectPoints->at(i);
		char *coordinateValue = strtok(point, " ");
		int coordinateIndex = 0;
		
		while(coordinateValue!=NULL)
		{
			setDataCoordinate(traceFormatRef->getChannelAtIndex(coordinateIndex), coordinateValue, boundingBox);
			coordinateValue = strtok(NULL, " ");
			
			coordinateIndex++;
		}
	}

	if(vectPoints)
	{
		delete vectPoints;
		vectPoints = NULL;
	}
}
/**
*Desc - function to assign sample point data and 
*       set the bounding box to be used for rendering
*       it parses and expand the single difference encoded 
*       channel data to absolute values
**/
void Trace::setDataCoordinate(CHANNEL coordinate, 
							  char *coordinateValue, 
							  BoundingBox *boundingBox)
{
	long x,y,f;
	switch(coordinate)
	{
	case X:
		
		if(coordinateValue[0]=='\'')
		{
			coordinateValue = GlobalFunction::removeVelocity(coordinateValue);
			this->FirstX = this->lastX;
			x = atol(coordinateValue) + this->lastX;
		}
		else
		{
			x = atol(coordinateValue) + this->FirstX;
		}
		this->lastX = x;

		if(x>boundingBox->maxX)
			boundingBox->maxX = x;

		else if(x<boundingBox->minX)
			boundingBox->minX = x;

		this->vectX->push_back(x);
		break;

	case Y:
		if(coordinateValue[0]=='\'')
		{
			coordinateValue = GlobalFunction::removeVelocity(coordinateValue);
			this->FirstY = this->lastY;
			y = atol(coordinateValue) + this->lastY;
		}
		else
		{
			y = atol(coordinateValue) + this->FirstY;
		}
		this->lastY = y;
		
		if(y>boundingBox->maxY)
			boundingBox->maxY = y;

		else if(y<boundingBox->minY)
			boundingBox->minY = y;

		this->vectY->push_back(y);
		break;

	case F:
		if(coordinateValue[0]=='\'')
		{
			coordinateValue = GlobalFunction::removeVelocity(coordinateValue);
			this->FirstF = this->lastF;
			f = atol(coordinateValue) + this->FirstF;
		}
		else
		{
			f = atol(coordinateValue) + this->FirstF;
		}
		this->lastF = f;

		this->vectF->push_back(atoi(coordinateValue));
		break;
	case UNKNOWN:
		break;
	}
}
