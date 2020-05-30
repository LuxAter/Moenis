
// This is a generated file. Do not edit!

#ifndef CXX_COMPILER_DETECTION_H
#define CXX_COMPILER_DETECTION_H

#ifdef __cplusplus
# define CXX_COMPILER_IS_Comeau 0
# define CXX_COMPILER_IS_Intel 0
# define CXX_COMPILER_IS_PathScale 0
# define CXX_COMPILER_IS_Embarcadero 0
# define CXX_COMPILER_IS_Borland 0
# define CXX_COMPILER_IS_Watcom 0
# define CXX_COMPILER_IS_OpenWatcom 0
# define CXX_COMPILER_IS_SunPro 0
# define CXX_COMPILER_IS_HP 0
# define CXX_COMPILER_IS_Compaq 0
# define CXX_COMPILER_IS_zOS 0
# define CXX_COMPILER_IS_XLClang 0
# define CXX_COMPILER_IS_XL 0
# define CXX_COMPILER_IS_VisualAge 0
# define CXX_COMPILER_IS_PGI 0
# define CXX_COMPILER_IS_Cray 0
# define CXX_COMPILER_IS_TI 0
# define CXX_COMPILER_IS_Fujitsu 0
# define CXX_COMPILER_IS_GHS 0
# define CXX_COMPILER_IS_SCO 0
# define CXX_COMPILER_IS_ARMCC 0
# define CXX_COMPILER_IS_AppleClang 0
# define CXX_COMPILER_IS_ARMClang 0
# define CXX_COMPILER_IS_Clang 0
# define CXX_COMPILER_IS_GNU 0
# define CXX_COMPILER_IS_MSVC 0
# define CXX_COMPILER_IS_ADSP 0
# define CXX_COMPILER_IS_IAR 0
# define CXX_COMPILER_IS_MIPSpro 0

#if defined(__COMO__)
# undef CXX_COMPILER_IS_Comeau
# define CXX_COMPILER_IS_Comeau 1

#elif defined(__INTEL_COMPILER) || defined(__ICC)
# undef CXX_COMPILER_IS_Intel
# define CXX_COMPILER_IS_Intel 1

#elif defined(__PATHCC__)
# undef CXX_COMPILER_IS_PathScale
# define CXX_COMPILER_IS_PathScale 1

#elif defined(__BORLANDC__) && defined(__CODEGEARC_VERSION__)
# undef CXX_COMPILER_IS_Embarcadero
# define CXX_COMPILER_IS_Embarcadero 1

#elif defined(__BORLANDC__)
# undef CXX_COMPILER_IS_Borland
# define CXX_COMPILER_IS_Borland 1

#elif defined(__WATCOMC__) && __WATCOMC__ < 1200
# undef CXX_COMPILER_IS_Watcom
# define CXX_COMPILER_IS_Watcom 1

#elif defined(__WATCOMC__)
# undef CXX_COMPILER_IS_OpenWatcom
# define CXX_COMPILER_IS_OpenWatcom 1

#elif defined(__SUNPRO_CC)
# undef CXX_COMPILER_IS_SunPro
# define CXX_COMPILER_IS_SunPro 1

#elif defined(__HP_aCC)
# undef CXX_COMPILER_IS_HP
# define CXX_COMPILER_IS_HP 1

#elif defined(__DECCXX)
# undef CXX_COMPILER_IS_Compaq
# define CXX_COMPILER_IS_Compaq 1

#elif defined(__IBMCPP__) && defined(__COMPILER_VER__)
# undef CXX_COMPILER_IS_zOS
# define CXX_COMPILER_IS_zOS 1

#elif defined(__ibmxl__) && defined(__clang__)
# undef CXX_COMPILER_IS_XLClang
# define CXX_COMPILER_IS_XLClang 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ >= 800
# undef CXX_COMPILER_IS_XL
# define CXX_COMPILER_IS_XL 1

#elif defined(__IBMCPP__) && !defined(__COMPILER_VER__) && __IBMCPP__ < 800
# undef CXX_COMPILER_IS_VisualAge
# define CXX_COMPILER_IS_VisualAge 1

#elif defined(__PGI)
# undef CXX_COMPILER_IS_PGI
# define CXX_COMPILER_IS_PGI 1

#elif defined(_CRAYC)
# undef CXX_COMPILER_IS_Cray
# define CXX_COMPILER_IS_Cray 1

#elif defined(__TI_COMPILER_VERSION__)
# undef CXX_COMPILER_IS_TI
# define CXX_COMPILER_IS_TI 1

#elif defined(__FUJITSU) || defined(__FCC_VERSION) || defined(__fcc_version)
# undef CXX_COMPILER_IS_Fujitsu
# define CXX_COMPILER_IS_Fujitsu 1

#elif defined(__ghs__)
# undef CXX_COMPILER_IS_GHS
# define CXX_COMPILER_IS_GHS 1

#elif defined(__SCO_VERSION__)
# undef CXX_COMPILER_IS_SCO
# define CXX_COMPILER_IS_SCO 1

#elif defined(__ARMCC_VERSION) && !defined(__clang__)
# undef CXX_COMPILER_IS_ARMCC
# define CXX_COMPILER_IS_ARMCC 1

#elif defined(__clang__) && defined(__apple_build_version__)
# undef CXX_COMPILER_IS_AppleClang
# define CXX_COMPILER_IS_AppleClang 1

#elif defined(__clang__) && defined(__ARMCOMPILER_VERSION)
# undef CXX_COMPILER_IS_ARMClang
# define CXX_COMPILER_IS_ARMClang 1

#elif defined(__clang__)
# undef CXX_COMPILER_IS_Clang
# define CXX_COMPILER_IS_Clang 1

#elif defined(__GNUC__) || defined(__GNUG__)
# undef CXX_COMPILER_IS_GNU
# define CXX_COMPILER_IS_GNU 1

#elif defined(_MSC_VER)
# undef CXX_COMPILER_IS_MSVC
# define CXX_COMPILER_IS_MSVC 1

#elif defined(__VISUALDSPVERSION__) || defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
# undef CXX_COMPILER_IS_ADSP
# define CXX_COMPILER_IS_ADSP 1

#elif defined(__IAR_SYSTEMS_ICC__) || defined(__IAR_SYSTEMS_ICC)
# undef CXX_COMPILER_IS_IAR
# define CXX_COMPILER_IS_IAR 1


#endif

#  if CXX_COMPILER_IS_MSVC

#    if !(_MSC_VER >= 1600)
#      error Unsupported compiler version
#    endif

  /* _MSC_VER = VVRR */
# define CXX_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
# define CXX_COMPILER_VERSION_MINOR (_MSC_VER % 100)
# if defined(_MSC_FULL_VER)
#  if _MSC_VER >= 1400
    /* _MSC_FULL_VER = VVRRPPPPP */
#   define CXX_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#  else
    /* _MSC_FULL_VER = VVRRPPPP */
#   define CXX_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#  endif
# endif
# if defined(_MSC_BUILD)
#  define CXX_COMPILER_VERSION_TWEAK (_MSC_BUILD)
# endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_CONSTEXPR 1
#    else
#      define CXX_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if _MSC_VER >= 1700
#      define CXX_COMPILER_CXX_FINAL 1
#    else
#      define CXX_COMPILER_CXX_FINAL 0
#    endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_NOEXCEPT 1
#    else
#      define CXX_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if _MSC_VER >= 1600
#      define CXX_COMPILER_CXX_OVERRIDE 1
#    else
#      define CXX_COMPILER_CXX_OVERRIDE 0
#    endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_ALIGNAS 1
#    else
#      define CXX_COMPILER_CXX_ALIGNAS 0
#    endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_ALIGNOF 1
#    else
#      define CXX_COMPILER_CXX_ALIGNOF 0
#    endif

#    if _MSC_VER >= 1600
#      define CXX_COMPILER_CXX_NULLPTR 1
#    else
#      define CXX_COMPILER_CXX_NULLPTR 0
#    endif

#    if _MSC_VER >= 1600
#      define CXX_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define CXX_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if _MSC_VER >= 1900
#      define CXX_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define CXX_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif CXX_COMPILER_IS_GNU

#    if !((__GNUC__ * 100 + __GNUC_MINOR__) >= 404)
#      error Unsupported compiler version
#    endif

# if defined(__GNUC__)
#  define CXX_COMPILER_VERSION_MAJOR (__GNUC__)
# else
#  define CXX_COMPILER_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define CXX_COMPILER_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define CXX_COMPILER_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_CONSTEXPR 1
#    else
#      define CXX_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define CXX_COMPILER_CXX_FINAL 1
#    else
#      define CXX_COMPILER_CXX_FINAL 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_NOEXCEPT 1
#    else
#      define CXX_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 407 && __cplusplus >= 201103L
#      define CXX_COMPILER_CXX_OVERRIDE 1
#    else
#      define CXX_COMPILER_CXX_OVERRIDE 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define CXX_COMPILER_CXX_ALIGNAS 1
#    else
#      define CXX_COMPILER_CXX_ALIGNAS 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define CXX_COMPILER_CXX_ALIGNOF 1
#    else
#      define CXX_COMPILER_CXX_ALIGNOF 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 406 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_NULLPTR 1
#    else
#      define CXX_COMPILER_CXX_NULLPTR 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 404 && (__cplusplus >= 201103L || (defined(__GXX_EXPERIMENTAL_CXX0X__) && __GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define CXX_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 409 && __cplusplus > 201103L
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if (__GNUC__ * 100 + __GNUC_MINOR__) >= 408 && __cplusplus >= 201103L
#      define CXX_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define CXX_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif CXX_COMPILER_IS_Clang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 301)
#      error Unsupported compiler version
#    endif

# define CXX_COMPILER_VERSION_MAJOR (__clang_major__)
# define CXX_COMPILER_VERSION_MINOR (__clang_minor__)
# define CXX_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define CXX_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define CXX_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_constexpr)
#      define CXX_COMPILER_CXX_CONSTEXPR 1
#    else
#      define CXX_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_deleted_functions)
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_override_control)
#      define CXX_COMPILER_CXX_FINAL 1
#    else
#      define CXX_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_noexcept)
#      define CXX_COMPILER_CXX_NOEXCEPT 1
#    else
#      define CXX_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_override_control)
#      define CXX_COMPILER_CXX_OVERRIDE 1
#    else
#      define CXX_COMPILER_CXX_OVERRIDE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alignas)
#      define CXX_COMPILER_CXX_ALIGNAS 1
#    else
#      define CXX_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_alignas)
#      define CXX_COMPILER_CXX_ALIGNOF 1
#    else
#      define CXX_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_nullptr)
#      define CXX_COMPILER_CXX_NULLPTR 1
#    else
#      define CXX_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_static_assert)
#      define CXX_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define CXX_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 304 && __cplusplus > 201103L
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 301 && __has_feature(cxx_thread_local)
#      define CXX_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define CXX_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif CXX_COMPILER_IS_Intel

#    if !(__INTEL_COMPILER >= 1210)
#      error Unsupported compiler version
#    endif

  /* __INTEL_COMPILER = VRP */
# define CXX_COMPILER_VERSION_MAJOR (__INTEL_COMPILER/100)
# define CXX_COMPILER_VERSION_MINOR (__INTEL_COMPILER/10 % 10)
# if defined(__INTEL_COMPILER_UPDATE)
#  define CXX_COMPILER_VERSION_PATCH (__INTEL_COMPILER_UPDATE)
# else
#  define CXX_COMPILER_VERSION_PATCH (__INTEL_COMPILER   % 10)
# endif
# if defined(__INTEL_COMPILER_BUILD_DATE)
  /* __INTEL_COMPILER_BUILD_DATE = YYYYMMDD */
#  define CXX_COMPILER_VERSION_TWEAK (__INTEL_COMPILER_BUILD_DATE)
# endif
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define CXX_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define CXX_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# if defined(__GNUC__)
#  define CXX_SIMULATE_VERSION_MAJOR (__GNUC__)
# elif defined(__GNUG__)
#  define CXX_SIMULATE_VERSION_MAJOR (__GNUG__)
# endif
# if defined(__GNUC_MINOR__)
#  define CXX_SIMULATE_VERSION_MINOR (__GNUC_MINOR__)
# endif
# if defined(__GNUC_PATCHLEVEL__)
#  define CXX_SIMULATE_VERSION_PATCH (__GNUC_PATCHLEVEL__)
# endif

#    if __cpp_constexpr >= 200704 || __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_CONSTEXPR 1
#    else
#      define CXX_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_FINAL 1
#    else
#      define CXX_COMPILER_CXX_FINAL 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_NOEXCEPT 1
#    else
#      define CXX_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if __INTEL_COMPILER >= 1400 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_OVERRIDE 1
#    else
#      define CXX_COMPILER_CXX_OVERRIDE 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_ALIGNAS 1
#    else
#      define CXX_COMPILER_CXX_ALIGNAS 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_ALIGNOF 1
#    else
#      define CXX_COMPILER_CXX_ALIGNOF 0
#    endif

#    if __INTEL_COMPILER >= 1210 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_NULLPTR 1
#    else
#      define CXX_COMPILER_CXX_NULLPTR 0
#    endif

#    if (__cpp_static_assert >= 200410 || __INTEL_COMPILER >= 1210) && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define CXX_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201300L) || ((__cplusplus == 201103L) && !defined(__INTEL_CXX11_MODE__)) || ((((__INTEL_COMPILER == 1500) && (__INTEL_COMPILER_UPDATE == 1))) && defined(__GXX_EXPERIMENTAL_CXX0X__) && !defined(__INTEL_CXX11_MODE__) ) || (defined(__INTEL_CXX11_MODE__) && defined(__cpp_aggregate_nsdmi)) )
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if __INTEL_COMPILER >= 1500 && ((__cplusplus >= 201103L) || defined(__INTEL_CXX11_MODE__) || defined(__GXX_EXPERIMENTAL_CXX0X__))
#      define CXX_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define CXX_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  elif CXX_COMPILER_IS_AppleClang

#    if !(((__clang_major__ * 100) + __clang_minor__) >= 400)
#      error Unsupported compiler version
#    endif

# define CXX_COMPILER_VERSION_MAJOR (__clang_major__)
# define CXX_COMPILER_VERSION_MINOR (__clang_minor__)
# define CXX_COMPILER_VERSION_PATCH (__clang_patchlevel__)
# if defined(_MSC_VER)
   /* _MSC_VER = VVRR */
#  define CXX_SIMULATE_VERSION_MAJOR (_MSC_VER / 100)
#  define CXX_SIMULATE_VERSION_MINOR (_MSC_VER % 100)
# endif
# define CXX_COMPILER_VERSION_TWEAK (__apple_build_version__)

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_constexpr)
#      define CXX_COMPILER_CXX_CONSTEXPR 1
#    else
#      define CXX_COMPILER_CXX_CONSTEXPR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_deleted_functions)
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 1
#    else
#      define CXX_COMPILER_CXX_DELETED_FUNCTIONS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_override_control)
#      define CXX_COMPILER_CXX_FINAL 1
#    else
#      define CXX_COMPILER_CXX_FINAL 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_noexcept)
#      define CXX_COMPILER_CXX_NOEXCEPT 1
#    else
#      define CXX_COMPILER_CXX_NOEXCEPT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_override_control)
#      define CXX_COMPILER_CXX_OVERRIDE 1
#    else
#      define CXX_COMPILER_CXX_OVERRIDE 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define CXX_COMPILER_CXX_ALIGNAS 1
#    else
#      define CXX_COMPILER_CXX_ALIGNAS 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_alignas)
#      define CXX_COMPILER_CXX_ALIGNOF 1
#    else
#      define CXX_COMPILER_CXX_ALIGNOF 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_nullptr)
#      define CXX_COMPILER_CXX_NULLPTR 1
#    else
#      define CXX_COMPILER_CXX_NULLPTR 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_static_assert)
#      define CXX_COMPILER_CXX_STATIC_ASSERT 1
#    else
#      define CXX_COMPILER_CXX_STATIC_ASSERT 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 501 && __cplusplus > 201103L
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 1
#    else
#      define CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED 0
#    endif

#    if ((__clang_major__ * 100) + __clang_minor__) >= 400 && __has_feature(cxx_thread_local)
#      define CXX_COMPILER_CXX_THREAD_LOCAL 1
#    else
#      define CXX_COMPILER_CXX_THREAD_LOCAL 0
#    endif

#  else
#    error Unsupported compiler
#  endif

#  if defined(CXX_COMPILER_CXX_CONSTEXPR) && CXX_COMPILER_CXX_CONSTEXPR
#    define CXX_CONSTEXPR constexpr
#  else
#    define CXX_CONSTEXPR 
#  endif


#  if defined(CXX_COMPILER_CXX_DELETED_FUNCTIONS) && CXX_COMPILER_CXX_DELETED_FUNCTIONS
#    define CXX_DELETED_FUNCTION = delete
#  else
#    define CXX_DELETED_FUNCTION 
#  endif


#  if defined(CXX_COMPILER_CXX_FINAL) && CXX_COMPILER_CXX_FINAL
#    define CXX_FINAL final
#  else
#    define CXX_FINAL 
#  endif


#  if defined(CXX_COMPILER_CXX_NOEXCEPT) && CXX_COMPILER_CXX_NOEXCEPT
#    define CXX_NOEXCEPT noexcept
#    define CXX_NOEXCEPT_EXPR(X) noexcept(X)
#  else
#    define CXX_NOEXCEPT
#    define CXX_NOEXCEPT_EXPR(X)
#  endif


#  if defined(CXX_COMPILER_CXX_OVERRIDE) && CXX_COMPILER_CXX_OVERRIDE
#    define CXX_OVERRIDE override
#  else
#    define CXX_OVERRIDE 
#  endif


#  if defined(CXX_COMPILER_CXX_ALIGNAS) && CXX_COMPILER_CXX_ALIGNAS
#    define CXX_ALIGNAS(X) alignas(X)
#  elif CXX_COMPILER_IS_GNU || CXX_COMPILER_IS_Clang || CXX_COMPILER_IS_AppleClang
#    define CXX_ALIGNAS(X) __attribute__ ((__aligned__(X)))
#  elif CXX_COMPILER_IS_MSVC
#    define CXX_ALIGNAS(X) __declspec(align(X))
#  else
#    define CXX_ALIGNAS(X)
#  endif


#  if defined(CXX_COMPILER_CXX_ALIGNOF) && CXX_COMPILER_CXX_ALIGNOF
#    define CXX_ALIGNOF(X) alignof(X)
#  elif CXX_COMPILER_IS_GNU || CXX_COMPILER_IS_Clang || CXX_COMPILER_IS_AppleClang
#    define CXX_ALIGNOF(X) __alignof__(X)
#  elif CXX_COMPILER_IS_MSVC
#    define CXX_ALIGNOF(X) __alignof(X)
#  endif


#  if defined(CXX_COMPILER_CXX_NULLPTR) && CXX_COMPILER_CXX_NULLPTR
#    define CXX_NULLPTR nullptr
#  elif CXX_COMPILER_IS_GNU
#    define CXX_NULLPTR __null
#  else
#    define CXX_NULLPTR 0
#  endif

#  if defined(CXX_COMPILER_CXX_STATIC_ASSERT) && CXX_COMPILER_CXX_STATIC_ASSERT
#    define CXX_STATIC_ASSERT(X) static_assert(X, #X)
#    define CXX_STATIC_ASSERT_MSG(X, MSG) static_assert(X, MSG)
#  else
#    define CXX_STATIC_ASSERT_JOIN(X, Y) CXX_STATIC_ASSERT_JOIN_IMPL(X, Y)
#    define CXX_STATIC_ASSERT_JOIN_IMPL(X, Y) X##Y
template<bool> struct CXXStaticAssert;
template<> struct CXXStaticAssert<true>{};
#    define CXX_STATIC_ASSERT(X) enum { CXX_STATIC_ASSERT_JOIN(CXXStaticAssertEnum, __LINE__) = sizeof(CXXStaticAssert<X>) }
#    define CXX_STATIC_ASSERT_MSG(X, MSG) enum { CXX_STATIC_ASSERT_JOIN(CXXStaticAssertEnum, __LINE__) = sizeof(CXXStaticAssert<X>) }
#  endif


#  ifndef CXX_DEPRECATED
#    if defined(CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED) && CXX_COMPILER_CXX_ATTRIBUTE_DEPRECATED
#      define CXX_DEPRECATED [[deprecated]]
#      define CXX_DEPRECATED_MSG(MSG) [[deprecated(MSG)]]
#    elif CXX_COMPILER_IS_GNU || CXX_COMPILER_IS_Clang
#      define CXX_DEPRECATED __attribute__((__deprecated__))
#      define CXX_DEPRECATED_MSG(MSG) __attribute__((__deprecated__(MSG)))
#    elif CXX_COMPILER_IS_MSVC
#      define CXX_DEPRECATED __declspec(deprecated)
#      define CXX_DEPRECATED_MSG(MSG) __declspec(deprecated(MSG))
#    else
#      define CXX_DEPRECATED
#      define CXX_DEPRECATED_MSG(MSG)
#    endif
#  endif


#  if defined(CXX_COMPILER_CXX_THREAD_LOCAL) && CXX_COMPILER_CXX_THREAD_LOCAL
#    define CXX_THREAD_LOCAL thread_local
#  elif CXX_COMPILER_IS_GNU || CXX_COMPILER_IS_Clang || CXX_COMPILER_IS_AppleClang
#    define CXX_THREAD_LOCAL __thread
#  elif CXX_COMPILER_IS_MSVC
#    define CXX_THREAD_LOCAL __declspec(thread)
#  else
// CXX_THREAD_LOCAL not defined for this configuration.
#  endif

#endif

#endif
