/*! \file unitGI.cc
 *  \brief A graphical interface to dysplay units 
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/25
 */
 
#include "unitGI.hh"
     
#include MAP_GI_H  
   
#include <iostream>
       
        
        UnitGI::UnitGI(Unit & unit,MapGI & map  ):
        theUnit(unit)
        {
            TileGI gi;

             if (unitTexture[unit.getType()].loadFromFile(IMGS_DIR+spriteTab[unit.getType()]))
                sprit.setTexture(unitTexture[unit.getType()]);
            
            sprit.setPosition(map.getTileAt(unit.getPos()).leftAngle().first
            +map.getSquareSize()-
            sprit.getGlobalBounds().width/2-MARGIN,
            map.getTileAt(unit.getPos()).leftAngle().second - 
            sprit.getGlobalBounds().height);
        }
