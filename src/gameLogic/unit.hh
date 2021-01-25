/*! \file unit.hh
 *  \brief The interface for the playable units
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/25
 */
#include <iostream>
#include <sstream>  

#ifndef __UNIT_HH__
#define __UNIT_HH__


    class Unit{
        public :

            Unit(std::string name,int maxHP,int type,std::pair<int,int> pos) : maxHP(maxHP),hP(maxHP),
            type(type),name(name),pos(pos) {

            }
            Unit* operator-(const int& b) {  
                this->hP -= b;
                if(hP<=0)
                    delete this;
                return this;
            }

            std::pair<int,int> getPos()const{return pos;}

            int getType()const{return type;}

            std::string toString()const{
                std::stringstream oss;
                oss << " \n\t" << name << "HP:" << hP << '/' << maxHP ;
                return oss.str();
            }
        private :
            int maxHP;
            int hP;
            int type;
            std::string name; 
            std::pair<int,int> pos;
    };
#endif