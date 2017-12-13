#include "ObjectCfg.h"

#include "BinTable.h"
//#include "Text.h"
//#include "TextDef.h"


ObjectCfg::ObjectCfg()
{
	init( "object" );
}

ObjectCfg::~ObjectCfg()
{

}

bool ObjectCfg::init( const char* pszItemCfgName )
{
	if( !pszItemCfgName )
	{
		//ERROR_LOG( "ObjectCfg::init false pszItemCfgName=NULL" );
		return false;
	}

	TTableGroup  group;
	group.Load(pszItemCfgName);
	TTable* tableItem =  group.GetTable("object");

	if( !tableItem )
	{
		//ERROR_LOG( "ObjectCfg::init false GetTable pszItemCfgName[%s]", pszItemCfgName );
		return false;
	}

	for( int i = 0; i < tableItem->m_recordCount; ++i )
	{
		int nRecordIndex = i + 1;
		ObjectData stItemData;
		stItemData.m_name = tableItem->GetFieldString( nRecordIndex, "name" );

		stItemData.m_icon = tableItem->GetField( nRecordIndex, "icon" );

		stItemData.m_nID = tableItem->GetField( nRecordIndex, "id" );
		stItemData.m_nType = tableItem->GetField( nRecordIndex, "type" );
		stItemData.m_animation = tableItem->GetField( nRecordIndex, "animation" );
		stItemData.m_nParam1 = tableItem->GetField(nRecordIndex, "param1");
		stItemData.m_nParam2 = tableItem->GetField(nRecordIndex, "param2");
		stItemData.m_nParam3 = tableItem->GetField(nRecordIndex, "param3");
		stItemData.m_nParam4 = tableItem->GetField(nRecordIndex, "param4");

		if( findObjectDataByID(stItemData.m_nID) )
		{
			//ERROR_LOG( "ObjectCfg::init false exist id[%d] pszItemCfgName[%s]", stItemData.m_nID, pszItemCfgName );
			continue;
		}

		m_itemDatas[stItemData.m_nID] = stItemData;
	}

	return true;
}