#include "TreePaint_Prefix.pch"
#include "cinder/app/AppNative.h"

#include "cinder/Camera.h"
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
    void resize();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    CameraPersp m_camera;
    
    Scene m_scene;
    TreePaint::Renderer m_renderer;
};

void TreePaintApp::setup()
{
    
}

void TreePaintApp::resize()
{
    m_camera.lookAt( Vec3f( 0.0f, 0.0f, 5.0f ), Vec3f::zero() );
	m_camera.setPerspective( 60, getWindowAspectRatio(), 1, 40 );

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
    
    std::vector<std::shared_ptr<SceneObject>> renderSet;
    m_scene.GetRenderSet(m_camera, &renderSet);
    
    m_renderer.Render(m_camera, renderSet);
    
}

CINDER_APP_NATIVE( TreePaintApp, RendererGl )
