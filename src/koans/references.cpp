#include "cppkoans.h"
#pragma GCC diagnostic ignored "-Wunused-variable"

// Resources on references:
// - C++FAQ: http://www.parashift.com/c++-faq/references.html
// - TC++PL4 5.5 References
// - http://en.wikipedia.org/wiki/Reference_(C++)


// TC++PL4 7.7 References
//   A reference is an alternative name for an object, an alias... In a type
//   name, the notation X& means "reference to X".
//
// Always remember that a reference is an alias. So after ri has been defined to
// be a reference to object i, the identifiers ri and i can be used
// interchangably. Both identifiers mean the same object without any exception.
TEST(about_references,a_reference_is_an_alias)
{
  int i = 3;
  int& ri = i;
  EXPECT_EQ( __, ri );

  ri = 2;
  EXPECT_EQ( __, i );
  EXPECT_EQ( __, ri );

  i = 4;
  EXPECT_EQ( __, i );
  EXPECT_EQ( __, ri );

  // example address-of operator
  EXPECT_EQ( __ /*true or false?*/, &i == &ri );

  // example typeid operator
  EXPECT_EQ( typeid(________/*int or int& or ...?*/), typeid(ri) );

  // example sizeof operator
  char ac[100];
  char(&rac)[100] = ac; // rac is a reference to an array of 100 chars
  EXPECT_EQ( __, sizeof(rac) );
}


// TC++PL4 7.7 References
//   A reference _always_ refers to the [same] object to which it was
//   initialized... Consequently, the value of a reference cannot be changed
//   after initialization; it always refers to the same object.
//
// Remember that references are aliases. Given ri is an reference, the identifier
// ri always means the object with which ri was initialized.
TEST(about_references,a_reference_always_refers_to_the_same_object)
{
  // pointers
  {
    int i1 = 1;
    int i2 = 2;
    int* pi = &i1;
    *pi = 10;
    pi = &i2;
    EXPECT_EQ( __, i1 );
    EXPECT_EQ( __, i2 );
    *pi = 20;
    EXPECT_EQ( __, i1 );
    EXPECT_EQ( __, i2 );
  }

  // references
  {
    int i1 = 1;
    int i2 = 2;
    int& ri = i1;
    ri = 10;
    EXPECT_EQ( __, i1 );
    EXPECT_EQ( __, i2 );
    ri = i2;
    EXPECT_EQ( __, i1 );
    EXPECT_EQ( __, i2 );
    ri = 20;
    EXPECT_EQ( __, i1 );
    EXPECT_EQ( __, i2 );
  }
}


// TC++PL4 7.7 References
//   There is no "null reference", and we may assume that a reference refers to
//   an object.
//
// TStd (8.3.2/4 "References"):
//   Note: in particular, a null reference cannot exist in a well-defined
//   program, because the only way to create such a reference would be to bind
//   it to the â€œobjectâ€? obtained by dereferencing a null pointer, which causes
//   undefined behavior.
TEST(about_references,a_reference_cannot_be_null)
{
#if 0
  int* pi = NULL;
  int& ri = *pi; // the expression '*pi' is undefined behavior, since it
                 // dereferences a null pointer
#endif
  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}


// TC++PL4 7.7 References
//   To ensure that a reference is a name for something (that is, that is bound
//   to an object [opposed to being "null"]) we must initialize the reference.
TEST(about_references,a_reference_must_be_initialized)
{
#if 0
  int& ri; //compile error
#endif
  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}


// There are actually two kinds of references (three in C++11): lvalue ("plain")
// references and const references. This koan is about lvalue references.
//
// TC++PL4 7.7.1 Lvalue References
//   The initializer for a "plain" T& [opposed to const T&] must be an lvalue of
//   type T.
TEST(about_references,the_initializer_for_an_lvalue_reference_must_be_an_lvalue)
{
#if 0
  int i1 = 2;
  int& ri1 = i1; // ok

  const int ci2 = 3;
  // int& ri2 = ci; // compile error, ci is not an lvalue

  // int& ri3 = 42; // compile error, 42 is not an lvalue

  // int& ri4 = 2 * i2; // compile error, the expression '2 * i2' is not an lvalue

  float f = 3.1415;
  // double& rd = f; // compile error, f is not of type double

  // contrast this koan with the next
#endif
  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

// About initializing const references
//
// TC++PL4 7.7.1 Lvalue References
//   The initializer for a const T& need not to be an lvalue [of type T] or even
//   of type T. In such cases
//   1) First, implicit type conversion to T is applied if necessary
//   2) Then, the resulting value is placed in a temporary variable of type T
//   3) Finally, this temporary is used as the value [i.e. the object] of the
//      initializer
TEST(about_references,initializing_const_references)
{
  // contrast this koan with the previous

  int i1 = 3;
  const int& cri1 = i1; //ok

  const int ci2 = 3;
  const int& cri2 = ci2; // ok

  const int& cri3 = 42; // ok. 42 is put into a temporary object, and the
                        // reference is then initialized to refer to that
                        // temporary object

  const int& cri4 = 2 * i1; // ok. The result of the expression '2 * i1' is put
                            // into a temporary object, and the reference is
                            // then initialized to refer to that temporary
                            // object

  float f = 3.1415;
  const double& crd = f; // ok. f is implicitly converted to double. The result
                         // is put into a temporary object, and the reference is
                         // then initialized to refer to that temporary object.
                         // Note that crd refers to the temporary, _not_ to f!

  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

// Regarding write access, the difference between 'T&' (lvalue reference) and
// 'const T&' (const reference) is the same as between 'T*' and 'const T*'. 'T&'
// allows to change the referred object whereas 'const T&' does not.
TEST(about_references,object_refered_to_by_const_reference_cannot_be_modified)
{
}


// Where to place const qualifier?
//
// ISO/IEC 14882-2003 8.3.2 References
//   Cv-qualified references are ill-formed except when the cv-qualifiers are
//   introduced through the use of a typedef (7.1.3) or of a template type
//   argument (14.3), in which case the cv-qualifiers are ignored.
typedef int& intref;
TEST(about_references,where_to_place_const_qualifier)
{
#if 0
  int i = 0;
  const int& ri1 = i;
  ri1 = 1; // compile eror
  int const & ri2 = i; // same thing as const int &
  ri2 = 2; // compile error

  int& const ri3 = i; // compile error
#endif
  int i4 = 0;
  intref const ri4 = i4; // ok, contrary to the above example, since int& having
                         // to be const was introduced through the use of a
                         // typedef. The const is ignored.
  ri4 = 4;               // ok, since the const was ignored

  EXPECT_TRUE(_________);//	acknowledge you understood this koan
}

//   A temporary created to hold a reference initializer persists until the end
//   of its reference's scope. [I.e. a const reference that is destructed, when
//   it refers to a temporary object, also destructs that temporary object].

// References to invalid objects. E.g. function returning a reference to a local
// object. Or a collection returning a reference to internal data, and the
// refernce is used after the object has been deleted (the Umweg via collection
// is not needed, its just a typical case). The same is true for pointers, so
// put it into a separate koan? Or simply have the topic at multiple places?
// Humans learn by repetition...

// difference pointer ref
// - ref cannot be NULL, i.e. use ptr when null is a possible value. This can be
//   an advantage (no nullptr checks necessairy) or an disadvantage (sometimes
//   you want to allow the scenario that there is no object)
// - ref allow for natural expressions like foo(a) or a + b (opposed to foo(&a)
//   or &a + &b respectively )
// - pointer must not neccessairly be initialized
// -
