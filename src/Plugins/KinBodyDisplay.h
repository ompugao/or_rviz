/*
 * KinBodyDisplay.h
 *
 *  Created on: Sep 24, 2013
 *      Author: mklingen
 */

#ifndef KINBODYDISPLAY_H_
#define KINBODYDISPLAY_H_

#include <openrave-core.h>

#include <rviz/display.h>
#include "KinBodyVisual.h"

namespace superviewer
{

    class KinBodyDisplay : public rviz::Display
    {
        public:
            KinBodyDisplay(OpenRAVE::KinBodyPtr kinBody, Ogre::SceneManager* sceneManager);
            virtual ~KinBodyDisplay();

            virtual void onInitialize();
            virtual void fixedFrameChanged();
            virtual void reset();
            virtual void createProperties();

        protected:
            virtual void onEnable() { }
            virtual void onDisable() { }
            KinBodyVisual* m_visual;

    };

} /* namespace superviewer */
#endif /* KINBODYDISPLAY_H_ */