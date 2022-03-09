
#include <iostream>
#include <physics/cFireworkShot.h>

namespace nPhysics
{
	cFireworkShot::cFireworkShot(float mass, const glm::vec3& position, int nStage, float nTimeToDie) : cCannonShot(mass, position)
	{
		SetAcceleration(glm::vec3(0.0f, -9.8f, 0.0f));
		SetIsAlive(true);
		stage = nStage;
		timeToDie = nTimeToDie;
		timeAlive = 0.0f;
	}
	cFireworkShot::~cFireworkShot()
	{

	}

	void cFireworkShot::Integrate(float deltaTime)
	{
		if (GetIsAlive())
		{
			if (GetInverseMass() == 0.f)
			{
				return; // static things don't move!
			}

			SetPosition(glm::vec3(GetPosition() + GetVelocity() * deltaTime));
			// F*(1/m) = a
			SetVelocity(glm::vec3(GetVelocity() + (GetAcceleration() / GetInverseMass() * deltaTime)));

			// apply damping
			SetVelocity(glm::vec3(GetVelocity() * glm::pow(GetDamping(), deltaTime)));

			updateMeshPosition(GetPosition());

			timeAlive += deltaTime;

			if (timeAlive >= timeToDie || GetPosition().y <= 0)
			{
				SetIsAlive(false);
			}
		}
	}

}