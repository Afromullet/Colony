//
//  ImguiDebug.hpp
//  Colony
//
//  Created by Sean on 7/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef ImguiDebug_hpp
#define ImguiDebug_hpp


#ifdef ENABLE_IMGUI


#include "imgui.h"
#include "imgui-SFML.h"
#include <memory>
#include "BodyGraph.hpp"
#include <string>
#include "BodyPart.hpp"
#include <vector>
#include <string>
//#include "BodyGraphGetters.hpp"




//Storing information entered in the debug menu
extern BodyPart tempBodyPart;
extern CreatureBody tempBody;

extern std::shared_ptr<CreatureBody> anatomy;

extern std::vector<BodyPart> debugBodyparts;
extern std::vector<std::string> debugBodyartNames;

extern std::vector<CreatureBody> debugBodies;
extern std::vector<std::string> debugBodiesNames;



#define CREATE_BODYPART_WINDOW "Create Bodypart"
#define CREATE_BODYPART_BUTTON "Create Body Button"

#define EDIT_BODYPART_WINDOW "Edit Bodypart"
#define BP_EDITOR_SELECT_COMBO "Select Editor Bodypart"
#define EDIT_BODYPART_BUTTON "Edit Bodypart Button"

#define CREATE_NEW_BODYGRPAH_BUTTON "New Body Graph Button"

#define CREATE_BODYPART_MENU_ITEM "Create BodyPart Menu Item"
#define EDIT_BODYPART_MENU_ITEM "Edit BodyPart Menu Item"


enum BodyPartValidity
{
    DUPLICATE_NAME,
    DUPLICATE_TOKEN,
    DUPLICATE_NAME_AND_TOKEN,
    VALID_BODY_PART
};

BodyPartValidity isValidBodyPart(BodyPart &bp,std::vector<BodyPart> &bpVec);


namespace MainDebugWindow
{
    static bool showCreateBodyPartWindow = false;
    static bool showEditBodyPartWindow = false;
    static bool showGraphEditor = false;
    static bool showGraphViewer = false;
    
    static bool show_app_main_menu_bar = false;
    static bool show_app_console = false;
    static bool show_app_log = false;
    static bool show_app_layout = false;
    static bool show_app_property_editor = false;
    static bool show_app_long_text = false;
    static bool show_app_auto_resize = false;
    static bool show_app_constrained_resize = false;
    static bool show_app_simple_overlay = false;
    static bool show_app_window_titles = false;
    static bool show_app_custom_rendering = false;
    
    void DebugMainWindow();
    void ShowMainDebugWindow();
    void MenuBarHandler();
}

namespace BodyPartCreator
{
    static int canHoldWeaponSelect = 0;
    static int canHoldArmorSelect = 0;
    static int canInteractSelect = 0;
    static int canMoveCreatureSelect = 0;
    static int canSeeSelect = 0;
    static int canSmellSelect = 0;
    static int canBreatheSelect = 0;
    //static int isInternalSelect = 0
    static char bpName[128] = "Empty";
    static char bpToken[128] = "Empty";
    static char bpSection[128] = "Empty";
    static const char* items[] = { "False", "True"};
    static int createButtonClicked = 0;
    static int item = -1;
    
    
    static int modeSelectIndex;
    
    
    
    void BPCreator();
    void ReadInput();
    void CreateBodyPart();
    
    void BPEditor();
    void DisplaySelectedInput(BodyPart &bpRef);
    void ReadInput();
    void UpdateBodyPart(BodyPart &bpRef);
}


namespace BodyGraphViewer
{
    static int graphItem = -1;
    static int item = -1;
    static int item2 = -1;
    static int vertexAddItem = -1;
    static int modeSelectIndex = -1;
    static int prevIndex = -1;
    
    
    
    static bool showBP1Stats = false;
    static bool showBP2Stats = false;
    static bool showBPStats = false;
    static bool showAnatomy = false;
    
    

    
    
    void SetupViewerComponents();
    void BuildBodypartGraph();
    void DisplayGraph();
    void GraphViewer();
    void BodyGraphConnector();
    
    
    void CreateNewGraph();
    void VertexAdder();
    void FirstBodyPartMenu();
    void SecondBodyPartMenu();
    void ConnectBodyPartsButtonHandler();
}

namespace UniversalDebugFunctions
{
    void UpdateBodyPartNames();
    void UpdateAnatomyNames();
    BodyPart GetBodyPart(std::string name);
    CreatureBody getBody(std::string name);
    CreatureBody getBodyRef(std::string name);
}




void BPConnector();
void BodyGraphViewer2(CreatureBody &body);
void CreateBPTree(CreatureBody &body,int n);

int getBPTruthValIndex(bool val);
std::string convertBPTruthVal(bool val);

void DisplayShit();


//Will eventually need something that interfaces with mapdata, to put the creatures on the map.
//shared_ptr<BaseCreature> debugCreatures;

/*
 The idea for a class here is one that takes input from the debug window and handles it to allow the construction of different body parts of creatures..A humanoid body, a winged creature, something with horns..
 
  Container of BodyGraph that is manipulated - therefore body pars.
 
 
 
 
 
 */



//Groups of functions that serve as a debug menu..I.E, spawning creatures, modifying stats


#endif 

#endif /* ImguiDebug_hpp */
