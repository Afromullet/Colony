//
//  DataWindow.cpp
//  Colony
//
//  Created by Sean on 1/13/18.
//  Copyright © 2018 Afromullet. All rights reserved.
//

#include "DataWindow.hpp"
#include <iostream>
void DataWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
    if(!isOpen)
        return;
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(highlighter);
    for(int i = 0; i < textComponents.size(); i++)
    {
        target.draw(textComponents.at(i));
    }
    
    
    //states.transform *= getTransform();
    
    
  
    
   }

DataWindow::DataWindow(): rectangle(sf::Vector2f(0,0)),windowType(enUndefinedWindow)
{
    rectangle.setSize(sf::Vector2f(20,20));
    isHighlightOpen = false;
    
}

DataWindow::DataWindow(sf::Vector2f position,sf::Vector2f size) : rectangle(position)
{
    isHighlightOpen = false;
    rectangle.setSize(size);
    
}

void DataWindow::setWindowColor(sf::Color color)
{
    rectangle.setFillColor(color);
}

void DataWindow::setWindowSize(sf::Vector2f size)
{
    rectangle.setSize(size);
}

void DataWindow::setWindowPosition(sf::Vector2f position)
{
    rectangle.setPosition(position);
}


void DataWindow::setYTextOffset(float offset)
{
    yYextOffset = offset;
    
}

void DataWindow::setTextSize(int newTextSize)
{
    textSize = newTextSize;
}

void DataWindow::setTextColor(sf::Color color)
{
    for(int i = 0; i < textComponents.size(); i++)
    {
        textComponents.at(i).setColor(color);
    }
}
/*
void DataWindow::AddText(std::string const &dataString)
{
    
    
    //textComponents.clear();
    int xPosition = 0;
    int yPosition = 0;
    sf::Text text;
    
    //If there are no entries, the text starts at the top left corner
    if(textComponents.size() > 0)
        text.setPosition(0, textSize * textComponents.size());
    else
        text.setPosition(0, 0);

    
    
    text.setFont(font);
    text.setString(dataString);
    
    text.setCharacterSize(textSize);
    textComponents.push_back(text);
    

}
*/

void DataWindow::AddText(std::string const &dataString)
{
    
    
    //textComponents.clear();
    int xPosition = 0;
    int yPosition = 0;
    sf::Text text;
    
    //If there are no entries, the text starts at the top left corner
    sf::Vector2f textPos = rectangle.getPosition();
    
    if(textComponents.size() > 0)
        text.setPosition(rectangle.getPosition().x, textSize * textComponents.size() + rectangle.getPosition().y);
    else
        text.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);

    
    
   
    
    
    text.setFont(font);
    text.setString(dataString);
    
    text.setCharacterSize(textSize);
    textComponents.push_back(text);
    
    
}

void DataWindow::AddTextInBounds(std::string const &dataString)
{
    

}

void DataWindow::setFont(std::string fontName)
{
    if(!font.loadFromFile(fontName))
    {
        std::cout << "Error loading font for datawindow";
    }
    
    
    
    //textComponents.clear();
    sf::Text text;
    text.setFont(font);
    
    /*
    text.setString("abcdefg");
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    textComponents.push_back(text);
    
    text.setString("vyydasdr");
    text.setPosition(100, 100);
    text.setCharacterSize(24);
    text.setColor(sf::Color::Red);
    textComponents.push_back(text);
     */
    
}

void DataWindow::setWindowType(EnDataWindowType _windowType)
{
    windowType = _windowType;
}

void DataWindow::PrintTextToConsole()
{
    for(int i=0; i < textComponents.size(); i++)
    {
        
        std::string tempString = textComponents.at(i).getString();
        std::cout << "\n" << tempString;
    }
}

EnDataWindowType DataWindow::getWindowType()
{
    return windowType;
}

void DataWindow::clearTextComponents()
{
    textComponents.clear();
}

//Basic highlight rectangle is the dimension of the text, top right of the screen
void DataWindow::initBasicHighlightSquare()
{
  
 
    highlighter.setSize(sf::Vector2f(rectangle.getSize().x,textSize));
    highlighter.setFillColor(sf::Color::Yellow);
    highlighter.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);
    highlightPosition = 0;
    
    isHighlightOpen  = true;
}

//Moves the rectangle from the origin to the offset..the offset is calculated from the text size
void DataWindow::MoveHighlightSquare(int yOffset)
{
    int newY = textSize * yOffset + rectangle.getPosition().y; //will use later
    highlighter.setPosition(rectangle.getPosition().x,newY);
    highlightPosition = yOffset;
}