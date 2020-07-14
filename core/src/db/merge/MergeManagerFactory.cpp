// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#include "db/merge/MergeManagerFactory.h"
#include "db/merge/MergeManagerImpl.h"
#include "db/merge/SSMergeManagerImpl.h"
#include "utils/Exception.h"
#include "utils/Log.h"

namespace milvus {
namespace engine {

MergeManagerPtr
MergeManagerFactory::Build(const meta::MetaPtr& meta_ptr, const DBOptions& options) {
    return std::make_shared<MergeManagerImpl>(meta_ptr, options, MergeStrategyType::LAYERED);
}

MergeManagerPtr
MergeManagerFactory::SSBuild(const DBOptions& options) {
    return std::make_shared<SSMergeManagerImpl>(options, MergeStrategyType::SIMPLE);
}

}  // namespace engine
}  // namespace milvus