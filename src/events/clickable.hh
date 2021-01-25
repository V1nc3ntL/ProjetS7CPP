/*! \file clickable.hh
 *  \brief The interface for clickable graphics
 *  \author Vincent Lefebvre 
 *  \version 0.1
 *  \date 20/12/28
 */

#ifndef __CLICKABLE_HH__
#define __CLICKABLE_HH__


class Clickable {
    
    public:
    /*! \fn virtual int leftClickAction()=0
     *  \brief The action triggered by a left click button
     *  \return code an int that the main application translates
     */
    
    virtual int  leftClickAction()=0;

    /*! \fn  virtual int rightClickAction()=0
     *  \brief The action triggered by a right click button
     *  \return code an int that the main application translates
     */
    virtual int  rightClickAction()=0;   
};
#endif