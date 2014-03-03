//
//  SceneNode.cpp
//  TreePaint
//
//  Created by Michael Ey on 2/26/14.
//
//

#include "TreePaint_Prefix.pch"
#include "Transform.h"
#include "SceneNode.h"

using namespace cinder;
using namespace TreePaint;
using namespace std;

bool SceneNode::IsDescendent(const std::shared_ptr<SceneNode> &parent)
{
    const auto spParent = m_parent.lock();
    if(!spParent)
    {
        return false;
    }
    
    return (spParent == parent) || spParent->IsDescendent(parent);
}

void SceneNode::SetParent(const shared_ptr<SceneNode> &parent)
{
    m_parent = weak_ptr<SceneNode>(parent);
}

Matrix44f SceneNode::GetGlobalTransform() const
{
    const auto spParent = m_parent.lock();
    if(spParent)
    {
        return m_transform.GetTransform() * spParent->GetGlobalTransform();
    }
    else
    {
        return m_transform.GetTransform();
    }
}

Transform& SceneNode::GetTransform()
{
    return m_transform;
}