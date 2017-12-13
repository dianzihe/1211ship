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
	//��ͼ�ϵĹ�����NPC
	vector<MapObject> objects;
	vector<DanamicMapObject> dynamic_objects;//��ͼ�ж�̬��object ��Ŀǰ��ս���õ�
	//��ͼ�ϵĴ��͵�
	vector<TransportData> transport;
	//Ѱ·վ̨����
	BUS_STATIONS busStations;
	//Ѱ·վ�����ID
	int	iMaxStationId;
	//��ͼ�����
	char* phyData;
	//��Դ��
	string  resName;
	//���ؿ�
	int  widthInPixel;
	//���ӿ�
	int  widthInTile;
	//������
	int  widthInPhy;
	//���ظ�
	int  heightInPixel;
	//���Ӹ�
	int  heightInTile;
	//������
	int  heightInPhy;
	string name;//��ͼ����

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
	map<int, ObjectPos*> m_objNpcPosTable;	//npcλ�ñ�
	map<int, ObjectPos*> m_objPilePosTable;	//׮׮λ�ñ�
};