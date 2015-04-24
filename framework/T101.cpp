// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T101.h"

//////////////////////////////

T101::
T101(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T101::getFieldType(){ 
  return tT101; 
}
