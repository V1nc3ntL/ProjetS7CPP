#include "spriteButtonGI.hh"
#include "../app/headersLocation.hh"

 SpriteButtonGI::SpriteButtonGI(std::pair<int,int> topLeftCorner  ,
           std::string spriteFileName,
           int returnCode
  ) :
  returnCode(returnCode){
      if (texture.loadFromFile(IMGS_DIR+spriteFileName ))
        {
            sprit.setTexture(texture);
            sprit.setPosition(sf::Vector2f(topLeftCorner.first, topLeftCorner.second));
        }
  }

  bool SpriteButtonGI::isUnder(std::pair<int,int>mouse) const{
     if ((mouse.first < sprit.getPosition().x +sprit.getGlobalBounds().width 
       && mouse.first > sprit.getPosition().x   )
      // Inside Y
      &&
         (mouse.second < sprit.getPosition().y + sprit.getGlobalBounds().height  
       && mouse.second > sprit.getPosition().y )
      // Outside LeftCorner

  )
    return true;

    return false;
  }
  