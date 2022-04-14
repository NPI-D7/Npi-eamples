#include "global.hpp"

Npi::Color clearcl(122, 145, 255); 
Npi::Cube cube(1, 1, 1);
Npi::Texture tex;
int main(int argc, char*argv[])
{
    Npi::Game cubegame;
    Npi::Renderer enre(true);
    Npi::Camera &cam = enre.getCamera(Npi::RenderContext::ScreenTarget::Top);
    tex.loadFromFile("romfs:/dirt.png");
    cube.bindTexture(tex);
    while (cubegame.IsRunning())
    {
        hidScanInput();
      
        u32 d7_hDown = hidKeysDown();
        u32 d7_hHeld = hidKeysHeld();
        if(d7_hHeld & KEY_CSTICK_DOWN) 
        {
            cam.rotatePitch(1);
            if (90 < cam.getPitch())
                cam.setPitch(90);
        }
        if(d7_hHeld & KEY_CSTICK_UP) 
        {
            cam.rotatePitch(-1);
            if(-90 > cam.getPitch())
                cam.setPitch(-90);
        }
        if(d7_hHeld & KEY_CSTICK_RIGHT) cam.rotateYaw(1);
        if(d7_hHeld & KEY_CSTICK_LEFT) cam.rotateYaw(-1);
        

        if(d7_hDown & KEY_START)break;
        if(d7_hHeld & KEY_CPAD_DOWN) {
            float dirX = std::sin(cam.getYaw(true)) * 0.03;
            float dirZ = -std::cos(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }
        if(d7_hHeld & KEY_CPAD_UP) {
            float dirX = -std::sin(cam.getYaw(true)) * 0.03;
            float dirZ = std::cos(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }
        if(d7_hHeld & KEY_CPAD_RIGHT) {
            float dirX = -std::cos(cam.getYaw(true)) * 0.03;
            float dirZ = -std::sin(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }
        if(d7_hHeld & KEY_CPAD_LEFT) {
            float dirX = std::cos(cam.getYaw(true)) * 0.03;
            float dirZ = std::sin(cam.getYaw(true)) * 0.03;
            cam.moveX(dirX);
            cam.moveZ(dirZ);
        }
        cube.rotatePitch(1);
        cube.rotateRoll(1);
        cube.rotateYaw(1);
        enre.drawTop(cube, Npi::RenderContext::Mode::_3D);
        enre.setClearColor(clearcl);
        enre.Render(true);
    }
    
    return 0;
}