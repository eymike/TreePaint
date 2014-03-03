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

using namespace cinder;
using namespace cinder::gl;
using namespace TreePaint;

void TreePaint::Renderer::Render(const Camera& camera, const std::vector<std::shared_ptr<SceneObject>>& renderSet)
{
    for(const auto& it : renderSet)
    {
        it->GetMaterial()->Bind(it->GetSceneNode()->GetGlobalTransform(),
                                camera.getModelViewMatrix(),
                                camera.getProjectionMatrix());
        
        gl::draw(it->GetMesh());
    }
}