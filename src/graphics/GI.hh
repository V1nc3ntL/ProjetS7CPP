/*! \file GI.hh
 *  \brief An interface to ease polymorphism on graphical interfaces
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 21/01/20
 */
#ifndef __GRAPHIC_IMP_HH__
#define __GRAPHIC_IMP_HH__
    Class usrInterface {
        std::shared_ptr<Clickable> getClickedOn(std::pair<int,int>mouse) const ;

    }

#endif