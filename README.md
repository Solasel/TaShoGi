# The TaShoGi Engine

This is a project to create a relatively functional [Shogi](https://en.wikipedia.org/wiki/Shogi) engine.

Some goals for the project:
- A transposition table to cache game position evaluations.
- Implementation of alpha-beta pruning and the killer heuristic
- Proper handling of sennichite (draw by repetition) and nyuugyokusengenhou (victory/draw by impasse).
- Proper implementation of clarifying notation (sugu, hiku, etc.) only when necessary.

As for the power of the resulting engine:
- The ability to solve the "hadakagyoku" checkmate problem optimally (where both kings are naked with all pieces in hand).
- The ability to beat the author of this project in a game of shogi.

Note: for the code of this project, I will be using the Japanese names for pieces, written in romaji (for instance, a bishop will be "kaku" and a promoted bishop will be "uma"), and the output notation will be in the Japanese style (eg, ☗７六歩 vs 76P).

By the way, "TaShoGi" is a pun on "多少" (tashou = more or less) and "将棋" (shougi = the game of shogi).
*Because this project more or less plays shogi.*	

乞うご期待!

