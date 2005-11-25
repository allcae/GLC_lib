/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 0.9, packaged on Novemeber, 2005.

 http://glc-lib.sourceforge.net

 GLC-lib is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 GLC-lib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with GLC-lib; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*****************************************************************************/

//! \file GLC_Object.cpp Implementation of the GLC_Object class.

#include "glc_object.h"
using namespace std;


//////////////////////////////////////////////////////////////////////
// Constructor/Destructor
//////////////////////////////////////////////////////////////////////

GLC_Object::GLC_Object(const char *pName)
: m_Uid(GLC_GenID())	// Object ID
, m_Name(pName)			// Object Name
{

}

GLC_Object::~GLC_Object()
{

}


//////////////////////////////////////////////////////////////////////
// Get function
//////////////////////////////////////////////////////////////////////

// Identifiant de l'objet
GLC_uint GLC_Object::GetID() const
{
	return m_Uid;
}

// Nom de l'objet
const char* GLC_Object::GetName() const
{
	return m_Name.c_str();
}

//////////////////////////////////////////////////////////////////////
// SET function
//////////////////////////////////////////////////////////////////////

// Nom de l'objet
void GLC_Object::SetName(char *SetName)
{
	m_Name.assign(SetName);
}

