#include "cat.h"
#include <stdio.h>
#include <iostream>

bool cat::init()
{
    string cam_path = "res/image/meoa.png";
    if (saved_path == cam_path)
    {
        posCat.getPos(75, SCREEN_HEIGHT / 2 - 10);
        ahead = 0;
        angle = 0;
    }
    if (isNULL() || saved_path != cam_path)
    {
        saved_path = cam_path;
        if ( Load(cam_path.c_str() , 1) )
        {
            return true;
        }
        else
        {
            return false;
        }

    }
    return false;
}

void cat::Free()
{
    free();
}

void cat::render()
{
    Render(posCat.x, posCat.y, angle);
}

void cat::fall()
{
    if (die && posCat.y < SCREEN_HEIGHT - LAND_HEIGHT - CAM_HEIGHT - 5)
    {
        if (time == 0)
        {
            x0 = posCat.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posCat.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }
    }
    else return;
}

void cat::update(short int pipeWidth, short int pipeHeight)
{
    if (!die)
    {
        if (time == 0)
        {
            x0 = posCat.y;
            angle = -25;
        }
        else if (angle < 70 && time > 30)
        {
            angle += 3;
        }

        if (time >= 0)
        {
            posCat.y = x0 + time * time * 0.18 - 7.3 * time;
            time++;
        }

        if ( (posCat.x + getWidth() > posPipe[ahead].x + 5) && (posCat.x + 5 < posPipe[ahead].x + pipeWidth) &&
             (posCat.y + 5 < posPipe[ahead].y + pipeHeight || posCat.y  + getHeight() > posPipe[ahead].y + pipeHeight + PIPE_SPACE + 5) )
        {
            die = true;
        }
        else if (posCat.x > posPipe[ahead].x + pipeWidth )
        {
            ahead = ( ahead + 1 ) % TOTAL_PIPE;
            score++;
        }

        if (posCat.y > SCREEN_HEIGHT - LAND_HEIGHT -  CAM_HEIGHT - 5 || posCat.y < - 10 )
        {
            die = true;
        }
    }
}

