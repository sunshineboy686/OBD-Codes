/* car-eye��������ƽ̨ 
 * car-eye����������ƽ̨   www.car-eye.cn
 * car-eye��Դ��ַ:  https://github.com/Car-eye-admin
 * Copyright car-eye ��������ƽ̨  2017 
 */

#ifndef __OBDII_H
#define __OBDII_H

#define ENTERSYS_NEVER		0
#define ENTERSYS_OK		1
#define ENTERSYS_NEVER_SLEEP	2
#define ENTERSYS_OK_SLEEP	4


#define ONEHOUR_CALC(t)		((float)(1000.0/t)*60*60)	//����˲ʱ�ͺ���//

#define LINKING_STATUS_NONE	0x00		//�ϵ�ǰɨ��//
#define LINKING_STATUS_OK		0x01		//���߳�ʼ���ɹ�����ʾ�ѽ���ECU��//
#define LINKING_STATUS_FAIL		0x02		//�������ڳ�ʼ������ʾ���Խ���ECU��//

#define ENGER_STATUS_NONE		0x00		//δ֪//
#define ENGER_STATUS_ON		0x01		//��������(���)//
#define ENGER_STATUS_OFF		0x02		//����δ����(Ϩ��)//



#define MAX_SPEC_NUM	3

#define MAX_DTC_NUM		51


#define CALCOIL_NULL_TYPE	0	//��֧���ͺ�//
#define CALCOIL_MAF_TYPE	1	//����������ʽ//
#define CALCOIL_MAP_TYPE	2	//������ܾ���ѹ����ʽ//
#define CALCOIL_ABS_TYPE	3	//���Ը��ɷ�ʽ//


#define APP_READSTEP_NULL		0x00		//�޲���//
#define APP_READSTART_STEP	0x01		//��ȡ//
#define APP_READING_STEP		0x02		//��ȡ�� //

#define APP_READEND_STEP		0x04		//��ȡ���//

#define MIL_READ_EN				1
#define MIL_READ_DIS			2

#define OBD_CMD					0x0165
#define HAND_SHANKE				0x0001
#define CMD_FIRE_ON				0x0002
#define CMD_FIRE_OFF			0x0003
#define CMD_DTC					0x0004
#define JIA_SU_FLAG				0x0005
#define JIAN_SU_FLAG			0x0006
#define CMD_STREAM				0x0007
#define VIN_MA					0x0008
#define CMD_TRAVEL_STATUS		0x0009
#define RETURN_DTC				0x000A
#define RETURN_CLEAR_DTC		0x000B
#define M_ID					0x000C
#define CAR_STATUS              0x000D
#define GSM_Power_OFF_Relay		0x000E
#define GPS_DATA_SEND			0x000F



#pragma pack(1)
typedef struct
{
	u8 step;
	u32 time;
}_sCtrlObd;

typedef struct
{
	bool flag;
	u8 Cmd[8];
	u8 len;
}_sCmdRead;

typedef struct
{
	u32 jiffies;	//���ͳ�Ƽ�ʱ//
	float CmMile;
 	u8 CmCnt;
}_sVssMile;

typedef struct
{
	bool flag;			//���ݸ��±�־//
	u32 jiffies;	//�ͺļ���ʱ��//
}_sOilCalc;


typedef struct
{
	bool flag;
	u32 time;//�г�ʱ��//
	u32 mile;//�г����//
	float oil;//�г̺�����//
	float boil;//�г�100����ƽ���ͺ�//

	u32 idletime;//����ʱ��//
	u8 hspeed;//����ٶ�//
	u8 pspeed;//ƽ���ٶ�//
	u8 jiascnt;//�����ٴ���//
	u8 jianscnt;//�����ٴ���//
}sTrip;


typedef struct
{
   u32 cnt;
   u32 times;
   u32 miles;
   u32 tempmiles;
   float oils;
   float tempoils;
   float boils;

}sTrips;


//����ɲ�����ٶ�-35m/ss//
//��������0~100KM/H����Ϊ��׼��Ϊ10m/ss//
typedef struct
{
	bool jiasu_fg;
	bool jiansu_fg;
	u8 oldspeed;
	float oldrpm;
	float tripmile;
}_sgctrl;

typedef struct
{
	u8 time;
	u8 Name;	//��������//
	u8 Val[4];	//ֵ//
}_sPidtab;




typedef struct
{
	u8 PidDtcNum;	//���ϵ���ָʾ�Ĺ�����//
	bool fg;		//��ȡ��־//
	u8 Num;			//���������//
	u8 dtc[MAX_DTC_NUM][5];//������//
}_sDTC;

typedef struct
{
	bool SpecData;
	u8 CmdNum;
	u8 Cmd[MAX_SPEC_NUM];
	bool Piddata;
}_sReadType;

typedef struct
{
	bool MIL_fg;		//MIL��״̬//
	u8 DTCs;			//��ǰ���ϸ���//
	u8 Misfire;
	u8 Catalyst1;
	u8 Catalyst2;
	//_sDTC DtcBuf;
}_sInessCode;

typedef struct
{
	u8 name;
	u8 Val[2];	//ֵ//
}_sFreezePid;

typedef struct			//����֡//
{
	bool readpidfg;	//�Ƿ����ȡ�����������//
	bool Fg;	//���ڶ���֡��־//
	u8 Dtc[5];		//����Ĺ���//
//	u8 FreePidNum;	//���������������//
	u8 sup1[4];//֧����1//
	u8 sup2[4];//֧����2//
	u8 sup3[4];//֧����3//
	
	u16 Savecnt;	//���ݳ���//
	_sFreezePid Pid[128];	//�����������//
}_sFreezeDtc;


typedef struct
{
	bool Fg;
	u8 MC_vin;	//MessageCount VIN = ?  response messages//
	u8 Data[17];	////
}_sVIN;

typedef struct
{
	u8 Freeze_Fg:1;
	u8 CLearDtc_Fg:1;
	u8 ReadDtc_Fg:1;
	u8 ReadVin_Fg:1;

	u8 res:4;
}_sCOMCMD;

typedef struct
{
	_sCOMCMD cmd;
	u32 time;
}_sCOM;

typedef struct
{
	u8 Data[200];	//Pid���ݣ��198�ֽ�//
	u32 PidSup1;
	u32 PidSup2;
	u32 PidSup3;
	

}_sPid;




typedef struct
{
	u8 oilcalctype;	//�ͺļ��㷽ʽ//
	u8 vss;		//����  0x0D//
	s8 fireangle;  	//�����ǰ��0x0e//
	u8 RemainL;
	u16 TrouLen;
	u16 CleartrouLen;
	float rpm;	 //ת��0x0C//
	float maf;	//�������� 0x10//
	
	float ect;		//ˮ�� 0x05//
	float map;	//������ܾ���ѹ�� 0x0B//
	float iat;		//�����¶� 0x0F//

	float load_abs;	//���Ը���0x43//
}_sPid_Cycle;


typedef struct
{
	

	_sReadType ReadType;
	bool entry;
	u8 ProtoclType;//Э������//
	u8 Link_status;//����״̬//
	u8 Enger_status;//����״̬//

	float EngineL;

	_sPid Pid;
	_sPid_Cycle PidCycle;

	
	_sInessCode InessCode;	//׼�����������������//
			//������//
	_sFreezeDtc Freeze;	//����֡//
	_sVIN Vin;

	float ssOil;	//˲ʱ�ͺ�//
	float bgOil;	//�ٹ���ƽ���ͺ�//

	u32 tripmile;	//���//

	_sCOM com;
	
}_sOBDDATA;


typedef struct
{
	u8 step;	//��ȡ���Ʊ�׼//

	u8 n;
	u8 x;
	u8 id[256];

	u8 data[512];	//���ݻ���//
	u16 len;		//���ݳ���//
}sAppPidreadCtl;

typedef struct
{
	u8 step;	////
	bool flag;	//���ޱ�־//
	u8 dtc[5];
	u8 data[300];
	u16 len;
}sAppFreezeDtcCtl;	//����֡��ȡ//

typedef struct
{
	u8 step;	////
	bool AutoReadFalg;
	_sDTC dtc;
}sAppDtcreadCtl;	//�������ȡ//

typedef struct
{
	u8 step;	////
}sAppVinreadCtl;	//�������ȡ//


typedef struct
{
	u8 flag;	//�Ƿ��ȡ���ϵ�״̬//
	u32 time;	//��ȡ���//
}_sMilRead;


typedef struct
{
	float firstMile;	//��ʼ���//
	float firstOile;		//��ʼ�ܺ���//
	float first100Oile;	//��ʼ100�������ֵ//
	float first100Mile;	//��ʼ100�������ֵ//

	float CurMile;	//��ǰ�ܵ������//
	float CurOil;	//��ǰ������//
}sDtuRdata;



#pragma pack()

extern _sOBDDATA  ObdData;
extern sTrip trip;
extern sTrip temptrip;		//��ʱ�г�//
extern sTrips trips;
extern sAppPidreadCtl AppPidreadCtl;
extern sAppFreezeDtcCtl AppFreezeDtcCtl;
extern sAppDtcreadCtl AppDtcreadCtl;
extern sAppDtcreadCtl AppDtcClearCtl;
extern u8 K_Enter_ErrFg;
extern u8 K2000_Enter_ErrFg;


void CmdRead_In(u8* cmd,u8 len);
void Obd_App_Initial(void);
void Obd_task(void);
bool WakeSysInit(void);
void Read_Trip_Data(void);
void Read_Trips_Data(void);
#endif


