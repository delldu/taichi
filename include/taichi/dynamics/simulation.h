/*******************************************************************************
    Taichi - Physically based Computer Graphics Library

    Copyright (c) 2016 Yuanming Hu <yuanmhu@gmail.com>
                  2017 Yu Fang <squarefk@gmail.com>

    All rights reserved. Use of this source code is governed by
    the MIT license as written in the LICENSE file.
*******************************************************************************/

#pragma once

#include <taichi/common/interface.h>
#include <taichi/visualization/particle_visualization.h>
#include <vector>
#include <taichi/math/levelset.h>

TC_NAMESPACE_BEGIN

template <int DIM>
class Simulation : public Unit {
 protected:
  real current_t = 0.0_f;
  int num_threads;
  DynamicLevelSet<DIM> levelset;

 public:
  static constexpr int D = DIM;

  Simulation() {
  }

  virtual real get_current_time() const {
    return current_t;
  }

  virtual void initialize(const Config &config) override {
    num_threads = config.get<int32>("num_threads");
  }

  virtual void add_particles(const Config &config) {
    error("no impl");
  }

  virtual void step(real t) {
    error("no impl");
  }

  virtual std::vector<RenderParticle> get_render_particles() const {
    error("no impl");
    return std::vector<RenderParticle>();
  }

  virtual void set_levelset(const DynamicLevelSet<DIM> &levelset) {
    this->levelset = levelset;
  }

  virtual void update(const Config &config) {
  }

  virtual bool test() const override {
    return true;
  };

  virtual void visualize() const {
  }

  virtual int get_mpi_world_rank() const {
    return 0;
  }

  virtual Vector2i get_vis_resolution() const {
    return Vector2i(512, 512);
  }

  virtual std::string get_debug_information() {
    NOT_IMPLEMENTED;
    return "";
  }
};

typedef Simulation<2> Simulation2D;
typedef Simulation<3> Simulation3D;

TC_INTERFACE(Simulation2D);
TC_INTERFACE(Simulation3D);

TC_NAMESPACE_END
