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
#include <list>

namespace eth
{

template<typename... Values>
class Signal
{
private:
	std::list<std::function<void(Values...)>> fns;

public:
	void connect(std::function<void(Values...)> fn) { fns.push_back(fn); }
	void clear() { fns.clear(); }
	void operator()(Values... values) { for (auto fn: fns) fn(values...); }
};

template<>
class Signal<void>
{
private:
	std::list<std::function<void()>> fns;

public:
	void connect(std::function<void()> fn) { fns.push_back(fn); }
	void clear() { fns.clear(); }
	void operator()() { for (auto fn : fns) fn(); }
};

}
