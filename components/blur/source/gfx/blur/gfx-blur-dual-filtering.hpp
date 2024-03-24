// AUTOGENERATED COPYRIGHT HEADER START
// Copyright (C) 2019-2023 Michael Fabian 'Xaymar' Dirks <info@xaymar.com>
// AUTOGENERATED COPYRIGHT HEADER END

#pragma once
#include "common.hpp"
#include "gfx-blur-base.hpp"
#include "gfx/gfx-util.hpp"
#include "obs/gs/gs-effect.hpp"
#include "obs/gs/gs-texrender.hpp"
#include "obs/gs/gs-texture.hpp"

#include "warning-disable.hpp"
#include <mutex>
#include <vector>
#include "warning-enable.hpp"

namespace streamfx::gfx {
	namespace blur {
		class dual_filtering_data {
			streamfx::obs::gs::effect            _effect;
			std::shared_ptr<streamfx::gfx::util> _gfx_util;

			public:
			dual_filtering_data();
			virtual ~dual_filtering_data();

			std::shared_ptr<streamfx::gfx::util> get_gfx_util();

			streamfx::obs::gs::effect get_effect();
		};

		class dual_filtering_factory : public ::streamfx::gfx::blur::ifactory {
			std::mutex                                                _data_lock;
			std::weak_ptr<::streamfx::gfx::blur::dual_filtering_data> _data;

			public:
			dual_filtering_factory();
			virtual ~dual_filtering_factory() override;

			virtual bool is_type_supported(::streamfx::gfx::blur::type type) override;

			virtual std::shared_ptr<::streamfx::gfx::blur::base> create(::streamfx::gfx::blur::type type) override;

			virtual double_t get_min_size(::streamfx::gfx::blur::type type) override;

			virtual double_t get_step_size(::streamfx::gfx::blur::type type) override;

			virtual double_t get_max_size(::streamfx::gfx::blur::type type) override;

			virtual double_t get_min_angle(::streamfx::gfx::blur::type type) override;

			virtual double_t get_step_angle(::streamfx::gfx::blur::type type) override;

			virtual double_t get_max_angle(::streamfx::gfx::blur::type type) override;

			virtual bool is_step_scale_supported(::streamfx::gfx::blur::type type) override;

			virtual double_t get_min_step_scale_x(::streamfx::gfx::blur::type type) override;

			virtual double_t get_step_step_scale_x(::streamfx::gfx::blur::type type) override;

			virtual double_t get_max_step_scale_x(::streamfx::gfx::blur::type type) override;

			virtual double_t get_min_step_scale_y(::streamfx::gfx::blur::type type) override;

			virtual double_t get_step_step_scale_y(::streamfx::gfx::blur::type type) override;

			virtual double_t get_max_step_scale_y(::streamfx::gfx::blur::type type) override;

			std::shared_ptr<::streamfx::gfx::blur::dual_filtering_data> data();

			public: // Singleton
			static ::streamfx::gfx::blur::dual_filtering_factory& get();
		};

		class dual_filtering : public ::streamfx::gfx::blur::base {
			std::shared_ptr<::streamfx::gfx::blur::dual_filtering_data> _data;

			double_t    _size;
			std::size_t _iterations;

			std::shared_ptr<streamfx::obs::gs::texture> _input_texture;

			std::vector<std::shared_ptr<streamfx::obs::gs::texrender>> _rts;

			public:
			dual_filtering();
			virtual ~dual_filtering() override;

			virtual void set_input(std::shared_ptr<::streamfx::obs::gs::texture> texture) override;

			virtual ::streamfx::gfx::blur::type get_type() override;

			virtual double_t get_size() override;

			virtual void set_size(double_t width) override;

			virtual void set_step_scale(double_t x, double_t y) override;

			virtual void get_step_scale(double_t& x, double_t& y) override;

			virtual std::shared_ptr<::streamfx::obs::gs::texture> render() override;

			virtual std::shared_ptr<::streamfx::obs::gs::texture> get() override;
		};
	} // namespace blur
} // namespace streamfx::gfx
