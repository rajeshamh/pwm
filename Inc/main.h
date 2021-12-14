/*
 * main.h
 *
 *  Created on: Nov 13, 2021
 *      Author: Rajesha M H
 */

#ifndef MAIN_H_
#define MAIN_H_

#define __vo  volatile

#define SWSTART     1<<30
#define TCIF 		1<<5
#define ARPE 		1<<7
#define CCE2_EN		1<<4
#define UPDATE_GEN  1<<0
#define TIM_EN      1<<0
#define CCE1_EN     1<<0
#define RESET       0<<4
#define UPDATE_EVNT 2<<4
#define PWM_MOD1_EN 6<<4
#define PRELOAR_EN  1<<3


#define EXT_TRIG_EN      3<<28
#define EXT_EVNT_SELCTN	 11<<24
#define TCIE			 1<<4
#define MINC             1<<10
#define PINC			 1<<9
#define CIRC			 1<<8
#define DIR				 0<<6
#define CHSEL			 0<<25
#define DMDIS			 0<<2
#define EN 				 1<<0
#define DMA_MODE_ON      1<<8


#define ENABLE 			1

#define PERIPHERAL_BASEADDR              (0x40000000U)
#define APB1PERIPH_BASEADDR				 (0x40000000U)
#define AHB1PERIPH_BASEADDR				 (0x40020000U)
#define APB2PERIPH_BASEADDR				 (0x40010000U)


#define TIM2_BASEADDR    				(APB1PERIPH_BASEADDR   + 0x0000)
#define TIM4_BASEADDR    				(APB1PERIPH_BASEADDR   + 0x0800)
#define RCC_BASEADDR             		(AHB1PERIPH_BASEADDR   + 0x3800)
#define GPIOA_BASEADDR					((AHB1PERIPH_BASEADDR))
#define GPIOB_BASEADDR					((AHB1PERIPH_BASEADDR) + 0X0400U )
#define ADC1_BASEADDR					((APB2PERIPH_BASEADDR) + 0x2000U )
#define DMA2_BASEADDR                   ((AHB1PERIPH_BASEADDR) + 0X6400U)
#define SYST_BASEADDR		            ((volatile uint32_t*) 0xE000E010U)




#define SysTick						   ((SysTick_t*)SYST_BASEADDR)
#define RCC                            ((RCC_Regdef_t *)RCC_BASEADDR  )
#define TIM2                           ((TIM_Regdef_t *)TIM2_BASEADDR )
#define GPIOA                          ((GPIO_Regdef_t*)GPIOA_BASEADDR)
#define GPIOB   					   ((GPIO_Regdef_t*)GPIOB_BASEADDR)
#define TIM4						   ((TIM_Regdef_t *)TIM4_BASEADDR )
#define ADC1                           ((ADCx_Regdef_t*)ADC1_BASEADDR )
#define DMA2                           ((DMAx_Regdef_t*)DMA2_BASEADDR )



#define DMA2_PERIPH_CLK_EN()            (RCC->AHB1ENR |= (1<<22))
#define TIM2_PERIPH_CLK_EN()            (RCC->APB1ENR |= (1<<0))
#define TIM4_PERIPH_CLK_EN()			(RCC->APB1ENR |= (1<<2))
#define GPIOA_PERIPH_CLK_EN()		    (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PERIPH_CLK_EN()			(RCC->AHB1ENR |= (1<<1))
#define ADC1_PERIPH_CLK_EN()			(RCC->APB2ENR |= (1<<8))



typedef struct
{
	volatile uint32_t  CNTRL;
	volatile uint32_t  LOAD;
	volatile uint32_t  CURRENT_VAL;

}SysTick_t;


typedef struct
{

	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	         uint32_t Reserved;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	         uint32_t RESERVED1;
	         uint32_t RESERVED2;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
             uint32_t RESERVED3;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    	     uint32_t RESERVED4;
	         uint32_t RESERVED5;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	         uint32_t RESERVED6;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    		 uint32_t RESERVED7;
	         uint32_t RESERVED8;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
	         uint32_t RESERVED9;
	         uint32_t RESERVED10;
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR;
}RCC_Regdef_t;


typedef struct
{
	    volatile	uint32_t	CR1;
		volatile   	uint32_t    CR2;
		volatile	uint32_t	SMCR;
		volatile	uint32_t	DIER;
		volatile	uint32_t	SR;
		volatile	uint32_t	EGR;
		volatile	uint32_t	CCMR1;
		volatile	uint32_t	CCMR2;
		volatile	uint32_t	CCER;
		volatile	uint32_t	CNT;
		volatile    uint32_t	PSC;
		volatile 	uint32_t	ARR;
		volatile	uint32_t	RCR;
		volatile	uint32_t	CCR[4];
		volatile	uint32_t	BDTR;
		volatile    uint32_t	DCR;
		volatile	uint32_t	DMAR;


}TIM_Regdef_t;


typedef struct
{
	volatile uint32_t MODER;			//	|<TODO	        Address Offset     0x00
	volatile uint32_t OTYPER;			//	|<TODO	        Address Offset     0x04
	volatile uint32_t OSPEEDR;			//	|<TODO	        Address Offset     0x08
	volatile uint32_t PUPDR;			//	|<TODO	        Address Offset     0x1c
	volatile uint32_t IDR;				//	|<TODO	        Address Offset     0x10
	volatile uint32_t ODR;			    //	|<TODO	        Address Offset     0x14
	volatile uint32_t BSRR;				///	|<TODO	        Address Offset     0x18
	volatile uint32_t LCKR;              //  	|<TODO	        Address Offset     0x2c
	volatile uint32_t AFR[2];			//	|<TODO	        Address Offset     0x20


}GPIO_Regdef_t;


typedef struct
{
	volatile uint32_t SR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMPR[2];
	volatile uint32_t JOFR[4];
	volatile uint32_t HTR;
	volatile uint32_t LTR;
	volatile uint32_t SQR[3];
	volatile uint32_t JSQR;
	volatile uint32_t JDR[4];
	volatile uint32_t DR;
	volatile uint32_t CSR;
	volatile uint32_t CCR;
	volatile uint32_t CDR;

}ADCx_Regdef_t;

typedef struct
{

	__vo uint32_t LISR;				/*|<TODO	        Address Offset     0x00    */
	__vo uint32_t HISR;				/*|<TODO	        Address Offset     0x04    */
	__vo uint32_t LIFCR;			/*|<TODO	        Address Offset     0x08    */
	__vo uint32_t HIFCR;			/*|<TODO	        Address Offset     0xc    */
	__vo uint32_t S0CR;				/*|<TODO	        Address Offset     0x10    */
	__vo uint32_t S0NDTR;			/*|<TODO	        Address Offset     0x14    */
	__vo uint32_t S0PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S0M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S0M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S0FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S1CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S1NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S1PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S1M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S1M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S1FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S2CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S2NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S2PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S2M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S2M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S2FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S3CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S3NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S3PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S3M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S3M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S3FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S4CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S4NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S4PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S4M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S4M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S4FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S5CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S5NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S5PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S5M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S5M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S5FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S6CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S6NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S6PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S6M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S6M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S6FCR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S7CR;             /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S7NDTR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S7PAR;			/*|<TODO	        Address Offset     0x18    */
	__vo uint32_t S7M0AR;           /*|<TODO	        Address Offset     0x1c    */
	__vo uint32_t S7M1AR;		    /*|<TODO	        Address Offset     0x20    */
	__vo uint32_t S7FCR;			/*|<TODO	        Address Offset     0x18    */

}DMAx_Regdef_t;










#endif /* MAIN_H_ */
