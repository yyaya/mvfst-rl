#pragma once

#include "CongestionControlRPCEnv.h"

namespace quic {

class CongestionControlEnvFactory {
 public:
  CongestionControlEnvFactory(const CongestionControlEnv::Config& config)
      : config_(config) {}

  std::unique_ptr<CongestionControlEnv> make(
      CongestionControlEnv::Callback* cob) {
    switch (config_.mode) {
      case CongestionControlEnv::Mode::TRAIN:
        return std::make_unique<CongestionControlRPCEnv>(config_, cob);
      case CongestionControlEnv::Mode::TEST:
        std::runtime_error("Test mode not yet implemented");
        break;
    }
  }

 private:
  CongestionControlEnv::Config config_;
};

}  // namespace quic