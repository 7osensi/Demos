/*==============================================================================================
===============================   - BIT_MATH.h				     ===============================
===============================   - Created:22/9/2022			 ===============================
===============================   - Author: Hussein Mohamed      ===============================
===============================   - Version : _1_				 ===============================
===============================   - Note :
									     *-
									     *-
=================================================================================================*/


 #ifndef BIT_MATH_H_
 #define BIT_MATH_H_


 #define 	SET_BIT(REG, BITNUM) 	REG |= 1U << BITNUM
 #define 	CLR_BIT(REG, BITNUM) 	REG &= ~(1U << BITNUM)
 #define 	TOG_BIT(REG, BITNUM) 	REG ^= 1U << BITNUM
 #define 	GET_BIT(REG, BITNUM) 	( ( REG >> BITNUM ) & 1U )

 #endif /* BIT_MATH_H_ */