# - Find CGAL
#
# Find the CGAL includes and libraries
# This module defines
#  CGAL_FOUND           - TRUE if found, FALSE otherwise
#  CGAL_INCLUDE_DIR     - Include directories for CGAL
#  CGAL_LIBRARIES       - The libraries to link against to use CGAL

FIND_PACKAGE(PackageHandleStandardArgs)

SET(CGAL_SEARCHPATH
    /usr/include/
    /usr/local/include/
    /opt/include/
    /opt/local/include/
    )

FIND_PATH(CGAL_INCLUDE_DIR
          NAMES CGAL/basic.h
          PATHS ${CGAL_SEARCHPATH}
          DOC "The CGAL include directory")

FIND_LIBRARY(CGAL_LIBRARIES
             NAMES CGAL libCGAL
             PATHS
             /usr/lib
             /usr/local/lib
             /usr/lib/CGAL
             /usr/lib64
             /usr/local/lib64
             /usr/lib64/CGAL
             DOC "The CGAL libraries")

IF(CGAL_INCLUDE_DIR AND CGAL_LIBRARIES)
    SET(CGAL_FOUND TRUE)
ELSE(CGAL_INCLUDE_DIR AND CGAL_LIBRARIES)
    SET(CGAL_FOUND FALSE)
ENDIF(CGAL_INCLUDE_DIR AND CGAL_LIBRARIES)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CGAL REQUIRED_VARS CGAL_INCLUDE_DIR CGAL_LIBRARIES)

MARK_AS_ADVANCED( CGAL_INCLUDE_DIR CGAL_LIBRARIES )

