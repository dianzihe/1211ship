#pragma once

#include "base.h"
#include "MapSettingCfg.h"
#include "BusPathSeeker.h"


class Map;
class ConfigChecking;
struct MapObject
{
	friend class Map;
	friend class ConfigChecking;

	int type;
	int id; 
	int x;
	int y;
	vector<int> params;	
private:
	string name;
public:
	string GetName();
};

struct DanamicMapObject: public MapObject
{
	int virtualID;
};

struct TransportData : public MapObject
{
	TransportData(MapObject &obj);

	int getDestMapId();

	CCPoint getPos();

	int getLevelLimit();
};


struct MapData
{
	int id;
	//地图上的怪物与NPC
	vector<MapObject> objects;
	vector<DanamicMapObject> dynamic_objects;//地图中动态的object ，目前就战场用到
	//地图上的传送点
	vector<TransportData> transport;
	//寻路站台数据
	BUS_STATIONS busStations;
	//寻路站点最大ID
	int	iMaxStationId;
	//地图物理层
	char* phyData;
	//资源名
	string  resName;
	//像素宽
	int  widthInPixel;
	//格子宽
	int  widthInTile;
	//物理层宽
	int  widthInPhy;
	//像素高
	int  heightInPixel;
	//格子高
	int  heightInTile;
	//物理层高
	int  heightInPhy;
	string name;//地图名字

	void loadData( const MapSettingData* pMapSettingData );

	MapData()
	{
		phyData=NULL;
	}


	~MapData()
	{
		SAFE_DELETE_ARRAY(phyData);
	}
};

struct ObjectPos
{
	int mapID;
	int posX;
	int posY;

	ObjectPos()
	{
		mapID = 0;
		posX = 0;
		posY = 0;
	}
};

class MapCfg
{
private:
	MapCfg();
public:
	~MapCfg();

	static MapCfg& instance( void )
	{
		static MapCfg	s;
		return s;
	}

	bool	init( map<int, MapSettingData> *pMapSetting );

	const MapData *getMapCfgData(int dataId)
	{
		map<int, MapData*>::iterator it = m_mapCfgTable.find(dataId);
		if( it == m_mapCfgTable.end() )
			return NULL;
		return it->second;
	}

	const ObjectPos *getNpcPosByID(int dataID)
	{
		map<int, ObjectPos*>::iterator it = m_objNpcPosTable.find(dataID);
		if(it == m_objNpcPosTable.end())
			return NULL;
		return it->second;
	}

	const ObjectPos *getPilePosByID(int dataID)
	{
		map<int, ObjectPos*>::iterator it = m_objPilePosTable.find(dataID);
		if(it == m_objPilePosTable.end())
			return NULL;
		return it->second;
	}
	
private:
	map<int, MapData*>  m_mapCfgTable;
	map<int, ObjectPos*> m_objNpcPosTable;	//npc位置表
	map<int, ObjectPos*> m_objPilePosTable;	//桩桩位置表
};