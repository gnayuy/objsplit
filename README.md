# objsplit
to split a 3D object by a given point cloud

## compile using cmake

Install [CGAL][] by following the instructions on their [web site][CGAL].

Install [gflags][] for using the command lines.

Install [ApproxMVBB][] for computing an approximation of the minimal volume oriented bounding box of a point cloud.

## usage

./objsplit -obj <$Object> -pc <$PointCloud> -o <$Outputs>

## file formats

[OFF][]: object file format

[CGAL]: http://www.cgal.org
[gflags]: https://github.com/gflags/gflags
[OFF]: http://www.geomview.org/docs/html/OFF.html#OFF
[ApproxMVBB]: http://gabyx.github.io/ApproxMVBB
