#include "TreePaint_Prefix.pch"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "SceneNode.h"
#include "Scene.h"
#include "Renderer.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace TreePaint;

class TreePaintApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Scene m_scene;
    TreePaint::Renderer m_renderer;
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
