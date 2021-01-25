/*! \file unitGI.hh
 *  \brief A graphical interface to dysplay units 
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/25
 */

#ifndef __UNITGI_HH__
#define __UNITGI_HH__
#include <string>
#include "../app/headersLocation.hh"
#include <SFML/Graphics.hpp>
#include UNIT_H
#include MAP_GI_H

#define N_UNIT_TEXTURE 2
static std::string spriteTab[N_UNIT_TEXTURE] = {
    "badRobot1.png",
    "badRobot2.png"
};

static sf::Texture unitTexture[N_UNIT_TEXTURE];
    
    class UnitGI : public sf::Drawable{
    public :

        /*! \fn 
         *  \brief Creates a graphical implementation of an unit on a map
         *
         *  \param unit the unit to display
         *  \param map the map to display the unit on
         */
        
    UnitGI(Unit & unit,MapGI & map  );

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
        target.draw(sprit);
    };
        private :
            Unit theUnit;
            sf::Sprite sprit;
    };

#endif