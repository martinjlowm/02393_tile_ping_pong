/*
 @author: Martin Jesper Low Madsen (s124320)
 @author: Mark Seidenschnur (s114740)
 @author: Christian Kjaer Laustsen (s124324)
 
 T29: Tile of Doom
 
 This tile...
 
 */
#include "game.h"
#include "field.h"
#include "T29.h"


T29::T29(ISceneManager* smgr, IVideoDriver* driver, int x, int y, playground pg): Floor(smgr,driver,x,y,pg) {
    // Change the texture of the tile to a different one than the default
    texture = driver->getTexture(texturepath + "st-oxydd.png");
    block->setMaterialTexture(0, texture);
    
    alt_texture = driver->getTexture(texturepath + "st-blue-sand.png");
};


/**
 * Alter the texture of the tile to an alternate one, when a sphere 
 * is touching it.
 *
 * @param Sphere the sphere object that has entered the floor tile
 */
void T29::sphereEnter(Sphere &s) {
    block->setMaterialTexture(0, alt_texture);
};


/**
 * Change the texture back to the original one, when the sphere is
 * no longer touching the floor tile.
 *
 * @param Sphere the sphere object that has entered the floor tile
 */
void T29::sphereExit(Sphere &s) {
    block->setMaterialTexture(0, texture);
}


/**
 * Act upon the sphere, changing its coordinates.
 *
 * @param Sphere      the sphere object that has entered the floor tile
 * @param position2di the position of the mouse
 * @param f32         the delta time
 */
void T29::handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime) {
    s.standardSphereProgress(mousemove, frameDeltaTime, stdfriction);
};


/**
 * @return the unique field type for field T29
 */
fieldtype T29::getFieldType(){
    return tT29;
};
