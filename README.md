# C-neural-network-lib
Short and unoptimized neural network lib used for learning the way a neural network work and learn.

To create a new neural network use the functions create_neural_network or create_neural_network_from_file.
If you create the neural network from scratch you will need to give to the function:
  * The number of input nodes
  * The number of hidden layers
  * The number of hidden nodes per layer
  * The number of output nodes
If you create the neural network from a save you just need to give the path to the file.

To destroy a neural network (make sure to save it before as it can not be recovered) use destroy_nn_neural_network.

To save a neural network call nn_neural_network_save with as arguments the network to save and an optional filename.
If not name is specified the name will be DD_MM_YY_hh_mm_ss.nnbrain

You can train a neural network from this library in two ways:
Supervised: by giving the neural network inputs and expected outputs.
Reinforced: by giving the neural network it's initial state, the function to call to reset the environnement and the observer.
  The observer is the function that compute the reward got and the new_state based of a taken action.
  To edit the settings of the reinforcement training edit the settings properties in settings.h or update it in code with the settings field of the neural networkk.

You can generate documentation for the project using doxygen.

If you have any questions send a mail to julian.frabel@epitech.eu and i will respond to it as quick as i can.
