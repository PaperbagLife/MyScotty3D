
#include "../lib/mathlib.h"
#include "debug.h"
#include <iostream>

bool BBox::hit(const Ray& ray, Vec2& times) const {

    // TODO (PathTracer):
    // Implement ray - bounding box intersection test
    // If the ray intersected the bounding box within the range given by
    // [times.x,times.y], update times with the new intersection times.
    Vec3 O = ray.point;
    Vec3 D = ray.dir;
    float t0x, t1x, t0y, t1y, t0z, t1z;
    t0x = (min.x - O.x) / D.x;
    t1x = (max.x - O.x) / D.x;
    if (t0x > t1x) std::swap(t0x, t1x);
    t0y = (min.y - O.y) / D.y;
    t1y = (max.y - O.y) / D.y;
    if (t0y > t1y) std::swap(t0y, t1y);
    t0z = (min.z - O.z) / D.z;
    t1z = (max.z - O.z) / D.z;
    if (t0z > t1z) std::swap(t0z, t1z);
    float tmin = t0x;
    float tmax = t1x;
    if ((tmin > t1y) || (t0y > tmax)) return false;
    if (t0y > tmin) tmin = t0y;
    if (t1y < tmax) tmax = t1y;
    if ((tmin > t1z) || (t0z > tmax)) return false;
    if (t0z > tmin) tmin = t0z;
    if (t1z < tmax) tmax = t1z;
    if (tmin > times.y || tmax < times.x) {
        return false;
    }
    if (tmin < ray.dist_bounds.x || tmax > ray.dist_bounds.y) return false;
    if (tmin > times.x) times.x = tmin;
    if (tmax < times.y) times.y = tmax;

    return true;
}
