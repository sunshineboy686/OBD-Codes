/* car-eye��������ƽ̨ 
 * car-eye����������ƽ̨   www.car-eye.cn
 * car-eye��Դ��ַ:  https://github.com/Car-eye-admin
 * Copyright car-eye ��������ƽ̨  2017 
 */


 
#ifndef _MAIN_H
#define _MAIN_H
#define VER 			" car-eye-OBDII-1.0.0"


#define CAN_POWER_ON			GPIO_WriteBit(GPIOA, GPIO_Pin_6,Bit_RESET)
#define CAN_POWER_OFF			GPIO_WriteBit(GPIOA, GPIO_Pin_6,Bit_SET)


#pragma pack(1)

typedef struct
{
	u32 flag;
	u8 serialnum[12];
	float Mile;
	float Oil;
	float OilMileage;		//����ƽ���ͺ���//
	float MileageOil;		//����ƽ���ͺ���//
	float EngineL;			//����������//
	u32 Encryptval;

	u32 K_Delay;
	u32 K2000_Delay;
	u32 res3;
	u32 res4;
	u32 res5;
	u32 res6;
	u32 res7;
	u32 res8;
	float oldSetMile;		//��һ��У׼���//

	float Mile_Percent;		//���У׼ϵ��//

	u32 end;				///����������//
}_SaveSet;

#pragma pack()

extern bool accstate;
extern _SaveSet  saveset;
extern float PowerV;
extern u32 SoftDog;


#endif

