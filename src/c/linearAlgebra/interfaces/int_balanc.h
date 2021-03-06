 /* Copyright (C) 2017 - IIT Bombay - FOSSEE

 This file must be used under the terms of the CeCILL.
 This source file is licensed as described in the file COPYING, which
 you should have received as part of this distribution.  The terms
 are also available at
 http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 Author: Siddhesh Wani
 Organization: FOSSEE, IIT Bombay
 Email: toolbox@scilab.in
 */
#ifndef __INT_BALANC_H__
#define __INT_BALANC_H__

#ifdef  __cplusplus
extern "C" {
#endif

#define d2balancd2d2(in1,size1,out1,out2) dbalanca(in1,size1[0],NULL,out1, \
			out2,NULL,NULL)

#define d2d2balancd2d2d2d2(in1,size1,in2,size2,out1,out2,out3,out4) \
			dbalanca(in1,size1[0],in2,out1,out2,out3,out4)

#ifdef  __cplusplus
} /* extern "C" */
#endif

#endif /*__INT_BALANC_H__*/
