#pragma once

#include "base.h"
#include <string>
#include <map>
struct NpcData
{
	int id;						//id
	std::string name;				//
	std::string type;				//type
	int animation;			//¶¯»­ID
	int icon;					//
	std::string commonTalk;	//
	int collectTime;			//
	int cdTime;				//
	int head;					//
	int shopId;				//
	std::string title;			//³ÆÎ½

};

class NpcCfg
{
private:
	NpcCfg();
public:
	~NpcCfg();

	static NpcCfg& instance( void )
	{
		static NpcCfg	s;
		return s;
	}

	bool	init( const char* pFile );

	const map<int, NpcData> &getNpcCfgTable(){ return m_mapNpcCfgTable;};

	const NpcData *getNpcCfgData( int id )
	{
		map<int, NpcData>::iterator it = m_mapNpcCfgTable.find(id);
		if( it == m_mapNpcCfgTable.end() )
			return NULL;
		return &it->second;
	}

private:
	map<int, NpcData>  m_mapNpcCfgTable;
};