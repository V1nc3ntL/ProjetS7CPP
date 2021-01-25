/*! \file spriteButtonGI.hh
 *  \brief The graphic implementation of a button with an embedded sprite
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 20/12/16
 */
#ifndef __SP_BUTTON_GRAPHIC_IMP_HH__
#define __SP_BUTTON_GRAPHIC_IMP_HH__

#include <SFML/Graphics.hpp>
#include "../events/clickable.hh"


class SpriteButtonGI : public sf::Drawable, public Clickable {

public:

  /*! \fn SpriteButtonGI::SpriteButtonGI()
   *  \brief Creates an empty graphic implementation
   *  The implementation must be set after construction !
   */
  SpriteButtonGI();
  /*! \fn SpriteButtonGI::~SpriteButtonGI()
   *  \brief Destroys a main menu graphic implementation
   *
   */
  ~SpriteButtonGI(){};

  /*! \fn  SpriteButtonGI(std::pair<int, int> topLeftCorner, int buttonWidth,std::string spriteFileName,int returnCode) 
   * \brief Creates a button from the parameters 
   * \param topLeftCorner the xy position of the top Left corner
   * \param spriteFileName the sprite file name
   * \param returnCode the int returned by the button when clicked on it 
   */
  SpriteButtonGI(std::pair<int,int> topLeftCorner ,
           std::string spriteFileName,
           int returnCode
  );

  virtual int leftClickAction(){      return returnCode;  }
  virtual int rightClickAction(){    return -1;  }

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
      target.draw(sprit);
      
  }

  
  bool isUnder(std::pair<int,int>mouse) const;
  
  private:
    int returnCode;
    sf::Sprite sprit;
    sf::RectangleShape rect;
    sf::Texture texture;
};
#endif