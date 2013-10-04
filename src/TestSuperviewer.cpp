#include <openrave-core.h>
#include <vector>
#include <cstring>
#include <sstream>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include "SuperViewer.h"
#include <qapplication.h>

using namespace OpenRAVE;
using namespace std;


void OpenraveThread(EnvironmentBasePtr penv, std::string scenefilename)
{
    penv->Load(scenefilename); // load the scene
}

int main(int argc, char ** argv)
{
    //int num = 1;
    QApplication app(argc, argv);
    ros::init(argc, argv, "superviewer", ros::init_options::AnonymousName);
    string scenefilename = "data/lab1.env.xml";
    string viewername = "superviewer";
    // parse the command line options
    int i = 1;
    while (i < argc)
    {
        if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "-?") == 0) || (strcmp(argv[i], "/?") == 0) || (strcmp(argv[i], "--help") == 0) || (strcmp(argv[i], "-help") == 0))
        {
            RAVELOG_INFO("orloadviewer [--num n] [--scene filename] viewername\n");
            return 0;
        }
        else if (strcmp(argv[i], "--scene") == 0)
        {
            scenefilename = argv[i + 1];
            i += 2;
        }
        else
            break;
    }

    if (i < argc)
    {
        viewername = argv[i++];
    }

    RaveInitialize(true); // start openrave core

    EnvironmentBasePtr penv = RaveCreateEnvironment(); // create the main environment
    RaveSetDebugLevel(Level_Verbose);
    RaveLoadPlugin("./lib/superviewer.so");
    ViewerBasePtr viewer = RaveCreateViewer(penv, "superviewer");
    penv->Add(viewer);

    boost::thread threadRave(boost::bind(OpenraveThread,penv,scenefilename));
    viewer->main(true);

    threadRave.join();

    penv->Destroy(); // destroy
    return 0;
}