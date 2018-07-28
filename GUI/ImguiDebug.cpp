//
//  ImguiDebug.cpp
//  Colony
//
//  Created by Sean on 7/20/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "ImguiDebug.hpp"
#include <string>
#include "BodyGraphGetters.hpp"

//Storing information entered in the debug menu

std::shared_ptr<CreatureBody> anatomy;

std::vector<BodyPart> debugBodyparts;
std::vector<std::string> debugBodyartNames;

std::vector<CreatureBody> debugBodies;
std::vector<std::string> debugBodiesNames;


BodyPart tempBodyPart;
CreatureBody tempBody;


//Wrappers to help deal with the vector debugBodyParts and anatomy storage containers
//From https://eliasdaler.github.io/using-imgui-with-sfml-pt2/
namespace ImGui
{
    static auto vector_getter = [](void* vec, int idx, const char** out_text)
    {
        auto& vector = *static_cast<std::vector<std::string>*>(vec);
        if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
        *out_text = vector.at(idx).c_str();
        return true;
    };
    
    bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
    {
        if (values.empty()) { return false; }
        return Combo(label, currIndex, vector_getter,
                     static_cast<void*>(&values), values.size());
    }
    
    bool ListBox(const char* label, int* currIndex, std::vector<std::string>& values)
    {
        if (values.empty()) { return false; }
        return ListBox(label, currIndex, vector_getter,
                       static_cast<void*>(&values), values.size());
    }
    
}

BodyPartValidity isValidBodyPart(BodyPart &bp,std::vector<BodyPart> &bpVec)
{
    
    bool nameExists,tokenExists;
    for(int i = 0; i < bpVec.size(); i++)
    {
        if(bpVec.at(i).getBodyPartName() == bp.getBodyPartName() && bpVec.at(i).getBodyPartToken() == bp.getBodyPartToken())
        {
            return BodyPartValidity::DUPLICATE_NAME_AND_TOKEN;
        }
        else if(bpVec.at(i).getBodyPartName() == bp.getBodyPartName())
        {
            return BodyPartValidity::DUPLICATE_NAME;
        }
        else if(bpVec.at(i).getBodyPartToken() == bp.getBodyPartToken())
        {
            return BodyPartValidity::DUPLICATE_TOKEN;
        }
    }
    
    return BodyPartValidity::VALID_BODY_PART;
    
   
}

namespace MainDebugWindow
{
    
    void DebugMainWindow()
    {
        ShowMainDebugWindow();
     
    }
    
    void ShowMainDebugWindow()
    {
    
        static bool p_open;
        static bool no_titlebar = false;
        static bool no_scrollbar = false;
        static bool no_menu = false;
        static bool no_move = false;
        static bool no_resize = false;
        static bool no_collapse = false;
        static bool no_close = false;
        static bool no_nav = false;
        ImGuiWindowFlags window_flags = 0;
        if (no_titlebar)  window_flags |= ImGuiWindowFlags_NoTitleBar;
        if (no_scrollbar) window_flags |= ImGuiWindowFlags_NoScrollbar;
        if (!no_menu)     window_flags |= ImGuiWindowFlags_MenuBar;
        if (no_move)      window_flags |= ImGuiWindowFlags_NoMove;
        if (no_resize)    window_flags |= ImGuiWindowFlags_NoResize;
        if (no_collapse)  window_flags |= ImGuiWindowFlags_NoCollapse;
        if (no_nav)       window_flags |= ImGuiWindowFlags_NoNav;
        if (no_close)     p_open = NULL; // Don't pass our bool* to Begin
        
        ImGui::Begin("blablala",&p_open,window_flags);
        // Menu
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Menu"))
            {
                //ShowExampleMenuFile();
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Examples"))
            {
                if(ImGui::MenuItem("Bodypart Menu"))
                {
                    showCreateBodyPartWindow = true;
                    showEditBodyPartWindow = false;
                    showGraphEditor = false;
                    showGraphViewer = false;
                    
                    
                }
                /*
                if(ImGui::MenuItem("Edit Bodypart"))
                {
                    showCreateBodyPartWindow = false;
                    showEditBodyPartWindow = true;
                    showGraphEditor = false;
                    showGraphViewer = false;
                    
                }
                 */
                if(ImGui::MenuItem("Anatomy Viewer"))
                {
                    showCreateBodyPartWindow = false;
                    showEditBodyPartWindow = false;
                    showGraphEditor = false;
                    showGraphViewer = true;
                    
                }
                if(ImGui::MenuItem("Anatomy Editor"))
                {
                    showCreateBodyPartWindow = false;
                    showEditBodyPartWindow = false;
                    showGraphEditor = true;
                    showGraphViewer = false;
                    
                }
                
                
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Help"))
            {
                
                
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }
           MenuBarHandler();
        
        ImGui::End();
        
    }
    
    void MenuBarHandler()
    {
        if(showCreateBodyPartWindow)
            BodyPartCreator::BPCreator();
        
       // if(showEditBodyPartWindow)
           // BodyPartEditor::BPEditor();
        
       // if(showGraphEditor)
          //  BodyGraphEditor::GraphEditor();
        
        if(showGraphViewer)
            BodyGraphViewer::GraphViewer();
    }
    
   
    
}

namespace BodyPartCreator
{

    void BPCreator()
    {
        
        ImGui::LabelText("label", "Value");
        
        {
            const char* modeSelectItems[] = { "Create Mode", "Edit Mode"};
            ImGui::Combo("Mode Select", &modeSelectIndex, modeSelectItems, IM_ARRAYSIZE(modeSelectItems));
            
            
            if(modeSelectIndex == 0)
            {
                ReadInput();
                if(ImGui::Button(CREATE_BODYPART_BUTTON))
                {
                    CreateBodyPart();
                }
            }
            else if(modeSelectIndex == 1)
            {
                BPEditor();
            }
        }
        
     

    }
    
    
    void ReadInput()
    {
        ImGui::InputText("Bodypart Name", bpName, IM_ARRAYSIZE(bpName));
        ImGui::InputText("Bodypart Token", bpToken, IM_ARRAYSIZE(bpToken));
        ImGui::InputText("Bodypart Section", bpSection, IM_ARRAYSIZE(bpSection));
        
        ImGui::Combo("Can Hold Weapon", &canHoldWeaponSelect, items, IM_ARRAYSIZE(items));
        ImGui::Combo("Can Hold Armor", &canHoldArmorSelect, items, IM_ARRAYSIZE(items));
        ImGui::Combo("Can Interact", &canInteractSelect, items, IM_ARRAYSIZE(items));
        ImGui::Combo("Can Move Creture", &canMoveCreatureSelect, items, IM_ARRAYSIZE(items));
        ImGui::Combo("Can See", &canSeeSelect, items, IM_ARRAYSIZE(items));
        ImGui::Combo("Can Smell", &canSmellSelect, items, IM_ARRAYSIZE(items));
        ImGui::Combo("Can Breathe", &canBreatheSelect, items, IM_ARRAYSIZE(items));
    }
    
    void CreateBodyPart()
    {
        tempBodyPart.setCanHoldWeapon(canHoldWeaponSelect);
        tempBodyPart.setCanHoldArmor(canHoldArmorSelect);
        tempBodyPart.setCanInteract(canInteractSelect);
        tempBodyPart.setCanMoveCreature(canMoveCreatureSelect);
        tempBodyPart.setCanSee(canSeeSelect);
        tempBodyPart.setCanSmell(canSmellSelect);
        tempBodyPart.setCanBreathe(canBreatheSelect);
        tempBodyPart.setBodyPartName(bpName);
        tempBodyPart.setBodyPartToken(bpToken);
        tempBodyPart.setSection(bpSection);
        
        BodyPartValidity validity = isValidBodyPart(tempBodyPart,debugBodyparts);
        
        if(validity == DUPLICATE_NAME_AND_TOKEN)
        {
            std::cout << "\n Duplicate name and token";
        }
        else if(validity == DUPLICATE_NAME)
        {
            std::cout << "\n Duplicate name ";
        }
        else if(validity == DUPLICATE_TOKEN)
        {
            std::cout << "\n Duplicate token";
        }
        else if(validity == VALID_BODY_PART)
        {
            std::cout << "\n Valid body part";
            
            debugBodyparts.push_back(tempBodyPart);
        }
        
        
        
        
        tempBodyPart =  BodyPart();
        
        DisplayShit();

    }
    
    
    void BPEditor()
    {
        //ImGui::Begin(EDIT_BODYPART_WINDOW);
        
        
        ImGui::LabelText("label", "Value");
        
        {
            UniversalDebugFunctions::UpdateBodyPartNames();
            
            ImGui::Combo(BP_EDITOR_SELECT_COMBO, &item, debugBodyartNames);
            
            //Don't want out of bounds condition
            if(item > -1)
            {
                BodyPart &bpRef = debugBodyparts.at(item);
                //std::cout << "\n Printing selected item name " << bpRef.getBodyPartName();
                DisplaySelectedInput(bpRef);
                
                
                
                ImGui::Separator();
                ImGui::Separator();
                
                
                ReadInput();
                
                if(ImGui::Button(EDIT_BODYPART_BUTTON))
                {
                    
                    UpdateBodyPart(bpRef);
                }
                
                
                
            }//End index > -1
            
            
        }//
        // ImGui::End();
    }
    
    void DisplaySelectedInput(BodyPart &bpRef)
    {
        ImGui::Text("Current Values");
        
        std::string dataString = "Name: " + bpRef.getBodyPartName();
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Token: " + bpRef.getBodyPartToken();
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Section: " + bpRef.getSection();
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Weapon: " + convertBPTruthVal(bpRef.getCanHoldWeapon());
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Armor " + convertBPTruthVal(bpRef.getCanHoldArmor());
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanInteract());
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanMoveCreature());
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSee());
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSmell());
        ImGui::Text("%s",dataString.c_str());
        
        dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanBreathe());
        ImGui::Text("%s",dataString.c_str());
        
    }
    

    
    void UpdateBodyPart(BodyPart &bpRef)
    {
        BodyPart tempBP = bpRef;
        std::cout << "\n Item number" << item;
        
        bpRef.setCanHoldWeapon(canHoldWeaponSelect);
        bpRef.setCanHoldArmor(canHoldArmorSelect);
        bpRef.setCanInteract(canInteractSelect);
        bpRef.setCanMoveCreature(canMoveCreatureSelect);
        bpRef.setCanSee(canSeeSelect);
        bpRef.setCanSmell(canSmellSelect);
        bpRef.setCanBreathe(canBreatheSelect);
        
        bpRef.setBodyPartName(bpName);
        bpRef.setBodyPartToken(bpToken);
        bpRef.setSection(bpSection);
        
    }

    
    
}

namespace BodyGraphViewer
{
    CreatureBody tempGraph;

    
    void SetupViewerComponents()
    {
        
        
         UniversalDebugFunctions::UpdateAnatomyNames();
        UniversalDebugFunctions::UpdateBodyPartNames();
        
         ImGui::Text("Select Graph Graph");
        
        ImGui::Combo("Select Anatomy Graph", &graphItem, debugBodiesNames);
        

    }
    
    void BuildBodypartGraph()
    {
        
    }
    
    void CreateNewGraph()
    {
        ImGui::LabelText("Test","Vale");
        {
            static char graphName[128] = "Empty";
            ImGui::InputText("Graph Name", graphName, IM_ARRAYSIZE(graphName));
            
            if(ImGui::Button(CREATE_NEW_BODYGRPAH_BUTTON))
            {
                
                
                tempBody.setName(graphName);
                debugBodies.push_back(tempBody);
            }
        }
    }
    
    void VertexAdder()
    {
        ImGui::Text("Select Bodypart to Add to Graph");
        
        {
            ImGui::Combo("BP Vertex Selector", &vertexAddItem, debugBodyartNames);
            ImGui::SameLine(); ImGui::Checkbox("Show Bodypart Stats", &showBPStats);
            
            
            //Don't want out of bounds condition
            if(vertexAddItem > -1 && showBPStats)
            {
                BodyPart &bpRef = debugBodyparts.at(vertexAddItem);
                //std::cout << "\n Printing selected item name " << bpRef.getBodyPartName();
                
                
                
                ImGui::Text("Current Values");
                
                std::string dataString = "Name: " + bpRef.getBodyPartName();
                ImGui::Text("%s",dataString.c_str());
                
                
                dataString = "Token: " + bpRef.getBodyPartToken();
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Section: " + bpRef.getSection();
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Weapon: " + convertBPTruthVal(bpRef.getCanHoldWeapon());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Armor " + convertBPTruthVal(bpRef.getCanHoldArmor());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanInteract());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanMoveCreature());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSee());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSmell());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanBreathe());
                ImGui::Text("%s",dataString.c_str());
            }
            
            if(ImGui::Button("Add Vertex to graph"))
            {
                
                if(graphItem > -1  && vertexAddItem > -1)
                {
                    
                    debugBodies.at(graphItem).AddVertex(debugBodyparts.at(vertexAddItem));
                    
            
                }
                
            }
        }
        

    }
    
    void DisplayGraph()
    {
                tempGraph = UniversalDebugFunctions::getBody(debugBodiesNames.at(graphItem));
        std::string nodeString;
        for(int i = 0; i < num_vertices(tempGraph.anatomyGraph); i++)
        {
            nodeString = tempGraph.anatomyGraph[i].getBodyPartName() + " Connections ";
            
            if (ImGui::TreeNode(nodeString.c_str()))
            {
                
                
                CreateBPTree(tempGraph,i);
                ImGui::TreePop();
                
            }
            
        }
        
        std::cout << "\n Show name " << tempGraph.getName();
    }
    
    void GraphViewer()
    {
        
       
      //  ImGui::Begin("Body Graph Viewer");
        
        
        const char* modeSelectItems[] = { "Create Graph Mode", "Add Vertex Mode","Connector Mode","Viewer Mode"};
        ImGui::Combo("Mode Select", &modeSelectIndex, modeSelectItems, IM_ARRAYSIZE(modeSelectItems));

        ImGui::Separator();
        ImGui::Separator();
        ImGui::Separator();
        if(modeSelectIndex == 0)
        {
             CreateNewGraph();
        }
        else if(modeSelectIndex == 1)
        {
            SetupViewerComponents();
            VertexAdder();
            
        }
        else if(modeSelectIndex == 2)
        {
             SetupViewerComponents();
             BodyGraphConnector();
        }
        else if(modeSelectIndex == 3)
        {
            
            SetupViewerComponents();
            
            
            ImGui::Checkbox("Show Body Anatomy ", &showAnatomy);
            
            
            
            if(showAnatomy)
            {
                if(graphItem >= 0)
                    DisplayGraph();
            }
            
            
        }
        

       
        

        
       

       
        
        
        
 
        
       
        
       
        
       
        
      
        
       // ImGui::End();
    }
    
    void BodyGraphConnector()
    {
    
        
        FirstBodyPartMenu();
        SecondBodyPartMenu();

        ImGui::LabelText("Connection Type", "");
        
        {
            // Using the _simplified_ one-liner Combo() api here
            // See "Combo" section for examples of how to use the more complete BeginCombo()/EndCombo() api.
            const char* bpConnectionTypes[] = { "Symmetric", "Direct", "Left", "Right", "Internal", "Internal Left", "Internal Right", "External Left", "External Right", "External", "External Left Front", "External Right Front" };
            static int current_BP_connection = 0;
            ImGui::Combo("Connection Type", &current_BP_connection, bpConnectionTypes, IM_ARRAYSIZE(bpConnectionTypes));
            
        }
        
        ConnectBodyPartsButtonHandler();
        
        
    }
    
    void FirstBodyPartMenu()
    {
        ImGui::Text("Body Part 1");
        
        {
            ImGui::Combo("Bodypart 1", &item, debugBodyartNames);
            ImGui::SameLine(); ImGui::Checkbox("Show BP 1 Stats", &showBP1Stats);
            //Don't want out of bounds condition
            if(item > -1 && showBP1Stats)
            {
                BodyPart &bpRef = debugBodyparts.at(item);
                //std::cout << "\n Printing selected item name " << bpRef.getBodyPartName();
                
                
                
                ImGui::Text("Current Values");
                
                std::string dataString = "Name: " + bpRef.getBodyPartName();
                ImGui::Text("%s",dataString.c_str());
                
                
                dataString = "Token: " + bpRef.getBodyPartToken();
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Section: " + bpRef.getSection();
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Weapon: " + convertBPTruthVal(bpRef.getCanHoldWeapon());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Armor " + convertBPTruthVal(bpRef.getCanHoldArmor());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanInteract());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanMoveCreature());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSee());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSmell());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanBreathe());
                ImGui::Text("%s",dataString.c_str());
            }
        }
        
     
    }
    
    void SecondBodyPartMenu()
    {
        
        ImGui::Text("Body Part 2");
        
        {
            
            
            
            
            ImGui::Combo("Bodypart 2", &item2, debugBodyartNames);
            ImGui::SameLine(); ImGui::Checkbox("Show BP 2", &showBP2Stats);

            //Don't want out of bounds condition
            if(item2 > -1 && showBP2Stats)
            {
                BodyPart &bpRef = debugBodyparts.at(item2);
                //std::cout << "\n Printing selected item name " << bpRef.getBodyPartName();
                
                
                
                ImGui::Text("Current Values");
                
                std::string dataString = "Name: " + bpRef.getBodyPartName();
                ImGui::Text("%s",dataString.c_str());
                
                
                dataString = "Token: " + bpRef.getBodyPartToken();
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Section: " + bpRef.getSection();
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Weapon: " + convertBPTruthVal(bpRef.getCanHoldWeapon());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Armor " + convertBPTruthVal(bpRef.getCanHoldArmor());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanInteract());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanMoveCreature());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSee());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSmell());
                ImGui::Text("%s",dataString.c_str());
                
                dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanBreathe());
                ImGui::Text("%s",dataString.c_str());
            }
        }
        
    }
    
    void ConnectBodyPartsButtonHandler()
    {
        
        
        if(ImGui::Button("Connect Parts"))
        {
            
            BodyPart bp1,bp2;
            
            UniversalDebugFunctions::UpdateBodyPartNames();
            
            
         
            
            if(item >= 0)
            {
                bp1 = UniversalDebugFunctions::GetBodyPart(debugBodyartNames.at(item));
            }
                
            if(item2 >= 0)
            {
                bp2 = UniversalDebugFunctions::GetBodyPart(debugBodyartNames.at(item2));
            }
            
            std::cout << "\n Name 1 " << bp1.getBodyPartName();
            std::cout << "\n Name 2 " << bp2.getBodyPartName();
        }
        

    }
    

    
}


namespace UniversalDebugFunctions
{
    
    
    BodyPart GetBodyPart(std::string name)
    {
        std::vector<BodyPart>::iterator it;
        for(it = debugBodyparts.begin(); it != debugBodyparts.end(); ++it)
        {
          
            if(it->getBodyPartName() == name)
                return *it;
        }
        
        BodyPart bp;
        return bp;
            
    }
    
    CreatureBody getBody(std::string name)
    {
        std::vector<CreatureBody>::iterator it;
        for(it = debugBodies.begin(); it != debugBodies.end(); ++it)
        {
            
            if(it->getName() == name)
                return *it;
        }
        
        CreatureBody body;
        return body;
    }
    
    void UpdateBodyPartNames()
    {
        debugBodyartNames.clear();
        std::vector<BodyPart>::iterator it;
        for(it = debugBodyparts.begin(); it != debugBodyparts.end(); ++it)
            debugBodyartNames.push_back(it->getBodyPartName());
    }
    
    void UpdateAnatomyNames()
    {
        debugBodiesNames.clear();
        std::vector<CreatureBody>::iterator it;
        for(it = debugBodies.begin(); it != debugBodies.end(); ++it)
            debugBodiesNames.push_back(it->getName());
    }
}




// Helper to display a little (?) mark which shows a tooltip when hovered.
static void ShowHelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}





void BPConnector()
{
    
    ImGui::Begin("Body Part Connector");
    
    

    
    
    ImGui::Text("Body Part 1");
    
    {
        
        
        
        static int item = -1;
        ImGui::Combo("Combo", &item, debugBodyartNames);
        //Don't want out of bounds condition
        if(item > -1)
        {
            BodyPart &bpRef = debugBodyparts.at(item);
            //std::cout << "\n Printing selected item name " << bpRef.getBodyPartName();
            
            
            
            ImGui::Text("Current Values");
            
            std::string dataString = "Name: " + bpRef.getBodyPartName();
            ImGui::Text("%s",dataString.c_str());
            
            
            dataString = "Token: " + bpRef.getBodyPartToken();
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Section: " + bpRef.getSection();
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Weapon: " + convertBPTruthVal(bpRef.getCanHoldWeapon());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Armor " + convertBPTruthVal(bpRef.getCanHoldArmor());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanInteract());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanMoveCreature());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSee());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSmell());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanBreathe());
            ImGui::Text("%s",dataString.c_str());
        }
    }
    
    
    ImGui::Text("Body Part 2");
    
    {
        
        
        
        static int item2 = -1;
        ImGui::Combo("Combo2", &item2, debugBodyartNames);
        //Don't want out of bounds condition
        if(item2 > -1)
        {
            BodyPart &bpRef = debugBodyparts.at(item2);
            //std::cout << "\n Printing selected item name " << bpRef.getBodyPartName();
            
            
            
            ImGui::Text("Current Values");
            
            std::string dataString = "Name: " + bpRef.getBodyPartName();
            ImGui::Text("%s",dataString.c_str());
            
            
            dataString = "Token: " + bpRef.getBodyPartToken();
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Section: " + bpRef.getSection();
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Weapon: " + convertBPTruthVal(bpRef.getCanHoldWeapon());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Armor " + convertBPTruthVal(bpRef.getCanHoldArmor());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanInteract());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanMoveCreature());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSee());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanSmell());
            ImGui::Text("%s",dataString.c_str());
            
            dataString = "Can Hold Interact " + convertBPTruthVal(bpRef.getCanBreathe());
            ImGui::Text("%s",dataString.c_str());
        }
    }
    

    
    ImGui::LabelText("Connection Type", "");
    
    {
        // Using the _simplified_ one-liner Combo() api here
        // See "Combo" section for examples of how to use the more complete BeginCombo()/EndCombo() api.
        const char* bpConnectionTypes[] = { "Symmetric", "Direct", "Left", "Right", "Internal", "Internal Left", "Internal Right", "External Left", "External Right", "External", "External Left Front", "External Right Front" };
        static int current_BP_connection = 0;
        ImGui::Combo("Connection Type", &current_BP_connection, bpConnectionTypes, IM_ARRAYSIZE(bpConnectionTypes));
       
    }

    
    
    ImGui::End();
}



void BodyGraphViewer2(CreatureBody &body)
{
    
    
    
    

    std::string nodeString;
    
    ImGui::Begin("Body Graph Viewer2");
    
    ImGui::LabelText("Test","Vale");
    {
        static char graphName[128] = "Empty";
        ImGui::InputText("Graph Name", graphName, IM_ARRAYSIZE(graphName));
        
        if(ImGui::Button("Create Anatomy Graph"))
        {
           
    
            tempBody.setName(graphName);
            debugBodies.push_back(tempBody);
        }
    }
    static int item = -1;

    
    debugBodiesNames.clear();
    
    std::vector<CreatureBody>::iterator bodyIt;

    for(bodyIt = debugBodies.begin(); bodyIt != debugBodies.end(); ++bodyIt)
        debugBodiesNames.push_back(bodyIt->getName());

        ImGui::Combo("Combo", &item, debugBodiesNames);
    ImGui::Separator();
    ImGui::Separator();
    
    //nodeString = body.anatomyGraph[0].getBodyPartName() + "Connections ";
    
    
    for(int i = 0; i < num_vertices(body.anatomyGraph); i++)
    {
         nodeString = body.anatomyGraph[i].getBodyPartName() + "Connections ";
        
        if (ImGui::TreeNode(nodeString.c_str()))
        {
            
           
            CreateBPTree(body,i);
            ImGui::TreePop();
            
        }
        
    }
    
    /*
    if (ImGui::TreeNode(nodeString.c_str()))
    {
        
        CreateBPTree(body,0);
        ImGui::TreePop();
    }
    
    
    
      if (ImGui::TreeNode("Collapsing Headers"))
      {
          
          CreateBPTree(body,1);
          ImGui::TreePop();
      }
     */
    
    //CreateBPTree(body,5);
    
    
    
    
    
    
    
    
    
    ImGui::End();

}

//Creates a tree of all body parts connected to vertex[n] in the anatomyGraph
void CreateBPTree(CreatureBody &body,int n)
{
    std::vector<int> indices;
    indices = getConnectedVertices(n,body.anatomyGraph);
    
    //The top node is the name of the body part for which we will show all connected vertices
    
    std::string testS = body.anatomyGraph[n].getBodyPartName();
    
    //The top node is the name of the body part for which we will show all connected vertices
    if (ImGui::TreeNode("%s",body.anatomyGraph[n].getBodyPartName().c_str()))
    {
        
        //This call to ImGui::Text prints the name of the body parts the parent node is connected to
        for (int i = 0; i < indices.size(); i++)
        {
             ImGui::Text("%s",body.anatomyGraph[indices.at(i)].getBodyPartName().c_str());
        }
        
        
        ImGui::TreePop();
        
        
        
        
        
    }

}

int getBPTruthValIndex(bool val)
{
    if(val == false)
        return 0;
    else if(val == true)
        return 1;
}

std::string convertBPTruthVal(bool val)
{
    if(val== true)
        return "True";
    if(val == false)
        return "False";
}

void DisplayShit()
{
    for(int i = 0; i < debugBodyparts.size(); i++)
    {
        std::cout << "\n" << debugBodyparts.at(i).getBodyPartName();
    }
}
