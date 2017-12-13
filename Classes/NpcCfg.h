#pragma once

#include "base.h"

struct NpcData
{
	int id;						//id
	string name;				//
	string type;				//type
	int animation;			//¶¯»­ID
	int icon;					//
	string commonTalk;	//
	int collectTime;			//
	int cdTime;				//
	int head;					//
	int shopId;				//
	string title;			//³ÆÎ½

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