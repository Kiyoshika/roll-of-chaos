# Roll of Chaos
This is the official repo for the text adventure Roll of Chaos.

Originally planned to be a tabletop RPG but realized the mechanics involved would be too tedious to play, so instead I've converted it to a virtual text adventure.

**NOTE:** This repo is more "source available" than "open source" as I will not be taking arbitrary pull requests. But if we have a discussion and all agree it would be better for the game, I will review PRs on a case-by-case basis. However, players are more than welcome to modify the code themselves to "mod" the game however they like, change the rules and play however you want to play. This repo will just stand as the "official" ruleset.

## Introduction
Roll of Chaos is a D&D-inspired text adventure focused on a hack-and-slash style of gameplay designed for solo players. 

Create a character with basic rolled stats and traverse various zones and dungeons to gain unique items and create a wide variety of builds. 

There is no class system; invest points into different skills to unlock different abilities that can be blended together. 

Respec your stats for a fee in most towns. 

Obtain high level weapons, armor and spells from boss drops at elite versions of dungeons. 

Find secret bosses around the world to obtain legendary items.

It’s up to the player to make their own endgame - reach level 50? Collect every unique? Kill every boss? Clear every dungeon? Make the weirdest build possible? It’s your choice!

## Wiki
Eventually I want to create a Wiki for this game but at the moment one does not exist yet...

## Installing
There are no pre-built executables (yet) so for now you must build the game from source.

All you need is a C++17 compatible compiler and `make`. Perform the following steps:

1. Download/clone this repo
2. Enter the root directory and run `make` - this should build the executable and store it in the `dist/` folder
3. Play! - `./dist/roll-of-chaos`

## Contributions
I mentioned this is not exactly "open source" but if you are interested in improving the game by either fixing bugs, improving mechanics, or just generally have ideas about zones, dugeons, items, balancing, etc., feel free to start a discussion in this repo.
