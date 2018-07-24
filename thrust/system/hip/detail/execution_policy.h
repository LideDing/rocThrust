/******************************************************************************
 * Copyright (c) 2016, NVIDIA CORPORATION.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the NVIDIA CORPORATION nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************/
#pragma once

#include <hip/hip_runtime.h>
#include <thrust/detail/execution_policy.h>
#include <thrust/iterator/detail/any_system_tag.h>
#include <thrust/system/hip/config.h>

BEGIN_NS_THRUST
namespace hip_rocprim {

  struct tag;

  template <class>
  struct execution_policy;

  template <>
  struct execution_policy<tag> : thrust::execution_policy<tag>
  {};

  struct tag : execution_policy<tag>
  {};

  template <class Derived>
  struct execution_policy : thrust::execution_policy<Derived>
  {
    inline operator tag() const { return tag(); }
  };
}    // namespace hip_rocprim

namespace system {
namespace hip {
  using thrust::hip_rocprim::tag;
  using thrust::hip_rocprim::execution_policy;
} // namespace hip
} // namespace system

namespace hip {
using thrust::hip_rocprim::execution_policy;
using thrust::hip_rocprim::tag;
} // namespace hip

END_NS_THRUST
