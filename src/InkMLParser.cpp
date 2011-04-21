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
 * FILE DESCR: InkMLParser.cpp 
 * CONTENTS:   This class uses tinyxml to parse InkML and create corresponding Ink object
 *			   with all absolute context of each trace/trace group resolved. This is used
 *			   by the plugin to render the traces. This InkML parser only processes those
 *             elements that are required for rendering eg. * contribute to the context of
 *             trace/trace group and hence other elements might not even appear in the Ink object.
 * AUTHOR:     Birendra
 * DATE:       16th June 2007
 * CHANGE HISTORY:
 * Author		Date			Description of change
 * Balaji M N A 18-June-08      Moved class definition methods into .cpp file 
 *                              from .h file.
 ************************************************************************/
#include "InkMLParser.h"
#include "tinyxml.h"
#include <vector>

InkMLParser::InkMLParser()
{
}

Ink* InkMLParser::parse(char *inkMLData, InkMLError *retCode)
{
	if(!inkMLData)
		return NULL;

	TiXmlDocument doc;
	doc.Parse(inkMLData);
	Ink *objInk = new Ink();
	if(doc.Error())
	{
		*retCode = TinyXmlError;
		GlobalFunction::tinyXmlError = (char *)malloc(sizeof(char)*strlen(doc.ErrorDesc()));
		strcpy(GlobalFunction::tinyXmlError,doc.ErrorDesc());
		return objInk;
	}

	TiXmlElement *root = doc.RootElement();

	//Document toot should be ink
	if(strcmp(root->Value(), "ink")==0)
	{
		TiXmlNode *child;
		for(child = root->FirstChild(); child; child = child->NextSibling())
		{
			//capture DEFINITIONS
			if(strcmp(child->Value(), "definitions")==0)
			{
				Definitions *objDefinitions = new Definitions();
				
				//process each child of DEFINITIONS
				TiXmlNode *defChild;
				for(defChild = child->FirstChild(); defChild; defChild = defChild->NextSibling())
				{
					//TRACEFORMAT
					if(strcmp(defChild->Value(), "traceFormat")==0)
					{
						TraceFormat *traceFormat = new TraceFormat();
						TiXmlElement *defChildElement = defChild->ToElement();
						const char *id = defChildElement->Attribute("id");
						if(id!=NULL)
							traceFormat->id = (char *)id;
						traceFormat->initializeFromXMLNode(defChild);
						objDefinitions->addTraceFormat(traceFormat);
					}

					//INKSOURCE
					else if(strcmp(child->Value(), "inkSource")==0)
					{
						InkSource *objInkSource = new InkSource();
						TiXmlNode *inkSourceChild;

						for(inkSourceChild = child->FirstChild(); inkSourceChild; inkSourceChild = inkSourceChild->NextSibling())
						{
							//TRACEFORMAT
							if(strcmp(inkSourceChild->Value(), "traceFormat")==0)
							{
								TraceFormat *traceFormat = new TraceFormat();
								TiXmlElement *inkSourceChildElement = inkSourceChild->ToElement();
								const char *id = inkSourceChildElement->Attribute("id");
								if(id!=NULL)
									traceFormat->id = (char *)id;
								traceFormat->initializeFromXMLNode(inkSourceChild);
								objInkSource->addTraceFormat(traceFormat);
							}
						}//end for
						objDefinitions->addInkSource(objInkSource);
					}//end INKSOURCE
				}
				objInk->addDefinitions(objDefinitions);
			}

			//CONTEXTUAL ELEMENTS
			else if(strcmp(child->Value(), "context")==0)
			{
				TiXmlElement *childElement = child->ToElement();
				const char *attr = childElement->Attribute("traceFormatRef");
				if(attr)
				{
					char *attrNew = GlobalFunction::checkAndRemoveHash((char *)attr);
					TraceFormat traceFormat;
					traceFormat = objInk->getDefinitions()->getTraceFormat(attrNew);
					if(&traceFormat!=NULL)
					{
						objInk->currentContext->traceFormatRef = &traceFormat;
					}
				}
			}

			//TRACE
			else if(strcmp(child->Value(), "trace")==0)
			{
				insertTrace(child, objInk);
			}

			else if(strcmp(child->Value(), "traceGroup")==0)
			{
				TiXmlNode *traceGroupChild;
				for(traceGroupChild = child->FirstChild(); traceGroupChild; traceGroupChild = traceGroupChild->NextSibling())
				{
					if(strcmp(traceGroupChild->Value(), "trace")==0)
					{
						insertTrace(traceGroupChild, objInk);
					}
				}
			}
		}
	}
	else
	{
		*retCode = NoInkRoot;
		return objInk;
	}

	*retCode = NoError;//Success
	return objInk;
}

void InkMLParser::insertTrace(TiXmlNode *child, Ink *objInk)
{
	if(NULL == child && NULL == objInk)
		return;

	TiXmlElement *childElement = child->ToElement();
	Trace trace;

	if(objInk->currentContext->traceFormatRef!=NULL)
		trace.setTraceFormatRef(objInk->currentContext->traceFormatRef);

	trace.parseTraceData((char *)childElement->GetText(), objInk->boundingBox);
	objInk->addTrace(trace);
}
