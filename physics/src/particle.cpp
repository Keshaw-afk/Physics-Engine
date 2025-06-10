#include <cyclone/particle.h> 
#include <assert.h> 

using namespace cyclone;

void Particle::integrate(real duration)
{
    assert(duration > 0.0);

    // p = p + vt;
    position.addScaledVector(velocity, duration);

    //forceAccum is the accumulation of forces on object which will increase the resulting
    //accelaration vector
    Vector3 resultingAcc = accelaration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    velocity.addScaledVector(resultingAcc, duration);

    //impose damping, v = v0 * d^t;
    velocity *= real_pow(damping, duration);
}


