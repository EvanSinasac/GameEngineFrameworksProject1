#include <physics/cCannonShotFactory.h>

#include <physics/cBullet.h>
#include <physics/cLaser.h>
#include <physics/cCannonBall.h>
#include <physics/cEnergyBall.h>
#include <physics/cFireworkShot.h>

#include <iostream>

using namespace nPhysics;

cCannonShotFactory::cCannonShotFactory()
{

}

cCannonShotFactory::~cCannonShotFactory()
{

}


cCannonShot* cCannonShotFactory::makeThisCannonShot(std::string shotToMake,
	glm::vec3 position,
	glm::vec3 velocity,
	cConfigReaderJSON* config,
	std::string modelName)
{
	cCannonShot* shot;
	glm::vec3 colour = glm::vec3(1.0f);
	float scale = 7.0f;

	//I guess this is more of a factory "builder" than an abstract factory
	if (shotToMake == "Bullet")
	{
		//cBullet* shotB;
		//From config: size, damping, mass, velocity (magnitude)
		//shotB = new nPhysics::cBullet(config->GetBulletMass(), position);					//config.GetBulletMass()
		//shotB->SetVelocity(velocity);
		//shotB->SetDamping(config->GetBulletDamping());												//config.GetBulletDamping()
		//shotB->SetAcceleration(glm::vec3(0.0f, -9.8f, 0.0f));		//acceleration could get replaced
		//shotB->SetType(1);
		//colour = glm::vec3(1.0f, 0.0f, 1.0f);						//colour could get replaced
		//scale = config->GetBulletSize();											//config.GetBulletSize();
		//
		shot = new cBullet(config->GetBulletMass(), position);
		shot->SetVelocity(velocity);
		shot->SetDamping(config->GetBulletDamping());												//config.GetBulletDamping()
		shot->SetAcceleration(glm::vec3(0.0f, -9.8f, 0.0f));		//acceleration could get replaced
		shot->SetType(1);
		colour = glm::vec3(1.0f, 0.0f, 1.0f);						//colour could get replaced
		scale = config->GetBulletSize();

		shot->makeMesh(modelName, position, scale, colour);

		return shot;
	}
	else if (shotToMake == "Cannon Ball")
	{
		//cCannonBall* shotCB;
		//From config: size, damping, mass, velocity (magnitude)
		shot = new cCannonBall(config->GetCannonBallMass(), position);
		shot->SetVelocity(velocity);
		shot->SetDamping(config->GetCannonBallDamping());
		shot->SetAcceleration(glm::vec3(0.0f, -9.8f, 0.0f));	//acceleration could get replaced
		shot->SetType(3);
		colour = glm::vec3(0.6f, 0.8f, 1.0f);					//colour could get replaced
		scale = config->GetCannonBallSize();

		shot->makeMesh(modelName, position, scale, colour);

		return shot;
	}
	else if (shotToMake == "Laser")
	{
		//cLaser* shotL;
		//From config: size, damping, mass, velocity (magnitude), and distance until death
		shot = new cLaser(config->GetLaserMass(), position);
		shot->SetVelocity(velocity);
		shot->SetDamping(config->GetLaserDamping());
		shot->SetAcceleration(glm::vec3(0.0f, -3.2f, 0.0f));	//acceleration could get replaced
		((cLaser*)shot)->SetDistanceToDeath(config->GetLaserDistanceLimit());
		((cLaser*)shot)->SetCannonPosition(config->GetCannonPosition());
		shot->SetType(2);
		colour = glm::vec3(0.0f, 1.0f, 0.3f);					//colour could get replaced
		scale = config->GetLaserSize();

		shot->makeMesh(modelName, position, scale, colour);
		
		return shot;
	}
	else if (shotToMake == "Energy Ball")
	{
		//cEnergyBall* shotEB;
		//From config: size, damping, mass, velocity (magnitude), time limit and distance limit
		shot = new cEnergyBall(config->GetEnergyBallMass(), position);
		shot->SetVelocity(velocity);
		shot->SetDamping(config->GetEnergyBallDamping());
		shot->SetAcceleration(glm::normalize(velocity) * 2.0f);			//Energy ball accelerates in the same direction it's fired, maybe replace magnitude of acceleration or just use velocity
		((cEnergyBall*)shot)->SetDistanceToDeath(config->GetEnergyBallDistanceLimit());
		((cEnergyBall*)shot)->SetTimeToDie(config->GetEnergyBallTimeLimit());
		((cEnergyBall*)shot)->SetCannonPosition(config->GetCannonPosition());
		shot->SetType(4);
		colour = glm::vec3(1.0f, 0.4f, 0.0f);								//colour could get replaced
		scale = config->GetEnergyBallSize();;

		shot->makeMesh(modelName, position, scale, colour);
		
		return shot;
	}
	else if (shotToMake == "Firework")
	{
		shot = new cFireworkShot(1.0f, position, 1, 5.0f);
		shot->SetVelocity(velocity);
		shot->SetDamping(0.99);
		shot->SetAcceleration(glm::vec3(0.0f, -3.2f, 0.0f));
		shot->SetType(5);
		colour = glm::vec3(1.0f, 0.0f, 0.0f);
		scale = 10.0f;

		shot->makeMesh(modelName, position, scale, colour);

		return shot;
	}
	else
	{
		return nullptr;
	}
}

cCannonShotFactory* cCannonShotFactory::getFactory()
{
	if (cCannonShotFactory::m_pTHECannonShotFactory == NULL)
	{
		cCannonShotFactory::m_pTHECannonShotFactory = new cCannonShotFactory();
	}
	return m_pTHECannonShotFactory;
}

cCannonShotFactory* cCannonShotFactory::m_pTHECannonShotFactory = NULL;