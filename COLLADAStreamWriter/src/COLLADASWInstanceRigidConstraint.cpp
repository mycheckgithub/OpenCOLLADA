/*
    Copyright (c) 2015 Starbreeze

    This file is part of COLLADAStreamWriter.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#include "COLLADASWInstanceRigidConstraint.h"
#include "COLLADASWConstants.h"

namespace COLLADASW
{

	//---------------------------------------------------------------
	void InstanceRigidConstraint::openInstanceRigidConstraint()
	{
		mCurrentInstanceRigidConstraintcloser = mSW->openElement(CSWC::CSW_ELEMENT_INSTANCE_RIGID_BODY);
		mSW->appendAttribute(CSWC::CSW_ATTRIBUTE_CONSTRAINT, mConstraint);
		mSW->closeElement();
	}

	void InstanceRigidConstraint::closeInstanceRigidConstraint()
	{
		mCurrentInstanceRigidConstraintcloser.close();
	}

} //namespace COLLADASW
