//
//  Statistics.hpp
//  File file is part of the "Time" project and released under the MIT License.
//
//  Created by Samuel Williams on 28/6/2017.
//  Copyright, 2017, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Timer.hpp"

namespace Time
{
	class Statistics
	{
	protected:
		Interval _min = 0, _max = 0;
		
		Interval _duration = 0;
		std::uint64_t _count = 0;
		
	public:
		Statistics();
		
		Statistics & operator+=(const Statistics & other) noexcept;
		
		std::uint64_t count() const noexcept {return _count;}

		Interval average_duration() const noexcept;
		double updates_per_second() const noexcept;

		const Interval & minimum_duration() const noexcept {return _min;}
		const Interval & maximum_duration() const noexcept {return _max;}

		const Interval & duration() const noexcept { return _duration; }
		const std::uint64_t & update_count() const noexcept { return _count; }
		
		/// Add a single sample.
		void add(const Interval & duration) noexcept;
		
		/// Add a sample from the timer, and then reset it.
		void add(Timer & timer) noexcept;
	};
}
