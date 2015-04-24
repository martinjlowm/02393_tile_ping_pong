// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T6.h"

//////////////////////////////

T6::
T6(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T6::getFieldType(){ 
  return tT6; 
}
