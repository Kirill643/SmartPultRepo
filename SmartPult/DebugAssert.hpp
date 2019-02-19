/*
 * DebugAssert.hpp
 *
 *  Created on: 1 ���. 2019 �.
 *      Author: KapustinIV
 */

#ifndef SUPPORT_DEBUGASSERT_HPP_
#define SUPPORT_DEBUGASSERT_HPP_
#define LIBS_DEBUG_MODE



#ifdef LIBS_DEBUG_MODE

#define debugAssert(EXPR) {\
    if(!(EXPR)) {\
        asm("   BKPT #1");\
    }\
}
#else
#define debugAssert(EXP)
#endif


#endif /*  */
