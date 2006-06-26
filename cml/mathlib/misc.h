/* -*- C++ -*- ------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/
/** @file
 *  @brief
 */

#ifndef misc_h
#define misc_h

#include <cml/mathlib/checking.h>

/* A few miscellaneous functions and helper classes.
 *
 * @todo: Fix this.
 *
 * Although we have functions to modify an existing vector to be the zero
 * vector or a cardinal axis (similarly with matrix and identity(), I often
 * find it useful to have these available as 'one-liners', for use in object
 * creation or for passing as arguments to functions, e.g.:
 *
 * vector3f v = zero_3D();
 *
 * For right now I've thrown together an ad hoc set of functions to do this,
 * but there is probably a much more elegant way to do this, perhaps involving
 * returning expressions that perform the assignment. Also:
 *
 * @todo: Function for quaternion identity.
 *
 * How to do this using this system is not immediately obvious due to
 * incompatibility between different order and cross types.
 *
 * A perhaps better option (for all these function) would be to make them
 * static member functions of the classes to which they belong. Since this
 * would involve altering existing code, I'm going to leave it alone for now.
 */

namespace cml {

//////////////////////////////////////////////////////////////////////////////
// N-d functions
//////////////////////////////////////////////////////////////////////////////

/** Return an N-d zero vector */
template < size_t N >
vector< int, fixed<N> > zero()
{
    typedef vector< int, fixed<N> > vector_type;

    vector_type result;
    result.zero();
    return result;
}

/** Return an N-d cardinal axis by index */
template < size_t N >
vector< int, fixed<N> > axis(size_t i)
{
    /* Checking */
    detail::CheckValidArg(i < N);

    typedef vector< int, fixed<N> > vector_type;
    vector_type result;
    result.cardinal(i);
    return result;
}

/** Return an NxM zero matrix */
template < size_t N, size_t M >
matrix< int, fixed<N,M>, row_basis, row_major > zero()
{
    typedef matrix< int, fixed<N,M>, row_basis, row_major > matrix_type;

    matrix_type result;
    result.zero();
    return result;
}

/** Return an NxN identity matrix */
template < size_t N >
matrix< int, fixed<N,N>, row_basis, row_major > identity()
{
    typedef matrix< int, fixed<N,N>, row_basis, row_major > matrix_type;

    matrix_type result;
    result.identity();
    return result;
}

/** Return an NxM identity transform */
template < size_t N, size_t M >
matrix< int, fixed<N,M>, row_basis, row_major > identity_transform()
{
    typedef matrix< int, fixed<N,M>, row_basis, row_major > matrix_type;

    matrix_type result;
    identity_transform(result);
    return result;
}

//////////////////////////////////////////////////////////////////////////////
// Zero vector
//////////////////////////////////////////////////////////////////////////////

/** Return the 2D zero vector */
inline vector< int, fixed<2> > zero_2D() {
    return zero<2>();
}

/** Return the 3D zero vector */
inline vector< int, fixed<3> > zero_3D() {
    return zero<3>();
}

/** Return the 4D zero vector */
inline vector< int, fixed<4> > zero_4D() {
    return zero<4>();
}

//////////////////////////////////////////////////////////////////////////////
// Cardinal axis
//////////////////////////////////////////////////////////////////////////////

/** Return a 2D cardinal axis by index */
inline vector< int, fixed<2> > axis_2D(size_t i) {
    return axis<2>(i);
}

/** Return a 3D cardinal axis by index */
inline vector< int, fixed<3> > axis_3D(size_t i) {
    return axis<3>(i);
}

/** Return a the 2D x cardinal axis */
inline vector< int, fixed<2> > x_axis_2D() {
    return axis_2D(0);
}

/** Return a the 2D y cardinal axis */
inline vector< int, fixed<2> > y_axis_2D() {
    return axis_2D(1);
}

/** Return a the 3D x cardinal axis */
inline vector< int, fixed<3> > x_axis_3D() {
    return axis_3D(0);
}

/** Return a the 3D y cardinal axis */
inline vector< int, fixed<3> > y_axis_3D() {
    return axis_3D(1);
}

/** Return a the 3D z cardinal axis */
inline vector< int, fixed<3> > z_axis_3D() {
    return axis_3D(2);
}

//////////////////////////////////////////////////////////////////////////////
// Zero matrix
//////////////////////////////////////////////////////////////////////////////

/** Return the 2x2 zero matrix */
inline matrix< int, fixed<2,2>, row_basis, row_major > zero_2x2() {
    return zero<2,2>();
}

/** Return the 3x3 zero matrix */
inline matrix< int, fixed<3,3>, row_basis, row_major > zero_3x3() {
    return zero<3,3>();
}

/** Return the 4x4 zero matrix */
inline matrix< int, fixed<4,4>, row_basis, row_major > zero_4x4() {
    return zero<4,4>();
}

//////////////////////////////////////////////////////////////////////////////
// Identity matrix
//////////////////////////////////////////////////////////////////////////////

/** Return the 2x2 identity matrix */
inline matrix< int, fixed<2,2>, row_basis, row_major > identity_2x2() {
    return identity<2>();
}

/** Return the 3x3 identity matrix */
inline matrix< int, fixed<3,3>, row_basis, row_major > identity_3x3() {
    return identity<3>();
}

/** Return the 4x4 identity matrix */
inline matrix< int, fixed<4,4>, row_basis, row_major > identity_4x4() {
    return identity<4>();
}

//////////////////////////////////////////////////////////////////////////////
// Identity transform matrix
//////////////////////////////////////////////////////////////////////////////

/** Return a 3x2 identity transform */
inline matrix< int,fixed<3,2>,row_basis,row_major > identity_transform_3x2() {
    return identity_transform<3,2>();
}

/** Return a 2x3 identity transform */
inline matrix< int,fixed<2,3>,col_basis,col_major > identity_transform_2x3() {
    return identity_transform<2,3>();
}

/** Return a 4x3 identity transform */
inline matrix< int,fixed<4,3>,row_basis,row_major > identity_transform_4x3() {
    return identity_transform<4,3>();
}

/** Return a 3x4 identity transform */
inline matrix< int,fixed<3,4>,col_basis,col_major > identity_transform_3x4() {
    return identity_transform<3,4>();
}

} // namespace cml

#endif