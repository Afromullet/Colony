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

    states.blendMode = sf::BlendAlpha;
    
    target.draw(rectangle,states);
    //target.draw(rectangle);
    
    
    
    target.draw(highlighter);
    for(int i = 0; i < textComponents.size(); i++)
    {
        target.draw(textComponents.at(i));
    }
    
    for(int i = 0; i < subWindows.size(); i++)
    {
        
        if(!subWindows.at(i).isOpen)
            continue;
        
        //target.draw(subWindows.at(i));
        //target.draw(subWindows.at(i).highlighter);
        target.draw(subWindows.at(i),states);
        if(subWindows.at(i).isHighlightOpen)
            target.draw(subWindows.at(i).highlighter,states);

        for(int j = 0; j > subWindows.at(i).textComponents.size(); i++)
        {
            target.draw(subWindows.at(i).textComponents.at(i),states);
        }
    
        
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


DataWindow::DataWindow(const DataWindow& newWindow)
{
    font = newWindow.font;
    yYextOffset = newWindow.yYextOffset;
    textSize = newWindow.textSize;
    

    textComponents = newWindow.textComponents;
    windowType = newWindow.windowType;
    subWindows = newWindow.subWindows;
    rectangle = newWindow.rectangle;
    highlighter = newWindow.highlighter;
    subWindows = newWindow.subWindows;
    isOpen = newWindow.isOpen;
    isHighlightOpen = newWindow.isHighlightOpen;
    highlightPosition = newWindow.highlightPosition;
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

void DataWindow::AddSubWindow(DataWindow _dataWindow)
{
    subWindows.push_back(_dataWindow);
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
    highlighter.setFillColor(BasicHighlightColor);
    highlighter.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);
    highlightPosition = 0;
    
    isHighlightOpen  = true;
}

//Handles highlighte for subwindows
void DataWindow::initBasicHighlightSquare(EnDataWindowType _windowType)
{
    for(int i=0; i < subWindows.size(); i++)
    {
        if(subWindows.at(i).getWindowType() == _windowType)
        {
            DataWindow &tempWindow = subWindows.at(i);
            
            tempWindow.highlighter.setSize(sf::Vector2f(tempWindow.rectangle.getSize().x,tempWindow.textSize));
            tempWindow.highlighter.setFillColor(BasicHighlightColor);
            tempWindow.highlighter.setPosition(tempWindow.rectangle.getPosition().x, tempWindow.rectangle.getPosition().y);
            tempWindow.highlightPosition = 0;
            tempWindow.isHighlightOpen  = true;
            break;
            
         
        }
    }
    
    /*
    highlighter.setSize(sf::Vector2f(rectangle.getSize().x,textSize));
    highlighter.setFillColor(sf::Color::Yellow);
    highlighter.setPosition(rectangle.getPosition().x, rectangle.getPosition().y);
    highlightPosition = 0;
    isHighlightOpen  = true;
     */
}

//Moves the rectangle from the origin to the offset..the offset is calculated from the text size
void DataWindow::MoveHighlightSquare(int yOffset)
{
    int newY = textSize * yOffset + rectangle.getPosition().y; //will use later
    highlighter.setPosition(rectangle.getPosition().x,newY);
    highlightPosition = yOffset;
}

DataWindow& DataWindow::getSubWindow(EnDataWindowType windowType)
{
    for(int i = 0; i < subWindows.size(); i++)
    {
        if(subWindows.at(i).getWindowType() == windowType)
        {
           
            
           
            return subWindows.at(i);
        }
    }
    
    printf("\nCould not find shit\n");
    
    //TODO handle window not found
    
    return subWindows.at(0);
}

void DataWindow::OpenSubWindow(EnDataWindowType _windowType)
{
    for(int i = 0; i < subWindows.size(); i++)
    {
        if(subWindows.at(i).getWindowType() == _windowType)
        {
            subWindows.at(i).isOpen = true;
        }
    }
}

bool DataWindow::anySubWindowsOpen()
{
    for(int i=0; i < subWindows.size(); i++)
    {
        if(subWindows.at(i).isOpen)
            return true;
    }
    
    return false;
}

void DataWindow::closeSubWindow(EnDataWindowType _windowType)
{
    for(int i = 0; i < subWindows.size(); i++)
    {
        if(subWindows.at(i).getWindowType() == _windowType)
        {
            subWindows.at(i).isOpen = false;
            break;
        }
    }
}
