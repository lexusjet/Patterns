#pragma once

#include <vector>


#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
class Comand;
class ProcessKBHit;
//====================================================

class SBomber
{
public:

    SBomber();
    ~SBomber();

    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

    friend class ProcessKBHit;
private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;

    Ground* FindGround() const;
    Plane* FindPlane() const;

    LevelGUI* FindLevelGUI() const;

    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;


    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;


};
/*������ ��� ������� ����� �������� ��������� �� ��������� ������ � ������ �� �������, ������ ��� ���� �������.
        ��� ������� ������� ����� ����������, ����������� ��������� �� ������ Plane(�� ���� ������� ����� ����� ���������� ��������),

        ������ �� ������ ������������ �������� ��������(��� �������� ������������� ������� Bomb) � ����������� ������ �� ���������� ���� � ��������(���������� ��������� ���� �������� � ������� SBomber).
        ����� ���������� ��� �������� ������� � ������(������) ������� �� ������ � ��� �������� � ������� ������� ����� ������ �����, ������� ����� ������� ������ � ��������� ������� ����.

        ���������������� �� ���� ��� ������� ����� ��� �������� ��������� � �������.
        ���� ����������� ��������� ����� - �� ������� ������ ������ SBomber, �� ����� ����������� ��������� ��� �������, �������� �� ���������(SetParams) � ���������� � ������� - ������.
        ��, � ���� �������, ����� �������� ��� ���� ������� ����������� ����� Execute � ������� � �� ������.
        */

//====================================================

    class Comand {
    public:
        virtual void Execute() = 0;
        void SetObject() {}
    };

//====================================================

    class DeleteDynamicObj : public Comand
    {
        std::vector<DynamicObject*>& game_objects;
        DynamicObject* object;
    public:
        DeleteDynamicObj(std::vector<DynamicObject*>& objects, DynamicObject* obj) : game_objects(objects), object(obj) {};
        ~DeleteDynamicObj() {};

        void Execute() override;
    };

//====================================================

    class DeleteStaticObj : public Comand {
    protected:
        std::vector<GameObject*>& game_objects;
        GameObject* object;
    public:
        DeleteStaticObj(std::vector<GameObject*>& objects, GameObject* obj) : game_objects(objects), object(obj) {};
        ~DeleteStaticObj() {};
        void Execute() override;


    };

//====================================================

    class DropBomb : public Comand {
        Plane* plane;
        std::vector<DynamicObject*>& objects;
        uint16_t& bombsNumber;
        int16_t& score;
    public:
        DropBomb(Plane* plan, std::vector<DynamicObject*>& obj, uint16_t& bombsNum, int16_t& scr) : plane(plan), objects(obj), bombsNumber(bombsNum), score(scr) {};
        ~DropBomb() {};
        void Execute() override;
    };

//===============================================================

    class ProcessKBHit: public Comand {
        SBomber* sbomber;
    public:
        ProcessKBHit(SBomber* s) : sbomber(s) {};
        void Execute() override;

    };
    
//===============================================================

   class Invoker {
        protected:
            Comand* comand;
        public:
            Invoker() : comand(nullptr) {};
            Invoker(Comand* comnd) : comand(comnd) {};
            ~Invoker() { delete comand; };

            void SetComand(Comand* comnd) { comand = comnd; };
            void ExecuteComand() { comand->Execute(); }
    };

//===============================================================
   
   
