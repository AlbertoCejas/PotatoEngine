#pragma once

#ifdef PLATFORM_WIN32

	using FileSystem = WindowsFileSystem;

#else

	using LinuxFileSystem = LinuxFileSystem;

#endif