/* car-eye��������ƽ̨ 
 * car-eye����������ƽ̨   www.car-eye.cn
 * car-eye��Դ��ַ:  https://github.com/Car-eye-admin
 * Copyright car-eye ��������ƽ̨  2017 
 */


#ifndef _OIL_ARITH_H
#define _OIL_ARITH_H


float Oil_Arith_PID10(float maf,u32 time);
float Oil_Arith_PID0b(float rpm,float etc,float iat,float map,u32 time);
float Oil_Arith_PID43(float rpm,float EngineL,float load_lbs);

#endif








