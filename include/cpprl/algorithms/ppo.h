#pragma once

#include <string>
#include <vector>

#include <torch/torch.h>

#include "cpprl/algorithms/algorithm.h"

namespace cpprl
{n
    class Policy;
    class RolloutStorage;

    class PPO : public Algorithm  {
        private: 
            Policy &policy;     
            // PPO loss-function is defined in terms of actor, value coefficients, clip_params and/or kl_target, as well as entropy to encourage exploration
            // original_learning_rate is a hyperparameter that determines how fast we optimise
            float actor_loss_coef, value_loss_coef, entropy_coef, max_grad_norm, original_learning_rate, original_clip_param, kl_target;
            int num_epoch, num_mini_batch;
            
            // use adam optimiser
            std::unique_ptr<torch::optim::Adam> optimizer;

        public:
            PPO(Policy &policy,
                float clip_param,
                int num_epoch,
                int num_mini_batch,
                float actor_loss_coef,
                float value_loss_coef,
                float entropy_coef,
                float learning_rate,
                float epsilon = 1e-8
                float max_grad_norm = 0.5,
                float kl_target = 0.01);
        
        std::vector<UpdateDatum> update(RolloutStorage &rollouts, float decay_level = 1);
    };
}
