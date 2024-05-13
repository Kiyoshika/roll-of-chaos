# General TODO List
* Add `Perception` skill to increase the chance of finding chests/secret doors when traversing dungeons (can also lead to secret boss rooms)
* Finish adding `const` modifiers on the appropriate methods that don't modify internal data
* Add XP/next level XP in the character config file
* Need to add max health
* Make health an integer instead of a double
* Allow agility to improve flee chance. By default it'll be 1d12 with 0 Agility (1d10 with 5 Agl, 1d8 with 10, 1d6 with 15, 1d4 with 20 and 1d2 with 25)
* Prettify the menus a little bit by (optionally) removing the bottom bar in dialogs or top bar in choice menus (depending on which length is greater) and add some color eventually

## WIP XP Formula
* Levels 1-50: `5x^2 + 2.5x + 20` where `x` is the level
* Monster XP Granted: `x*pi` where `x` is the level of the monster

This is very experimental and will be tuned with gameplay
