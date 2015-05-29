/*
	Copyright (c) 2015 Starbreeze

	This file is part of COLLADAStreamWriter.
	
    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASTREAMWRITER_LIBRARY_PHYSICS_MODELS_H__
#define __COLLADASTREAMWRITER_LIBRARY_PHYSICS_MODELS_H__

#include "COLLADASWPrerequisites.h"
#include "COLLADASWLibrary.h"
#include "COLLADASWInputList.h"

namespace COLLADASW
{

    /** Class to simply the creation of @a \<library_physics_model\> and @a \<physics_model\>'s*/

    class LibraryPhysicsModels : public Library
    {

    private:

        TagCloser mCurrentPhysicsModelCloser;  //!< Used to close the current physicsModel
		TagCloser mCurrentTechniqueCommonCloser;  //!< Used to close the current techniqueCommon
		TagCloser mCurrentRigidBodyCloser;   //!< Used to close the current rigidBody
		TagCloser mCurrentRigidConstraintCloser; //!< Used to close the current rigidConstraint

		TagCloser mCurrentRefAttachmentCloser;
		TagCloser mCurrentAttachmentCloser;
		TagCloser mCurrentLimitCloser;
		TagCloser mCurrentSpringCloser;

		TagCloser mCurrentShapeCloser;
		
    public:
        /** Constructor
        @param streamWriter The stream the @a \<library_physics_models\> and @a \<physics_model\>'s
        should be written to.
        */
		LibraryPhysicsModels(StreamWriter* streamWriter);

		virtual ~LibraryPhysicsModels() {}

    protected:

		void openRigidConstraint(const String & rbSId, const String & rbName);
		void closeRigidConstraint();
		
		void openRefAttachment(const String & rbName);
		void closeRefAttachment();
		void openAttachment(const String & rbName);
		void closeAttachment();
		
		void openSpring();
		void AddAngularSpring(float stiffness, float damping, float target);
		void AddLinearSpring(float stiffness, float damping, float target);
		void closeSpring();

		void openLimits();
		void AddSwingAndTwistLimit(std::vector<String> minValues, std::vector<String> maxValues);
		void AddLinearLimit(std::vector<String> minValues, std::vector<String> maxValues);
		void closeLimits();

		void openRigidBody(const String & rbSId, const String & rbName);
		void closeRigidBody();

		void openTechniqueCommon();
		void closeTechniqueCommon();
		

		void openShape();
		void closeShape();
		void AddBoxShape(float x, float y, float z);
		void AddCapsuleShape(float radiusX, float radiusY, float radiusZ, float height);
		void AddConvexMeshShape(const String &convexHullOf);
		
		void addDynamic(bool dynamic);
		void addMass(float mass);
		void addInertia(float x, float y, float z);

		void addTranslate(const String &sid, float x, float y, float z) const;
		void addRotate(const String &sid, double x, double y, double z, double angle) const;


        /** Writes the opening @a \<rigid_body\> tag and, if necessary the opening @a \<library_physics_models\> tag.
        closePhysicsModel() must be use to close the opened tags.
        @param id The id of the physicsModel.
        @param name The name of the physicsModel.*/
        void openPhysicsModel ( const String& id, const String& name = EMPTY_STRING );

        /** Closes the tag open by openPhysicsModel()*/
        void closePhysicsModel();
    };

} //namespace COLLADASW

#endif //__COLLADASTREAMWRITER_LIBRARY_PHYSICS_MODELS_H__
