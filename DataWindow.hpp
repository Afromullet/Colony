//
//  DataWindow.hpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#ifndef DataWindow_hpp
#define DataWindow_hpp
//Contains data to display to the player. I.E, inventory and what's equipped
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.hpp"
#include "Globals.hpp"

enum EnDataWindowType{enInventoryWindow,enEquipmentWindow,enInventorySelectWindow,enExamineItemWindow,enUndefinedWindow};

//Isn't this basically a DataWindow tree?

class DataWindow : public sf::Drawable, sf::Transformable
{
private:

    sf::Font font;
    float yYextOffset; //The y offset between each text Component
    int textSize;
    std::vector<sf::Text> textComponents;
    EnDataWindowType windowType;
    
    
    
    sf::RectangleShape highlighter; //The rectangle highlights parts of the window, I.E, selecting equipment
    
    
    
public:
    
    DataWindow();
    DataWindow(const DataWindow& newWindow);
    //DataWindow();
    sf::RectangleShape rectangle;
    std::vector<DataWindow> subWindows;
    bool isOpen;
    bool isHighlightOpen;
    int highlightPosition; //Determines y position

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
  
    DataWindow(sf::Vector2f position,sf::Vector2f size);
    void AddText(std::string const &dataString);
    void AddTextInBounds(std::string const &dataString);
    void AddSubWindow(DataWindow _dataWindow);
    
    void setYTextOffset(float offset);
    void setWindowColor(sf::Color color);
    void setWindowSize(sf::Vector2f size);
    void setWindowPosition(sf::Vector2f position);
    void setFont(std::string fontName);
    void setTextSize(int newTextSize);
    void setTextColor(sf::Color color);
    void setWindowType(EnDataWindowType _windowType);
    EnDataWindowType getWindowType();
    void clearTextComponents();
    void initBasicHighlightSquare();
    void initBasicHighlightSquare(EnDataWindowType _windowType);
    void OpenSubWindow(EnDataWindowType _windowType);
    bool anySubWindowsOpen();
    void closeSubWindow(EnDataWindowType _windowType);
    
    DataWindow& getSubWindow(EnDataWindowType windowType);
    
    void PrintTextToConsole();
    void MoveHighlightSquare(int yOffset);
    
};

#endif /* DataWindow_hpp */
