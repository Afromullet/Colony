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

class DataWindow : public sf::Drawable, sf::Transformable
{
private:
    sf::RectangleShape rectangle;
    sf::Font font;
       float yYextOffset; //The y offset between each text Component
    int textSize;
    std::vector<sf::Text> textComponents;
    
public:
    
    


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    DataWindow();
    DataWindow(sf::Vector2f position,sf::Vector2f size);
    void AddText(std::string const &dataString);
    void setYTextOffset(float offset);
    void setWindowColor(sf::Color color);
    void setWindowSize(sf::Vector2f size);
    void setWindowPosition(sf::Vector2f position);
    void setFont(std::string fontName);
    void setTextSize(int newTextSize);
    void setTextColor(sf::Color color);
    
    void clearTextComponents();
    
    
    
    void PrintTextToConsole();
    
};

#endif /* DataWindow_hpp */
