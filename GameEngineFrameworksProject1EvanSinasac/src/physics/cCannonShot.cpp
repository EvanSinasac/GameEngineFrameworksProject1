//Evan Sinasac - 1081418
//INFO6019 Physics and Simulation and INFO6025 Configuration and Deployment Midterm
//cCannonShot.cpp description:
//						The cpp file for the cCannonShot class, with the actual functions and integration.
//						I also finally figured out how to actually inherit from cParticle with this lol

#include <physics/cCannonShot.h>
#include <iostream>

namespace nPhysics
{
	cCannonShot::cCannonShot(float mass, const glm::vec3& position) : cParticle(mass, position)
	{
		this->m_pMesh = NULL;
	}
	cCannonShot::~cCannonShot()
	{

	}

	void cCannonShot::Integrate(float deltaTime)
	{

	}

	void cCannonShot::SetIsAlive(bool newIsAlive)
	{
		this->isAlive = newIsAlive;
	}
	bool cCannonShot::GetIsAlive()
	{
		return this->isAlive;
	}

	void cCannonShot::SetType(int newType)
	{
		this->type = newType;
	}
	int cCannonShot::GetType()
	{
		return this->type;
	}

	cMesh* cCannonShot::makeMesh(std::string modelName, glm::vec3 position, float scale, glm::vec3 colour)
	{
		this->m_pMesh = new cMesh;
		this->m_pMesh->meshName = modelName;
		this->m_pMesh->positionXYZ = position;
		this->m_pMesh->bOverrideColour = true;
		this->m_pMesh->vertexColourOverride = colour;
		this->m_pMesh->bIsWireframe = true;
		this->m_pMesh->scale = scale;

		return this->m_pMesh;
	}

	void cCannonShot::updateMeshPosition(glm::vec3 newPos)
	{
		this->m_pMesh->positionXYZ = newPos;
	}
	cMesh* cCannonShot::getMesh()
	{
		return this->m_pMesh;
	}

}

