//
//  Renderer.cpp
//  TreePaint
//
//  Created by Michael Ey on 2/27/14.
//
//

#include "TreePaint_Prefix.pch"

#include "cinder/Camera.h"

#include "Material.h"
#include "Renderer.h"

#define COLOR  0
#define NORMAL 1

using namespace cinder;
using namespace cinder::gl;
using namespace TreePaint;

void TreePaint::Renderer::Reset(int width, int height)
{
    Fbo::Format format;
    
    format.enableColorBuffer(true, 2);
    format.enableDepthBuffer(true, true);
    
    
    m_renderTarget = Fbo(width, height, format);
}

void TreePaint::Renderer::Render(const Camera& camera, const std::vector<std::shared_ptr<SceneObject>>& renderSet)
{
    m_renderTarget.bindFramebuffer();
    gl::setViewport( m_renderTarget.getBounds() );
    
    gl::clear(Color(0.5, 1, 0.5));
    
    gl::enableWireframe();
    
    for(const auto& it : renderSet)
    {
        it->GetMaterial()->Bind(it->GetSceneNode()->GetGlobalTransform(),
                                camera.getModelViewMatrix(),
                                camera.getProjectionMatrix());
        
        gl::draw(it->GetMesh());
    }
    gl::disableWireframe();
    m_renderTarget.unbindFramebuffer();
    GlslProg::unbind();
    
    gl::setMatricesWindow(m_renderTarget.getSize(), true);
    gl::draw(m_renderTarget.getTexture(COLOR), m_renderTarget.getBounds());
}

void TreePaint::Renderer::RenderDebugTargets(float scalingFactor)
{
    auto size = m_renderTarget.getSize() * scalingFactor;
    float h = 0;
    
    gl::setMatricesWindow(m_renderTarget.getSize(), true);
    gl::draw(m_renderTarget.getTexture(NORMAL), Rectf(0, h, size.x, size.y));
}
