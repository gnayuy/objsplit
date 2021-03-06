
#
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/src/cmake ${CMAKE_MODULE_PATH})

# sources
SET( objsplit_sources

# header files

# source files 
    ${PROJECT_SOURCE_DIR}/src/objsplit.cpp
)

# gflags
FIND_PACKAGE( GFlags REQUIRED)
IF(GFLAGS_FOUND)
    SET(CMAKE_REQUIRED_LIBRARIES ${GFLAGS_LIBRARIES})
    INCLUDE_DIRECTORIES(${GFLAGS_INCLUDE_DIR})
ENDIF(GFLAGS_FOUND)

# CGAL
FIND_PACKAGE( CGAL REQUIRED)
IF(CGAL_FOUND)
    SET(CMAKE_REQUIRED_LIBRARIES ${CGAL_LIBRARIES})
    INCLUDE_DIRECTORIES(${CGAL_INCLUDE_DIR})
ENDIF(CGAL_FOUND)

#[[ computing an oriented bounding box.
#ApproxMVBB
FIND_PACKAGE( ApproxMVBB REQUIRED)
IF(ApproxMVBB_FOUND)
    SET(CMAKE_REQUIRED_LIBRARIES ${ApproxMVBB_LIBRARIES})
    INCLUDE_DIRECTORIES(${ApproxMVBB_INCLUDE_DIRS})
ENDIF(ApproxMVBB_FOUND)
]]

# OpenVDB
FIND_PACKAGE( OpenVDB REQUIRED)
IF(OpenVDB_FOUND)
    SET(CMAKE_REQUIRED_LIBRARIES ${OPENVDB_LIBRARIES})
    INCLUDE_DIRECTORIES(${OPENVDB_INCLUDE_DIRS})
ENDIF(OpenVDB_FOUND)

#
ADD_EXECUTABLE(objsplit ${objsplit_sources})
TARGET_LINK_LIBRARIES(objsplit ${DataIO_RLE_LIBRARY} ${CGAL_LIBRARIES} ${GFLAGS_LIBRARIES} ${BOOST_LIBRARIES} ${GMP_LIBRARIES} ${MPFR_LIBRARIES} ${OPENVDB_LIBRARIES})

