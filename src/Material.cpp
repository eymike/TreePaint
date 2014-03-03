//
//  Material.cpp
//  TreePaint
//
//  Created by Michael Ey on 3/1/14.
//
//
#include "TreePaint_Prefix.pch"

#include "cinder/gl/GlslProg.h"
#include "Material.h"

using namespace cinder;
using namespace cinder::gl;
using namespace TreePaint;

Material::Material(const GlslProg& program):
    m_shader(program)
{
    
}

void Material::Bind(const Matrix44f& world,
                    const Matrix44f& view,
                    const Matrix44f& proj)
{
    m_shader.bind();
    
    SetUniform("world", world);
    SetUniform("view", view);
    SetUniform("proj", proj);
}

MaterialInstance::MaterialInstance(const std::shared_ptr<Material>& material):
    m_material(material)
{
    
}

void MaterialInstance::Bind(const Matrix44f& world,
                            const Matrix44f& view,
                            const Matrix44f& proj)
{
    m_material->Bind(world, view, proj);
}
