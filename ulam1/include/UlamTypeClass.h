/**                                        -*- mode:C++ -*-
 * UlamTypeClass.h -  Basic handling of the Class UlamType for ULAM
 *
 * Copyright (C) 2014 The Regents of the University of New Mexico.
 * Copyright (C) 2014 Ackleyshack LLC.
 *
 * This file is part of the ULAM programming language compilation system.
 *
 * The ULAM programming language compilation system is free software:
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The ULAM programming language compilation system is distributed in
 * the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the ULAM programming language compilation system
 * software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>
 */

/**
  \file UlamTypeClass.h -  Basic handling of the Class UlamType for ULAM
  \author Elenas S. Ackley.
  \author David H. Ackley.
  \date (C) 2014 All rights reserved.
  \gpl
*/


#ifndef ULAMTYPECLASS_H
#define ULAMTYPECLASS_H

#include "UlamType.h"

namespace MFM{

  class CompilerState; //forward

  class UlamTypeClass : public UlamType
  {
  public:
    
    UlamTypeClass(const UlamKeyTypeSignature key, const UTI uti, ULAMCLASSTYPE type = UC_INCOMPLETE);

    virtual ~UlamTypeClass(){}

    virtual void newValue(UlamValue & val);
    
    virtual void deleteValue(UlamValue * val);

    virtual ULAMTYPE getUlamTypeEnum();

    virtual bool cast(UlamValue & val);

    virtual const char * getUlamTypeAsSingleLowercaseLetter();

    virtual void genUlamTypeMangledDefinitionForC(File * fp, CompilerState * state);

    //virtual const std::string getUlamTypeAsStringForC();
    
    virtual const std::string getUlamTypeUPrefix();
    
    virtual const std::string getUlamTypeMangledName(CompilerState * state);

    virtual void getUlamValueAsString(const UlamValue & val, char * valstr, CompilerState * state);
    
    virtual bool isZero(const UlamValue & val);

    virtual ULAMCLASSTYPE getUlamClassType();

    void setUlamClassType(ULAMCLASSTYPE type);

    virtual s32 getBitSize();      //'class' type calculates its size after type labeling

    virtual void setBitSize(s32 bits);  //'class' type calculates its size after type labeling

    virtual const std::string getBitSizeTemplateString();

   private:

    ULAMCLASSTYPE m_classType;


    void genArrayMangledDefinitionForC(File * fp, CompilerState * state);
  };
  
}

#endif //end ULAMTYPECLASS_H
