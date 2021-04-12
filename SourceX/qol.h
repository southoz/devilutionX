/**
 * @file qol.h
 *
 * Quality of life features
 */
#pragma once

#include "engine.h"

namespace devilution {

bool ShrineIsCrippling(int i);
void FreeQol();
void InitQol();
void DrawMonsterHealthBar(CelOutputBuffer out);
void DrawXPBar(CelOutputBuffer out);
void AutoGoldPickup(int pnum);

} // namespace devilution
