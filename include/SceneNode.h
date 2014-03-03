//
//  SceneNode.h
//  TreePaint
//
//  Created by Michael Ey on 2/26/14.
//
//

#include "Transform.h"

#ifndef TreePaint_SceneNode_h
#define TreePaint_SceneNode_h

namespace TreePaint
{
    class SceneNode
    {
    public:
        bool IsDescendent(const std::shared_ptr<SceneNode>& parent);
        
        void SetParent(const std::shared_ptr<SceneNode>& parent);
        
        cinder::Matrix44f GetGlobalTransform() const;
        
        Transform& GetTransform();
    private:
        Transform m_transform;
        
        std::weak_ptr<SceneNode> m_parent;
    };
}

#endif
