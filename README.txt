Evan Sinasac - 1081418
INFO6044 Game Engine Framworks
Project 1

The purpose of this project is to show some clever design decisions in implementing some of the patterns/techniques we've learned in class.  For this, I have modified some of the program I made for the Physics and Configuration midterm, in particular I have added an abstract factory/builder for making the cannon shots (rather than doing it all in the main) which is also a singleton.  (And I think I've done so in a way that it also uses the ideas of PIMPL so that adding any new kinds of cannon shots will only affect a re-build of the factory and the new shot, watch video for more info on that). 

Built and compiled using Visual Studios 2019 in Debug and Release in x64.

CONTROLS
W/A/S/D		- Move the camera around the scene
Q/E		- Move the camera up and down in the scene
Mouse		- Moving the mouse moves the camera's target allowing you to look around
1/2/3/4/5	- Launch different kinds of cannon shots
Arrow Keys	- Change the direction of the cannon

MODELS
Models are loaded from ply files with only vertex coordinates and normals
Models used are our Stanford bunny model and some models from Creepy Cat's 3D Scifi Kit Vol 3 (https://assetstore.unity.com/packages/3d/environments/sci-fi/3d-scifi-kit-vol-3-121447)

GAME ENGINE FRAMEWORKS
Added an abstract factory/builder to seperate the creation of cannon shots.  This factory is also a singleton so there will only ever be one that can be called upon.  Addition of new cannon shots should only affect the factory (and any other class that changes to show the new stuff, such as main so we can launch the new shot).  

CONFIGURATION
Config.json located at PROJECT_DIR/src/ has all the information for the cannon and each type of shot.  cConfigReaderJSON.cpp loads the information and is used to store the values.

PHYSICS
Using the same given cParticleWorld and cParticle for the base.  Implemented a cCannonShot that inherits cParticle and adds variables used for every type of cannon shot.  Then cBullet, cLaser, cCannonBall and cEnergyBall inherit from cCannonShot and implement any additional variables and death conditions for the type of shot.

DEMO VIDEO
https://youtu.be/2tg_pvtMfAc
