//////////////////////////////////////////////////////////////////////////
// 物件定义
#pragma once

#include "base.h"
//#include "Singleton.h"
#using namespace std;
struct ObjectData
{
	//	物件ID
	int			m_nID;
	//	物件名字
	string		m_name;
	//	物件类型，参考ACTORTYPE
	int			m_nType;
	//	物件动画ID
	int			m_animation;
	//	物件icon
	int		m_icon;
	//	m_ntype为采集物时，——采集时间，		m_ntype为传送点时，——
	int			m_nParam1;
	//	m_ntype为采集物时，——采集物重生间隔，	m_ntype为传送点时，——
	int			m_nParam2;
	//	m_ntype为采集物时，——，	m_ntype为传送点时，——
	int			m_nParam3;
	//	m_ntype为采集物时，——，	m_ntype为传送点时，——
	int			m_nParam4;
};
typedef std::map< int, ObjectData >	MAP_OBJECTS;


class ObjectCfg //: public Singleton<ObjectCfg, Tag_Singleton_Auto>
{
public:
	ObjectCfg();
	~ObjectCfg();

	static ObjectCfg& instance( void )
	{
		static ObjectCfg	s;
		return s;
	}

	bool					init( const char* pszItemCfgName );

	const ObjectData*		findObjectDataByID( int nID )const
	{
		MAP_OBJECTS::const_iterator iterFind = m_itemDatas.find( nID );
		return iterFind != m_itemDatas.end() ? &(iterFind->second) : NULL;
	}

	MAP_OBJECTS &		getObjectCfgMap(){ return m_itemDatas;};
private:
	MAP_OBJECTS						m_itemDatas;

};
