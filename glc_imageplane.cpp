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

//! \file glc_imagePlane.cpp implementation of the GLC_ImagePlane class.

#include "glc_imageplane.h"
#include "glc_viewport.h"
//////////////////////////////////////////////////////////////////////
// Constructor Destructor
//////////////////////////////////////////////////////////////////////
GLC_ImagePlane::GLC_ImagePlane(GLC_Viewport* pViewport, const char* pName, const GLfloat *pColor)
:GLC_Geometrie(pName, pColor)
, m_pImgTexture(NULL)
, m_pViewport(pViewport)
, m_dLgImage(0)
, m_dZpos(0)
{

}

GLC_ImagePlane::~GLC_ImagePlane(void)
{
	// Lib�ration de la m�moire de la texture
	if (m_pImgTexture != NULL)
	{
		delete m_pImgTexture;
		m_pImgTexture= NULL;
	}

}
/////////////////////////////////////////////////////////////////////
// Set Functions
//////////////////////////////////////////////////////////////////////
// Load image
bool GLC_ImagePlane::ChargeImage(QGLWidget *GLWidget, const QString ImageName)
{
	if (m_pImgTexture != NULL)
	{
		delete m_pImgTexture;
	}

	m_pImgTexture= new GLC_Texture(GLWidget, ImageName);

	return (m_pImgTexture != NULL);
}

// Update image size
void GLC_ImagePlane::UpdatePlaneSize(void)
{
	// position Camera plane
	m_dZpos= m_pViewport->GetDistMax();	

	// compute quad size
	int nCote;
	if (m_pViewport->GetWinHSize() < m_pViewport->GetWinVSize())
	{
		nCote= m_pViewport->GetWinVSize();
	}
	else
	{
		nCote= m_pViewport->GetWinHSize();
	}

	// Calcul du cot� du carr� de vision de la cam�ra
	// Le cot� du carr� de la cam�ra est mapp� sur la hauteur de la fen�tre
	const double ChampsVision = 2 * m_dZpos *  tan((m_pViewport->GetFov() * PI / 180)/ 2);
	
	// Circle radius in openGL unit = RayonPixel * (dimens GL / dimens Pixel)
	m_dLgImage= ((double)nCote * ChampsVision / (double)m_pViewport->GetWinVSize());

	// Invalidate OpenGL Display list
	m_bListeIsValid= false;
}


//////////////////////////////////////////////////////////////////////
// OpenGL Functions
//////////////////////////////////////////////////////////////////////
// Plane Display
void GLC_ImagePlane::GlDraw(void)
{

	const double LgImgSur2= m_dLgImage / 2;

	glLoadIdentity();
	glTranslated(0.0, 0.0, -m_dZpos);
	glBegin(GL_QUADS);

		glNormal3d(0.0, 0.0, 1.0);	// Z
		glTexCoord2f(0.0f, 0.0f); glVertex3d(-LgImgSur2, -LgImgSur2, 0.0);
		glTexCoord2f(1.0f, 0.0f); glVertex3d(LgImgSur2, -LgImgSur2, 0.0);
		glTexCoord2f(1.0f, 1.0f); glVertex3d(LgImgSur2, LgImgSur2, 0.0);
		glTexCoord2f(0.0f, 1.0f); glVertex3d(-LgImgSur2, LgImgSur2, 0.0);

	glEnd();

}
// Define Geometry property (Couleur, position, epaisseur)
void GLC_ImagePlane::GlPropGeom(void)
{
	glDisable(GL_LIGHTING);

	if (m_pImgTexture != NULL)
	{		
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
		//glEnable(GL_DEPTH_TEST);
		glEnable(GL_TEXTURE_2D);
		glColor4fv(GetfRGBA());
		m_pImgTexture->GlBindTexture();
	}
	else
	{
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
		//glEnable(GL_DEPTH_TEST);
		glDisable(GL_TEXTURE_2D);
		glColor4fv(GetfRGBA());
	}

}


