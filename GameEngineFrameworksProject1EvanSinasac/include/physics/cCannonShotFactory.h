#pragma once

#include <physics/cCannonShot.h>
#include <string>

#include "../../src/cConfigReaderJSON.h"

namespace nPhysics
{
	class cCannonShotFactory
	{
	private:
		static cCannonShotFactory* m_pTHECannonShotFactory;

	public:
		cCannonShotFactory();
		~cCannonShotFactory();

		cCannonShot* makeThisCannonShot(std::string shotToMake, 
			glm::vec3 position, 
			glm::vec3 velocity,
			cConfigReaderJSON* config,
			std::string modelName);

		static cCannonShotFactory* getFactory(void);
	};
}