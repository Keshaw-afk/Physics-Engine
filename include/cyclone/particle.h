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

        public:
        void setInverseMass(const real inverseMass)
        {
            this->inverseMass = inverseMass;
        }

        void setMass(const real mass)
        {
            this->inverseMass = ((real)1) / mass;
        }

        void integrate(real duration);
     
    };

}
