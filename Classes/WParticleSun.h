//
//  WParticleSun.h
//  dandandao
//
//  Created by haotao on 12-3-18.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#ifndef dandandao_WParticleSun_h
#define dandandao_WParticleSun_h

#include "cocos2d.h"
using namespace cocos2d;

//#include "typedefine.h"


//! @brief A sun particle system
class  WParticleSun : public ParticleSystemQuad
//class  WParticleSun : public ParticleSystemPoint
{
public:
	WParticleSun(){}
	virtual ~WParticleSun(){}
	bool init(){ return initWithTotalParticles(60); }
	virtual bool initWithTotalParticles(unsigned int numberOfParticles);
	static WParticleSun * node()
	{
		WParticleSun *pRet = new WParticleSun();
		if (pRet->init()){
			pRet->autorelease();
			return pRet;
		}
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
};


#endif
