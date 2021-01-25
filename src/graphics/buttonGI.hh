/*! \file buttonGI.hh
 *  \brief The graphic implementation of a button
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 20/12/16
 */
#ifndef __BUTTON_GRAPHIC_IMP_HH__
#define __BUTTON_GRAPHIC_IMP_HH__

#include <SFML/Graphics.hpp>
#include "../events/clickable.hh"


constexpr int MARGIN = 10; 
class Clickable;
class ButtonGI : public sf::Drawable, public Clickable {


public:

  /*! \fn ButtonGI::ButtonGI()
   *  \brief Creates an empty graphic implementation
   *  The implementation must be set after construction !
   */
  ButtonGI(){};
  /*! \fn ButtonGI::~ButtonGI()
   *  \brief Destroys a main menu graphic implementation
   *
   */
  ~ButtonGI(){};

  /*! \fn  ButtonGI(std::pair<int, int> topLeftCorner, int buttonWidth,int buttonHeight,std::string buttonString,int returnCode,int offset) 
   * \brief Creates a button from the parameters 
   * \param topLeftCorner the xy position in pixel of the top left corner of the button 
   * \param buttonWidth the button width in pixels 
   * \param buttonHeight the button height in pixels 
   * \param buttonString the button text
   * \param returnCode the int returned by the button when clicked on it 
   * \param offset  the text offset from the top 
   */
  ButtonGI(std::pair<int, int> topLeftCorner, 
           int buttonWidth,
           int buttonHeight, 
           std::string buttonString,
           int returnCode,
           int offset
  );
 /*! \fn  ButtonGI(std::pair<int, int> topLeftCorner, int buttonWidth,int buttonHeight,std::string buttonString,int returnCode) 
   * \brief Creates a button from the parameters without offset
   * \param topLeftCorner the xy position in pixel of the top left corner of the button 
   * \param buttonWidth the button width in pixels 
   * \param buttonString the button text
   * \param returnCode the int returned by the button when clicked on it 
   */
  ButtonGI(std::pair<int, int> topLeftCorner, 
           int buttonWidth,
           int buttonHeight , 
           std::string buttonString,
           int returnCode
  );
  virtual int leftClickAction(){      return returnCode;  }
  virtual int rightClickAction(){    return -1;  }

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect);
    target.draw(buttonText);
  }

  
  bool isUnder(std::pair<int,int>mouse);
  
  private:
    sf::Text buttonText;
    sf::Font buttonFont;
    sf::RectangleShape rect;
    int returnCode;
};
#endif