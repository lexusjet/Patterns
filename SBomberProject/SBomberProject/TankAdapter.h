#pragma once
#include "DestroyableGroundObject.h"
#include "TankAdaptee.h"

class TankAdapter :
    public DestroyableGroundObject
{
protected:
    TankAdaptee tank;
public :
    TankAdapter():tank() {};

    void Draw() const override { tank.Paint(); };
    bool __fastcall isInside(double x1, double x2) const override { return tank.isInRange(x1, x2); };

    inline void SetPos(double nx, double ny) { tank.SetPos(nx, ny);};

    inline double GetY() const { return tank.GetY(); };
    inline double GetX() const { return tank.GetX(); };

    inline void SetWidth(uint16_t widthN) { tank.SetWidth(width); };
    inline uint16_t GetWidth() const { return tank.GetWidth(); };

    inline uint16_t GetScore() const override { return tank.GetScore(); }
    
};

