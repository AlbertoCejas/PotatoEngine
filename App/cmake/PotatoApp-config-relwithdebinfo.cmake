#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "PotatoApp" for configuration "RelWithDebInfo"
set_property(TARGET PotatoApp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(PotatoApp PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/PotatoApp.exe"
  )

list(APPEND _IMPORT_CHECK_TARGETS PotatoApp )
list(APPEND _IMPORT_CHECK_FILES_FOR_PotatoApp "${_IMPORT_PREFIX}/bin/PotatoApp.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
