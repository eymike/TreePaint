//
//  Transform.cpp
//  TreePaint
//
//  Created by Michael Ey on 2/26/14.
//
//

#include "TreePaint_Prefix.pch"
#include "Transform.h"

using namespace cinder;
using namespace TreePaint;

Transform::Transform():
    m_position(0, 0, 0),
    m_rotation(0, 0, 0, 1),
    m_scale(1, 1, 1)
{}

Transform::Transform(
                     const cinder::Vec3f& position,
                     const cinder::Quatf& rotation,
                     const cinder::Vec3f& scale):
    m_position(position),
    m_rotation(rotation),
    m_scale(scale)
{}

void Transform::Translate(const Vec3f &translation)
{
    m_position += translation;
}

void Transform::Rotate(const Quatf &rotation)
{
    m_rotation *= rotation;
}

void Transform::Scale(const Vec3f& scaling)
{
    m_scale *= scaling;
}

void Transform::SetPosition(const Vec3f &translation)
{
    m_position = translation;
}

void Transform::SetRotation(const Quatf &rotation)
{
    m_rotation = rotation;
}

void Transform::SetScale(const Vec3f& scaling)
{
    m_scale = scaling;
}


Matrix44f Transform::GetTransform() const
{
    return  Matrix44f::createScale(m_scale) *
            m_rotation.toMatrix44() *
            Matrix44f::createTranslation(m_position);
}
