/*! \file application.hh
 *  \brief Class representing the application
 *  \author Karim El-Kharroubi --- Vincent LEFEBVRE
 *  \version 0.1
 *  \date 16/12/2020
 */

#ifndef __APPLICATION_HH__
#define __APPLICATION_HH__

#include "headersLocation.hh"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include GAME_H
#include USR_INTERFACE_H
#include APP_STATES_H
#include ACTIONS_H
class Application {
    public:
        Application(sf::RenderWindow & window );
        void run() ;
        void treatKeyPressed(sf::Event & event);
    private:
        sf::RenderWindow& window;

        std::unique_ptr<usrInterface> currentUI;

                    // An int to store the return code of a clickable object
        int rtCode = actions::NOTHING,
        // An int to know in which state the application currently is
        currentState = MAIN_MENU;

        std::unique_ptr<Game> curGame;
        std::shared_ptr<Clickable> clicked ;
};

#endif