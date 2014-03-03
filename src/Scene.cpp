//
//  Scene.cpp
//  TreePaint
//
//  Created by Michael Ey on 2/26/14.
//
//

#include "TreePaint_Prefix.pch"

#include "cinder/AxisAlignedBox.h"
#include "cinder/Frustum.h"

#include <atomic>
#include "SceneNode.h"
#include "Scene.h"

using namespace cinder;
using namespace cinder::gl;
using namespace std;
using namespace TreePaint;

namespace
{
    struct IDSource
    {
        IDSource():
        seed(0)
        {}
        
        atomic_uint seed;
    };
    
    IDSource g_seed;
}

SceneObject::SceneObject(
                         const cinder::AxisAlignedBox3f& box,
                         const cinder::gl::VboMeshRef& mesh,
                         const std::shared_ptr<SceneNode>& node):
m_boundingBox(box),
m_mesh(mesh),
m_node(node),
m_id(g_seed.seed++)
{
    
}

UInt32 SceneObject::GetID() const
{
    return m_id;
}

AxisAlignedBox3f SceneObject::GetBoundingBox() const
{
    const auto& globalTransform = m_node->GetGlobalTransform();
    return m_boundingBox.transformed(globalTransform);
}

VboMeshRef& SceneObject::GetMesh()
{
    return m_mesh;
}

shared_ptr<SceneNode>& SceneObject::GetSceneNode()
{
    return m_node;
}

void Scene::GetRenderSet(const cinder::Camera &camera, std::vector<std::shared_ptr<SceneObject>>* renderSet)
{
    Frustumf frustum(camera);
    for(const auto& it : m_objects)
    {
        const auto& box = it.second->GetBoundingBox();
        if(frustum.intersects(box))
        {
            renderSet->push_back(it.second);
        }
    }
}

void Scene::AddSceneObject(const std::shared_ptr<SceneObject>& object)
{
    if(!object->GetSceneNode()->IsDescendent(m_sceneRoot))
    {
        object->GetSceneNode()->SetParent(m_sceneRoot);
    }
    
    m_objects.insert(make_pair(object->GetID(), object));
}

bool Scene::RemoveSceneObject(UInt32 id)
{
    return m_objects.erase(id) > 0;
}