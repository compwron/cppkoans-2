#include "cppkoans.h"

// TC++PL 5.5 References
// 
//   A reference is an alternative name for an object. [I.e. an reference is an
//   alias.] ... The notation X& means reference to X.
// 
//   To ensure that a reference is a name for something (that is, bound to an
//   object), we _must_ initialize the reference.
// 
//   Consequently, the value of a reference cannot be changed after
//   initialization; it always refers to the same object.
// 
//   The initializer for a "plain" T& [opposed to const T&] must be an lvalue of
//   type T.
//
//   The initializer for a const T& need not to be an lvalue [of type T] or even
//   of type T. In such cases
//   1) ....
//   2)
//   3)
//
//   A temporary created to hold a reference initializer persists until the end
//   of its reference's scope. [I.e. a const reference that is destructed, when
//   it refers to a temporary object, also destructs that temporary object].
TEST(about_references,foo)
{
}
