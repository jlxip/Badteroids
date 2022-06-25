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
void lsSkillFire();
void lsSkillLeft();
void lsSkillRight();

// Right ship
void rsShoot();
void rsSkillFire();
void rsSkillLeft();
void rsSkillRight();

// --- META ---
void _menuUp();
void _menuDown();
void _menuLeft();
void _menuRight();
void _menuEnter();

void _pause();

void _skip();
void _godMode();

#endif
