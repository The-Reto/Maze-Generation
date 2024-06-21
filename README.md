# Origin Shift Algorithm for maze generation

This is a C++ implementation of the "Origin Shift" algorithm to generate a maze.
I stumbled over this algorithm on the YouTube channel of [CaptainLuma](https://www.youtube.com/@captainluma7991), specifically their video titled ["New Maze Generating Algorithm"](https://www.youtube.com/watch?v=zbXKcDVV4G0).

The algorithm is implemented almost exactly as described in the video, with two minor changes:

- The "origin" node retains its previous link instead of not linking to any other node. This is only replaced once the random walk continues to the next point.
- The number of steps the algorithm is run for is calculated as `4 * xy *(log sqrt(xy) )^2 / π` instead of `10 * xy` (for maze width/height: `x` and `y`). This choice is based on [this paper](https://annals.math.princeton.edu/wp-content/uploads/annals-v160-n2-p02.pdf), which shows that the number of steps a random walk takes to visit all sites on a square lattice is asysmtotic to `4 * n^2 * (log n)^2 / π`*.

*: This result is valid for a square lattice of side length `n`. In my implementation, the width and height can be set independently; therefore, some adjustments were necessary. I eyeballed these changes. They seem to work well as long as the width and height of the maze are of the same order of magnitude.

## Example Output
```
═╦══════╦═╦════╗║╔═══╦══╦╦═╦═╗╔╗═╗╔╦═══╔═╔═══╗══╗╔╗╔══════╗╔═╦╗║
═╩╗╔══╦═╩╗╚═╔╗║║╠╬══╗╠═╔╣╚═║║║║║╔╬╝╚╗║═╣═╬═║║╠╗║║║╠╣═╗═╗══╬╝═╝║║
═╦╩╩═╗╠══╠═╔╝╠╩╩╝╠═║║╚╗║╚══╣║║╔╬╝╠╗║╠╣║║═╬═╚╣║╠╩╣═╣╠═║║║═╗╚╗═╦═╣
═╩╗═╦╩╬═╔╩═╠╗║╔══║║╚╣╔╬╬═══╩╣═╝╠═║║╠╝╠╩╣═╝╔╗║═╩═╠═║║╔╬╬╝║╚═╬═║╔╣
╔═╣║║╔╝║║══╣║║╠╗╔╝╠╗║║║║╔═╦╗╠═║╚╗║╔╬═╠╗╠══║╚╝╔═╔╩══╚╣║║║╠╗╔╝══╣║
╠╗║║║║║╚╝╔╗║║║║║╠╗║╚╩╣═╗║═╝╚╩╗║═╣╔╝║║║║╚╗═╬══╬╦╝╔═══╝║╚╩╣╚╝╔╗║║║
║║╚╣║╠╝══╣╚══╩╝╠╝╚═══╣╔╝╚╦╦══╩╩═╣║║║╠══╦╬═╣═╦╣║╔╩╗╔═╦╩╦═╠═╔╝╚╣║║
║══╣║╠╦╦═╠══╦═║║═╦═══╩╣╔╗║║║║║╔═╝╔╬╝║══╝╠╗║═╣╚╗║║╚╬═╠╗║╔╬═╬╗║║╠╗
║══╝║║║╚╗╠══╩╦╝╠═║╔╦══╬╝║╚═╠╝╚╣══╝║═╣║══╣╚═╔╝═╩╣╚═╬═║║║║║║║╠╝╚╣║
║═╦═╚╗║═╩╩══╗╠═║╔╣║║║═╣═╩═╗╚══╩╦══╣╔╣╚╦═╝║╔╝╔══╩══╚═╚═══╗╚═╣═╗║║
║═╩╦╗╚╣║═╦═╔╝╠═╠╣║╚╗║═╩╦═║╚═══╗║╔╗║║║═╣═╗╠╝═╝═╗╔═╔═╔╗══╦╝╔═╬═╝║║
║║═╣╠╦╩╣═╬═╩╗║║║║╚╦╝╚╦═╚╗╠╦╗║═╝╔╝╠╣║╔═╚═╬╬═║═╗╠╩═╬═║╚╗╔╩╗║╔╝══╬╝
╠╝║║║╚╗╠═║║═╬═║╔══╣╔═║║═╝║║║╚╦═╝╔╣║═╩═╦═║║═╬╗╠╣╔╦╝╔╦╦╣╚╗╠╣╚╦═║╠╗
║═╬═╔═║║║║║╔╣╔╬╝══╬╬═╩╝═╗╔╝╚╦╩═╗║║╔═══╣║║╠╦╝║║║║╠═╝║║║═╝║║═╩╗║║║
╚═║╔╝╔═║╠═╬╝╠╝╠═║═╝║║║══╬╝║║║║═╬╦╗║╔╗╔╬╝╚╣║║║║╔╗╠╦═╚╦═══╝║╔═╩╣║║
║╔╬╬═╩╗═╩═║║║═╬═╚═╦═╠╬══╠═╣║═╬═║║╠═║║║╚═╦╩╦╝╚╣║╠╣╠═╗╚╗═╦╗║╚═║╠╩╗
║║║║╔═╣═╗══╩╬╗╠═║╔╩╦╣║╔═║║╚╝║║═╗║║═╝╠╣═╦╩╗║║═╝║║║║═╣═╝═╝║╚══╚╩═║
╠╣║╔╩═║║╚╗╔═╝║╚╗╚╝╔╝║╔╩╦═╠═╔╩╬╦╩╗║║║║╠═║║║║╚╗╔╩╦╗╚═║║╔╦═╩═║╔═╗═╣
║║╚╝╔═║╚╦╝║╔═║╔╩══╬╗╔╝║║║║║║║║║═╣═╩╣║╚═║╠╝║═╩╝═╝║══╬╝║║╔══╣║╔╬═╣
╠═╔═╩╗╚╗╠═║╚╦═╣╔═║║║║║╠╩╩╬╩╝╚╦══╚═╗║║══╬╣═╣║═╗══╩══╚═╠═╬╦═╝║║║║║
║╔╝╔╗║╔╣╠═══╣═╝║═╣╚╦╣║╠══╩╦╦╦╝║║╔═╚╣║║╔╣║║║╠╗║═══╦═══╝╔╝╚╗╔═║╔╣║
║║╔╝╚╝║║╠╗╔═║╔═╩═╣╔╝║╚╣═╗═╣║║═╩╬╩╗═╣╚╝║╠╦╣║║║║╔╗═╣═╦╗╔╣═╦╬╩╗║║╠╗
╠═║═╗═╦╬╣║╠═╚╣║║═╝║║╠═║║╠═║║╔╗║╠═║═╣╔═║║║╚╣║╠╝║╚╗╠═║║║║═╣╠═║╠╝║║
╠═╬═╠═║║║║║║╔╩╬╩═║╔╝╠═╔╬╩═══║║║╠══║║╠╗╔═╝║╚╩╣═╦╗║║╔═╩╦╗╔╝║═╗║║╔═
║║║║╠═╝║║║╚╩╝═╣║═╬╩═║║║║═╦══║╔╝║═╦╩╩╝╠╬═╗╠═╔╩╦╝╚╩═║╔═╝║║═╣║║╚╩╣║
║║╚╣╚╗║║╠╦═╦═║║║╔╝═╗║║╠╗═╩═╗╠╝═╣║║╔╦═║║║╚╣═╣═╩═╔═══╬╗═╗║╔╩╝║╔═╚╣
═╩═╩╗╠╝║║║║╚═╚═╣╠╦═╚╣║║╚╗╔═╣╠═║╚╩╦╝╠╦═╗║║╚═║═╦╗╠═╔═║║═╣║║═╦╩╣╔═╣
╔╗╔═╩╩╗║║╚╝╔═╦╦╝║╚╦╗╠╣║║╚╝╔╣╚╗╠══╝═╝║║║║╠═╔╩╦╣╚╣═╩╦╣╠╗║╚╗║╚╗╠╬╗║
║║║╔═║║╠══║╚╗║╠═╣═╝║║╚╩╬═╦╝║║║╠═╔═╦═╣╠╩╝╚╦╬╗║║═╣╔╗║║║╚╝╔╣╠═║║║║║
╠═╬╣╔╬╣╠╗╔╩╗║║╠═╚═║╚═══╝╔╩══╩╬╝╔╝═╝═╣╚╦═╔╣║║║╠═║║╚╣═╬═╦╣║╠═╩═║║║
║═╝║║║║║║╠╗╚╣║╚═║╔╬══╦╦═╚╦══╦╝╔╬══╦═╠═╚╗║╠═╗║╠╦═╠╗╚╗╚╗║║╚╩╗╔═╗║║
║══╝║╚══╩╝║═╩╝══╩╝╚══╝╚══╝══╝═╝║══╝═╩══╩╝║═╩╝║╚═╝╚═║═╝║╚══╚╩═║╚╝
```