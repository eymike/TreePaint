//
//  Renderer.cpp
//  TreePaint
//
//  Created by Michael Ey on 2/27/14.
//
//

#include "TreePaint_Prefix.pch"
#include "Renderer.h"

using namespace cinder;
using namespace cinder::gl;
using namespace TreePaint;

void TreePaint::Renderer::Render(const std::vector<std::shared_ptr<SceneObject>>& renderSet)
{
    for(const auto& it : renderSet)
    {
        
        gl::draw(it->GetMesh());
    }
}