//
//  WParticleSun.cpp
//  dandandao
//
//  Created by haotao on 12-3-18.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include "WParticleSun.h"
//#include "../battle_base/WBUtil.h"
//#include "ddd_global.h"
//#include "WMusic.h"


bool WParticleSun::initWithTotalParticles(unsigned int numberOfParticles)
{
	if (ParticleSystemQuad::initWithTotalParticles(numberOfParticles))
	{
		// additive
		//this->setIsBlendAdditive(true);
        
		// duration
		//m_fDuration = kCCParticleDurationInfinity;
        
		// Gravity Mode
		//m_nEmitterMode = kCCParticleModeGravity;
        
		// Gravity Mode: gravity
		modeA.gravity = ccp(0,0);
        
		// Gravity mode: radial acceleration
		modeA.radialAccel = 0;
		modeA.radialAccelVar = 0;
        
		// Gravity mode: speed of particles
		modeA.speed = 20;
		modeA.speedVar = 5;
        
        
		// angle
		//m_fAngle = 90;
		//m_fAngleVar = 360;
        
		// emitter position
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		this->setPosition(ccp(winSize.width/2, winSize.height/2));
		//m_tPosVar = CCPointZero;
        
		// life of particles
		//m_fLife = 1;
		//m_fLifeVar = 0.5f;
        
		// size, in pixels
		//m_fStartSize = 30.0f;
		//m_fStartSizeVar = 10.0f;
		//m_fEndSize = kCCParticleStartSizeEqualToEndSize;
        
		// emits per seconds
		//m_fEmissionRate = m_uTotalParticles/m_fLife;
        
		/*
		// color of particles
		m_tStartColor.r = 0.76f;
		m_tStartColor.g =0.25f;
		m_tStartColor.b =0.12f;
		m_tStartColor.a = 1.0f;
		m_tStartColorVar.r = 0.0f;
		m_tStartColorVar.g = 0.0f;
		m_tStartColorVar.b = 0.0f;
		m_tStartColorVar.a = 0.0f;
		m_tEndColor.r = 0.0f;
		m_tEndColor.g = 0.0f;
		m_tEndColor.b = 0.0f;
		m_tEndColor.a = 1.0f;
		m_tEndColorVar.r = 0.0f;
		m_tEndColorVar.g = 0.0f;
		m_tEndColorVar.b = 0.0f;
		m_tEndColorVar.a = 0.0f;
        */
		return true;
	}
	return false;
}


