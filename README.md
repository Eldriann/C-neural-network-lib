# C-neural-network-lib
Short and unoptimized neural network lib used for learning the way a neural network work and learn.

To create a new neural network use the functions create_neural_network or create_neural_network_from_file.
If you create the neural network from scratch you will need to give to the function:
  * The number of input nodes
  * The number of hidden layers
  * The number of hidden nodes per layer
  * The number of output nodes

If you create the neural network from a save you just need to give the path to the file.

Examples:
```c
nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1); //Will create a neural network taking 2 inputs and giving 1 output with 1 hidden layer of 2 nodes
nn_neural_network_t *nn = create_neural_network_from_file("my_super_network.nnbrain"); //Will create a neural network from the file ./my_super_network.nnbrain
```

To destroy a neural network (make sure to save it before as it can not be recovered) use destroy_nn_neural_network.
```c
destroy_nn_neural_network(nn); //Destroy the created neural network
```

To save a neural network call nn_neural_network_save with as arguments the network to save and an optional filename.
If not name is specified the name will be DD_MM_YY_hh_mm_ss.nnbrain

Example:
```c
nn_neural_network_save(nn, "yay"); //Will save the neural network with as name: yay.nnbrain
```

You can train a neural network from this library in two ways:

Supervised: by giving the neural network inputs and expected outputs.

Example:
```c
/* Train a neural network supervised */
nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
float inputs[2] = {1.0, 0.0};
float target[1] = {1.0};
train_supervised(nn, inputs, target);
destroy_nn_neural_network(nn); //Don't forget to destroy the neural network
```
Reinforced: by giving the neural network it's initial state, the function to call to reset the environnement and the observer.
  * The observer is the function that compute the reward got and the new_state based of a taken action.
  * To edit the settings of the reinforcement training edit the settings properties in settings.h or update it in code with the settings field of the neural network.

To get a neural network guess call the feed_forward or feed_forward_from_mat function depending on your encoding and what suits you better.

Example from float array:
```c
nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
float inputs[2] = {0.0, 1.0};
float *guess = feed_forward(nn, inputs);

//Use the guess as you like
free(guess); //Don't forget to free the guess
destroy_nn_neural_network(nn);
```
Example from matrix:
```c
nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
nn_matrix_t *inputs = create_empty_nn_matrix(2, 1);
nn_matrix_t *guess = NULL;

if (inputs == NULL)
  return; //ERROR
inputs->values[0][0] = 0.0;
inputs->values[1][0] = 1.0;
guess = feed_forward_from_mat(nn, inputs);
//Use the guess as you like
destroy_nn_matrix(inputs);
destroy_nn_matrix(guess); //Don't forget to free the guess
destroy_nn_neural_network(nn);
```

You can generate documentation for the project using doxygen.

If you have any questions send a mail to julian.frabel@epitech.eu and i will respond to it as quick as i can.
