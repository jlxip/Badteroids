#ifndef GAME_EVENTS_HPP
#define GAME_EVENTS_HPP

#include <Badteroids/Badteroids.hpp>

void registerEvents();

// --- MOVEMENT ---
// Left ship
void lsLeft();
void lsRight();
void lsUp();
void lsDown();

// Right ship
void rsLeft();
void rsRight();
void rsUp();
void rsDown();

// --- ACTIONS ---
// Left ship
void lsShoot();

// Right ship
void rsShoot();

#endif
