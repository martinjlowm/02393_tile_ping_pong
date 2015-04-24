/*
 @author: Martin Jesper Low Madsen (s124320)
 @author: Mark Seidenschnur (s114740)
 @author: Christian Kjaer Laustsen (s124324)
 
 T29: Tile of Doom
 
 This tile...
 
 */
#ifndef ____TT29____
#define ____TT29____

#include "game.h"
#include "field.h"


class T29: public Floor {
    protected:
        // Alternate texture, for when the sphere is touching the floor tile
        ITexture *alt_texture;
    public:
        T29(ISceneManager* smgr, IVideoDriver* driver, int x, int y, playground pg);
    
        virtual void sphereEnter(Sphere &s);
        virtual void sphereExit(Sphere &s);
        virtual void handleSphere(Sphere &s, position2di mousemove, f32 frameDeltaTime);
        virtual fieldtype getFieldType();
};


#endif
