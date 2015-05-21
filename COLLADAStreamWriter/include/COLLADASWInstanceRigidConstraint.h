/*
    Copyright (c) 2015 Starbreeze

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_INSTANCE_RIGID_CONSTRAINT_H__
#define __COLLADASTREAMWRITER_INSTANCE_RIGID_CONSTRAINT_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWElementWriter.h"
#include "COLLADASWConstants.h"

#include "COLLADABUURI.h"


namespace COLLADASW
{

    /** A class that holds informations of an @a \<instance_rigid_constraint\> element*/
	class InstanceRigidConstraint : public ElementWriter
    {

    private:

        String mConstraint;
        
    public:

        /** Constructor
        @param symbol The symbol name
        @param target The target
        */
		InstanceRigidConstraint(StreamWriter* streamWriter, const String& constraint)
			: ElementWriter(streamWriter), mConstraint(constraint) {}

		/** Writes the opening @a \<instance_rigidConstraint\> tag
		closeInstanceRigidConstraint() must be use to close the opened tags.
		@param id the id of ... */
		void openInstanceRigidConstraint();

		/** Closes the tag opened by openInstanceRigidConstraint()*/
		void closeInstanceRigidConstraint();

	private:
		TagCloser mCurrentInstanceRigidConstraintcloser;  //!< Used to close the current rigidConstraint instance


    };

} //namespace COLLADASW


#endif //__COLLADASTREAMWRITER_INSTANCE_RIGID_BODY_H__
