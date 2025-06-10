#include <cyclone/particle.h> 
#include <assert.h> 

using namespace cyclone;

void Particle::setInverseMass(const real inverseMass)
        {
            this->inverseMass = inverseMass;
            this->mass = ((real)1) / inverseMass;
        }

void Particle::setMass(const real mass)
{
    this->inverseMass = ((real)1) / mass;
    this->mass = mass;
}

real Particle::getMass() const
{
    return mass;
}

real Particle::getInverseMass() const
{
    return inverseMass;
}

bool Particle::hasFiniteMass() const
{
    if (inverseMass > 0)
        return true;
    else
        return false;
}

Vector3 Particle::getVelocity() const
{
    return velocity;
}

void Particle::getVelocity(Vector3* velocity) const
{
    *velocity = Particle::velocity;
}

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

    clearAccumulator();
}

void Particle::clearAccumulator()
{
        forceAccum.clear();
}

void Particle::addForce(const Vector3& force)
{
    forceAccum += force;
}


