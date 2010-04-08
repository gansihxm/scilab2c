/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2008 - INRIA - Arnaud TORSET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */
 
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "logm.h"


/* FIXME : Untested*/

static void dlogmaTest(void){
	int i=0;

	double in4[4] = {0.0683740368112921714783,0.5608486062847077846527,
	0.6623569373041391372681,0.7263506767340004444122 };
	double in9[9] = {0.1985143842175602912903,0.5442573162727057933807,0.2320747897028923034668,
	0.2312237196601927280426,0.2164632631465792655945,0.8833887814544141292572,
	0.6525134947150945663452,0.3076090742833912372589,0.9329616213217377662659};
	double in16[16] = {2.1460078610107302665710,3.126419968903064727783,3.6163610080257058143616,2.922266637906432151794,
	5.664248815737664699554,4.8264719732105731964111,3.3217189135029911994934,5.9350947011262178421021,
	5.0153415976092219352722,4.3685875833034515380859,2.6931248093023896217346,6.3257448654621839523315,
	4.051954015158116817474,9.1847078315913677215576,0.4373343335464596748352,4.818508932366967201233};	
	double inHer[16] = {2,3,4,5,3,1,7,9,4,7,2,4,5,9,4,7};	
	
	double result4R[4]={- 0.8770746698483730119378,0.5288031941140065583795,
	0.6245116064569415925689,- 0.2566930821175439358939};
	
	double result9R[9]={- 0.8537183024765053751537,1.9622873186332121520081,- 0.8931518563294031931577,
	- 0.6983367178614473536,- 1.1199049557115796638129,1.539392415892589571769,
	1.0815849580686147657,- 0.4078285487954845245362,0.1789837218054647349774,};
	
	double result16R[16]={1.4069394184534917968676,- 1.7915236034592834091228,2.3099248310776610004780,0.5320777350783232328979,
	0.6986579270151970222358,0.9874373592109859654187,0.8902400742596190408307,0.6067035092100719895214,
	0.0466142343271527676007,0.3821963653954382200695,1.129789301050062144682,1.2310339071369393870725,
	0.424502387440284123521,3.4580528009566289249221,- 2.1337657344549150195689,1.0826836628584670663145};
	
	double resultHerR[16]={- 0.0707459665791660696765,0.9744491331561414559914,0.0316695005563280007621,0.9186825501429138896015,
	0.9744491331561416780360,1.9318283614573175110962,- 0.0664515082056250649956,0.3546926741474874522631,
	0.0316695005563280562733,- 0.0664515082056250649956,0.3206743709780528472919,1.82590946141052867802,
	0.9186825501429141116461,0.3546926741474875632854,1.82590946141052867802,0.9537374500729456361370};
	
	 
	double out4[4],out9[9],out16[16],outHer[16];
	
	
	dlogma(in4,2,out4);
	dlogma(in9,3,out9);
	dlogma(in16,4,out16);
	dlogma(inHer,4,outHer);
	
	for(i=0;i<4;i++) {
		assert( (fabs(out4[i]-result4R[i]) / fabs(out4[i])) <3e-15);
	}
	
	for(i=0;i<9;i++) {
		assert( (fabs(out9[i]-result9R[i]) / fabs(out9[i])) <3e-14);
	}
	
	for(i=0;i<16;i++) {

		assert( (fabs(out16[i]-result16R[i]) / fabs(out16[i])) <3e-14);
	}
	
	for(i=0;i<16;i++) {
		assert( (fabs(outHer[i]-resultHerR[i]) / fabs(outHer[i])) <3e-13);
	}
} 


static void zlogmaTest(void){
	int i;
	
	
	double in4D[4] = {0.0683740368112921714783,0.5608486062847077846527,
	0.6623569373041391372681,0.7263506767340004444122 };
	double in9D[9] = {0.1985143842175602912903,0.5442573162727057933807,0.2320747897028923034668,
	0.2312237196601927280426,0.2164632631465792655945,0.8833887814544141292572,
	0.6525134947150945663452,0.3076090742833912372589,0.9329616213217377662659};
	double in16D[16] = {2.1460078610107302665710,3.126419968903064727783,3.6163610080257058143616,2.922266637906432151794,
	5.664248815737664699554,4.8264719732105731964111,3.3217189135029911994934,5.9350947011262178421021,
	5.0153415976092219352722,4.3685875833034515380859,2.6931248093023896217346,6.3257448654621839523315,
	4.051954015158116817474,9.1847078315913677215576,0.4373343335464596748352,4.818508932366967201233};	
	double inHerD[16] = {2,3,4,5,3,1,7,9,4,7,2,4,5,9,4,7};	
	
	
	double result4R[4]={- 0.8770746698483730119378,0.5288031941140065583795,
	0.6245116064569415925689,- 0.2566930821175439358939};
	double result4I[4]={2.3169161534469857599561,- 1.2719608554746495432397,
	- 1.5021738258100643115256,0.8246765001428078001311};
	double result9R[9]={- 0.8537183024765053751537,1.9622873186332121520081,- 0.8931518563294031931577,
	- 0.6983367178614473536,- 1.1199049557115796638129,1.539392415892589571769,
	1.0815849580686147657,- 0.4078285487954845245362,0.1789837218054647349774,};
	double result9I[9]={+ 0.0000000000000006661338,-0.0000000000000005551115,+0.0000000000000001110223,
	-0.0000000000000002844947,+0.0000000000000004163336,+ 0.0000000000000008743006,
	-0.0000000000000001665335,+ 0.0000000000000004996004,-0.0000000000000003330669};
	double result16R[16]={1.4069394184534917968676,- 1.7915236034592834091228,2.3099248310776610004780,0.5320777350783232328979,
	0.6986579270151970222358,0.9874373592109859654187,0.8902400742596190408307,0.6067035092100719895214,
	0.0466142343271527676007,0.3821963653954382200695,1.129789301050062144682,1.2310339071369393870725,
	0.424502387440284123521,3.4580528009566289249221,- 2.1337657344549150195689,1.0826836628584670663145};
	double result16I[16]={-1.4875734535892033427729,+ 1.8146634352088595321106,-0.0551064758054355952055,-0.8617364610492967980093,
	+ 1.0892397305420760122985,-1.3287434690517783142383,+ 0.0403503858667347281575,+ 0.6309857092212021179023,
	+ 1.3838992102024216813,-1.6881931367553519862668,+ 0.0512659110447117594145,+ 0.8016790061501579689463,
	-0.6500053973791579675634,+ 0.7929296025459252605927,-0.0240791515993044047406,-0.3765416419935233571792};

	 
	doubleComplex out4[4],out9[9],out16[16],outHer[16];
	doubleComplex in4[4],in9[9],in16[16],inHer[16];
	

	for(i=0;i<4;i++) in4[i]=DoubleComplex(in4D[i],0);
	for(i=0;i<9;i++) in9[i]=DoubleComplex(in9D[i],0);
	for(i=0;i<16;i++) in16[i]=DoubleComplex(in16D[i],0);
	for(i=0;i<16;i++) inHer[i]=DoubleComplex(inHerD[i],0);
	
	
	zlogma(in4,2,out4);
	zlogma(in9,3,out9);
	zlogma(in16,4,out16);
	zlogma(inHer,4,outHer);	
	
	
	
	
	for(i=0;i<4;i++) {		
		assert( fabs(zreals(out4[i])-result4R[i]) / fabs(zreals(out4[i])) <3e-15);
		assert( fabs(zimags(out4[i])-result4I[i]) / fabs(zimags(out4[i])) <3e-15);
	}
	
	for(i=0;i<9;i++) {
		assert( fabs(zreals(out9[i])-result9R[i]) / fabs(zreals(out9[i])) <3e-14);
		if (zimags(out9[i])>3e-16) assert( fabs(zimags(out9[i])-result9I[i]) / fabs(zimags(out9[i])) <1e-16);
		else assert(1);
	}
	
	/* FIXME : sign pb with the imaginary part below : it's due to the reals eigenvalues which are
	stored like that : eigenvalues + (-0)*i instead of eigenvalues + 0 *i 
	When we do operations with eigenvalues the sign isn't good 
	*/
	
	for(i=0;i<16;i++) {
		printf("out[%d] = %f + %f *i ---result = %f + %f *i --- assert : %f + %f*i\n",
				i,
				zreals(out16[i]),
				zimags(out16[i]),
				result16R[i],
				result16I[i],
				fabs(zreals(out16[i])-result16R[i]) / fabs(zreals(out16[i])),
				fabs(zimags(out16[i])-result16I[i]) / fabs(zimags(out16[i])));
		
		assert( fabs(zreals(out16[i])-result16R[i]) / fabs(zreals(out16[i])) <3e-13);
		assert( fabs(zimags(out16[i])-result16I[i]) / fabs(zimags(out16[i])) <3e-13);
	}
	

}

static int logmTest(void){
	dlogmaTest();
	zlogmaTest();
	return 0;
}

int main (void){
	assert(logmTest()==0);
	return 0;
}

	
	

	

	
	
