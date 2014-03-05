/*
        This file is part of cpp-ethereum.

        cpp-ethereum is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        (at your option) any later version.

        cpp-ethereum is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file Signals.h
 * @author Eric Lombrozo <elombrozo@gmail.com>
 * @date 2014
 */

#pragma once

#include <functional>
#include <map>
#include <mutex>

namespace eth
{

template<typename... Values>
class Signal
{
public:
	~Signal() { clear(); }

	uint64_t connect(std::function<void(Values...)> fn);
	bool disconnect(uint64_t connection);
	size_t size() const;
	void clear();

	void operator()(Values... values) const;

private:
	mutable std::recursive_mutex m_mutex;
	uint64_t m_nextConnection = 0;
	std::map<uint64_t, std::function<void(Values...)>> m_fnMap;
};

template<typename... Values>
inline uint64_t Signal<Values...>::connect(std::function<void(Values...)> fn)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	m_fnMap[m_nextConnection] = fn;
	return m_nextConnection++;
}

template<typename... Values>
inline bool Signal<Values...>::disconnect(uint64_t connection)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	return m_fnMap.erase(connection);
}

template<typename... Values>
inline size_t Signal<Values...>::size() const
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	return m_fnMap.size();
}

template<typename... Values>
inline void Signal<Values...>::clear()
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	m_fnMap.clear();
}

template<typename... Values>
inline void Signal<Values...>::operator()(Values... values) const
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	for (auto& i: m_fnMap) { i.second(values...); }
}



template<>
class Signal<void>
{
public:
	~Signal() { clear(); }

	uint64_t connect(std::function<void()> fn);
	bool disconnect(uint64_t connection);
	size_t size() const;
	void clear();

	void operator()() const;

private:
	mutable std::recursive_mutex m_mutex;
	uint64_t m_nextConnection = 0;
	std::map<uint64_t, std::function<void()>> m_fnMap;
};

template<>
inline uint64_t Signal<>::connect(std::function<void()> fn)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	m_fnMap[m_nextConnection] = fn;
	return m_nextConnection++;
}

template<>
inline bool Signal<>::disconnect(uint64_t connection)
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	return m_fnMap.erase(connection);
}

template<>
inline size_t Signal<>::size() const
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	return m_fnMap.size();
}

template<>
inline void Signal<>::clear()
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	m_fnMap.clear();
}

template<>
inline void Signal<>::operator()() const
{
	std::lock_guard<std::recursive_mutex> lock(m_mutex);
	for (auto& i: m_fnMap) { i.second(); }
}

/*
template<>
class Signal<void>
{
public:
	void connect(std::function<void()> fn)             { fns.push_back(fn); }
	void clear()                                       { fns.clear(); }

	void operator()()                                  { for (auto fn: fns) fn(); }

private:
	std::list<std::function<void()>> fns;
};
*/
}
