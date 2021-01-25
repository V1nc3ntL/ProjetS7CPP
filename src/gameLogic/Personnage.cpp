#include "Personnage.h"

// Constructors/Destructors
//  

Personnage::Personnage()
{
  initAttributes();
}

Personnage::~Personnage()
{
}

//  
// Methods
//  


// Accessor methods
//  


// Other methods
//  

void Personnage::initAttributes()
{
  vie = 100;
  attaque = 0;
}

