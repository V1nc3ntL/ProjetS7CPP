
#ifndef PERSONNAGE_H
#define PERSONNAGE_H


/**
  * class Personnage
  * Classe abstraite Personnage. Les différentes sous classes pour chaque personnage
  * vont hériter de cette classe.
  */

/******************************* Abstract Class ****************************
Personnage does not have any pure virtual methods, but its author
  defined it as an abstract class, so you should not use it directly.
  Inherit from it instead and create only objects from the derived classes
*****************************************************************************/

class Personnage
{
public:
  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Personnage();

  /**
   * Empty Destructor
   */
  virtual ~Personnage();

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

  // Nombre entier qui caractérise la vie restante du personnage.
  int vie;
  // Attaque du personnage.
  int attaque;

  // Protected attribute accessor methods
  //  


  // Protected attribute accessor methods
  //  


  /**
   * Set the value of vie
   * Nombre entier qui caractérise la vie restante du personnage.
   * @param value the new value of vie
   */
  void setVie(int value)
  {
    vie = value;
  }

  /**
   * Get the value of vie
   * Nombre entier qui caractérise la vie restante du personnage.
   * @return the value of vie
   */
  int getVie()
  {
    return vie;
  }

  /**
   * Set the value of attaque
   * Attaque du personnage.
   * @param value the new value of attaque
   */
  void setAttaque(int value)
  {
    attaque = value;
  }

  /**
   * Get the value of attaque
   * Attaque du personnage.
   * @return the value of attaque
   */
  int getAttaque()
  {
    return attaque;
  }


  /**
   * Fonction attaque du Personnage.
   * @param  cible On passe en paramètre la réference de la cible à attaquer.
   */
  void attaque(Personnage& cible)
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

#endif // PERSONNAGE_H
