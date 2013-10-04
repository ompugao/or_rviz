/*
 * LinkVisual.h
 *
 *  Created on: Sep 24, 2013
 *      Author: mklingen
 */

#ifndef LINKVISUAL_H_
#define LINKVISUAL_H_

#include <openrave/openrave.h>
#include <openrave/kinbody.h>
#include <vector>

namespace Ogre
{
    class SceneNode;
    class SceneManager;
}

namespace superviewer
{
    class KinBodyVisual;
    class LinkVisual
    {
        public:
            LinkVisual(KinBodyVisual* kinBody, OpenRAVE::KinBody::LinkPtr link, Ogre::SceneNode* parent, Ogre::SceneManager* sceneManager);
            virtual ~LinkVisual();

            inline OpenRAVE::KinBody::LinkPtr GetLink() { return m_link; }
            inline void SetLink(OpenRAVE::KinBody::LinkPtr value) { m_link = value; }

            inline Ogre::SceneNode* GetSceneNode() { return m_sceneNode; }
            inline void SetSceneNode(Ogre::SceneNode* value) { m_sceneNode = value; }

            inline KinBodyVisual* GetKinBody() { return m_kinBody; }
            inline void SetKinBody(KinBodyVisual* value) { m_kinBody = value; }

            void CreateParts();

        protected:
            KinBodyVisual* m_kinBody;
            OpenRAVE::KinBody::LinkPtr m_link;
            Ogre::SceneNode* m_sceneNode;
            Ogre::SceneNode* m_parentNode;
            Ogre::SceneManager* m_sceneManager;

    };

} /* namespace superviewer */
#endif /* LINKVISUAL_H_ */