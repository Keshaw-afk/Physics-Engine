#include "core.h"

namespace cyclone
{

    class Particle
    {

        public:

        Vector3 position;

        Vector3 velocity;

        Vector3 accelaration;

        real damping; // This factor purely exists to balance out numerical instability in the integrator, ideally velocity of object shouldn't 
                      // change when their are no forces involved but since the computer will perform inaccurate calculations, objects can become
                      // faster on their own accord
        
        protected:
        real inverseMass;
        real mass;

        public:
        void setInverseMass(const real inverseMass);

        void setMass(const real mass);

        real getMass() const;

        real getInverseMass() const;

        bool hasFiniteMass() const;

        Vector3 getVelocity() const;

        void getVelocity(Vector3* velocity) const;


        void integrate(real duration);

        Vector3 forceAccum; //Stores force

        void clearAccumulator(); //Zeroes all the forces

        void addForce(const Vector3& force);
     
    };

}
