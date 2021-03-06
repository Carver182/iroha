#
# Copyright Soramitsu Co., Ltd. 2017 All Rights Reserved.
# http://soramitsu.co.jp
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

addtest(shared_proto_commands_test
    shared_proto_commands_test.cpp
    )
target_link_libraries(shared_proto_commands_test
    shared_model_proto_backend
    )

addtest(shared_proto_tx_response_test
    shared_proto_tx_response_test.cpp
    )
target_link_libraries(shared_proto_tx_response_test
    shared_model_proto_backend
    )

addtest(shared_proto_transaction_test
    shared_proto_transaction_test.cpp
    )
target_link_libraries(shared_proto_transaction_test
    shared_model_proto_backend
    shared_model_cryptography
    shared_model_stateless_validation
    )

addtest(shared_proto_queries_test
    shared_proto_queries_test.cpp
    )
target_link_libraries(shared_proto_queries_test
    shared_model_proto_backend
    shared_model_cryptography
    shared_model_stateless_validation
    )

addtest(shared_proto_query_responses_test
    shared_proto_query_responses_test.cpp
    )
target_link_libraries(shared_proto_query_responses_test
    shared_model_proto_backend
    shared_model_stateless_validation
    shared_model_cryptography
    )

addtest(shared_proto_util_test
    shared_proto_util_test.cpp
    )
target_link_libraries(shared_proto_util_test
    shared_model_proto_backend
    )

addtest(shared_proto_amount_test
    common_objects/shared_proto_amount_test.cpp
    )

target_link_libraries(shared_proto_amount_test
    shared_model_proto_backend
    )

addtest(permissions_test
    permissions_test.cpp
    )
target_link_libraries(permissions_test
    shared_model_proto_backend
    )

