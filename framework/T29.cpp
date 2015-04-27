/*
  @author: Martin Jesper Low Madsen (s124320)
  @author: Mark Seidenschnur (s114740)
  @author: Christian Kjaer Laustsen (s124324)

  T29: Shooting Teleporter

  This floor tile registers when the sphere is upon it, energizes over
  time and once the sphere exits the tile it teleports and multiplies
  its velocity by an energizing factor (speedIncrease). A teleport
  destination can be introduced in field.lvl, but falls back to (84,
  28) if it isn't set.

*/
#include "game.h"
#include "field.h"
#include "T29.h"


/**
 * Initialize the floor tile object and set parameters.
 *
 * @param smgr   the scene manager
 * @param driver interface to the video driver
 * @param x      the x-coordinate for the tile
 * @param y      the y-coordinate for the tile
 * @param pg     a two-dimensional array of pointers to fields
 */
T29::T29(ISceneManager* smgr, IVideoDriver* driver, int x, int y,
         playground pg) : Floor(smgr, driver, x, y, pg) {
  // Change the texture of the tile to a different one than the default
  texture = driver->getTexture(texturepath + "st-oxydd.png");
  block->setMaterialTexture(0, texture);
  // Prepare an alternate texture for when the sphere is touching the field
  altTexture = driver->getTexture(texturepath + "st-blue-sand.png");
  // Count the time the sphere has spent on the field. This is to create
  // a small delay before it teleports, which makes for a nicer experience,
  // and allows the user to notice the a texture change on the field.
  timeSpentOnField = 0.f;
  // The speed multiplication factor the sphere gets after being
  // teleported.
  speedIncrease = 1.f;

  // Use the field.lvl to set a target teleport destination.
  targetField = 0;
};


/**
 * Alter the texture of the tile to an alternate one, when a sphere
 * is touching it.
 *
 * @param Sphere the sphere object that has entered the floor tile
 */
void T29::sphereEnter(Sphere &sphere) {
  // Change the texture
  block->setMaterialTexture(0, altTexture);
};


/**
 * Change the texture back to the original one, when the sphere is
 * no longer touching the floor tile.
 *
 * @param Sphere the sphere object that has entered the floor tile
 */
void T29::sphereExit(Sphere &sphere) {
  // Change the texture.
  block->setMaterialTexture(0, texture);

  // Allow just enough time before activating, so the player sees the
  // texture change on the field.
  if (timeSpentOnField > 0.05f) {
    // Set the position coordinates to an introduced field or to the
    // bottom left if such doesn't exist.
    vector3df position = sphere.getPosition();
    if (targetField) {
      position.X = targetField->getx() * fieldsize;
      position.Z = targetField->gety() * fieldsize;
    } else {
      position.X = 84.0;
      position.Z = 28.0;
    }

    sphere.setVelocity(sphere.getVelocity() * speedIncrease);
    sphere.setPosition(position);
  }

  timeSpentOnField = 0.f;
  speedIncrease = 1.f;
};


/**
 * Count the time the sphere is touching the floor field and increase
 * the speed factor.
 *
 * @param Sphere      the sphere object that has entered the floor tile
 * @param position2di the position of the mouse
 * @param f32         the delta time
 */
void T29::handleSphere(Sphere &sphere, position2di mousemove, f32 frameDeltaTime) {
  timeSpentOnField += frameDeltaTime;

  // Increase the speed factor while the sphere is on the field.
  if (speedIncrease <= 25.f) {
    speedIncrease += 0.05f;
  }

  // Continue the progress of the sphere, using the standard method
  sphere.standardSphereProgress(mousemove, frameDeltaTime, stdfriction);
};


/**
 * @return the unique field type for field T29
 */
fieldtype T29::getFieldType() {
  return tT29;
};


/**
 * Store the teleport destination field.
 */
void T29::introduceTo(Field &f) {
  if (!targetField) {
    targetField = &f;
  }
};
