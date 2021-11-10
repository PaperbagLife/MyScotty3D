
#include "../lib/mathlib.h"
#include "debug.h"

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
    if (t0x > t1x) {
        float temp = t0x;
        t0x = t1x;
        t1x = temp;
    }
    t0y = (min.y - O.y) / D.y;
    t1y = (max.y - O.y) / D.y;
    if (t0y > t1y) {
        float temp = t0y;
        t0y = t1y;
        t1y = temp;
    }
    t0z = (min.z - O.z) / D.z;
    t1z = (max.z - O.z) / D.z;
    if (t0z > t1z) {
        float temp = t0z;
        t0z = t1z;
        t1z = temp;
    }
    float tmin = t0x;
    float tmax = t1x;
    if ((tmin > t1y) || (t0x > tmax)) return false;
    if (t0y > tmin) tmin = t0y;
    if (t1y < tmax) tmax = t1y;
    if ((tmin > t1x) || (t0x > tmax)) return false;
    if (t0z > tmin) tmin = t0z;
    if (t1z < tmax) tmax = t1z;
    if (tmin > times.y || tmax < times.x) {
        return false;
    }
    if (tmin > times.x) times.x = tmin;
    if (tmax < times.y) times.y = tmax;

    return true;
}
