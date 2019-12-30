# Drift

Deep Reinforcement Learning for Fusion Control. Initial simulation environment is based on the paper "Mathematical Modeling of Plasma Transport in Tokamaks", by Ji Qiang.

Initially, we have an A2C agent that aims to maximise net energy gain and ignition probability by moving about in parameter space. Equations from the above paper are used as the model, and codes from BOUT++ are repurposed to solve these differential equations and provide a simulation environment for the agent.

The current method of modelling is not very computationally expensive due to its simplicity. However future iterations will incorporate further control mechanisms such as RMPs: 

https://iopscience.iop.org/article/10.1088/0741-3335/57/12/123001s. 

This will require more expressive and costly simulation, so the agent will need to be model-based, and the latent space and its predicted evolution will serve as the environment, as seen in https://arxiv.org/abs/1803.10122.

## Building
