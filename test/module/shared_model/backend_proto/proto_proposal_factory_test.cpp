/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <gtest/gtest.h>

#include "backend/protobuf/proto_proposal_factory.hpp"
#include "framework/result_fixture.hpp"
#include "module/shared_model/validators/validators.hpp"
#include "validators/default_validator.hpp"
#include "validators/field_validator.hpp"

using namespace shared_model;
using namespace framework::expected;

class ProposalFactoryTest : public ::testing::Test {
 public:
  shared_model::proto::ProtoProposalFactory<
      validation::AlwaysValidValidator>
      valid_factory;
  shared_model::proto::ProtoProposalFactory<
      validation::DefaultProposalValidator>
      factory;
};

TEST_F(ProposalFactoryTest, ValidProposalTest) {
  iroha::protocol::Transaction proto_tx;
  std::vector<shared_model::proto::Transaction> txs;
  txs.emplace_back(proto_tx);

  auto height = 1;
  auto time = iroha::time::now();
  auto proposal = valid_factory.createProposal(height, time, txs);

  proposal.match(
      [&](const ValueOf<decltype(proposal)> &v) {
        ASSERT_EQ(txs, v.value->transactions());
        ASSERT_EQ(height, v.value->height());
        ASSERT_EQ(time, v.value->createdTime());
      },
      [](const ErrorOf<decltype(proposal)> &e) { FAIL() << e.error; });
}

TEST_F(ProposalFactoryTest, InvalidProposalTest) {
  iroha::protocol::Transaction proto_tx;
  std::vector<shared_model::proto::Transaction> txs;
  txs.emplace_back(proto_tx);

  auto height = 1;
  auto time = iroha::time::now();
  auto proposal = factory.createProposal(height, time, txs);

  proposal.match(
      [&](const ValueOf<decltype(proposal)> &) {
        FAIL() << "unexpected value case";
      },
      [](const ErrorOf<decltype(proposal)> &) { SUCCEED(); });
}