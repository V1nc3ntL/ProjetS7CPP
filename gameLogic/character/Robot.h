
#ifndef ROBOT_H
#define ROBOT_H

#include "Personnage.h"


/**
  * class Robot
  * Classe abstraite pour les ennemis robots.
  */

/******************************* Abstract Class ****************************
Robot does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Robot : virtual public Personnage
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Robot();

  /**
   * Empty Destructor
   */
  virtual ~Robot();

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

  // Défense spéciale du robot.
  void defenseSpeciale;

  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //  


  /**
   * Set the value of defenseSpeciale
   * Défense spéciale du robot.
   * @param value the new value of defenseSpeciale
   */
  void setDefenseSpeciale(void value)
  {
    defenseSpeciale = value;
  }

  /**
   * Get the value of defenseSpeciale
   * Défense spéciale du robot.
   * @return the value of defenseSpeciale
   */
  void getDefenseSpeciale()
  {
    return defenseSpeciale;
  }


  /**
   * Fonction Defense qui permet au robot de recuperer des points vie pour lui-meme
   * et/ou pour un allie.
   * @param  cible Réference de la cible à qui augmenter la vie.
   */
  void Defense(Robot& cible)
  {
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

#endif // ROBOT_H
