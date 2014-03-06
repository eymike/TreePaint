#include "TreePaint_Prefix.pch"

#include "cinder/app/AppNative.h"

#include "cinder/Camera.h"
#include "cinder/gl/gl.h"

#include "Resources.h"

#include "MeshHelper.h"

#include "Material.h"
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
    
    std::shared_ptr<Material> m_basicMaterial;
    
    Scene m_scene;
    TreePaint::Renderer m_renderer;
};

void TreePaintApp::setup()
{
    setWindowSize(1280, 720);
    
    auto shader = gl::GlslProg(loadResource(RES_GLSL_BASICVERTEX), loadResource(RES_GLSL_BASICFRAG));
    
    m_basicMaterial = make_shared<Material>(shader);
    
    auto sphere = make_shared<SceneObject>(MeshHelper::createSphere(Vec2i(30,30)), make_shared<MaterialInstance>(m_basicMaterial));
    
    m_scene.AddSceneObject(sphere);
    
}

void TreePaintApp::resize()
{
    m_camera.lookAt( Vec3f( 0.0f, 0.0f, 5.0f ), Vec3f::zero() );
	m_camera.setPerspective( 60, getWindowAspectRatio(), 1, 40 );
    const auto bounds = getWindowBounds();
    m_renderer.Reset(bounds.getWidth(), bounds.getHeight());

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
    m_renderer.RenderDebugTargets(0.25f);
    
}

CINDER_APP_NATIVE( TreePaintApp, RendererGl )
