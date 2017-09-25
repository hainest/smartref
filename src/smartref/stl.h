#pragma once

#include <reflection/reflection.h>

#if 0
//! This block contains the old-style STL-support, and has been superseeded by
//! the generic reflection support.

namespace smartref {

DECLARE_USING_MEMBER_TYPE(value_type);
DECLARE_USING_MEMBER_TYPE(difference_type);
DECLARE_USING_MEMBER_TYPE(iterator);

template<typename Delegate, class Derived>
struct STL : USING_MEMBER_TYPE(Delegate, value_type)
           , USING_MEMBER_TYPE(Delegate, difference_type)
           , USING_MEMBER_TYPE(Delegate, iterator)
{
    USING_MEMBER(push_back)
    USING_MEMBER(begin)
    USING_MEMBER(end)
};

} // namespace smartref
#endif

////////////////////////////////////////////////////////////////////////////////
//! std::vector                                                               //
////////////////////////////////////////////////////////////////////////////////

//! member-types
REFLECTABLE(auto, value_type);
REFLECTABLE(auto, allocator_type);
REFLECTABLE(auto, size_type);
REFLECTABLE(auto, difference_type);
REFLECTABLE(auto, reference);
REFLECTABLE(auto, const_reference);
REFLECTABLE(auto, pointer);
REFLECTABLE(auto, const_pointer);
REFLECTABLE(auto, iterator);
REFLECTABLE(auto, const_iterator);
REFLECTABLE(auto, reverse_iterator);
REFLECTABLE(auto, const_reverse_iterator);

//! member-functions
// TODO: (constructor)
// TODO: operator=
REFLECTABLE(auto, assign);
REFLECTABLE(auto, get_allocator);
REFLECTABLE(auto, at);
// TODO: operator[]
REFLECTABLE(auto, front);
REFLECTABLE(auto, back);
REFLECTABLE(auto, data);
REFLECTABLE(auto, begin);
REFLECTABLE(auto, cbegin);
REFLECTABLE(auto, end);
REFLECTABLE(auto, cend);
REFLECTABLE(auto, rbegin);
REFLECTABLE(auto, crbegin);
REFLECTABLE(auto, rend);
REFLECTABLE(auto, crend);
REFLECTABLE(auto, empty);
REFLECTABLE(auto, size);
REFLECTABLE(auto, max_size);
REFLECTABLE(auto, reserve);
REFLECTABLE(auto, capacity);
REFLECTABLE(auto, shrink_to_fit);
REFLECTABLE(auto, clear);
REFLECTABLE(auto, insert);
REFLECTABLE(auto, emplace);
REFLECTABLE(auto, erase);
REFLECTABLE(auto, push_back);
REFLECTABLE(auto, emplace_back);
REFLECTABLE(auto, pop_back);
REFLECTABLE(auto, resize);
REFLECTABLE(auto, swap);