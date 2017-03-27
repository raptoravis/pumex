#pragma once
#include <pumex/Export.h>
#include <glm/glm.hpp>

namespace pumex
{

struct PUMEX_EXPORT BoundingBox
{
  BoundingBox()
    : bbMin(FLT_MAX, FLT_MAX, FLT_MAX), bbMax(-FLT_MAX, -FLT_MAX, -FLT_MAX)
  {
  }
  BoundingBox(const glm::vec3& mn, const glm::vec3& mx)
    : bbMin(mn), bbMax(mx)
  {
  }

  void operator+=(const glm::vec3& v)
  {
    if (v.x<bbMin.x) bbMin.x = v.x;
    if (v.x>bbMax.x) bbMax.x = v.x;

    if (v.y<bbMin.y) bbMin.y = v.y;
    if (v.y>bbMax.y) bbMax.y = v.y;

    if (v.z<bbMin.z) bbMin.z = v.z;
    if (v.z>bbMax.z) bbMax.z = v.z;
  }

  void operator+=(const BoundingBox& bbox)
  {
    if (bbox.bbMin.x<bbMin.x) bbMin.x = bbox.bbMin.x;
    if (bbox.bbMax.x>bbMax.x) bbMax.x = bbox.bbMax.x;

    if (bbox.bbMin.y<bbMin.y) bbMin.y = bbox.bbMin.y;
    if (bbox.bbMax.y>bbMax.y) bbMax.y = bbox.bbMax.y;

    if (bbox.bbMin.z<bbMin.z) bbMin.z = bbox.bbMin.z;
    if (bbox.bbMax.z>bbMax.z) bbMax.z = bbox.bbMax.z;
  }

  bool contains(const glm::vec3& v) const
  {
    return (v.x >= bbMin.x && v.x <= bbMax.x) && (v.y >= bbMin.y && v.y <= bbMax.y) && (v.z >= bbMin.z && v.z <= bbMax.z);
  }

  glm::vec3 bbMin;
  glm::vec3 bbMax;
};


}