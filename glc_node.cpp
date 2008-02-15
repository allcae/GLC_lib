/****************************************************************************

 This file is part of the GLC-lib library.
 Copyright (C) 2005-2008 Laurent Ribon (laumaya@users.sourceforge.net)
 Version 0.9.8, packaged on January, 2008.

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
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

*****************************************************************************/

//! \file glc_node.cpp implementation of the GLC_Node class.

#include "glc_node.h"
#include "glc_world.h"

//////////////////////////////////////////////////////////////////////
// Constructor destructor
//////////////////////////////////////////////////////////////////////

GLC_Node::GLC_Node(GLC_World *pWorld)
: m_Uid(GLC_GenID())
, m_pWorld(pWorld)
, m_pFather(NULL)
, m_Ref()
, m_RelativeMatrix()
, m_AbsoluteMatrix()
{
}

GLC_Node::~GLC_Node()
{
}

// Set the father of this node
void GLC_Node::setFather(GLC_Node* pNode)
{
	m_pFather= pNode;
	updateAbsoluteMatrix();
}








