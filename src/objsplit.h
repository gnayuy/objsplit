// objsplit: to split a 3D object by a given point cloud
// Yang Yu (gnayuy@gmail.com)


#ifndef __OBJSPLIT_H__
#define __OBJSPLIT_H__

//
#include <gflags/gflags.h>

#include <CGAL/Scale_space_surface_reconstruction_3.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/IO/read_off_points.h>
#include <CGAL/Timer.h>

#include <ApproxMVBB/ComputeApproxMVBB.hpp>

#include <deque>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <ctime>
#include <limits>
#include <complex>
#include <iostream>

#include <boost/foreach.hpp>

// c++11
//#include <thread>
//#include <mutex>
//#include <future>

//
using namespace std;

// types
typedef CGAL::Exact_predicates_inexact_constructions_kernel     Kernel;

typedef CGAL::Scale_space_surface_reconstruction_3< Kernel >    Reconstruction;

typedef Reconstruction::Point                                   Point;
typedef std::vector< Point >                                    Point_collection;

typedef Reconstruction::Triple_const_iterator                   Triple_iterator;
typedef CGAL::Timer Timer;


// classes



#endif // __OBJSPLIT_H__
