//
//  Scene.h
//  TreePaint
//
//  Created by Michael Ey on 2/27/14.
//
//

#ifndef TreePaint_Scene_h
#define TreePaint_Scene_h

#include "SceneNode.h"

namespace TreePaint
{
    class SceneObject
    {
    public:
        SceneObject(const cinder::AxisAlignedBox3f& box,
                    const cinder::gl::VboMeshRef& mesh,
                    const std::shared_ptr<SceneNode>& node);
        
        UInt32 GetID() const;
        cinder::AxisAlignedBox3f GetBoundingBox() const;
        cinder::gl::VboMeshRef& GetMesh();
        std::shared_ptr<SceneNode>& GetSceneNode();
    private:
        const UInt32 m_id;
        cinder::AxisAlignedBox3f m_boundingBox;
        cinder::gl::VboMeshRef m_mesh;
        std::shared_ptr<SceneNode> m_node;
    };
    
    class Scene
    {
    public:
        void GetRenderSet(const cinder::Camera& camera, std::vector<std::shared_ptr<SceneObject>>* renderSet);
        
        void AddSceneObject(const std::shared_ptr<SceneObject>& object);
        bool RemoveSceneObject(UInt32 id);
        
    private:
        std::map<UInt32, std::shared_ptr<SceneObject>> m_objects;
        std::shared_ptr<SceneNode> m_sceneRoot;
    };
}

#endif
