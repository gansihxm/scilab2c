// Copyright (C) 2017 - IIT Bombay - FOSSEE
//
// This file must be used under the terms of the CeCILL.
// This source file is licensed as described in the file COPYING, which
// you should have received as part of this distribution.  The terms
// are also available at
// http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
// Author: Jorawar Singh, Sandeep Gupta
// Organization: FOSSEE, IIT Bombay
// Email: toolbox@scilab.in


subdemolist = ["Discrete Cosine Transform" , "test_dct.dem.sce";
	          "Inverse Cosine Transform" , "test_idct.dem.sce";
              ];

global SCI2CHOME;
subdemolist(:,2) = SCI2CHOME + "/demos/CT/"+ subdemolist(:,2);