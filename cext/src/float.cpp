/*
 * Copyright (C) 2010 Tim Felgentreff
 *
 * This file is part of jruby-cext.
 *
 * This code is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 3 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 3 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 3 along with this work.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "jruby.h"
#include "ruby.h"
#include "JLocalEnv.h"

using namespace jruby;

extern "C" VALUE
rb_float_new(double val) {
    JLocalEnv env;
    VALUE _float;
    jobject rb_float = env->CallStaticObjectMethod(RubyFloat_class,
            getStaticMethodID(env, RubyFloat_class, "newFloat", "(Lorg/jruby/Ruby;D)Lorg/jruby/RubyFloat;"),
            getRuntime(), (jdouble)val);
    _float = objectToValue(env, rb_float);
    return _float;
}
