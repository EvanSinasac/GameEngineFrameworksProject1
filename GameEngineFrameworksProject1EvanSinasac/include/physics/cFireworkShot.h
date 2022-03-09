#pragma once

#include <physics/cCannonShot.h>

namespace nPhysics
{
	class cFireworkShot : public cCannonShot
	{
	private:
		float timeAlive;
		float timeToDie;
		int stage;
	public:
		cFireworkShot(float mass, const glm::vec3& position, int nStage, float nTimeToDie);
		virtual ~cFireworkShot();

		virtual void Integrate(float deltaTime);

	};
}