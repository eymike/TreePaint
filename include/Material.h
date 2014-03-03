//
//  Material.h
//  TreePaint
//
//  Created by Michael Ey on 3/1/14.
//
//

#ifndef TreePaint_Material_h
#define TreePaint_Material_h

#include "cinder/gl/GlslProg.h"
#include "cinder/Matrix44.h"
#include "cinder/Quaternion.h"
#include "cinder/Vector.h"

namespace TreePaint {
    class Material
    {
    public:
        Material(const cinder::gl::GlslProg& program);
        
        void Bind(const cinder::Matrix44f& world,
                  const cinder::Matrix44f& view,
                  const cinder::Matrix44f& proj);
        
        template<typename T>
        void SetUniform(const std::string& varName, const T& value)
        {
            m_shader.uniform(varName.c_str(), value);
        }
        
        
    private:
        cinder::gl::GlslProg m_shader;
    };
    
    class MaterialInstance
    {
    public:
        MaterialInstance(const std::shared_ptr<Material>& material);
        
        virtual void Bind(const cinder::Matrix44f& world,
                          const cinder::Matrix44f& view,
                          const cinder::Matrix44f& proj);
        
    private:
        std::shared_ptr<Material> m_material;
    };;
}


#endif
