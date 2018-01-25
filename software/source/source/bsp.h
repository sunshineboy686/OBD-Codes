/* car-eye��������ƽ̨ 
 * car-eye����������ƽ̨   www.car-eye.cn
 * car-eye��Դ��ַ:  https://github.com/Car-eye-admin
 * Copyright car-eye ��������ƽ̨  2017 
 */

#ifndef	BSP_H
#define	BSP_H

#define    TIM_05US_VAL			3
#define    TIM_1US_VAL			7

/*
*******************************************************************************
* ��������
*******************************************************************************
*/
#define UART_TXH_GSM		1		//����1//
#define UART_DEBUG_PRINT 	2	//����2//


#define 	UART_BUF_SIZE           256     /*������󻺳���Ϊ256���ֽ�*/

//FLASH�ռ����///////////////////////////////////////////////
#define Page_Size				1024
#define Page_UseFlag			0xAA55AA55
#define MinBlockSize			256

//��������ռ�10K//
#define Bootstap               0x8000000
//Ӧ�ó���ռ�50k//
#define AppliactionAdress 0x8002800
//��̿ռ�//
#define MileStartAddress		0x800E000
#define Mile_Page_Num		2
//�ͺĿռ�//
#define OilStartAddress			(MileStartAddress + Mile_Page_Num*Page_Size)
#define Oil_Page_Num			2

//�����ռ�//
#define SaveParaAddress		(OilStartAddress + Oil_Page_Num*Page_Size)
#define Para_Page_Num		2
//���������ı���1K//
#define UpdateParaAdress      0x8010800
//�����ļ��ռ�61K//
#define UpdateFileAdress       0x8010C00
#define UpdateFilePages         61

#define ACC_ON_OUT			GPIO_SetBits(GPIOB, GPIO_Pin_8)
#define ACC_OFF_OUT			GPIO_ResetBits(GPIOB, GPIO_Pin_8)
#define TIME_40_DAYS			3456000000UL

/*
*******************************************************************************
* ���Ͷ���
*******************************************************************************
*/
#pragma pack(1)

typedef struct 
{
    u8 iHead;
    u8 iTail;
    u8 buf[UART_BUF_SIZE];
} sUart;

#pragma pack()


/*
*******************************************************************************
* ȫ�ֱ�������
*******************************************************************************
*/

/*
*******************************************************************************
* ����ԭ������
*******************************************************************************
*/
void CheckEncryphtion(void);
u16 BSP_PowerAdcValue(void);
u16 BSP_ScanAdcChannel(void);
void Adc_PowerOff(void);

void ReadOilMilePara(float* data,u32 StartAddress,u8 PageNum);
void WriteOilMilePara(float* data,u32 StartAddress,u8 PageNum);
void ReadSavePara(_SaveSet* set);
void WriteSavePara(u32* set);



void Uart_Send_Byte(u8 uart,u8 data);
void Uart_send(u8 uart,u8* src,u16 len);
bool Uart_read(u8 NUM,u8* data);

void BSP_UartInit(u8 PortNum, u32 Baud);

void BSP_SysTick(void);
void GetSysTick(u32* n);
bool CheckSysTick(u32* n,u32 time);
bool CheckSysTicki(u32* n,u32 time);
bool CheckSysTick_ck(u32* n,u32 time);

void BSP_InterruptConfig(void);
void BSP_SysTick_Config(void);
void BSP_GPIO_Config(void);
void BSP_SysInit(void);
void BSP_RESET_DOG(void);
void BSP_SysReset(void);
void SysTick_Deal(void);
//void BSP_SimUartRx(u8 UartNum, u8 c);
#endif
