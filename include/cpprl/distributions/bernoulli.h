#pragma once

#include <c10/util/ArrayRef.h>
#include <torch/torch.h>

#include "cpprl/distributions/distribution.h"

namespace cpprl
{
class Bernoulli : public Distribution
{
  private:
    torch::Tensor probs, logits, param;

  public:
    Bernoulli(const torch::Tensor *probs, const torch::Tensor *logits);

    torch::Tensor entropy();
    torch::Tensor log_prob(torch::Tensor value);
    torch::Tensor sample(c10::ArrayRef<int64_t> sample_shape = {});

    inline torch::Tensor get_logits() { return logits; }
    inline torch::Tensor get_probs() { return probs; }
};
}