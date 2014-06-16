#include "physical_calculator.hpp"

#include <btBulletDynamicsCommon.h>

#include <boost/bind.hpp>
#include <boost/thread.hpp>

////////////////////////////////////////////////////////////////////////////////
// Private Data
////////////////////////////////////////////////////////////////////////////////

struct MyPhysicalCalculator::PrivateData {
    btDiscreteDynamicsWorld*             _world;
    btBroadphaseInterface*               _broadphase;
    btDefaultCollisionConfiguration*     _collision_configuration;
    btCollisionDispatcher*               _dispatcher;
    btSequentialImpulseConstraintSolver* _solver;
    btClock*                             _clock;

    bool                                 _running;
    bool                                 _keep_going;
    boost::thread*                       _thread;
};

////////////////////////////////////////////////////////////////////////////////
// Class Methods
////////////////////////////////////////////////////////////////////////////////

MyPhysicalCalculator& MyPhysicalCalculator::getIntance(void) {
    static MyPhysicalCalculator _physical_calculator;
    return _physical_calculator;
}

////////////////////////////////////////////////////////////////////////////////
// Methods
////////////////////////////////////////////////////////////////////////////////

MyPhysicalCalculator::MyPhysicalCalculator(void) {
    _data = new PrivateData;

    _data->_running    = false;
    _data->_keep_going = true;

    _data->_clock = new btClock;

    _data->_broadphase              = new btDbvtBroadphase;
    _data->_collision_configuration = new btDefaultCollisionConfiguration;
    _data->_solver                  = new btSequentialImpulseConstraintSolver;

    // Create collision dipatcher
    _data->_dispatcher =
            new btCollisionDispatcher(
                _data->_collision_configuration
                );

    // Create scene
    _data->_world =
            new btDiscreteDynamicsWorld(
                _data->_dispatcher,
                _data->_broadphase,
                _data->_solver,
                _data->_collision_configuration
                );

    // Create thread
    _data->_thread =
            new boost::thread(
                boost::bind(&MyPhysicalCalculator::run, this)
                );
}

MyPhysicalCalculator::~MyPhysicalCalculator(void) {
    delete _data->_world;
    delete _data->_dispatcher;
    delete _data->_solver;
    delete _data->_collision_configuration;
    delete _data->_broadphase;

    delete _data->_clock;

    _data->_keep_going = false;
    _data->_thread->join();

    delete _data->_thread;

    delete _data;
}

btDiscreteDynamicsWorld* MyPhysicalCalculator::getWorld(void) {
    return _data->_world;
}

double MyPhysicalCalculator::getTime(void) {
    return _data->_clock->getTimeMicroseconds() * 0.001;
}

void MyPhysicalCalculator::start(void) {
    if(!_data->_running) {
        _data->_world->setGravity(btVector3(0,9.0,0));
        _data->_running = true;
    }
}

void MyPhysicalCalculator::pause(void) {
    _data->_running = false;
}

void MyPhysicalCalculator::resume(void) {
    _data->_running = true;
}

void MyPhysicalCalculator::run(void) {
    while(_data->_keep_going) {
        if(_data->_running) {
            _data->_world->stepSimulation(1.0/60.0, 20);

            // Sleep
            boost::this_thread::sleep_for(
                        boost::chrono::duration<double>(1.0/60.0)
                        );
        }
    }
}

/////////////////////////////////////////////////////////////////////
// TODO : Remove
/////////////////////////////////////////////////////////////////////

//#define WALL_HEIGHT 3

//PhysicalCalculator::PhysicalCalculator()
//    : _world(NULL) {
//    _broadphase = new btDbvtBroadphase();
//    _collisionConfiguration = new btDefaultCollisionConfiguration();
//    _dispatcher = new btCollisionDispatcher(_collisionConfiguration);
//    _solver = new btSequentialImpulseConstraintSolver;

//    _scene = new btDiscreteDynamicsWorld(_dispatcher,_broadphase,_solver,_collisionConfiguration);
//    _world = World(_scene);
//    Mesh::setWorld(_world);

//    btContactSolverInfo& info = _scene->getSolverInfo();
//    info.m_numIterations = 20;
//    _clock= new btClock();
//    init();
//}

//PhysicalCalculator::~PhysicalCalculator(){
//    delete _scene;
//    delete _clock;
//    delete _solver;
//    delete _dispatcher;
//    delete _collisionConfiguration;
//    delete _broadphase;
//}

//btRigidBody* PhysicalCalculator::addBox(btVector3 size, btVector3 position, btScalar mass){
//    btDiscreteDynamicsWorld * myscene=getScene();
//    btCollisionShape* boxShape = new btBoxShape(size);
//    btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),position));
//    btVector3 boxInertial(0,0,0);
//    boxShape->calculateLocalInertia(mass, boxInertial);
//    btRigidBody::btRigidBodyConstructionInfo boxBodyCI(mass, boxMotionState, boxShape, boxInertial);
//    btRigidBody* newbox = new btRigidBody(boxBodyCI);
//    myscene->addRigidBody(newbox);
//    return newbox;
//}

//void PhysicalCalculator::empty_scene(){
//    this->init();
//}

//World& PhysicalCalculator::getScene(){
//    return _world;
//}

//void PhysicalCalculator::simple_scene(btScalar size){
//    this->init();
//    btCollisionShape *planeShape;

//    planeShape = new btBoxShape(btVector3(size,1,size));


//    //No movement for the ground
//    btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1), btVector3(0,-1,0)));

//    btRigidBody::btRigidBodyConstructionInfo groundBodyCI(0, groundMotionState, planeShape, btVector3(0,0,0));

//    btRigidBody* groundBody = new btRigidBody(groundBodyCI);
//    _scene->addRigidBody(groundBody);
//}


//void PhysicalCalculator::simple_scene_walls(btScalar size){
//    simple_scene(size);
//    addBox(btVector3(size,WALL_HEIGHT,2),btVector3(0,WALL_HEIGHT,size+2),0);
//    addBox(btVector3(2,WALL_HEIGHT,size),btVector3(size+2,WALL_HEIGHT,0),0);
//    addBox(btVector3(size,WALL_HEIGHT,2),btVector3(0,WALL_HEIGHT,-size-2),0);
//    addBox(btVector3(2,WALL_HEIGHT,size),btVector3(-size-2,WALL_HEIGHT,0),0);

//}

//void PhysicalCalculator::nextStep(double time, int addedoperations){
//    _scene->stepSimulation(time,addedoperations);
//}

//unsigned long int PhysicalCalculator::getTime() const{
//    return _clock->getTimeMilliseconds();
//}

//void PhysicalCalculator::init() {
//    _scene->setGravity(btVector3(0,-10,0));

//}

//const QVector<const PrintableMobileObject*>& PhysicalCalculator::getObjectsList() {
//    //return PrintableMobileObject::getObjectsList();
//}
