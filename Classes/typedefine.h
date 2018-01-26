

/**
*   完成一些经常使用的宏定义
*
*/


#ifndef  __wyd_typedefine_include__
#define __wyd_typedefine_include__ 

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
//#include "common.h"

using namespace cocos2d;
using namespace CocosDenshion;

//#include "Box2D.h"
using namespace std;

///////////////////////////////////////////
#define USE_UNKOWN_SDK 0
#define USE_WYD_SDK 1001
#define USE_91SDK 1025
#define USE_JY_SDK 1007
#define USE_UC_SDK 1003
#define USE_DJ_SDK 1002
#define USE_IFREE_KT_SDK 1036
#define USE_EF_SDK 1035
#define USE_IFREE_SK_SDK 1038
#define USE_IFREE_GOOGLE_PAY_SDK 1037
#define USE_IFREE_IOS_SDK  1054
#define USE_EGAME_SDK 1016
#define USE_MOBILE_SDK 1017
#define USE_360_SDK 1018
#define USE_91IOS_SDK	1004
#define USE_EFUN_IOS_SDK 1055
#define USE_WYD_GOOGLE_PAY_SDK 1056
#define USE_Mi_SDK     1049
#define USE_MP_SDK      1034
#define USE_KY_SDK      1051
#define USE_FACEBOOK_SDK 1057
#define USE_WYD_IOS_SDK		1053
#define USE_TB_IOS_SDK   1050
#define USE_DDD_IOS_CN 1058
#define USE_DDD_IOS_EN  1059
#define USE_OL_IOS_CN 1060
#define USE_OL_IOS_EN 1061
#define USE_BD_SDK     1064
#define USE_PP_IOS_SDK 1065
#define USE_UNISHOP_SDK 1067
#define USE_IAPPPAY_SDK 1070
#define USE_WANDOUJIA_SDK 1033
#define USE_ANZHI_SDK 1080
#define USE_GFAN_SDK 1005
#define USE_SKYCHEE_SDK 1085
#define USE_LX_SDK 1083

#define USE_OL_IOS_EN 1061
#define USE_UNICOM_SDK 3003
//默认使用友盟
#define USE_UMENG 1


//InMObi_SDK
#define USE_InMObi_SDK 0

//GoogleConversionPing
#define USE_GoogleConversionPing 0

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    #define  USE_Download 0
#else
	#if USE_SDK_TYPE == USE_IFREE_KT_SDK || USE_SDK_TYPE == USE_IFREE_SK_SDK || USE_SDK_TYPE == USE_WANDOUJIA_SDK
		 #define  USE_Download 0	
	#else
		#define  USE_Download 1	
	#endif
#endif

//#if USE_SDK_TYPE == USE_IFREE_KT_SDK || USE_SDK_TYPE == USE_IFREE_SK_SDK
//#define  USE_Download 0
//#endif


#if USE_SDK_TYPE == USE_DDD_IOS_CN ||\
USE_SDK_TYPE == USE_DDD_IOS_EN ||\
USE_SDK_TYPE == USE_WYD_GOOGLE_PAY_SDK

#undef USE_InMObi_SDK
#define USE_InMObi_SDK 1

#undef USE_GoogleConversionPing 
#define USE_GoogleConversionPing 1

#endif

#if USE_SDK_TYPE == USE_IFREE_GOOGLE_PAY_SDK || \
USE_SDK_TYPE == USE_EFUN_IOS_SDK || \
USE_SDK_TYPE == USE_EF_SDK

#undef USE_Download

#define USE_Download 1

#endif

#if USE_SDK_TYPE == USE_TB_IOS_SDK || USE_SDK_TYPE == USE_IFREE_IOS_SDK
#undef USE_UMENG
    #if USE_SDK_TYPE == USE_IFREE_IOS_SDK
        #define USE_UMENG 1
    #else
        #define USE_UMENG 0
    #endif
#endif

#define USE_CPP_SDK 0
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#define USE_THIRD_SDK 0
#else
#define USE_THIRD_SDK 1
#endif
#define USE_ACCOUNT_SYSTEM 0
#define SDK_AUTO_CHECK_UPGRADE 0



#if (USE_WYD_SDK == USE_SDK_TYPE || \
USE_DDD_IOS_CN == USE_SDK_TYPE || \
USE_DDD_IOS_EN == USE_SDK_TYPE || \
USE_OL_IOS_CN == USE_SDK_TYPE || \
USE_OL_IOS_EN == USE_SDK_TYPE || \
USE_UNISHOP_SDK == USE_SDK_TYPE || \
USE_IAPPPAY_SDK == USE_SDK_TYPE || \
USE_LX_SDK == USE_SDK_TYPE || \
USE_ANZHI_SDK == USE_SDK_TYPE || \
USE_SKYCHEE_SDK == USE_SDK_TYPE || \
USE_WYD_IOS_SDK == USE_SDK_TYPE)

#undef USE_ACCOUNT_SYSTEM
#define USE_ACCOUNT_SYSTEM 1
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 0
#endif

#if USE_EGAME_SDK == USE_SDK_TYPE || USE_UNICOM_SDK == USE_SDK_TYPE
#undef USE_ACCOUNT_SYSTEM
#define USE_ACCOUNT_SYSTEM 1
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 0

#endif
#if USE_SDK_TYPE == USE_91IOS_SDK
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 1
#endif
#if USE_SDK_TYPE == USE_TB_IOS_SDK
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 1
#endif

#if (USE_IFREE_KT_SDK == USE_SDK_TYPE || USE_IFREE_SK_SDK == USE_SDK_TYPE ||USE_SDK_TYPE == USE_IFREE_GOOGLE_PAY_SDK )

#define YUNYING_MUHE 1
#define USE_ACCOUNT_SYSTEM 0
//#define USE_TAPJOY 0
#ifdef USE_IFREEPASSPORT
#define OPEN_IFREE_PASSPORT
#endif
#undef OPEN_FOURTH
#undef OPEN_FIFTH

//四期功能宏定义
#define OPEN_FOURTH 0
#define OPEN_FIFTH 0



#else

#undef YUNYING_MUHE 

#endif 

#if USE_SDK_TYPE == USE_IFREE_TAPJOY_SDK
#define USE_TAPJOY 1
#undef USE_ACCOUNT_SYSTEM
#define USE_ACCOUNT_SYSTEM 1
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 0
#undef YUNYING_MUHE
#define YUNYING_MUHE 1
#endif

#if USE_SDK_TYPE == USE_91IOS_SDK || USE_SDK_TYPE == USE_EFUN_IOS_SDK || USE_SDK_TYPE == USE_TB_IOS_SDK || USE_SDK_TYPE == USE_PP_IOS_SDK
    #undef USE_CPP_SDK
    #define USE_CPP_SDK 1
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 1
#endif

#if USE_SDK_TYPE == USE_IFREE_IOS_SDK
#undef USE_THIRD_SDK
#define USE_THIRD_SDK 1
#endif
#if USE_SDK_TYPE == USE_EFUN_IOS_SDK
#undef USE_GoogleConversionPing
#endif
/////////////////////////////////////////////////////////////////
#if USE_THIRD_SDK == 0
	#define USE_SINA_WEIBO 1
#else	
	#if USE_SDK_TYPE == USE_FACEBOOK_SDK
		#define USE_SINA_WEIBO 1
	#endif
#endif

#define OPEN_BOSSMAP 1


#if USE_SDK_TYPE == USE_BD_SDK
#define USE_ACCOUNT_SYSTEM  0
#endif
//////////////////////////////////////////////////////////////////////////
//#undef USE_Download
//
//#define USE_Download 0
//////////////////////////////////////////////////////////////////////////

//强化宏定义
#define OPEN_STRONGLEN 0
//四期功能宏定义
#define OPEN_FOURTH 0
//五期功能宏定义
#define OPEN_FIFTH 0
//六期功能宏定义
#define OPEN_SIXTH 0
//八期功能宏定义
#define OPEN_EIGHTH 0
//九期功能宏定义
#define OPEN_NINTH 0

//副本4宏定义
#define OPEN_BOSS4 0

#define OPEN_NEWTEACH 0
#define OPEN_DEBUGSPEED 0

#define NOT_USE_STENCIL_SPRITE 1


#if (OPEN_FOURTH == 1)
    #define OPEN_CUXIAO 1
    #define OPEN_BOSSMAP_3 1
#else
    #define OPEN_CUXIAO 0
    #define OPEN_BOSSMAP_3 0
#endif

#if (OPEN_FIFTH == 1)
//结婚宏定义
#define OPEN_MARRY 1
//成就宏定义
#define OPEN_ACHIEVEMENT 1
#else
#define OPEN_MARRY 0
#define OPEN_ACHIEVEMENT 0
#endif

//慕和sdk的开关
#ifdef YUNYING_MUHE

#ifdef USE_IFREEPASSPORT
#define OPEN_IFREE_PASSPORT
#endif

#endif

#define WFPS (60)

#define WYD_DEBUG




#define ENCRYPT_KEY "pifnwkjdhn\0"




#define GET_THIS_SCENE_SCALE() \
CCDirector::sharedDirector()->getRunningScene()->getScale()

#define GET_RIGHT_TXT_SIZE(x) \
((x)*(CC_CONTENT_SCALE_FACTOR()==2?1:2))

//#define SET_FIT_THE_SCREAN(pNode) \
//do{ \
//    if(!CCDirector::sharedDirector()->isRetinaDisplay()) \
//    {\
//        pNode->setAnchorPoint(ccp(0,0)); \
//        pNode->setScale(0.5); \
//    } \
//}while(0);

#define DEFAULT_SCR_WIDTH 960.0f
#define DEFAULT_SCR_HEIGHT 640.0f


#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)

#define SET_FIT_THE_SCREAN(pNode) \
do{ \
pNode->setAnchorPoint(ccp(0,0)); \
CCSize size=CCDirector::sharedDirector()->getWinSizeInPixels(); \
float scaleWidth=size.width/DEFAULT_SCR_WIDTH; \
float scale=size.height/DEFAULT_SCR_HEIGHT;\
if(scaleWidth<scale)\
{\
    scale=scaleWidth;\
}\
pNode->setScale(scale); \
pNode->setPositionInPixels(CCPointMake((size.width-DEFAULT_SCR_WIDTH*scale)/2, (size.height-DEFAULT_SCR_HEIGHT*scale)/2)); \
}while(0);

#define GET_EDGE_CUT() (((CCDirector::sharedDirector()->getWinSizeInPixels().height-DEFAULT_SCR_HEIGHT*GET_THIS_SCENE_SCALE())/2)/GET_THIS_SCENE_SCALE())

#define GET_X_EDGE_CUT() (((CCDirector::sharedDirector()->getWinSizeInPixels().width-DEFAULT_SCR_WIDTH*GET_THIS_SCENE_SCALE())/2)/GET_THIS_SCENE_SCALE())

#else ////////////////////////////////////////////////////////////////////

#define SET_FIT_THE_SCREAN(pNode) \
do{ \
pNode->setAnchorPoint(ccp(0,0)); \
CCSize size=CCDirector::sharedDirector()->getWinSizeInPixels(); \
float scaleWidth=size.width/DEFAULT_SCR_WIDTH; \
float scaleHeight=size.height/DEFAULT_SCR_HEIGHT;\
pNode->setScaleX(scaleWidth);\
pNode->setScaleY(scaleHeight);\
}while(0);

#define GET_EDGE_CUT() 0

#define GET_X_EDGE_CUT() 0

#endif

#define WBNODE(class_name)  \
static class_name* node()                   \
{                                           \
    class_name *pRet = new class_name();    \
    if (pRet->init())                               \
    {                                       \
        pRet->autorelease();                \
        return pRet;                        \
    }                                       \
    else                                    \
    {                                       \
        delete pRet;                        \
        pRet = NULL;                        \
    }     \
    return NULL;                            \
} 


#define WDDD_FONT "Helvetica"


/**
 * @brief 错误处理回调函数
 * @param data   发送通告时传过来的数据 @see WNotifyManager::SendNotifyToShow
 * @param msg   点击的了什么类型的按钮 @see WNotifyManager::E_MSG_SHOW_DONE
 * @param param1 留着以后使用
 * @param param2 
 */
typedef void (*pWErrCallBack)(void *data,int msg,int param1,int param2);

/**
 * @brief 处理回调函数
 * @param data   用户数据 
 * @param msg   消息类型
 * @param param1 留着以后使用
 * @param param2 
 */
typedef void (*pWMsgCallback)(void *data,int msg,int param1,int param2);


typedef struct
{
    string notify;
    int notify_show_type;
    pWErrCallBack callback_func;
    void *data;
    
}NOTIFY_MSG;

typedef void (*pWCallBack_Func)(void *data);//回调函数定义


class strtempString:public CCObject
{
    
    
public:
    
    char *m_pstr;
    
    strtempString(const char *str)
    {
        int len = strlen(str);
        m_pstr = new char[len+1];
        memset(m_pstr, 0, len+1);
        memcpy(m_pstr, str, len);
        autorelease();
    }
    
    ~strtempString()
    {
        CC_SAFE_DELETE_ARRAY(m_pstr);
    }
    
    
};

//环境变量定义
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#define RESOURCE_PATH	""
#define DOCUMENT_PATH	"document"
#define CACHE_PATH	"cache"
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#define SYS_PATH_SEPARATOR	'\\'
#else
#define SYS_PATH_SEPARATOR	'/'

#endif

#if( CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

    #ifndef GAMERESOUCEPVR
        #define GAMERESOUCE_PATH "gameResources/"
    #else
        #define GAMERESOUCE_PATH "gameResourcesPVR/"
    #endif

#else
    #define GAMERESOUCE_PATH "gameResources/"
#endif


#ifndef INT32_MAX
#define INT32_MAX	2147483647
#endif

#ifndef INT32_MIN
#define INT32_MIN	(-2147483647 - 1)
#endif


//节点显示优先级
//系统弹出框/网络提示框
#define LAYER_PRIORITY_SYSMSGBOX 128  
//弹出的聊天信息
#define LAYER_PRIORITY_POP_MESSAGE 100
//聊天窗口
#define LAYER_PRIORITY_CHAT 90
//默认优先级 必须小于90
#define LAYER_PRIORITY_DEFAULT 0

//TTLog("TTLog""a %s",a,,);
//#define TTLog(fmt,args...)  CCLog("TTLog file : %s line : %d"fmt,__FILE__,__LINE__,##args)

#endif
