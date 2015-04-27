/*
 @author: Martin Jesper Low Madsen (s124320)
 @author: Mark Seidenschnur (s114740)
 @author: Christian Kjaer Laustsen (s124324)
 
 T29: Shooting Teleporter
 
 This floor tile registers when the sphere is upon it, and after a set time it
 teleports the sphere (changes its position coordinates) to a fixed point on 
 the playground. It also adds a speed boost to the sphere.
 
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
T29::T29(ISceneManager* smgr, IVideoDriver* driver, int x, int y, playground pg): Floor(smgr, driver, x, y, pg) {
    // Change the texture of the tile to a different one than the default
    texture = driver->getTexture(texturepath + "st-oxydd.png");
    block->setMaterialTexture(0, texture);
    // Prepare an alternate texture for when the sphere is touching the field
    altTexture = driver->getTexture(texturepath + "st-blue-sand.png");
    // Count the time the sphere has spent on the field. This is to create
    // a small delay before it teleports, which makes for a nicer experience,
    // and allows the user to notice the a texture change on the field.
    timeSpentOnField = 0.f;
    // The speed increase the sphere gets after being teleported
    speedIncrease = 30.f;
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
    // Change the texture
    block->setMaterialTexture(0, texture);
};


/**
 * Count the time the sphere is touching the floor field, and if enough,
 * teleport the sphere by changing its coordinates to a fixed point on the
 * playground. Furthermore, a small velocity boost is added to the sphere.
 *
 * @param Sphere      the sphere object that has entered the floor tile
 * @param position2di the position of the mouse
 * @param f32         the delta time
 */
void T29::handleSphere(Sphere &sphere, position2di mousemove, f32 frameDeltaTime) {
    timeSpentOnField += frameDeltaTime;
    // Allow just enough time before activating, so the player sees the texture
    // change on the field
    if (timeSpentOnField > 0.1f) {
        // Reset the counter
        timeSpentOnField = 0.f;
        // Alter the momentum, so that the sphere gets a little boost
        vector3df velocity = sphere.getVelocity();
        if (velocity.X < 0.f) {
            velocity.X -= speedIncrease;
        } else {
            velocity.X += speedIncrease;
        }
        if (velocity.Z < 0.f) {
            velocity.Z -= speedIncrease;
        } else {
            velocity.Z += speedIncrease;
        }
        // Set the position coordinates to the bottom left
        vector3df position = sphere.getPosition();
        position.X = 84.0;
        position.Z = 28.0;

        sphere.setVelocity(velocity);
        sphere.setPosition(position);
    }
    // Continue the progress of the sphere, using the standard method
    sphere.standardSphereProgress(mousemove, frameDeltaTime, stdfriction);
};


/**
 * @return the unique field type for field T29
 */
fieldtype T29::getFieldType(){
    return tT29;
};

