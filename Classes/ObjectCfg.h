//////////////////////////////////////////////////////////////////////////
// �������
#pragma once

#include "base.h"
//#include "Singleton.h"
#using namespace std;
struct ObjectData
{
	//	���ID
	int			m_nID;
	//	�������
	string		m_name;
	//	������ͣ��ο�ACTORTYPE
	int			m_nType;
	//	�������ID
	int			m_animation;
	//	���icon
	int		m_icon;
	//	m_ntypeΪ�ɼ���ʱ�������ɼ�ʱ�䣬		m_ntypeΪ���͵�ʱ������
	int			m_nParam1;
	//	m_ntypeΪ�ɼ���ʱ�������ɼ������������	m_ntypeΪ���͵�ʱ������
	int			m_nParam2;
	//	m_ntypeΪ�ɼ���ʱ��������	m_ntypeΪ���͵�ʱ������
	int			m_nParam3;
	//	m_ntypeΪ�ɼ���ʱ��������	m_ntypeΪ���͵�ʱ������
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
