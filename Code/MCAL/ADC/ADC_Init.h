﻿/*
 * ADC_Init.h
 *
 * Created: 11/03/2023 06:11:04 
 *  Author: Menna Eid
 */ 


#ifndef ADC_INIT_H_
#define ADC_INIT_H_
ES_t ADC_euInit(ADC_enTypesVref type);
ES_t ADC_SelectChannel(ADC_enCHANNELS enChannelId);
ES_t ADC_enStartConversion();
ES_t ADC_enPollingSystem(void);
ES_t ADC_euReadADC(u16_t *value);
ES_t ADC_enEnableTriggeringMode(ADC_enTriggeringTypes en_TriggerId);
ES_t ADC_enDisableTriggeringMode(void);
ES_t ADC_enEnableInterruptMode(void); 
ES_t ADC_enCallBack(void(*Localptr)(void));
float ADC_AnalogVal(u16_t value,ADC_enTypesVref type);



#endif /* ADC_INIT_H_ */