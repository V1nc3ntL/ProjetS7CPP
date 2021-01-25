/*! \file main.cc
 *  \brief File containing the main
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 16/12/2020
 */

#include <iostream>
#include <vector>

#include "application.hh"

 /*! \fn main
  *  \brief The functin from which it all begins
  *! \return int true or false depending on the execution
  */
int main(void){

    // Get screen size
    int curW = 	    sf::VideoMode::getDesktopMode().width,
    curH = 	    sf::VideoMode::getDesktopMode().height;

    // Creates a window  
    sf::RenderWindow window(sf::VideoMode( curW, curH, sf::Style::Fullscreen)
         , "DYSTOPIA");

  Application app(window);
  app.run();
      
  return 0;
}
