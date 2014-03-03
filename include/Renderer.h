//
//  Renderer.h
//  TreePaint
//
//  Created by Michael Ey on 2/27/14.
//
//

#ifndef TreePaint_Renderer_h
#define TreePaint_Renderer_h

#include "Scene.h"

namespace TreePaint
{
    class Renderer
    {
        void Render(const std::vector<std::shared_ptr<SceneObject>>& renderSet);
        
    };
}

#endif