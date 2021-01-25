
#ifndef HEROS_H
#define HEROS_H

#include "Personnage.h"


/**
  * class Heros
  * Classe abstraite pour les h�ros.
  */

/******************************* Abstract Class ****************************
Heros does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Heros : virtual public Unit
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Heros();

  /**
   * Empty Destructor
   */
  virtual ~Heros();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //

protected:
  // Static Protected attributes
  //  

  // Protected attributes
  //  

  // Attaque sp�ciale de l'h�ros.
  int attaqueSpeciale;

  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //  


  /**
   * Set the value of attaqueSpeciale
   * Attaque sp�ciale de l'h�ros.
   * @param value the new value of attaqueSpeciale
   */
  void setAttaqueSpeciale(int value)
  {
    attaqueSpeciale = value;
  }

  /**
   * Get the value of attaqueSpeciale
   * Attaque sp�ciale de l'h�ros.
   * @return the value of attaqueSpeciale
   */
  int getAttaqueSpeciale()
  {
    return attaqueSpeciale;
  }

private:
  // Static Private attributes
  //  

  // Private attributes
  //  


  // Private attribute accessor methods
  //  


  // Private attribute accessor methods
  //  


  void initAttributes();

};

#endif // HEROS_H
