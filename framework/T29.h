/*
  @author: Martin Jesper Low Madsen (s124320)
  @author: Mark Seidenschnur (s114740)
  @author: Christian Kjaer Laustsen (s124324)

  T29: Shooting Teleporter

  This floor tile registers when the sphere is upon it, and after a set time it
  teleports the sphere (changes its position coordinates) to a fixed point on
  the playground. It also adds a speed boost to the sphere.

*/
#ifndef ____TT29____
#define ____TT29____

#include "game.h"
#include "field.h"


class T29 : public Floor {
 protected:
  // Alternate texture, for when the sphere is touching the floor field
  ITexture *altTexture;
  // A counter for the time the sphere has been on the field
  f32 timeSpentOnField;
  // Amount of velocity added to the sphere after being teleported
  f32 speedIncrease;
  // Teleport destination at some field.
  Field *targetField;

 public:
  T29(ISceneManager* smgr, IVideoDriver* driver, int x, int y, playground pg);

  void introduceTo(Field &f);
  void sphereEnter(Sphere &s);
  void sphereExit(Sphere &s);
  void handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime);
  fieldtype getFieldType();
}


#endif
