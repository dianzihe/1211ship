#include "NpcCfg.h"
#include "BinTable.h"

NpcCfg::NpcCfg()
{
	init( "npc" );
}

NpcCfg::~NpcCfg()
{
}


bool	NpcCfg::init( const char* pFile )
{
	if( pFile == NULL )
		return false;
	m_mapNpcCfgTable.clear(); 

	TTableGroup group;
	group.Load(pFile);

	TTable* pTable =  group.GetTable( "npc" );
	if( !pTable )
		return false;

	for( int i=1; i<=pTable->m_recordCount; ++i )
	{

		NpcData data;
		data.id = pTable->GetField(i, "id");
		data.name = pTable->GetFieldString(i, "name");
		data.type = pTable->GetFieldString(i, "type");
		data.animation = pTable->GetField(i, "animation");
		data.icon = pTable->GetField(i, "npcico");
		data.commonTalk = pTable->GetFieldString(i, "commonTalk");
		data.collectTime = pTable->GetField(i, "collectTime");
		data.cdTime = pTable->GetField(i, "cdTime");
		data.head = pTable->GetField(i, "ncphead");
		data.shopId = pTable->GetField(i, "shopid");
		data.title = pTable->GetFieldString(i, "title");
		m_mapNpcCfgTable[data.id] = data;
	}
	return true;
}