/*! \file mainMenuGI.hh
 *  \brief The graphic implementation of the main menu
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 20/12/16
 */
#ifndef __MAIN_MENU_GRAPHIC_IMP_HH__
#define __MAIN_MENU_GRAPHIC_IMP_HH__

#include "buttonGI.hh"
#include "localization.hh"
#include "usrInterface.hh"


static constexpr int buttonNr = 2;

static constexpr int itemsHeight = 100;
// Forward declaration
class Clickable;

class MainMenuGI : public usrInterface {

public:
  /*! \fn MainMenuGI::MainMenuGI()
   *  \brief Creates an empty graphic implementation
   *  The implementation must be set after construction !
   */
  MainMenuGI(){};
  /*! \fn MainMenuGI::~MainMenuGI()
   *  \brief Destroys a main menu graphic implementation
   *
   */
  ~MainMenuGI(){};

  /*! \fn  MainMenuGI(int & windowWidth, int &windowHeight)
   *  \brief Creates a main menu graphic implementation pfollowing its parameter
   *  \param windowWidth the width of the window where the main menu is
   *  displayed in pixel 
   *  \param windowHeight the height of the window where the
   * main menu is displayed in pixel
   */
  MainMenuGI(int &windowWidth, int &windowHeight)
      : title("DYSTOPIA", titleFont, itemsHeight), 
      width(windowWidth),
        newGameButton(
        std::make_pair<int,int> (width/2-width/8, itemsHeight*3),
        width/4,
        itemsHeight,
        localization::newGameButtonText,
        1),
      quitButton(
          std::make_pair<int,int> (width/2-width/8,itemsHeight*5),
          width/4,
          itemsHeight,
          localization::quitButtonText,
          0) 
    {

    Background.loadFromFile(IMGS_DIR"mainMenuBackground.jpg");
    titleFont.loadFromFile(FONTS_DIR"insomnia.ttf"); 

    s_bg.setTexture(Background);
    s_bg.setScale(1, 1);

    title.setFont(titleFont);
    title.setFillColor(sf::Color::Black);
    title.setPosition(width / 2 - title.getGlobalBounds().width / 2, 40);
  }

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(s_bg);
    target.draw(title);
    for(ButtonGI b : buttons )
      target.draw(b);
  }

  /*! \fn std::shared_ptr<Clickable> getClickedOn(std::pair<int,int>mouse) const
   *  \brief Returns a pointer to the item clicked on
   *  \param mouse the xy coordinates of the click
   *  \return a pointer to the clickable object clicked on
   */
  
  std::shared_ptr<Clickable> getClickedOn(std::pair<int,int>mouse) const{
    
    std::shared_ptr<ButtonGI> tmp;

    for (ButtonGI b : buttons)
      if (b.isUnder(mouse)) {
        tmp = std::make_shared<ButtonGI>(b);
        break;
      }
    return tmp;

  }


private:
  sf::Texture Background;
  sf::Sprite s_bg;
  sf::Font titleFont;
  sf::Text title;
  int width;

  ButtonGI newGameButton;
  ButtonGI quitButton;

  std::array<ButtonGI,2> buttons = {newGameButton,quitButton};
};
#endif