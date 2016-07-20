// objsplit: to split a 3D object by a given point cloud
// Yang Yu (gnayuy@gmail.com)

// usage:
//
//

//
#include "objsplit.h"

// command line interface

DEFINE_string(obj, "", "object input ");
DEFINE_string(pc, "", "point cloud input .off");
DEFINE_string(o, "", "output");



// main func
int main(int argc, char *argv[])
{
    cout<<"objsplit: to split a 3D object by a given point cloud\n";
    
    //
    gflags::SetUsageMessage("objsplit -obj <object> -pc <pointcloud> -o <output>");
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    
    std::cout<<"Parameters:"<<std::endl;
    std::cout<<"inputs: \n  <Object>: "<<FLAGS_obj<<" \n  <PointCloud>: "<<FLAGS_pc<<" \noutput: \n  <splitObjects>: "<<FLAGS_o<<std::endl;
    
    //
    Point_collection points;
    std::ifstream in(FLAGS_pc);
    std::cerr << "Reading " << std::flush;
    if( !in || !CGAL::read_off_points( in, std::back_inserter( points ) ) ) {
        std::cerr << "Error: cannot read file" << std::endl;
        return -1;
    }
    
    std::cerr << "done: " << points.size() << " points." << std::endl;
    
    Timer t;
    t.start();
    
    // Construct the mesh in a scale space.
    Reconstruction reconstruct( 10, 200 );
    
    reconstruct.reconstruct_surface( points.begin(), points.end(), 4,
                                    false, // Do not separate shells
                                    true // Force manifold output
                                    );
    
    std::cerr << "Reconstruction done in " << t.time() << " sec." << std::endl;
    
    t.reset();
    std::ofstream out(FLAGS_o);
    for( Triple_iterator it = reconstruct.surface_begin( ); it != reconstruct.surface_end(  ); ++it )
        out << "3 "<< *it << '\n'; // We write a '3' in front so that it can be assembled into an OFF file
    
    std::cerr << "Writing result in " << t.time() << " sec." << std::endl;
    
    out.close();
    
//    t.reset();
//    std::ofstream garbage ("garbage.off");
//    // Write facets that were removed to force manifold output
//    for( Triple_iterator it = reconstruct.garbage_begin( ); it != reconstruct.garbage_end(  ); ++it )
//        garbage << "3 "<< *it << '\n'; // We write a '3' in front so that it can be assembled into an OFF file
//    std::cerr << "Writing garbage facets in " << t.time() << " sec." << std::endl;
//    
//    garbage.close ();
    
    std::cerr << "Done." << std::endl;

    
    //
    return 0;
}
