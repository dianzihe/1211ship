﻿// ---------------------------------------------------------------------
// THIS FILE IS AUTO-GENERATED BY BEHAVIAC DESIGNER, SO PLEASE DON'T MODIFY IT BY YOURSELF!
// ---------------------------------------------------------------------

#ifndef _BEHAVIAC_MEMBER_VISITOR_H_
#define _BEHAVIAC_MEMBER_VISITOR_H_

#include "behaviac_agent_headers.h"

// Agent property and method handlers


struct METHOD_TYPE_PlaneEnemy_applyForce { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_applyForce>(Vec2 p0)
{
	this->PlaneEnemy::applyForce(p0);
}

struct METHOD_TYPE_PlaneEnemy_avoid { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_avoid>()
{
	this->PlaneEnemy::avoid();
}

struct METHOD_TYPE_PlaneEnemy_boundaries { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_boundaries>()
{
	this->PlaneEnemy::boundaries();
}

struct METHOD_TYPE_PlaneEnemy_eat { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_eat>()
{
	this->PlaneEnemy::eat();
}

struct METHOD_TYPE_PlaneEnemy_mate { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_mate>()
{
	this->PlaneEnemy::mate();
}

struct METHOD_TYPE_PlaneEnemy_randomRotate { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_randomRotate>()
{
	this->PlaneEnemy::randomRotate();
}

struct METHOD_TYPE_PlaneEnemy_updatePosition { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_updatePosition>()
{
	this->PlaneEnemy::updatePosition();
}

struct METHOD_TYPE_PlaneEnemy_wander { };
template<> inline void PlaneEnemy::_Execute_Method_<METHOD_TYPE_PlaneEnemy_wander>()
{
	this->PlaneEnemy::wander();
}


#endif // _BEHAVIAC_MEMBER_VISITOR_H_
