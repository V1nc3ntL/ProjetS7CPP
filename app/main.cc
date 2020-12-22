/*! \file main.cc
 *  \brief File containing the main
 *  \author Vincent Lefebvre Karim El-Kharroubi
 *  \version 0.1
 *  \date 16/12/2020
 */

/*! \mainpage Projet S7 C++ EL-KHARROUBI LEFEBVRE
 *
 * \section intro_sec Introduction
 *
 * Dans le monde d'après, les humains ont disparu,
 * les conditions climatiques extrêmes et 
 * la disparition de l'eau empêchant leur survie.
 * Néanmoins, les robots ont continué de travailler.
 * 
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Faire quelquechose
 * \subsection step2 Step 2: Faire autrechose
 * 
 */


 /*! \fn main
  *  \brief The functin from which it all begins
  *! \return int true or false depending on the execution
  */
 
#include "headersLocation.hh"
#include <SFML/Graphics.hpp>

#include <iostream>
#include MAP_H

#define TILE_OUTLINE_THICKNESS -5

int main(void){

sf::RenderWindow window(
		sf::VideoMode(
			sf::VideoMode::getDesktopMode().height
			,sf::VideoMode::getDesktopMode().width), 
            "Projet S7");
    
    
    sf::VertexArray shape(sf::Quads,4);
    
    shape[0].position =  sf::Vector2f(10, 10);
    shape[1].position =  sf::Vector2f(10, 50);
    shape[2].position =  sf::Vector2f(50, 50);
    shape[3].position =  sf::Vector2f(50, 10);
    /*

    shape.setFillColor(sf::Color::Black);

    shape.setOutlineThickness(TILE_OUTLINE_THICKNESS);
    shape.setOutlineColor(sf::Color::White);
*/
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
