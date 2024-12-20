/*-------------------------------------------------------------------------
 @@COPYRIGHT@@
 *-----------------------------------------------------------------------*/

#pragma once

#include <cml/vector/cross_node.h>

namespace cml {

/** Compute the cross-product of two 3D vectors, and return the result as an
 * expression node (vector_cross_node).
 *
 * @throws vector_size_error at run-time if left or right is
 * dynamically-sized and is not a 3D vector.  The size is checked at
 * compile time for fixed-sized expressions.
 */
template<class Sub1, class Sub2, enable_if_vector_t<Sub1>* = nullptr,
  enable_if_vector_t<Sub2>* = nullptr>
inline auto
cross(Sub1&& sub1,
  Sub2&& sub2) -> vector_cross_node<actual_operand_type_of_t<decltype(sub1)>,
  actual_operand_type_of_t<decltype(sub2)>>
{
  /* Deduce the operand types of the subexpressions (&, const&, &&): */
  using sub1_type = actual_operand_type_of_t<decltype(sub1)>;
  using sub2_type = actual_operand_type_of_t<decltype(sub2)>;
  return vector_cross_node<sub1_type, sub2_type>((sub1_type) sub1,
    (sub2_type) sub2);
}

}  // namespace cml
