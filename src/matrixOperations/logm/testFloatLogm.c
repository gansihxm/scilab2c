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
 
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "logm.h"


static void slogmaTest(void){
	int i=0;

	float in4[4] = {0.0683740368112921714783f,0.5608486062847077846527f,
	0.6623569373041391372681f,0.7263506767340004444122f };
	float in9[9] = {0.1985143842175602912903f,0.5442573162727057933807f,0.2320747897028923034668f,
	0.2312237196601927280426f,0.2164632631465792655945f,0.8833887814544141292572f,
	0.6525134947150945663452f,0.3076090742833912372589f,0.9329616213217377662659f};
	float in16[16] = {2.1460078610107302665710f,3.126419968903064727783f,3.6163610080257058143616f,2.922266637906432151794f,
	5.664248815737664699554f,4.8264719732105731964111f,3.3217189135029911994934f,5.9350947011262178421021f,
	5.0153415976092219352722f,4.3685875833034515380859f,2.6931248093023896217346f,6.3257448654621839523315f,
	4.051954015158116817474f,9.1847078315913677215576f,0.4373343335464596748352f,4.818508932366967201233f};	
	float inHer[16] = {2.0f,3.0f,4.0f,5.0f,3.0f,1.0f,7.0f,9.0f,4.0f,7.0f,2.0f,4.0f,5.0f,9.0f,4.0f,7.0f};	
	
	float result4R[4]={- 0.8770746698483730119378f,0.5288031941140065583795f,
	0.6245116064569415925689f,- 0.2566930821175439358939f};
	
	float result9R[9]={- 0.8537183024765053751537f,1.9622873186332121520081f,- 0.8931518563294031931577f,
	- 0.6983367178614473536f,- 1.1199049557115796638129f,1.539392415892589571769f,
	1.0815849580686147657f,- 0.4078285487954845245362f,0.1789837218054647349774f};
	
	float result16R[16]={1.4069394184534917968676f,- 1.7915236034592834091228f,2.3099248310776610004780f,0.5320777350783232328979f,
	0.6986579270151970222358f,0.9874373592109859654187f,0.8902400742596190408307f,0.6067035092100719895214f,
	0.0466142343271527676007f,0.3821963653954382200695f,1.129789301050062144682f,1.2310339071369393870725f,
	0.424502387440284123521f,3.4580528009566289249221f,- 2.1337657344549150195689f,1.0826836628584670663145f};
	
	float resultHerR[16]={- 0.0707459665791660696765f,0.9744491331561414559914f,0.0316695005563280007621f,0.9186825501429138896015f,
	0.9744491331561416780360f,1.9318283614573175110962f,- 0.0664515082056250649956f,0.3546926741474874522631f,
	0.0316695005563280562733f,- 0.0664515082056250649956f,0.3206743709780528472919f,1.82590946141052867802f,
	0.9186825501429141116461f,0.3546926741474875632854f,1.82590946141052867802f,0.9537374500729456361370f};
	
	 
	float out4[4],out9[9],out16[16],outHer[16];
	
	
	slogma(in4,2,out4);
	slogma(in9,3,out9);
	slogma(in16,4,out16);
	slogma(inHer,4,outHer);
	
	for(i=0;i<4;i++) {
		assert( (fabs(out4[i]-result4R[i]) / fabs(out4[i])) <1e-6);
	}
	
	for(i=0;i<9;i++) {
		assert( (fabs(out9[i]-result9R[i]) / fabs(out9[i])) <1e-6);
	}
	
	for(i=0;i<16;i++) {
		assert( (fabs(out16[i]-result16R[i]) / fabs(out16[i])) <1e-6);
	}
	
	for(i=0;i<16;i++) {
		assert( (fabs(outHer[i]-resultHerR[i]) / fabs(outHer[i])) <1e-7);
	}
}


static void clogmaTest(void){	
	int i;
	 
	float in4D[4] = {0.0683740368112921714783f,0.5608486062847077846527f,
	0.6623569373041391372681f,0.7263506767340004444122f };
	float in9D[9] = {0.1985143842175602912903f,0.5442573162727057933807f,0.2320747897028923034668f,
	0.2312237196601927280426f,0.2164632631465792655945f,0.8833887814544141292572f,
	0.6525134947150945663452f,0.3076090742833912372589f,0.9329616213217377662659f};
	float in16D[16] = {2.1460078610107302665710f,3.126419968903064727783f,3.6163610080257058143616f,2.922266637906432151794f,
	5.664248815737664699554f,4.8264719732105731964111f,3.3217189135029911994934f,5.9350947011262178421021f,
	5.0153415976092219352722f,4.3685875833034515380859f,2.6931248093023896217346f,6.3257448654621839523315f,
	4.051954015158116817474f,9.1847078315913677215576f,0.4373343335464596748352f,4.818508932366967201233f};	
	float inHerD[16] = {2.0f,3.0f,4.0f,5.0f,3.0f,1.0f,7.0f,9.0f,4.0f,7.0f,2.0f,4.0f,5.0f,9.0f,4.0f,7.0f};	
	
	
	float result4R[4]={- 0.8770746698483730119378f,0.5288031941140065583795f,
	0.6245116064569415925689f,- 0.2566930821175439358939f};
	float result4I[4]={2.3169161534469857599561f,- 1.2719608554746495432397f,
	- 1.5021738258100643115256f,0.8246765001428078001311f};
	float result9R[9]={- 0.8537183024765053751537f,1.9622873186332121520081f,- 0.8931518563294031931577f,
	- 0.6983367178614473536f,- 1.1199049557115796638129f,1.539392415892589571769f,
	1.0815849580686147657f,- 0.4078285487954845245362f,0.1789837218054647349774f};
	float result9I[9]={- 0.0000000000000006661338f,0.0000000000000005551115f,0.0000000000000001110223f,
	0.0000000000000002844947f,0.0000000000000004163336f,- 0.0000000000000008743006f,
	0.0000000000000001665335f,- 0.0000000000000004996004f,0.0000000000000003330669f};
	float result16R[16]={1.4069394184534917968676f,- 1.7915236034592834091228f,2.3099248310776610004780f,0.5320777350783232328979f,
	0.6986579270151970222358f,0.9874373592109859654187f,0.8902400742596190408307f,0.6067035092100719895214f,
	0.0466142343271527676007f,0.3821963653954382200695f,1.129789301050062144682f,1.2310339071369393870725f,
	0.424502387440284123521f,3.4580528009566289249221f,- 2.1337657344549150195689f,1.0826836628584670663145f};
	float result16I[16]={1.4875734535892033427729f,- 1.8146634352088595321106f,0.0551064758054355952055f,0.8617364610492967980093f,
	- 1.0892397305420760122985f,1.3287434690517783142383f,- 0.0403503858667347281575f,- 0.6309857092212021179023f,
	- 1.3838992102024216813f,1.6881931367553519862668f,- 0.0512659110447117594145f,- 0.8016790061501579689463f,
	0.6500053973791579675634f,- 0.7929296025459252605927f,0.0240791515993044047406f,0.3765416419935233571792f};
	float resultHerR[16]={- 0.0707459665791660696765f,0.9744491331561414559914f,0.0316695005563280007621f,0.9186825501429138896015f,
	0.9744491331561416780360f,1.9318283614573175110962f,- 0.0664515082056250649956f,0.3546926741474874522631f,
	0.0316695005563280562733f,- 0.0664515082056250649956f,0.3206743709780528472919f,1.82590946141052867802f,
	0.9186825501429141116461f,0.3546926741474875632854f,1.82590946141052867802f,0.9537374500729456361370f};
	float resultHerI[16]={2.1383917599789858954296f,- 0.5351429414718615884539f,- 1.3567950682942089279948f,0.1340361867044403687554f,
	- 0.5351429414718615884539f,2.2766753224580762449136f,- 0.6151069729626167381653f,- 1.1421039303668867326280f,
	- 1.3567950682942089279948f,- 0.6151069729626165161207f,1.2861990290089324595613f,0.4088471998565592624431f,
	0.1340361867044403965110f,- 1.1421039303668867326280f,0.4088471998565592624431f,0.5819191957335942966267f};

	floatComplex out4[4],out9[9],out16[16],outHer[16];
	floatComplex in4[4],in9[9],in16[16],inHer[16];
	

	for(i=0;i<4;i++) in4[i]=FloatComplex(in4D[i],0);
	for(i=0;i<9;i++) in9[i]=FloatComplex(in9D[i],0);
	for(i=0;i<16;i++) in16[i]=FloatComplex(in16D[i],0);
	for(i=0;i<16;i++) inHer[i]=FloatComplex(inHerD[i],0);
	
	
	clogma(in4,2,out4);
	clogma(in9,3,out9);
	clogma(in16,4,out16);
	clogma(inHer,4,outHer);	
	
	
	
	
	for(i=0;i<4;i++) {		
		assert( fabs(creals(out4[i])-result4R[i]) / fabs(creals(out4[i])) <1e-6);
		assert( fabs(cimags(out4[i])-result4I[i]) / fabs(cimags(out4[i])) <1e-6);
	}
	
	for(i=0;i<9;i++) {
		assert( fabs(creals(out9[i])-result9R[i]) / fabs(creals(out9[i])) <1e-6);
		if (cimags(out9[i])>1e-15) assert( fabs(cimags(out9[i])-result9I[i]) / fabs(cimags(out9[i])) <1e-7);
		else assert(1);
	}
	
	/* FIXME : sign pb with the imaginary part below : it's due to the reals eigenvalues which are
	stored like that : eigenvalues + (-0)*i instead of eigenvalues + 0 *i 
	When we do operations with eigenvalues the sign isn't good 
	*/
	
	for(i=0;i<16;i++) {
		printf("out[%d] = %f + %f *i ---result = %f + %f *i --- assert : %f + %f*i\n",
				i,
				creals(out16[i]),
				cimags(out16[i]),
				result16R[i],
				result16I[i],
				fabs(creals(out16[i])-result16R[i]) / fabs(creals(out16[i])),
				fabs(cimags(out16[i])-result16I[i]) / fabs(cimags(out16[i])));
		
		assert( fabs(creals(out16[i])-result16R[i]) / fabs(creals(out16[i])) <1e-6);
		assert( fabs(cimags(out16[i])-result16I[i]) / fabs(cimags(out16[i])) <1e-5);
	}
	
	for(i=0;i<16;i++) {
		assert( fabs(creals(outHer[i])-resultHerR[i]) / fabs(creals(outHer[i])) <1e-7);
		assert( fabs(cimags(outHer[i])-resultHerI[i]) / fabs(cimags(outHer[i])) <1e-7);
	}
}

static int logmTest(void){
	slogmaTest();
	clogmaTest();
	return 0;
}

int main (void){
	assert(logmTest()==0);
	return 0;
}


