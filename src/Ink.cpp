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
 * FILE DESCR: Definitions.h 
 * AUTHOR:     Birendra
 * DATE:       24th July 2007
 * Author		Date			Description of change
 * Balaji M N A 18-June-08      Moved class definition methods into .cpp file 
 *                              from .h file.
 ************************************************************************/
#include "Ink.h"

/**
*Desc - constructor to create an ink document
**/ 
Ink::Ink() 
{
	definitions = new Definitions();
	vectTrace = new vector<Trace>();
	currentContext = new Context();

	//initialize the boundingbox data
	boundingBox = (BoundingBox *)malloc(sizeof(BoundingBox));
	boundingBox->maxX = 0;
	boundingBox->maxY = 0;
	boundingBox->minX = 99999;
	boundingBox->minY = 99999;
}

/**
*Desc - function to normalize trace sample point data to fit within 
*       the given boundary box for rendering
**/ 
void Ink::normalizeTracePoint(long width, long height)
{
	float scale1, scale2, scale;
	
	scale1 = ((float)width - 10)/(this->boundingBox->maxX - this->boundingBox->minX);
	scale2 = ((float)height - 10)/(this->boundingBox->maxY - this->boundingBox->minY);
	scale = scale1<scale2?scale1:scale2;

	float newX, newY;

	for(int i =0; i< (int)this->vectTrace->size(); i++)
	{
		Trace trace = vectTrace->at(i);
		for(int j=0; j<(int)trace.vectX->size(); j++)
		{
			newX = scale*(trace.vectX->at(j) - this->boundingBox->minX + 5);
			long& tx = trace.vectX->at(j);
			tx = (long)newX;

			newY = scale*(trace.vectY->at(j) - this->boundingBox->minY + 5);
			long&  ty = trace.vectY->at(j);
			ty = (long)newY;
		}
	}
}
