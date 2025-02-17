#pragma once

#include "pattern.hpp"
#include "range.hpp"

#include <functional>

#include <CTRPluginFramework.hpp>

namespace base::memory
{
	class batch
	{
	public:
		void add(std::string_view name, pattern pattern, std::function<void (handle)> callback);
		void run(range range = ranges::text());

	private:
		struct entry
		{
			std::string_view m_name;
			pattern m_pattern;
			std::function<void (handle)> m_callback;
		};
		
		struct task_arg
		{
			range m_range;
			entry m_entry;
		};

		static s32 task_func(void *);

		std::vector<entry> m_entries;
	};
}