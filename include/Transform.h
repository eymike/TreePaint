//
//  Transform.h
//  TreePaint
//
//  Created by Michael Ey on 2/26/14.
//
//

#ifndef TreePaint_Transform_h
#define TreePaint_Transform_h

#include "cinder/Matrix44.h"
#include "cinder/Quaternion.h"
#include "cinder/Vector.h"

namespace TreePaint
{
    class Transform
    {
    public:
        Transform();
        Transform(const cinder::Vec3f& position,
                  const cinder::Quatf& rotation,
                  const cinder::Vec3f& scale);
        
        void Translate(const cinder::Vec3f& translation);
        void Rotate(const cinder::Quatf& rotation);
        void Scale(const cinder::Vec3f& scaling);
        
        void SetPosition(const cinder::Vec3f& translation);
        void SetRotation(const cinder::Quatf& rotation);
        void SetScale(const cinder::Vec3f& scaling);
        
        cinder::Matrix44f GetTransform() const;
    private:
        cinder::Vec3f m_position;
        cinder::Quatf m_rotation;
        cinder::Vec3f m_scale;
    };
}

#endif
