// Skeleton of implementation file for groups

#include "game.h"
#include "field.h"
#include "T35.h"

//////////////////////////////

T35::
T35(ISceneManager* smgr,
	 IVideoDriver* driver,
	 int x, int y, playground pg) 
  : Wall(smgr,driver,x,y,pg)
    // calling the parent constructor 
    // (if you implement a Floor Field, replace "Wall" with "Floor")
{
} ;

fieldtype T35::getFieldType(){ 
  return tT35; 
}
