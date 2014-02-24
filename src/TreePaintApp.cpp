#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TreePaintApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void TreePaintApp::setup()
{
}

void TreePaintApp::mouseDown( MouseEvent event )
{
}

void TreePaintApp::update()
{
}

void TreePaintApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( TreePaintApp, RendererGl )
