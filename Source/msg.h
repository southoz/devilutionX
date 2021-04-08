/**
 * @file msg.h
 *
 * Interface of function for sending and reciving network messages.
 */
#pragma once

namespace devilution {

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push, 1)
typedef struct TCmd {
	Uint8 bCmd;
} TCmd;

typedef struct TCmdLoc {
	Uint8 bCmd;
	Uint8 x;
	Uint8 y;
} TCmdLoc;

typedef struct TCmdLocParam1 {
	Uint8 bCmd;
	Uint8 x;
	Uint8 y;
	Uint16_NET wParam1;
} TCmdLocParam1;

typedef struct TCmdLocParam2 {
	Uint8 bCmd;
	Uint8 x;
	Uint8 y;
	Uint16_NET wParam1;
	Uint16_NET wParam2;
} TCmdLocParam2;

typedef struct TCmdLocParam3 {
	Uint8 bCmd;
	Uint8 x;
	Uint8 y;
	Uint16_NET wParam1;
	Uint16_NET wParam2;
	Uint16_NET wParam3;
} TCmdLocParam3;

typedef struct TCmdParam1 {
	Uint8 bCmd;
	Uint16_NET wParam1;
} TCmdParam1;

typedef struct TCmdParam2 {
	Uint8 bCmd;
	Uint16_NET wParam1;
	Uint16_NET wParam2;
} TCmdParam2;

typedef struct TCmdParam3 {
	Uint8 bCmd;
	Uint16_NET wParam1;
	Uint16_NET wParam2;
	Uint16_NET wParam3;
} TCmdParam3;

typedef struct TCmdGolem {
	Uint8 bCmd;
	Uint8 _mx;
	Uint8 _my;
	Uint8 _mdir;
	Sint8 _menemy;
	Sint32_NET _mhitpoints;
	Uint8 _currlevel;
} TCmdGolem;

typedef struct TCmdQuest {
	Uint8 bCmd;
	Uint8 q;
	Uint8 qstate;
	Uint8 qlog;
	Uint8 qvar1;
} TCmdQuest;

typedef struct TCmdGItem {
	Uint8 bCmd;
	Uint8 bMaster;
	Uint8 bPnum;
	Uint8 bCursitem;
	Uint8 bLevel;
	Uint8 x;
	Uint8 y;
	Uint16_NET wIndx;
	Uint16_NET wCI;
	Sint32_NET dwSeed;
	Uint8 bId;
	Uint8 bDur;
	Uint8 bMDur;
	Uint8 bCh;
	Uint8 bMCh;
	Uint16_NET wValue;
	Uint32_NET dwBuff;
	Sint32_NET dwTime;
	Uint16_NET wToHit;
	Uint16_NET wMaxDam;
	Uint8 bMinStr;
	Uint8 bMinMag;
	Uint8 bMinDex;
	Uint8 bAC;
} TCmdGItem;

typedef struct TCmdPItem {
	Uint8 bCmd;
	Uint8 x;
	Uint8 y;
	Uint16_NET wIndx;
	Uint16_NET wCI;
	Sint32_NET dwSeed;
	Uint8 bId;
	Uint8 bDur;
	Uint8 bMDur;
	Uint8 bCh;
	Uint8 bMCh;
	Uint16_NET wValue;
	Uint32_NET dwBuff;
	Uint16_NET wToHit;
	Uint16_NET wMaxDam;
	Uint8 bMinStr;
	Uint8 bMinMag;
	Uint8 bMinDex;
	Uint8 bAC;
} TCmdPItem;

typedef struct TCmdChItem {
	Uint8 bCmd;
	Uint8 bLoc;
	Uint16_NET wIndx;
	Uint16_NET wCI;
	Sint32_NET dwSeed;
	Uint8 bId;
	Uint32_NET dwBuff;
} TCmdChItem;

typedef struct TCmdDelItem {
	Uint8 bCmd;
	Uint8 bLoc;
} TCmdDelItem;

typedef struct TCmdDamage {
	Uint8 bCmd;
	Uint8 bPlr;
	Uint32_NET dwDam;
} TCmdDamage;

typedef struct TCmdMonDamage {
	Uint8 bCmd;
	Uint16_NET wMon;
	Uint32_NET dwDam;
} TCmdMonDamage;

typedef struct TCmdPlrInfoHdr {
	Uint8 bCmd;
	Uint16_NET wOffset;
	Uint16_NET wBytes;
} TCmdPlrInfoHdr;

typedef struct TCmdString {
	Uint8 bCmd;
	char str[MAX_SEND_STR_LEN];
} TCmdString;

typedef struct TFakeCmdPlr {
	Uint8 bCmd;
	Uint8 bPlr;
} TFakeCmdPlr;

typedef struct TFakeDropPlr {
	Uint8 bCmd;
	Uint8 bPlr;
	Uint32_NET dwReason;
} TFakeDropPlr;

typedef struct TSyncHeader {
	Uint8 bCmd;
	Uint8 bLevel;
	Uint16_NET wLen;
	Uint8 bObjId;
	Uint8 bObjCmd;
	Uint8 bItemI;
	Uint8 bItemX;
	Uint8 bItemY;
	Uint16_NET wItemIndx;
	Uint16_NET wItemCI;
	Uint32_NET dwItemSeed;
	Uint8 bItemId;
	Uint8 bItemDur;
	Uint8 bItemMDur;
	Uint8 bItemCh;
	Uint8 bItemMCh;
	Uint16_NET wItemVal;
	Uint32_NET dwItemBuff;
	Uint8 bPInvLoc;
	Uint16_NET wPInvIndx;
	Uint16_NET wPInvCI;
	Uint32_NET dwPInvSeed;
	Uint8 bPInvId;
	Uint16_NET wToHit;
	Uint16_NET wMaxDam;
	Uint8 bMinStr;
	Uint8 bMinMag;
	Uint8 bMinDex;
	Uint8 bAC;
} TSyncHeader;

typedef struct TSyncMonster {
	Uint8 _mndx;
	Uint8 _mx;
	Uint8 _my;
	Uint8 _menemy;
	Uint8 _mdelta;
} TSyncMonster;

typedef struct TPktHdr {
	Uint8 px;
	Uint8 py;
	Uint8 targx;
	Uint8 targy;
	Sint32_NET php;
	Sint32_NET pmhp;
	Uint8 bstr;
	Uint8 bmag;
	Uint8 bdex;
	Uint16_NET wCheck;
	Uint16_NET wLen;
} TPktHdr;

typedef struct TPkt {
	TPktHdr hdr;
	Uint8 body[493];
} TPkt;

typedef struct DMonsterStr {
	Uint8 _mx;
	Uint8 _my;
	Uint8 _mdir;
	Uint8 _menemy;
	Uint8 _mactive;
	Sint32_NET _mhitpoints;
} DMonsterStr;

typedef struct DObjectStr {
	Uint8 bCmd;
} DObjectStr;

typedef struct DLevel {
	TCmdPItem item[MAXITEMS];
	DObjectStr object[MAXOBJECTS];
	DMonsterStr monster[MAXMONSTERS];
} DLevel;

typedef struct LocalLevel {
	Uint8 automapsv[DMAXX][DMAXY];
} LocalLevel;

typedef struct DPortal {
	Uint8 x;
	Uint8 y;
	Uint8 level;
	Uint8 ltype;
	Uint8 setlvl;
} DPortal;

typedef struct MultiQuests {
	Uint8 qstate;
	Uint8 qlog;
	Uint8 qvar1;
} MultiQuests;

typedef struct DJunk {
	DPortal portal[MAXPORTAL];
	MultiQuests quests[MAXMULTIQUESTS];
} DJunk;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct TMegaPkt {
	struct TMegaPkt *pNext;
	Uint32_NET dwSpaceLeft;
	Uint8 data[32000];
} TMegaPkt;
#pragma pack(pop)

typedef struct TBuffer {
	Uint32 dwNextWriteOffset;
	Uint8 bData[4096];
} TBuffer;

extern BOOL deltaload;
extern BYTE gbBufferMsgs;
extern int dwRecCount;

void msg_send_drop_pkt(int pnum, int reason);
BOOL msg_wait_resync();
void run_delta_info();
void DeltaExportData(int pnum);
void delta_init();
void delta_kill_monster(int mi, BYTE x, BYTE y, BYTE bLevel);
void delta_monster_hp(int mi, int hp, BYTE bLevel);
void delta_sync_monster(const TSyncMonster *pSync, BYTE bLevel);
BOOL delta_portal_inited(int i);
BOOL delta_quest_inited(int i);
void DeltaAddItem(int ii);
void DeltaSaveLevel();
void DeltaLoadLevel();
void NetSendCmd(BOOL bHiPri, BYTE bCmd);
void NetSendCmdGolem(BYTE mx, BYTE my, BYTE dir, BYTE menemy, int hp, BYTE cl);
void NetSendCmdLoc(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void NetSendCmdLocParam1(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1);
void NetSendCmdLocParam2(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2);
void NetSendCmdLocParam3(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2, WORD wParam3);
void NetSendCmdParam1(BOOL bHiPri, BYTE bCmd, WORD wParam1);
void NetSendCmdParam2(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2);
void NetSendCmdParam3(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2, WORD wParam3);
void NetSendCmdQuest(BOOL bHiPri, BYTE q);
void NetSendCmdGItem(BOOL bHiPri, BYTE bCmd, BYTE mast, BYTE pnum, BYTE ii);
void NetSendCmdPItem(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void NetSendCmdChItem(BOOL bHiPri, BYTE bLoc);
void NetSendCmdDelItem(BOOL bHiPri, BYTE bLoc);
void NetSendCmdDItem(BOOL bHiPri, int ii);
void NetSendCmdDamage(BOOL bHiPri, BYTE bPlr, DWORD dwDam);
void NetSendCmdMonDmg(BOOL bHiPri, WORD bMon, DWORD dwDam);
void NetSendCmdString(int pmask, const char *pszStr);
void delta_close_portal(int pnum);
DWORD ParseCmd(int pnum, TCmd *pCmd);

#ifdef __cplusplus
}
#endif

}
