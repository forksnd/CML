/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 */

#pragma once

#include <cml/matrix.h>

using matrix44d = cml::matrix44d;
inline void mxm_4x4(matrix44d& res, const matrix44d& A, const matrix44d& B)
{
    res = A*B;
}