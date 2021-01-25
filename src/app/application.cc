#include "headersLocation.hh"
#include<memory>
#include "../events/eventTreatment.hh"
#include "application.hh"
#include MAIN_MENU_GI_H


Application::Application(sf::RenderWindow& window):window(window),
    currentUI(std::make_unique<MainMenuGI>(window.getSize().x,window.getSize().y))

{
    
}

/*! \fn int static checkButtonPressed(std::shared_ptr<Clickable> clicked )
 *  \brief Check if a mouse click is on the left or the right button
 *
 *  \param clicked a shared pointer on a clickable object
 *  \return the return code of the clickable object
 */

int static checkButtonPressed(std::shared_ptr<Clickable> clicked ){
            int rt = actions::NOTHING;
            
            if( sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    rt =   clicked->leftClickAction(); 
                    
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
                    rt = clicked->rightClickAction();
                    
            return rt;
}

/*! \fn void static  treatKeyPressed(sf::Event & event,sf::RenderWindow & window )
 *  \brief Check the key pressed
 *
 *  \param event reference on the event triggering the function
 *  \param window reference on the application unique window
 */
void Application::treatKeyPressed(sf::Event & event){
                    switch(event.key.code){
                      case sf::Keyboard::Escape:
                        window.close();
                      default:
                        break;
                    }
}

void Application::run(){
          


    while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
            rtCode = actions::NOTHING;
                switch(event.type){
                    case sf::Event::KeyPressed:
                        this->treatKeyPressed(event);
                    break;    
                    case sf::Event::MouseButtonPressed :
                        clicked = (*currentUI).getClickedOn(
                        std::pair<int,int>(sf::Mouse::getPosition (window).x ,
                        sf::Mouse::getPosition(window).y)
                        );
                        if(clicked)   
                        rtCode = checkButtonPressed(clicked);
                        else
                        rtCode = actions::NOTHING;
                    break;
                    case sf::Event::Closed :
                        window.close();
                    break;
                    default:  
                    break;
                }
            if(rtCode != actions::NOTHING)
            decode(rtCode,window,&currentUI,&currentState,&curGame);
            }
            window.clear();
            window.draw(*currentUI);
            window.display();
        }
}
