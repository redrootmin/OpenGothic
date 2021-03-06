#pragma once

#include <Tempest/Point>
#include <array>
#include <vector>

class Light final {
  public:
    Light();

    Tempest::Vec3        dir() const { return ldir; }
    void                 setDir(const Tempest::Vec3& d);
    void                 setDir(float x,float y,float z);

    const Tempest::Vec3& color() const { return clr; }
    void                 setColor(const Tempest::Vec3& cl);
    void                 setColor(uint32_t cl);
    void                 setColor(const std::vector<uint32_t>& cl, float fps, bool smooth);

    void                 setPosition(const Tempest::Vec3& p) { pos = p; }
    const Tempest::Vec3& position() const { return pos; }

    float                range() const { return rgn; }
    void                 setRange(float r);
    void                 setRange(const std::vector<float>& rangeAniScale, float base, float fps, bool smooth);

    void                 update(uint64_t time);
    bool                 isDynamic() const;
    float                currentRange() const { return curRgn; }
    const Tempest::Vec3& currentColor() const { return curClr; }

  private:
    Tempest::Vec3      ldir;
    Tempest::Vec3      clr;
    Tempest::Vec3      pos;
    float              rgn = 0;

    std::vector<float> rangeAniScale;
    uint64_t           rangeAniFPSInv = 0;
    bool               rangeSmooth = false;

    std::vector<Tempest::Vec3> colorAniList;
    uint64_t                   colorAniListFpsInv = 0;
    bool                       colorSmooth = false;

    Tempest::Vec3      curClr;
    float              curRgn = 0;
  };

