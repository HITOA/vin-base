#pragma once

#ifdef _WIN32
#define VIN_PLATFORM_WINDOWS
#endif // _WIN32

#ifdef unix
#define VIN_PLATFORM_UNIX
#error "UNIX NOT SUPPORTED"
#endif // unix

#ifdef __APPLE__
#define VIN_PLATFORM_APPLE
#error "APPLE NOT SUPPORTED"
#endif // __APPLE__

#if !defined(VIN_PLATFORM_WINDOWS) && !defined(VIN_PLATFORM_UNIX) && !defined(VIN_PLATFORM_APPLE)
#error "NO PLATFORM DEFINED"
#endif

#ifdef _DEBUG
#define VIN_DEBUG
#endif

#ifdef VIN_DEBUG
#define VIN_ENABLE_ASSERT
#define VIN_ENABLE_HARD_ASSERT
#define VIN_ENABLE_SOFT_ASSERT
#endif // DEBUG
