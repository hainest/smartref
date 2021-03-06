#pragma once

#include "reflect.h"
#include "reflectors.h"

#include <utils/utils.h>

namespace reflection {

namespace detail {

template<class Reflection, typename Derived>
constexpr static auto is_member_type()
{
  return utils::is_detected_v<
    reflection::detect_is_member_type,
    typename Reflection::template reflector_member_type<Derived>,
    Derived
  >;
}

template<class Reflection>
constexpr static auto is_member_function()
{
  //! Member-functions currently cannot be detected (yet).
  //! However, that is not a problem, because they will be SFINAE'ed away,
  //! in case the reflected entity wasn't a member-function.
  // TODO: It might still be an annoyance for IDEs, though, where it could show
  //       the candidate member-functions, even though none exists.
  // TODO: -cmaster Come up with a mechanism to reject member functions before calling them,
  //       by checking for existence of a member that is not a member type (nor a data member).
  //       struct Detector : T, BAR
  //       but will not work for final classes
  return utils::always_true<Reflection>;
}

} // namespace detail

template<typename T>
constexpr static auto reify(Reflection<T>) -> T;

template<class Derived, class Reflection>
constexpr static auto reify(Reflection refl)
{
  if constexpr (detail::is_member_type<Reflection, Derived>())
  {
    return typename Reflection::template reflector_member_type<Derived>{};
  }
  else if constexpr (detail::is_member_function<Reflection>())
  {
    return typename Reflection::template reflector_member_function<Derived>{};
  }
}

} // namespace reflection
