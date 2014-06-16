#ifndef PHYSICAL_CALCULATOR_HPP
#define PHYSICAL_CALCULATOR_HPP

class btDiscreteDynamicsWorld;

class MyPhysicalCalculator {

private:
    // Private constructor (singleton)
    MyPhysicalCalculator(void);

    // Thread
    void run(void);

public:

    // Class Methods
    static MyPhysicalCalculator& getIntance(void);

    // Methods
    virtual ~MyPhysicalCalculator(void);

    btDiscreteDynamicsWorld* getWorld(void);
    double getTime(void);

    void start(void);

    void pause(void);
    void resume(void);

private:
    struct PrivateData;
    PrivateData* _data;
};

    /////////////////////////////////////////////////////////////////////
    // TODO : Remove
    /////////////////////////////////////////////////////////////////////

#include <btBulletDynamicsCommon.h>
#include <QVector>

#include "printable_mobile_object.hpp"
#include "world.hpp"

    class PhysicalCalculator {
    public:
        const QVector<const PrintableMobileObject*>& getObjectsList();
    public:
        void empty_scene();

        void simple_scene(btScalar size);

        World& getScene();

        void simple_scene_walls(btScalar size);

    public:
        void nextStep(double time=1/80.f, int addedoperations=20);

    public:
        unsigned long int getTime() const;

        PhysicalCalculator();
        ~PhysicalCalculator();


    private:
        //! \brief The init method set the gravity
        void init();

        //! \brief it adds a box in the world
        btRigidBody* addBox( btVector3 size, btVector3 position, btScalar mass);

        btDiscreteDynamicsWorld* _scene;
        World _world;
        btBroadphaseInterface* _broadphase;
        btDefaultCollisionConfiguration* _collisionConfiguration;
        btCollisionDispatcher* _dispatcher;
        btSequentialImpulseConstraintSolver* _solver;
        btClock * _clock;
    };



#endif
