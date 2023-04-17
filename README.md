### Description
This repo holds a 2-player card game. The game is played as follows:
- We start with the deck of 52 cards, each uniquely numbered from 1 to 52.
- The deck is shuffled.
- We deal out those cards between the 2 players. Each player gets half the deck.
- On each turn of the game, both players turn over their topmost card and they compare the value of those cards.
- The player with the higher-valued card “wins” the round and gets a point. The two cards being compared are discarded.
- Rounds are played until all the cards are discarded.
- At the end of the game the player who has the most points wins.

We then simulate this game in C++. The outputs of the simulation are:
- When each round is played we print each player’s card value along with an indication of which player won that round.
- When all rounds are played we print each player’s final score along with an indication of which player won overall.

### Running code
Install dependencies:
- `brew install bazelisk`

Run code:
- Build everything: `bazel build //...`
- Run tests: `bazel test //...`
- Run app: `bazel run //src:play-game`

### Supported environments
This has only been tested on an M1 mac. It will likely also work on an x86 Mac, but not on Windows or Linux.
