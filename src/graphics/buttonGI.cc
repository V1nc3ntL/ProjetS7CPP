
/*! \file buttonGI.cc
 *  \brief Implementation of the buttons
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/24
 */
#include "buttonGI.hh"
#include "../app/headersLocation.hh"

ButtonGI::ButtonGI(std::pair<int,int> topLeftCorner, int buttonWidth,
  int buttonHeight , 
  std::string buttonString,
  int returnCode
  ) : ButtonGI(topLeftCorner,buttonWidth,buttonHeight,buttonString,returnCode,0){}

ButtonGI::ButtonGI(std::pair<int,int> topLeftCorner, int buttonWidth,
  int buttonHeight , 
  std::string buttonString,
  int returnCode,
  int offset
  )
      : buttonText(buttonString,buttonFont,buttonHeight-MARGIN), 
      rect(sf::Vector2f(buttonWidth,buttonHeight)),
      returnCode(returnCode)
      {  
        rect.setOutlineThickness(MARGIN);
        rect.setFillColor(sf::Color(54, 43, 2,190));
        rect.setOutlineColor(sf::Color(0, 0, 0));
        rect.setPosition(topLeftCorner.first,topLeftCorner.second);

    // ! TODO  take care of file not found case
    buttonFont.loadFromFile(FONTS_DIR"apocalypse.ttf");
    buttonText.setFont(buttonFont);
    buttonText.setFillColor(sf::Color::White);

    // Center text
    buttonText.setPosition( topLeftCorner.first+buttonWidth/2-buttonText.getGlobalBounds().width/2,
                            topLeftCorner.second-MARGIN+offset);
                                      }

bool ButtonGI::isUnder(std::pair<int,int>mouse){
     if ((mouse.first < rect.getPosition().x +rect.getGlobalBounds().width 
       && mouse.first > rect.getPosition().x   )
      // Inside Y
      &&
         (mouse.second < rect.getPosition().y + rect.getGlobalBounds().height  
       && mouse.second > rect.getPosition().y )
      // Outside LeftCorner

  )
    return true;

    return false;
  }