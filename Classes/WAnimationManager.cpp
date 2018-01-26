//
//  WAnimationManager.cpp
//  dandandao
//
//  Created by haotao on 12-2-9.
//  Copyright (c) 2012Äê __MyCompanyName__. All rights reserved.
//


#include "WAnimationManager.h"


const char WanimationFileNameList[][32]=
{
    WANI_IWCO_BATTLEBOY,  
    WANI_IWCO_BATTLEGIRL,    
    WANI_IWCO_BATTLEEFFECT,
    WANI_IWCO_BATTLEEFFICIENTS,
    WANI_IWCO_SHOPEFFICIENTS,
    WANI_IWCO_SHOPBOY,
    WANI_IWCO_SHOPGIRL, 
    WANI_IWCO_ISLAND,    
    WANI_IWCO_BATTLEFACE,  
    WANI_IWCO_TEACH,
    WANI_IWCO_NEWTEACH,
    WANI_IWCO_BOSS,
    WANI_IWCO_MONSTER1,
    WANI_IWCO_MONSTER2,
    WANI_IWCO_BOSS21,
    WANI_IWCO_BOSS22,
    WANI_IWCO_MONSTER3,
    WANI_IWCO_EGG,
    WANI_IWCO_STRENGTHEN,
    WANI_IWCO_WING,
    WANI_IWCO_MONSTEREFFICIENTS, 
    WANI_IWCO_BOSS31,
    WANI_IWCO_BOSS32,
    WANI_IWCO_BOSS4
};

const char WanimationFileNameListInloading[][32]=
{
   
    WANI_IWCO_BATTLEEFFICIENTS,
    WANI_IWCO_NEWTEACH,
    WANI_IWCO_MONSTER2,
};




void WAnimationManager::BuildIWcoManagerList()
{
    

    int count=sizeof(WanimationFileNameList)/sizeof(WanimationFileNameList[0]);
    
    for(int i=0; i<count; i++)
    {
        cwSngAnimationPool::sharedAnimationPool()->loadIWCO("gameResources/sng_animation/", WanimationFileNameList[i]);
   }
        

}

void WAnimationManager::BuildIWcoManagerListInLoading()
{
    
    
    int count=sizeof(WanimationFileNameListInloading)/sizeof(WanimationFileNameListInloading[0]);
    
    for(int i=0; i<count; i++)
    {
        cwSngAnimationPool::sharedAnimationPool()->loadIWCO("gameResources/sng_animation/", WanimationFileNameListInloading[i]);
    }
    
    
}



