#include <cyclone/particle.h>
#include <vector>

namespace cyclone
{

    class ParticleForceGenerator
    {
        public:
            virtual void updateForce(Particle* particle, real duration) = 0;

    };
    
    class ParticleForceRegistry
    {
        protected:
            //Keeps track of one force generator and the particle it applies to

            struct ParticleForceRegistration
            {
                Particle* particle;
                ParticleForceGenerator* fg;
            };

            typedef std::vector<ParticleForceRegistration> Registry;
            Registry registrations;

        public:
            // Registers the given force generator to apply to the particle

            void add(Particle* particle, ParticleForceGenerator* fg);

            // Removes the pair of force generator and the particle it was being applied to
            // If no such pair is registered, this method will do nothing

            void remove(Particle* particle, ParticleForceGenerator* fg);

            //Clears all registration from the registry. This will not delete the particles
            //or the force generators themselves but their record;
            void clear();

            void updateForces(real duration);
        
    };
    
    class ParticleGravity : public ParticleForceGenerator
    {
        Vector3 gravity;

        public:
            
            ParticleGravity(const Vector3& gravity);

            virtual void updateForce(Particle* particle, real duration);
    };

    class ParticleDrag : public ParticleForceGenerator
    {
        real k1;

        real k2;

        public:
            
            ParticleDrag(real k1, real k2);

            virtual void updateForce(Particle* particle, real duration);
    };


}
