# Drift

Deep Reinforcement Learning for Fusion Control. Initial simulation environment is based on the paper "Mathematical Modeling of Plasma Transport in Tokamaks", by Ji Qiang.

Initially, we have an A2C or PPO agent that aims to maximise net energy gain and ignition probability by moving about in parameter space. Equations from the above paper are used as the model, and codes from BOUT++ are repurposed to solve these differential equations and provide a simulation environment for the agent.

The current method of modelling is not very computationally expensive due to its simplicity. However future iterations will incorporate further control mechanisms such as RMPs: 

https://iopscience.iop.org/article/10.1088/0741-3335/57/12/123001s. 

This will require more expressive and costly simulation, so the agent will need to be model-based, with the latent space and its predicted evolution serving as the environment, as seen in https://arxiv.org/abs/1803.10122.

## Building

CMake is used as the build system. Dependencies must be installed manually.

The BOUT++ solver codes have various dependencies, for installation instructions see [BOUT-docs](https://bout-dev.readthedocs.io/en/latest/). 

You will also need to install [libtorch](https://pytorch.org/cppdocs/installing.html).

## Linux

```
cd Drift
mkdir build && cd build
cmake ..
make -j4
```

## Motivation

Disruption control is a major problem in fusion energy. As high-temperature superconducting technology continues to improve, I expect it will be the main bottleneck to achieving fusion. 

Deep Reinforcement Learning (DRL) is powerful and expressive enough to solve this problem; furthermore having energy gain as the reward function naturally incentivises the agent to create sustained fusion with very little disruption, as it is trying to maximise the expected energy return of a given burn.

Applications of DL to fusion are given below:

https://arxiv.org/pdf/1811.00333.pdf

https://www.nature.com/articles/s41586-019-1116-4

Attempting to solve the control problem with DRL is the logical next step.
