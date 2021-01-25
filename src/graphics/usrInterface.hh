/*! \file usrInterface.hh
 *  \brief An interface to ease polymorphism on graphical interfaces
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/20
 */
#ifndef __USER_INTERFACE_HH__
#define __USER_INTERFACE_HH__

#include "../app/headersLocation.hh"
#include CLICKABLE_H
#include <SFML/Graphics.hpp>

    class usrInterface : public sf::Drawable{
        public:
            virtual std::shared_ptr<Clickable> getClickedOn(std::pair<int,int>mouse) const=0;
            virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const=0;
    };

#endif